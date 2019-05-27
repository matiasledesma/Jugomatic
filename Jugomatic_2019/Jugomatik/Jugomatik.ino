#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int relay1 =42, relay2 =43, relay3 =44, relay4 =45;

//Config del Teclado
const byte filas=4;
const byte colum=4;

char botones[filas][colum]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};

byte pinesFila[filas]={22,24,26,28};
byte pinesColu[colum]={30,32,34,36};


Keypad teclado=Keypad( makeKeymap(botones),pinesFila,pinesColu,filas,colum );

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Jugomatik");
  delay(2000);
    
  lcd.clear();
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}


void loop() {
 char key = teclado.getKey();
  
 digitalWrite(Trig,LOW);
 delayMicroseconds(4);
 digitalWrite(Trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(Trig,LOW);
  
 duracion = pulseIn(Echo,HIGH);
 duracion = duracion/2;
 distancia = duracion/29;
  
 delay(500);
 if (distancia > vasovacio){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Coloque el vaso");
  lcd.setCursor(0,1);
  lcd.print("y elija un jugo");
  }

 
 if(distancia <= vasovacio ) { 
      lcd.clear();
      lcd.setCursor(0,0);
      if(key == '1'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("eligio manzana");
        digitalWrite(relay1, LOW);
        delay(5000);
        digitalWrite(relay1, HIGH);
        lcd.clear();
        } 
      if(key == '2'){
        lcd.clear();
        lcd.setCursor(0,0);  
        lcd.print("eligio naranja");
        digitalWrite(relay2, LOW);
        delay(5000);
        digitalWrite(relay2, HIGH);
        lcd.clear();
        }
      if(key == '3'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("eligio pomelo");
        digitalWrite(relay3, LOW);
        delay(5000);
        digitalWrite(relay3, HIGH);
        lcd.clear();
        }
      if(key == 'A'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("eligio limon");
        digitalWrite(relay4, LOW);
        delay(5000);
        digitalWrite(relay4, HIGH);
        lcd.clear();
        }
       } //cierre si el vaso esta vacio
  } //cierre de loop



