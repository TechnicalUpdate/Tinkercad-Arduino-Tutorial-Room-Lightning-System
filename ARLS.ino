
// Tinkercad Arduino  Tutorials: Tutorials: Automatic Room Lightning System

int LightSensorVal = 0; //Input SEnsor
int PIRSensorVal = 0;   //Input S
int RelayOutputVal = 0;  //Output Relay 

void setup()
{
  pinMode(A0, INPUT); // Read the LDR sensor Value digital Input
  pinMode(2, INPUT);  // Read the PIR motion sensor value digital Input
  pinMode(8, OUTPUT); // Write the Relay output value, digital output
  Serial.begin(9600);

}

void loop()
{
  LightSensorVal = analogRead(A0);
  PIRSensorVal = digitalRead(2);
  RelayOutputVal = 8;
  if (LightSensorVal < 600) {
    if (PIRSensorVal == HIGH) {
      digitalWrite(8, HIGH);
      delay(5000); // Wait for 5000 millisecond(s)
    } else {
      digitalWrite(8, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
    }
  } else {
    digitalWrite(8, LOW);
    Serial.println(LightSensorVal);
    delay(300); // Wait for 300 millisecond(s)
  }
}