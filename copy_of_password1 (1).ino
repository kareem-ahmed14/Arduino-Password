#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(38, 16, 2);
#include <Keypad.h>
const byte cols = 4;
const byte rows = 4;
int counter = 0;
int counter1 = 0;
char a, b, c, d, e, f;
char g[6] = {'1', '6', '1', '0', '2', '0'};
char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte row_pins[] = {2, 3, 4, 5};
byte col_pins[] = {6, 7, 8, 9};
Keypad myKeypad(makeKeymap(keys), row_pins, col_pins, rows, cols);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Ent pass:");
}


void resetPassword() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("New pass:");

  char newPass[6] = {'\0'}; // Array to store the new password

  while (counter < 7) {
    char key = myKeypad.getKey();

    if (key) {
      if (key == 'C') {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Ent pass:");
        counter = 0;
        counter1 = 0;
        return;
      }
      else if (key == 'D') {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Ent pass:");
        counter = 0;
        counter1 = 0;
        return;
      }
      else {
        lcd.setCursor(8 + counter, 0);
        lcd.print(key);
        newPass[counter] = key;
        counter++;
      }
    }
  }

  for (int i = 0; i < 6; i++) {
    g[i] = newPass[i]; // Update the password with the new one
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Password reset");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ent pass:");
  counter = 0;
  counter1 = 0;
}



void loop() {
  char m = myKeypad.getKey();
  if (m) {
    if (m == g[counter]) {
      counter1++;
    }
    counter++;
    if (m == 'D') {
      if (counter1 >= 6) {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Right pass");
        delay(2000);
        lcd.clear();
        counter = 0;
        counter1 = 0;
        lcd.setCursor(0, 0);
        lcd.print("Ent pass:");
      }
      else {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Wrong password");
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        counter = 0;
        counter1 = 0;
        lcd.print("Ent pass:");
      }
   
    }
    if (counter == 1) {
      lcd.setCursor(9, 0);
      lcd.print(m);
    }
    if (counter == 2) {
      lcd.setCursor(10, 0);
      lcd.print(m);
    }
    if (counter == 3) {
      lcd.setCursor(11, 0);
      lcd.print(m);
    }
    if (counter == 4) {
      lcd.setCursor(12, 0);
      lcd.print(m);
    }
    if (counter == 5) {
      lcd.setCursor(13, 0);
      lcd.print(m);
    }
    if (counter == 6) {
      lcd.setCursor(14, 0);
      lcd.print(m);
    }
    if (m == 'C') {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ent pass:");
      counter = 0;
      counter1 = 0;
    }
     if (m == 'A') {
      resetPassword();
    }
  }
}

