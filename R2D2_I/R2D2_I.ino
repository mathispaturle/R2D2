  /*
   * 
   * R2D2 ARDUINO: CODE FOR ARDUINO UNO I
   * MOTORS & SENSORS
   * 
   */
  
  //COMMUNICATION PINS
  #define RX 0
  #define TX 1
  
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
  #define NO_OBSATCLE 0
  #define OBSATCLE 1
  #define NULL_VALUE 0  
  

  //CONSTATANTS
  #define MAX_RPM 255
  #define FIRST_DISTANCE 30


  // VARIABLES
  int potentiometer;
  int speedMotors;
  long previousMillis = 0;
  int currentDistance;
  bool obstacle;
  int sendValue;
  
  void setup() {
     Serial.begin(9600);

     pinMode(RX, OUTPUT);
     pinMode(TX, INPUT);
     
     pinMode(TRIGGER_PIN, OUTPUT);
     pinMode(ECHO_PIN, INPUT);
     pinMode(MOTOR_PIN_1, OUTPUT);
     pinMode(MOTOR_PIN_2, OUTPUT);
     pinMode(MOTOR_PIN_3, OUTPUT);
     pinMode(MOTOR_PIN_4, OUTPUT);
     pinMode (PIN_POTENTIOMETER, INPUT);

     obstacle = false;
  }
   
  void loop() {

     long timeMillis = millis();

     potentiometer = analogRead(PIN_POTENTIOMETER);
     speedMotors = map(potentiometer, MIN_VALUE, MAX_VALUE, TARGET_MIN_VALUE, TARGET_MAX_VALUE);

     
     if (timeMillis - previousMillis > INTERVAL){
       currentDistance = ping(TRIGGER_PIN, ECHO_PIN);
       previousMillis = timeMillis;
     }

     // CHECK THE DISTANCES
     if (currentDistance <= FIRST_DISTANCE) {
      obstacle = true;
      Atras(speedMotors);
      Alante2(speedMotors);
     } 
     
     else {
      obstacle = false;
      Atras(speedMotors);
      Atras2(speedMotors);
     }

     //Send info to other Arduino
     if (obstacle){
      sendValue= 1;
     } else if (!obstacle){
      sendValue = 0;
     }else{
      sendValue = 1;
     }

    
    //if (Serial.available() > NULL_VALUE) {
       Serial.println(sendValue);
       //elay(100);
    //}
     
  }
  
  
  
  
  
  /*
   * 
   * ADDITIONAL MOVEMENT FUNCTIONS
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
  


  /*
   * 
   * ADDITIONAL DISTANCE FUNCTION
   * 
   */

  int ping(int TriggerPin, int EchoPin) {
    
     long duration, distanceCm;
     
     digitalWrite(TriggerPin, LOW);               //para generar un pulso limpio ponemos a LOW 4ms
     //delayMicroseconds(4);
     digitalWrite(TriggerPin, HIGH);              //generamos Trigger (disparo) de 10ms
     //delayMicroseconds(10);
     digitalWrite(TriggerPin, LOW);
     
     duration = pulseIn(EchoPin, HIGH);           //medimos el tiempo entre pulsos, en microsegundos
     
     distanceCm = duration * 10 / 292/ 2;         //convertimos a distancia, en cm
     
     return distanceCm;
     
  }

