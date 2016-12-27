
#define MY_DEBUG
#define MY_RADIO_NRF24
#define MY_REPEATER_FEATURE

#include <MySensors.h>

#define RELAY_OFF 1
#define RELAY_ON 0
 
#define RELAY_POWER 3  
#define RELAY_LEVEL2 4 
#define RELAY_LEVEL3 5  

#define MYSENSOR_POWER 1 
#define MYSENSOR_LEVEL1 2
#define MYSENSOR_LEVEL2 3
#define MYSENSOR_LEVEL3 4

#define LEVEL1 1
#define LEVEL2 2
#define LEVEL3 3

#define MEM_POWER 1
#define MEM_LEVEL 2

bool power = false;
int level = 1;
bool level1 = true;
bool level2 = false;
bool level3 = false;

void before() { 
    power =  loadState(MEM_POWER);
    pinMode(RELAY_POWER, OUTPUT);
    digitalWrite(RELAY_POWER, power ? RELAY_ON : RELAY_OFF);
 
    pinMode(RELAY_LEVEL2, OUTPUT);
    digitalWrite(RELAY_LEVEL2, RELAY_OFF);
    pinMode(RELAY_LEVEL3, OUTPUT);
    digitalWrite(RELAY_LEVEL3, RELAY_OFF);

    level =  loadState(MEM_LEVEL);
    if (level != 2 and level != 3) level1 = true;
    if (level == 2) {
        level2 = true;
        digitalWrite(RELAY_LEVEL2, RELAY_ON);
    }
    if (level == 3) {
        level3 = true;
        digitalWrite(RELAY_LEVEL3, RELAY_ON); 
    }
}

void setup() {
  send(MyMessage(MYSENSOR_POWER, S_BINARY).set(power==HIGH));
  send(MyMessage(MYSENSOR_LEVEL1, S_BINARY).set(level1==HIGH));
  send(MyMessage(MYSENSOR_LEVEL2, S_BINARY).set(level2==HIGH));
  send(MyMessage(MYSENSOR_LEVEL3, S_BINARY).set(level3==HIGH));
}

void presentation() {
  sendSketchInfo("Vento Switch", "0.3");
  present(MYSENSOR_POWER, S_BINARY);
  present(MYSENSOR_LEVEL1, S_BINARY);
  present(MYSENSOR_LEVEL2, S_BINARY);
  present(MYSENSOR_LEVEL3, S_BINARY);
}


void loop()
{

}

void receive(const MyMessage &message) {

  if (message.type == V_STATUS) {

    if (message.sensor == MYSENSOR_POWER) {
      power = message.getBool();
      digitalWrite(RELAY_POWER, power ? RELAY_ON : RELAY_OFF);
      send(MyMessage(message.sensor, S_BINARY).set(power==HIGH));
      saveState(MEM_POWER, power);
    }

    if (message.sensor == MYSENSOR_LEVEL1) {
      if (level2) {
        level2 = false;
        send(MyMessage(message.sensor, S_BINARY).set(level2==HIGH));
        digitalWrite(RELAY_LEVEL2, RELAY_OFF);
      }
      if (level3) {
        level3 = false;
        send(MyMessage(message.sensor, S_BINARY).set(level3==HIGH));
        digitalWrite(RELAY_LEVEL3, RELAY_OFF);
      }
      if (not level1) {
        level1 = true;
        send(MyMessage(message.sensor, S_BINARY).set(level1==HIGH));
      }
      if (level != LEVEL1) {
        level = LEVEL1;
        saveState(MEM_LEVEL, level);
      }
    }

   if (message.sensor == MYSENSOR_LEVEL2) {
      if (level1) {
        level1 = false;
        send(MyMessage(message.sensor, S_BINARY).set(level1==HIGH));
      }
      if (level3) {
        level3 = false;
        send(MyMessage(message.sensor, S_BINARY).set(level3==HIGH));
        digitalWrite(RELAY_LEVEL3, RELAY_OFF);
      }
      if (not level2) {
        level2 = true;
        digitalWrite(RELAY_LEVEL2, RELAY_ON);
        send(MyMessage(message.sensor, S_BINARY).set(level2==HIGH));
      }
      if (level != LEVEL2) {
        level = LEVEL2;
        saveState(MEM_LEVEL, level);
      }
    }

   if (message.sensor == MYSENSOR_LEVEL3) {
      if (level1) {
        level1 = false;
        send(MyMessage(message.sensor, S_BINARY).set(level1==HIGH));
      }
      if (level2) {
        level2 = false;
        send(MyMessage(message.sensor, S_BINARY).set(level2==HIGH));
        digitalWrite(RELAY_LEVEL2, RELAY_OFF);
      }
      if (not level3) {
        level3 = true;
        digitalWrite(RELAY_LEVEL3, RELAY_ON);
        send(MyMessage(message.sensor, S_BINARY).set(level3==HIGH));
      }
      if (level != LEVEL3) {
        level = LEVEL3;
        saveState(MEM_LEVEL, level);
      }
    }

    Serial.print("Incoming change for sensor:");
    Serial.print(message.sensor);
    Serial.print(", New status: ");
    Serial.println(message.getBool());
    
  }
}
