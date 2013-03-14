/*
  Morse Code
  
  Turns characters input by user into Morse Code signals

*/
/* Wikipedia: http://en.wikipedia.org/wiki/File:International_Morse_Code.svg
  1. the length of a dot is one unit
  2. a dash is three units
  3. the space between parts of the same character is one unit
  4. the space between characters is three units
  5. the space between words is seven units
*/

// using const saves RAM (Arduino Cookbook) - here it's about 340 bytes for these 4 variables
  // the term const tells the compiler not to treat the var as an ordinary variable. 
  // Unlike the ordinary int, no RAM is reserved to hold the value for the const, as it is guaranteed not to change
const int light = 13;
const int dot = 250;
const int dash = dot * 3;
const int wordSpace = dot * 7;

// set the message you want displayed here:
const char message[] = "SOS";
const int messageLength = strlen(message);

void setup() {
  pinMode(light, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // returning arrays from functions: http://arduino.cc/forum/index.php/topic,42934.0.html
  // holds an array of ints, with max length of 5
  // values in signal is changed in translate() with pointer to this variable
  int signal[5];
  int msgLenIdx = 0;
  
  for  (int i = 0; i <= messageLength; i++) {
    Serial.println("message[i] follows: ");
    Serial.println(message[i]);

    int signalSize = translate(message[i], signal);
    
    messageOutput(signal, signalSize);
    
    // handle end of message with long delay
    if (msgLenIdx == messageLength) {
      Serial.println("_________END OF MESSAGE__________");
      delay(wordSpace);
      msgLenIdx = 0;
    }
    msgLenIdx++;
  }

}

    
/* 
 * turn character into dashes and dots
 *
 * @param {char} character  the single message character that is to be turned into dots and/or dashes
 * @param {pointer} psignal[]  points to signal[]; allows function to alter signal[] (i.e., fill it with dots and dashes related to character)
 * @return the length of the signal; used by messageOutput in for loop to know how many times to go through (the number of elements in signal[])
 */
// was getting "invalid conversion from 'char' to 'const char*" error when I called character a String
int translate(char character, int psignal[]) {

  // make sure we're getting normalized characters
  char characterLwr = tolower(character);
  
  switch(characterLwr) {
     case 'a': 
       psignal[0] = dot;
       psignal[1] = dash;
       return 2;
       break;
     case 'b':
       psignal[0] = dash;
       psignal[1] = dot;
       psignal[2] = dot;
       psignal[3] = dot;
       return 4;
       break;
     case 'c':
       psignal[0] = dash;
       psignal[1] = dot;
       psignal[2] = dash;
       psignal[3] = dot;
       return 4;
       break;
     case 'd':
       psignal[0] = dash;
       psignal[1] = dot;
       psignal[2] = dot;
       return 3;
       break;
     case 'e':
       psignal[0] = dot;
       return 1;
       break;
     case 'f':
       psignal[0] = dot;
       psignal[1] = dot;
       psignal[2] = dash;
       psignal[3] = dot;
       return 4;
       break;
     case 'g':
       // psignal[0] = {dash, dash, dot};
       psignal[0] = dash;
       psignal[1] = dash;
       psignal[2] = dot;
       return 3;
       break;
     case 'h':
//       psignal[0] = {dot, dot, dot, dot};
       psignal[0] = dot;
       psignal[1] = dot;
       psignal[2] = dot;
       psignal[3] = dot;
       return 4;
       break;
     case 'i':
//       psignal[0] = {dot, dot};
       psignal[0] = dot;
       psignal[1] = dot;
       return 2;
       break;
     case 'j':
//       psignal[0] = {dot, dash, dash, dash};
       psignal[0] = dot;
       psignal[1] = dash;
       psignal[2] = dash;
       psignal[3] = dash;
       return 4;
       break;
     case 'k':
//       psignal[0] = {dash, dot, dash};
       psignal[0] = dash;
       psignal[1] = dot;
       psignal[2] = dash;
       return 3;
       break;
     case 'l':
//       psignal[0] = {dot, dash, dot, dot};
       psignal[0] = dot;
       psignal[1] = dash;
       psignal[2] = dot;
       psignal[3] = dot;
       return 4;
       break;
     case 'm':
//       psignal[0] = {dash, dash};
       psignal[0] = dash;
       psignal[1] = dash;
       return 2;
       break;
     case 'n':
//       psignal[0] = {dash, dot};
       psignal[0] = dash;
       psignal[1] = dot;
       return 2;
       break;
     case 'o':
//       psignal[0] = {dash, dash, dash};
       psignal[0] = dash;
       psignal[1] = dash;
       psignal[2] = dash;
       return 3;
       break;
     case 'p':
//       psignal[0] = {dot, dash, dash, dot};
       psignal[0] = dot;
       psignal[1] = dash;
       psignal[2] = dash;
       psignal[3] = dot;
       return 4;
       break;
     case 'q':
//       psignal[0] = {dash, dash, dot, dash};
       psignal[0] = dash;
       psignal[1] = dash;
       psignal[2] = dot;
       psignal[3] = dash;
       return 4;
       break;
     case 'r':
//       psignal[0] = {dot, dash, dot};
       psignal[0] = dot;
       psignal[1] = dash;
       psignal[2] = dot;
       return 3;
       break;
     case 's':
//       psignal[0] = {dot, dot, dot};
       psignal[0] = dot;
       psignal[1] = dot;
       psignal[2] = dot;
       return 3;
       break;
     case 't':
//       psignal[0] = {dash};
       psignal[0] = dash;
       return 1;
       break;
     case 'u':
//       psignal[0] = {dot, dot, dash};
       psignal[0] = dot;
       psignal[1] = dot;
       psignal[2] = dash;
       return 3;
       break;
     case 'v':
//       psignal[0] = {dot, dot, dot, dash};
       psignal[0] = dot;
       psignal[1] = dot;
       psignal[2] = dot;
       psignal[3] = dash;
       return 4;
       break;
     case 'w':
//       psignal[0] = {dot, dash, dash};
       psignal[0] = dot;
       psignal[1] = dash;
       psignal[2] = dash;
       return 3;
       break;
     case 'x':
//       psignal[0] = {dash, dot, dot, dash};
       psignal[0] = dash;
       psignal[1] = dot;
       psignal[2] = dot;
       psignal[3] = dash;
       return 4;
       break;
     case 'y':
//       psignal[0] = {dash, dot, dash, dash};
       psignal[0] = dash;
       psignal[1] = dot;
       psignal[2] = dash;
       psignal[3] = dash;
       return 4;
       break;
     case 'z':
//       psignal[0] = {dash, dash, dot, dot};
       psignal[0] = dash;
       psignal[1] = dash;
       psignal[2] = dot;
       psignal[3] = dot;
       return 4;
       break;
       
     case ' ':
       psignal[0] = wordSpace;
       return 1;
       break;
     
     // numbers
     case '1':
//       psignal[0] = {dot, dash, dash, dash, dash};
       psignal[0] = dot;
       psignal[1] = dash;
       psignal[2] = dash;
       psignal[3] = dash;
       psignal[4] = dash;
       return 5;
       break;
     case '2':
//       psignal[0] = {dot, dot, dash, dash, dash};
       psignal[0] = dot;
       psignal[1] = dot;
       psignal[2] = dash;
       psignal[3] = dash;
       psignal[4] = dash;
       return 5;
       break;
     case '3':
//       psignal[0] = {dot, dot, dot, dash, dash};
       psignal[0] = dot;
       psignal[1] = dot;
       psignal[2] = dot;
       psignal[3] = dash;
       psignal[4] = dash;
       return 5;
       break;
     case '4':
//       psignal[0] = {dot, dot, dot, dot, dash};
       psignal[0] = dot;
       psignal[1] = dot;
       psignal[2] = dot;
       psignal[3] = dot;
       psignal[4] = dash;
       return 5;
       break;
     case '5':
//       psignal[0] = {dot, dot, dot, dot, dot};
       psignal[0] = dot;
       psignal[1] = dot;
       psignal[2] = dot;
       psignal[3] = dot;
       psignal[4] = dot;
       return 5;
       break;
     case '6':
//       psignal[0] = {dash, dot, dot, dot, dot};
       psignal[0] = dash;
       psignal[1] = dot;
       psignal[2] = dot;
       psignal[3] = dot;
       psignal[4] = dot;
       return 5;
       break;
     case '7':
//       psignal[0] = {dash, dash, dot, dot, dot};
       psignal[0] = dash;
       psignal[1] = dash;
       psignal[2] = dot;
       psignal[3] = dot;
       psignal[4] = dot;
       break;
     case '8':
//       psignal[0] = {dash, dash, dash, dot, dot};
       psignal[0] = dash;
       psignal[1] = dash;
       psignal[2] = dash;
       psignal[3] = dot;
       psignal[4] = dot;
       return 5;
       break;
     case '9':
//       psignal[0] = {dash, dash, dash, dash, dot};
       psignal[0] = dash;
       psignal[1] = dash;
       psignal[2] = dash;
       psignal[3] = dash;
       psignal[4] = dot;
       return 5;
       break;
     case '0':
//       psignal[0] = {dash, dash, dash, dash, dash};
       psignal[0] = dash;
       psignal[1] = dash;
       psignal[2] = dash;
       psignal[3] = dash;
       psignal[4] = dash;
       return 5;
       break;
   }
}

/*
 * turn dashes and dots into light
 *
 * @param {pointer} signalP[]  points to signal[] so elements can be iterated through
 * @param {int} signalSize  used by for loop to determine how many times it needs to loop through to display all dots and dashes of this character
 */ 
void messageOutput(int signalP[], int signalSize) {
  Serial.println("signalSize follows: ");
  Serial.println(signalSize);
  
  for (int i = 0; i < signalSize; i++) {
    Serial.println("psignal[i] follows: ");
    Serial.println(signalP[i]);
    digitalWrite(light, HIGH);
    delay(signalP[i]);
    
    // the space between parts of the same character is one unit, so a dot follows every light flash
    digitalWrite(light, LOW);
    delay(dot);
    
    // handle space between characters (3 units)
    if (i == signalSize - 1) {
      Serial.println("\n");
      delay(dash);
    }

  }

}
