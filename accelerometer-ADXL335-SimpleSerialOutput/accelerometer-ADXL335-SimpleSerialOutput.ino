
int pin_x = A0;
int pin_y = A1;
int pin_z = A2;


void setup() {

  analogReference(EXTERNAL);

  pinMode(pin_x, INPUT);
  pinMode(pin_y, INPUT);
  pinMode(pin_z, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  int x, y, z;
  
  x = analogRead(pin_x);
  y = analogRead(pin_y);
  z = analogRead(pin_z);



  Serial.print(x); Serial.print('\t');
  Serial.print(y); Serial.print('\t');
  Serial.print(z); Serial.println();

  delay(10);
}
