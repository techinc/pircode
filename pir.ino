/*
 * PIR sensor tester
 */
 
int ledPin = 13;                // choose the pin for the LED
int inputPinA = 2;               // choose the input pin (for PIR sensor)
int powerPinA = 3;
int inputPinB = 4;
int powerPinB = 5;

int pirStateA = LOW;
int pirStateB = LOW;
int valA = 0;                    // variable for reading the pin status
int valB = 0;
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPinA, INPUT);     // declare sensor as input
  pinMode(powerPinA, OUTPUT);
  pinMode(inputPinB, INPUT);
  pinMode(powerPinB, OUTPUT);
  digitalWrite(powerPinA, HIGH);
  digitalWrite(powerPinB, HIGH);
  Serial.begin(9600);
}

void loop(){
  valA = digitalRead(inputPinA);  // read input value A
  valB = digitalRead(inputPinB); //
//  Serial.println(valB);
  if (valA == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirStateA == LOW) {
      // we have just turned on
      Serial.println("A");
      // We only want to print on the output change, not state
      pirStateA = HIGH;
    }
  } 
  if (valA == LOW) {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirStateA == HIGH){
      // we have just turned of
      Serial.println("Z");
      // We only want to print on the output change, not state
      pirStateA = LOW;
    }
  }
  
  if (valB == HIGH) {            // check if the input is HIGH
    if (pirStateB == LOW) {
      // we have just turned on
      Serial.println("B");
      // We only want to print on the output change, not state
      pirStateB = HIGH;
    }
  } 
  if (valB == LOW) {
    if (pirStateB == HIGH){
      // we have just turned of
      Serial.println("Y");
      // We only want to print on the output change, not state
      pirStateB = LOW;
    }
  }
}
