int ch1;
int ch2;
int Throttle;
int Steering;
void setup()
{
	pinMode(11,OUTPUT); // Motor A EN
	pinMode(12,OUTPUT); // Motor B EN
	pinMode(5,OUTPUT); // B REV
	pinMode(4,OUTPUT); // B FOR
	pinMode(3,OUTPUT); // A REV
	pinMode(2,OUTPUT); // A FOR
	pinMode(6,INPUT); // CH1
	pinMode(7,INPUT); // CH2

	Serial.begin(9600);
  

}

void loop()
{
	ch1 = pulseIn(6, HIGH, 300000);
	ch2 = pulseIn(7,HIGH,300000);

	if (ch2 > 1530){
		digitalWrite(2,HIGH);
		digitalWrite(3,LOW);
			Throttle = map(ch2,1530,2000,0,255);
			if (Throttle > 255){
				Throttle = 255;
			}
			
			Serial.println(Throttle);
			analogWrite(11,Throttle);
	} 
	if(ch2 < 1470){
		digitalWrite(2,LOW);
		digitalWrite(3,HIGH);
			Throttle = map(ch2,950,1470,255,0);
			if (Throttle > 255){
				Throttle = 255;
			}
			Serial.println(Throttle);

			analogWrite(11,Throttle);
			
	
	}
	
	
	if(ch2 > 1470 && ch2 < 1530){
		digitalWrite(11,LOW);
	}
	
	Serial.println(ch2);
  

}
