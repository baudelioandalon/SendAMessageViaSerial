#include <Arduino.h>

//VARIABLES DE TRANSMISION DE MENSAJES
String mensaje = "";
String Temp = "";
String mensaje2 = "";
String Temp2 = "";

//MESSAGE
String message = "INICIO"; // Replace instead for your message
int sizeOfMessage = message.length();

String message2 = "000000"; // Replace instead for your message
int sizeOfMessage2 = message2.length();

//CANTIDAD DE MOVIMIENTOS
//MOVIMIENTO 1 - MINIMO 0 - MAXIMO 99
//MOVIMIENTO 2 - MINIMO 0 - MAXIMO 99
//MOVIMIENTO 3 - MINIMO 0 - MAXIMO 99

int Mov1 = 0;
int Mov2 = 0;
int Mov3 = 0;

int charecito = 0;

// String INICIO

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
              Serial.println("Esperando...");
              while(10>0){//inicio while loop
              while(10>0){//inicio while loop2
              while(Serial.available() > 0){
                  //STEP 1: Reading a Byte and saving the Byte in other place
                  char recibido2 = Serial.read();
                  //STEP 2: Concatenate Byte with Byte
                  mensaje2 = Temp2 + recibido2;
                  //STEP 3: Saving the complete message in other place
                  Temp2 = mensaje2;
                  //STEP 4: Preparing the variables, for the other Byte (Cleaning)
                  mensaje2 = "";
                  //STEP 5: Wait 50 Milli Seconds ITS NECESSARY
                  delay(50);
                  //STEP 6: Quit blank space and car return
                  Temp2.trim();
                }
                if(Temp2.length() == sizeOfMessage2){
                  break;
                }
                else{
                  Temp2 = "";
                }
                }//fin while loop2

                if(Temp2.length() == sizeOfMessage2){
                  
                  Serial.println("MOVIMIENTO 1: " + Temp2.substring(0,2));
                  Serial.println("MOVIMIENTO 2: " + Temp2.substring(2,4));
                  Serial.println("MOVIMIENTO 3: " + Temp2.substring(4,6));

                  if(isNumeric(Temp2.substring(0,2))  && 
                  isNumeric(Temp2.substring(2,4)) && 
                  isNumeric(Temp2.substring(4,6))){
                    //CONTINUAR
                    Serial.println("CONTINUAR");
                    break;
                  }else{
                    Serial.println("NO NUMERO");
                    
                  }
                  Temp2 = "";
                }
                else{
                  Serial.println("Error, reenviar cantidad de movimientos");
                }

              }//fin while loop
              
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


boolean isNumeric(String str) {
    unsigned int stringLength = str.length();
 
    if (stringLength == 0) {
        return false;
    }
    boolean seenDecimal = false;
 
    for(unsigned int i = 0; i < stringLength; ++i) {
        if (isDigit(str.charAt(i))) {
            continue;
        }
        if (str.charAt(i) == '.') {
            if (seenDecimal) {
                return false;
            }
            seenDecimal = true;
            continue;
        }
        return false;
    }
    return true;
}//fin isNumeric