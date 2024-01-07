void setup() {

pinMode(10,OUTPUT);// la led est placée en sortie sur la broche 10

}

void loop() {

analogWrite(10,63);//allumer la led à 25 pourcents
delay (2000);//attendre 2 seconde
analogWrite(10,125);//allumer la led à 50 pourcents
delay(2000);//attendre 2 seconde
analogWrite(10,191);//allumer la led à 75 pourcents
delay(2000);


}
