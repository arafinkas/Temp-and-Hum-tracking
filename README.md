# Temperature and Humidity tracking

## Short description
 Arduino+python project to track workspace temperature and humidity

 I noticed changes in temperature and humidity in my workspace
 across the day, so i decided to make a simple arduino project
 to keep an eye on it.

 Since I know how to code in Arduino, I started this project for 
 re-gaining knowledge in python, because I hadn't coded in python for 
 4 yeas.

 Additionaly, this will also allow me to start creating my own internet
 identity, and make easier for everyone to know what I am capable of doing.

## Motivations

At the place where I live right now, there is a high mean level of humidity. Temperature
also has a great gradient across the day, so there is some material to work as basis.
Additionaly, I own a 3D printer, which is extremely sensitive to these two parameters.
I noticed some of my prints have some visible warping after printed. I'm familiar with this
problem, but it was strange that it happened after printing, since it's usually found at bed-air temperature.
For this reason, I decided to track these two parameters, because warping depends mainly on temperature.

## Construction

This project relies on the DHT11 sensor. It is a temperature and humidity sensor that can be found 
in a lot of places online. It is easy to set up and can be done with a little knowledge of arduino.
I mounted this prototype with a breadboard and I added a lcd screen (both pieces usually come with 
basic arduino kits) to monitor it out of the computer.

## Software implementation

The project is divided in 3 parts:

-Arduino code
-Python script
-Data management

### Arduino code

As I already explained before, the arduino code obtains the sensor data and sends it through the
serial port, adding extra lines for lcd presentation. It is sended in a specific format (csv), in order 
to make it possible to use those data with several programs.

### Python script

This part of the software basically receives arduino data and writes it into a file. It adds some timestamps
for further management. This script can be upgraded in a lot of ways. I only coded in python in my first year
of my degree, and since then almost all the programming content was made in Matlab. This is my way to start knowing
again how to use this language.

### Data management

Something I learned in all these years studying engineering is that the most important part of a project
is to read into the data to find some meaning and make conclusions. In this case it can be done by analyzing
and plotting the data in some calc sheets and comparing the results to weather tracking. 

The results are not yet ready, but I will show them here once I have them ready.