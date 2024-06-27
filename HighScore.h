#include <EEPROM.h>

#define EEPROM_SIZE 10 // Define the EEPROM size to be used

struct HighScore {
  long score;
  char initials[3];
};

HighScore highScore;

void saveHighScore() {
  EEPROM.begin(EEPROM_SIZE);
  EEPROM.put(0, highScore);
  EEPROM.commit();
  EEPROM.end();
}
void loadHighScore() {
  EEPROM.begin(EEPROM_SIZE);
  EEPROM.get(0, highScore);
  EEPROM.end();
}
void getInitials() {
  tft.fillScreen(TFT_BLACK);
  char currentInitial = 'A';
  int initialIndex = 0;
  bool initialsConfirmed = false;

  highScore.initials[0] = 'A';
  highScore.initials[1] = 'A';
  highScore.initials[2] = 'A';

  while (!initialsConfirmed) {
    // Clear the area where the initials are displayed
    tft.fillRect(100, 120, 60, 16, TFT_BLACK); // Adjust size as necessary

    // Display the initials with highlighted current initial
    for (int i = 0; i < 3; i++) {
      if (i == initialIndex) {
        tft.setTextColor(TFT_GREEN); // Current initial
      } else {
        tft.setTextColor(TFT_RED); // Other initials
      }
      tft.setCursor(100 + i * 20, 120);
      tft.print(highScore.initials[i]);
    }

    // Use dashButton to cycle through letters or to re-enter initials
    if (digitalRead(dashButton) == LOW) {
      if (initialIndex < 3) {
        currentInitial++;
        if (currentInitial > 'Z') currentInitial = 'A';
        highScore.initials[initialIndex] = currentInitial;
      } else {
        // Reset initials for re-entry
        initialIndex = 0;
        currentInitial = 'A';
        highScore.initials[0] = 'A';
        highScore.initials[1] = 'A';
        highScore.initials[2] = 'A';
        tft.fillRect(100, 140, 240, 16, TFT_BLACK); // Clear the confirmation area
      }
      delay(200); // Debounce delay
    }

    // Use jumpButton to advance to the next slot or confirm initials
    if (digitalRead(jumpButton) == LOW) {
      if (initialIndex < 2) {
        initialIndex++;
        currentInitial = 'A';
      } else if (initialIndex == 2) {
        // Move to confirmation stage
        initialIndex++;
        tft.setTextColor(TFT_GREEN);
        tft.setCursor(100, 140); // Position for confirmation message
        tft.print("Jump: Confirm, Dash: Re-enter");
      } else {
        // Confirm initials
        initialsConfirmed = true;
      }
      delay(200); // Debounce delay
    }

    delay(100); // Short delay for readability
  }
}
void displayHighScore() {
  drawStartScreen();
  tft.setTextSize(2);
  tft.setTextFont(1);
  tft.setTextColor(TFT_BLACK);
  tft.setCursor(40, 10);
  tft.print("High Score: ");
  tft.setTextSize(2);
   tft.setCursor(60, 50);
  tft.setTextFont(2);
  tft.setTextColor(TFT_GREEN);
  tft.print(highScore.score);
  tft.setTextFont(1);
  tft.setCursor(40, 110);
  tft.setTextColor(TFT_BLACK);
  tft.println("Player: ");
  tft.setTextSize(2);
  tft.setCursor(60, 150);
  tft.setTextFont(2);
  tft.setTextSize(2);
  tft.setTextColor(TFT_RED);
  tft.print(highScore.initials[0]);
  tft.setTextColor(TFT_BLUE);
  tft.print(highScore.initials[1]);
  tft.setTextColor(TFT_YELLOW);
  tft.print(highScore.initials[2]);
  tft.setTextSize(1);
  tft.setTextFont(1);
  delay(1000);
}
