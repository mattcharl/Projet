unsigned int PotentiometreValue;
// La broche numérique 5 est reliée à la led. On lui donne le nom Led.
int Led = 10;
// Déclaration variable IntensiteLed qui va servir à stocker une valeur au format int.
int IntensiteLed;
#define LDR A0
unsigned int value;


void setup() {
  // Définit Led soit la broche numérique 10 comme sortie.
 
  pinMode(Led, OUTPUT);//la led esr placée en sortie
  pinMode(A0, INPUT);//la photorésistance est placée en entrée 
  Serial.begin(9600);//ouverture du moniteur série 
}

void loop() {
value = analogRead(LDR);//la valeur sera celle de la photorésistance
   Serial.println(value);//cette valeur est affiché dans le moniteur série
  // Lit la valeur de la broche analogique A2 et stock sa valeur dans PotentiometreValue.
  PotentiometreValue= analogRead(A2);
  // La valeur du PotentiometreValue Min = 0, Max = 1023 et mappée à Min = 0, Max = 255 puis est stockée dans IntensiteLed.
  IntensiteLed = map(PotentiometreValue, 0, 1023, 0, 255);
  // Met la broche numérique 5 (Ledverte) à la valeur de IntensiteLed.
  analogWrite(Led, IntensiteLed);
  // attend 10 millisecondes.
  delay(10);
}
