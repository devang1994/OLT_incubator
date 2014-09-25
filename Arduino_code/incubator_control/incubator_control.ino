#include "DHT.h"
#define DHTTYPE DHT22
#define DHTPIN 2
DHT dht(DHTPIN, DHTTYPE);
#define hPin 12
#define cPin 13
#define MARGIN 0.3

//takes in a temperature and tries to maintain it in the box

//tested by Devang 0n 23/9/14  comments works but as 
//is to be expected from such a control system, it overshoots a lot
//in current design PID is hard to do as relays are not good
//at handling pwm and would blow , trying to develop a more effective contol strategy
float set_temp=25;

void setup()
{
  Serial.begin(9600);
  pinMode(hPin,OUTPUT);
  pinMode(cPin,OUTPUT);
  dht.begin();
  Serial.println("enter temperature. enter 999 to nap ");
}

void loop()
{
  float t = dht.readTemperature();
  int b1=Serial.parseInt();
  if (Serial.read() == '\n') 
  {
    Serial.print("Trying to control temperature at :");
    Serial.println(b1);
    set_temp=b1;
  }
  
  
  
  if (isnan(t)) 
  {
    Serial.println("Failed to read from DHT sensor!");
  }
  else if(set_temp==999)
  {
    Serial.println("going for a nap");
    digitalWrite(hPin, LOW);
    digitalWrite(cPin, LOW);
  }
  else if (t<set_temp)
  {
    Serial.println("Heating");
    digitalWrite(hPin, HIGH);
    digitalWrite(cPin, LOW);
  }
  else if(t>set_temp)
  {
    Serial.println("Cooling");      
    digitalWrite(hPin, LOW);
    digitalWrite(cPin, HIGH);
  }  
  
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.println(" *C "); 
  delay(3000);

}

