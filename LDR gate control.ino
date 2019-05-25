#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include <Servo.h>
#define LDR A0
#define LED D7
#define SSD1306_LCDHEIGHT 64
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
int i=0;
Servo myservo;



void setup() {
 
 myservo.attach(D3);
 pinMode(LED,OUTPUT);
 pinMode(LDR,OUTPUT);
 myservo.write(0);
 display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
   display.clearDisplay();

 
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldr=analogRead(A0);
int pos;
if(ldr<=600  ){
myservo.write(90);
  digitalWrite(LED,HIGH);
  
if(i==0){
 display.clearDisplay(); 
 i++;  
}
// display a line of text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,10);
  display.print("Gate is open");
  // update display with all of the above graphics
  display.display();
  
}
 
if(ldr>600   ){
  myservo.write(0);
  
if(i==1){
  display.clearDisplay();
  i--;
}
 digitalWrite(LED,LOW);
  
  
// display a line of text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,10);
  display.print("Gate is closed");
  // update display with all of the above graphics
  display.display();}
}
