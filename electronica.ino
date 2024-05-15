// Definición de pines para los displays de 7 segmentos
const int displayPins[7] = { 2, 3, 4, 5, 6, 7, 8 };

// Definición de pines para el encendido de los displays
const int pinesVoltaje[2] = { 9, 10 };

// Pin de salida para la señal de alarma y su temperatura de activación
const int pinAlarma = 11;
int tempAlarma = 30;

// Variable para almacenar el voltaje obtenido del input
float voltaje = 0.0;

// Variable para almacenar el valor de la temperatura en unidad y decena
int unidad = 0;
int decena = 0;

void setup() {
  // Inicialización de pines para los displays de 7 segmentos
  for (int i = 0; i < 7; i++) {
    pinMode(displayPins[i], OUTPUT);
  }

  // Inicialización de pines para el encendido de los displays
  for (int i = 0; i < 2; i++) {
    pinMode(pinesVoltaje[i], OUTPUT);
  }

  // Configurar el pin de salida para la señal de alarma
  pinMode(pinAlarma, OUTPUT);

  // Inicialización del puerto serial para la depuración
  Serial.begin(9600);
}

void loop() {
  // Lectura del voltaje desde el input
  voltaje = analogRead(A0) * (50 / 1023.0);  // Se lee el valor del pin de entrada A0 y se pasa a voltaje en las unidades correspondientes

  // Convertir el voltaje a un número entero
  int valor = int(voltaje);

  // Calibrar el valor medido introduciendo un offset determinado por el usuario
  int offset = 0;
  int valor_calibrado = valor - offset;

  // Sacar el valor de la unidad y de la decena a partir del voltaje medido
  unidad = valor_calibrado % 10;
  decena = valor_calibrado / 10;


  // Verificar si la temperatura supera el umbral de 30 grados
  if (valor_calibrado >= tempAlarma) {
    digitalWrite(pinAlarma, HIGH);  // Activar la señal de alarma
  } else {
    digitalWrite(pinAlarma, LOW);  // Desactivar la señal de alarma
  }

  // Mostrar el número en los displays de 7 segmentos a la vez que se alterna el display encendido
  mostrarNumero(decena, 2);

  static bool estado = false;

  // Encender y apagar los displays alternativamente
  digitalWrite(pinesVoltaje[0], estado);
  digitalWrite(pinesVoltaje[1], !estado);

  // Alternar el display para el próximo ciclo
  estado = !estado;

  // Si se aumenta el delay se puede visualizar el cambio de un display a otro
  delay(5);

  mostrarNumero(unidad, 1);

  // Encender y apagar los displays alternativamente de nuevo
  digitalWrite(pinesVoltaje[0], estado);
  digitalWrite(pinesVoltaje[1], !estado);

  estado = !estado;

  delay(5);
}

void mostrarNumero(int numero, int pos) {
  // Mostrar el número en los displays de 7 segmentos comparando los valores con condicionales
  if (numero == 0) {
    digitalWrite(displayPins[0], LOW);  // Como la entrada está negada hay que poner en low los segmentos que queramos iluminados
    digitalWrite(displayPins[1], LOW);
    digitalWrite(displayPins[2], LOW);
    digitalWrite(displayPins[3], LOW);
    digitalWrite(displayPins[4], LOW);
    digitalWrite(displayPins[5], LOW);
    digitalWrite(displayPins[6], HIGH);
  } else if (numero == 1) {
    digitalWrite(displayPins[0], HIGH);
    digitalWrite(displayPins[1], LOW);
    digitalWrite(displayPins[2], LOW);
    digitalWrite(displayPins[3], HIGH);
    digitalWrite(displayPins[4], HIGH);
    digitalWrite(displayPins[5], HIGH);
    digitalWrite(displayPins[6], HIGH);
  } else if (numero == 2) {
    digitalWrite(displayPins[0], LOW);
    digitalWrite(displayPins[1], LOW);
    digitalWrite(displayPins[2], HIGH);
    digitalWrite(displayPins[3], LOW);
    digitalWrite(displayPins[4], LOW);
    digitalWrite(displayPins[5], HIGH);
    digitalWrite(displayPins[6], LOW);
  } else if (numero == 3) {
    digitalWrite(displayPins[0], LOW);
    digitalWrite(displayPins[1], LOW);
    digitalWrite(displayPins[2], LOW);
    digitalWrite(displayPins[3], LOW);
    digitalWrite(displayPins[4], HIGH);
    digitalWrite(displayPins[5], HIGH);
    digitalWrite(displayPins[6], LOW);
  } else if (numero == 4) {
    digitalWrite(displayPins[0], HIGH);
    digitalWrite(displayPins[1], LOW);
    digitalWrite(displayPins[2], LOW);
    digitalWrite(displayPins[3], HIGH);
    digitalWrite(displayPins[4], HIGH);
    digitalWrite(displayPins[5], LOW);
    digitalWrite(displayPins[6], LOW);
  } else if (numero == 5) {
    digitalWrite(displayPins[0], LOW);
    digitalWrite(displayPins[1], HIGH);
    digitalWrite(displayPins[2], LOW);
    digitalWrite(displayPins[3], LOW);
    digitalWrite(displayPins[4], HIGH);
    digitalWrite(displayPins[5], LOW);
    digitalWrite(displayPins[6], LOW);
  } else if (numero == 6) {
    digitalWrite(displayPins[0], LOW);
    digitalWrite(displayPins[1], HIGH);
    digitalWrite(displayPins[2], LOW);
    digitalWrite(displayPins[3], LOW);
    digitalWrite(displayPins[4], LOW);
    digitalWrite(displayPins[5], LOW);
    digitalWrite(displayPins[6], LOW);
  } else if (numero == 7) {
    digitalWrite(displayPins[0], LOW);
    digitalWrite(displayPins[1], LOW);
    digitalWrite(displayPins[2], LOW);
    digitalWrite(displayPins[3], HIGH);
    digitalWrite(displayPins[4], HIGH);
    digitalWrite(displayPins[5], HIGH);
    digitalWrite(displayPins[6], HIGH);
  } else if (numero == 8) {
    digitalWrite(displayPins[0], LOW);
    digitalWrite(displayPins[1], LOW);
    digitalWrite(displayPins[2], LOW);
    digitalWrite(displayPins[3], LOW);
    digitalWrite(displayPins[4], LOW);
    digitalWrite(displayPins[5], LOW);
    digitalWrite(displayPins[6], LOW);
  } else if (numero == 9) {
    digitalWrite(displayPins[0], LOW);
    digitalWrite(displayPins[1], LOW);
    digitalWrite(displayPins[2], LOW);
    digitalWrite(displayPins[3], HIGH);
    digitalWrite(displayPins[4], HIGH);
    digitalWrite(displayPins[5], LOW);
    digitalWrite(displayPins[6], LOW);
  }
}
