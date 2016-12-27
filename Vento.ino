
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

bool power;
int level;
bool level1 = false;
bool level2 = false;
bool level3 = false;

#ifdef MY_DEBUG
void debug() {
  Serial.print("Power: ");
  Serial.print(power);
  Serial.print(", Level: ");
  Serial.print(level);
  Serial.print(", Level1: ");
  Serial.print(level1);
  Serial.print(", Level2: ");
  Serial.print(level2);
  Serial.print(", Level3: ");
  Serial.println(level3);
}
#endif

void before() { 
    // Load power state and set relay
    power =  loadState(MEM_POWER);
    pinMode(RELAY_POWER, OUTPUT);
    digitalWrite(RELAY_POWER, power ? RELAY_ON : RELAY_OFF);

    // Disable Level1 & Level2
    pinMode(RELAY_LEVEL2, OUTPUT);
    digitalWrite(RELAY_LEVEL2, RELAY_OFF);
    pinMode(RELAY_LEVEL3, OUTPUT);
    digitalWrite(RELAY_LEVEL3, RELAY_OFF);

    // Load levels and set relay if power
    level =  loadState(MEM_LEVEL);
    if (level != LEVEL2 and level != LEVEL3) {
      level1 = true;
      level = LEVEL1;
    }
    if (level == LEVEL2) {
        level2 = true;
        if (power) digitalWrite(RELAY_LEVEL2, RELAY_ON);
    }
    if (level == LEVEL3) {
        level3 = true;
        if (power) digitalWrite(RELAY_LEVEL3, RELAY_ON); 
    }
    #ifdef MY_DEBUG
    debug();
    #endif
}

void sendlevel(int level,bool state) {
  send(MyMessage(level, S_BINARY).set(state==HIGH));
  #ifdef MY_DEBUG
  Serial.print("Sending: Sensor: ");
  Serial.print(level);  
  Serial.print(", state: ");
  Serial.println(state);  
  #endif
}

void sendpower() {
  send(MyMessage(MYSENSOR_POWER, S_BINARY).set(power==HIGH));
}

void setup() {
  sendlevel(MYSENSOR_LEVEL1,level1);
  sendlevel(MYSENSOR_LEVEL2,level2);
  sendlevel(MYSENSOR_LEVEL3,level3);
  sendpower();
}

void presentation() {
  sendSketchInfo("Vento Switch", "0.3");
  present(MYSENSOR_POWER, S_BINARY);
  present(MYSENSOR_LEVEL1, S_BINARY);
  present(MYSENSOR_LEVEL2, S_BINARY);
  present(MYSENSOR_LEVEL3, S_BINARY);
}

void loop() {
}

void receive(const MyMessage &message) {

  if (message.type == V_STATUS) {

    if (message.sensor == MYSENSOR_POWER) {

      // Switch power
      power = message.getBool();
      digitalWrite(RELAY_POWER, power ? RELAY_ON : RELAY_OFF);
      sendpower();
      saveState(MEM_POWER, power);

      // ...
      if (power) {
        if (level2) digitalWrite(RELAY_LEVEL2, RELAY_ON);
        if (level3) digitalWrite(RELAY_LEVEL3, RELAY_ON);
      } else {
        if (level2) digitalWrite(RELAY_LEVEL2, RELAY_OFF);
        if (level3) digitalWrite(RELAY_LEVEL3, RELAY_OFF);        
      }
    }

    if (message.sensor == MYSENSOR_LEVEL1) {
      debug();
      if (level2) {
        level2 = false;
        sendlevel(MYSENSOR_LEVEL2,level2);
        if (power) digitalWrite(RELAY_LEVEL2, RELAY_OFF);
      }
      if (level3) {
        level3 = false;
        sendlevel(MYSENSOR_LEVEL3,level3);
        if (power) digitalWrite(RELAY_LEVEL3, RELAY_OFF);
      }
      if (not level1) {
        level1 = true;
        sendlevel(message.sensor,level1);
      }
      if (level != LEVEL1) {
        level = LEVEL1;
        saveState(MEM_LEVEL, level);
      }
    }

    if (message.sensor == MYSENSOR_LEVEL2) {
      debug();
      if (level1) {
        level1 = false;
        sendlevel(MYSENSOR_LEVEL1,level1);
      }
      if (level3) {
        level3 = false;
        sendlevel(MYSENSOR_LEVEL3,level3);
        if (power) digitalWrite(RELAY_LEVEL3, RELAY_OFF);
      }
      if (not level2) {
        level2 = true;
        sendlevel(message.sensor,level2);
        if (power) digitalWrite(RELAY_LEVEL2, RELAY_ON);
      }
      if (level != LEVEL2) {
        level = LEVEL2;
        saveState(MEM_LEVEL, level);
      }
    }

    if (message.sensor == MYSENSOR_LEVEL3) {
      debug();
      if (level1) {
        level1 = false;
        sendlevel(MYSENSOR_LEVEL1,level1);
      }
      if (level2) {
        level2 = false;
        sendlevel(MYSENSOR_LEVEL2,level2);
        if (power) digitalWrite(RELAY_LEVEL2, RELAY_OFF);
      }
      if (not level3) {
        level3 = true;
        sendlevel(message.sensor,level3);
        if (power) digitalWrite(RELAY_LEVEL3, RELAY_ON);
      }
      if (level != LEVEL3) {
        level = LEVEL3;
        saveState(MEM_LEVEL, level);
      }
    }

    #ifdef MY_DEBUG
    Serial.print("Incoming change for sensor:");
    Serial.print(message.sensor);
    Serial.print(", New status: ");
    debug();
    #endif 
  }
}
