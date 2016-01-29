// Connection pin
#define CONNECTION_PIN 12

// TODO: Serial port speed
#define SERIAL_SPEED 115200

#define COMMAND_TURN_ON 84 // T
#define COMMAND_TURN_OFF 79 // O

void experiment_turn_off();

void setup() {
  // Set up connection pin as OUTPUT, LOW
  pinMode(CONNECTION_PIN, OUTPUT);
  experiment_turn_off();
  
  // Set up serial port
  Serial.begin(SERIAL_SPEED);
  while(!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  
  // TODO: Read time.
  // TODO: Send the time so the host can synchronize RTC with milliseconds.
}

void loop() {
  // TODO: Check sensors
  // TODO: Format Sensor data to write out
  // Listen for commands from the serial port
  int command = 0;
  if(Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);

    switch(command) {
      case COMMAND_TURN_ON:
        experiment_turn_on();
        break;
      case COMMAND_TURN_OFF:
        experiment_turn_off();
        break;
    }
  }
}

void experiment_turn_on() {
  Serial.println("Turning relay on");
  digitalWrite(CONNECTION_PIN, HIGH);
}

void experiment_turn_off() {
  Serial.println("Turning relay off");
  digitalWrite(CONNECTION_PIN, LOW);
}

