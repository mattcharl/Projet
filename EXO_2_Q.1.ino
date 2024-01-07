#include <PID_v1.h>

#define PIN_INPUT A1//on définit la photorésistance en entrée analogique sur la broche A1
#define PIN_OUTPUT 11//on définit la LED en sortie sur la broche 11


double Setpoint, Input, Output;//on définit les différentes variables pour simplifier le code par la suite


double Kp=0, Ki=10, Kd=0;//on définit les différentes variables pour simplifier le code par la suite

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Input = analogRead(PIN_INPUT);//on lit la valeur du potentiomètre
  Setpoint = 50;//on définit la sensibilité de la photorésistance

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
  Input = analogRead(PIN_INPUT);//on lit la veleur de la photorésistance et on l'applique à la led
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);//on illumine la led en fonction de la valeur de la photorésistance
}
