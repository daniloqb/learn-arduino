//Programa: Sensor de velocidade Arduino LM393
//Autor: Arduino e Cia

//Pino ligado ao pino D0 do sensor
int pino_D0 = 2;
int pino_D1 = 3;

int rpm1;
int rpm2;

float analogVal;

volatile byte pulsos;
unsigned long timeold;

//Altere o numero abaixo de acordo com o seu disco encoder
unsigned int pulsos_por_volta = 20;

int status;

void contador()
{
  //Incrementa contador
  pulsos++;
}

void setup()
{
  Serial.begin(9600);
  //Pino do sensor como entrada
  pinMode(pino_D0, INPUT);
  pinMode(pino_D1, INPUT);
  //Interrupcao 0 - pino digital 2
  //Aciona o contador a cada pulso
  //attachInterrupt(0, contador, FALLING);
  pulsos = 0;
  rpm1 = 0;
  rpm2 = 0;
  analogVal = 0;
  timeold = 0;

  status = 0;
}

void loop()
{


  // PRIMEIRO MOTOR
  // 1 - Habilita o contador
  if (status == 0){
    attachInterrupt(0, contador, FALLING);
    status = 1;
    timeold = millis();
  }


  // Desabilita o contador e faz a leitura
  if ((status == 1) && (millis() - timeold >= 1000))
  {
    //Desabilita interrupcao durante o calculo
    detachInterrupt(0);
    detachInterrupt(1);
    rpm1 = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold) * pulsos;
    timeold = millis();
    pulsos = 0;

    //Mostra o valor de RPM no serial monitor
//    Serial.print("RPM = ");
//    Serial.println(rpm1, DEC);
    //Habilita interrupcao
    //attachInterrupt(0, contador, FALLING);

    status = 2;
  }

  // SEGUNDO MOTOR
  // 1 - Habilita o contador
  
  if (status == 2){
    attachInterrupt(1, contador, FALLING);
    status = 3;
    timeold = millis();
  }


  // Desabilita o contador e faz a leitura
  if ((status == 3) && (millis() - timeold >= 1000))
  {
    //Desabilita interrupcao durante o calculo
    detachInterrupt(0);
    detachInterrupt(1);
    rpm2 = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold) * pulsos;
    timeold = millis();
    pulsos = 0;

    //Mostra o valor de RPM no serial monitor
//    Serial.print("RPM = ");
//    Serial.println(rpm1, DEC);
    //Habilita interrupcao
    //attachInterrupt(0, contador, FALLING);

    status = 4;
  }



  // Desabilita o contador e faz a leitura



  // SENSOR ANALOGICO
  // Faz a leitura do sensor
  if (status == 4){
    analogVal = analogRead(A0);

    status = 5;
  }



  // ENVIO DOS DADOS
  if (status == 5){
    Serial.println("Values: ");
    Serial.print("Analog: ");
    Serial.println(analogVal);
    Serial.print("RPM 1: ");
    Serial.println(rpm1,DEC);
    Serial.print("RPM 2: ");
    Serial.println(rpm2,DEC);
    Serial.println();
    status = 0;
  }
  
  
}
