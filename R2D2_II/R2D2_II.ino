/*
 * 
 * 
 * 
 * R2D2 ARDUINO: CODE FOR ARDUINO UNO II
 * LEDS ETC
 * 
 * 
 * 
 */

  //LIBRARIES
  #include "musical_notes.h"
  #include <Servo.h>

  //COMMUNICATION PINS
  #define RX 1
  #define TX 0
  
  //LED PINS
  #define PIN_LED_BLUE 9
  #define PIN_LED_RED 8

  //SERVO PIN
  #define PIN_SERVO 6

  //BUTTON PIN
  #define PIN_BUTTON 3
  
  //CONSTANTS
  #define ASCII_0 48
  #define ASCII_1 49
  #define NULL_VALUE 0
  
  // VARIABLES
  int SPEAKER_PIN = 5;
  int incomingByte = 0;
  int redLedState, blueLedState;
  int systemState = 0;
  int counter = 0;
  boolean firstTime = false;

  //OBJECTS
  // Declaramos la variable para controlar el servo
  Servo servoMotor;

  void setup() {
    
    Serial.begin(9600);

    pinMode(RX, INPUT);
    pinMode(TX, OUTPUT);
    
    servoMotor.attach(PIN_SERVO);

    pinMode(SPEAKER_PIN, OUTPUT);  
    pinMode(PIN_LED_BLUE, OUTPUT);  
    pinMode(PIN_LED_RED, OUTPUT);  
    pinMode(PIN_BUTTON, INPUT);

    redLedState = LOW;
    blueLedState = LOW;
    servoMotor.write(180);
  }
  
  void loop() {
    
    if (Serial.available() > NULL_VALUE) {
        // read the incoming byte:
        incomingByte = Serial.read();

        // say what you got:
        if (incomingByte == ASCII_0){
          redLedState = LOW;
          servoMotor.write(180);
          firstTime = true;
         
        }
        else if (incomingByte == ASCII_1){
          redLedState = HIGH;
          servoMotor.write(counter);
          counter+=2;

          if (counter >= 180){

            counter = 0;
          }

          if (firstTime){
            //r2D2 song to play::
            uhoh();
            
            firstTime = false;
           }
        }
        else{
          redLedState = LOW;
          
        }
        //servoMotor.write(180);
        blueLedState = HIGH;
        
        //Serial1.print("I received: ");
        //Serial1.println(incomingByte, DEC);
    }
    
    digitalWrite(PIN_LED_BLUE, blueLedState);
    digitalWrite(PIN_LED_RED, redLedState); 


      //delay(1000);
      
      
  }




















  
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  //                                                                                                         //
  //                                                                                                         //    
  //                                         R2-D2 AUDIO FUNCTIONS                                           //
  //                                                                                                         //
  //                                                                                                         //
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////// 
      
  
  void beep (int SPEAKER_PIN, float noteFrequency, long noteDuration)
  {    
    int x;
    // Convert the frequency to microseconds
    float microsecondsPerWave = 1000000/noteFrequency;
    
    // Calculate how many HIGH/LOW cycles there are per millisecond
    float millisecondsPerCycle = 1000/(microsecondsPerWave * 2);
    
    // Multiply noteDuration * number or cycles per millisecond
    float loopTime = noteDuration * millisecondsPerCycle;
    
    // Play the note for the calculated loopTime.
    for (x=0;x<loopTime;x++)   
            {   
                digitalWrite(SPEAKER_PIN,HIGH); 
                delayMicroseconds(microsecondsPerWave); 
                digitalWrite(SPEAKER_PIN,LOW); 
                delayMicroseconds(microsecondsPerWave); 
            } 
  }     
       
 

 
   
  
  void laugh2() {
            beep(SPEAKER_PIN, note_C6,200); //C
            beep(SPEAKER_PIN, note_E6,200); //E  
            beep(SPEAKER_PIN, note_G6,200); //G 
            beep(SPEAKER_PIN, note_C7,200); //C 
            beep(SPEAKER_PIN, note_C6,200); //C
            
            beep(SPEAKER_PIN, note_C6,200); //C
            beep(SPEAKER_PIN, note_E6,200); //E  
            beep(SPEAKER_PIN, note_G6,200); //G 
            beep(SPEAKER_PIN, note_C7,200); //C 
            beep(SPEAKER_PIN, note_C6,200); //C
            
            beep(SPEAKER_PIN, note_C6,50); //C
            
            beep(SPEAKER_PIN, note_C6,50); //C
            
            beep(SPEAKER_PIN, note_C6,50); //C
            
            beep(SPEAKER_PIN, note_C6,50); //C
            
            beep(SPEAKER_PIN, note_C6,50); //C
            
            beep(SPEAKER_PIN, note_C6,50); //C
            
            beep(SPEAKER_PIN, note_C6,50); //C
            
  
            
  }
    
  void squeak() {
    for (int i=100; i<5000; i=i*1.45) {
      beep(SPEAKER_PIN,i,60);
    }
    
    for (int i=100; i<6000; i=i*1.5) {
      beep(SPEAKER_PIN,i,20);
    }
  }
  
  void waka() {
    for (int i=1000; i<3000; i=i*1.05) {
      beep(SPEAKER_PIN,i,10);
    }
    
    for (int i=2000; i>1000; i=i*.95) {
      beep(SPEAKER_PIN,i,10);
    }
      for (int i=1000; i<3000; i=i*1.05) {
      beep(SPEAKER_PIN,i,10);
    }
    
    for (int i=2000; i>1000; i=i*.95) {
      beep(SPEAKER_PIN,i,10);
    }
      for (int i=1000; i<3000; i=i*1.05) {
      beep(SPEAKER_PIN,i,10);
    }
    
    for (int i=2000; i>1000; i=i*.95) {
      beep(SPEAKER_PIN,i,10);
    }
      for (int i=1000; i<3000; i=i*1.05) {
      beep(SPEAKER_PIN,i,10);
    }
    
    for (int i=2000; i>1000; i=i*.95) {
      beep(SPEAKER_PIN,i,10);
    }
  }
  
  void catcall() {
    for (int i=1000; i<5000; i=i*1.05) {
      beep(SPEAKER_PIN,i,10);
    }
   
   
    for (int i=1000; i<3000; i=i*1.03) {
      beep(SPEAKER_PIN,i,10);
    }
    for (int i=3000; i>1000; i=i*.97) {
      beep(SPEAKER_PIN,i,10);
    }
  }
  
  void ohhh() {
    for (int i=1000; i<2000; i=i*1.02) {
      beep(SPEAKER_PIN,i,10);
    }
    for (int i=2000; i>1000; i=i*.98) {
      beep(SPEAKER_PIN,i,10);
    }
  }
  
  void uhoh() {
    for (int i=1000; i<1244; i=i*1.01) {
      beep(SPEAKER_PIN,i,30);
    }
    
    for (int i=1244; i>1108; i=i*.99) {
      beep(SPEAKER_PIN,i,30);
    }
  }
  
  void laugh() {
    for (int i=1000; i<2000; i=i*1.10) {
      beep(SPEAKER_PIN,i,10);
    }
    
    for (int i=1000; i>500; i=i*.90) {
      beep(SPEAKER_PIN,i,10);
    }
    
    for (int i=1000; i<2000; i=i*1.10) {
      beep(SPEAKER_PIN,i,10);
    }
    
    for (int i=1000; i>500; i=i*.90) {
      beep(SPEAKER_PIN,i,10);
    }
    
      for (int i=1000; i<2000; i=i*1.10) {
      beep(SPEAKER_PIN,i,10);
    }
    
    for (int i=1000; i>500; i=i*.90) {
      beep(SPEAKER_PIN,i,10);
    }
    
      for (int i=1000; i<2000; i=i*1.10) {
      beep(SPEAKER_PIN,i,10);
    }
    
    for (int i=1000; i>500; i=i*.90) {
      beep(SPEAKER_PIN,i,10);
    }
    
  }
