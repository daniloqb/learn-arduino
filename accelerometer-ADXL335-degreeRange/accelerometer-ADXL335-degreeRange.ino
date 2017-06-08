
int x_pin = A0;
int y_pin = A1;
int z_pin = A2;


int x_min,x_max;
int y_min,y_max;
int z_min,z_max;

int x_pos,y_pos,z_pos;

void setup() {

  analogReference(EXTERNAL);
 
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  pinMode(z_pin, INPUT);
  Serial.begin(9600);

  x_min = 399;
  y_min = 403;
  z_min = 419;
  x_max = 598;
  y_max = 605;
  z_max = 623;
  
}

void loop() {

  x_pos = map(analogRead(x_pin),x_min,x_max,-90,90);
  y_pos = map(analogRead(y_pin),y_min,y_max,-90,90);
  z_pos = map(analogRead(z_pin),z_min,z_max,-90,90);


  Serial.print("x: ");Serial.print(x_pos);Serial.print('\t');
  Serial.print("y: ");Serial.print(y_pos);Serial.print('\t');
  Serial.print("z: ");Serial.print(z_pos);Serial.println();

  delay(20);

}
