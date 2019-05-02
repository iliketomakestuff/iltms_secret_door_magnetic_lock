/*
* This code is for the project at 
* http://www.iliketomakestuff.com/how-to-make-a-secret-room-through-a-wardrobe
* All of the components are list on the url above.
* 
* We offer NO SUPPORT for this code, and do not promise any updates/improvements.
* Please regard this as "unoptimized, prototype code".
* 
*This script was created by Bob Clagett for I Like To Make Stuff
*For more projects, check out iliketomakestuff.com
*/
// Include the Bounce2 library found here :
// https://github.com/thomasfredericks/Bounce2
#include <Bounce2.h>

#define BUTTON_PIN 14
#define BUTTON_PIN2 16
#define LED_PIN 12
#define RELAY_PIN 13

boolean lockEngage = false;
int lockState = LOW;
int debounceInterval = 25;

Bounce debouncer = Bounce(); // Instantiate a Bounce object
Bounce debouncer2 = Bounce(); // Instantiate a Bounce object

void setup() {
  Serial.begin(9600);  
  debouncer.attach(BUTTON_PIN,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  debouncer2.attach(BUTTON_PIN2,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  debouncer.interval(debounceInterval);
  debouncer2.interval(debounceInterval); 

  pinMode(BUTTON_PIN,INPUT_PULLUP);
  pinMode(BUTTON_PIN2,INPUT_PULLUP);
  pinMode(RELAY_PIN,OUTPUT); // Setup the LED
  pinMode(LED_PIN,OUTPUT); // Setup the LED
  digitalWrite(RELAY_PIN,lockState);
  digitalWrite(LED_PIN,lockState);
 Serial.println("cool beans");
}

void loop() {
   debouncer2.update();
   debouncer.update(); 
    // Get the updated value :
  int value1 = debouncer.read();
  int value2 = debouncer2.read();
     if ( debouncer.fell() || debouncer2.fell()) {  // Call code if button transitions from HIGH to LOW
     Serial.println("click");
     lockState = !lockState; // Toggle lock state
     if (lockState == HIGH){
      delay(3500);
      }
     lockEngage = lockState; 
     digitalWrite(RELAY_PIN, lockEngage);
     digitalWrite(LED_PIN, lockEngage);
   }  
}
