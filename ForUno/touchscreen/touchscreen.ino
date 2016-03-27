#include <SoftwareSerial.h>
int key = 0;
int dx = 0;
int dy = 0;
int x = 0;
int y = 0;
int logo = 0;
SoftwareSerial mySerial(10, 11);
void setup() {
  Serial.begin(115200);
  connecting();
  mySerial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pic_show(0);//logo
  for (int i = 0; i < 25; i++) {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
  }
  mySerial.println("pi");
  delay(500);
  mySerial.println("raspberry");
  delay(2000);
  mySerial.println("cat /dev/input/mice");
  delay(1000);
  mySerial.flush();
}

void loop() {
  while (digitalRead(3) > 0) {
    if (mySerial.available() > 0) {
      key = mySerial.read();
      dx = mySerial.read();
      dy = mySerial.read();
      if (dx > 127) {
        dx = dx - 256;
      }
      if (dy > 127) {
        dy = dy - 256;
      }
      x = x + dx;
      y = y + dy;
      //Serial.println(x);
      //Serial.println(y);
      //Serial.println(key);
      fullcircle(x / 4, -y / 3, 5);
    }
  }
  int pici =2;
  while (digitalRead(2) > 0) {
    logo=1;
    if (mySerial.available() > 0) {
      key = mySerial.read();
      dx = mySerial.read();
      dy = mySerial.read();

      pici++;
      if (pici == 6) {
        pici = 2;
      }
      pic_show(pici);
      delay(500);
      mySerial.flush();
    }
  }
  if (logo==1){
    pic_show(6);
    }
}
void pic_show(int n) {
  unsigned char hexdata[9] = {0xEE, 0x31, 0x00, 0x00, 0x00, 0xFF, 0xFC, 0xFF, 0xFF};
  switch (n) {
    case 0: {
        hexdata[3] = 0x00;
        Serial.write(hexdata, 9); break;
      }
    case 1: {
        hexdata[3] = 0x01;
        Serial.write(hexdata, 9); break;
      }
    case 2: {
        hexdata[3] = 0x02;
        Serial.write(hexdata, 9); break;
      }
    case 3: {
        hexdata[3] = 0x03;
        Serial.write(hexdata, 9); break;
      }
    case 4: {
        hexdata[3] = 0x04;
        Serial.write(hexdata, 9); break;
      }
    case 5: {
        hexdata[3] = 0x05;
        Serial.write(hexdata, 9); break;
      }
    case 6: {
        hexdata[3] = 0x06;
        Serial.write(hexdata, 9); break;
      }
    case 7: {
        hexdata[3] = 0x07;
        Serial.write(hexdata, 9); break;
      }
    case 8: {
        hexdata[3] = 0x08;
        Serial.write(hexdata, 9); break;
      }
    case 9: {
        hexdata[3] = 0x09;
        Serial.write(hexdata, 9); break;
      }
    case 10: {
        hexdata[3] = 0x0a;
        Serial.write(hexdata, 9); break;
      }
    case 11: {
        hexdata[3] = 0x0b;
        Serial.write(hexdata, 9); break;
      }
    case 12: {
        hexdata[3] = 0x0c;
        Serial.write(hexdata, 9); break;
      }

  }

}
void connecting(void) {

  unsigned char hexdata[6] = {0xEE, 0x04, 0xFF, 0xFC, 0xFF, 0xFF};
  Serial.write(hexdata, 6);

}
void fullcircle(int x, int y, int r)
{
  x = (char)x;
  y = (char)y;
  r = (char)r;
  unsigned char hexdata[12] = {0xEE, 0x53, 0x00, 0xC8, 0x00, 0xC8, 0x00, 0x05, 0xFF, 0xFC, 0xFF, 0xFF};
  //  sprintf(&hexdata[2],"%2X",x%256);
  //  sprintf(&hexdata[3],"%X",x);
  //  sprintf(&hexdata[4],"%2X",y%256);
  //  sprintf(&hexdata[5],"%X",y);
  //  sprintf(&hexdata[6],"%2X",r%256);
  //  sprintf(&hexdata[7],"%X",r);
  hexdata[3] = x;
  hexdata[5] = y;
  hexdata[7] = r;
  Serial.write(hexdata, 12);
}
