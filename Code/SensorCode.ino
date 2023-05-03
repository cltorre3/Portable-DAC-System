#include <LiquidCrystal.h>
#include <SoftwareSerial.h>                           //we have to include the SoftwareSerial library, or else we can't use it
#define rx 16                                          //define what pin rx is going to be
#define tx 17                                          //define what pin tx is going to be

 
// Create An LCD Object. Signals: [ RS, EN, D4, D5, D6, D7 ]
LiquidCrystal My_LCD(21, 12, 26, 25, 33, 32);
SoftwareSerial myserial(rx, tx);                      //define how the soft serial port is going to work

String inputstring = "";                              //a string to hold incoming data from the PC
String sensorstring = "";                             //a string to hold the data from the Atlas Scientific product
boolean input_string_complete = false;                //have we received all the data from the PC
boolean sensor_string_complete = false;               //have we received all the data from the Atlas Scientific product
int Co2;  

void setup()
{
   Serial.begin(9600);                                 //set baud rate for the hardware serial port_0 to 9600
  myserial.begin(9600);                               //set baud rate for the software serial port to 9600
  inputstring.reserve(10);                            //set aside some bytes for receiving data from the PC
  sensorstring.reserve(30);
  // Initialize The LCD. Parameters: [ Columns, Rows ]
  My_LCD.begin(16, 2);
  // Clears The LCD Display
  My_LCD.clear();
 
  
}

 void serialEvent() {                                  //if the hardware serial port_0 receives a char
  inputstring = Serial.readStringUntil(13);           //read the string until we see a <CR>
  input_string_complete = true;   //set the flag used to tell if we have received a completed string from the 
 }
  
void loop()
{
  My_LCD.setCursor(0, 1);
  My_LCD.print("PPM");
  My_LCD.setCursor(6, 1);
   My_LCD.print("STATE CNCE");
  if (input_string_complete == true) {                //if a string from the PC has been received in its entirety
    myserial.print(inputstring);                      //send that string to the Atlas Scientific product
    myserial.print('\r');                             //add a <CR> to the end of the string
    inputstring = "";                                 //clear the string
    input_string_complete = false;                    //reset the flag used to tell if we have received a completed string from the PC
  }

  if (myserial.available() > 0) {                     //if we see that the Atlas Scientific product has sent a character
    char inchar = (char)myserial.read();              //get the char we just received
    sensorstring += inchar;                           //add the char to the var called sensorstring
    if (inchar == '\r') {                             //if the incoming character is a <CR>
      sensor_string_complete = true;                  //set the flag
    }
  }


  if (sensor_string_complete == true) {               //if a string from the Atlas Scientific product has been received in its entirety
    Serial.println(sensorstring);                     //send that string to the PC's serial monitor
    My_LCD.setCursor(0, 0);
    My_LCD.print(sensorstring);
    My_LCD.setCursor(6, 0);
    My_LCD.print("ARIZONA");
                                                    //uncomment this section to see how to convert the Co2 readings from a string to an  integer 
    if (isdigit(sensorstring[0])) {                   //if the first character in the string is a digit
      Co2 = sensorstring.toInt();                     //convert the string to a integer so it can be evaluated by the Arduino
      if (Co2 >= 400) {                               //if the Co2 is greater than or equal to 400
        Serial.println("high");                       //print "high" this is demonstrating that the Arduino is evaluating the Co2 as a number and not as a string
      }
      if (Co2 <= 399) {                               //if the Co2 is less than or equal to 399
        Serial.println("low");                        //print "low" this is demonstrating that the Arduino is evaluating the Co2 as a number and not as a string
      }
    }
    
    sensorstring = "";                                //clear the string
    sensor_string_complete = false;                   //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
  }
}


