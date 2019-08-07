#include <Arduino.h>

String mensaje = "";

int verificado = 0;
String Temp = "";
String om = "";

void setup() {
  Serial.begin(9600);

}

void loop() {
  
   while(Serial.available() > 0){
    
    char recibido = Serial.read();
    om = recibido;
    mensaje = Temp + om;
    Temp = mensaje;
    mensaje = "";
    Serial.println(Temp + " con tamaño de: " + Temp.length());
    delay(50);
   }
   if(Temp.length() == 5){
    Serial.println("ENTRO");
    Temp = "";
   }

}//fin loop