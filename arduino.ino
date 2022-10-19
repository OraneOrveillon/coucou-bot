#include <Servo.h>  // on inclut la bibliothèque pour piloter un servomoteur
#define OBS 2
#define LED 3

Servo monServo;  // on crée l'objet monServo

int avoid;

int calibrationTime = 2;

void setup() {
  monServo.attach(A0); // on définit le Pin utilisé par le servomoteur

  Serial.begin(9600);

  pinMode(OBS, INPUT);
  pinMode(LED, OUTPUT);

}
void loop() {
  

  avoid = digitalRead(OBS);   // lecture de la valeur du signal
  Serial.print("Avoid Sensor - ");
  Serial.println(avoid);

  
  if (avoid == HIGH) { 
    digitalWrite(LED, LOW);
  }
  // Quand il y a une présence
  else { 
    // Allume la LED
    digitalWrite(LED, HIGH);

    // Fait touner le moteur 
    for (int position = 0; position <=180; position ++){ // on crée une variable position qui prend des valeurs entre 0 à 180 degrés
      monServo.write(position);  // le bras du servomoteur prend la position de la variable position
      delay(1);  // on attend 15 millisecondes
    }
    for (int position = 180; position >=0; position --){ // cette fois la variable position passe de 180 à 0°
      monServo.write(position);  // le bras du servomoteur prend la position de la variable position
      delay(1);  // le bras du servomoteur prend la position de la variable position
    }
  }
}