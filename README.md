# InputSequencePuzzle
This code is designed for an Arduino board to play a memory game where the user has to repeat a random pattern of 6 numbers between 1 and 3 by pressing buttons. The purpose of the game is to test the user's memory and reaction time.

# Pin Configuration
The following pins are used for LED, push buttons:
```
int one = 8;
int two = 9;
int three = 10;
int LED_1 = 2;
int LED_2 = 3;
int LED_3 = 4;
int LED_4 = 5;
int LED_5 = 6;
int LED_6 = 7;
```
# Variables
The variables used in this code are:

one: stores the state of the first push button

two: stores the state of the second push button

three: stores the state of the third push button

pattern: an array for storing a random pattern of 6 numbers between 1 and 3

personInput: an array for storing the user's input

DELAY: a delay time used in the game loop

# Setup
The code sets up the LED and push button pins as output and input respectively. The random seed is set based on an analog read value:
```
void setup() {
Serial.begin(9600);
randomSeed(analogRead(0));
pinMode(LED_1, OUTPUT);
pinMode(LED_2, OUTPUT);
pinMode(LED_3, OUTPUT);
pinMode(LED_4, OUTPUT);
pinMode(LED_5, OUTPUT);
pinMode(LED_6, OUTPUT);
pinMode(one, INPUT_PULLUP);
pinMode(two, INPUT_PULLUP);
pinMode(three, INPUT_PULLUP);
one = 1;
two = 1;
three = 1;
}
```

# Game Loop
The game loop consists of three main parts: generating a random pattern of 6 numbers, printing the pattern to the serial monitor for debugging purposes, and playing the game.

# Generating Random Pattern
A random pattern of 6 numbers between 1 and 3 is generated:
```
int pattern[6] = {0, 0, 0, 0, 0, 0};
for (int i = 0; i < 6; i++) {
pattern[i] = random(1, 4);
}
```
# Printing the Pattern
The generated pattern is printed to the serial monitor for debugging purposes:
```
for (int i = 0; i < 6; i++)
Serial.println(pattern[i]);
Serial.println("-------");
```
# Playing the Game
The user has to repeat the pattern by pressing buttons. The game loop continues until the user completes the pattern or makes a mistake. The user's input is checked against the pattern, and LEDs corresponding to the correct input are turned on. If the input is incorrect, all LEDs are turned on and the user has to start over:
```
while (1) {
int needBreak = 0;
int needContinue = 0;
int pc = 0;
for (pc; pc < 6; pc++) {
if (personInput[pc] == 0)
break;
}
int i = pc;
for (i; personInput[i] == 0 && i < 6; i++) {
if (one == 0) {
delay(1000);
personInput[i] = 1;
break;
}
if(two==0){
delay(1000);
personInput[i]=2;
break;
}
if(three==0){
delay(1000);
personInput[i]=3;
break;
}
}
```
# Playing the game
Once the user has entered their input, the code will check the user input against the pattern generated at the beginning of the game. If the user enters the correct number in the correct position, the corresponding LED will turn on. If the user enters the incorrect number or enters the correct number in the wrong position, the red LED will turn on, indicating a mistake. The game will then clear the user input and start over.
```
  // Check the user input against the pattern
  int t=pc;
  for(t;t<6 && pattern[t]>0 && personInput[t]>0  ;t++){
    if(pattern[t]==personInput[t]){
      LED_turnOn(t+1);
      needContinue=1;
      break;
    }
    else{
      digitalWrite(11,1);
      delay(1000);
      digitalWrite(11,0);
      LED_turnOn(10);
      
      // Clear the user input array and start over
      for(int j=0;j<6;j++){
        personInput[j]=0;
      }
      pc=0;
      needContinue=1;
      break;
    }
    if(LED_turnOn){
      needBreak=1;
    }
  }
```
If the user correctly enters all six numbers in the correct order, the game will end and the green LED will turn on.
```
  // End the game if the input matches the pattern or if the user makes a mistake
  if(needBreak==1){
    break;
  }
  if(needContinue==1){
    continue;
  }
}

// If the user correctly enters all six numbers in the correct order, the green LED will turn on
LED_turnOn(9);
```
# Conclusion
This code creates a simple memory game using LEDs and push buttons on an Arduino board. The game generates a pattern of six random numbers between 1 and 3, and the user must correctly enter the pattern to win. If the user enters the correct number in the correct position, the corresponding LED will turn on. If the user makes a mistake, the red LED will turn on, and the game will start over. If the user correctly enters all six numbers in the correct order, the green LED will turn on, indicating a win. This code can be easily modified to create more complex memory games with longer patterns or more buttons.
    
