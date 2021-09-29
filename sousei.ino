/*******************************************************************************
 * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTY AND SUPPORT
 * IS APPLICABLE TO THIS SOFTWARE IN ANY FORM. CYTRON TECHNOLOGIES SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR CONSEQUENTIAL
 * DAMAGES, FOR ANY REASON WHATSOEVER.
 ********************************************************************************
 * DESCRIPTION:
 *
 * This example shows how to drive 2 motors using the PWM and DIR pins with
 * 2-channel motor driver.
 * 
 * 
 * CONNECTIONS:
 * 
 * Arduino D3  - Motor Driver PWM 1 Input
 * Arduino D4  - Motor Driver DIR 1 Input
 * Arduino D9  - Motor Driver PWM 2 Input
 * Arduino D10 - Motor Driver DIR 2 Input
 * Arduino GND - Motor Driver GND
 *
 *
 * AUTHOR   : bibliothec
 *
 *******************************************************************************/

 #include "CytronMotorDriver.h"

// Configure the motor driver.
CytronMD motor1(PWM_DIR, 3, 4);  // PWM 1 = Pin 3, DIR 1 = Pin 4.
CytronMD motor2(PWM_DIR, 9, 10); // PWM 2 = Pin 9, DIR 2 = Pin 10.

 int interval=100;  // for chattering prevention
 int switch_socket=10; 
 int volume_socket=0;
 float default_motor_speed=32.0;

// The setup routine runs once when you press reset.
void setup() {
  Serial.begin(9600);
  pinMode(switch_socket,INPUT_PULLUP);
}


// The loop routine runs over and over again forever.
void loop() {
  int analog_val;
  float input_volt,motor_speed;

  analog_val=analogRead(volume_socket);
  input_volt=float(analog_val)*(5.0/1023.0); 
  
  motor_speed=default_motor_speed*input_volt;   //write motor speed formula

  Serial.print(analog_val);
  Serial.print(" : ");
  Serial.print(input_volt);
  Serial.print(" V ");
  Serial.print("motorspeed : ");
  Serial.println(motor_speed);
    
  if(digitalRead(switch_socket)==1){
    delay(interval);
    motor1.setSpeed(motor_speed);    
    motor2.setSpeed(motor_speed);    
  }else if(digitalRead(switch_socket)==0){
    delay(interval);
    motor1.setSpeed(motor_speed*-1);    
    motor2.setSpeed(motor_speed*-1);  
  }
}
