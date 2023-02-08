 #include <Servo.h>
 
 int pot_1 = A0;
 int pot_2 = A1;
 int pot_3 = A2;
 int pot_4 = A3;
 int pot_5 = A4;
 
Servo myservo1; 
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;


int prev_val_1 = 0;
int prev_val_2 = 0;
int prev_val_3 = 0;
int prev_val_4 = 0;
int prev_val_5 = 0;

int servo_val_1;
int servo_val_2;
int servo_val_3;
int servo_val_4;
int servo_val_5;

void Home(){
   myservo1.write(135); 
  myservo2.write(247);
  myservo3.write(60); 
  myservo4.write(0);
  myservo5.write(0);
  delay(3000);
  

}

void setup() {
  myservo1.attach(3);
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(9);
  myservo5.attach(10);
  
  pinMode(2,INPUT_PULLUP);
  
  Serial.begin(9600);

  Home();

}

void loop() {

prev_val_1 = servo_val_1;
prev_val_2 = servo_val_2;
prev_val_3 = servo_val_3;
prev_val_4 = servo_val_4;
prev_val_5 = servo_val_5;
  int home_button = digitalRead(2);
  
  int pot_val_1 = analogRead(pot_1);
  int pot_val_2 = analogRead(pot_2);
  int pot_val_3 = analogRead(pot_3);
  int pot_val_4 = analogRead(pot_4);
  int pot_val_5 = analogRead(pot_5);

  int val_1 = pot_val_1/4 ;
  int val_2 = pot_val_2/4 ;
  int val_3 = pot_val_3/4 ;
  int val_4 = pot_val_4/4 ;

  servo_val_1 = (val_1*0.05)+(prev_val_1*0.95);
  servo_val_2 = (val_2*0.05)+(prev_val_2*0.95);
  servo_val_3 = (val_3*0.05)+(prev_val_3*0.95);
  servo_val_4 = (val_4*0.05)+(prev_val_4*0.95);

  int servo_val_5 = pot_val_5/4 ;
  Serial.print(servo_val_1);
  Serial.print("\n");
  Serial.print(servo_val_2);
  Serial.print("\n");
  Serial.print(servo_val_3);
  Serial.print("\n");
  Serial.print(servo_val_4);
  Serial.print("\n");
  Serial.print(servo_val_5);
  Serial.print("\n"); 

  myservo1.write(servo_val_1); 
  myservo2.write(servo_val_2);
  myservo3.write(servo_val_3); 
  myservo4.write(servo_val_4);
  myservo5.write(servo_val_5);
  if (home_button == LOW){
    End();
    exit(0);
   }
  
}
void End(){
    myservo4.write(205);
  delay(500); 
  myservo5.write(0);
  delay(500); 
  myservo3.write(150);
   delay(500); 
  myservo2.write(255);
  delay(500); 
  myservo1.write(42);
   

  delay(5000);
}
