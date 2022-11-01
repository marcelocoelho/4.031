# 4.031 - Interactive Clock - ***2022 version***

Step-by-step electronics for interactive clock project.

## How This Works

Each of the code examples in this repository will help you get a different electronic component to work. If you follow them from beginning to end you will end up with a work-like prototype and a great platform to create your own interactive clock.

## 0. Download Repo

Start by downloading this repository and save it to a local drive. If you know how to use Git you can clone it, if not, you can just download the files. Git is a great tool for writing software, keeping tracking of different versions and collaborating with others. If you haven't used it before, the desktop app is a great way to get started: https://desktop.github.com/

## 1. Download Arduino IDE

Arduino is the microcontroller platform you will use to create your clock. You can download the Arduino IDE here: https://www.arduino.cc/en/software which is where you will write your software, compile it, and flash it into the Arduino. If you've never used an Arduino before, this page has all the info you need to get started: https://docs.arduino.cc/tutorials/

## 2. Program Arduino

We are using Arduino Nano. Plug your Arduino into your computer and you should see two small LEDs turn on. The one always on tells you the board is powered, while the blinking one tells you the default software is running.  If you don't the LEDs turn on, it could be because your Arduino is not properly connected to your computer or your computer might be having a driver issue recognizing the board.

Now let's make sure you can program your board.

First you need tell the Arduino IDE what port your board is connected to and make sure you've selected the right board. On my computer it looks like this:

![port](https://github.com/marcelocoelho/4.031/blob/main/images/port.png)
![board](https://github.com/marcelocoelho/4.031/blob/main/images/board.png)

Go to File > Examples > 01.Basics > Blink. This will open a sketch that makes the LED blink.

Click the Upload arrow. And you should get a **Done Uploading** message.

Your LED should continue blinking as before. Now, try changing the delay time to 100 ms, reprogram and see if it blinks faster:

```java
digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
delay(100); // wait for a second
digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
delay(100); // wait for a second
```

## 3. Start Building your 'Roadkill'

A 'roadkill' is a flattened circuit board, designed this way so that you only need to worry about your electronics, and not the form-factor of your object. In product design, this lets electrical engineers and firmware developers do their work, while mechanical and industrial designers are still figuring out the form-factor and look of an object.

At this early prototyping phase, I use a small piece of wood or cardboard, and protoboards to create a 'roadkill'. Once I know that everything works as intended I start migrating my circuit design to its final custom PCB form-factor.

![roadkill](https://github.com/marcelocoelho/4.031/blob/main/images/roadkill.jpg)

If you are using an Arduino Nano, check out this video on how to solder header pins and attach your Nano to a breadboard:
[Soldering Nano](https://www.youtube.com/watch?v=wDbUChzxIrE&ab_channel=CodeandMake)

***IMPORTANT: Before soldering or wiring components to your Arduino, make sure you disconnect it from power to prevent shortcuts.***


## 4. Add a Breadboard

Add your Arduino and breadboard to your 'roadkill' so you can add a button and LED to your prototype. Bring 5V and GND to the breadboard rails. If you are using an Arduino Nano, you should connect your Arduino to the breadboard and attach the breadboard to the roadkill panel.

If you haven't used a breadboard before, there is a great tutorial from Sparkfun here: [How to Use a Breadboard](https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard/all)

![roadkill](https://github.com/marcelocoelho/4.031/blob/main/images/breadboard.jpg)

## 5. Add an External LED

Add an LED to breadboard with a 330 Ohm resistor and connect it to Pin D2 on the Arduino.

Now go back to the Blink sketch you used earlier and change LED_BUILTIN to 2. This changes the Arduino pin you are controlling from pin 13 to pin 2, which is where your external LED is connected.

For more information, check out: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink

![led](https://github.com/marcelocoelho/4.031/blob/main/images/led.jpg)


![arduinoled](https://github.com/marcelocoelho/4.031/blob/main/images/arduinoled.png)

## 6. Add a Button

Follow this example to add a button and control the external LED. Make sure that you change pin numbers to reflect the pins you are connecting things to: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button

![button](https://github.com/marcelocoelho/4.031/blob/main/images/button.jpg)

![arduinobutton](https://github.com/marcelocoelho/4.031/blob/main/images/arduinobutton.png)

## 7. Debug Using the Serial Port

One of the most difficult things about electronics, specially when you are starting, is to debug your circuits when things are not working. Being able to output variable values and states to the serial port is an easy way to get a better insight of what is going on. Look at this example to learn how to output different data types to serial monitor.

https://www.arduino.cc/en/Tutorial/BuiltInExamples/ASCIITable

## 8. Add a Rotary Encoder

Use the example included wih the Github repo. This example also requires a library that you will need to install by going to Tools > Manage Libraries and search for rotaryencoder.

![rotaryencoder](https://github.com/marcelocoelho/4.031/blob/main/A_RotaryEncoderModule/rotaryencoderlibrary.png)

CLK and DT are the pins on the rotary encoder that you need to connect to Arduino to detect rotation.
SW works like a regular button if you press down the rotary encoder. Code is not included in the example for the switch but it's similar to the button sketch above.

This video has a good explanation of how the encoder works if you are curious:
https://www.youtube.com/watch?v=v4BbSzJ-hz4&ab_channel=HowToMechatronics

## 9. Add LED Strip

Use the example included in the Github repo. This example also requires a library that you will need to install by going to Tools > Manage Libraries and search for FastLED.

You will need to solder wires to the end of your LED strip to be able to power and control it. Make sure to solder your wires to CI and DI end of the strip (I means input), and not to CO and DO (O means output).

GND and 5V connect to ground and power.
CI and DI mean clock in and data in and can connect to any digital pin.
In the repo example, we use pins 4 and 5. If you mix them up your LED strip will not work. Double check them if you are having problems.

You also need to be careful to not connect too many LEDs to your Arduino. They will draw too much current. Keep it to 4-5 LEDs for this prototype.

![ledstrip](https://github.com/marcelocoelho/4.031/blob/main/images/ledstrip.jpg)

## 10. Stepper Motor

Use the example included in the Github repo. This example also requires a library that you will need to install by going to Tools > Manage Libraries and search for AccelStepper.

For the stepper to work, you will need to connect it to the driver board and connect the driver board to the Arduino. Pins IN1-IN4 on driver board correspond to pins 8-11 on the Arduino. Also, you will need to connect the + and - on the driver board to 5V and GND on the Arduino

If you attach a small piece of tape to the motor shaft, it becomes easier to see it move, specially when the movement steps are very small.

## 11. Add Servo

***Correction: servo not included in your kit, but we have some if you want to use them in your final project.***

Use the example included in the Github repo.

This example is written so that the servo moves one step, waits 15 ms, and then moves another step. This ensures that a step is complete before the next one, but also that the delay does not lock your Arduino and prevent others things from happening, such as sensor readings, LED controls, etc.

https://www.arduino.cc/reference/en/libraries/servo/

## 12. Add a Buzzer

***Correction: buzzer not included in your kit, but we have some if you want to use them in your final project.***

More info coming soon, but for now you can try this:
https://create.arduino.cc/projecthub/SURYATEJA/use-a-buzzer-module-piezo-speaker-using-arduino-uno-89df45

## 13. Create Your Own Timer

Now that you have all of these components working, try to build an interactive clock or timer.

- How does someone set the time?
- Does it count up or down?
- How does someone know when the time has elapsed?
- What is the best form of input and output for your type of clock and how it is used?
