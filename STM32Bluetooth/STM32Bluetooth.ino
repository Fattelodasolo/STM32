#define LED PB15

const char stato0 = 'S';              // S per SPENTO
const char stato1 = 'A';              // A per ACCESO

void setup(){
 Serial2.begin(9600);                // Comunicazione Seriale2 per Bluetooth
 Serial2.println("Avvio Bluetooth:");
 
 pinMode(LED, OUTPUT);
}

void loop(){
   while(Serial2.available() > 0) {     // Mentre la Seriale2 è avviata

      char msg = Serial2.read();        // Leggo dal monitor seriale
               
      if(msg == stato1) {
         digitalWrite(LED, HIGH);        // Accendo LED
         Serial2.println("LED ON");
      }

       if(msg == stato0) {      
         digitalWrite(LED, LOW);        // Spengo LED
         Serial2.println("LED OFF");
      }
         
   }
}
