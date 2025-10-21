// LEDs VARIABLES
int redLED = 3;
int yellowLED = 4;
int greenLED = 5;
int blueLED1 = 6;
int blueLED2 = 7;

// BUTTONs VARIABLES
int button1 = 11;
int button2 = 10;

// BUZZERs VARIABLES
int buzzer = 9;

// Other Variables
bool buttonPressed = 0;

void setup() {
  // LEDs setup
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED1, OUTPUT);
  pinMode(blueLED2, OUTPUT);

  // BUTTONs setup
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  //BUZZERs setup
  pinMode(buzzer, OUTPUT);

  //NUMBER RNG
  randomSeed(analogRead(A0));
}

void loop() {
  digitalWrite(redLED, HIGH);
  tone(buzzer, 100);
  delay(100);
  noTone(buzzer);

  delay(1900);

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  tone(buzzer, 250);
  delay(100);
  noTone(buzzer);

  delay(1900);

  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  tone(buzzer, 500);
  delay(100);
  noTone(buzzer);

  delay(random(1500, 5001));

  digitalWrite(greenLED, LOW);

  buttonPressed = 0;

  while (buttonPressed == 0) {
    digitalWrite(blueLED1, HIGH);
    digitalWrite(blueLED2, HIGH);

    if (digitalRead(button1) == 0) {
      buttonPressed = 1;
      digitalWrite(blueLED2, LOW);
      tone(buzzer, 3000);
      delay(150);
      noTone(buzzer);

    } else if (digitalRead(button2) == 0) {
      buttonPressed = 1;
      digitalWrite(blueLED1, LOW);
      tone(buzzer, 3000);
      delay(150);
      noTone(buzzer);

    }
  }

  delay(5000);

  digitalWrite(blueLED1, LOW);
  digitalWrite(blueLED2, LOW);
  buttonPressed = 0;
}
