#include <Keypad.h>
#include <STM32SD.h>

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

char input[60];
int pos = 0;

char token[16];
char token1[16];
char token2[16];

void setup() {
  Serial.begin(115200);
  Serial.println("\nInitializing");

}

void loop() {
  input[pos] = keypad.getKey();

  if (input[pos]) {
    if (input[pos] == '\n') {
      sscanf(input, "%s %s %s", token, token1, token2);
      Serial.println();
      Serial.println(token);
      Serial.println(token1);
      Serial.println(token2);
      if(!strcmp(token,"mkdir"))
      {
        Serial.println("MAKE DIRECTORY");
        }
    }
    Serial.print(input[pos]);
    pos++;
  }
}



