#define POTENTIOMETER_PIN A0
float temp;
int tempPin=0;
int led = 11;                
int sensor = 2;              
int state = LOW;             
int val = 0;  
void setup() 
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(led, OUTPUT);   
  pinMode(sensor, INPUT);    
}
void loop()
{
  temp = analogRead(tempPin);
  temp = temp*0.488;
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.print("*C");
  Serial.println();
  if(temp>100)
  {
    digitalWrite(12,HIGH);
  }
  else
 	digitalWrite(12,LOW);
  int a = analogRead(POTENTIOMETER_PIN);
  if(a>500)
  {
    digitalWrite(13,HIGH);
  }
  else
    digitalWrite(13,LOW);
  
  Serial.print("Potentiometer = ");
  Serial.println(analogRead(POTENTIOMETER_PIN));
  
    val = digitalRead(sensor);   
  if (val == HIGH) {           
    digitalWrite(led, HIGH);   
    delay(500);                
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       
    }
  } 
  else {
      digitalWrite(led, LOW); 
      delay(500);             
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       
    }
  }

  delay(100);
}