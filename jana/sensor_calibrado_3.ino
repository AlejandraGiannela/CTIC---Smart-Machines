#include <SPI.h>
#include <SD.h>
#include "HX711.h" 
#define DOUT  3
#define CLK  2
float calibration_factor = -96650; 
HX711 scale(DOUT, CLK);
File myFile;
int i;
unsigned long time1;
int ini;

void setup() {
  Serial.begin(9600);  
  scale.set_scale(-96650);  
  scale.tare();
  
  //Serial.print("Iniciando SD ...");
  if (!SD.begin(4)) {Serial.println("No se pudo inicializar");return;}
  //Serial.println("inicializacion exitosa");  
      
  //Serial.println("Removing example.txt...");
  SD.remove("example.txt");
  if (SD.exists("example.txt")) {Serial.println("example.txt exists.");} 
  else {/*Serial.println("example.txt doesn't exist.");*/}
  //Serial.println("Creating example.txt...");
  myFile = SD.open("example.txt", FILE_WRITE);
  myFile.close();
  if (SD.exists("example.txt")) {/*Serial.println("example.txt exists.");*/} 
  else {Serial.println("example.txt doesn't exist.");}     
  myFile = SD.open("example.txt", FILE_WRITE);
/*
  Serial.print("PIND  - ");
  Serial.println(PIND, BIN);
  Serial.print("DDRD  - ");
  Serial.println(DDRD, BIN);
  Serial.print("PORTD - ");
  Serial.println(PORTD, BIN);*/
  ini=millis();
}
void loop() {
  
  time1 = millis()-ini;
  //if (myFile) { 
        //myFile.print(time1);
        //myFile.print(" ");
        myFile.println(scale.get_units(), 3); 
        //Serial.println(i);                  
        i++;
  //} else {
   // Serial.println("Error al abrir el archivo");
  //}
  if (time1>5000){//Serial.print("Cantidad de datos: ");
                  //Serial.println(i);
                  myFile.close();
                  myFile = SD.open("example.txt");
                  if (myFile) { //Serial.println(" ***** example.txt:");
                                while (myFile.available()) {Serial.write(myFile.read());}
                                //Serial.println("all file");
                                myFile.close();} 
                  else {Serial.println("error opening test.txt");}
                  for (;;) {}}

}
