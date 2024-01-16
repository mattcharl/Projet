#include <Servo.h>  //Appel de la librairie "SERVO"


Servo myservo;  // Crée l'objet SERVO pour controler le SERVOMOTEUR
int pos = 0;    // variable qui enregistre la position du SERVO
// définition des bornes d'entrée et sortie
const int rouge = 3;   //La led rouge est connectée à la PIN 3
const int verte = 4;   //La led verte est connectée à la PIN 4
const int bouton = 2;  //Le bouton est connecté à la PIN 2
const int servo = 9;  //Le servo est connecté à la PIN 9
int etatbouton = 0;  // Vérification de l'état du bouton


void setup() {
  myservo.attach(servo);
  pinMode(rouge, OUTPUT); // Définition des entrées/sorties
  pinMode(verte, OUTPUT);
  pinMode(bouton, INPUT);
  Serial.begin(9600);
}


void loop() {
  // On initialise dès le début l'état des led
  digitalWrite(rouge, HIGH);
  digitalWrite(verte, LOW);


  etatbouton = digitalRead(bouton); // Lit l'état du bouton poussoir
  if (etatbouton == HIGH) {    // si bouton appuyé, alors on lève la barrière et on fait changer l'état des led, sinon, on reboucle
  Serial.println("Bouton appuyé");
    for (pos = 0; pos <= 90; pos += 1) { // on commence à actionner dans un sens la barrière, jusqu'à 90°, degrés par degrés
      myservo.write(pos);              // va à la position "POS"
      delay(15);                       // attends 15ms avant de changer la position de la barrière d'1 degré
    }
    // la barrière est levée, on peut allumer la led verte et éteindre la rouge
    digitalWrite(verte, HIGH);
    digitalWrite(rouge, LOW);


    delay(5000); // Attends 5 secondes
    // La led rouge s'allume et on éteint la verte
    digitalWrite(rouge, HIGH);
    digitalWrite(verte, LOW);
    //On referme ensuite la barrière
    for (pos = 90; pos >= 0; pos -= 1) { // cette fois si, on passe de 90° à 0° (décroit à chaque fois de -1)
      myservo.write(pos);              // va à la position "POS"
      delay(15);                       // attends 15ms avant de changer la position de la barrière d'1 degré
    }
  }
}
