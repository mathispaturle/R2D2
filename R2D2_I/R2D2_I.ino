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

  //POTENTIOMETER
  #define PIN_POTENTIOMETER A1

  // OTHER CONSTANTS
  #define INTERVAL 500
  #define MIN_VALUE 0
  #define MAX_VALUE 1023
  #define TARGET_MIN_VALUE 0
  #define TARGET_MAX_VALUE 255
  

  //CONSTATANTS
  #define MAX_RPM 255
  #define FIRST_DISTANCE 30



  // VARIABLES
  int potentiometer;
  int speedMotors;
  long previousMillis = 0;
  
  void setup() {
     Serial.begin(9600);
     
     pinMode(TRIGGER_PIN, OUTPUT);
     pinMode(ECHO_PIN, INPUT);
  
     pinMode(MOTOR_PIN_1, OUTPUT);
     pinMode(MOTOR_PIN_2, OUTPUT);
     pinMode(MOTOR_PIN_3, OUTPUT);
     pinMode(MOTOR_PIN_4, OUTPUT);

     pinMode (PIN_POTENTIOMETER, INPUT);

  }
   
  void loop() {

     long timeMillis = millis();

     potentiometer = analogRead(PIN_POTENTIOMETER);
     speedMotors = map(potentiometer, MIN_VALUE, MAX_VALUE, TARGET_MIN_VALUE, TARGET_MAX_VALUE);

     Serial.println(speedMotors);
     
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
     if (distanceCm <= FIRST_DISTANCE) {
      Atras(speedMotors);
      Alante2(speedMotors);
     } 
     else {
      Atras(speedMotors);
      Atras2(speedMotors);
     }
     
     return distanceCm;
     
  }

