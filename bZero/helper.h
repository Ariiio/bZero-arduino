#define LED_PIN 13
#define RECV_PIN 15
#define DOWN_BTN 11
#define OK_BTN 12
#define UP_BTN 10

/*
  0x7
  0xB
  0xF
  0x12
  0x10
*/

int modes[] = {0, 1, 2, 3, 4, 5};
size_t modes_len = sizeof(modes) / sizeof(modes[0]) - 1;
int current_mode = 0;

uint16_t sam_addr = 0x707;
uint16_t sam_commands[] = {0xE6, 0x7, 0xB, 0xF, 0x12, 0x10};