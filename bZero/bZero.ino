#include "IRremote.h"
#include "helper.h"

void blinkLED(pin_size_t pinNumber);

void setup()
{
  IrSender.begin(LED_PIN);

  pinMode(DOWN_BTN, INPUT_PULLUP);
  pinMode(OK_BTN, INPUT_PULLUP);
  pinMode(UP_BTN, INPUT_PULLUP);
  pinMode(25, OUTPUT);
}

void loop()
{
  int down_status = digitalRead(DOWN_BTN);
  int ok_status = digitalRead(OK_BTN);
  int up_status = digitalRead(UP_BTN);


  if (!down_status)
  {
    current_mode -= 1;
    if (current_mode < 0)
    {
      current_mode = modes_len;
    }
    blinkLED(PICO_DEFAULT_LED_PIN);
    delay(500);
  }
  
  if (!up_status)
  {
    current_mode += 1;
    if (current_mode > modes_len)
    {
      current_mode = 0;
    }
    blinkLED(PICO_DEFAULT_LED_PIN);
    delay(500);
  }

  if (!ok_status)
  {
    if (current_mode == 0)
    {
      IrSender.sendSamsung(sam_addr, sam_commands[0], 1);
      delay(50);
      IrSender.sendSamsung(sam_addr, 0x2, 0);
    }
    if (current_mode == 1)
    {
      IrSender.sendSamsung(sam_addr, sam_commands[1], 0);
    }
    if (current_mode == 2)
    {
      IrSender.sendSamsung(sam_addr, sam_commands[2], 0);
    }
    if (current_mode == 3)
    {
      IrSender.sendSamsung(sam_addr, sam_commands[3], 0);
    }
    if (current_mode == 4)
    {
      IrSender.sendSamsung(sam_addr, sam_commands[4], 0);
    }
    if (current_mode == 5)
    {
      IrSender.sendSamsung(sam_addr, sam_commands[5], 0);
    }
    delay(500);
  }
}

// receiver
void setup1()
{
  IrReceiver.begin(RECV_PIN);
}

void loop1()
{
  if (IrReceiver.decode())
  {
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.resume();
  }
}

void blinkLED(pin_size_t pinNumber)
{
  digitalWrite(pinNumber, HIGH);
  delay(100);
  digitalWrite(pinNumber, LOW);
}