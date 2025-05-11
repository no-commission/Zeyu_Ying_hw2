#include <Arduino.h>

void setup() {
  // 设定主角（程序里的变量对应硬件的引脚），引脚功能/作用（输入/输出）
int a[6]={15,2,4,16,17,5};
  for(int i = 0; i < 6; i++)
pinMode(a[i],OUTPUT);
}
 
void loop() {
  //来回for循环，设置好起止点
for(int i = 0; i < 6 ; i++ )
  {
    int a[6]={15,2,4,16,17,5};
    digitalWrite(a[i] , HIGH);
    delay(500);
    digitalWrite(a[i] , LOW);
  }
for(int i =4; i > 0 ; i-- )
  {
    int a[6]={15,2,4,16,17,5};
    digitalWrite(a[i] , HIGH);
    delay(500);
    digitalWrite(a[i] , LOW);
  }
}
