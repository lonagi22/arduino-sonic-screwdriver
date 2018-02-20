const int leds = 2;
const int sound = 3;
const int btn1 = 4;
const int btn2 = 5;

int typeS = 0;
bool b_btn1 = false;
int delaka = 100;

int type1[3] = {
  1500,1800,2500
};

int type2 = 2000;

int type3 = 200;

void setup() {
pinMode(leds,OUTPUT);
pinMode(sound,OUTPUT);
pinMode(btn1,INPUT);
pinMode(btn2,INPUT);
}

void loop() {

  if(typeS>4) typeS=1;
  
  if(digitalRead(btn2) == HIGH)
  {
   digitalWrite(leds,HIGH); 
    switch(typeS){
    case 1:
     for (int i = 0; i < 3; i++)
     { 
        tone(sound, type1[i]); 
        delay(delaka); 
        noTone(sound);
     }
    break;
    case 2:
        tone(sound, type2); 
    break;
     case 3:
        tone(sound, type3); 
    break;
  }

  }
  else
  {
    noTone(sound);
    digitalWrite(leds,LOW);
  }

    if(digitalRead(btn1) == HIGH && !b_btn1)
  {
    b_btn1 = true;
    typeS++;
    delay(1500);
    b_btn1 = false;
  }

}
