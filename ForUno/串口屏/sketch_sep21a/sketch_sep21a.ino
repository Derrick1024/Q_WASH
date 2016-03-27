void setup() {
  Serial.begin(115200);
  connecting();

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
  x = (char)y;
  x = (char)y;
  unsigned char hexdata[12] = {0xEE, 0x53, 0x00, 0xC8, 0x00, 0xC8, 0x00, 0x05, 0xFF, 0xFC, 0xFF, 0xFF};
  //  sprintf(&hexdata[2],"%2X",x%256);
  //  sprintf(&hexdata[3],"%X",x);
  //  sprintf(&hexdata[4],"%2X",y%256);
  //  sprintf(&hexdata[5],"%X",y);
  //  sprintf(&hexdata[6],"%2X",r%256);
  //  sprintf(&hexdata[7],"%X",r);
  hexdata[3]=x;
  hexdata[5]=y;
  hexdata[7]=r;
  Serial.write(hexdata, 12);
}

void loop() {
  pic_show(3);
  for(int i=0;i<8;i++)
  {
     pic_show(i);
     delay(3000);
  }
  //fullcircle(10, 10, 5);

}

