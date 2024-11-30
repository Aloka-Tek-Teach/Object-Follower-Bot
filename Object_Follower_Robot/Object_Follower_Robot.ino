//@alokatekteack youtube channel subescrib now

#define trigPin 8
#define echoPin 9

#define motor1Pin1 2 // Left motor
#define motor1Pin2 3
#define motor2Pin1 4 // Right motor
#define motor2Pin2 5

long duration;
int distance;
int detectionThreshold = 50; // Maximum distance for object detection in cm
int desiredDistance = 15;    // Target distance from the object in cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 0 && distance <= detectionThreshold) { // Object detected within range
    if (distance < desiredDistance - 5) {
      moveBackward(); // Too close, move backward
    } else if (distance > desiredDistance + 5) {
      moveForward(); // Too far, move forward
    } else {
      stopRobot(); // Within range, stop
    }
  } else {
    stopRobot(); // No object detected, stop
  }

  delay(100);
}

void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  Serial.println("Moving Forward");
}

void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  Serial.println("Moving Backward");
}

void stopRobot() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  Serial.println("Stopping");
}
