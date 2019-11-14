#include "SSD1306_minimal.h"
#include <avr/pgmspace.h>
#include <string.h>
#define Trig 1 //引脚Tring
#define Echo 3 //引脚Echo
#include "font.h"

SSD1306_Mini oled;
float cm; //距离变量
float temp; //

void setup() {
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);

  oled.init(0x3c);
  oled.clear();
  oled.startScreen();
}

void drawNum(int n, int i) {
  const unsigned char * img;
  if (n == 0) {
    img = s0;
  }
  if (n == 1) {
    img = s1;
  }
  if (n == 2) {
    img = s2;
  }
  if (n == 3) {
    img = s3;
  }
  if (n == 4) {
    img = s4;
  }
  if (n == 5) {
    img = s5;
  }
  if (n == 6) {
    img = s6;
  }
  if (n == 7) {
    img = s7;
  }
  if (n == 8) {
    img = s8;
  }
  if (n == 9) {
    img = s9;
  }
  oled.drawImage(img, i * 32, 0, 32, 8);
}

void loop() {
  oled.clear();
  digitalWrite(Trig, LOW); //给Trig发送一个低电平
  delayMicroseconds(2);    //等待 2微妙
  digitalWrite(Trig, HIGH); //给Trig发送一个高电平
  delayMicroseconds(10);    //等待 10微妙
  digitalWrite(Trig, LOW); //给Trig发送一个低电平
  temp = float(pulseIn(Echo, HIGH)); //存储回波等待时间,
  //pulseIn函数会等待引脚变为HIGH,开始计算时间,再等待变为LOW并停止计时
  //返回脉冲的长度

  //声速是:340m/1s 换算成 34000cm / 1000000μs => 34 / 1000
  //因为发送到接收,实际是相同距离走了2回,所以要除以2
  //距离(厘米)  =  (回波时间 * (34 / 1000)) / 2
  //简化后的计算公式为 (回波时间 * 17)/ 1000

  cm = (temp * 17 ) / 1000; //把回波时间换算成cm
  int len = 1;
  int num = (int)cm;

  int n;
  n=num/100%10;
  drawNum(n, 0);
  
  n=num/10%10;
  drawNum(n, 1);

  n=num%10;
  drawNum(n, 2);

  delay(1000);
}
