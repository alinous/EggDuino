void initHardware(){
  // enable eeprom wait in avr/eeprom.h functions
  SPMCSR &= ~SELFPRGEN;

  pinMode(enableRotMotor, OUTPUT); 
  pinMode(enablePenMotor, OUTPUT);  
  pinMode(prgButton, INPUT_PULLUP);
  pinMode(penToggleButton, INPUT_PULLUP);
  rotMotor.setMaxSpeed(2000.0);
  rotMotor.setAcceleration(10000.0);
  penMotor.setMaxSpeed(2000.0);
  penMotor.setAcceleration(10000.0);
  digitalWrite(enableRotMotor, HIGH) ;
  digitalWrite(enablePenMotor, HIGH) ;
  penServo.attach(servoPin);
  penServo.write(penUpPos);
  }

void inline loadPenPosFromEE() {
  penUpPos = eeprom_read_word(penUpPosEEAddress);
  penDownPos = eeprom_read_word(penDownPosEEAddress);
  penState = penUpPos;
}

void inline storePenUpPosInEE() {
  eeprom_update_word(penUpPosEEAddress, penUpPos);
}

void inline storePenDownPosInEE() {
  eeprom_update_word(penDownPosEEAddress, penDownPos);
}

void inline sendAck(){
	Serial.print("OK\r\n");
}

void inline sendError(){
	Serial.print("unknown CMD\r\n");
}

void inline checkPenToggleButton() {
  int b = digitalRead(penToggleButton);

  long t = millis();

  if (b != lastPenToggleButtonState) {
    penToggleButtonDebounce = t;
  }

  if ((t - penToggleButtonDebounce) > debounceDelay) {
    if (b != penToggleButtonState) {
      penToggleButtonState = b;

      if (LOW == penToggleButtonState) {
        doTogglePen();
      }
    }
  }

  lastPenToggleButtonState = b;
}

