String comdata = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);  //   定义13脚为数字输出接口
}

void loop() {
  Serial.println("ON"  );
  digitalWrite(13, HIGH);   // 打开激光头
  delay(1000);              // 延时一秒
  Serial.println("OFF"  );
  digitalWrite(13, LOW);    // 关闭激光头
  delay(1000);              // 延时一秒  

  }
