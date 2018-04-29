
const int col_pins[8] = {2,3,4,5,6,7,8,9};
const int row_pins[6] = {10,11,12,13,18,19};


const int COL_OFF = HIGH;
const int COL_ON = LOW;
const int ROW_OFF = LOW;
const int ROW_ON = HIGH;


int num_cols = 8;
int num_rows = 6;



void handle_rows(byte data){

  byte mask = 0x01;

  for (int i = 0; i < num_rows; i++){
    digitalWrite(row_pins[i], (data & mask));
    mask = mask << 1;
  }
}

void handle_cols(byte data){

  byte mask = 0x01;

  for (int i = 0; i < num_cols; i++){
    digitalWrite(col_pins[i], !(data & mask));
    mask = mask << 1;
  }
}

void setbit(byte r, byte c){
  digitalWrite(row_pins[r],ROW_ON);
  digitalWrite(col_pins[c],COL_ON);
}


void turnoff_cols(){
 
 for (int i =0; i < num_cols; i++){
 
  digitalWrite(col_pins[i], COL_OFF);
 }

}

void turnoff_rows(){
  for (int i = 0; i < num_rows; i++){
   
   digitalWrite(row_pins[i],ROW_OFF);
  }
}


void setup() {

 for (int i =0; i < num_cols; i++){
  pinMode(col_pins[i], OUTPUT);
  digitalWrite(col_pins[i], COL_OFF);
 }


  for (int i = 0; i < num_rows; i++){
    pinMode(row_pins[i],OUTPUT);
    digitalWrite(row_pins[i],ROW_OFF);
  }


}

byte data_rows = 0;
byte data_cols = 0;

void loop() {




for (int i = 0; i < num_rows;i++){
  for (int j = 0; j < num_cols; j++){
    
turnoff_cols();
turnoff_rows();
    setbit(i,j);
    
    
  }
}


}
