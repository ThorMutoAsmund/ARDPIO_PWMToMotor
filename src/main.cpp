#include <Arduino.h>


int aout1_pin = 6;
int pot_pin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(aout1_pin, OUTPUT);
  pinMode(pot_pin, INPUT);
}

int output;
int motor_value;

void pot_controls_motor();
void motor_up_down();

void loop() {
    pot_controls_motor();
}

// Fades a motor up and down
void motor_up_down() {
  for (int i=0; i<255; i++){
    analogWrite(aout1_pin, i);
    delay(5);
  }
  for (int i=255; i>0; i--){
    analogWrite(aout1_pin, i);
    delay(5);
  }
}

// Motor speed is controlled by a potmeter
void pot_controls_motor() {
    output = analogRead(pot_pin);
    motor_value = map(output, 0, 1023, 60, 255);
    if (motor_value == 60)
        motor_value = 0;
    analogWrite(aout1_pin, motor_value);    
    delay(1);
}