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
  
  #include "musical_notes.h"
  #include <Servo.h>
  #define PIN_LED_BLUE 2
  #define PIN_LED_RED 9
  
  int SPEAKER_PIN = 5;
  
  // Declaramos la variable para controlar el servo
  Servo servoMotor;
  
  void setup() {
    // put your setup code here, to run once:
    // Iniciamos el monitor serie para mostrar el resultado
    Serial.begin(9600);
   
    // Iniciamos el servo para que empiece a trabajar con el pin 6
    servoMotor.attach(6);

    pinMode(SPEAKER_PIN, OUTPUT);  
    pinMode(PIN_LED_BLUE, INPUT);  
    pinMode(PIN_LED_RED, INPUT);  

    
  }
  
  void loop() {
    // put your main code here, to run repeatedly:
    int currentTime = millis();
    Serial.println(currentTime);

       digitalWrite(PIN_LED_BLUE, HIGH);
       digitalWrite(PIN_LED_RED, HIGH);
       
       // Desplazamos a la posición 0º
      servoMotor.write(0);
      // Esperamos 1 segundo
      delay(1000);
      
      // Desplazamos a la posición 90º
      servoMotor.write(90);
      // Esperamos 1 segundo
      delay(1000);
      
      // Desplazamos a la posición 180º
      servoMotor.write(180);
      // Esperamos 1 segundo

      
      delay(1000);
      squeak();
      delay(500);
      catcall();
      delay(500);
      ohhh();
      delay(500);
      laugh();
      delay(500);
//      closeEncounters();
//      delay(500);
//      laugh2();
//      delay(500);
//      //waka();
//      //delay(500);  
//      r2D2();
//      delay(500);
//      ariel();
//      delay(3000);


      // Vamos a tener dos bucles uno para mover en sentido positivo y otro en sentido negativo
      // Para el sentido positivo
      for (int i = 0; i <= 180; i+=2)
      {
        // Desplazamos al ángulo correspondiente
        servoMotor.write(i);
        // Hacemos una pausa de 25ms
        delay(25);
      }
     
      // Para el sentido negativo
      for (int i = 179; i > 0; i-=2)
      {
        // Desplazamos al ángulo correspondiente
        servoMotor.write(i);
        // Hacemos una pausa de 25ms
        delay(25);
      }

      
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
       
  void scale() 
  {    
            beep(SPEAKER_PIN, note_C7,500); //C: play the note C for 500ms 
            beep(SPEAKER_PIN, note_D7,500); //D 
            beep(SPEAKER_PIN, note_E7,500); //E 
            beep(SPEAKER_PIN, note_F7,500); //F 
            beep(SPEAKER_PIN, note_G7,500); //G 
            beep(SPEAKER_PIN, note_A7,500); //A 
            beep(SPEAKER_PIN, note_B7,500); //B 
            beep(SPEAKER_PIN, note_C8,500); //C 
  }  
  
  void r2D2(){
            beep(SPEAKER_PIN, note_A7,100); //A 
            beep(SPEAKER_PIN, note_G7,100); //G 
            beep(SPEAKER_PIN, note_E7,100); //E 
            beep(SPEAKER_PIN, note_C7,100); //C
            beep(SPEAKER_PIN, note_D7,100); //D 
            beep(SPEAKER_PIN, note_B7,100); //B 
            beep(SPEAKER_PIN, note_F7,100); //F 
            beep(SPEAKER_PIN, note_C8,100); //C 
            beep(SPEAKER_PIN, note_A7,100); //A 
            beep(SPEAKER_PIN, note_G7,100); //G 
            beep(SPEAKER_PIN, note_E7,100); //E 
            beep(SPEAKER_PIN, note_C7,100); //C
            beep(SPEAKER_PIN, note_D7,100); //D 
            beep(SPEAKER_PIN, note_B7,100); //B 
            beep(SPEAKER_PIN, note_F7,100); //F 
            beep(SPEAKER_PIN, note_C8,100); //C 
  }
  
  void closeEncounters() {
            beep(SPEAKER_PIN, note_Bb5,300); //B b
            delay(50);
            beep(SPEAKER_PIN, note_C6,300); //C
            delay(50);
            beep(SPEAKER_PIN, note_Ab5,300); //A b
            delay(50);
            beep(SPEAKER_PIN, note_Ab4,300); //A b
            delay(50);
            beep(SPEAKER_PIN, note_Eb5,500); //E b   
            delay(500);     
            
            beep(SPEAKER_PIN, note_Bb4,300); //B b
            delay(100);
            beep(SPEAKER_PIN, note_C5,300); //C
            delay(100);
            beep(SPEAKER_PIN, note_Ab4,300); //A b
            delay(100);
            beep(SPEAKER_PIN, note_Ab3,300); //A b
            delay(100);
            beep(SPEAKER_PIN, note_Eb4,500); //E b   
            delay(500);  
            
            beep(SPEAKER_PIN, note_Bb3,300); //B b
            delay(200);
            beep(SPEAKER_PIN, note_C4,300); //C
            delay(200);
            beep(SPEAKER_PIN, note_Ab3,300); //A b
            delay(500);
            beep(SPEAKER_PIN, note_Ab2,300); //A b
            delay(550);
            beep(SPEAKER_PIN, note_Eb3,500); //E b      
  }
  
  void ariel() {
  
            beep(SPEAKER_PIN, note_C6,300); //C
            delay(50);
            beep(SPEAKER_PIN, note_D6,300); //D
            delay(50);
            beep(SPEAKER_PIN, note_Eb6,600); //D#
            delay(250);
            
            beep(SPEAKER_PIN, note_D6,300); //D
            delay(50);
            beep(SPEAKER_PIN, note_Eb6,300); //D#
            delay(50);
            beep(SPEAKER_PIN, note_F6,600); //F
            delay(250);
            
            beep(SPEAKER_PIN, note_C6,300); //C
            delay(50);
            beep(SPEAKER_PIN, note_D6,300); //D
            delay(50);
            beep(SPEAKER_PIN, note_Eb6,500); //D#
            delay(50);          
            beep(SPEAKER_PIN, note_D6,300); //D
            delay(50);
            beep(SPEAKER_PIN, note_Eb6,300); //D#
            delay(50);             
            beep(SPEAKER_PIN, note_D6,300); //D
            delay(50);
            beep(SPEAKER_PIN, note_Eb6,300); //D#
            delay(50);
            beep(SPEAKER_PIN, note_F6,600); //F
            delay(50); 
  
  }
   
  
  void laugh2() {
            beep(SPEAKER_PIN, note_C6,200); //C
            beep(SPEAKER_PIN, note_E6,200); //E  
            beep(SPEAKER_PIN, note_G6,200); //G 
            beep(SPEAKER_PIN, note_C7,200); //C 
            beep(SPEAKER_PIN, note_C6,200); //C
            delay(50);
            beep(SPEAKER_PIN, note_C6,200); //C
            beep(SPEAKER_PIN, note_E6,200); //E  
            beep(SPEAKER_PIN, note_G6,200); //G 
            beep(SPEAKER_PIN, note_C7,200); //C 
            beep(SPEAKER_PIN, note_C6,200); //C
            delay(50);
            beep(SPEAKER_PIN, note_C6,50); //C
            delay(50);
            beep(SPEAKER_PIN, note_C6,50); //C
            delay(50);
            beep(SPEAKER_PIN, note_C6,50); //C
            delay(50);
            beep(SPEAKER_PIN, note_C6,50); //C
            delay(50);
            beep(SPEAKER_PIN, note_C6,50); //C
            delay(50);
            beep(SPEAKER_PIN, note_C6,50); //C
            delay(50);
            beep(SPEAKER_PIN, note_C6,50); //C
            
  
            
  }
    
  void squeak() {
    for (int i=100; i<5000; i=i*1.45) {
      beep(SPEAKER_PIN,i,60);
    }
    delay(10);
    for (int i=100; i<6000; i=i*1.5) {
      beep(SPEAKER_PIN,i,20);
    }
  }
  
  void waka() {
    for (int i=1000; i<3000; i=i*1.05) {
      beep(SPEAKER_PIN,i,10);
    }
    delay(100);
    for (int i=2000; i>1000; i=i*.95) {
      beep(SPEAKER_PIN,i,10);
    }
      for (int i=1000; i<3000; i=i*1.05) {
      beep(SPEAKER_PIN,i,10);
    }
    delay(100);
    for (int i=2000; i>1000; i=i*.95) {
      beep(SPEAKER_PIN,i,10);
    }
      for (int i=1000; i<3000; i=i*1.05) {
      beep(SPEAKER_PIN,i,10);
    }
    delay(100);
    for (int i=2000; i>1000; i=i*.95) {
      beep(SPEAKER_PIN,i,10);
    }
      for (int i=1000; i<3000; i=i*1.05) {
      beep(SPEAKER_PIN,i,10);
    }
    delay(100);
    for (int i=2000; i>1000; i=i*.95) {
      beep(SPEAKER_PIN,i,10);
    }
  }
  
  void catcall() {
    for (int i=1000; i<5000; i=i*1.05) {
      beep(SPEAKER_PIN,i,10);
    }
   delay(300);
   
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
    delay(200);
    for (int i=1244; i>1108; i=i*.99) {
      beep(SPEAKER_PIN,i,30);
    }
  }
  
  void laugh() {
    for (int i=1000; i<2000; i=i*1.10) {
      beep(SPEAKER_PIN,i,10);
    }
    delay(50);
    for (int i=1000; i>500; i=i*.90) {
      beep(SPEAKER_PIN,i,10);
    }
    delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
      beep(SPEAKER_PIN,i,10);
    }
    delay(50);
    for (int i=1000; i>500; i=i*.90) {
      beep(SPEAKER_PIN,i,10);
    }
    delay(50);
      for (int i=1000; i<2000; i=i*1.10) {
      beep(SPEAKER_PIN,i,10);
    }
    delay(50);
    for (int i=1000; i>500; i=i*.90) {
      beep(SPEAKER_PIN,i,10);
    }
    delay(50);
      for (int i=1000; i<2000; i=i*1.10) {
      beep(SPEAKER_PIN,i,10);
    }
    delay(50);
    for (int i=1000; i>500; i=i*.90) {
      beep(SPEAKER_PIN,i,10);
    }
    delay(50);
  }
