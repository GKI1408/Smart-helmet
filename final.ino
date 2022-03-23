const int MQ3 = A2;
 int relay = 8;
int value;
int count = 0;
void setup() {
  Serial.begin(9600);
  pinMode(MQ3,INPUT);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,LOW);
  // put your setup code here, to run once:

}

void loop() {
  while(count<10)
  {
    value = analogRead(MQ3);
    Serial.println(value);
    if(value>250)
    {
      digitalWrite(relay,HIGH);
     delay(5000);
      
      }
    else
    if(value<=250)
    {
        digitalWrite(relay,LOW);  
        }
        delay(2000);
        count=count+1;
   } 
  if(count>10)
  exit(0);
    }
