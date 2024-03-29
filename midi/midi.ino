/* Tiny MIDI Player - see http://www.technoblogy.com/show?2E6L

   David Johnson-Davies - www.technoblogy.com - 12th December 2018
   ATtiny85 @ 16 MHz (internal PLL; 4.3 V BOD)
   
   CC BY 4.0
   Licensed under a Creative Commons Attribution 4.0 International license: 
   http://creativecommons.org/licenses/by/4.0/
*/

// Bach Fugue in D Minor
const uint8_t Tune[] PROGMEM = {
  0x4d, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x01, 0x00, 0x01,
  0x03, 0xc0, 0x4d, 0x54, 0x72, 0x6b, 0x00, 0x00, 0x0a, 0x7e, 0x00, 0xff,
  0x03, 0x13, 0x4d, 0x75, 0x73, 0x69, 0x63, 0x42, 0x6f, 0x78, 0x4d, 0x61,
  0x6e, 0x69, 0x61, 0x63, 0x73, 0x2e, 0x63, 0x6f, 0x6d, 0x00, 0xc0, 0x0a,
  0x00, 0x90, 0x53, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x00, 0x90, 0x4a, 0x7f,
  0x00, 0xff, 0x51, 0x03, 0x0c, 0x35, 0x00, 0x81, 0x70, 0x80, 0x53, 0x7f,
  0x00, 0x80, 0x43, 0x7f, 0x00, 0x80, 0x4a, 0x7f, 0x81, 0x70, 0x90, 0x43,
  0x7f, 0x00, 0x90, 0x4f, 0x7f, 0x00, 0x90, 0x47, 0x7f, 0x81, 0x70, 0x80,
  0x43, 0x7f, 0x00, 0x80, 0x4f, 0x7f, 0x00, 0x80, 0x47, 0x7f, 0x81, 0x70,
  0x90, 0x42, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x00, 0x90, 0x4a, 0x7f, 0x81,
  0x70, 0x80, 0x42, 0x7f, 0x00, 0x80, 0x45, 0x7f, 0x00, 0x80, 0x4a, 0x7f,
  0x81, 0x70, 0x90, 0x42, 0x7f, 0x00, 0x90, 0x4c, 0x7f, 0x81, 0x70, 0x80,
  0x42, 0x7f, 0x00, 0x80, 0x4c, 0x7f, 0x00, 0x90, 0x4e, 0x7f, 0x81, 0x70,
  0x80, 0x4e, 0x7f, 0x00, 0x90, 0x40, 0x7f, 0x00, 0x90, 0x4f, 0x7f, 0x00,
  0x90, 0x47, 0x7f, 0x81, 0x70, 0x80, 0x40, 0x7f, 0x00, 0x80, 0x4f, 0x7f,
  0x00, 0x80, 0x47, 0x7f, 0x81, 0x70, 0x90, 0x43, 0x7f, 0x00, 0x90, 0x40,
  0x7f, 0x00, 0x90, 0x4c, 0x7f, 0x81, 0x70, 0x80, 0x43, 0x7f, 0x00, 0x80,
  0x40, 0x7f, 0x00, 0x80, 0x4c, 0x7f, 0x81, 0x70, 0x90, 0x42, 0x7f, 0x00,
  0x90, 0x3e, 0x7f, 0x00, 0x90, 0x47, 0x7f, 0x81, 0x70, 0x80, 0x42, 0x7f,
  0x00, 0x80, 0x3e, 0x7f, 0x00, 0x80, 0x47, 0x7f, 0x81, 0x70, 0x90, 0x3e,
  0x7f, 0x81, 0x70, 0x80, 0x3e, 0x7f, 0x81, 0x70, 0x90, 0x3c, 0x7f, 0x00,
  0x90, 0x4c, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x81, 0x70, 0x80, 0x3c, 0x7f,
  0x00, 0x80, 0x4c, 0x7f, 0x00, 0x80, 0x43, 0x7f, 0x81, 0x70, 0x90, 0x45,
  0x7f, 0x00, 0x90, 0x48, 0x7f, 0x00, 0x90, 0x3c, 0x7f, 0x81, 0x70, 0x80,
  0x45, 0x7f, 0x00, 0x80, 0x48, 0x7f, 0x00, 0x80, 0x3c, 0x7f, 0x81, 0x70,
  0x90, 0x3e, 0x7f, 0x00, 0x90, 0x42, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x81,
  0x70, 0x80, 0x3e, 0x7f, 0x00, 0x80, 0x42, 0x7f, 0x00, 0x80, 0x45, 0x7f,
  0x81, 0x70, 0x90, 0x47, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x81, 0x70, 0x80,
  0x47, 0x7f, 0x00, 0x80, 0x45, 0x7f, 0x00, 0x90, 0x48, 0x7f, 0x81, 0x70,
  0x80, 0x48, 0x7f, 0x00, 0x90, 0x42, 0x7f, 0x00, 0x90, 0x4a, 0x7f, 0x81,
  0x70, 0x80, 0x42, 0x7f, 0x00, 0x80, 0x4a, 0x7f, 0x00, 0x90, 0x47, 0x7f,
  0x81, 0x70, 0x80, 0x47, 0x7f, 0x00, 0x90, 0x3e, 0x7f, 0x00, 0x90, 0x48,
  0x7f, 0x81, 0x70, 0x80, 0x3e, 0x7f, 0x00, 0x80, 0x48, 0x7f, 0x00, 0x90,
  0x45, 0x7f, 0x81, 0x70, 0x80, 0x45, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x00,
  0x90, 0x48, 0x7f, 0x81, 0x70, 0x80, 0x43, 0x7f, 0x00, 0x80, 0x48, 0x7f,
  0x00, 0x90, 0x47, 0x7f, 0x81, 0x70, 0x80, 0x47, 0x7f, 0x00, 0x90, 0x3e,
  0x7f, 0x00, 0x90, 0x45, 0x7f, 0x81, 0x70, 0x80, 0x3e, 0x7f, 0x00, 0x80,
  0x45, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x81, 0x70, 0x80, 0x43, 0x7f, 0x00,
  0x90, 0x37, 0x7f, 0x00, 0x90, 0x4a, 0x7f, 0x00, 0x90, 0x53, 0x7f, 0x81,
  0x70, 0x80, 0x37, 0x7f, 0x00, 0x80, 0x4a, 0x7f, 0x00, 0x80, 0x53, 0x7f,
  0x00, 0x90, 0x3e, 0x7f, 0x81, 0x70, 0x80, 0x3e, 0x7f, 0x00, 0x90, 0x4f,
  0x7f, 0x00, 0x90, 0x40, 0x7f, 0x00, 0x90, 0x47, 0x7f, 0x81, 0x70, 0x80,
  0x4f, 0x7f, 0x00, 0x80, 0x40, 0x7f, 0x00, 0x80, 0x47, 0x7f, 0x00, 0x90,
  0x42, 0x7f, 0x81, 0x70, 0x80, 0x42, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x00,
  0x90, 0x4c, 0x7f, 0x00, 0x90, 0x49, 0x7f, 0x81, 0x70, 0x80, 0x43, 0x7f,
  0x00, 0x80, 0x4c, 0x7f, 0x00, 0x80, 0x49, 0x7f, 0x00, 0x90, 0x45, 0x7f,
  0x81, 0x70, 0x80, 0x45, 0x7f, 0x00, 0x90, 0x4c, 0x7f, 0x00, 0x90, 0x49,
  0x7f, 0x00, 0x90, 0x43, 0x7f, 0x81, 0x70, 0x80, 0x4c, 0x7f, 0x00, 0x80,
  0x49, 0x7f, 0x00, 0x80, 0x43, 0x7f, 0x00, 0x90, 0x42, 0x7f, 0x00, 0x90,
  0x4e, 0x7f, 0x00, 0x90, 0x4a, 0x7f, 0x81, 0x70, 0x80, 0x42, 0x7f, 0x00,
  0x80, 0x4e, 0x7f, 0x00, 0x80, 0x4a, 0x7f, 0x00, 0x90, 0x4f, 0x7f, 0x00,
  0x90, 0x40, 0x7f, 0x00, 0x90, 0x4c, 0x7f, 0x81, 0x70, 0x80, 0x4f, 0x7f,
  0x00, 0x80, 0x40, 0x7f, 0x00, 0x80, 0x4c, 0x7f, 0x00, 0x90, 0x3e, 0x7f,
  0x81, 0x70, 0x80, 0x3e, 0x7f, 0x00, 0x90, 0x40, 0x7f, 0x00, 0x90, 0x49,
  0x7f, 0x00, 0x90, 0x4c, 0x7f, 0x81, 0x70, 0x80, 0x40, 0x7f, 0x00, 0x80,
  0x49, 0x7f, 0x00, 0x80, 0x4c, 0x7f, 0x00, 0x90, 0x42, 0x7f, 0x81, 0x70,
  0x80, 0x42, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x00, 0x90, 0x49, 0x7f, 0x00,
  0x90, 0x45, 0x7f, 0x81, 0x70, 0x80, 0x43, 0x7f, 0x00, 0x80, 0x49, 0x7f,
  0x00, 0x80, 0x45, 0x7f, 0x81, 0x70, 0x90, 0x47, 0x7f, 0x00, 0x90, 0x4a,
  0x7f, 0x81, 0x70, 0x80, 0x47, 0x7f, 0x00, 0x80, 0x4a, 0x7f, 0x00, 0x90,
  0x49, 0x7f, 0x00, 0x90, 0x4c, 0x7f, 0x81, 0x70, 0x80, 0x49, 0x7f, 0x00,
  0x80, 0x4c, 0x7f, 0x00, 0x90, 0x4e, 0x7f, 0x00, 0x90, 0x3e, 0x7f, 0x81,
  0x70, 0x80, 0x4e, 0x7f, 0x00, 0x80, 0x3e, 0x7f, 0x00, 0x90, 0x4a, 0x7f,
  0x81, 0x70, 0x80, 0x4a, 0x7f, 0x00, 0x90, 0x4f, 0x7f, 0x00, 0x90, 0x49,
  0x7f, 0x81, 0x70, 0x80, 0x4f, 0x7f, 0x00, 0x80, 0x49, 0x7f, 0x00, 0x90,
  0x4c, 0x7f, 0x81, 0x70, 0x80, 0x4c, 0x7f, 0x00, 0x90, 0x3e, 0x7f, 0x00,
  0x90, 0x4e, 0x7f, 0x81, 0x70, 0x80, 0x3e, 0x7f, 0x00, 0x80, 0x4e, 0x7f,
  0x00, 0x90, 0x4a, 0x7f, 0x81, 0x70, 0x80, 0x4a, 0x7f, 0x00, 0x90, 0x51,
  0x7f, 0x00, 0x90, 0x42, 0x7f, 0x81, 0x70, 0x80, 0x51, 0x7f, 0x00, 0x80,
  0x42, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x81, 0x70, 0x80, 0x43, 0x7f, 0x00,
  0x90, 0x4f, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x81, 0x70, 0x80, 0x4f, 0x7f,
  0x00, 0x80, 0x45, 0x7f, 0x00, 0x90, 0x4e, 0x7f, 0x81, 0x70, 0x80, 0x4e,
  0x7f, 0x00, 0x90, 0x4c, 0x7f, 0x00, 0x90, 0x39, 0x7f, 0x81, 0x70, 0x80,
  0x4c, 0x7f, 0x00, 0x80, 0x39, 0x7f, 0x00, 0x90, 0x4e, 0x7f, 0x81, 0x70,
  0x80, 0x4e, 0x7f, 0x00, 0x90, 0x4a, 0x7f, 0x00, 0x90, 0x3e, 0x7f, 0x81,
  0x70, 0x80, 0x4a, 0x7f, 0x00, 0x80, 0x3e, 0x7f, 0x85, 0x50, 0x90, 0x42,
  0x7f, 0x00, 0x90, 0x3e, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x81, 0x70, 0x80,
  0x42, 0x7f, 0x00, 0x80, 0x3e, 0x7f, 0x00, 0x80, 0x45, 0x7f, 0x81, 0x70,
  0x90, 0x4a, 0x7f, 0x00, 0x90, 0x39, 0x7f, 0x00, 0x90, 0x42, 0x7f, 0x00,
  0x90, 0x45, 0x7f, 0x81, 0x70, 0x80, 0x4a, 0x7f, 0x00, 0x80, 0x39, 0x7f,
  0x00, 0x80, 0x42, 0x7f, 0x00, 0x80, 0x45, 0x7f, 0x81, 0x70, 0x90, 0x4e,
  0x7f, 0x00, 0x90, 0x43, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x00, 0x90, 0x4a,
  0x7f, 0x81, 0x70, 0x80, 0x4e, 0x7f, 0x00, 0x80, 0x43, 0x7f, 0x00, 0x80,
  0x45, 0x7f, 0x00, 0x80, 0x4a, 0x7f, 0x00, 0x90, 0x42, 0x7f, 0x81, 0x70,
  0x80, 0x42, 0x7f, 0x00, 0x90, 0x40, 0x7f, 0x81, 0x70, 0x80, 0x40, 0x7f,
  0x00, 0x90, 0x3e, 0x7f, 0x81, 0x70, 0x80, 0x3e, 0x7f, 0x00, 0x90, 0x4f,
  0x7f, 0x00, 0x90, 0x45, 0x7f, 0x81, 0x70, 0x80, 0x4f, 0x7f, 0x00, 0x80,
  0x45, 0x7f, 0x00, 0x90, 0x4e, 0x7f, 0x81, 0x70, 0x80, 0x4e, 0x7f, 0x00,
  0x90, 0x4c, 0x7f, 0x00, 0x90, 0x48, 0x7f, 0x81, 0x70, 0x80, 0x4c, 0x7f,
  0x00, 0x80, 0x48, 0x7f, 0x00, 0x90, 0x4a, 0x7f, 0x81, 0x70, 0x80, 0x4a,
  0x7f, 0x00, 0x90, 0x47, 0x7f, 0x00, 0x90, 0x4f, 0x7f, 0x00, 0x90, 0x4a,
  0x7f, 0x81, 0x70, 0x80, 0x47, 0x7f, 0x00, 0x80, 0x4f, 0x7f, 0x00, 0x80,
  0x4a, 0x7f, 0x00, 0x90, 0x48, 0x7f, 0x81, 0x70, 0x80, 0x48, 0x7f, 0x00,
  0x90, 0x47, 0x7f, 0x00, 0x90, 0x4a, 0x7f, 0x81, 0x70, 0x80, 0x47, 0x7f,
  0x00, 0x80, 0x4a, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x81, 0x70, 0x80, 0x45,
  0x7f, 0x00, 0x90, 0x43, 0x7f, 0x00, 0x90, 0x4a, 0x7f, 0x00, 0x90, 0x53,
  0x7f, 0x81, 0x70, 0x80, 0x43, 0x7f, 0x00, 0x80, 0x4a, 0x7f, 0x00, 0x80,
  0x53, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x81, 0x70, 0x80, 0x45, 0x7f, 0x00,
  0x90, 0x47, 0x7f, 0x00, 0x90, 0x4f, 0x7f, 0x81, 0x70, 0x80, 0x47, 0x7f,
  0x00, 0x80, 0x4f, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x81, 0x70, 0x80, 0x43,
  0x7f, 0x00, 0x90, 0x4c, 0x7f, 0x00, 0x90, 0x48, 0x7f, 0x81, 0x70, 0x80,
  0x4c, 0x7f, 0x00, 0x80, 0x48, 0x7f, 0x00, 0x90, 0x4a, 0x7f, 0x81, 0x70,
  0x80, 0x4a, 0x7f, 0x00, 0x90, 0x4e, 0x7f, 0x00, 0x90, 0x48, 0x7f, 0x81,
  0x70, 0x80, 0x4e, 0x7f, 0x00, 0x80, 0x48, 0x7f, 0x00, 0x90, 0x47, 0x7f,
  0x00, 0x90, 0x4f, 0x7f, 0x81, 0x70, 0x80, 0x47, 0x7f, 0x00, 0x80, 0x4f,
  0x7f, 0x00, 0x90, 0x51, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x81, 0x70, 0x80,
  0x51, 0x7f, 0x00, 0x80, 0x45, 0x7f, 0x00, 0x90, 0x47, 0x7f, 0x81, 0x70,
  0x80, 0x47, 0x7f, 0x00, 0x90, 0x4e, 0x7f, 0x00, 0x90, 0x48, 0x7f, 0x81,
  0x70, 0x80, 0x4e, 0x7f, 0x00, 0x80, 0x48, 0x7f, 0x00, 0x90, 0x45, 0x7f,
  0x81, 0x70, 0x80, 0x45, 0x7f, 0x00, 0x90, 0x4b, 0x7f, 0x00, 0x90, 0x47,
  0x7f, 0x00, 0x90, 0x42, 0x7f, 0x81, 0x70, 0x80, 0x4b, 0x7f, 0x00, 0x80,
  0x47, 0x7f, 0x00, 0x80, 0x42, 0x7f, 0x81, 0x70, 0x90, 0x3b, 0x7f, 0x81,
  0x70, 0x80, 0x3b, 0x7f, 0x81, 0x70, 0x90, 0x47, 0x7f, 0x81, 0x70, 0x80,
  0x47, 0x7f, 0x00, 0x90, 0x49, 0x7f, 0x81, 0x70, 0x80, 0x49, 0x7f, 0x00,
  0x90, 0x4b, 0x7f, 0x00, 0x90, 0x42, 0x7f, 0x81, 0x70, 0x80, 0x4b, 0x7f,
  0x00, 0x80, 0x42, 0x7f, 0x00, 0x90, 0x4c, 0x7f, 0x81, 0x70, 0x80, 0x4c,
  0x7f, 0x00, 0x90, 0x4e, 0x7f, 0x00, 0x90, 0x4b, 0x7f, 0x81, 0x70, 0x80,
  0x4e, 0x7f, 0x00, 0x80, 0x4b, 0x7f, 0x00, 0x90, 0x4f, 0x7f, 0x81, 0x70,
  0x80, 0x4f, 0x7f, 0x00, 0x90, 0x4b, 0x7f, 0x00, 0x90, 0x4e, 0x7f, 0x81,
  0x70, 0x80, 0x4b, 0x7f, 0x00, 0x80, 0x4e, 0x7f, 0x00, 0x90, 0x4c, 0x7f,
  0x81, 0x70, 0x80, 0x4c, 0x7f, 0x00, 0x90, 0x4b, 0x7f, 0x00, 0x90, 0x42,
  0x7f, 0x81, 0x70, 0x80, 0x4b, 0x7f, 0x00, 0x80, 0x42, 0x7f, 0x00, 0x90,
  0x4c, 0x7f, 0x81, 0x70, 0x80, 0x4c, 0x7f, 0x00, 0x90, 0x4b, 0x7f, 0x00,
  0x90, 0x4e, 0x7f, 0x81, 0x70, 0x80, 0x4b, 0x7f, 0x00, 0x80, 0x4e, 0x7f,
  0x00, 0x90, 0x4f, 0x7f, 0x81, 0x70, 0x80, 0x4f, 0x7f, 0x00, 0x90, 0x51,
  0x7f, 0x00, 0x90, 0x47, 0x7f, 0x81, 0x70, 0x80, 0x51, 0x7f, 0x00, 0x80,
  0x47, 0x7f, 0x00, 0x90, 0x53, 0x7f, 0x81, 0x70, 0x80, 0x53, 0x7f, 0x00,
  0x90, 0x51, 0x7f, 0x00, 0x90, 0x47, 0x7f, 0x81, 0x70, 0x80, 0x51, 0x7f,
  0x00, 0x80, 0x47, 0x7f, 0x00, 0x90, 0x4f, 0x7f, 0x00, 0x90, 0x49, 0x7f,
  0x81, 0x70, 0x80, 0x4f, 0x7f, 0x00, 0x80, 0x49, 0x7f, 0x00, 0x90, 0x4b,
  0x7f, 0x00, 0x90, 0x4e, 0x7f, 0x81, 0x70, 0x80, 0x4b, 0x7f, 0x00, 0x80,
  0x4e, 0x7f, 0x00, 0x90, 0x4f, 0x7f, 0x81, 0x70, 0x80, 0x4f, 0x7f, 0x00,
  0x90, 0x47, 0x7f, 0x00, 0x90, 0x51, 0x7f, 0x81, 0x70, 0x80, 0x47, 0x7f,
  0x00, 0x80, 0x51, 0x7f, 0x00, 0x90, 0x53, 0x7f, 0x81, 0x70, 0x80, 0x53,
  0x7f, 0x00, 0x90, 0x43, 0x7f, 0x00, 0x90, 0x54, 0x7f, 0x81, 0x70, 0x80,
  0x43, 0x7f, 0x00, 0x80, 0x54, 0x7f, 0x00, 0x90, 0x42, 0x7f, 0x00, 0x90,
  0x51, 0x7f, 0x81, 0x70, 0x80, 0x42, 0x7f, 0x00, 0x80, 0x51, 0x7f, 0x00,
  0x90, 0x53, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x81, 0x70, 0x80, 0x53, 0x7f,
  0x00, 0x80, 0x43, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x81, 0x70, 0x80, 0x45,
  0x7f, 0x00, 0x90, 0x4c, 0x7f, 0x00, 0x90, 0x47, 0x7f, 0x81, 0x70, 0x80,
  0x4c, 0x7f, 0x00, 0x80, 0x47, 0x7f, 0x81, 0x70, 0x90, 0x4e, 0x7f, 0x00,
  0x90, 0x3b, 0x7f, 0x81, 0x70, 0x80, 0x4e, 0x7f, 0x00, 0x80, 0x3b, 0x7f,
  0x00, 0x90, 0x4b, 0x7f, 0x81, 0x70, 0x80, 0x4b, 0x7f, 0x00, 0x90, 0x4c,
  0x7f, 0x00, 0x90, 0x40, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x81, 0x70, 0x80,
  0x4c, 0x7f, 0x00, 0x80, 0x40, 0x7f, 0x00, 0x80, 0x43, 0x7f, 0x81, 0x70,
  0x90, 0x3b, 0x7f, 0x81, 0x70, 0x80, 0x3b, 0x7f, 0x81, 0x70, 0x90, 0x40,
  0x7f, 0x00, 0x90, 0x47, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x81, 0x70, 0x80,
  0x40, 0x7f, 0x00, 0x80, 0x47, 0x7f, 0x00, 0x80, 0x43, 0x7f, 0x00, 0x90,
  0x42, 0x7f, 0x81, 0x70, 0x80, 0x42, 0x7f, 0x00, 0x90, 0x4c, 0x7f, 0x00,
  0x90, 0x43, 0x7f, 0x00, 0x90, 0x47, 0x7f, 0x81, 0x70, 0x80, 0x4c, 0x7f,
  0x00, 0x80, 0x43, 0x7f, 0x00, 0x80, 0x47, 0x7f, 0x00, 0x90, 0x45, 0x7f,
  0x81, 0x70, 0x80, 0x45, 0x7f, 0x00, 0x90, 0x4a, 0x7f, 0x00, 0x90, 0x4f,
  0x7f, 0x00, 0x90, 0x47, 0x7f, 0x81, 0x70, 0x80, 0x4a, 0x7f, 0x00, 0x80,
  0x4f, 0x7f, 0x00, 0x80, 0x47, 0x7f, 0x00, 0x90, 0x48, 0x7f, 0x81, 0x70,
  0x80, 0x48, 0x7f, 0x00, 0x90, 0x4a, 0x7f, 0x81, 0x70, 0x80, 0x4a, 0x7f,
  0x00, 0x90, 0x4c, 0x7f, 0x81, 0x70, 0x80, 0x4c, 0x7f, 0x00, 0x90, 0x41,
  0x7f, 0x00, 0x90, 0x48, 0x7f, 0x81, 0x70, 0x80, 0x41, 0x7f, 0x00, 0x80,
  0x48, 0x7f, 0x00, 0x90, 0x47, 0x7f, 0x00, 0x90, 0x37, 0x7f, 0x81, 0x70,
  0x80, 0x47, 0x7f, 0x00, 0x80, 0x37, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x00,
  0x90, 0x39, 0x7f, 0x81, 0x70, 0x80, 0x45, 0x7f, 0x00, 0x80, 0x39, 0x7f,
  0x00, 0x90, 0x3b, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x81, 0x70, 0x80, 0x3b,
  0x7f, 0x00, 0x80, 0x43, 0x7f, 0x00, 0x90, 0x3c, 0x7f, 0x00, 0x90, 0x4d,
  0x7f, 0x81, 0x70, 0x80, 0x3c, 0x7f, 0x00, 0x80, 0x4d, 0x7f, 0x00, 0x90,
  0x4a, 0x7f, 0x00, 0x90, 0x3e, 0x7f, 0x81, 0x70, 0x80, 0x4a, 0x7f, 0x00,
  0x80, 0x3e, 0x7f, 0x00, 0x90, 0x4c, 0x7f, 0x00, 0x90, 0x3c, 0x7f, 0x81,
  0x70, 0x80, 0x4c, 0x7f, 0x00, 0x80, 0x3c, 0x7f, 0x00, 0x90, 0x3b, 0x7f,
  0x81, 0x70, 0x80, 0x3b, 0x7f, 0x00, 0x90, 0x39, 0x7f, 0x00, 0x90, 0x42,
  0x7f, 0x81, 0x70, 0x80, 0x39, 0x7f, 0x00, 0x80, 0x42, 0x7f, 0x00, 0x90,
  0x43, 0x7f, 0x00, 0x90, 0x37, 0x7f, 0x81, 0x70, 0x80, 0x43, 0x7f, 0x00,
  0x80, 0x37, 0x7f, 0x00, 0x90, 0x42, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x81,
  0x70, 0x80, 0x42, 0x7f, 0x00, 0x80, 0x45, 0x7f, 0x00, 0x90, 0x47, 0x7f,
  0x00, 0x90, 0x40, 0x7f, 0x81, 0x70, 0x80, 0x47, 0x7f, 0x00, 0x80, 0x40,
  0x7f, 0x00, 0x90, 0x3e, 0x7f, 0x00, 0x90, 0x48, 0x7f, 0x81, 0x70, 0x80,
  0x3e, 0x7f, 0x00, 0x80, 0x48, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x00, 0x90,
  0x3c, 0x7f, 0x81, 0x70, 0x80, 0x45, 0x7f, 0x00, 0x80, 0x3c, 0x7f, 0x00,
  0x90, 0x47, 0x7f, 0x00, 0x90, 0x3b, 0x7f, 0x81, 0x70, 0x80, 0x47, 0x7f,
  0x00, 0x80, 0x3b, 0x7f, 0x00, 0x90, 0x48, 0x7f, 0x00, 0x90, 0x39, 0x7f,
  0x81, 0x70, 0x80, 0x48, 0x7f, 0x00, 0x80, 0x39, 0x7f, 0x00, 0x90, 0x37,
  0x7f, 0x00, 0x90, 0x4a, 0x7f, 0x81, 0x70, 0x80, 0x37, 0x7f, 0x00, 0x80,
  0x4a, 0x7f, 0x00, 0x90, 0x39, 0x7f, 0x00, 0x90, 0x48, 0x7f, 0x81, 0x70,
  0x80, 0x39, 0x7f, 0x00, 0x80, 0x48, 0x7f, 0x00, 0x90, 0x3b, 0x7f, 0x00,
  0x90, 0x4a, 0x7f, 0x81, 0x70, 0x80, 0x3b, 0x7f, 0x00, 0x80, 0x4a, 0x7f,
  0x00, 0x90, 0x4c, 0x7f, 0x00, 0x90, 0x3c, 0x7f, 0x81, 0x70, 0x80, 0x4c,
  0x7f, 0x00, 0x80, 0x3c, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x00, 0x90, 0x42,
  0x7f, 0x00, 0x90, 0x3e, 0x7f, 0x81, 0x70, 0x80, 0x45, 0x7f, 0x00, 0x80,
  0x42, 0x7f, 0x00, 0x80, 0x3e, 0x7f, 0x00, 0x90, 0x39, 0x7f, 0x81, 0x70,
  0x80, 0x39, 0x7f, 0x00, 0x90, 0x42, 0x7f, 0x81, 0x70, 0x80, 0x42, 0x7f,
  0x00, 0x90, 0x39, 0x7f, 0x81, 0x70, 0x80, 0x39, 0x7f, 0x00, 0x90, 0x51,
  0x7f, 0x00, 0x90, 0x3e, 0x7f, 0x00, 0x90, 0x54, 0x7f, 0x81, 0x70, 0x80,
  0x51, 0x7f, 0x00, 0x80, 0x3e, 0x7f, 0x00, 0x80, 0x54, 0x7f, 0x00, 0x90,
  0x40, 0x7f, 0x81, 0x70, 0x80, 0x40, 0x7f, 0x00, 0x90, 0x42, 0x7f, 0x00,
  0x90, 0x4a, 0x7f, 0x00, 0x90, 0x51, 0x7f, 0x81, 0x70, 0x80, 0x42, 0x7f,
  0x00, 0x80, 0x4a, 0x7f, 0x00, 0x80, 0x51, 0x7f, 0x00, 0x90, 0x43, 0x7f,
  0x81, 0x70, 0x80, 0x43, 0x7f, 0x00, 0x90, 0x4e, 0x7f, 0x00, 0x90, 0x45,
  0x7f, 0x00, 0x90, 0x48, 0x7f, 0x81, 0x70, 0x80, 0x4e, 0x7f, 0x00, 0x80,
  0x45, 0x7f, 0x00, 0x80, 0x48, 0x7f, 0x00, 0x90, 0x47, 0x7f, 0x81, 0x70,
  0x80, 0x47, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x00, 0x90, 0x4e, 0x7f, 0x81,
  0x70, 0x80, 0x45, 0x7f, 0x00, 0x80, 0x4e, 0x7f, 0x00, 0x90, 0x43, 0x7f,
  0x00, 0x90, 0x4f, 0x7f, 0x81, 0x70, 0x80, 0x43, 0x7f, 0x00, 0x80, 0x4f,
  0x7f, 0x00, 0x90, 0x51, 0x7f, 0x00, 0x90, 0x48, 0x7f, 0x00, 0x90, 0x42,
  0x7f, 0x81, 0x70, 0x80, 0x51, 0x7f, 0x00, 0x80, 0x48, 0x7f, 0x00, 0x80,
  0x42, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x81, 0x70, 0x80, 0x43, 0x7f, 0x00,
  0x90, 0x4e, 0x7f, 0x00, 0x90, 0x45, 0x7f, 0x81, 0x70, 0x80, 0x4e, 0x7f,
  0x00, 0x80, 0x45, 0x7f, 0x00, 0x90, 0x47, 0x7f, 0x81, 0x70, 0x80, 0x47,
  0x7f, 0x00, 0x90, 0x42, 0x7f, 0x00, 0x90, 0x4a, 0x7f, 0x00, 0x90, 0x48,
  0x7f, 0x81, 0x70, 0x80, 0x42, 0x7f, 0x00, 0x80, 0x4a, 0x7f, 0x00, 0x80,
  0x48, 0x7f, 0x00, 0x90, 0x3e, 0x7f, 0x81, 0x70, 0x80, 0x3e, 0x7f, 0x00,
  0x90, 0x4a, 0x7f, 0x00, 0x90, 0x3c, 0x7f, 0x81, 0x70, 0x80, 0x4a, 0x7f,
  0x00, 0x80, 0x3c, 0x7f, 0x00, 0x90, 0x3b, 0x7f, 0x00, 0x90, 0x4c, 0x7f,
  0x81, 0x70, 0x80, 0x3b, 0x7f, 0x00, 0x80, 0x4c, 0x7f, 0x00, 0x90, 0x4e,
  0x7f, 0x00, 0x90, 0x39, 0x7f, 0x81, 0x70, 0x80, 0x4e, 0x7f, 0x00, 0x80,
  0x39, 0x7f, 0x00, 0x90, 0x4f, 0x7f, 0x00, 0x90, 0x3b, 0x7f, 0x81, 0x70,
  0x80, 0x4f, 0x7f, 0x00, 0x80, 0x3b, 0x7f, 0x00, 0x90, 0x51, 0x7f, 0x00,
  0x90, 0x3c, 0x7f, 0x81, 0x70, 0x80, 0x51, 0x7f, 0x00, 0x80, 0x3c, 0x7f,
  0x00, 0x90, 0x3e, 0x7f, 0x00, 0x90, 0x4e, 0x7f, 0x81, 0x70, 0x80, 0x3e,
  0x7f, 0x00, 0x80, 0x4e, 0x7f, 0x00, 0x90, 0x4f, 0x7f, 0x00, 0x90, 0x40,
  0x7f, 0x81, 0x70, 0x80, 0x4f, 0x7f, 0x00, 0x80, 0x40, 0x7f, 0x00, 0x90,
  0x4c, 0x7f, 0x81, 0x70, 0x80, 0x4c, 0x7f, 0x00, 0x90, 0x51, 0x7f, 0x00,
  0x90, 0x3c, 0x7f, 0x81, 0x70, 0x80, 0x51, 0x7f, 0x00, 0x80, 0x3c, 0x7f,
  0x81, 0x70, 0x90, 0x4e, 0x7f, 0x00, 0x90, 0x3e, 0x7f, 0x81, 0x70, 0x80,
  0x4e, 0x7f, 0x00, 0x80, 0x3e, 0x7f, 0x81, 0x70, 0x90, 0x32, 0x7f, 0x81,
  0x70, 0x80, 0x32, 0x7f, 0x00, 0x90, 0x43, 0x7f, 0x81, 0x70, 0x80, 0x43,
  0x7f, 0x00, 0x90, 0x4f, 0x7f, 0x00, 0x90, 0x3e, 0x7f, 0x00, 0x90, 0x4a,
  0x7f, 0x00, 0x90, 0x37, 0x7f, 0x81, 0x70, 0x80, 0x4f, 0x7f, 0x00, 0x80,
  0x3e, 0x7f, 0x00, 0x80, 0x4a, 0x7f, 0x00, 0x80, 0x37, 0x7f, 0x84, 0xbf,
  0x50, 0xb0, 0x5b, 0x00, 0x00, 0xff, 0x2f, 0x00
};

// Synth **********************************************

const int Volume = 8; // Volume: 7 = loud, 8 = medium, 9 = quiet
const int Decay = 14; // Length of note decay: 14 = maximum, 13 = medium, 12 = staccato

unsigned int Scale[] = {
10973, 11626, 12317, 13050, 13826, 14648, 15519, 16442, 17419, 18455, 19552, 20715};

const int Channels = 4;
int Chan = 0;

volatile unsigned int Acc[Channels];
volatile unsigned int Freq[Channels];
volatile unsigned int Amp[Channels];

// Generate square waves on Channels channels

ISR(TIMER0_COMPA_vect) {
  static uint8_t c;
  signed char Temp, Mask, Env, Note;
  Acc[c] = Acc[c] + Freq[c];  
  Amp[c] = Amp[c] - (Amp[c] != 0);
  Temp = Acc[c] >> 8;
  Temp = Temp & Temp<<1;
  Mask = Temp >> 7;
  Env = Amp[c] >> Volume;
  Note = (Env ^ Mask) + (Mask & 1);
  OCR1B = Note + 128;
  c = (c + 1) & 3;
}

// Tempo timing **********************************************

// Global tick counter
volatile unsigned int GlobalTicks = 0;

// Ticks timer
unsigned int Ticks() {
  unsigned int t;
  cli();
  t = GlobalTicks;
  sei();
  return t;
}

// Delay using Watchdog timer - 62.5 ticks a second
void Delay (unsigned int t) {
  unsigned int t0 = Ticks();
  while (Ticks() - t0 < t);
}

// Watchdog interrupt counts ticks
ISR(WDT_vect) {
  WDTCR |= 1<<WDIE;
  GlobalTicks++;
}

// MIDI interpreter **********************************************

unsigned int Ptr, EndBlock;
unsigned long Tempo = 500000;    // Default - microseconds per beat; ie 120bpm
unsigned int TempoDivisor;
const int Error = 0;  // Error LED on PB0
const long MThd = 0x4D546864;
const long MTrk = 0x4D54726B;

void readIgnore (int n) {
  Ptr = Ptr + n;
}

unsigned long readNumber (int n) {
  long result = 0;
  for (int i=0; i<n; i++) result = (result<<8) + pgm_read_byte(&Tune[Ptr++]);
  return result;
}

unsigned long readVariable () {
  long result = 0;
  uint8_t b;
  do {
    b = pgm_read_byte(&Tune[Ptr++]);
    result = (result<<7) + (b & 0x7F);
  } while (b & 0x80);
  return result;
}

// Flash error light n times: 1=header block, 2=track block, 3=MIDI event
void error(int n) {
  while (1) {
    for (int i=0; i<n; i++) {
      digitalWrite(Error, HIGH);
      Delay(15);
      digitalWrite(Error, LOW);
      Delay(15);
    }
  Delay(125);
  }
}

// Play note. 60 = middle C (261.63 Hz)
void noteOn (uint8_t number) {
  uint8_t octave = number/12;
  uint8_t note = number%12;
  unsigned int freq = Scale[note];
  uint8_t shift = 9-octave;
  Freq[Chan] = freq>>shift;
  Amp[Chan] = 1<<Decay;
  Chan = (Chan + 1) & 3;
}

void playMidiData () {
  Ptr = 0;                                  // Begin at start of file
  // Read header chunk
  unsigned long type = readNumber(4);
  if (type != MThd) error(1);
  unsigned long len = readNumber(4);
  unsigned int format = readNumber(2);
  unsigned int tracks = readNumber(2);
  unsigned int division = readNumber(2);    // Ticks per beat
  TempoDivisor = (long)division*16000/Tempo;

  // Read track chunks
  for (int t=0; t<tracks; t++) {
    type = readNumber(4);
    if (type != MTrk) error(2);
    len = readNumber(4);
    EndBlock = Ptr + len;

    // Parse track
    while (Ptr < EndBlock) {
      unsigned long delta = readVariable();
      uint8_t event = readNumber(1);
      uint8_t eventType = event & 0xF0;    
      if (delta > 0) Delay(delta/TempoDivisor);
      
      // Meta event
      if (event == 0xFF) {
        uint8_t mtype = readNumber(1);
        uint8_t mlen = readNumber(1);
        // Tempo
        if (mtype == 0x51) {
          Tempo = readNumber(mlen);
          TempoDivisor = (long)division*16000/Tempo;
        // Ignore other meta events
        } else readIgnore(mlen);
        
      // Note off - ignored
      } else if (eventType == 0x80) {
        uint8_t number = readNumber(1);
        uint8_t velocity = readNumber(1);
      // Note on
      } else if (eventType == 0x90) {
        uint8_t number = readNumber(1);
        uint8_t velocity = readNumber(1);
        noteOn(number);
      // Polyphonic key pressure
      } else if (eventType == 0xA0) readIgnore(2);
      // Controller change
      else if (eventType == 0xB0) readIgnore(2);
      // Program change
      else if (eventType == 0xC0) readIgnore(1);
      // Channel key pressure
      else if (eventType == 0xD0) readIgnore(1);
      // Pitch bend
      else if (eventType == 0xD0) readIgnore(2);
      else error(3);
    }
  }
}

// Setup **********************************************

void setup() {
  // Set up error light
  pinMode(Error, OUTPUT);
  digitalWrite(Error, LOW);      // Initially off
  
  // Enable 64 MHz PLL and use as source for Timer1
  PLLCSR = 1<<PCKE | 1<<PLLE;     

  // Set up Timer/Counter1 for PWM output
  TIMSK = 0;                     // Timer interrupts OFF
  TCCR1 = 1<<CS10;               // 1:1 prescale
  GTCCR = 1<<PWM1B | 2<<COM1B0;  // PWM B, clear on match
  OCR1B = 128;
  DDRB = 1<<DDB4;                // Enable PWM output on pin 4

  // Set up Timer/Counter0 for 25kHz interrupt to output samples.
  TCCR0A = 3<<WGM00;             // Fast PWM
  TCCR0B = 1<<WGM02 | 2<<CS00;   // 1/8 prescale
  OCR0A = 19;                    // Divide by 100/Channels
  TIMSK = 1<<OCIE0A;             // Enable compare match, disable overflow
 
  // Set up Watchdog timer for 16ms interrupt for ticks timer.
  WDTCR = 1<<WDIE | 0<<WDP0;     // Interrupt every 16ms
}

void loop() {
  playMidiData();
  for(;;);
}
