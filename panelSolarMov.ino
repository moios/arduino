// Programa para controlar un panel solar en dos ejes utilizando servomotores
#include <Servo.h>

// Configuración de los servos
#define MOTOR1_PIN 9     // Servo que gira el panel sobre su eje
#define MOTOR2_PIN 6     // Servo que controla la inclinación

// Constantes para los ángulos
const int MOTOR1_STEP_ANGLE = 10; // Ángulo por paso para el servo 1
const int MOTOR2_STEP_ANGLE = 5;  // Ángulo por paso para el servo 2
const int MOTOR1_FULL_ROTATION = 360; // Rotación completa del servo 1
const int MOTOR2_MAX_ANGLE = 90;      // Máximo ángulo del servo 2

// Inicialización de los servos
Servo motor1;
Servo motor2;

void setup() {
  // Adjuntar servos a los pines
  motor1.attach(MOTOR1_PIN);
  motor2.attach(MOTOR2_PIN);

  // Posicionar servos en la posición inicial
  motor1.write(0);
  motor2.write(0);
}

void loop() {
  // Movimiento del servo 1 (Rotación completa y retorno)
  for (int angle = 0; angle < MOTOR1_FULL_ROTATION; angle += MOTOR1_STEP_ANGLE) {
    motor1.write(angle % 180); // Los servos estándar tienen un rango de 0-180 grados
    delay(100);
  }
  for (int angle = MOTOR1_FULL_ROTATION; angle > 0; angle -= MOTOR1_STEP_ANGLE) {
    motor1.write(angle % 180);
    delay(100);
  }

  // Movimiento del servo 2 (Inclinación máxima y retorno)
  for (int angle = 0; angle <= MOTOR2_MAX_ANGLE; angle += MOTOR2_STEP_ANGLE) {
    motor2.write(angle);
    delay(100);
  }
  for (int angle = MOTOR2_MAX_ANGLE; angle > 0; angle -= MOTOR2_STEP_ANGLE) {
    motor2.write(angle);
    delay(100);
  }
}
