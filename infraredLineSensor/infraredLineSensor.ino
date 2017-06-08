
const byte sensor = 2;


void setup() {
  Serial.begin(9600);

  pinMode(sensor,INPUT);
}

void loop() {

  boolean obstacule = digitalRead(sensor);

  if(obstacule)
    Serial.println("Find Obstacule.");
  else
    Serial.println("Nothing or line found.");
  
}
