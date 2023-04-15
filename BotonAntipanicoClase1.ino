int estado = LOW;
int duracion = 250;  //Duración del sonido
int fMin = 2000;     //Frecuencia más baja que queremos emitir
int fMax = 4000;     //Frecuencia más alta que queremos emitir
int i = 0;

void setup() {
  pinMode(8, INPUT_PULLUP);  // boton
  pinMode(13, OUTPUT);       // led
  digitalWrite(13, LOW);     // el led se inicializa apagado
  pinMode(9, OUTPUT);        //pin configurado como salida // buzzer ( parlante)
}

void loop() {
  int boton = digitalRead(8);  // creo la variable boton y guardo el estado del boton
  if (boton == LOW) {          // if
    estado = digitalRead(13);
    digitalWrite(13, !estado);
    delay(1000);
  }
  if (digitalRead(13) == HIGH) {
    alarma();
  }
}
void alarma() {

  //sonido más agudo
  for (i = fMin ; i <= fMax; i++)
    tone(9, i, duracion);
  //sonido más grave
  for (i = fMax ; i >= fMin; i--)
    tone(9, i, duracion);
}
