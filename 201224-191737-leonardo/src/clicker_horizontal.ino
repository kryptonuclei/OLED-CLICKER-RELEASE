
//Includes
#include "Vcc.h"
#include <avr/sleep.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
Adafruit_SH110X display = Adafruit_SH110X(64, 128, &Wire);
const int buttonPin = 8;

//Maths
const float VccMin   = 2.7;           // Minimum expected Vcc level, in Volts.
const float VccMax   = 4.2;           // Maximum expected Vcc level, in Volts.
const float VccCorrection = 1.0/1.0;  // Measured Vcc by multimeter divided by reported Vcc (default is 1:1 ratio)
Vcc vcc(VccCorrection);
int clicks=0;
int clickst=0;
float clkmaf=0;
float cps=0;


//Timers
const unsigned long debounceInterval = 10;
const unsigned long modechange = 1000;
const unsigned long returnInterval = 2500;
const unsigned long sleepwait = 60000;
const unsigned long clicktimer = 10000;
unsigned long timeset = 0;
unsigned long timeleft = 0;
unsigned long buttonDownMillis = 0;
unsigned long lastPressMillis = 0;

//Logic
bool buttonState = true;
bool returnButtonState = false;
bool buttonlongpress=false;
bool justreset=false; //for ignoring button release upon reset
bool start=false; //for game start detection
bool gamerunning=false; 
bool gmjstrun=false; //game just run>>>>>fixes bug where sleep is called on game finish
bool slpskp=false; //sleep skip>>>>>fixes sleep bug
bool scrchg=false;//screen change
int screen = 1;


void displayturnon(){
  display.begin(0x3C, true); // Address 0x3C default
  display.clearDisplay();
  display.display();
  display.setRotation(1);
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0,0);
}

void wake(){
}
void enableButtonInterrupt(void){
  // Enable pin change interrupt mask for pin PB4.
  PCMSK0 |= (1 << PCINT4);
  // Enable global pin change interrupts
  PCICR |= (1 << PCIE0);
  // Clear the Pin Change Interrupt flag
  PCIFR |= (1 << PCIF0);
}
// INTERRUPT VECTOR FOR PIN CHANGE INTERRUPTS (non-discriminate, but only PB4 pin change is enabled as a source).
  ISR(PCINT0_vect)
{
    // Perform wake routine
    wake();
    // Clear the Pin Change Interrupt flag (not sure if necessary)
    PCIFR |= (1 << PCIF0);
}

void toSleep(){
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); 
  sleep_enable();
  // Enable external interrupt on PB4
  enableButtonInterrupt();
  sleep_mode();
  sleep_disable(); 
  displayturnon();
  lastPressMillis=millis();
}


void pressed() {
   
  if (buttonlongpress==false&&justreset==false&&scrchg==false){
    lastPressMillis=millis();
    clicks++;
    slpskp=true;
    if (screen==2&&clicks==1){
      start=true;
    }
  }

  justreset=false;
  if (buttonlongpress==true){
    buttonlongpress=false;
    clicks=0;
    clickst=0;
    clkmaf=0;
    justreset=true;
    display.clearDisplay();
    display.setCursor(5,20);
    display.print("RESETTING!");
    display.display();
    delay(500);
    
  }
  
}

void screenchange(){
      if(scrchg==true){
        switch(screen){
      
        case 1:
          screen=2;
          clicks=0;
          clickst=0;
          break;
        
        case 2:
          screen=1;
          clicks=0;
          clickst=0;
          break;
        }
        scrchg=false;
        justreset=true;
 }
}

void readVcc() {
  float v = vcc.Read_Volts();
  //float p = vcc.Read_Perc(VccMin, VccMax);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Voltage: ");
  display.setCursor(50,0);
  display.print(v);
  display.display();
  display.setTextSize(2);
  if(v>(VccMax+0.1)){
    display.setCursor(0,7);
    display.print("OVERCHARGED!");
    display.display();
  }
  if(v<VccMin){
    display.setCursor(0,7);
    display.print("LOW BATTERY!");
    display.display();
  }

}

void counterscreen(){
  display.clearDisplay();
  display.setCursor(35,15);
  display.print("Count:");
  display.setCursor(45,40);
  display.print(clicks);
  readVcc();
  display.display();
}

void timerscreen(){
  gmjstrun=false;
  unsigned long currentMillist = millis();
  display.setTextSize(1);
  if (clicks==0){
    display.clearDisplay();
    display.setCursor(8,25);
    display.print("Click Speed Counter");
    display.setCursor(20,40);
    display.print("Click to start");
    readVcc();
    display.display();
  }
  if (gamerunning==false&&clickst>0){
    display.clearDisplay();
    display.setCursor(15,15);
    display.print("Total clicks: ");
    display.print(clickst);
    display.setCursor(10,30);
    cps=(clkmaf/10);
    display.print("Clicks per Second: ");
    display.setCursor(50,45);
    display.print(cps);
    readVcc();
    display.display();
}
  
    if (clicks==1&&start==true&&justreset==false&&scrchg==false){
      display.clearDisplay();
      display.setCursor(25,25);
      display.print("Starting in 3");
      display.display();
      delay(500);
      display.clearDisplay();
      display.setCursor(25,25);
      display.print("Starting in 2");
      display.display();
      delay(500);
      display.clearDisplay();
      display.setCursor(25,25);
      display.print("Starting in 1");
      display.display();
      delay(500);
      start=false;
      gamerunning=true;
      timeset=currentMillist+clicktimer;
    }
 

  while (gamerunning==true){
    unsigned long currentMillist = millis();
  static unsigned long previousMillist = 0;
    timeleft = (-(currentMillist-timeset));
    display.clearDisplay();
    display.setCursor(25,20);
    display.print("Time Left:");
    display.print(timeleft);
    display.setCursor(25,30);
    display.print("Total clicks:");
    display.setCursor(60,40);
    display.print(clickst);
    display.display();
  if (currentMillist - previousMillist >= debounceInterval) {
    previousMillist = currentMillist;
    if (digitalRead(buttonPin) != buttonState) {
      buttonState = !buttonState;
      if (buttonState) {
        returnButtonState = false;
        clickst++;
        clicks++;
        clkmaf++;
      }
    }
  }
  if (timeleft>0&&timeleft<100){
    gamerunning=false;
    gmjstrun=true;
  }
  }
  if(clicks==1){
    clicks=0;
  }

}


void setup(){
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  displayturnon();
  display.clearDisplay();
  display.setCursor(50,10);
  display.print("Ze");
  display.setCursor(20,35);
  display.print("Clicker");
  display.display();
  delay(500);
}

void loop(){
  
  unsigned long currentMillis = millis();
  static unsigned long previousMillis = 0;
  slpskp=false;

  

    if (screen==1&&scrchg==false){
      counterscreen();
    }
    if (screen==2&&scrchg==false){
      timerscreen();
    
    }
  



//short press
  if (currentMillis - previousMillis >= debounceInterval) {
    previousMillis = currentMillis;
    if (digitalRead(buttonPin) != buttonState) {
      buttonState = !buttonState;
      if (buttonState) {
        returnButtonState = false;
        pressed();
        screenchange();
        justreset=false;
      }
      else {
        buttonDownMillis = currentMillis;
        returnButtonState = true;
        
      }
    }
    // Check long press
    else if (returnButtonState) {
      if(currentMillis - buttonDownMillis >= modechange && currentMillis - buttonDownMillis <=returnInterval) {
        scrchg=true;
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(0,20);
        display.print("Release to change mode or keep holding for reset");
        display.display();
        display.setTextSize(2);
        
      }

      if (currentMillis - buttonDownMillis >=returnInterval) {
        scrchg=false;
        returnButtonState = false;
        buttonlongpress=true;
        pressed();
      }
    }
  }
  //sleep timer
  if (currentMillis - lastPressMillis >= sleepwait) {
    if(gmjstrun==false&&slpskp==false){
        display.oled_command(0xAE);
        toSleep();
      }
  }
    
 
}
