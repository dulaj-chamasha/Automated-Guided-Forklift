#include  <Servo.h>

Servo Forklift;





int S_A = 5;    // Speed motor A
int M_A1 = 8;   // Motor A = +
int M_A2 = 7;   // Motor A = -
int M_B1 = 3;   // Motor B = -
int M_B2 = 2;   // Motor B = +
int S_B = 6;    // Speed motor B

int R_S = 11;   // Sensor R
int S_S = 10;   // Sensor S
int L_S = 9;    // Sensor L

const int trigPin = 12; // Ultrasonic sensor trigger pin
const int echoPin = 13; // Ultrasonic sensor echo pin

void setup() {

  Forklift.attach(4);  //servo motor pin
  Forklift.write(180);  //servo motor initial position

  pinMode(M_B1, OUTPUT);
  pinMode(M_B2, OUTPUT);
  pinMode(M_A1, OUTPUT);
  pinMode(M_A2, OUTPUT);
  pinMode(S_B, OUTPUT);
  pinMode(S_A, OUTPUT);

  pinMode(L_S, INPUT);
  pinMode(S_S, INPUT);
  pinMode(R_S, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  analogWrite(S_A, 65);
  analogWrite(S_B, 65);
  //delay(200);
}

void loop() {
  
   float distance = getUltrasonicDistance();

   if (distance <3) { 
     Stop();                 // Stop the robot if an object is detected within 3cm
     delay(1500);
     for(int i =180; i>=0; i--){
         Forklift.write(i);
         delay(10);    
     }

     delay(1000);
     
     while(true){
      
      if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 0)) {
          forward();
        }
    
        if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 0)) {
          turnLeft();
        }
    
        if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 0) && (digitalRead(R_S) == 0)) {
          turnLeft();
        }
    
        if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 1)) {
          turnRight();
        }
    
        if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 0) && (digitalRead(R_S) == 1)) {
          turnRight();
        }
    
        if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 1)) {                //all sensors in black line
          Stop();
          delay(1500);
          for(int i =0; i<=180; i++){
             Forklift.write(i);
             delay(10);
          }
          delay(1000);
          backward();
          delay(600);
          while(true){
            Stop(); 
          }
          
        }
    
        if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 0) && (digitalRead(R_S) == 0)) {
          Stop();
        }



     }
   }

    else {
      
        if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 0)) {
          forward();
        }
    
        if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 0)) {
          turnLeft();
        }
    
        if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 0) && (digitalRead(R_S) == 0)) {
          turnLeft();
        }
    
        if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 1)) {
          turnRight();
        }
    
        if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 0) && (digitalRead(R_S) == 1)) {
          turnRight();
        }
    
        if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 1)) {
          Stop();
        }
    
        if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 0) && (digitalRead(R_S) == 0)) {
          Stop();
        }
  }


}



void forward() {
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
}

void backward() {
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, HIGH);
}


void turnRight() {
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
}

void turnLeft() {
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
}

void Stop() {
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
}

void setupUltrasonic() {
  // Additional ultrasonic sensor setup code if needed
}

float getUltrasonicDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  return distance;
}
