#include <PID_v1.h>

#define PIN_INPUT A1//on définit la photorésistance en entrée analogique sur la broche A1
#define PIN_OUTPUT 11//on définit la LED en sortie sur la broche 11
#define PIN_POT A0//on définit le potentiomètre en entrée sur la broche A0
unsigned int PotentiometreValue;

double Setpoint, Input, Output;//on définit les différentes variables pour simplifier le code par la suite


double Kp=0, Ki=10, Kd=0;//on définit les différentes variables pour simplifier le code par la suite

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  //on ininitialise les variables 
  Input = analogRead(PIN_INPUT);//on lit la valeur du potentiomètre

  //on allume le PID
  myPID.SetMode(AUTOMATIC);
}
void loop()
{
PotentiometreValue = analogRead(PIN_POT);//la valeur attribuée au potentiomètre est celle lue sur celui ci
  Setpoint = PotentiometreValue ;//on définit la sensibilité de la photorésistance
  Input = analogRead(PIN_INPUT);//on lit la veleur de la photorésistance et on l'applique à la led
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);//on illumine la led en fonction de la valeur de la photorésistance
 }
