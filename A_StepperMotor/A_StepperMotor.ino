// ********************************************************************
//
// Don't forget to install the AccelStepper library for this example to work
// Library documentation here: https://www.airspayce.com/mikem/arduino/AccelStepper/
// Function reference here: https://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html#adfb19e3cd2a028a1fe78131787604fd1
// Video that explains how the stepper works: https://www.youtube.com/watch?v=avrdDZD7qEQ&ab_channel=NikodemBartnik
//
// ********************************************************************


#include <AccelStepper.h>
#define STEP 4  // 4 for full step, 8 for half step, explanation here: https://www.motioncontrolonline.org/content-detail.cfm/Motion-Control-Application-Case-Studies/What-is-the-difference-between-full-stepping-the-half-stepping-and-the-micro-drive/content_id/3192

// Motor pin definitions
#define motorPin1  8     // IN1 on the ULN2003 driver 1
#define motorPin2  9     // IN2 on the ULN2003 driver 1
#define motorPin3  10     // IN3 on the ULN2003 driver 1
#define motorPin4  11     // IN4 on the ULN2003 driver 1

AccelStepper stepper1(STEP, motorPin1, motorPin3, motorPin2, motorPin4);


//////////////////////////////////////////////////////////////////
/// Use these  if you want to move a specific number of steps
//  This example moves a full rotation clockwise and then a full rotation counter-clockwise. Repeats.

int position = 2048; // this is the number of steps of a full rotation

void setup()
{  

  Serial.begin(9600);
  
   stepper1.setMaxSpeed(600);       // Sets the maximum permitted speed.  If your motors starts behaving erratically, lower this number. 600 seemed to be the limit for me.
   stepper1.setAcceleration(200.0); // Ramp up and ramp down. 
   stepper1.moveTo(position);
   stepper1.setSpeed(400);         // Sets the speed. Positive numbers rotate clockwise. Negative numbers rotate counter-clockwise.

}

void loop()
{  
   stepper1.run();
   Serial.println(stepper1.currentPosition());

   // Flip rotation direction once done
   if (stepper1.currentPosition() == position) {
    stepper1.moveTo(0);
   }
   // Then flip again
   if (stepper1.currentPosition() == 0) {
    stepper1.moveTo(position);
   }
}



/*
//////////////////////////////////////////////////////////////////
/// Use these instead if you are just looking for a constant speed motion

void setup()
{  
   stepper1.setMaxSpeed(600);       // Sets the maximum permitted speed.  If your motors starts behaving erratically, lower this number. 600 seemed to be the limit for me.
   stepper1.setSpeed(400);          // Sets the speed. Positive numbers rotate clockwise. Negative numbers rotate counter-clockwise.
}

void loop()
{  
   stepper1.runSpeed();
}
*/
