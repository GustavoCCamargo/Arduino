#define PIN_LED_R 9
#define  PIN_LED_G 10
#define  PIN_LED_B 11
#define tempo 50
#define tempinho 20

void setRGB(int R, int G, int B){
  analogWrite(PIN_LED_R, R);
  analogWrite(PIN_LED_G, G);
  analogWrite(PIN_LED_B, B);
}

void setup() {
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  setRGB(0,0,0);

  Serial.begin(9600);
}


void pwm_separado(){

  setRGB(0,0,0);


  // led vermelho
  for(int i=0; i <256; i++){
    setRGB(i,0,0);
    delay(tempo);
  }

  for(int i=255; i >=0; i--){
    setRGB(i,0,0);
    delay(tempo);
  }

  delay(tempinho);

  //led Verde
  for(int i=0; i <256; i++){
    setRGB(0,i,0);
    delay(tempo);
  }
  for(int i=255; i >=0; i--){
    setRGB(0,i,0);
    delay(tempo);
  }

  delay(tempinho);

  //led Azul
  for(int i=0; i <256; i++){
    setRGB(0,0,i);
    delay(tempo);
  }
  for(int i=255; i >=0; i--){
    setRGB(0,0,i);
    delay(tempo);
  }

  delay(tempinho);
}

void todas_cores(){
  for(int r =0; r<256; r +=30){
    for(int g =0; g<256; g +=30){
      for(int b =0; b<256; b +=30){
        setRGB(r,g,b);
        delay(tempo);
      }
    }
  }
}

void controle_serial(){
  int incomingByte = 0;
  if(Serial.available() > 0){
    incomingByte = Serial.read();

    if(incomingByte >= '0' && incomingByte <= '9'){
      setRGB(0, 0, 0);
      incomingByte = incomingByte - '0';
      int valor = map(incomingByte, 0, 9, 0, 255);
      setRGB(valor, 0, 0);
    }


    if(incomingByte >= 'A' && incomingByte <= 'Z'){
      setRGB(0, 0, 0);
      incomingByte = incomingByte - 'A';
      int valor = map(incomingByte, 0, 'Z' - 'A' + 1, 0, 255);

      setRGB(0, valor, 0);
    }

    if(incomingByte >= 'a' && incomingByte <= 'z'){
      setRGB(0, 0, 0);
      incomingByte = incomingByte - 'a';
      int valor = map(incomingByte, 0, 'z' - 'a' + 1, 0, 255);

      setRGB(0,0,valor);
    }
  }
}

void controle_serial_tds_cores(){
  int letra;
  int valor; 
  
  if(Serial.available() > 0){

    letra = Serial.read();

    if(letra == 'r' || letra == 'g' || letra == 'b' ){
      
      while(Serial.available() == 0){
        delay(1);
      }
      
      valor = Serial.read();
      if(valor >= '0' && valor <= '9'){
        valor = valor - '0';
        int valor = map(valor, 0, 9, 0, 255);

        switch(letra){
          case 'r':
            analogWrite(PIN_LED_R, valor);
          break;

          case 'g':
            analogWrite(PIN_LED_G, valor);
          break;

          case 'b':
            analogWrite(PIN_LED_B, valor);
          break;
        }
        
      }
    }
  }


}

void loop() {

  //pwm_separado();
  //todas_cores();
  //controle_serial();
  controle_serial_tds_cores();
}
