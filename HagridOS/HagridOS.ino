#include <Keypad.h>
#include <STM32SD.h>
#define debug_on 1

const byte ROWS = 4; //four rows
const byte COLS = 10; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
  {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
  {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '\n'},
  {'_', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ' ', ' '}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {34, 33, 32, 31, 30, 29, 28, 27, 26, 86}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char input[60];//input buffer
int pos = 0;

char* tmpE[20];//split field

void setup() {
  Serial.begin(115200);
  Serial.println("\nInitializing");

}

void loop() {
  input[pos] = keypad.getKey();

  if (input[pos]) {
    if (input[pos] == '\n') {
      input[pos] = '\0';
      kbsplit(input);
      switch (compare(&tmpE[0])) { //switch run basic commands
        case 0://mkdir
          Serial.println("\nMKDIR");
          Serial.print(">");
          clear_input_buffer();
          break;
        case 1:
        Serial.println("\nRM DIR");
          Serial.print(">");
          clear_input_buffer();
          break;
        default:
          Serial.print("\n");
          Serial.print("hsh: ");
          Serial.print(tmpE[0]);
          Serial.print(" command not found");
          Serial.print("\n>");
          clear_input_buffer();
          break;
      }


    } else {
      Serial.print(input[pos]);
      pos++;
    }
  }
}




