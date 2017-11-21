/*
  MORSE CODE

  Turns an LED on and off to spell out a message. An alternative to the standard blink program.

  Created 2015
  by Oliver Gilliland
*/

void setup() {
  
  // the uppercase text to represent in morse code
  char text[] = "HELLO WORLD";

  // the desired length of a dot flash in milliseconds
  int tick = 250;

  // standard morse code dictionary
  char morse[][] = {
    ".-",     // A
    "-...",   // B
    "-.-.",   // C
    "-..",    // D
    ".",      // E
    "..-.",   // F
    "--.",    // G
    "....",   // H
    "..",     // I
    ".---",   // J
    "-.-",    // K
    ".-..",   // L
    "--",     // M
    "-.",     // N
    "---",    // O
    ".--.",   // P
    "--.-",   // Q
    ".-.",    // R
    "...",    // S
    "-",      // T
    "..-",    // U
    "...-",   // V
    ".--",    // W
    "-..-",   // X
    "-.--",   // Y
    "--.."    // Z
  };

  // initialize digital pin LED_BUILTIN as an output
  pinMode(LED_BUILTIN, OUTPUT);
  
}

// run forever
void loop() {
  
  // begin reading words
  for(byte index = 0; index < sizeof(text)/sizeof(char); index++) {
    // find letter as index for matching in morse dictionary
    char letter = (text[index] - 'A');
    
    if(letter < 0 || letter > 25) {
      // we hit a space or invalid character
      // wait for 7 ticks and move on
      digitalWrite(LED_BUILTIN, LOW);
      delay(7 * tick);
    } else {
      // loop over each part of the morse letter
      for(byte i = 0; i < sizeof(morse[letter])/sizeof(char); i++) {
        
        /* FLASH FOR A DOT OR DASH */
        digitalWrite(LED_BUILTIN, HIGH);
        if(morse[letter][i] == '-') {
          // light for 3 ticks for a dash
          delay(3 * tick);
        } else {
          // light for 1 tick for a dot
          delay(tick);
        }
        
        /* WAIT BETWEEN FLASHES */
        digitalWrite(LED_BUILTIN, LOW);
        if(i == sizeof(morse[letter])/sizeof(char) - 1) {
          // we hit the end of this letter
          if(index + 1 < sizeof(text)/sizeof(char)) {
            char next = (text[index + 1] - 'A');
            if(next >= 0 && next <= 25) {
              // next character is a valid letter, so wait 3 ticks
              // if not a valid letter we will wait 7 ticks later
              delay(3 * tick);
            }
          }
        } else {
          // otherwise, add 1 tick between letter parts
          delay(tick);
        }
      }
    }
  }
  
  // end with a pause to indicate a new word before repeating
  digitalWrite(LED_BUILTIN, LOW);
  delay(7 * tick);
  
}