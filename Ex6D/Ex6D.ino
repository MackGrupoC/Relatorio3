

#define potencio_0 A0
#define potencio_1 A1

#define motor_0 9
#define motor_1 3

#define sentido_motor_0 7
#define sentido_motor_1 8


struct Potenciometro {
    int valor;
    int rotacao;
};

struct Potenciometro p0;
struct Potenciometro p1;

void setup(){
    
    Serial.begin(9600);
}

void loop(){
    p0.valor = analogRead(potencio_0);
    p1.valor = analogRead(potencio_1);

/*
    Serial.print("Potenciometro 0: ");
    Serial.println(p0.valor);
    Serial.print("Potenciometro 1: ");
    Serial.println(p1.valor);
*/

    p0.rotacao = map(p0.valor, 0, 1023, 0, 255);
    p1.rotacao = map(p1.valor, 0, 1023, 0, 255);

    Serial.print("Rotacao p0: ");
    Serial.println(p0.rotacao);
    Serial.print("Rotacao p1: ");
    Serial.println(p1.rotacao);-


    analogWrite(motor_0, p0.rotacao);
    analogWrite(motor_1, p1.rotacao);

    digitalWrite(sentido_motor_0, LOW);
    digitalWrite(sentido_motor_1, HIGH);
  

    delay(10);
}