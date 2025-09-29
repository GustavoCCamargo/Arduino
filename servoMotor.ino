#include <Servo.h>
Servo ms;


#define numServo 4
#define tempoMin 40

Servo servos[numServo];

int pinServos[] = {6, 9, 10, 11};

int angI[] = {0, 180, 90, 60};
int angF[] = {180, 120, 0, 180};


void setup() {
  
  // put your setup code here, to run once:
  for(int i = 0; i <numServo; i++){
    servos[i].attach(pinServos[i]);
  }
  

  
}



void moveServos(int angI[], int angF[], int tempo){

  int passos = tempo/tempoMin;

  float angP[numServo];
  float posicoes[numServo];

  for(int i= 0; i<numServo; i++){
    angP[i] = (angF[i] - angI[i])/passos;
    posicoes[i] = angI[i];
  }
  

  for(int p=0; p<passos; p++){
    for(int i = 0; i<numServo; i++){
      posicoes[i]+=angP[i];
      servos[i].write(posicoes[i]);
    }
    delay(tempoMin);
  }
  

  for(int i = 0; i<numServo; i++){
    posicoes[i] = angF[i];
    servos[i].write(posicoes[i]);
  }
  
}



void loop() {
  // put your main code here, to run repeatedly:
  //moveServoT(0, 180, 3000);
  //moveServoA(0, 180, 3000);


  moveServos(angI, angF,5000);
  moveServos(angF, angI, 8000);
}

