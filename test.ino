// CHANGE TO REQUIRED PINS
const int TRIG_PIN = 9;
const int ECHO_PIN = 8;

void setup() {
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    digitalWrite(TRIG_PIN, LOW);
}

void loop() {
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    unsigned long duration = pulseIn(ECHO_PIN, HIGH); 

    float distance_cm = (duration * 0.017)

    Serial.print("Distance: ");
    Serial.println(distance_cm);

    delay(250);
}