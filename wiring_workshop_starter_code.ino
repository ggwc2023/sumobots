/*******************************************
*        Defining our motor pins
********************************************/

// Motor A
int RIGHT_SPEED = 9; // Speed pin, ranges from 0 to 255 (ENA). 9 shows pin.
int RIGHT_F = 14; // Pin to move motor forwards (IN1)
int RIGHT_R = 15; // Pin to move motor backwards (IN2)

// Motor B
int LEFT_SPEED = 10; // Speed pin, ranges from 0 to 255 (ENB)
int LEFT_F = 16; // Pin to move motor forwards (IN3)
int LEFT_R = 17; // Pin to move motor backwards (IN4)

void setup() { // Put your setup code here, to run once:
  // Setting up the serial monitor
  Serial.begin(9600);
  Serial.println("Setting pins for motors");

  // Setup all the motor control pins to outputs
  pinMode(RIGHT_SPEED, OUTPUT);
  pinMode(RIGHT_F, OUTPUT);
  pinMode(RIGHT_R, OUTPUT);

  pinMode(LEFT_SPEED, OUTPUT);
  pinMode(LEFT_F, OUTPUT);
  pinMode(LEFT_R, OUTPUT);
}

void loop() {
  // Put your main code here, to run repeatedly: make motors move.
  // Feel free to comment out testMotors and write your own test for specific functions
  testMotors();
}

// Have a go completing all the rest of the functions 
// Think about which motor needs to go forwards or backwards

void motorSTOP() { // This will stop both motors, I have done this one for you
  digitalWrite(RIGHT_F, LOW);
  digitalWrite(RIGHT_R, LOW);

  digitalWrite(LEFT_F, LOW);
  digitalWrite(LEFT_R, LOW);
}

void driveForward() {
  //use table from earlier here to make it move forward, highs/lows

}

void driveBackward() {
 //use table from earlier here to make it move back, highs/lows
}

void turnRight() {
 //use table from earlier here to make only left motor spin--
}

void turnLeft() {
  //use table from earlier here to make only left motor spin
}

void testMotors() {
  Serial.println("--- Starting motor test ---");

  Serial.println("--- Testing driveForward ---");
  driveForward();
  delay(500);

  Serial.println("--- Testing driveBackward ---");
  driveBackward();
  delay(500);

  Serial.println("--- Testing turnRight ---");
  turnRight();
  delay(500);

  Serial.println("--- Testing turnLeft ---");
  turnLeft();
  delay(500);

  motorSTOP();
  Serial.println("--- Motor test complete ---");
}

