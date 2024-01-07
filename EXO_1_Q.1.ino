void setup()
 {

pinMode(10,OUTPUT);// la led est placée en sortie sur la broche 10

}

void loop() {

digitalWrite(10,HIGH);//allumer la led
delay (1000);//attendre 1 seconde
digitalWrite(10,LOW);//éteindre la led
delay(1000);//attendre 1 seconde

}
