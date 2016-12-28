#define MY_DEBUG
#define MY_RADIO_NRF24
#define MY_REPEATER_FEATURE
#include <MySensors.h>
#define RELAY_1  3 
#define NUMBER_OF_RELAYS 4 
#define RELAY_ON 0  
#define RELAY_OFF 1 

// +1 for easy offset state[0] not used
int state[NUMBER_OF_RELAYS+1];

void before() { 
  for (int sensor = 1, pin = RELAY_1; sensor <= NUMBER_OF_RELAYS; sensor++, pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, RELAY_OFF);
    state[sensor] = loadState(sensor);
  }
  digitalWrite(RELAY_1, state[1] ? RELAY_ON : RELAY_OFF);
  if (state[1]) {
    digitalWrite(RELAY_1 + 1, state[2] ? RELAY_ON : RELAY_OFF);
    digitalWrite(RELAY_1 + 2, state[3] ? RELAY_ON : RELAY_OFF);
    digitalWrite(RELAY_1 + 3, state[4] ? RELAY_ON : RELAY_OFF);   
  }
}

void setup() {
  for (int sensor = 1; sensor <= NUMBER_OF_RELAYS; sensor++) {
    send(MyMessage(sensor, S_BINARY).set(state[sensor]==HIGH));
  }
}

void presentation() {
  sendSketchInfo("Vento Switch", "0.2");
  for (int sensor = 1; sensor <= NUMBER_OF_RELAYS; sensor++) {
    present(sensor, S_BINARY);
  }
}

void loop() {
}

void go(int sensor,bool value) {
  if (sensor == 1) {
    digitalWrite(RELAY_1, value ? RELAY_ON : RELAY_OFF);
    if (not value && state[2]) digitalWrite(1 + RELAY_1, RELAY_OFF);
    if (not value && state[3]) digitalWrite(2 + RELAY_1, RELAY_OFF);
    if (not value && state[4]) digitalWrite(3 + RELAY_1, RELAY_OFF);      
    if (value && state[2]) digitalWrite(1 + RELAY_1, RELAY_ON);
    if (value && state[3]) digitalWrite(2 + RELAY_1, RELAY_ON);
    if (value && state[4]) digitalWrite(3 + RELAY_1, RELAY_ON);      
  } else {
    if (state[1]) {
        digitalWrite(sensor - 1 + RELAY_1, value ? RELAY_ON : RELAY_OFF);
    } 
  }
  send(MyMessage(sensor, S_BINARY).set(value==HIGH));  
  state[sensor] = value;
  saveState(sensor,value);
  Serial.println(state[sensor]);
}

void receive(const MyMessage &message) {
  if (message.type == V_STATUS) {
    if (message.sensor == 1) {
      go(1,message.getBool()); 
    }
    if (message.sensor == 2) {
      go(3,false);
      go(4,false);   
      go(2,true);
    }
    if (message.sensor == 3) {
      go(2,false);
      go(4,false);
      go(3,true);
    }
    if (message.sensor == 4) {
      go(2,false);
      go(3,false);
      go(4,true);
    }

    #ifdef MY_DEBUG
    Serial.print("Incoming change for sensor:");
    Serial.print(message.sensor);
    Serial.print(", New status: ");
    Serial.println(message.getBool());
    #endif
  }
}
