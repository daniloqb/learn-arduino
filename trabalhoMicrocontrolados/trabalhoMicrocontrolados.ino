//Bibliotecas
#include <Thermistor.h>    //termistor
#include <Stepper.h>       //motor de passo
#include <LiquidCrystal.h> //LCD

//Janela
int mecanismoJanela = 0; //aberta

//LCD  (LiquidCrystal(rs, enable, d4, d5, d6, d7) )
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //Configura os pinos do Arduino para se comunicar com o LCD

// Motor 
const int passo = 230;
Stepper   motorJanela(passo, 8,9,10,11);      //inicia a biblioteca do motor nos pinos do 8 ao 11

//Termistor
Thermistor temp(A0); 
int temperature=0;

// rainSensor 
int rainAnPin = A1;

//LDR
int luminosity = A2;

//Botao interruptor com debouncing via millis()
int  buttonPin   = 12;
int  buttonState = 0 ;
int  lastButtonState  = 0;
long lastDebounceTime = 0;
long debounceDelay    = 100;

//Functions
void abreJanela(){
  motorJanela.step(passo); //para o outro lado e so por positivo (passo)
  mecanismoJanela = 0;
}
void fechaJanela(){
  motorJanela.step(-passo); 
  mecanismoJanela = 1;
}

void retChuva(int pinToRead, int *digital, int *analogico){
  //observacao: Calibragem do sensor: {1024 - 900 = sem chuva / 900 - 400 = chuva moderada / 400< = Chuva Forte}
  *analogico = analogRead(pinToRead);
  
  if (*analogico < 900) 
    *digital = 1;
  else
    *digital = 0;//sem chuva
}

int retNoite(int pinToRead){
  if (analogRead(pinToRead) < 100)
    return 1;
  else
    return 0;
}

char lin0[16]={};
char lin1[16]={};

//SETUP
void setup() {  
  //motor
  motorJanela.setSpeed(30);    
  
  pinMode(rainAnPin,  INPUT);
  pinMode(luminosity, INPUT);
  pinMode(buttonPin,  INPUT); 
  
  //lcd
  Serial.begin(9600);
  lcd.begin(16, 2); //Inicia o LCD com dimensões 16x2(Colunas x Linhas)

  sprintf(lin0,"Apresent. Marcio");
  lcd.setCursor(0, 0); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD  
  lcd.print(lin0);
  sprintf(lin1, "F, J, L, R    :D", temperature);
  lcd.setCursor(0, 1); //Posiciona o cursor na primeira coluna(0) e na segunda linha(1) do LCD
  lcd.print(lin1); 
  delay(2000);
  lcd.clear();
}

//LOOP
void loop() {
  //acionamento manual do mecanismo da janela
  int readBtn = digitalRead(buttonPin); 

  if (readBtn != lastButtonState) {
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    //btn
    if (readBtn != buttonState) {
      buttonState = readBtn;

      if (buttonState == HIGH) {
        if (mecanismoJanela==0){
          fechaJanela();
        }else if (mecanismoJanela==1){
          abreJanela();       
        }
      }
    }
  }
    
  //temperatura
  temperature = temp.getTemp();  
  if (retNoite(luminosity)==0){
    sprintf(lin0,"%d*C DIA        ", temperature);  
  }else{
    sprintf(lin0,"%d*C NOITE      ", temperature);  
  }
  
  lcd.setCursor(0, 0); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD  
  lcd.print(lin0);
    
  //chuva
  int recChuva[2];
  retChuva(rainAnPin, &recChuva[0], &recChuva[1]);
  if (recChuva[0]==0)
  {
    sprintf(lin1, "Sem Chuva!      ");
  }
  else 
  {
    if (recChuva[1] >900 && recChuva[1] <1024)
      sprintf(lin1, "Sem Chuva!      ");
    else if (recChuva[1] >400 && recChuva[1] <900)
      sprintf(lin1, "Chuva Media!    ");
    else if (recChuva[1] > 0 && recChuva[1] <400)
      sprintf(lin1, "Chuva Forte!    ");
  } 
  lcd.setCursor(0, 1); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD  
  lcd.print(lin1);
 
  //mecanismo da janela funciona sozinho somente se o estado for aberto "0"
  if (((recChuva[0] == 1) || (temperature<17) || retNoite(luminosity)) && (mecanismoJanela == 0))
  {
      fechaJanela();
  }
  
  lastButtonState = readBtn; 
}
