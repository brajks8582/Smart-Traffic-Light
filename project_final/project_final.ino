
#define c1 3
#define c2 2
#define c3 8
#define c4 9
#define ir1 4
#define ir2 5
#define ir3 6
#define ir4 7
int i,t=1,a,b,c,d,e,t1=0,t2=0,t3=0,t4=0,lr=1,ud=1;
void setup() {
  // put your setup code here, to run once:
     pinMode(c1,OUTPUT);
     pinMode(c2,OUTPUT);
     pinMode(c3,OUTPUT);
     pinMode(c4,OUTPUT);
     pinMode(ir1,INPUT);
     pinMode(ir2,INPUT);
     pinMode(ir3,INPUT);
     pinMode(ir4,INPUT);
     Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  a=digitalRead(ir1);
  b=digitalRead(ir2);
  c=digitalRead(ir3);
  d=digitalRead(ir4);
  if(Serial.available() >0)
  {
   // Serial.println("if condition excuted");
    char data;
    data=Serial.read();
   // Serial.println(data);
    switch(data)
    {
      case 'l' :
                  
                  digitalWrite(c1,LOW);
                  digitalWrite(c4,HIGH);
                  delay(2000);
                  digitalWrite(c2,HIGH);
                  digitalWrite(c3,LOW);
                 delay(8000);
                    t=0;
                   break;
       case 'r' :

                     
                    digitalWrite(c1,LOW);
                    digitalWrite(c4,HIGH);
                    delay(2000);
                    digitalWrite(c2,HIGH);
                    digitalWrite(c3,LOW);
                   delay(8000);
                     t=0;
                     break;

        case 'u' : 
                        
                      digitalWrite(c3,HIGH);        
                      digitalWrite(c2,LOW);
                      delay(2000);
                      digitalWrite(c1,HIGH);
                      digitalWrite(c4,LOW);
                      delay(8000);
                      t=0;
                      break;

         case 'd' :
                      
                        digitalWrite(c3,HIGH);        
                        digitalWrite(c2,LOW);
                        delay(2000);
                        digitalWrite(c1,HIGH);
                        digitalWrite(c4,LOW);
                        delay(8000);
                        t=0;
                        break;
                  
    }
  }

else{
  

    if(a==0)
     t1++;
    else
     t1=0;
   
   if(b==0)
     t2++;
    else
     t2=0;
    
    if(c==0)
      t3++;
    else
     t3=0;
     
    if(d==0)
     t4++;
    else
     t4=0;
    
    if(t1>6 || t2>6)
    {
     lr=1;
    }
     
       
    else
     {
        lr=0; 
      }
    
    if(t3>6 || t4>6)
     {
         ud=1;
      } 
    else
      {
        ud=0;
      }


       //main work starts here
       // ud=0 && ld=0 means no jam ,traffic light works according to its timer of 2 seconds
    if(lr==0 && ud==0){
    
          if(t<21)      //blinking time set as 10 seconds  2seconds red 8 sec green
  {
      
   
      digitalWrite(c3,HIGH);
      digitalWrite(c2,LOW); 
    if(t>4)
    {
    digitalWrite(c1,HIGH);
    digitalWrite(c4,LOW);  
    }
    
    
  }
  else
  {
    
      digitalWrite(c1,LOW);
    digitalWrite(c4,HIGH);
    if(t>24)
    {
    digitalWrite(c2,HIGH);
    digitalWrite(c3,LOW);  
    }
    
    
    if(t==40)
    {
      t=0;
    }
    
  }
  t++;
   
}

  //lr==1 means traffic in left_right road has exceed threshold value
  else if(lr==1)
  { 
    
    digitalWrite(c3,HIGH);        
    digitalWrite(c2,LOW);
    delay(2000);
    digitalWrite(c1,HIGH);
    digitalWrite(c4,LOW);
    delay(8000);
    t=0;
  }
 
  //ud==1 means traffic in up_down road has exceed threshold value
  else if(ud==1){
    
            
    digitalWrite(c1,LOW);
    digitalWrite(c4,HIGH);
    delay(2000);
    digitalWrite(c2,HIGH);
    digitalWrite(c3,LOW);
    delay(8000);
    t=0;
  }
  
        
     delay(500);
}
  int value;
  value=digitalRead(c1);
  if(value==HIGH)
  {
    Serial.println("Up-Down");
  }
  else 
  {
    Serial.println("Left-Right");
  }
}

