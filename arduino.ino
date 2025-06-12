const int C4 = 9;
const int D4 = 8;
const int E4 = 7;
const int F4 = 6;
const int G4 = 5;
const int A_4 = 4;
const int B4 = 3;
const int C5 = 2;
const int pinoBuzzer = 10;
const int chaveLED = 11;
const int chaveSom = 12;
const int energiaLED = 13;

bool mandaLED = true;
bool estadoAtualLED = true;
bool estadoAnteriorLED = true;
bool mandaSom = true;
bool estadoAtualSom = true;
bool estadoAnteriorSom = true;

int notaAtual;
int notaTocada = 0;

void ligaLed() {
  if (mandaLED) {
    digitalWrite(energiaLED, HIGH);
    Serial.print(chaveLED); // LED ligado
  } else {
    digitalWrite(energiaLED, LOW);
    Serial.print(22); // LED desligado
  }
}

void atualizaNota() {
  int leitura = Serial.read();

  if (leitura == chaveLED) {
    mandaLED = !mandaLED;
  } else if (leitura == chaveSom) {
    mandaSom = !mandaSom;
  } else if (leitura >= C5 && leitura <= C4) {
    notaAtual = leitura;
  }
}

void mandaNota() {
  Serial.print(notaTocada);
}

void registraNota() {
  if (digitalRead(C4)) {
    notaTocada = C4;
    mandaNota();
  } else if (digitalRead(D4)) {
    notaTocada = D4;
    mandaNota();
  } else if (digitalRead(E4)) {
    notaTocada = E4;
    mandaNota();
  } else if (digitalRead(F4)) {
    notaTocada = F4;
    mandaNota();
  } else if (digitalRead(G4)) {
    notaTocada = G4;
    mandaNota();
  } else if (digitalRead(A_4)) {
    notaTocada = A_4;
    mandaNota();
  } else if (digitalRead(B4)) {
    //notaTocada = B4;
    mandaNota();
  } else if (digitalRead(C5)) {
    notaTocada = C5;
    mandaNota();
  } else {
    notaTocada = 0;
  }
}

void mudouLED() {
  estadoAtualLED = digitalRead(chaveLED);
  if (estadoAtualLED != estadoAnteriorLED) {
    mandaLED = !mandaLED;
  }
  estadoAnteriorLED = estadoAtualLED;
}

void mudouSom() {
  estadoAtualSom = digitalRead(chaveSom);
  if (estadoAtualSom != estadoAnteriorSom) {
    mandaSom = !mandaSom;
    Serial.print(24);
  }
  estadoAnteriorSom = estadoAtualSom;
}

void toca() {
  if(mandaSom) {
    if (notaTocada == C4) {
      analogWrite(pinoBuzzer, 262);
    } else if (notaTocada == D4) {
      analogWrite(pinoBuzzer, 294);
    } else if (notaTocada == E4) {
      analogWrite(pinoBuzzer, 330);
    } else if (notaTocada == F4) {
      analogWrite(pinoBuzzer, 349);
    } else if (notaTocada == G4) {
      analogWrite(pinoBuzzer, 392);
    } else if (notaTocada == A_4) {
      analogWrite(pinoBuzzer, 440);
    } else if (notaTocada == B4) {
      analogWrite(pinoBuzzer, 494);
    } else if (notaTocada == C5) {
      analogWrite(pinoBuzzer, 523);
    }
    delay(1000);
    analogWrite(pinoBuzzer, 0);
  }
}

void setup() {
  pinMode(C4, INPUT);
  pinMode(D4, INPUT);
  pinMode(E4, INPUT);
  pinMode(F4, INPUT);
  pinMode(G4, INPUT);
  pinMode(A_4, INPUT);
  pinMode(B4, INPUT);
  pinMode(C5, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(chaveLED, INPUT);
  pinMode(chaveSom, INPUT);
  pinMode(energiaLED, OUTPUT);

  digitalWrite(energiaLED, HIGH);

  Serial.begin(9600);
}

void loop() {
  //ligaLed();
  //atualizaNota();
  registraNota();
  toca();
  //mudouLED();
  //mudouSom();
}