// A simple Code to setup an LED toggle on arduino
// The LED is connected to pin 13
// A push button connects the pin to ground. `

// Remember that in arduino, the setup() function runs one at the start of the code execution and the loop() function runs continously

// LED and switch connections
const byte ledPin = 13; 
const byte buttonPin = 2;

// A bool to indicate the state of the toggle
// Volatile tells the compiler that the the variable is not constant and can be changed by external events
volatile bool toggleState = false; 

void checkSwitch(){
    //Check status of the switch 
    // Toggle LED if button is pressed

    // digitalRead() returns HIGH or LOW depending on what value is found at a PIN
    // HIGH and LOW are preprocessor directives for 0x01 and 0x00
    if (digitalRead(buttonPin) == LOW){
      // Switch was pressed
      // Slight delay to debounce
      delay(200);

      // Change state of toggle
      toggleState = !toggleState;

      // digitalWrite() accepts HIGH and LOW or 1 and 0
      // Booleans convert to ints with true = 1, false = 0
      digitalWrite(ledPin, toggleState); 
    }

}

void setup() {
  // Set LED pin as output
  pinMode(ledPin, OUTPUT);

  // Set switch pin as INPUT with pullup
  // Remember that pullup resistors are needed for active low states to 
  // keep the base value at a high voltage so the system can change if 
  // the button connects the voltage to ground. 
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Call check switch function repeatedly forever
  checkSwitch();
}
