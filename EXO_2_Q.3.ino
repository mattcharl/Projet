#include <PID_v1.h>

#define PIN_INPUT 1//on définit la photorésistance en entrée analogique sur la broche A1
#define PIN_OUTPUT 11//on définit la LED en sortie sur la broche 11
#define PIN_POT 0//on définit le potentiomètre en entrée analogique sur la broche A0

unsigned int PotentiometreValue;//on déclare la variable de la valeur du potentiomètre 

double Setpoint, Input, Output;//on définit les différentes variables pour simplifier le code par la suite


double Kp=0, Ki=10, Kd=0;//on définit les différentes variables pour simplifier le code par la suite

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  //on initialise les variables
  Serial.begin(9600);//on ouvre le moniteur série 
  Input = analogRead(PIN_INPUT);//on lit la valeur du potentiomètre


  myPID.SetMode(AUTOMATIC);
}
void loop()
{
  Serial.println(PotentiometreValue);//on affiche la velur du potentiomètre dans le moniteur série 
  PotentiometreValue = analogRead(PIN_POT);//cette valeur sera celle lue sur la rotation du potentiomètre 
  Setpoint = PotentiometreValue ;//on définit la sensibilité de la photorésistance
  Input = analogRead(PIN_INPUT);//on lit la veleur de la photorésistance et on l'applique à la led
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);//on illumine la led en fonction de la valeur de la photorésistance
}
