
// ---------------- Pin Configuration ----------------
const int ledPins[4] = {2, 4, 5, 18};
const int buttonPins[4] = {12, 13, 14, 27};

// ---------------- Game Variables ----------------
int sequence[100];
int level = 0;
bool gameOver = false;

// ---------------- Setup ----------------
void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  randomSeed(analogRead(34));
  startGame();
}

// ---------------- Main Loop ----------------
void loop() {
  if (!gameOver) {
    showSequence();
    checkUserInput();
  }
}

// ---------------- Start Game ----------------
void startGame() {
  level = 1;
  gameOver = false;
  generateSequence();
}

// ---------------- Generate Random Sequence ----------------
void generateSequence() {
  for (int i = 0; i < 100; i++) {
    sequence[i] = random(0, 4);
  }
}

// ---------------- Show LED Sequence ----------------
void showSequence() {
  delay(500);

  for (int i = 0; i < level; i++) {
    digitalWrite(ledPins[sequence[i]], HIGH);
    delay(500);
    digitalWrite(ledPins[sequence[i]], LOW);
    delay(300);
  }
}

// ---------------- Check User Input ----------------
void checkUserInput() {
  for (int i = 0; i < level; i++) {

    int buttonPressed = waitForButton();

    if (buttonPressed != sequence[i]) {
      failAnimation();
      startGame();
      return;
    }
  }

  level++;
  delay(500);
}

// ---------------- Wait for Button Press ----------------
int waitForButton() {
  while (true) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(buttonPins[i]) == LOW) {
        delay(200);
        return i;
      }
    }
  }
}

// ---------------- Failure Indication ----------------
void failAnimation() {
  gameOver = true;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(300);

    for (int j = 0; j < 4; j++) {
      digitalWrite(ledPins[j], LOW);
    }
    delay(300);
  }
}
