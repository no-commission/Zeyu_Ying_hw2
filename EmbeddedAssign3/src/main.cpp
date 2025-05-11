#include <Arduino.h>
#include <Wire.h>           // 仅保留I2C必要库
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// 保持原有宏定义命名规范
#define WIDTH   128
#define HEIGHT  64

// 根据ESP32开发板参数定义I2C引脚（严格对应硬件）
#define OLED_SCL 22  // 对应参数图的GPIO22 (I2C SCL)
#define OLED_SDA 21  // 对应参数图的GPIO21 (I2C SDA)

// 重构为I2C初始化方式（保持对象名OLED不变）
Adafruit_SSD1306 OLED(WIDTH, HEIGHT, &Wire, -1);

void setup() {
  // 初始化I2C总线（严格匹配硬件参数）
  Wire.begin(OLED_SDA, OLED_SCL); // ESP32必须显式指定引脚
  
  // 保持原有初始化流程（增加错误检测）
  if(!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C为常见I2C地址
    while(1); // 硬件故障时死循环
  }

  // 完全保留原有显示逻辑
  OLED.clearDisplay();
  OLED.setCursor(1, 1);        // 严格保持原始坐标
  OLED.setTextColor(SSD1306_WHITE);
  OLED.setTextSize(2);
  OLED.println("HelloWorld");  // 显示内容不变
  OLED.display();
}

void loop() {}                 // 保留空循环结构