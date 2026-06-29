const int dirPin = A2; // Green wire
const int stePin = A3; // Orange wire
const int buttonPin = 3; // Blue wire
const int ledPin = 2; // Yellow wire

void setup() {
  // pinMode -> How we want the pins to behave, they behave as either an output or input
  // OUTPUT -> Pin that outputs information to something
  // INPUT -> Pin that recieves information from something

  pinMode(dirPin, OUTPUT); //A2 (Arduino pin) is outputting information to the direction pin on the motor driver
  pinMode(stePin, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP); //A4 inputs information to the arduino (turn on) -> INPUT_PULLUP stops button from floating and results in LOW when pin is pressed and HIGH when not pressed
  pinMode(ledPin, OUTPUT); //A5 tells the LED to turn on when the wheel is turning after the button is pressed

  // digitalWrite -> tells an OUTPUT pin to go either HIGH or LOW
  // HIGH for the dirPin on the driver means the motor goes CW
  // LOW for the dirPin on the driver means the motor goes CCW (We want CCW because of our design concept)
  digitalWrite(dirPin, LOW);
  digitalWrite(ledPin, HIGH); // Turns the LED ON
  digitalWrite(ledPin, LOW); // Turns the LED OFF

}

void loop() {
  bool dispenseCandy = digitalRead(buttonPin) == LOW; // LOW means button is pressed because of INPUT_PULLUP
  // digitalRead tells us the signal (0 -> LOW, 1-> HIGH) given off from the button when pressed
  // We store it in a boolean type variable if digitalRead finds buttonPin to be LOW it will equate to TRUE which is stored in the dispenseCandy variable

  // if user wants to dispenseCandy (dispenseCandy == True) we turn on the LED (HIGH) and rotate the wheel 1 full cycle (360 from original position)

  if (dispenseCandy) {
    digitalWrite(ledPin, HIGH); // LED ON fvf

    // 1 full motor step = 1.8 degrees
    // We need 360 degrees -> 1.8 * x = 360 -> 360/1.8 = 200 steps
    // We need to make it go that amount of steps
    for (int i=0; i < 200; i++) { // this is 200 steps
      // 1 Step -> (Beginning)
      digitalWrite(stePin, HIGH); // Starts the step pulse (motor takes a step/moves certain amount) pin goes to 5V
      delayMicroseconds(7000); // 5000 microseconds makes it run smoothly // lower this number the faster it goes
      digitalWrite(stePin, LOW); // pin goes to 0 volts
      delayMicroseconds(7000);
      // 1 Step -> (Ending)
    }

    digitalWrite(ledPin, LOW); // So the light waits till after the 360 degree turn

  }

}
