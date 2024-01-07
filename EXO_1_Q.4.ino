unsigned int PotentiometreValue;// La broche numérique 5 est reliée à la led. On lui donne le nom Led.

int Led = 10;// Déclaration variable IntensiteLed qui va servir à stocker une valeur au format int.
int IntensiteLed;


void setup() {
 
  pinMode(Led, OUTPUT); // Définit Led soit la broche numérique 10 comme sortie.
}

void loop() {
  // Lit la valeur de la broche analogique A2 et stock sa valeur dans PotentiometreValue.
  PotentiometreValue = analogRead(A2);
  // La valeur du PotentiometreValue Min = 0, Max = 1023 et mappée à Min = 0, Max = 255 puis est stockée dans IntensiteLed.
  IntensiteLed = map(PotentiometreValue, 0, 1023, 0, 255);
  // Met la broche numérique 5 (Led) à la valeur de IntensiteLed.
  analogWrite(Led, IntensiteLed);
  // attend 10 millisecondes.
  delay(10);
