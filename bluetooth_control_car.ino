char t;
 
void setup() {
pinMode(9,OUTPUT);   //left motors forward
pinMode(8,OUTPUT);   //left motors reverse
pinMode(7,OUTPUT);   //right motors forward
pinMode(6,OUTPUT);   //right motors reverse 
Serial.begin(9600); 
}
 
void loop() {
  if(Serial.available()){
    t = Serial.read();
    Serial.println(t);
  }
 
  if(t == '1'){            //move forward(all motors rotate in forward direction)
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
  }
 
  else if(t == '2'){      //move reverse (all motors rotate in reverse direction)
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(6,HIGH);
  }
 
  else if(t == '3'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
  }
 
  else if(t == '4'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
  }
 
  else if(t == '5'){      //STOP (all motors stop)
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
  }
  delay(100);
}
