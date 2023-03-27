// Initialize variables
int one;
int two;
int three;

void setup() {
  // Set up serial communication at 9600 bits per second
  Serial.begin(9600);
  
  // Initialize the random number generator
  randomSeed(analogRead(0));
  
  // Set up the LED and push button pins
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  
  // Initialize variables
  one=1;
  two=1;
  three=1;
}

void loop() {
  // Generate a random pattern of 6 numbers between 1 and 3
  int pattern[6]={0,0,0,0,0,0};
  for(int i=0;i<6;i++){
    pattern[i]=random(1,4);
  }
  
  // Print the pattern to the serial monitor for debugging purposes
  for(int i=0;i<6;i++)
    Serial.println(pattern[i]);
  Serial.println("-------");
  
  // Wait 2 seconds before starting the game
  delay(2000);
  
  // Main game loop
  while(1){
    // Initialize variables for tracking input and game status
    int needBreak=0;
    int needContinue=0;
    
    // Read the push button states
    one = digitalRead(8);
    two = digitalRead(9);
    three = digitalRead(10);
    
    // Determine how many inputs have been received so far
    int pc=0;
    for(pc;pc<6;pc++){
      if(personInput[pc]==0)
        break;
    }
    
    // Read input from the user
    int i=pc;
    for(i;personInput[i]==0 && i<6;i++){
      if(one==0){
        delay(1000);
        personInput[i]=1;
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
    
    // Print the user input for debugging purposes
    for(int i=0;i<6;i++)
      Serial.println(personInput[i]);
    Serial.println("&&&&&&&&&&&&&&&&&");
    
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
    
    // End the game if the input matches the pattern or if the user makes a mistake
    if(needBreak==1){
      break;
    }
    if(needContinue==1){
      continue;
    }
  }
