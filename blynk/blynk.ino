/* ใช้สำหรับเพื่อการศึกษาเท่านั่น
    ห้ามใช้ในเชิงพาณิช
    อุดหนุนอุปกรณ์ของเราได้ที่ www.ec-bot.com
*/
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
Servo myservo;
char auth[] = "xxx"; // Token App Blynk
char ssid[] = "xxx"; // ชื่อ Wi-Fi
char pass[] = "xxx"; // รหัส Wi-Fi
int Step = 0;
int State = 0;

BLYNK_WRITE(V0)
{
  if (param.asInt() == 1) {
    Step = 1;
  } else {
    Step = 0;
  }
}

void setup()
{
  myservo.attach(D4);
  myservo.write(0);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass); // เชื่อมต่อ auth , ssis , pass
}

void loop()
{
  Blynk.run();
  Serial.println(State);
  if (Step == 0 && State == 0) {
    myservo.write(0);
  } else if  (Step == 1 && State == 0) {
    State = 1;
  } else if (State == 1) {
    myservo.write(80);
    delay(500);
    myservo.write(0);
    delay(5000);
    State = 0;
  }
}