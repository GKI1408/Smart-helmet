#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

WiFiClient client;

long myChannelNumber = 173836;
const char myWriteAPIKey[] = "CNEX8Z9DX8YC3SPN";
//const int IRSensor = D4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(D4,INPUT);
  
  WiFi.begin("Saurav 2", "12345678");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());

//  dht.begin();
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  int statusSensor = digitalRead(D4);

if(statusSensor == 1) {
     ThingSpeak.writeField(myChannelNumber, 1, statusSensor, myWriteAPIKey);
  }
  else {
    
    }


  delay(5000);
}
