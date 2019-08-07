#include <Arduino.h>

//VARIABLES DE TRANSMISION DE MENSAJES
String mensaje = "";
String Temp = "";

//MESSAGE
String message = "HOLA"; // Replace instead for your message
int sizeOfMessage = message.length();

void setup() {
  Serial.begin(9600);

}

void loop() {
  
   while(Serial.available() > 0){
      //STEP 1: Reading a Byte and saving the Byte in other place
      char recibido = Serial.read();
      //STEP 2: Concatenate Byte with Byte
      mensaje = Temp + recibido;
      //STEP 3: Saving the complete message in other place
      Temp = mensaje;
      //STEP 4: Preparing the variables, for the other Byte (Cleaning)
      mensaje = "";
      //STEP 5: Wait 50 Milli Seconds ITS NECESSARY
      delay(50);
      //STEP 6: Quit blank space and car return
          Temp.trim();
   }
   

      if(Temp.length() == sizeOfMessage){
        
          if(Temp.equals(message)){
              Serial.println("CORRECT");
              
            }else{
              Serial.println("ERROR");
              Temp = "";
        }
        Temp = "";
      }//FIN SIZE OF THE MESSAGE
      else{
//        Serial.println("ERROR");
          Temp = "";
      }

}//fin loop