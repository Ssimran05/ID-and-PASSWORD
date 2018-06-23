//program to enter an id and password and verfiy it every time we enter::

#define led1 2  //defining the led and buzzer
#define led2 3
#define buzzer 4

String SSID, PASS;

void setup() {       // Enter the  code here, to run once:  
  Serial.begin(9600);   //to begin comminucation with serial monitor
  SSID=id();            //Calling the id function  
  PASS=pw();            //Calling the password function
  pinMode(2,OUTPUT);    //setting the led and buzzer as OUTPUT  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);

}



String id()    //function for id
{
  Serial.print("Enter SSID\n");
  check:
  char ch=Serial.read();
  if(ch=='*')
  {
    String str=Serial.readString();
    Serial.print("Your ID - ");
    Serial.print(str);
    Serial.print("\n");
    return str;
  }
  else {
    goto check;
  }
}
String pw(){     //function for password
  Serial.print("Enter password");
  Serial.print("\n");
  check:
  char ch= Serial.read();
  if(ch=='*')
  {
    String str=Serial.readString();
    Serial.print("YOUR PASSWORD - ");
    Serial.println(str);
    Serial.println("Enter id to login");
    return str;
  }
  else
  goto check;
}

void loop() {     // Enter the code to be run many times
  String str, a;
  {
  if(Serial.available())    //to make data available in serial monitor:
  {
    str=Serial.readString();    //store the data in String str:
    Serial.print(str);          //print the data:
    Serial.print("\n");
    if(str==SSID)           //if the data available matches with the ID
    {
      Serial.println("Now enter password to unlock ");    //then enter the password
      //delay(3000);
     
   {
   a=Serial.readString();      
   Serial.print(a);
   Serial.print("\n");
   delay(5000);
   {
    if(a==PASS)     //if password matches then welcome in & green led is on::
    {
      Serial.println("WELCOME IN!");
      digitalWrite(2, HIGH);
      //delay(1000);
      digitalWrite(3, LOW);
      }
   else if(a!=PASS)   //if password does not match then retry, red led is on and buzzer sounds::
        {
          Serial.println("Wrong password \nRetry");
          digitalWrite(3, HIGH);
         // delay(1000);
          digitalWrite(2, LOW);
          digitalWrite(4, LOW);
          digitalWrite(4, HIGH);
          delay(1000);
          digitalWrite(4, LOW);
          
          }
   }
    }
    }
    else if(str!=SSID)   //if the entered id is not right then reenter it and in this the red led is on and buzzer sounds::
    {
      Serial.println("id wrong");
      Serial.println("Retry");
       digitalWrite(3, HIGH);
      // delay(1000);
       digitalWrite(2, LOW);
       digitalWrite(4, HIGH);
      delay(1000);
       digitalWrite(4, LOW);
       }
}  
}
}
