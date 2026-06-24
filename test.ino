// CHANGE TO REQUIRED PINS
const int TRIG_PIN = 11;
const int ECHO_PIN = 10;

// Motor A pins
const int ENA = 9;
const int IN1 = 8;
const int IN2 = 7;

// Motor B pins
const int ENB = 3;
const int IN3 = 5;
const int IN4 = 4;

void setup() {
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    digitalWrite(TRIG_PIN, LOW);

    // Set all the motor control pins to outputs
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // Set full power to motors
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
}

void loop() {
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    unsigned long duration = pulseIn(ECHO_PIN, HIGH); 

    float distance_cm = (duration * 0.017)

    Serial.print("Distance: ");
    Serial.println(distance_cm);

    if (distance_cm < 50) {
        forward();
    }

    delay(250);
}

void forward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}
