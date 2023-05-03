// Code for Relay ESP32
// ESP32 Should have "RLY" on the top shell
// CODE IS USED FOR PHYSICAL SWITCH WITH NO WIFI. 
#define Relay_1 19 // Pin 19 for Relay 1
#define Relay_2 21 // Pin 21 for Reelay 2
#define Wifi_switch 27 // Pin 27 for the Wifi Switch activation
#define Relay_switch 26 // Pin 26 for the Relay switch activation
#define Wifi_LED 33 // Pin 33 for LED notification

void setup()
{
  pinMode(Relay_2, OUTPUT); // Set up both Relay pin as an output
  pinMode(Relay_1, OUTPUT); // Set up Relya pin for output
  pinMode(Wifi_switch, INPUT); // Set up Wifi switch for input read 
  pinMode(Relay_switch, INPUT); // Set up Relay switch for input read
  pinMode(Wifi_LED, OUTPUT); // Set up Wi-fi led to activate to notify if wifi is being used
}

void loop() 
{

  if (digitalRead(Relay_switch) == HIGH) // check the relay switch for high signal from 
    {
      delay(1500);
      digitalWrite(Relay_1, HIGH); // Activate Relay1
      digitalWrite(Relay_2, HIGH); // Activate Relay2
       

      
    }
    else //if the switch is low
    {
      digitalWrite(Relay_1, LOW); // Deactivate Relay1
      digitalWrite(Relay_2, LOW); // Deactivate Relay2
      delay(1500); 
    }
  
  if (digitalRead(Wifi_switch) == HIGH) // Implement with IOT system to indicate Wifi status
    {
      digitalWrite(Wifi_LED, LOW);
    }
  else
    {
      digitalWrite(Wifi_LED, HIGH);
    }
} 