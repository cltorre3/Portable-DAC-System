void onRelaysChange()  
{
  // Add your code here to act upon Relays change
  if(digitalRead(Wifi_switch) == HIGH)
  {
    digitalWrite(Wifi_LED, HIGH);
    if(relays)
    {
      digitalWrite(Relay_1, HIGH); // Activate Relay1
      digitalWrite(Relay_2, HIGH); // Activate Relay2
      delay(1000);
    }
    else
    {
      digitalWrite(Relay_1, LOW); // Deactivate Relay1
      digitalWrite(Relay_2, LOW); // Deactivate Relay2
      delay(1000);
    }
  }
  if(digitalRead(Wifi_switch) == LOW)
  {
    digitalWrite(Wifi_LED, LOW);
    if(digitalRead(Relay_switch) == HIGH)
    {
      digitalWrite(Relay_1, HIGH); // Activate Relay1
      digitalWrite(Relay_2, HIGH); // Activate Relay2
      delay(1000);
    }
    else
    {
      digitalWrite(Relay_1, LOW); // Deactivate Relay1
      digitalWrite(Relay_2, LOW); // Deactivate Relay2
      delay(1000);
    }
  }
    
}
