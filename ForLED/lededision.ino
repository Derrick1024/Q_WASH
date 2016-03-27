#define l1 13
#define l2 12
#define l3 11
#define l4 10
#define l5 9
#define l6 8
#define l7 7
#define l8 6
#define l9 5
#define l10 4
#define l11 3
#define l12 2
#define l13 A0
#define l14 A1
#define l15 A2
int led[15] ={
  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

void setup() {                
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
  pinMode(l7, OUTPUT);
  pinMode(l8, OUTPUT);
  pinMode(l9, OUTPUT);
  pinMode(l10, OUTPUT);
  pinMode(l11, OUTPUT);
  pinMode(l12, OUTPUT);
  pinMode(l13, OUTPUT);
  pinMode(l14, OUTPUT);
  pinMode(l15, OUTPUT);
  qled(led);
  \
  delay(1000);
  for(int i=0;i<15;i++){
    led[i]=0;
    qled(led);
    delay(100);
  }
}
void qled (int x[15])
{
  digitalWrite(l1,x[0]);
  digitalWrite(l2,x[1]);
  digitalWrite(l3,x[2]);
  digitalWrite(l4,x[3]);
  digitalWrite(l5,x[4]);
  digitalWrite(l6,x[5]);
  digitalWrite(l7,x[6]);
  digitalWrite(l8,x[7]);
  digitalWrite(l9,x[8]);
  digitalWrite(l10,x[9]);
  digitalWrite(l11,x[10]);
  digitalWrite(l12,x[11]);
  digitalWrite(l13,x[12]);
  digitalWrite(l14,x[13]);
  digitalWrite(l15,x[14]);
}

void loop() {
  for(int j=0;j<5;j++){
    for(int i=14;i>-1;i--){
      led[i]=1;
      qled(led);
      delay(10);
    }
    for(int i=0;i<15;i++){
      led[i]=0;
      qled(led);
      delay(10);
    }
  }
  for(int j=0;j<5;j++){
    for(int i=0;i<15;i++){
      led[i]=1;
      qled(led);
      delay(10);
    }
    for(int i=0;i<15;i++){
      led[i]=0;
      qled(led);
      delay(10);
    }
  }
  for(int j=0;j<5;j++){
    for(int i=14;i>-1;i--){
      led[i]=1;
    }
    qled(led);
    delay(100);
    for(int i=0;i<15;i++){
      led[i]=0;
    }
    qled(led);
    delay(100);
  }
  for(int j=0;j<20;j++){
    for(int i=14;i>1;i-=2){
      led[i]=1;
      led[i-1]=0;
    }
    led[0]=1;
    qled(led);
    delay(50);
    for(int i=0;i<13;i+=2){
      led[i]=0;
      led[i+1]=1;
    }
    led[14]=0;
    qled(led);
    delay(50);
  }
  for(int j=0;j<100;j++){
    for(int i=14;i>-1;i--){
      led[i]=random(0,2);
    }
    qled(led);
    delay(50);
  }
}





