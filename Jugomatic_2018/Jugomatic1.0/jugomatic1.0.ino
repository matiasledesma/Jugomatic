#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <Ethernet.h>
#include <Keypad.h>
#include <SoftwareSerial.h>
#include <DistanciaUltrasonidos.h>
#include <Wire.h>
#define XADRESS 0x3F

// Introduzca una dirección MAC y la dirección IP para el controlador
//byte mac[] = { 
//0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//IPAddress ip(192,168,0,50);  
//EthernetClient client;
 
//char serverC[] = "192.168.0.30";  // direccion IP del web server

//char dataLocationC[] = "/servidor.php?var="; // pagina php que conecta con la base debe estar en el localhost

LiquidCrystal_I2C lcd(XADRESS,16,2);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns modificar esto si es de 3 columnas
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};
byte rowPins[ROWS] = {28, 26, 24, 22}; // ( 1 2 3 4 )connect to the row pinouts of the keypad
byte colPins[COLS] = {29, 27, 25, 23}; // ( 5 6 7 8 )connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int Trig =39;
int Echo =38;

int ledR1 = 40;
int ledR2 = 41;
int ledR3 = 42;
int ledR4 = 43;

int senJ1 = 46; 
int senJ2 = 47;
int senJ3 = 48;
int senJ4 = 49;

int tiempoesperas=7000;

int vasosin = 19;  // en cm
int vasovacio = 14;
int vasolleno = 8;


long duracion;
long distancia;
 


void setup() {
  Serial.begin(9600); while(!Serial);
  pinMode(ledR1, OUTPUT);
  pinMode(ledR2, OUTPUT);
  pinMode(ledR3, OUTPUT);
  pinMode(ledR4, OUTPUT);

  digitalWrite(ledR1,HIGH);
  digitalWrite(ledR2,HIGH);
  digitalWrite(ledR3,HIGH);
  digitalWrite(ledR4,HIGH);
  
  pinMode(senJ1, INPUT);
  pinMode(senJ2, INPUT);
  pinMode(senJ3, INPUT);
  pinMode(senJ4, INPUT);

 
  delay(1000);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Bienvenido a  "); 
  lcd.setCursor(0,1);
  lcd.print("Jugo Matic 1.0"); 
  delay(3000);

 

  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  
}


void loop() {

//lcd.clear();
//lcd.setCursor(0,1);

//if (digitalRead(senJ1)!=LOW )
//{  
  
  char key = keypad.getKey();

  
  digitalWrite(Trig,LOW);
  delayMicroseconds(4);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  
  duracion = pulseIn(Echo,HIGH);
  duracion = duracion/2;
  distancia = duracion/29;
  
  Serial.print(distancia);
  Serial.println(" cm");
  
  delay(500);
 
  if (distancia > vasovacio)
  {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Coloque el vaso"); 
      lcd.setCursor(0,1);
      lcd.print("y elija un Jugo"); 
  }

  
  if(distancia <= vasovacio ) //Si el vaso está a menos de 13 cm
  {
  
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(" Elija un Jugo"); 

    if (key != NO_KEY){
      
      Serial.println(key);
      
      if (key == '1' && digitalRead(senJ1) != LOW){
        Serial.println("Jugo de naranja - sirviendose");
        digitalWrite(ledR1,LOW);
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Jugo de Naranja");
        lcd.setCursor(0,1);
        lcd.print("** sirviendo **");
     
       
        delay (tiempoesperas);
        digitalWrite(ledR1,HIGH);
        
     
      }
      
      if (key == '2' && digitalRead(senJ2) != LOW ){
       Serial.println("Jugo de manzana - sirviendose");
        digitalWrite(ledR2,LOW);
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Jugo de Manzana");
        lcd.setCursor(0,1);
        lcd.print("** sirviendo **");
     
       
        delay (tiempoesperas);
        digitalWrite(ledR2,HIGH);
        
      }
      if (key == '3' && digitalRead(senJ3) != LOW){
        Serial.println("Jugo de Pomelo - sirviendose");
        digitalWrite(ledR3,LOW);
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" Jugo de Pomelo ");
        lcd.setCursor(0,1);
        lcd.print("** sirviendo **");
     
       
        delay (tiempoesperas);
        digitalWrite(ledR3,HIGH);
       
        
      }
      if (key == '4' && digitalRead(senJ4) != LOW){
        Serial.println("Jugo de manzana verde - sirviendose");
        digitalWrite(ledR4,LOW);
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" Jugo de  Manzana"); 
        lcd.setCursor(0,1);
        lcd.print("** sirviendo **");
     
       
        delay (tiempoesperas);
        digitalWrite(ledR4,HIGH);
      }



   if (key == '*'){
        Serial.println("VACIANDO TODOS LOS JUGOS");
        digitalWrite(ledR1,LOW);
        digitalWrite(ledR2,LOW);
        digitalWrite(ledR3,LOW);
        digitalWrite(ledR4,LOW);
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" **VACIAR JUGOS**");
        lcd.setCursor(0,1);
        lcd.print("** WARNING **");
     
       
        delay (tiempoesperas*5);
       
        digitalWrite(ledR1,HIGH);
        digitalWrite(ledR2,HIGH);
        digitalWrite(ledR3,HIGH);
        digitalWrite(ledR4,HIGH);
        
     
      }

      
      
       while(distancia <= vasovacio)
       {
            Serial.println("Esperando que retire el vaso");
            digitalWrite(Trig,LOW);
            delayMicroseconds(4);
            digitalWrite(Trig,HIGH);
            delayMicroseconds(10);
            digitalWrite(Trig,LOW);
  
            duracion = pulseIn(Echo,HIGH);
            duracion = duracion/2;
            distancia = duracion/29;
            lcd.clear();
            lcd.print("*Retire su vaso*");
            delay(1000);
       }

      Serial.println("** GRACIAS POR UTILIZAR JUGOMATIC 1.0 **");
      lcd.clear();
      lcd.print("*** GRACIAS ***");
      delay(5000);
     
    } // fin del if tecla NO pulsada
    
 } // fin del if de vaso presente


//} 
// fin del if de sensores de liquido
//else
//{
 
  //lcd.setCursor(0,1);
 // lcd.println("NO HAY JUGO 1");
 // delay(1000);
//}  
delay(500);
  
} // fin del while del loop
