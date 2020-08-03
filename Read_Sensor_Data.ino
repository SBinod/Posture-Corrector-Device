#include <SPI.h>
#include <SD.h>
int flexs1 = A0;
int flexs2 = A1;
int flexs3 = A3;
INT FLEXS4 = A4;
int data = 0;
int chipSelect=4; 
File myFile;

void setup() {

Serial.begin(9600); // Open serial communications and wait for port to open

myFile.begin();

pinMode(10,OUTPUT);
pinMode(flexs1, INPUT);   

SD.begin(chipSelect);
}

void loop()
{
data1=analogRead(flexs1);
data2=analogRead(flexs2);
data3=analogRead(flexs3);
data4=analogRead(flexs4);
Serial.println(data1);
Serial.println(data2);
Serial.println(data3);
Serial.println(data4);
delay(1000);

myFile = SD.open("Data.txt", FILE_WRITE);

if (myFile) 
{
   Serial.print("The reading is: ");
   Serial.println(data1,data2,data3,data4);
   Serial.print("Writing to the file..."); 

   myFile.println(data1,data2,data3,data4);
   myFile.close();
   Serial.println("Done.");
}

else 
{
   Serial.println("Error opening the file...");
}
  
}