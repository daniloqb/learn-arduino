
const int x_pin = A0;
const int y_pin = A1;
const int z_pin = A2;

const int left = 450;
const int right = 550;
const int forward = 550;
const int backward = 450;

int x_pos,y_pos,z_pos;


void turnLeft();
void turnRight();
void moveForward();
void moveBackward();

void setup() {

  analogReference(EXTERNAL);
 
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  pinMode(z_pin, INPUT);
  Serial.begin(9600);


  
}

void loop() {

  x_pos = analogRead(x_pin);
  y_pos = analogRead(y_pin);
//  z_pos = analogRead(z_pin);
  

  if(x_pos <= left) turnLeft();
  else if(x_pos >= right) turnRight();

  if(y_pos <= backward) moveBackward();
  else if(y_pos >=forward) moveForward();

  Serial.println();
  delay(20);
  
}




void turnLeft(){
  Serial.print("Turn Left ");
  }
void turnRight(){
  Serial.print("Turn Right ");
  }
void moveForward(){
  Serial.print("Move Forward ");
  
  }
void moveBackward(){
  Serial.print("Move Backward ");
  
  }
