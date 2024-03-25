// C++ code
/* 
Este programa controla o sentido de xiro dun motor mediante 
a combinación de catro microinterruptores.
Os interruptores 1 e 4 activados á vez indican o xiro á dereita,
mentres que os outros dous indican o xiro á esquerda. 
Se ningún está activado, o motor detense. 

Autor: Pablo Cameán Garrido.
Data: Marzo 2024.
*/

// Definición de pins
int rele1 = 8;  // Relé 1
int rele2 = 9;  // Relé 2
int rele3 = 10; // Relé 3
int rele4 = 11; // Relé 4
int int1 = 4;   // Microinterruptor 1
int int2 = 5;   // Microinterruptor 2
int int3 = 6;   // Microinterruptor 3
int int4 = 7;   // Microinterruptor 4

void setup() {
  // Configuración de pins
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
  pinMode(int1, INPUT);
  pinMode(int2, INPUT);
  pinMode(int3, INPUT);
  pinMode(int4, INPUT);
  
  Serial.begin(9600);
}

void loop() {

 // Lectura dos estados dos microinterruptores
 int estadoint1 = digitalRead(int1);
 int estadoint2 = digitalRead(int2);
 int estadoint3 = digitalRead(int3);
 int estadoint4 = digitalRead(int4);
  
  if (estadoint1 == HIGH && estadoint4 == HIGH) {
    // Xiro á dereita
    digitalWrite(rele1, HIGH);
    digitalWrite(rele2, LOW);
    digitalWrite(rele3, LOW);
    digitalWrite(rele4, HIGH);
    Serial.println("Dereita");
  } else if (estadoint2 == HIGH && estadoint3 == HIGH) {
    // Xiro á esquerda
    digitalWrite(rele1, LOW);
    digitalWrite(rele2, HIGH);
    digitalWrite(rele3, HIGH);
    digitalWrite(rele4, LOW);
    Serial.println("Esquerda");
  } else {
    // Motor parado
    digitalWrite(rele1, LOW);
    digitalWrite(rele2, LOW);
    digitalWrite(rele3, LOW);
    digitalWrite(rele4, LOW);
    Serial.println("Apagado");
  }
  // Pequeno retraso para estabilidade
  delay(100);
}
