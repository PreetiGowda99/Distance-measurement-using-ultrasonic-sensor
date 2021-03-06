#include <LiquidCrystal.h>                //  includes the LiquidCrystal Library 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);    // interfacing pins of lcd

const int trigPin = A4;                  //  defines pin number
const int echoPin = A5;                  //  defines pin number 

long duration;                           //  defining the variable
int distanceCm, distanceInch;            //  defining the variable

void setup()
{
lcd.begin(16,2);                       // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);             // Setting the trigPin as output
pinMode(echoPin, INPUT);              // Setting the echoPin as input
}
void loop() 
{

digitalWrite(trigPin, LOW);         // turn off the trigpin
delayMicroseconds(2);               // wait for 2 microsecond
digitalWrite(trigPin, HIGH);        // turn on the trigpin
delayMicroseconds(10);              // wait for 10 microsecond
digitalWrite(trigPin, LOW);

//Reads the echopin, returns the sound wave travelling time in microseconds
duration = pulseIn(echoPin, HIGH);    // To receive the reflected signal


// calculating the distance
distanceCm= duration*0.034/2;         // calculating distance in cm
distanceInch = duration*0.0133/2;     // calculating distance in inch


// setting the cursor and printing the distance in lcd
lcd.setCursor(0,0);                  // Sets the cursor to column 0 and line 0
lcd.print("Distance: ");             // Prints string "Distance" on the LCD
lcd.print(distanceCm);               // Prints the distance value from the sensor
lcd.print(" cm");                    // Prints the distance in cm
delay(10);


// setting the cursor and printing the distance in lcd
lcd.setCursor(0,1);                // Sets the cursor to column 0 and line 1
lcd.print("Distance: ");           // Prints string "Distance" on the LCD
lcd.print(distanceInch);           // Prints the distance value from the sensor
lcd.print(" inch");                // Prints the distance in inches
delay(10);                        
}
