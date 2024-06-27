/*


//////////////////////////////////////////////////////////////////
//   ______     __  __     ______   ______     ______           //
//  /\  ___\   /\ \/\ \   /\  == \ /\  ___\   /\  == \          //
//  \ \___  \  \ \ \_\ \  \ \  _-/ \ \  __\   \ \  __<          //
//   \/\_____\  \ \_____\  \ \_\    \ \_____\  \ \_\ \_\        //
//    \/_____/   \/_____/   \/_/     \/_____/   \/_/ /_/        //
//                                                              //
//    __     __  __     __    __     ______   __     ______     //
//   /\ \   /\ \/\ \   /\ "-./  \   /\  == \ /\ \   /\  __ \    //
//  _\_\ \  \ \ \_\ \  \ \ \-./\ \  \ \  _-/ \ \ \  \ \ \/\ \   //
// /\_____\  \ \_____\  \ \_\ \ \_\  \ \_\    \ \_\  \ \_____\  //
// \/_____/   \/_____/   \/_/  \/_/   \/_/     \/_/   \/_____/  //
//                                                              //
//////////////////////////////////////////////////////////////////

                ~Brought to you by~


██╗    ██╗██████╗██╗  █████████████╗   ███████╗   ██╗    ██╗    █████████╗  ██╗
██║    ████╔════╝██║  ██╚══██╔══████╗  ████████╗  ██║    ██║    ██╔════╚██╗██╔╝
██║    ████║  ██████████║  ██║  ██╔██╗ ██████╔██╗ ██║    ██║    █████╗  ╚███╔╝ 
██║    ████║   ████╔══██║  ██║  ██║╚██╗██████║╚██╗██║    ██║    ██╔══╝  ██╔██╗ 
█████████╚██████╔██║  ██║  ██║  ██║ ╚████████║ ╚████║    ████████████████╔╝ ██╗
╚══════╚═╝╚═════╝╚═╝  ╚═╝  ╚═╝  ╚═╝  ╚═══╚═╚═╝  ╚═══╝    ╚══════╚══════╚═╝  ╚═╝



    This game was made with the intent of educating both myself and others on the capabilities of game development within the Arduino platform.
My setup is configured for the esp32-wroom32 dev module, and ILI9341 240x320 TFT display. If you are a beginner, I would suggest using the same hardware.
If you are intermediate+, just edit the TFT_eSPI user_setup_select.h to uncomment your equipment.
Please refer to the manual for gameplay information.

This game is free and to help people learn. Don't be a capitalist or a jerk.

To-DO:
convert all remaining sprite images to bitmap array

create/implement new BrowserObj for boss fight
  create/implement FireballObj for boss level
remove flapples from Boss Level
  create/implement flaptles for Boss level
test all collisions/new tiles 

*/
#include <TFT_eSPI.h>
#include "BGTiles.h"
//define constants for screen parameters
// Resolution for the display
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
// Resolution for the base tiles within the game
#define TILE_WIDTH 16
#define TILE_HEIGHT 16
// Initialize the display(read the docs if you don't get this part :P)
TFT_eSPI tft = TFT_eSPI();
//enumeration for the game state, this handles the map being drawn
enum GameState {
  OVERWORLD,
  BOSS_LEVEL, 
  INTRO_SCREEN
};
// initialize the game state to the overworld
GameState currentState = INTRO_SCREEN;
// Global Variables
//movement//
int movementCounter = 0;
// Gravity effect
static float gravity = .8; 
//positioning//
int cameraPosX = 0;
int xPos = 0;
const int screenPosition = SCREEN_WIDTH / 2;
const int updateInterval = 50; // Update interval in milliseconds
static int prevXPos = 0;
static int prevYPos = 192;
// controls
const int jumpButton = 13;
const int dashButton = 12;
//debounce
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // 50ms debounce delay
//time//
unsigned long prevMillis = 0;
unsigned long previousMillis = 0;
//timers
const long interval = 33; // Interval for 30fps
unsigned long gameStartTime;
int gloombleSpawnDelay = 250;
unsigned long coinChangeTime = 0;
//counters
int mapClearedCounter = 0;
int squishMultiplier = 1;
int remainingLives;
int boxCount = 0;
// Variables to track previous HUD values
int prevLives = -1;
int prevScore = -1;
int prevCoins = -1;
// Variabless for the animations handled by "?" box collisions
int coinTileX = -1;
int coinTileY = -1;
unsigned long tileChangeTime = 0;
int changedTileX = -1;
int changedTileY = -1;
// A variable to command the false walls in the boos level
bool buttonIsPressed = false;
// Define the background tile map for the level
uint8_t backgroundMap[15][162] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,14,14,0,0,14,14,14,0,0,0,14,14,14,14,0,0,0,14,14,14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,8},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,13,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,14,0,0,0,0,9,10},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,14,0,0,14,14,14,14,14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,13,0,0,0,0,0,0,14,14,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,14,14,0,0,0,0,0,14,13,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,19,20},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,14,14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,22},
  {0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0,0,14,14,0,0,14,14,14,14,14},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,14,14,0,0,0,0,0,0,13,14,14,14,14,14,14,14,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,12,0,0,6,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,4,0,0,0,0,0},
  {0,0,0,0,0,13,0,0,0,13,14,13,0,0,0,0,0,0,14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,13,13,0,0,0,0,0,0,14,14,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,14,14,14,0,0,0,0,0,0,11,0,0,0,0,12,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,3,3,4,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,4,0,0,0,0,0,0,2,3,3,4,0,0,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,4,0,0,0,0,0,0,0,0,0,0,0,2,3,3,3,3,3,4,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,3,3,4,0,0,0,0,0,0,0,0,0,0,0,0,2,3,3,3,4,0,0,0,0,2,3,3,3,3,4,0,0,0,0,0,0,0,2,3,3,4,0,0,0,0,0,0,0,0,0,0,0,2,3,3,3,4,0,0,0,0,0,0,0,0,0,2,3,3,3,3,3,3,3,4,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,2,3,3,3,3,3,4,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,2,1,1,1,3,4,0,1,1,0,0,1,1,1,0,2,3,1,1,1,3,4,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,2,3,3,3,3,3,3,3,4,0,1,1,1,1,1,1,1,1,1,1,1,1,2,3,1,1,1,3,3,4,1,1,0,0,1,1,1,2,3,3,1,1,1,3,3,4,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1}
};
uint8_t BossMap1[15][80] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,3,0,0,3,0,0,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,3,3,3,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,2,2,2,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,2,2,2,1,1,1,1,1}
};
uint8_t IntroScreen[15][20] = {
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
{0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0}
}
;
void drawHUD(int &lives, long &score, int &coins, int &prevLives, int &prevScore, int &prevCoins, bool hasKey) {
    // Only redraw the HUD if any of the values have changed or if the key status has changed
    static bool prevHasKey = false; // Keep track of the previous key status
    if (lives != prevLives || score != prevScore || coins != prevCoins || hasKey != prevHasKey) {
        // Update the previous values
        prevLives = lives;
        prevScore = score;
        prevCoins = coins;
        prevHasKey = hasKey;

        // Define HUD dimensions and position
        const int hudHeight = 16;
        const int hudWidth = SCREEN_WIDTH;
        const int hudX = 0;
        const int hudY = 0;
        int HudBG;
       if (currentState == OVERWORLD){
         HudBG = TFT_CYAN;
       } else {
         HudBG = TFT_BLACK;
       }
        // Set text color and font size
        if (lives > 2) {
            tft.setTextColor(TFT_WHITE, HudBG); // White text on cyan background
        } else {
            tft.setTextColor(TFT_RED, HudBG); // Red text on cyan background for low lives
        }
        tft.setTextSize(1); // Set the text size to small

        // Create the text for lives, score, and coins
        char hudText[50]; // Buffer to hold the HUD text
        sprintf(hudText, "Score: %d Lives: %d              Coins: %d", score, lives, coins);

        // Calculate the position to start drawing the text
        int textX = 5; // 5 pixels from the left edge of the HUD
        int textY = (hudHeight - 8) / 2; // Vertically center the text (assuming 8px font height)

        // Clear the previous HUD area before drawing new text
        tft.fillRect(hudX, hudY, hudWidth, hudHeight, HudBG);

        // Draw the text on the HUD
        tft.drawString(hudText, textX, textY);

        // Draw "Key" in yellow on the right side of the HUD if hasKey is true
        if (hasKey) {
            tft.setTextColor(TFT_YELLOW, TFT_CYAN); // Yellow text on cyan background
            tft.drawString("Key", hudWidth - 35, textY); // Adjust position as needed
        }
    }
}
void drawBossMap() {
  int startTileX = cameraPosX/TILE_WIDTH;
  int endTileX = min(startTileX + SCREEN_WIDTH / TILE_WIDTH + 1, 80);
  int pixelOffset = cameraPosX%TILE_WIDTH;
  int yOffset = 16;
  for (int y = 0; y < 15; y++){
    for (int x = startTileX; x < endTileX; x++){
      int drawPosX = (x - startTileX) * TILE_WIDTH - pixelOffset;
      int drawPosY = y * TILE_HEIGHT + yOffset;
      switch (BossMap1[y][x]) {
        case 0:  // Wall
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, BossWall);
          break;
        case 1:  //Ground
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, BossGround);
          break;
        case 2: //Lava
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, LavaFloor);
          break;
        case 3:  //Box
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, Box);
          break;
        case 4: // Brick
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, BossBrick);
          break;
          case 5:  // Empty Box
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, emptyBox);
            break; 
        case 6:  // Coin with a black background to match the boss walls
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, BossCoin);
            break;
        case 7:  // Life
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, Life);
            break; 
        case 8:  // False Wall
        if (!buttonIsPressed){
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, FalseWall);
        } else {
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, BossBrick);
        }
            break;   
          case 9: // Button
          if (!buttonIsPressed){
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, Button);
          } else {
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, PressedButton);
          }
            break;
      }

    }
  }
}
void drawBackground() {
  // Calculate the starting and ending tiles to draw based on the camera position
  int startTileX = cameraPosX / TILE_WIDTH;
  int endTileX = min(startTileX + SCREEN_WIDTH / TILE_WIDTH + 1, 162);
  // Calculate the pixel offset within the current tile
  int pixelOffset = cameraPosX % TILE_WIDTH;
  int yOffset = 16;
  for (int y = 0; y < 15; y++) {
    for (int x = startTileX; x < endTileX; x++) {
      // Calculate the correct position to draw the tile at, taking the camera offset into account
      int drawPosX = (x - startTileX) * TILE_WIDTH - pixelOffset;
      int drawPosY = y * TILE_HEIGHT + yOffset;
      // Draw the tile
      switch (backgroundMap[y][x]) {
        case 0:  // Sky
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, Sky);
          break;
        case 1:  //Ground
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, Ground);
          break;
        case 2:  //MtnLft
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, MountainLeft);
          break;
        case 3:  //MtnMid
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, MountainMid);
          break;
        case 4:  //MtnRgt
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, MountainRight);
          break;
        case 5:  //MtnTop1
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, MountainTop);
          break;
        case 6:  //MtnTop2
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, MountainTopAlt);
          break;
        case 7:  //Big Cloud a
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, BigCloudA);
          break;
        case 8:  //Big Cloud b
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, BigCloudB);
          break;
        case 9:  //Big Cloud c
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, BigCloudC);
          break;
        case 10:  //Big Cloud d
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, BigCloudD);
          break;
        case 11:  //Small Cloud
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, SmallCloud);
          break;
        case 12:  //Tiny Clouds
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, TinyClouds);
          break;
        case 13:  //Box
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, Box);
          break;
        case 14: // Brick
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, Brick);
          break;
          case 15:  // Empty Box
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, emptyBox);
            break;
        case 16:  // Coin
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, Coin);
            break;
        case 18:  // Key
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, Key);
            break;
        case 19:  // doora
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, DoorA);
            break;
        case 20:  // doorb
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, DoorB);
            break;
        case 21:  // doorc
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, DoorC);
            break; 
        case 22:  // doord
            tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, DoorD);
            break;   
      }
    }
  }
}
void redrawTile(int prevX, int prevY) {
  int tileX = prevX/TILE_WIDTH;
  int tileY = prevY/TILE_HEIGHT;
  uint8_t tileType = backgroundMap[tileY][tileX];
  switch (tileType) {
        case 0:  //Sky
          tft.pushImage(tileX * TILE_WIDTH, tileY * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, BossWall);
          break;
        case 1:  //Ground
          tft.pushImage(tileX * TILE_WIDTH, tileY * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, BossGround);
          break;
        case 13:  //Box
          tft.pushImage(tileX * TILE_WIDTH, tileY * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, Box);
          break;
          case 14: // Brick
          tft.pushImage(tileX * TILE_WIDTH, tileY * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, Brick);
          break;
          case 15:  // Empty Box
            tft.pushImage(tileX * TILE_WIDTH, tileY * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, emptyBox);
            break;
        case 16:  // Coin
            tft.pushImage(tileX * TILE_WIDTH, tileY * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, Coin);
            break;
        case 18:  // Key
            tft.pushImage(tileX * TILE_WIDTH, tileY * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, Key);
            break;
      }
}
void resetQuestionMarkBoxesOverworld() {
    for (int y = 0; y < 15; y++) {
        for (int x = 0; x < 162; x++) {
            if (backgroundMap[y][x] == 15) {
                backgroundMap[y][x] = 13; // Change empty box back to question mark box
                boxCount = 0;
            }
        }
    }
}
void resetQuestionMarkBoxesBoss() {
    for (int y = 0; y < 15; y++) {
        for (int x = 0; x < 80; x++) {
            if (BossMap1[y][x] == 5) {
                BossMap1[y][x] = 3; // Change empty box back to question mark box
                boxCount = 0;
            }
        }
    }
}
 void getRandomSeed() {
  int randomValue = analogRead(36);
  randomSeed(randomValue);
}
// include the headers which contain logic for all of the entities and assets, and construct the sprite implementations
// We call these lower than the initial declarations because the objects within have logic that is dependent on the above map logic
#include "HighScore.h"
#include "Jumpio.h"
JumpioCharacter jumpio(&tft);
#include "Gloomble.h"
GloombleObj gloomble(&tft, gloombleSpawnDelay);
#include "Flapple.h"
FlappleObj flapple(&tft);
#include "Quacktle.h"
QuacktleObj quacktle(&tft);
#define MAX_ENEMIES 5
#include "Browser.h"
BrowserObj browser(&tft);
//Declare an array of objects with a size of [MAX_ENEMIES], and a pointer to the Flapple object for logic and assets
FlappleObj* flappleEnemies[MAX_ENEMIES];
int gloombleX = gloomble.xPos;
int gloombleY = gloomble.yPos;

void updateOverworld() {
  unsigned long currentMillis = millis();
  jumpio.update();
  jumpio.checkTileCollision();
  if (jumpio.isDashing) {
    squishMultiplier = 1;
  }
  if (jumpio.resetting){
    gloomble.spawnedOnRight = false;
    for (int i = 0; i < MAX_ENEMIES; i++) {
      int spawnOffset = i * 32;
    flappleEnemies[i]->isSquished = false;
    flappleEnemies[i]->movingUp = false;
    if (currentState == OVERWORLD) {
    flappleEnemies[i]->xPos = random((16*5), (16*162)); // Reset position
    }
    if (currentState == BOSS_LEVEL) {
    flappleEnemies[i]->xPos = random((16*5), (16*80)); // Reset position
    }
    flappleEnemies[i]->yPos = 160;
    }
    jumpio.resetting = false;
  }
  int jumpioX = jumpio.cameraPosX;
  int jumpioY = jumpio.yPos; 
  gloomble.checkTile();
  // Now update Gloomble with Jumpio's position
  gloomble.update(jumpioX, jumpioY);
  gloomble.checkCollision();
    if(gloomble.isSquished){
      jumpio.score += ((1000 * (gloomble.gloombleSpeedMultiplier * squishMultiplier)));
      squishMultiplier++;
    }

    int gloombleTileX = gloomble.xPos / TILE_WIDTH;
    int gloombleTileBelowY = (gloomble.yPos + 16) / TILE_HEIGHT;  
    // Ensure the tile index is within the map boundaries
    if (gloombleTileX >= 0 && gloombleTileX < 162 && gloombleTileBelowY >= 0 && gloombleTileBelowY < 15) {
        // Check if the tile below the Gloomble is not solid ground
        if (backgroundMap[gloombleTileBelowY][gloombleTileX] != 1) {
            // Reverse the Gloomble's direction
            gloomble.movingLeft = !gloomble.movingLeft;
        }
    }
    if (jumpio.xPos >= 320) {
      quacktle.update(cameraPosX);
        if (quacktle.isSquished){
          jumpio.score += ((5000 * (quacktle.quacktleSpeedMultiplier * squishMultiplier)));
        }
    }
  for (int i= 0; i < MAX_ENEMIES; i++){
      // Update Flapple
    flappleEnemies[i]->update(cameraPosX); // Pass cameraPosX to update

    // Check collision between Flapple and Jumpio
    flappleEnemies[i]->checkCollision(cameraPosX, jumpio); // Pass cameraPosX and Jumpio object to checkCollisio
      if(flappleEnemies[i]->isSquished) {
        jumpio.bounce(-13.0);
        jumpio.score += ((500 * (flappleEnemies[i]->flappleSpeedMultiplier * squishMultiplier)));
        squishMultiplier++;
      }
  }
        // Check if the tile needs to be reverted
    if (tileChangeTime > 0 && millis() - tileChangeTime >= 200) {
        if (changedTileY >= 0 && changedTileX >= 0) {
            backgroundMap[changedTileY][changedTileX] = 0;
        }
        tileChangeTime = 0; // Reset the timer
    }
  if (jumpio.mapCleared) {
  gloomble.xPos = jumpio.xPos + 300;  
  mapClearedCounter++;
    if (mapClearedCounter = 3){
      if (boxCount < 16 && boxCount > 10) {
    jumpio.score += 1000 * squishMultiplier;
    resetQuestionMarkBoxesOverworld();
  }
  else if (boxCount > 16) {
    jumpio.score += 5000 * squishMultiplier;
    resetQuestionMarkBoxesOverworld();
  }
      for (int i = 0; i < MAX_ENEMIES; i++){
    flappleEnemies[i]->minSpeed ++;
    flappleEnemies[i]->maxSpeed++;
      }
    gloomble.minSpeed ++;
    gloomble.maxSpeed++;
    quacktle.minSpeed++;
    quacktle.maxSpeed++;
    mapClearedCounter = 0; 
    }
    // Increment speed multipliers for Jumpio and Gloomble
    jumpio.jumpioSpeedMultiplier += 0.25;
    gloomble.gloombleSpeedMultiplier += 0.25;
    quacktle.quacktleSpeedMultiplier += 0.25;
    // Ensure that speed multipliers don't exceed certain limits if needed
    if (jumpio.jumpioSpeedMultiplier > 4.0) {
        jumpio.jumpioSpeedMultiplier = 4.0; // Adjust as needed
    }
    if(jumpio.isDashing){
      if (gloomble.gloombleSpeedMultiplier > 4.0) {
        gloomble.gloombleSpeedMultiplier = 4.0; // Adjust as needed
    }
    } else {
    if (gloomble.gloombleSpeedMultiplier > 2.0) {
        gloomble.gloombleSpeedMultiplier = 2.0; // Adjust as needed
    }
    }
    if (quacktle.quacktleSpeedMultiplier > 2.0) {
        quacktle.quacktleSpeedMultiplier = 2.0; // Adjust as needed
    }
    for (int i = 0; i < MAX_ENEMIES; i++) {
    if (flappleEnemies[i]->flappleSpeedMultiplier > 2.0) {
        flappleEnemies[i]->flappleSpeedMultiplier = 2.0; // Adjust as needed
    }
    }
    jumpio.mapCleared = false;
  }
}
void updateBossLevel() {
  unsigned long currentMillis = millis();
  jumpio.update();
  jumpio.checkTileCollision();
  browser.update(cameraPosX);
  if (jumpio.isDashing) {
    squishMultiplier = 1;
  }
  if (jumpio.resetting){
    for (int i = 0; i < MAX_ENEMIES; i++) {
      int spawnOffset = i * 32;
    flappleEnemies[i]->isSquished = false;
    flappleEnemies[i]->movingUp = false;
    flappleEnemies[i]->xPos = random((16*5), (16*162)); // Reset position
    flappleEnemies[i]->yPos = 160;
    }
    gloomble.isSquished = false;
    gloomble.spawnedOnRight = false;
    jumpio.resetting = false;
  }
  int jumpioX = jumpio.cameraPosX;  // Replace getXPos() with the actual method to get X position
  int jumpioY = jumpio.yPos;  // Replace getYPos() with the actual method to get Y position
  gloomble.checkTile();
  // Now update Gloomble with Jumpio's position
  gloomble.update(jumpioX, jumpioY);
  gloomble.checkCollision();
    if(gloomble.isSquished){
      jumpio.score += ((1000 * gloomble.gloombleSpeedMultiplier) * squishMultiplier);
      squishMultiplier++;
    }
    // Add check for Gloomble tile collision
    int gloombleTileX = gloomble.xPos / TILE_WIDTH;
    int gloombleTileBelowY = (gloomble.yPos + 16) / TILE_HEIGHT;  // Assuming the Gloomble's height is 16

    // Ensure the tile index is within the map boundaries
    if (gloombleTileX >= 0 && gloombleTileX < 162 && gloombleTileBelowY >= 0 && gloombleTileBelowY < 15) {
        // Check if the tile below the Gloomble is not solid ground
        if (BossMap1[gloombleTileBelowY][gloombleTileX] != 1) {
            // Reverse the Gloomble's direction
            gloomble.movingLeft = !gloomble.movingLeft;
        }
    }
  for (int i= 0; i < MAX_ENEMIES; i++){
      // Update Flapple
    flappleEnemies[i]->update(cameraPosX); // Pass cameraPosX to update

    // Check collision between Flapple and Jumpio
    flappleEnemies[i]->checkCollision(cameraPosX, jumpio); // Pass cameraPosX and Jumpio object to checkCollisio
      if(flappleEnemies[i]->isSquished) {
        jumpio.bounce(-13.0);
        jumpio.score += ((500 * flappleEnemies[i]->flappleSpeedMultiplier) * squishMultiplier);
        squishMultiplier++;
      }
  }
        // Check if the tile needs to be reverted
    if (tileChangeTime > 0 && millis() - tileChangeTime >= 200) {
        if (changedTileY >= 0 && changedTileX >= 0) {
            BossMap1[changedTileY][changedTileX] = 0;
        }
        tileChangeTime = 0; // Reset the timer
    }
  if (jumpio.mapCleared) {
  gloomble.xPos = jumpio.xPos + 300;
  mapClearedCounter++;
    if (mapClearedCounter = 3){
      if (boxCount < 13 && boxCount > 9) {
    jumpio.score += 1000 * squishMultiplier;
    resetQuestionMarkBoxesBoss();
  }
  else if (boxCount > 13) {
    jumpio.score += 5000 * squishMultiplier;
    resetQuestionMarkBoxesBoss();
  }
      for (int i = 0; i < MAX_ENEMIES; i++){
    flappleEnemies[i]->minSpeed ++;
    flappleEnemies[i]->maxSpeed++;
      }
    gloomble.minSpeed ++;
    gloomble.maxSpeed++;
    }
    // Increment speed multipliers for Jumpio and Gloomble
    jumpio.jumpioSpeedMultiplier += 0.25;
    gloomble.gloombleSpeedMultiplier += 0.25;
    
    // Ensure that speed multipliers don't exceed certain limits if needed
    if (jumpio.jumpioSpeedMultiplier > 4.0) {
        jumpio.jumpioSpeedMultiplier = 4.0; // Adjust as needed
    }
    if (gloomble.gloombleSpeedMultiplier > 4.0) {
        gloomble.gloombleSpeedMultiplier = 4.0; // Adjust as needed
    }
    for (int i = 0; i < MAX_ENEMIES; i++) {
    if (flappleEnemies[i]->flappleSpeedMultiplier > 4.0) {
        flappleEnemies[i]->flappleSpeedMultiplier = 4.0; // Adjust as needed
    }
    }
    jumpio.mapCleared = false;
  }
}
void handleBossLevel(){
  if (currentState == BOSS_LEVEL) {
        // Update game logic
        jumpio.handleInput(); // Handle player input
        updateBossLevel(); // Update game state (position, collisions, etc.)
        cameraPosX = jumpio.cameraPosX;
        if (jumpio.yPos < 16) {
          drawHUD(jumpio.lives, jumpio.score, jumpio.coins, prevLives, prevScore, prevCoins, jumpio.hasKey);
        }
        drawBossMap(); // Redraw the background with updated game state
    }
}
void handleOverworld(){
  if (currentState == OVERWORLD){
        // Update game logic
        jumpio.handleInput(); // Handle player input
        updateOverworld(); // Update game state (position, collisions, etc.)
        if (!quacktle.fireballIsActive) {
            quacktle.launchFireball();
        }
        cameraPosX = jumpio.cameraPosX;
        if (jumpio.yPos < 16) {
          drawHUD(jumpio.lives, jumpio.score, jumpio.coins, prevLives, prevScore, prevCoins, jumpio.hasKey);
        }
        drawBackground(); // Redraw the background with updated game state
  }
}
void gameWin() {
  drawStartScreen();
  tft.setTextColor(TFT_GREEN); // Set text color to white
  tft.setTextSize(1); // Set text size (adjust as needed)
  int completionTime = millis() / 100;
  tft.setCursor(20, 0);
  tft.println("Congratulations!");
  tft.print("You have saved the"); tft.setTextColor(TFT_MAGENTA); tft.println("CuteCute Kingdom!");
  tft.setCursor(20, 100);
  tft.setTextColor(TFT_GREEN);
  tft.print("Score: "); tft.print(jumpio.score); tft.setTextColor(TFT_BLACK); tft.print(" x "); tft.setTextColor(TFT_GREEN);tft.print(" Remaining Lives: ");  tft.println(remainingLives); tft.setTextColor(TFT_RED); tft.print(" - Completion Time: "); tft.print(completionTime);tft.setTextColor(TFT_BLACK); tft.print(" = ");
  tft.setCursor(20, 200);
  int finalScore = (jumpio.score * remainingLives) - completionTime;
  tft.setTextColor(TFT_GREEN);
  tft.println("Final Score: ");
  tft.println(finalScore);
  delay(3000);
  if(finalScore > highScore.score){
    highScore.score = finalScore;
      getInitials();
      saveHighScore();
      displayHighScore();
      while(true){
   }
    } else { 
        while (true) {
        }
    }
}


void drawStartScreen() {
  int startTileX = 0;
  int endTileX = min(startTileX + SCREEN_WIDTH / TILE_WIDTH + 1, 20);
  for (int y = 0; y < 15; y++){
    for (int x = startTileX; x < endTileX; x++){
      int drawPosX = (x - startTileX) * TILE_WIDTH;
      int drawPosY = y * TILE_HEIGHT;
      switch (IntroScreen[y][x]) {
        case 0:  // background
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, BossWall);
          break;
        case 1:  //PaperTop
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, PaperTop);
          break;
        case 2: //PaperMid
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, PaperMid);
          break;
          case 3: //PaperBottom
          tft.pushImage(drawPosX, drawPosY, TILE_WIDTH, TILE_HEIGHT, PaperBottom);
          break;
      }
    }
  }
}
void animateIntro() {
  drawStartScreen();


// weird spacing on text to ensure the intro screen remains readable and on the "paper" hahaha
  const char* message = " Thank you for playing SUPER JUMPIO! Jump and    dash to avoid obstacles and defeat enemies.     The general of King Browser's minions,          Ducktle, lost his spare key to the fortress.    See if you can find it, and make your way to    Browser! Can you help Jumpio save the            CuteCute Kingdom?";
  int messageLength = strlen(message);
  int letterIndex = 0;
  int posX, posY;

  // Find the starting position for the text
  bool startPosFound = false;
  for (int y = 0; y < 15 && !startPosFound; y++) {
    for (int x = 0; x < 20; x++) {
      if (IntroScreen[y][x] == 2) {
        posX = x * TILE_WIDTH;
        posY = y * TILE_HEIGHT;
        startPosFound = true;
        break;
      }
    }
  }

  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(1);

  // Gradually display the text
  while (letterIndex < messageLength) {
    // Check for button press
    if (digitalRead(jumpButton) == LOW || digitalRead(dashButton) == LOW) {
      beginGame();
      return; // Exit the function once game begins
    }

    // Display the text only on '2' tiles
    if (IntroScreen[posY / TILE_HEIGHT][posX / TILE_WIDTH] == 2) {
      tft.setCursor(posX, posY);
      tft.print(message[letterIndex]);
    }

    letterIndex++;
    posX += 6; // Adjust this based on your font size

    // Check if we need to wrap to the next line
    if (posX > SCREEN_WIDTH - 6 || IntroScreen[posY / TILE_HEIGHT][posX / TILE_WIDTH] != 2) {
      bool nextLineFound = false;
      for (int y = (posY / TILE_HEIGHT) + 1; y < 15 && !nextLineFound; y++) {
        for (int x = 0; x < 20; x++) {
          if (IntroScreen[y][x] == 2) {
            posX = x * TILE_WIDTH;
            posY = y * TILE_HEIGHT;
            nextLineFound = true;
            break;
          }
        }
      }
      if (!nextLineFound) break; // No more writable tiles, stop the loop
    }

    delay(50); // Delay to create the writing effect
  }
}
void beginGame() {
  displayHighScore();
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(3);
  tft.setCursor(0,100);
  tft.setTextColor(TFT_WHITE);
  tft.print("READY??"); delay(800);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN);
  for (int i = 0; i < MAX_ENEMIES; i++) {
    int spawnOffset = i * 32;
    flappleEnemies[i] = new FlappleObj(&tft);
    flappleEnemies[i]->xPos = jumpio.xPos+300; // Reset position
  }
  tft.print("GO!!"); delay(800);
  tft.setTextSize(1);
  gameStartTime = millis();
  currentState = OVERWORLD;
}

void handleIntroScreen() {
  if (currentState == INTRO_SCREEN) {
    animateIntro();
    delay(1000);
}
}
void setup() {
  tft.init();
  tft.setRotation(3);
  tft.setSwapBytes(true);
  drawBackground();
  getRandomSeed();
  pinMode(jumpButton, INPUT_PULLUP);
  pinMode(dashButton, INPUT_PULLUP);
  Serial.begin(115200);
  loadHighScore();
  tft.setTextFont(1);
}
void loop() {
    unsigned long currentMillis = millis();
    static unsigned long previousGameUpdateMillis = 0;
    const unsigned long gameUpdateInterval = 1000 / 30; // 30fps game update interval
     unsigned long elapsedTime = currentMillis - gameStartTime;
     static unsigned long previousHudUpdateMillis = 0;
    // Update game logic at a fixed interval (30fps)
    if (currentMillis - previousGameUpdateMillis >= gameUpdateInterval) {
        previousGameUpdateMillis = currentMillis;
        if (elapsedTime >= 100) {
            jumpio.score += (10 * jumpio.jumpioSpeedMultiplier);
        }
        handleIntroScreen();
        handleOverworld(); handleBossLevel();
        gameStartTime = currentMillis;
    }
    // Update HUD only when necessary
    if (jumpio.lives != prevLives || jumpio.score != prevScore || jumpio.coins != prevCoins || jumpio.hasKey) {
        drawHUD(jumpio.lives, jumpio.score, jumpio.coins, prevLives, prevScore, prevCoins, jumpio.hasKey);
        previousHudUpdateMillis = currentMillis;
    }
    
}
