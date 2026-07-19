/*
  - On power-up, wait 5s
  - Spin in place, pinging the ultrasonic sensor, until an object is detected
  - Once detected, charge forward
  - If the object is lost, resume searching
  - If it drifts off-center, steer to re-center on it
*/

// ---------- PIN DEFINITIONS  ----------
// Motor A (right)
const int RIGHT_SPEED = 9; // Speed pin, ranges from 0 to 255 (ENA)
const int RIGHT_F = 8; // Pin to move motor forwards (IN1)
const int RIGHT_R = 7; // Pin to move motor backwards (IN2)

// Motor B (left)
const int ENB = 10; // Speed pin, ranges from 0 to 255 (ENB)
const int IN3 = 6; // Pin to move motor forwards (IN3)
const int IN4 = 5; // Pin to move motor backwards (IN4)

// Ultrasonic sensor
const int TRIG_PIN = 11;
const int ECHO_PIN = 12;

// ---------- CONSTANT VALUES ----------
const int SEARCH_SPEED   = 150;
const int ATTACK_SPEED   = 255; 
const int TURN_SPEED     = 180;

//How close other robot is before it is 'detected'
const int DETECT_DISTANCE_CM = 60; 
//How far other robot is before it is 'lost'
const int LOST_DISTANCE_CM   = 80;

//How long robot waits before moving
const unsigned long START_DELAY_MS = 5000;

// ---------- SETUP ----------
void setup() {
  //Set all motor control pins to outputs
  pinMode(RIGHT_SPEED, OUTPUT);
  pinMode(RIGHT_F, OUTPUT);
  pinMode(RIGHT_R, OUTPUT);
  pinMode(LEFT_SPEED, OUTPUT);
  pinMode(LEFT_F, OUTPUT);
  pinMode(LEFT_R, OUTPUT);
  
  //Set full power to motors
  analogWrite(RIGHT_SPEED, 255);
  analogWrite(LEFT_SPEED, 255);

  //Setup ultrasonic sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  stopMotors();

  //Wait 5 seconds
  delay(START_DELAY_MS);
}

// ---------- MAIN LOOP ----------
void loop() {
  long distance = getDistanceCM();

  
  if (distance > 0 && distance < DETECT_DISTANCE_CM) {
    // If opponent detected charge at them
    driveForward(ATTACK_SPEED);
  } else {
    // Otherwise spin in place to find other robot
    spinSearch();
  }
}

// ---------- SEARCH ----------
//Robot spins in place
void spinSearch() {
  motor(ENA, IN1, IN2, -SEARCH_SPEED);
  motor(ENB, IN3, IN4, SEARCH_SPEED);
}

// ---------- MOVEMENT ----------
// void driveForward(int speed) {
//   motor(ENA, IN1, IN2, speed);
//   motor(ENB, IN3, IN4, speed);
// }

// void driveBackward(int speed) {
//   motor(ENA, IN1, IN2, -speed);
//   motor(ENB, IN3, IN4, -speed);
// }

// void turnLeft(int speed) {
//   motor(ENA, IN1, IN2, -speed / 2);
//   motor(ENB, IN3, IN4, speed);
// }

// void turnRight(int speed) {
//   motor(ENA, IN1, IN2, speed);
//   motor(ENB, IN3, IN4, -speed / 2);
// }

// void stopMotors() {
//   analogWrite(ENA, 0);
//   analogWrite(ENB, 0);
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, LOW);
// }

void motorSTOP() {
  digitalWrite(RIGHT_F, LOW);
  digitalWrite(RIGHT_R, LOW);

  digitalWrite(LEFT_F, LOW);
  digitalWrite(LEFT_R, LOW);
}

void driveForward(int speed) {
  analogWrite(RIGHT_SPEED, speed);
  digitalWrite(RIGHT_F, HIGH);
  digitalWrite(RIGHT_R, LOW);

  analogWrite(LEFT_SPEED, speed);
  digitalWrite(LEFT_F, HIGH);
  digitalWrite(LEFT_R, LOW);
}

void driveBackward(int speed) {
  analogWrite(RIGHT_SPEED, speed);
  digitalWrite(RIGHT_F, LOW);
  digitalWrite(RIGHT_R, HIGH);

  analogWrite(LEFT_SPEED, speed);
  digitalWrite(LEFT_F, LOW);
  digitalWrite(LEFT_R, HIGH);
}

void turnRight(int speed) {
  analogWrite(RIGHT_SPEED, speed);
  digitalWrite(RIGHT_F, LOW);
  digitalWrite(RIGHT_R, HIGH);

  analogWrite(LEFT_SPEED, speed);
  digitalWrite(LEFT_F, HIGH);
  digitalWrite(LEFT_R, LOW);
}

void turnLeft(int speed) {
  analogWrite(RIGHT_SPEED, speed);
  digitalWrite(RIGHT_F, HIGH);
  digitalWrite(RIGHT_R, LOW);

  analogWrite(LEFT_SPEED, speed);
  digitalWrite(LEFT_F, LOW);
  digitalWrite(LEFT_R, HIGH);
}

// // speed: -255 to 255 (negative = reverse)
// void motor(int enPin, int in1, int in2, int speed) {
//   speed = constrain(speed, -255, 255);
//   if (speed >= 0) {
//     digitalWrite(in1, HIGH);
//     digitalWrite(in2, LOW);
//   } else {
//     digitalWrite(in1, LOW);
//     digitalWrite(in2, HIGH);
//     speed = -speed;
//   }
//   analogWrite(enPin, speed);
// }

// ---------- ULTRASONIC SENSOR ----------
long getDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout (~5m range)
  if (duration == 0) return -1; // no echo received

  long distance = duration * 0.0343 / 2; // speed of sound conversion
  return distance;
}

