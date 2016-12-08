//PWM LED Brightness and Bluetooth Serial Link

int Green_LED_Pin = 9; // PWM Pin for Green LED
int Yellow_LED_Pin = 10; // PWM Pin for Yellow LED

//Varibles to hold brightness values ranging from 0 (off) to 255 (fully on)
int Green_value=0;
int Yellow_value=0;

char BluetoothData; // the data received from bluetooth serial link

void setup() {
  
  // Initialise LED pins as outputs
  pinMode(Green_LED_Pin, OUTPUT);
  pinMode(Yellow_LED_Pin, OUTPUT);

  //initialsie serial communication
  Serial.begin(9600);
}

void loop() {

  //Process any info coming from the bluetooth serial link
  if (Serial.available()){
    BluetoothData=Serial.read(); //Get next character from bluetooth
    if(BluetoothData=='G') Green_value=Serial.parseInt(); //Read Green value
    if(BluetoothData=='Y') Yellow_value=Serial.parseInt(); //Read Yellow Value
  }
  
  //update LED Brightness
  analogWrite(Green_LED_Pin, Green_value);
  analogWrite(Yellow_LED_Pin, Yellow_value);
  
  delay(10);
  
}

