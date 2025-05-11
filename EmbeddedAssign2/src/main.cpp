#include <Arduino.h>

// 确定引脚
int led1 = 16; 
int led2 = 2;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  // 初始化
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    String myString = Serial.readStringUntil('\n');
    myString.trim(); // 去除换行符
    
    if (myString == "1") {
      // 点亮
      digitalWrite(led1, HIGH);
      Serial.println( "LED1亮");
      
    } else if (myString == "2") {
      digitalWrite(led2, HIGH);
      Serial.println( "LED2亮");
      
    } else {
      Serial.println("无效命令");
    }
  }
}
