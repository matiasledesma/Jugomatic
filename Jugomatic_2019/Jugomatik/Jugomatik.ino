#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(22, 24, 37, 35, 33, 31);

int led1 =50, led2 =51, led3 =52, led4 =53, Trig, duracion, Echo, distancia, vasovacio; /*Agregue Trig, duracion, Echo, distancia, vasovacio; PORQUE NO ESTABAN DECLARADAS*/

/*SENSOR*/
const int trigPin =45;
const int echoPin =43;
long duration;
int distanceCm;
/*SENSOR*/

//Config del Teclado
const byte filas=4;
const byte colum=4;

char botones[filas][colum]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};

byte pinesFila[filas]={2,3,4,5};
byte pinesColu[colum]={7,6,9,8};


Keypad teclado=Keypad( makeKeymap(botones),pinesFila,pinesColu,filas,colum );

void setup() {
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(1,0);
  lcd.print("Jugomatik 2.0");
  lcd.setCursor(0,0);
  delay(2000);
    
  lcd.clear();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

}


void loop() {
char key = teclado.getKey();


 digitalWrite(trigPin,LOW);
 delayMicroseconds(4);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
  
 duration = pulseIn(echoPin,HIGH);
 distanceCm = duration*0.034/2;
 
 if (distanceCm > 13){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Coloque el vaso");
  lcd.setCursor(0,1);
  lcd.print("y elija un jugo");
  delay(2000);
  lcd.clear();
  }


 if(distanceCm < 13 ) {

if (distanceCm < 9) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Coloque un");
  lcd.setCursor(0,1);
  lcd.print("vaso vacio");
  delay(2000);
  lcd.clear();  
  }
 
    
    lcd.setCursor(1,0);
    lcd.print("Seleccione un");
    lcd.setCursor(6,1);
    lcd.print("Jugo");
    if (key != NO_KEY){ 
      lcd.clear();
      lcd.setCursor(0,0);
      if(key == '1'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Eligio manzana");
        delay(2000);
        digitalWrite(led1, HIGH);
        lcd.clear();
        lcd.setCursor(0,0);  
        lcd.print("Sirviendo...");
        delay(5000);
        digitalWrite(led1, LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Retire el vaso");
        delay(3000);
        lcd.clear();
        } 
      if(key == '2'){
        lcd.clear();
        lcd.setCursor(0,0);  
        lcd.print("Eligio naranja");
        delay(2000);
        digitalWrite(led2, HIGH);
        lcd.clear();
        lcd.setCursor(0,0);  
        lcd.print("Sirviendo...");
        delay(5000);
        digitalWrite(led2, LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Retire el vaso");
        delay(3000);
        lcd.clear();
        }
      if(key == '3'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Eligio pomelo");
        delay(2000);
        digitalWrite(led3, HIGH);
        lcd.clear();
        lcd.setCursor(0,0);  
        lcd.print("Sirviendo...");
        delay(5000);
        digitalWrite(led3, LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Retire el vaso");
        delay(3000);
        lcd.clear();
        }
      if(key == 'A'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Eligio limon");
        delay(2000);
        digitalWrite(led4, HIGH);
        lcd.clear();
        lcd.setCursor(0,0);  
        lcd.print("Sirviendo...");
        delay(5000);
        digitalWrite(led4, LOW);
        lcd.clear();
        }
    }
       } //cierre si el vaso esta vacio
  } //cierre de loop



