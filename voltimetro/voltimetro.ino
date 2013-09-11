/*
     Arduino Voltímetro
	
Mario Pérez Esteso
http://www.geekytheory.com
https://www.youtube.com/user/telecoreference

https://twitter.com/geekytheory

Facebook page! Join us with a LIKE!
https://www.facebook.com/geekytheory
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float lectura;
float voltaje=0;
int estado_boton_1=0, estado_boton_2=0,estado_boton_3=0;
int boton_1=6;
int boton_2=7;
int boton_3=8;
void setup() { 
  lcd.begin(16, 2);
  pinMode(boton_1,INPUT);
  pinMode(boton_2,INPUT);
  pinMode(boton_3,INPUT);
  lcd.setCursor(0,0);
  lcd.print("Seleccione boton");
  lcd.setCursor(1,1);
  lcd.print("1.kV 2.V 3.mV");
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(boton_1)==HIGH)
  {
    lcd.clear();
    estado_boton_1=1;
    estado_boton_2=0;
    estado_boton_3=0;
  } else if(digitalRead(boton_2)==HIGH)
  {
    lcd.clear();
    estado_boton_1=0;
    estado_boton_2=1;
    estado_boton_3=0;
  } else if(digitalRead(boton_3)==HIGH)
  {
    lcd.clear();
    estado_boton_1=0;
    estado_boton_2=0;
    estado_boton_3=1;
  }
  if(estado_boton_2==1 && estado_boton_1==0 && estado_boton_3==0)
  { 
   lectura_voltios(1,2);
   lcd.setCursor(0,0);
   lcd.print("Voltaje medido:");
   lcd.setCursor(13, 1);
   lcd.print("(V)");
   delay(500);
  } else if(estado_boton_2==0 && estado_boton_1==1 && estado_boton_3==0)
  { 
   lectura_voltios(1000,0);
   lcd.setCursor(0,0);
   lcd.print("Voltaje medido:");
   lcd.setCursor(12, 1);
   lcd.print("(mV)");
   delay(500);
  } else if(estado_boton_2==0 && estado_boton_1==0 && estado_boton_3==1)
  { 
   lectura_voltios(0.001,4);
   lcd.setCursor(0,0);
   lcd.print("Voltaje medido:");
   lcd.setCursor(12, 1);
   lcd.print("(kV)");
   
  }
}
void lectura_voltios(float unidad, int decimales)
{
  lectura=analogRead(0);
  voltaje = ((5*float(lectura))/1024);
  lcd.setCursor(0, 1);
  lcd.print(float(voltaje)*3*unidad,decimales);
  delay(200);
}
