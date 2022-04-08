int one;
int two;
int three;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  one=1;
  two=1;
  three=1;
}

void loop() {
  int pattern[6]={0,0,0,0,0,0};
   int personInput[6]={0,0,0,0,0,0};
  for(int i=0;i<6;i++){
    pattern[i]=random(1,4);
  }
  for(int i=0;i<6;i++)
  Serial.println(pattern[i]);
  Serial.println("-------");
  delay(2000);
  while(1){
    int needBreak=0;
    int needContinue=0;
 
  one = digitalRead(8);
  two = digitalRead(9);
  three = digitalRead(10);
  int pc=0;
  for(pc;pc<6;pc++){
    if(personInput[pc]==0)
    break;
  }
  //Serial.println(pc);
  int i=pc;
  //Serial.println(pc);
   // Serial.println("********");
  
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
 // for(int i=0;i<6;i++)
  //Serial.println(personInput[i]);
  //Serial.println("&&&&&&&&&&&&&&&&&");
  //delay(1000);
  int t=pc;
  for(t;t<6 && pattern[t]>0 && personInput[t]>0  ;t++){
    if(pattern[t]==personInput[t]){
      //Serial.println(j);
      LED_turnOn(t+1);
      needContinue=1;
      break;
    }
    else{
      //Serial.println("iiiiiiiiiiiii");
      digitalWrite(11,1);
      delay(1000);
      digitalWrite(11,0);
      LED_turnOn(10);
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
  if(needBreak==1){
   
    break;
  }
  if(needContinue==1){
    continue;
  }
  }
}
bool LED_turnOn(int a){
  switch(a){

    case 1: 
    digitalWrite(2,1);
    break;
    case 2: 
    digitalWrite(3,1);
    break;
    case 3: 
    digitalWrite(4,1);
    break;
    case 4: 
    digitalWrite(5,1);
    break;
    case 5: 
    digitalWrite(6,1);
    break;
    case 6: 
    digitalWrite(7,1);
    break;
    return 1;
    case 10:

    digitalWrite(2,0);
    digitalWrite(3,0);
    digitalWrite(4,0);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,0);
    break;
  }
}
