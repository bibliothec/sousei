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
 * AUTHOR   : rune
 *
 *******************************************************************************/

 #include "CytronMotorDriver.h"

// Configure the motor driver.
CytronMD motor1(PWM_DIR, 3, 4);  // PWM 1 = Pin 3, DIR 1 = Pin 4.
CytronMD motor2(PWM_DIR, 9, 10); // PWM 2 = Pin 9, DIR 2 = Pin 10.

 int interval=0;
 int switch_socket=10;
 int motor_speed=32;

// The setup routine runs once when you press reset.
void setup() {
  pinMode(switch_socket,INPUT);
}


// The loop routine runs over and over again forever.
void loop() {
  if(digitalRead(switch_socket)==1){
    motor1.setSpeed(motor_speed);    
    motor2.setSpeed(motor_speed);    
  }else if(digitalRead(switch_socket)==0){
    motor1.setSpeed(motor_speed*-1);    
    motor2.setSpeed(motor_speed*-1);  
  }
}
