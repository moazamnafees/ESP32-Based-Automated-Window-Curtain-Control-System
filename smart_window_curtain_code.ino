// ---------------- SENSOR PINS ----------------
#define S1 7   // Upper sensor (D0 pin of opto sensor)
#define S2 6   // Lower sensor (D0 pin of opto sensor)

// ---------------- MANUAL BUTTONS ----------------
#define DOWN_BTN 9
#define UP_BTN   8

// ---------------- L298N MOTOR DRIVER PINS ----------------
#define ENA 4       // PWM speed control
#define IN1 3      // Motor direction 1
#define IN2 2       // Motor direction 2

// ---------------- CONFIG ----------------
int motorSpeed = 200;   // (0–255) Reduce if motor too fast (PWM)


void setup() {
  Serial.begin(115200);

  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);
  pinMode(DOWN_BTN, INPUT_PULLUP);
  pinMode(UP_BTN, INPUT_PULLUP);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  stopMotor();
}

void loop() {

  int s1 = digitalRead(S1);
  int s2 = digitalRead(S2);
  int downBtn = digitalRead(DOWN_BTN);
  int upBtn = digitalRead(UP_BTN);

  // ------ Serial Logs ------
  Serial.print("S1="); Serial.print(s1);
  Serial.print("  S2="); Serial.print(s2);
  Serial.print("  DOWN="); Serial.print(downBtn);
  Serial.print("  UP="); Serial.println(upBtn);

  // ===================== DOWN BUTTON =====================
  if (downBtn == LOW) {
    if (s1 == 0 && s2 == 0) {
      stopMotor();
    } else {
      moveDown();
    }
    return;
  }

  // ===================== UP BUTTON =====================
  if (upBtn == LOW) {
    if (s1 == 1 && s2 == 1) {
      stopMotor();
    } else {
      moveUp();
    }
    return;
  }

  // No button pressed
  stopMotor();
}


// ===================== MOTOR CONTROL =====================

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);    // Motor OFF
}

void moveDown() {  // Clockwise
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, motorSpeed);
}

void moveUp() {    // Anti-clockwise
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, motorSpeed);
}
