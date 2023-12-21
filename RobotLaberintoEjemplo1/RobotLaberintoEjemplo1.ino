#include <NewPing.h>

// Definición de pines para los sensores ultrasonidos
#define TRIGGER_PIN_1 2
#define ECHO_PIN_1 3
#define TRIGGER_PIN_2 4
#define ECHO_PIN_2 5
#define TRIGGER_PIN_3 6
#define ECHO_PIN_3 7

// Definición de pines para el puente H L293D
#define MOTOR_A1 8
#define MOTOR_A2 9
#define MOTOR_B1 10
#define MOTOR_B2 11

// Definición de pines para la dirección de los motores
#define MOTOR_A_EN 5
#define MOTOR_B_EN 6

// Definición de la distancia máxima de detección
#define MAX_DISTANCE 200

// Crear instancias de los sensores ultrasonidos
NewPing sonar1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);

void setup() {
  // Configuración de pines de control del puente H y motores
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);
  pinMode(MOTOR_B1, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);

  // Configuración de pines de velocidad (PWM)
  pinMode(MOTOR_A_EN, OUTPUT);
  pinMode(MOTOR_B_EN, OUTPUT);
}

void loop() {
  // Lógica para la detección de obstáculos y movimientos del robot
  int distancia1 = sonar1.ping_cm();
  int distancia2 = sonar2.ping_cm();
  int distancia3 = sonar3.ping_cm();

  // Ajusta estos valores según la lógica específica de tu laberinto
  int umbral = 10;

  // Lógica de movimiento en función de las lecturas de los sensores
  if (distancia2 > umbral) {
    // Avanzar
    forward();
  } else {
    // Giro o cambio de dirección según las lecturas de los sensores
    if (distancia1 > distancia3) {
      // Giro a la derecha
      turnRight();
    } else {
      // Giro a la izquierda
      turnLeft();
    }
  }
}

void forward() {
  // Motor A
  digitalWrite(MOTOR_A1, HIGH);
  digitalWrite(MOTOR_A2, LOW);
  analogWrite(MOTOR_A_EN, 255); // Velocidad máxima

  // Motor B
  digitalWrite(MOTOR_B1, HIGH);
  digitalWrite(MOTOR_B2, LOW);
  analogWrite(MOTOR_B_EN, 255); // Velocidad máxima
}

void turnRight() {
  // Motor A
  digitalWrite(MOTOR_A1, HIGH);
  digitalWrite(MOTOR_A2, LOW);
  analogWrite(MOTOR_A_EN, 150);

  // Motor B
  digitalWrite(MOTOR_B1, LOW);
  digitalWrite(MOTOR_B2, HIGH);
  analogWrite(MOTOR_B_EN, 150);
}

void turnLeft() {
  // Motor A
  digitalWrite(MOTOR_A1, LOW);
  digitalWrite(MOTOR_A2, HIGH);
  analogWrite(MOTOR_A_EN, 150);

  // Motor B
  digitalWrite(MOTOR_B1, HIGH);
  digitalWrite(MOTOR_B2, LOW);
  analogWrite(MOTOR_B_EN, 150);
}
