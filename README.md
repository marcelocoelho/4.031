# 4.031

# Interactive Clock

Step-by-step electronics for interactive clock project.

## How This Works

Each of the code examples in this repository will help you get a different electronic compoent to work. If you follow them from beginning to end you will end up with a work-like prototype and a great platform to create your own interactive clock.

## 0. Download Repo

Start by downloading this repository and save it to a local drive. If you know how to use Git you can clone it, if not, you can just download the files. Git is a great tool for writing software, keeping tracking of different versions and collaborating with others. If you haven't used it before, the desktop app is a great way to get started: https://desktop.github.com/

## 1. Download Arduino IDE

Arduino is the microcontroller platform you will use to create your clock. You can download the Arduino IDE here: https://www.arduino.cc/en/Main/Software which is where you will write your software, compile it, and flash it into the Arduino. If you've never used an Arduino before, this page has all the info you need to get started: https://www.arduino.cc/en/Tutorial/HomePage

## 2. Program Arduino

We are using Arduino Uno. Plug your Arduino into your computer and you should see a small blinking LED. If you don't, it could be because your Arduino is not properly connected to your computer or your computer might be having some driver issues recognizing the board.

Now let's make sure you can program your board.

Firs you need tell the Arduino IDE what port your board is connected to and make sure you've selected the right board. On my computer it looks like this:

![port](https://github.com/marcelocoelho/4.031/blob/main/images/board.png)
![board](https://github.com/marcelocoelho/4.031/blob/main/images/port.png)

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

A 'roadkill' is a flattened circuit board, designed this way so that you only need to worry about your electronics, and not the form-factor of your object. In product design, this lets electrical engineers and firmware developers start their work, while mechanical and industrial designers are still figuring out ethe form-factor and look of an object.

At this early prototyping phase, I use a small piece of wood or cardboard and protoboards to create a 'roadkill'. Once I know that everything works as intended I start migrating my circuit design to its final custom PCB form-factor.

![roadkill](https://github.com/marcelocoelho/4.031/blob/main/images/roadkill.jpg)

## 4. Add a Breadboard

Add a breadboard to your 'roadkill' so you can add a button and LED to your prototype. Bring 5V and GND to the breadboard rails.

If you haven't used a breadboard before, there is a great tutorial from Sparkfun here: https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard/all

![roadkill](https://github.com/marcelocoelho/4.031/blob/main/images/breadboard.jpg)

## 5. Add an External LED

Add an LED to breadboard with a 330 Ohm resistor and connect it to Pin X on the Arduino.

Now go back to the Blink sketch you used earlier and change LED_BUILTIN to 2. This change the Arduino pin you are controlling from pin 13 to pin 2, which is where your external LED is connected.

![led](https://github.com/marcelocoelho/4.031/blob/main/images/led.jpg)

For more information, check out: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink

## 6. Add a Button

## 7. Debug Using the Serial Port

## 8. Add a Knob

## 10. Add Servo

## 11. Add a Buzzer

## 11. Add Stepper

## 12. Add LED Strip

## 13. Create Your Own Timer

Now that you have all of these components working, try to build an interactive clock or timer.

- How does someone set the time?
- Does it count up or down?
- How does someone know when the time has elapsed?
- What is the best form of input and output for your type of clock and how it is used?
