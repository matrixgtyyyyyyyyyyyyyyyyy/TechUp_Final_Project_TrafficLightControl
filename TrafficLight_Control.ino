#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD setup (address 32 or 0x3F in Tinkercad)
LiquidCrystal_I2C lcd(32, 16, 2);

const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;
const int buttonPin = 7;

bool pedRequest = false;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Button active LOW

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Traffic System");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Green for cars
  digitalWrite(greenLED, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("Cars: GO   ");
  lcd.setCursor(0, 1);
  lcd.print("Ped: WAIT  ");

  for (int i = 0; i < 50; i++) { // 5s, check button every 100ms
    if (digitalRead(buttonPin) == LOW) {
      pedRequest = true;
    }
    delay(100);
  }
  digitalWrite(greenLED, LOW);

  // Yellow
  digitalWrite(yellowLED, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cars: SLOW ");
  lcd.setCursor(0, 1);
  lcd.print("Ped: WAIT  ");
  delay(2000);
  digitalWrite(yellowLED, LOW);

  // Red for cars
  digitalWrite(redLED, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cars: STOP ");

  if (pedRequest) {
    lcd.setCursor(0, 1);
    lcd.print("Ped: WALK  ");
    delay(5000); // Walk time
    pedRequest = false;
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Ped: WAIT  ");
    delay(5000);
  }

  digitalWrite(redLED, LOW);
  lcd.clear();
}