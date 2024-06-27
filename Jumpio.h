#if defined(__AVR__)
    #include <avr/pgmspace.h>
#elif defined(__PIC32MX__)
    #define PROGMEM
#elif defined(__arm__)
    #define PROGMEM
#endif


const unsigned short Jumpio[256] PROGMEM={
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0010 (16) pixels
  0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0020 (32) pixels
  0xFFFF, 0xFFFF, 0x0000, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0030 (48) pixels
  0xFFFF, 0xFFFF, 0x0000, 0xF81F, 0xF81F, 0xF81F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0040 (64) pixels
  0xFFFF, 0x0000, 0xFF13, 0x0000, 0x0000, 0x0000, 0x001F, 0xFF13, 0xFF13, 0x001F, 0xFF13, 0xFF13, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0050 (80) pixels
  0xFFFF, 0x0000, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0060 (96) pixels
  0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0070 (112) pixels
  0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0080 (128) pixels
  0xFFFF, 0xFFFF, 0x0000, 0xF81F, 0xF81F, 0x001F, 0xF81F, 0xF81F, 0xF81F, 0x001F, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0090 (144) pixels
  0xFFFF, 0x0000, 0x0000, 0x0000, 0xF81F, 0x001F, 0xF81F, 0xF81F, 0xF81F, 0x001F, 0xF81F, 0x0000, 0xDEDB, 0x0000, 0xFFFF, 0xFFFF,   // 0x00A0 (160) pixels
  0x0000, 0xD69A, 0xC618, 0xD69A, 0x0000, 0xFFE0, 0xFFE0, 0xF81F, 0xFFE0, 0xFFE0, 0xF81F, 0x0000, 0xC618, 0x0000, 0xFFFF, 0xFFFF,   // 0x00B0 (176) pixels
  0x0000, 0xDEDB, 0xDEDB, 0x0000, 0x001F, 0xFFE0, 0xFFE0, 0x001F, 0xFFE0, 0xFFE0, 0x001F, 0x0000, 0xCE59, 0x0000, 0xFFFF, 0xFFFF,   // 0x00C0 (192) pixels
  0x0000, 0xCE59, 0xCE59, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00D0 (208) pixels
  0xFFFF, 0x0000, 0x0000, 0x61C0, 0x61C0, 0x61C0, 0x0000, 0xFFFF, 0x61C0, 0x61C0, 0x61C0, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00E0 (224) pixels
  0xFFFF, 0xFFFF, 0x0000, 0x61C0, 0x61C0, 0x61C0, 0x61C0, 0x0000, 0x61C0, 0x61C0, 0x61C0, 0x61C0, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00F0 (240) pixels
  0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0100 (256) pixels
};
const unsigned short JumpioMove[256] PROGMEM={
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0010 (16) pixels
  0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0020 (32) pixels
  0xFFFF, 0xFFFF, 0x0000, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0030 (48) pixels
  0xFFFF, 0xFFFF, 0x0000, 0xF81F, 0xF81F, 0xF81F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0040 (64) pixels
  0xFFFF, 0x0000, 0xFF13, 0x0000, 0x0000, 0x0000, 0x001F, 0xFF13, 0xFF13, 0x001F, 0xFF13, 0xFF13, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0050 (80) pixels
  0xFFFF, 0x0000, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0060 (96) pixels
  0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0070 (112) pixels
  0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF,   // 0x0080 (128) pixels
  0xFFFF, 0x0000, 0xF81F, 0xF81F, 0xF81F, 0x001F, 0xF81F, 0xF81F, 0xF81F, 0x001F, 0xF81F, 0x0000, 0x0000, 0xDEDB, 0xDEDB, 0x0000,   // 0x0090 (144) pixels
  0x0000, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x001F, 0xF81F, 0xF81F, 0xF81F, 0x001F, 0xF81F, 0xF81F, 0xF81F, 0xC638, 0xC638, 0x0000,   // 0x00A0 (160) pixels
  0xF81F, 0x0000, 0x0000, 0xF81F, 0xF81F, 0xFFE0, 0xFFE0, 0xF81F, 0xFFE0, 0xFFE0, 0xF81F, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF,   // 0x00B0 (176) pixels
  0x0000, 0xDEDB, 0xDEDB, 0x0000, 0x001F, 0xFFE0, 0xFFE0, 0x001F, 0xFFE0, 0xFFE0, 0x001F, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00C0 (192) pixels
  0x0000, 0xC638, 0xC638, 0x0000, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00D0 (208) pixels
  0xFFFF, 0x0000, 0x0000, 0x61C0, 0x61C0, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x61C0, 0x61C0, 0x0000, 0xFFFF, 0xFFFF,   // 0x00E0 (224) pixels
  0xFFFF, 0xFFFF, 0x0000, 0x61C0, 0x61C0, 0x61C0, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x61C0, 0x61C0, 0x61C0, 0x0000, 0xFFFF,   // 0x00F0 (240) pixels
  0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF,   // 0x0100 (256) pixels
};
const unsigned short JumpioJump[256] PROGMEM={
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0010 (16) pixels
  0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0020 (32) pixels
  0xFFFF, 0xFFFF, 0x0000, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0030 (48) pixels
  0xFFFF, 0xFFFF, 0x0000, 0xF81F, 0xF81F, 0xF81F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0040 (64) pixels
  0xFFFF, 0x0000, 0xFF13, 0x0000, 0x0000, 0x0000, 0x001F, 0xFF13, 0xFF13, 0x001F, 0xFF13, 0xFF13, 0x0000, 0x0000, 0xFFFF, 0xFFFF,   // 0x0050 (80) pixels
  0xFFFF, 0x0000, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xFF13, 0xF2AB, 0xF2AB, 0xFF13, 0xFF13, 0x0000, 0xCE79, 0xD69A, 0x0000, 0xFFFF,   // 0x0060 (96) pixels
  0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFF13, 0xFF13, 0xF800, 0xF800, 0xFF13, 0x0000, 0x0000, 0xC638, 0xD69A, 0x0000, 0xFFFF,   // 0x0070 (112) pixels
  0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xF81F, 0xF81F, 0x0000, 0xFFFF,   // 0x0080 (128) pixels
  0xFFFF, 0x0000, 0xF81F, 0xF81F, 0xF81F, 0x001F, 0xF81F, 0xF81F, 0xF81F, 0x001F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x0000, 0xFFFF,   // 0x0090 (144) pixels
  0x0000, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0x001F, 0xF81F, 0xF81F, 0xF81F, 0x001F, 0xF81F, 0xF81F, 0xF81F, 0x0000, 0xFFFF, 0xFFFF,   // 0x00A0 (160) pixels
  0xF81F, 0xF81F, 0x0000, 0xF81F, 0xF81F, 0xFFE0, 0xFFE0, 0xF81F, 0xFFE0, 0xFFE0, 0xF81F, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00B0 (176) pixels
  0xDEDB, 0xDEDB, 0x0000, 0x001F, 0x001F, 0xFFE0, 0xFFE0, 0x001F, 0xFFE0, 0xFFE0, 0x001F, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00C0 (192) pixels
  0xC638, 0xC638, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00D0 (208) pixels
  0x0000, 0x0000, 0x0000, 0x001F, 0x001F, 0x001F, 0x0000, 0xFFFF, 0x0000, 0x61C0, 0x61C0, 0x61C0, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00E0 (224) pixels
  0x61C0, 0x61C0, 0x61C0, 0x001F, 0x001F, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x61C0, 0x61C0, 0x61C0, 0x61C0, 0x0000, 0xFFFF, 0xFFFF,   // 0x00F0 (240) pixels
  0x61C0, 0x61C0, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF,   // 0x0100 (256) pixels
};
const unsigned short JumpioDash1[256] PROGMEM ={
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0010 (16)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0020 (32)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0030 (48)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFBE4, 0xFBE4, 0xFBE4, 0x8802, 0x8802, 0x8802, 0x8802, 0x8802, 0x8802, 0x8802, 0xFBE4, 0xFFFF, 0xFFFF,   // 0x0040 (64)
  0xFFFF, 0xFBE4, 0xFFFF, 0xFFFF, 0xFBE4, 0x8802, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFF80, 0xFF80, 0x8802, 0xFBE4, 0xFFFF,   // 0x0050 (80)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFBE4, 0x8802, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFF80, 0xFF80, 0xFF80, 0x8802, 0xFBE4, 0xFFFF,   // 0x0060 (96)
  0xFFFF, 0xFFFF, 0xFBE4, 0x8802, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFF80, 0x8802, 0x8802, 0x8802, 0xFBE4,   // 0x0070 (112)
  0xFFFF, 0xFBE4, 0x8802, 0x8802, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFF80, 0xFF80, 0xFF80, 0xFF80, 0xFF80, 0x8802, 0xFBE4,   // 0x0080 (128)
  0xFFFF, 0xFFFF, 0xFBE4, 0x8802, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFF80, 0x8802, 0x8802, 0x8802, 0xFBE4,   // 0x0090 (144)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFBE4, 0x8802, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFF80, 0xFF80, 0xFF80, 0x8802, 0x8802, 0xFBE4,   // 0x00A0 (160)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFBE4, 0xFBE4, 0x8802, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFF80, 0x8802, 0x8802, 0xFBE4, 0xFFFF,   // 0x00B0 (176)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x8802, 0x8802, 0x8802, 0x8802, 0x8802, 0x8802, 0xFBE4, 0xFBE4, 0xFFFF, 0xFFFF,   // 0x00C0 (192)
  0xFFFF, 0xFFFF, 0xFBE4, 0xFFFF, 0xFFFF, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00D0 (208)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00E0 (224)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00F0 (240)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0100 (256)
};
const unsigned short JumpioDash2[0x100] PROGMEM ={
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0010 (16)
  0x8802, 0x8802, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0020 (32)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0030 (48)
  0xFFFF, 0xFFFF, 0xFFFF, 0xE8E4, 0xE8E4, 0xE8E4, 0x8802, 0x8802, 0x8802, 0x8802, 0x8802, 0x8802, 0x8802, 0xE8E4, 0xFFFF, 0xFFFF,   // 0x0040 (64)
  0xFFFF, 0xE8E4, 0xFFFF, 0xFFFF, 0xE8E4, 0x8802, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xFBE4, 0xFBE4, 0x8802, 0xE8E4, 0xFFFF,   // 0x0050 (80)
  0xFFFF, 0xFFFF, 0xFFFF, 0xE8E4, 0x8802, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xFBE4, 0xFBE4, 0xFBE4, 0x8802, 0xE8E4, 0xFFFF,   // 0x0060 (96)
  0xFFFF, 0xFFFF, 0xE8E4, 0x8802, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xFBE4, 0x8802, 0x8802, 0x8802, 0xE8E4,   // 0x0070 (112)
  0xFFFF, 0xE8E4, 0x8802, 0x8802, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0xFBE4, 0x8802, 0xE8E4,   // 0x0080 (128)
  0xFFFF, 0xFFFF, 0xE8E4, 0x8802, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xFBE4, 0x8802, 0x8802, 0x8802, 0xE8E4,   // 0x0090 (144)
  0xFFFF, 0xFFFF, 0xFFFF, 0xE8E4, 0x8802, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xFBE4, 0xFBE4, 0xFBE4, 0x8802, 0x8802, 0xE8E4,   // 0x00A0 (160)
  0x8802, 0x8802, 0xFFFF, 0xE8E4, 0xE8E4, 0x8802, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xFBE4, 0x8802, 0x8802, 0xE8E4, 0xFFFF,   // 0x00B0 (176)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x8802, 0x8802, 0x8802, 0x8802, 0x8802, 0x8802, 0xE8E4, 0xE8E4, 0xFFFF, 0xFFFF,   // 0x00C0 (192)
  0xFFFF, 0xFFFF, 0xE8E4, 0xFFFF, 0xFFFF, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xE8E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00D0 (208)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00E0 (224)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00F0 (240)
  0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0100 (256)
};
#include <TFT_eSPI.h>
struct JumpioCharacter {
  //player variables
  int lives = 5;
  long score = 0;
  int coins = 0;
  //Implements a sprite for Jumpio, call "sprite"
  TFT_eSprite sprite; 
  //positioning
  int xPos;
  int yPos;
  int cameraPosX = 0;
  const int screenWidth = 320; // The ILI9341 is used in landscape mode for this project, so the width is 320 pixels
  const int screenCenter = screenWidth / 2; 
  int initialYPos;
  //timers
  unsigned long prevMillis;
  unsigned long buttonPressTime;
  //counters
  int movementCounter;
  int dashMultiplier = 1;
  //flags
  bool usingJumpioSprite; // To track which sprite is currently in use
  bool jumpioGrounded; // Flag to track if Jumpio is grounded
  bool isJumpPressed;
  bool mapCleared = false; // Declare and initialize mapCleared as a variable("member")
  bool resetting;
  bool hasKey = false;
  bool keySpawned = false;
  bool speedTrigger;
  //movement and physics
  const int maxDescentSpeed = 5;
  float jumpioSpeedMultiplier = 1.0;
  float previousSpeedMultiplier = 1.0;
  float gravity = 0.9; // Downward acceleration
  // Jump logic variables
  bool isJumping;
  float jumpVelocity;
  const float jumpPowerMin = -8; // Minimum jump power
  const float jumpPowerMax = -12; // Maximum jump power
  unsigned long lastJumpTime;
  bool jumpingSprite = false;
  // Additional members for dashing
  bool isDashing = false;
  const float dashSpeed = 5.0; // Speed of the dash
  const unsigned long dashDuration = 500; // Duration of the dash in milliseconds
  unsigned long dashStartTime;
  unsigned long lastDashToggleTime = 0;
  // Debounce
  bool lastJumpButtonState;
  unsigned long lastDebounceTimeJump;
  bool lastDashButtonState;
  unsigned long lastDebounceTimeDash;
  int debounceDelay = 50;
          // Constructor for the Jumpio object
        //    This constructs the object and a pointer to it, so that the below methods may be called externally
  JumpioCharacter(TFT_eSPI *tft) : sprite(tft), xPos(0), yPos(192), prevMillis(0), movementCounter(0), usingJumpioSprite(true), isJumping(false), jumpVelocity(0), jumpioGrounded(false), lastJumpTime(0) {
   
    //creates the sprite that we implemented
    sprite.createSprite(16, 16);
    //colors are weird if we do not do this
    sprite.setSwapBytes(true);
    // We use white as a transparent color in this case, since white is so easily represented by any other color in lighter values
    //    This means that any white in the image that is pushed to the sprite will be transparent as well
    sprite.fillSprite(TFT_WHITE);
    //initializes the player as on the ground
    isJumpPressed = false;
    // another timer initialiization
    buttonPressTime = 0;
}
int getCameraLimit() {
        // Calculate the camera limit based on the level's boundaries
        if (currentState == OVERWORLD){
  int levelWidth = 162 * TILE_WIDTH; // This level is 162 tiles wide
  int cameraLimit = min(max(xPos - screenCenter, 0), levelWidth - SCREEN_WIDTH);
  return cameraLimit;
        }else {
  int levelWidth = 80 * TILE_WIDTH;
  int cameraLimit = min(max(xPos - screenCenter, 0), levelWidth - SCREEN_WIDTH);
  return cameraLimit;
        }
}
bool isOnBox(int x, int y) {
    // Logic to determine if Jumpio is currently on top of a box
    // You need to check if the tile under Jumpio's current position is a box
  int tileX = x / TILE_WIDTH;
  int tileY = (y + 16) / TILE_HEIGHT; // Check the tile under Jumpio's feet
    return backgroundMap[tileY][tileX] == 13 || backgroundMap[tileY][tileX] == 14|| BossMap1[tileY][tileX] == 1  || BossMap1[tileY][tileX] == 3 ; // If the tile at this location is solid....
    isJumpPressed = false; //end the current jump if applicapble
}
void handleInput() {
  //Here we read the jump and dash buttons

    bool readingA = digitalRead(jumpButton);
    bool readingB = digitalRead(dashButton);
    // Debouncing for jumpButton
    if (readingA != lastJumpButtonState) {
        lastDebounceTimeJump = millis();
    }
    // Debouncing for dashButton
    if (readingB != lastDashButtonState) {
        lastDebounceTimeDash = millis();
    }
    // Logic for jumpButton
    if ((millis() - lastDebounceTimeJump) > debounceDelay) {
        if (readingA == LOW) {
            if (jumpioGrounded && !isJumping) {
                startJump();
                isJumpPressed = true;
            }
        } else {
            isJumpPressed = false;
        }
    }
    // Logic for dashButton
    if ((millis() - lastDebounceTimeDash) > debounceDelay) {
        if (readingB == LOW) {
            if (!jumpioGrounded && isJumping && !isDashing) {
                startDash();
            }
        }
    }
    lastJumpButtonState = readingA;
    lastDashButtonState = readingB;
}
void startDash() {
  bool dashStarted = true;
    if (dashStarted){
    isDashing = true;
    dashStartTime = millis();
    previousSpeedMultiplier = jumpioSpeedMultiplier;
    jumpioSpeedMultiplier += dashSpeed; // Increase the speed for the dash
    dashStarted = false;
    }
    // Change to the JumpioDash sprite
    sprite.pushImage(0, 0, 16, 16, JumpioDash1);
}
void startJump() {
    jumpioGrounded = false;
    isJumping = true;
    jumpingSprite = true;
    jumpVelocity = -12; // Start with a lower initial upward velocity
    if (jumpioSpeedMultiplier = 0) {
      jumpioSpeedMultiplier = previousSpeedMultiplier;
    }
}
void updateJump() {
    if (isJumping) {
      if(!isDashing){
      jumpioSpeedMultiplier = 1.8;
      }
        yPos += jumpVelocity;
        jumpVelocity += gravity;
        // Handle jump button release
        if (digitalRead(jumpButton) == HIGH && jumpVelocity < 0) {
            jumpVelocity = maxDescentSpeed;
        } else if (jumpVelocity < 0) {
            jumpVelocity += gravity / 4;
        } else {
            if (jumpVelocity < maxDescentSpeed) {
                jumpVelocity += gravity;
            } else {
                jumpVelocity = maxDescentSpeed;
            }
        }
        checkTileCollision();
    }
}
void reset() {
  resetting = true;
  lives--;
  if (lives < 0){
    gameOver();
  } else {
  redrawPath(prevXPos, prevYPos, xPos, yPos, 16, 16);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 0);
    if (lives < 2) {
      tft.setTextColor(TFT_RED);
    } else {
  tft.setTextColor(TFT_WHITE);
    }
  tft.setTextSize(2);
  tft.print("coins: "); tft.print(coins);
  tft.setCursor(0, 65);
  tft.print("score: "); tft.print(score);
  tft.setCursor(0, 110);
  tft.print("Lives Remaining: "); tft.print(lives);
  delay(1500);
  }
}
void resetJumpio() {  // placeholder for eventual death animation
    // Reset Jumpio's position
  xPos = 0; // Define this variable as per your game's logic
  yPos = 170; // Same as above
  jumpVelocity = gravity;
}
void bounce(float bounceVelocity) {
            jumpVelocity = bounceVelocity; // Set jump velocity to a negative value
            isJumping = true;
}
void redrawPath(int oldX, int oldY, int newX, int newY, int spriteWidth, int spriteHeight) {
    int startTileX = min(oldX, newX) / TILE_WIDTH;
    int endTileX = max(oldX + spriteWidth, newX + spriteWidth) / TILE_WIDTH;
    int startTileY = min(oldY, newY) / TILE_HEIGHT;
    int endTileY = max(oldY + spriteHeight, newY + spriteHeight) / TILE_HEIGHT;

    for (int x = startTileX; x <= endTileX; x++) {
        for (int y = startTileY; y <= endTileY; y++) {
            redrawTile(x * TILE_WIDTH, y * TILE_HEIGHT);
        }
    }
}
void checkTileCollision() {
    jumpioGrounded = false;
    int jumpioLeft = xPos;
    int jumpioRight = xPos + 16;
    int jumpioTop = yPos;
    int jumpioBottom = yPos + 16;
    int yOffset = 16;
    for (int y = 0; y < 15; y++) {
        for (int x = 0; x < (currentState == OVERWORLD ? 162 : 80); x++) {
            int tileLeft = x * TILE_WIDTH;
            int tileRight = tileLeft + TILE_WIDTH;
            int tileTop = y * TILE_HEIGHT + yOffset;
            int tileBottom = tileTop + TILE_HEIGHT;

            if (currentState == OVERWORLD) {
                // OVERWORLD collision logic goes here
                // Check for collision with solid tiles
                if (backgroundMap[y][x] == 1 || backgroundMap[y][x] == 14 || backgroundMap[y][x] == 15) {
                    if (jumpioRight > tileLeft && jumpioLeft < tileRight &&
                        jumpioBottom > tileTop && jumpioTop < tileBottom) {
                        handleCollision(jumpioLeft, jumpioRight, jumpioTop, jumpioBottom, 
                                        tileLeft, tileRight, tileTop, tileBottom);
                        jumpioGrounded = true;
                    }
                }

                // Special handling for question mark box
                if (backgroundMap[y][x] == 13) {
                    if (jumpioBottom > tileTop && jumpioTop < tileBottom &&
                        jumpioRight > tileLeft && jumpioLeft < tileRight) {
                        if (yPos < tileBottom && yPos > tileTop) { // Player hits from below
                            handleCollision(jumpioLeft, jumpioRight, jumpioTop, jumpioBottom, 
                                            tileLeft, tileRight, tileTop, tileBottom);
                            backgroundMap[y][x] = 15; // Change to empty box
                            boxCount++;
                            int randChance = random(100); // Random number between 0 and 99

                            if (randChance < 90 || hasKey || keySpawned) {
                                // 90% chance to spawn coins or if player already has a key
                                if (y > 0) {
                                    backgroundMap[y - 1][x] = 16; // Temporarily change to coin tile
                                    int coinsGained = random(1, 20); // Randomly decide number of coins
                                    score += coinsGained * 100;
                                    coins += coinsGained;
                                    coinsGained = 0;
                                    if (coins >= 100) {
                                        lives++;
                                        coins -= 100;
                                        score += 5000;
                                    }
                                    coinChangeTime = millis(); // Start timer for coin
                                    coinTileX = x;
                                    coinTileY = y - 1;
                                }
                            } else {
                                // 10% chance to spawn a key and player doesn't have a key
                                if (y > 0 && !keySpawned) {
                                    backgroundMap[y - 1][x] = 18; // Change to key tile
                                    keySpawned = true;
                                }
                            }
                        } else {
                            handleCollision(jumpioLeft, jumpioRight, jumpioTop, jumpioBottom, 
                                            tileLeft, tileRight, tileTop, tileBottom);
                        }
                    }
                }
                // Logic to handle door collisions
                if (backgroundMap[y][x] >= 19 && backgroundMap[y][x] <= 22) { 
                    if (jumpioRight > tileLeft && jumpioLeft < tileRight &&
                        jumpioBottom > tileTop && jumpioTop < tileBottom) {
                        if (hasKey) {
                            // Change map logic when colliding with a door and having the key
                            currentState = BOSS_LEVEL;
                            hasKey = false;
                            mapClearedCounter = 0;
                            speedTrigger = true;
                        }
                    }
                }
                // Special handling for key tile
                if (backgroundMap[y][x] == 18) {
                    if (jumpioRight > tileLeft && jumpioLeft < tileRight &&
                        jumpioBottom > tileTop && jumpioTop < tileBottom) {
                            score += (20000 * (jumpioSpeedMultiplier + squishMultiplier));
                        // Player collected the key
                        hasKey = true;
                        keySpawned = false;
                        backgroundMap[y][x] = 0; // Change key tile back to sky
                    }
                }
            } else if (currentState == BOSS_LEVEL) {
                // BOSS_LEVEL collision logic goes here
                // Check for collision with solid tiles
                if (BossMap1[y][x] == 1 || BossMap1[y][x] == 4 || BossMap1[y][x] == 5) {
                    if (jumpioRight > tileLeft && jumpioLeft < tileRight &&
                        jumpioBottom > tileTop && jumpioTop < tileBottom) {
                        handleCollision(jumpioLeft, jumpioRight, jumpioTop, jumpioBottom, 
                                        tileLeft, tileRight, tileTop, tileBottom);
                        jumpioGrounded = true;
                    }
                }
                if (BossMap1[y][x] == 8 && buttonIsPressed == true) {
                    if (jumpioRight > tileLeft && jumpioLeft < tileRight &&
                        jumpioBottom > tileTop && jumpioTop < tileBottom) {
                        handleCollision(jumpioLeft, jumpioRight, jumpioTop, jumpioBottom, 
                                        tileLeft, tileRight, tileTop, tileBottom);
                        jumpioGrounded = true;
                    }
                }
                if (BossMap1[y][x] == 9) {
                    if (jumpioRight > tileLeft && jumpioLeft < tileRight &&
                        jumpioBottom > tileTop && jumpioTop < tileBottom && !buttonIsPressed) {
                            score += (20000 * (jumpioSpeedMultiplier * squishMultiplier));
                        buttonIsPressed = true;
                    }
                }
                // Special handling for question mark box
                if (BossMap1[y][x] == 3) {
                    if (jumpioBottom > tileTop && jumpioTop < tileBottom &&
                        jumpioRight > tileLeft && jumpioLeft < tileRight) {
                        if (yPos < tileBottom && yPos > tileTop) { // Player hits from below
                            handleCollision(jumpioLeft, jumpioRight, jumpioTop, jumpioBottom, 
                                            tileLeft, tileRight, tileTop, tileBottom);
                            BossMap1[y][x] = 5; // Change to empty box

                            int randChance = random(100); // Random number between 0 and 99

                            if (randChance < 95) {
                                // 95% chance to spawn coins or if player already has a key
                                if (y > 0) {
                                    BossMap1[y - 1][x] = 6; // Temporarily change to coin tile
                                    int coinsGained = random(1, 20); // Randomly decide number of coins
                                    score += coinsGained * 100;
                                    coins += coinsGained;
                                    coinsGained = 0;
                                    if (coins >= 100) {
                                        lives++;
                                        coins -= 100;
                                        score += 5000;
                                    }
                                    coinChangeTime = millis(); // Start timer for coin
                                    coinTileX = x;
                                    coinTileY = y - 1;
                                }
                            } else {
                                // 5% chance to spawn a key and player doesn't have a key
                                if (y > 0) {
                                    BossMap1[y - 1][x] = 7; // Temporarily change to Life tile
                                    lives++;
                            }
                                    coinChangeTime = millis(); // Start timer for coin
                                    coinTileX = x;
                                    coinTileY = y - 1;
                            }
                        } else {
                            handleCollision(jumpioLeft, jumpioRight, jumpioTop, jumpioBottom, 
                                            tileLeft, tileRight, tileTop, tileBottom);
                        }
                    }
                }
                }
            }
        }

    // Check if it's time to remove the coin for OVERWORLD
    if (currentState == OVERWORLD && millis() - coinChangeTime >= 200 && coinTileX != -1 && coinTileY != -1) {
        backgroundMap[coinTileY][coinTileX] = 0;
        resetCoinVariables();
    }

    // Check if it's time to remove the coin for BOSS_LEVEL
    if (currentState == BOSS_LEVEL && millis() - coinChangeTime >= 200 && coinTileX != -1 && coinTileY != -1) {
        BossMap1[coinTileY][coinTileX] = 0;
        resetCoinVariables();
    }
}
void resetCoinVariables() {
    coinChangeTime = 0;
    coinTileX = -1;
    coinTileY = -1;
    boxCount++;
}
void handleCollision(int jumpioLeft, int jumpioRight, int jumpioTop, int jumpioBottom, int tileLeft, int tileRight, int tileTop, int tileBottom) {
    int collisionBuffer = 4; // A small buffer to make collisions more natural

    // Top Collision
    if (jumpioBottom > tileTop && jumpioTop < tileTop) {
        yPos = tileTop - 16; // Adjust Jumpio's position to be on top of the tile
        jumpVelocity = 0;
        jumpioGrounded = true;
        isJumping = false;
        return;
    }

    // Bottom Collision
    if (jumpioTop < tileBottom && jumpioBottom > tileBottom) {
        yPos = tileBottom; // Adjust Jumpio's position to the bottom of the tile
        jumpVelocity = maxDescentSpeed;
        return;
    }

  // Side Collisions
  if (jumpioBottom > tileTop + collisionBuffer && jumpioTop < tileBottom - collisionBuffer) {
    // Left Collision
    if (jumpioRight > tileLeft && jumpioLeft < tileLeft) {
        xPos = tileLeft - 16; // Adjust to the left of the tile

        // Check if Jumpio is moving towards the tile
        if (jumpioSpeedMultiplier > 0) {
            previousSpeedMultiplier = jumpioSpeedMultiplier;
            jumpioSpeedMultiplier = 0; // Stop horizontal movement
        }

        return;
    }

  }

        // Right Collision
        if (jumpioLeft < tileRight && jumpioRight > tileRight) {
            xPos = tileRight; // Adjust to the right of the tile
            return;
        }
}
void updateCameraPosition() {
        // Only move the camera when Jumpio is beyond the center of the screen
        if (xPos > screenCenter) {
            cameraPosX = xPos - screenCenter;
        } else {
            cameraPosX = 0;
  }
}
void gameOver(){
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(2);
    tft.print("Game Over!");
    tft.setTextSize(1);
    tft.setCursor(0, 100);
    tft.setTextColor(TFT_RED);
    tft.print("You have failed to save the kingdom.");
    tft.setCursor(0, 110);
    tft.print("Browser's reign continues....");
    tft.setCursor(0, 200);
    tft.setTextColor(TFT_WHITE);
    tft.print("Score: "); tft.print(score);
    delay(2500);
    if(score > highScore.score){
      highScore.score = score;
      getInitials();
      saveHighScore();
      displayHighScore();
      while(true){
   }
    } else{
        while(true){
        }
      }
}
void update() {
  // Handle dashing
        if (isDashing) {
            gravity = 0.6;
            unsigned long dashElapsedTime = millis() - dashStartTime;
            if (dashElapsedTime < dashDuration) {
                // Change to the JumpioDash1 sprite
                sprite.pushImage(0, 0, 16, 16, JumpioDash1);
            } else {
              gravity = 0.9;
              jumpioSpeedMultiplier = previousSpeedMultiplier; // Reset speed after dash
                // End the dash
                isDashing = false;
                // Switch back to the previous sprite
                const unsigned short* currentSprite = jumpingSprite ? JumpioJump : Jumpio;
                sprite.pushImage(0, 0, 16, 16, currentSprite);
            }
        }
  remainingLives = lives + 1;
    int oldXPos = xPos; // Store previous position
    int oldYPos = yPos;
    // Update xPos for movement with speed multiplier
    xPos += 2 * jumpioSpeedMultiplier; // Adjust speed as needed
    // Update camera position
    updateCameraPosition();
    if (yPos >= 240) {
        reset();
        resetJumpio();
    }
    // Check if the camera position exceeds the level boundaries
    int cameraLimit = getCameraLimit();
    if (cameraPosX > cameraLimit) {
        cameraPosX = cameraLimit;
    }
    updateJump();
    // Apply gravity if not grounded
    if (!jumpioGrounded || isJumping) {
        jumpVelocity += gravity;
        yPos += jumpVelocity;
    }
    // Synchronize the jumpioGrounded state
    if (isOnBox(xPos, yPos)) {
        jumpioGrounded = true;
    }
    // Check if Jumpio has reached the edge of the map
    if (xPos >= 2592 && currentState == OVERWORLD) {
        xPos = 0;
        mapCleared = true;
        if (cameraPosX != 0) {
            cameraPosX = 0;
        }
    } else if (xPos >= 1280 && currentState == BOSS_LEVEL) {  //do the same in the boss level
        xPos = 0;
        mapCleared = true;
        if (cameraPosX != 0) {
            cameraPosX = 0;
        }
    }
    
    // Determine if state has changed
    bool stateChanged = oldXPos != xPos || oldYPos != yPos;
    // Only redraw if there is a change
    if (stateChanged) {
        const unsigned short* currentSprite;
        if (isDashing) {
            // Handle sprite toggle for dashing
            if (millis() - lastDashToggleTime > 15) {
                lastDashToggleTime = millis();
                usingJumpioSprite = !usingJumpioSprite; // Toggle the sprite
            }
            currentSprite = usingJumpioSprite ? JumpioDash1 : JumpioDash2;
        } else if (isJumping) {
            // If jumping, use the jumping sprite
            currentSprite = JumpioJump;
        } else {
            // Otherwise, use the moving sprite and normal sprite
            currentSprite = usingJumpioSprite ? Jumpio : JumpioMove;
            movementCounter++;
            if (movementCounter >= 8) {
                movementCounter = 0;
                usingJumpioSprite = !usingJumpioSprite;
            }
        }
        // Update the sprite
        sprite.pushImage(0, 0, 16, 16, currentSprite);
        if (yPos <= 16){
      if (currentState == OVERWORLD) {
      sprite.fillSprite(TFT_CYAN);
      } else {
        sprite.fillSprite(TFT_BLACK);
      }
    }
        sprite.pushSprite(xPos - cameraPosX, yPos, TFT_WHITE);
    }
}
};

