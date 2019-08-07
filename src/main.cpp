#include <Arduino.h>

String mensaje = "";
int verificado = 0;
String Temp = "";

void setup() {
  Serial.begin(9600);

}

void loop() {
  
   while(Serial.available() > 0){
    char recibido = Serial.read();
    mensaje = Temp + recibido;
    Temp = mensaje;
    mensaje = "";
    delay(50);
   }
   if(Temp.length() == 5){
//    Serial.println(Temp);

     Temp.trim();
    if(Temp.equals("HOLA")){
      Serial.println("ENTRO");
    }else{
      Serial.println("ERROR");
      Temp = "";
    }
    Temp = "";
   }
   else{
    Temp = "";
   }

}//fin loop