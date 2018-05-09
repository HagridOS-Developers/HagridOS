#include <SPI.h>
#include <RA8875.h>

#define RA8875_CS 10 //see below...

char input[60];//input buffer
int pos = 0;
char* tmpE[20];//split field

RA8875 tft = RA8875(RA8875_CS);//arduino's

void setup()
{
  Serial.begin(9600);
  tft.begin(RA8875_480x272);
  /*
    tft.setTextColor(RA8875_CYAN);
    tft.println("mkdir");//did you see it?
    tft.setTextColor(RA8875_RED);
    tft.println("rmdir");//did you see it?
    tft.setTextColor(RA8875_WHITE);
    tft.showCursor(IBEAM, true); //activate cursor iBeam blinking
  */
}

void loop()
{
  if (Serial.available() > 0) {
    input[pos] = Serial.read();
    if (input[pos] == 'N') {
      input[pos] = '\0';
      kbsplit(input);
      switch (compare(&tmpE[0])) { //switch run basic commands
        case 0://print
          if (!strcasecmp(tmpE[1], "color"))
          {
            Serial.print("\n\rprint color string");
            if (!strcasecmp(tmpE[2], "err")) {//error text
              tft.setTextColor(RA8875_RED);
              tft.print(tmpE[3]);
              Serial.println("\n\rprint error string");
            }
            if (!strcasecmp(tmpE[2], "war")) {//waring text
              tft.setTextColor(RA8875_YELLOW);
              tft.print(tmpE[3]);
              Serial.println("\n\rprint warning string");
            }
            if (!strcasecmp(tmpE[2], "run")) {//runable text
              tft.setTextColor(RA8875_GREEN);
              tft.print(tmpE[3]);
              Serial.println("\n\rprint runable string");
            }
            if (!strcasecmp(tmpE[2], "war1")) {//warning1 text
              tft.setTextColor(RA8875_MAGENTA);
              tft.print(tmpE[3]);
              Serial.println("\n\rprint waring1 string");
            }
          }
          else {
            tft.setTextColor(RA8875_WHITE);
            tft.print(tmpE[1]);
            Serial.println("\n\rprint string");
          }
          Serial.print(">");
          clear_input_buffer();
          break;

        case 1://clear
          tft.clearScreen();
          tft.setCursor(0, 0);
          Serial.println("\n\rclear screen");
          Serial.print(">");
          clear_input_buffer();
          break;

        case 2://cursor
          if (!strcasecmp(tmpE[1], "on")) {
            tft.showCursor(IBEAM, true); //activate cursor iBeam blinking
            Serial.println("\n\rcursor ON");

          } else {
            tft.showCursor(NOCURSOR, false); //deactivate cursor iBeam blinking
            Serial.println("\n\rcursor OFF");
            Serial.print(">");
          }
          Serial.print(">");
          clear_input_buffer();
          break;
        case 3://new line
          tft.println();
          Serial.println("\n\rnew line");
          Serial.print(">");
          clear_input_buffer();
          break;
        default:
          Serial.print("\n\r");
          Serial.print("hsh: ");
          Serial.print(tmpE[0]);
          Serial.print(" command not found");
          Serial.print("\n\r>");
          clear_input_buffer();
          break;
      }
    } else {
      Serial.print(input[pos]);
      pos++;
    }
  }
  delay(1);
}



