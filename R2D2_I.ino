  /*
   * 
   * R2D2 ARDUINO: CODE FOR ARDUINO UNO I
   * MOTORS & SENSORS
   * 
   */
  
  // CHIP CONTROL DE DIRECCION
  #define ECHO_PIN 2
  #define TRIGGER_PIN 4
  #define PWM_PIN 3
  #define PWM_PIN_1 11
  #define MOTOR_PIN_1 13
  #define MOTOR_PIN_2 12
  #define MOTOR_PIN_3 8
  #define MOTOR_PIN_4 7



  // OTHER CONSTANTS
  #define INTERVAL 500

  //CONSTATANTS
  #define MAX_RPM 255
  #define FIRST_DISTANCE 20
  #define SECOND_DISTANCE 30


  // VARIABLES
  int vel;
  long previousMillis = 0;
  
  void setup() {
     Serial.begin(9600);
     
     pinMode(TRIGGER_PIN, OUTPUT);
     pinMode(ECHO_PIN, INPUT);
  
     pinMode(MOTOR_PIN_1, OUTPUT);
     pinMode(MOTOR_PIN_2, OUTPUT);
     pinMode(MOTOR_PIN_3, OUTPUT);
     pinMode(MOTOR_PIN_4, OUTPUT);

  }
   
  void loop() {

     long timeMillis = millis();

     if (timeMillis - previousMillis > INTERVAL){
       ping(TRIGGER_PIN, ECHO_PIN);
       previousMillis = timeMillis;
     }


     
  }
  
  
  
  
  
  /*
   * 
   * ADDITIONAL FUNCTIONS
   * 
   */
  
  
   
  void Alante(int vel)
  {
    analogWrite(PWM_PIN, vel);
    digitalWrite(MOTOR_PIN_1, LOW);
    digitalWrite(MOTOR_PIN_2, HIGH);
    
  }
  
  void Alante2(int vel)
  {
    analogWrite(MOTOR_PIN_1, vel);
    digitalWrite(MOTOR_PIN_3, LOW);
    digitalWrite(MOTOR_PIN_4, HIGH);
  }
  
  
  void Atras(int vel)
  {
    analogWrite(PWM_PIN, vel);
    digitalWrite(MOTOR_PIN_1, HIGH);
    digitalWrite(MOTOR_PIN_2, LOW);
  }
  
  
  void Atras2(int vel)
  {
    analogWrite(PWM_PIN_1, vel);
    digitalWrite(MOTOR_PIN_3, HIGH);
    digitalWrite(MOTOR_PIN_4, LOW);
  }
  
  
  int ping(int TriggerPin, int EchoPin) {
    
     long duration, distanceCm;
     
     digitalWrite(TriggerPin, LOW);               //para generar un pulso limpio ponemos a LOW 4ms
     //delayMicroseconds(4);
     digitalWrite(TriggerPin, HIGH);              //generamos Trigger (disparo) de 10ms
     //delayMicroseconds(10);
     digitalWrite(TriggerPin, LOW);
     
     duration = pulseIn(EchoPin, HIGH);           //medimos el tiempo entre pulsos, en microsegundos
     
     distanceCm = duration * 10 / 292/ 2;         //convertimos a distancia, en cm
  
  
     // CHECK THE DISTANCES
     /*if(distanceCm <= FIRST_DISTANCE) {
      Alante(MAX_RPM);
      Alante2(MAX_RPM);  
     }*/

      if (distanceCm <= FIRST_DISTANCE) {
      Atras(MAX_RPM);
      Alante2(MAX_RPM);
     }
     
     else {
      Atras(MAX_RPM);
      Atras2(MAX_RPM);
     }
    
  
     
     return distanceCm;
     
  
     
  }

