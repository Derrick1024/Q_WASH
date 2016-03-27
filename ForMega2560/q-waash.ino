//Q-WASH 20150815 成都
//步进 1：x 2：空 3，4：z
int null_stepper_dir = 14;
int null_stepper_step = 5;
int x_stepper_dir = 15;
int x_stepper_step = 4;
int y1_stepper_dir = 16;
int y1_stepper_step = 3;
int y2_stepper_dir = 17;
int y2_stepper_step = 2;
int stepper1_enable = 18;
int stepper2_enable = 19;
//舵机 1：AC1 2：AC2
//servo1 = 7;
//servo2 = 6;
//强电继电器 4路
int switch1 = 20;
int switch2 = 21;
int switch3 = 22;
int switch4 = 23;
//强电继电器 4路
int switch5 = 24;
int switch6 = 25;
int switch7 = 26;
int switch8 = 27;
//L298N 4路
int l298n1_1 = 33;
int l298n1_2 = 34;
int l298n1_3 = 35;
int l298n1_4 = 36;
int l298n2_1 = 37;
int l298n2_2 = 38;
int l298n2_3 = 39;
int l298n2_4 = 40;
int l298n3_1 = 46;
int l298n3_2 = 47;
int l298n3_3 = 48;
int l298n3_4 = 49;
int l298n4_1 = 50;
int l298n4_2 = 51;
int l298n4_3 = 52;
int l298n4_4 = 53;
//A0:R A1:G A2:B
/* A6 x右
 * A7 x左
 * A8 y下
 * A9 y上
 * A10 门开
 * A11 门关
 * A12 夹具关
 * A13 夹具开
 * A14 按钮
*/

//常量
int z_pos = 0;
int program = 0;
//库
#include <AccelStepper.h>
#include <Servo.h>
Servo servo1;
Servo servo2;
AccelStepper stepper_x(1, x_stepper_step, x_stepper_dir);
AccelStepper stepper_y1(1, y1_stepper_step, y1_stepper_dir);
AccelStepper stepper_y2(1, y2_stepper_step, y2_stepper_dir);
void setup() {
  Serial1.begin(9600);
  servo1.attach(7);
  servo2.attach(6);
  servo1.write(0);
  servo2.write(0);
  delay(1000);
  servo1.detach();
  servo2.detach();
  pinMode (stepper1_enable, OUTPUT);
  pinMode (stepper2_enable, OUTPUT);
  pinMode (switch1, OUTPUT);
  pinMode (switch2, OUTPUT);
  pinMode (switch3, OUTPUT);
  pinMode (switch4, OUTPUT);
  pinMode (switch5, OUTPUT);
  pinMode (switch6, OUTPUT);
  pinMode (switch7, OUTPUT);
  pinMode (switch8, OUTPUT);
  pinMode (l298n1_1, OUTPUT);
  pinMode (l298n1_2, OUTPUT);
  pinMode (l298n1_3, OUTPUT);
  pinMode (l298n1_4, OUTPUT);
  pinMode (l298n2_1, OUTPUT);
  pinMode (l298n2_2, OUTPUT);
  pinMode (l298n2_3, OUTPUT);
  pinMode (l298n2_4, OUTPUT);
  pinMode (l298n3_1, OUTPUT);
  pinMode (l298n3_2, OUTPUT);
  pinMode (l298n3_3, OUTPUT);
  pinMode (l298n3_4, OUTPUT);
  pinMode (l298n4_1, OUTPUT);
  pinMode (l298n4_2, OUTPUT);
  pinMode (l298n4_3, OUTPUT);
  pinMode (l298n4_4, OUTPUT);
  pinMode (A0, OUTPUT);
  pinMode (A1, OUTPUT);
  pinMode (A2, OUTPUT);
  analogWrite(A0, 255); //LED
  analogWrite(A1, 255);
  analogWrite(A2, 255);
  digitalWrite (stepper1_enable , 1);  //步进默认关
  digitalWrite (stepper2_enable , 1);
  digitalWrite (switch1 , 1); //继电器默认关
  digitalWrite (switch2 , 1);
  digitalWrite (switch3 , 1);
  digitalWrite (switch4 , 1);
  digitalWrite (switch5 , 1);
  digitalWrite (switch6 , 1);
  digitalWrite (switch7 , 1);
  digitalWrite (switch8 , 1);
  digitalWrite (l298n1_1 , 0);
  digitalWrite (l298n1_2 , 0);
  digitalWrite (l298n1_3 , 0);
  digitalWrite (l298n1_4 , 0);
  digitalWrite (l298n2_1 , 0);
  digitalWrite (l298n2_2 , 0);
  digitalWrite (l298n2_3 , 0);
  digitalWrite (l298n2_4 , 0);
  digitalWrite (l298n3_1 , 0);
  digitalWrite (l298n3_2 , 0);
  digitalWrite (l298n3_3 , 0);
  digitalWrite (l298n3_4 , 0);
  digitalWrite (l298n4_1 , 0);
  digitalWrite (l298n4_2 , 0);
  digitalWrite (l298n4_3 , 0);
  digitalWrite (l298n4_4 , 0);
  //归零位置
  Serial1.println("0");
  analogWrite(A0, 0); //开始：白 1s
  analogWrite(A1, 0);
  analogWrite(A2, 0);
  delay(1000);
  analogWrite(A0, 0);
  analogWrite(A1, 255);
  analogWrite(A2, 255);
  digitalWrite (l298n2_1 , 1);
  digitalWrite (l298n2_2 , 0);
  stepper_x.setMaxSpeed(200);
  stepper_y1.setMaxSpeed(800);
  stepper_y2.setMaxSpeed(800);
  stepper_y1.setAcceleration(1000000);
  stepper_y2.setAcceleration(1000000);
  stepper_x.setAcceleration(1000000);
  digitalWrite (stepper1_enable , 0);
  digitalWrite (stepper2_enable , 0);
  //归零x
    Serial1.println("1");
  stepper_x.moveTo(-10000);
  while (analogRead(A6) < 900) {
    stepper_x.run();
  }
  stepper_x.setCurrentPosition(0);
  analogWrite(A0, 255);
  analogWrite(A1, 0);
  delay(500);
  analogWrite(A1, 255);

  //归零y
  Serial1.println("2");
  analogWrite(A0, 0);
  analogWrite(A1, 255);
  analogWrite(A2, 255);
  stepper_y1.moveTo(-100000);
  stepper_y2.moveTo(-100000);
  while (analogRead(A8) < 900) {
    stepper_y1.run();
    stepper_y2.run();
  }
  stepper_y1.setCurrentPosition(-11000);
  stepper_y2.setCurrentPosition(-11000);
  analogWrite(A0, 255);
  analogWrite(A1, 0);
  delay(500);
  analogWrite(A1, 255);
  digitalWrite (stepper1_enable , 1);//步进关
  digitalWrite (stepper2_enable , 1);
  digitalWrite (l298n2_1 , 0);
  digitalWrite (l298n2_2 , 0);
    Serial1.println("3");
  analogWrite(A0, 0);//夹紧归位：紫
  analogWrite(A1, 255);
  analogWrite(A2, 0);
  while (analogRead(A12) < 300) {
    digitalWrite (l298n1_1 , 0);//夹紧
    digitalWrite (l298n1_2 , 1);
    digitalWrite (l298n1_3 , 0);
    digitalWrite (l298n1_4 , 1);
  }
  digitalWrite (l298n1_1 , 0);
  digitalWrite (l298n1_2 , 0);
  digitalWrite (l298n1_3 , 0);
  digitalWrite (l298n1_4 , 0);
  analogWrite(A0, 255);//到位，青
  analogWrite(A1, 0);
  analogWrite(A2, 0);
    Serial1.println("4");
  digitalWrite (l298n1_1 , 1);//夹松
  digitalWrite (l298n1_2 , 0);
  digitalWrite (l298n1_3 , 1);
  digitalWrite (l298n1_4 , 0);
  delay(12000);
  digitalWrite (l298n1_1 , 0);
  digitalWrite (l298n1_2 , 0);
  digitalWrite (l298n1_3 , 0);
  digitalWrite (l298n1_4 , 0);
  analogWrite(A0, 0); //完成：白 1s
  analogWrite(A1, 0);
  analogWrite(A2, 0);
    Serial1.println("5");
}

void loop() {
  /* 0:待机
   * 1:开门
   * 2：等待关门
   * 3：关门
   * 4：位置初始化
   * 11：夹具工作
   * 5：用电器初始化
   * 6：洗衣程序
   * 7：开夹具
   * 8：开门
   * 9：等待关门
   * 10：关门
   */
  if (program == 0) {
      Serial1.println("10");
    analogWrite(A0, 0);
    analogWrite(A1, 0);
    analogWrite(A2, 0);
    if (analogRead(A14) > 800) {
      program = 1;
      analogWrite(A0, 255);//按键：绿
      analogWrite(A1, 0);
      analogWrite(A2, 255);
      delay(1000);
    }
  }
  if (program == 1) {
    analogWrite(A0, 0);//移动：黄
    analogWrite(A1, 0);
    analogWrite(A2, 255);
    digitalWrite (switch5 , 0);
    digitalWrite (l298n4_1 , 1);//开门
    digitalWrite (l298n4_2 , 1);
    digitalWrite (l298n4_3 , 0);
    digitalWrite (l298n4_4 , 0);
    if (analogRead(A10) > 800) {
      //delay(700);
      digitalWrite (l298n4_1 , 0);
      digitalWrite (l298n4_2 , 0);
      digitalWrite (l298n4_3 , 0);
      digitalWrite (l298n4_4 , 0);
      analogWrite(A0, 0);//到位，红
      analogWrite(A1, 255);
      analogWrite(A2, 255);
      program = 2;
    }
  }
  if (program == 2) {
    if (analogRead(A14) > 800) {
      program = 3;
      analogWrite(A0, 255);//按键：绿
      analogWrite(A1, 0);
      analogWrite(A2, 255);
      delay(1000);
    }
  }
  if (program == 3) {
    analogWrite(A0, 0);//移动：黄
    analogWrite(A1, 0);
    analogWrite(A2, 255);
    digitalWrite (l298n4_1 , 0);//关门
    digitalWrite (l298n4_2 , 0);
    digitalWrite (l298n4_3 , 1);
    digitalWrite (l298n4_4 , 1);
    if (analogRead(A11) > 800) {
      delay(50);
      digitalWrite (l298n4_1 , 0);
      digitalWrite (l298n4_2 , 0);
      digitalWrite (l298n4_3 , 0);
      digitalWrite (l298n4_4 , 0);
      program = 4;
      analogWrite(A0, 255);//到位，蓝
      analogWrite(A1, 255);
      analogWrite(A2, 0);
    }
  }
  if (program == 4) {
    digitalWrite (l298n2_1 , 1);
    digitalWrite (l298n2_2 , 0);
    stepper_x.setMaxSpeed(500);
    stepper_y1.setMaxSpeed(800);
    stepper_y2.setMaxSpeed(800);
    stepper_y1.setAcceleration(1000000);
    stepper_y2.setAcceleration(1000000);
    stepper_x.setAcceleration(1000000);
    digitalWrite (stepper1_enable , 0);
    digitalWrite (stepper2_enable , 0);
    stepper_y1.moveTo(100);
    stepper_y2.moveTo(100);
    while (stepper_y1.currentPosition() != 0) {
      stepper_y1.run();
      stepper_y2.run();
    }
    program = 11;
  }
  if (program == 11) {
    analogWrite(A0, 0);//夹紧：紫
    analogWrite(A1, 255);
    analogWrite(A2, 0);
    digitalWrite (l298n1_1 , 0);//夹紧
    digitalWrite (l298n1_2 , 1);
    digitalWrite (l298n1_3 , 0);
    digitalWrite (l298n1_4 , 1);
    if (analogRead(A12) > 800) {
      digitalWrite (l298n1_1 , 1);//夹松
      digitalWrite (l298n1_2 , 0);
      digitalWrite (l298n1_3 , 1);
      digitalWrite (l298n1_4 , 0);
      delay(1000);
      digitalWrite (l298n1_1 , 0);
      digitalWrite (l298n1_2 , 0);
      digitalWrite (l298n1_3 , 0);
      digitalWrite (l298n1_4 , 0);
      program = 5;
      analogWrite(A0, 255);//到位，青
      analogWrite(A1, 0);
      analogWrite(A2, 0);
    }
  }
  if (program == 5) {
    servo1.attach(7);
    servo2.attach(6);
    servo1.write(120);
    servo2.write(120);
    delay(1000);
    servo1.detach();
    servo2.detach();
    analogWrite(A0, 0);//继电器开，红
    analogWrite(A1, 255);
    analogWrite(A2, 255);
    digitalWrite (switch1 , 1); //继电器开
    digitalWrite (switch2 , 0);
    digitalWrite (switch3 , 1);
    digitalWrite (switch4 , 0);
    digitalWrite (switch7 , 0);
    digitalWrite (switch6 , 0);
    delay(1000);
    digitalWrite (switch6 , 1);
    delay(3000);
    servo1.attach(7);
    servo2.attach(6);
    servo1.write(70);
    servo2.write(70);
    delay(1000);
    servo1.detach();
    servo2.detach();
    analogWrite(A0, 255);//强电初始完成，绿
    analogWrite(A1, 0);
    analogWrite(A2, 255);
    program = 6;
  }
  if (program == 6) {
    z_pos = 0;
    for (int i = 1; i < 8; i++) {
      stepper_x.setMaxSpeed(600);
      stepper_y1.setMaxSpeed(800);
      stepper_y2.setMaxSpeed(800);
      stepper_y1.setAcceleration(1000000);
      stepper_y2.setAcceleration(1000000);
      stepper_x.setAcceleration(1000000);
      stepper_y1.moveTo(-11000);
      stepper_y2.moveTo(-11000);
      while (stepper_y1.currentPosition() != z_pos) {
        stepper_y1.run();
        stepper_y2.run();
      }
      z_pos = z_pos - 600;
      stepper_x.runToNewPosition(930);
      delay(100);
      while (stepper_y1.currentPosition() != z_pos) {
        stepper_y1.run();
        stepper_y2.run();
      }
      z_pos = z_pos - 600;
      stepper_x.runToNewPosition(30);
      delay(100);
    }
    digitalWrite (switch1 , 1);
    digitalWrite (switch3 , 1);
    digitalWrite (switch6 , 0);//电磁阀
    delay(1000);
    digitalWrite (switch6 , 1);
    //for (int j = 1; j < 3; j++) {  //风干
      analogWrite(A0, 0);
      analogWrite(A1, 0);
      analogWrite(A2, 0);
    digitalWrite (l298n1_1 , 1);//夹松
    digitalWrite (l298n1_2 , 0);
    digitalWrite (l298n1_3 , 1);
    digitalWrite (l298n1_4 , 0);
    delay(12000);
    digitalWrite (l298n1_1 , 0);
    digitalWrite (l298n1_2 , 0);
    digitalWrite (l298n1_3 , 0);
    digitalWrite (l298n1_4 , 0);
    stepper_x.setMaxSpeed(500);
    stepper_y1.setMaxSpeed(800);
    stepper_y2.setMaxSpeed(800);
    stepper_y1.setAcceleration(1000000);
    stepper_y2.setAcceleration(1000000);
    stepper_x.setAcceleration(1000000);
    digitalWrite (stepper1_enable , 0);
    digitalWrite (stepper2_enable , 0);
    stepper_y1.moveTo(100);
    stepper_y2.moveTo(100);
    while (stepper_y1.currentPosition() != 0) {
      stepper_y1.run();
      stepper_y2.run();
    }
    stepper_x.setMaxSpeed(100);
    stepper_y1.setMaxSpeed(500);
    stepper_y2.setMaxSpeed(500);
    stepper_y1.setAcceleration(1000000);
    stepper_y2.setAcceleration(1000000);
    stepper_x.setAcceleration(1000000);
    z_pos = 0;
    for (int i = 1; i < 8; i++) {
      stepper_y1.moveTo(-11000);
      stepper_y2.moveTo(-11000);
      while (stepper_y1.currentPosition() != z_pos) {
        stepper_y1.run();
        stepper_y2.run();
      }
      z_pos = z_pos - 600;
      stepper_x.runToNewPosition(930);
      delay(100);
      while (stepper_y1.currentPosition() != z_pos) {
        stepper_y1.run();
        stepper_y2.run();
      }
      z_pos = z_pos - 600;
      stepper_x.runToNewPosition(30);
      delay(100);
    }
    //}
    ///////////////////////////////////////////////////////////////////////////////////
    digitalWrite (switch1 , 1); //洗完，关强电
    digitalWrite (switch2 , 1);
    digitalWrite (switch3 , 1);
    digitalWrite (switch4 , 1);
    digitalWrite (switch7 , 1);
    servo1.attach(7);//功率管归零
    servo2.attach(6);
    servo1.write(0);
    servo2.write(0);
    delay(1000);
    servo1.detach();
    servo2.detach();
    //归位：黄
    analogWrite(A0, 0);
    analogWrite(A1, 0);
    analogWrite(A2, 255);
    delay(1000);
    analogWrite(A0, 0);
    analogWrite(A1, 255);
    analogWrite(A2, 255);
    stepper_x.setMaxSpeed(200);
    stepper_y1.setMaxSpeed(800);
    stepper_y2.setMaxSpeed(800);
    stepper_y1.setAcceleration(1000000);
    stepper_y2.setAcceleration(1000000);
    stepper_x.setAcceleration(1000000);
    digitalWrite (stepper1_enable , 0);
    digitalWrite (stepper2_enable , 0);

    //归零x
    stepper_x.moveTo(-10000);
    while (analogRead(A6) < 900) {
      stepper_x.run();
    }
    stepper_x.setCurrentPosition(0);
    analogWrite(A0, 255);
    analogWrite(A1, 0);
    delay(500);
    analogWrite(A1, 255);
    //归零y
    analogWrite(A0, 0);
    analogWrite(A1, 255);
    analogWrite(A2, 255);
    stepper_y1.moveTo(-100000);
    stepper_y2.moveTo(-100000);
    while (analogRead(A8) < 900) {
      stepper_y1.run();
      stepper_y2.run();
    }
    stepper_y1.setCurrentPosition(-9000);
    stepper_y2.setCurrentPosition(-9000);
    analogWrite(A0, 255);
    analogWrite(A1, 0);
    delay(500);
    analogWrite(A1, 255);
    digitalWrite (stepper1_enable , 1);  //步进关
    digitalWrite (stepper2_enable , 1);
    analogWrite(A0, 255);   //完成归位：蓝
    analogWrite(A1, 255);
    analogWrite(A2, 0);
    program = 7;
    digitalWrite (l298n2_1 , 0);
    digitalWrite (l298n2_2 , 0);
  }
  if (program == 7) {
    analogWrite(A0, 0);//夹具开
    analogWrite(A1, 255);
    analogWrite(A2, 0);
    digitalWrite (l298n1_1 , 1);//夹松
    digitalWrite (l298n1_2 , 0);
    digitalWrite (l298n1_3 , 1);
    digitalWrite (l298n1_4 , 0);
    delay(2000);
    digitalWrite (l298n1_1 , 0);
    digitalWrite (l298n1_2 , 0);
    digitalWrite (l298n1_3 , 0);
    digitalWrite (l298n1_4 , 0);
    analogWrite(A0, 255);//完成，青
    analogWrite(A1, 0);
    analogWrite(A2, 0);
    while (analogRead(A14) < 300) {
      digitalWrite (switch5 , 1);
    }
    analogWrite(A0, 255);//按键：绿
    analogWrite(A1, 0);
    analogWrite(A2, 255);
    delay(1000);
    program = 8;
  }
  if (program == 8) {
    analogWrite(A0, 0);//移动：黄
    analogWrite(A1, 0);
    analogWrite(A2, 255);
    digitalWrite (switch5 , 0);
    digitalWrite (l298n4_1 , 1);//开门
    digitalWrite (l298n4_2 , 1);
    digitalWrite (l298n4_3 , 0);
    digitalWrite (l298n4_4 , 0);
    if (analogRead(A10) > 800) {
      //delay(700);
      digitalWrite (l298n4_1 , 0);
      digitalWrite (l298n4_2 , 0);
      digitalWrite (l298n4_3 , 0);
      digitalWrite (l298n4_4 , 0);
      analogWrite(A0, 0);//到位，红
      analogWrite(A1, 255);
      analogWrite(A2, 255);
      program = 9;
    }
  }
  if (program == 9) {
    if (analogRead(A14) > 800) {
      program = 10;
      analogWrite(A0, 255);//按键：绿
      analogWrite(A1, 0);
      analogWrite(A2, 255);
      delay(1000);
    }
  }
  if (program == 10) {
    analogWrite(A0, 0);//移动：黄
    analogWrite(A1, 0);
    analogWrite(A2, 255);
    digitalWrite (l298n4_1 , 0);//关门
    digitalWrite (l298n4_2 , 0);
    digitalWrite (l298n4_3 , 1);
    digitalWrite (l298n4_4 , 1);
    if (analogRead(A11) > 800) {
      delay(50);
      digitalWrite (l298n4_1 , 0);
      digitalWrite (l298n4_2 , 0);
      digitalWrite (l298n4_3 , 0);
      digitalWrite (l298n4_4 , 0);
      program = 0;
      analogWrite(A0, 255);//到位，蓝
      analogWrite(A1, 255);
      analogWrite(A2, 0);
      digitalWrite (switch5 , 1);
    }
  }
}












