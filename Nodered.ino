// ใช้อุปกรณ์ raspberry pi 400 และ ต้องเชื่อม laptop ไวไฟเดียวกันกับ raspberry pi
// default user = pi 
// default password = raspberry
#include <WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>		//อย่าลืมติดตั้ง library PubSubClient ของ Nick O’Leadry version 2.7.0
#define LED_PIN 33
WiFiClient espClient;
PubSubClient client(espClient);     // สร้าง object
const char* ssid = "UMR-LAB_2";     //  ชื่อไวไฟ
const char* password = "Ubon2565";  // รหัสไวไฟ
#define mqtt_server "192.168.1.202" // ไอพีของraspberry
#define mqtt_port 1883              // พอร์ทที่ใช้ในการติดต่อสื่อสาร
#define mqtt_user "xxxx"            // ชื่อ user ที่ต้องการ
#define mqtt_password "xxxx"        // รหัส user ที่ต้องการ

void setup() {
pinMode(LED_PIN, OUTPUT);
Serial.begin(115200);
delay(10);
Serial.println();
Serial.print("Connecting to");
Serial.println(ssid);
WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED) {
	delay(500);
	Serial.print(".");
		}
Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
client.setServer(mqtt_server, mqtt_port);
client.setCallback(callback);
}

void loop() {
if (!client.connected()) {
Serial.print("Attempting MQTT connection...");
if (client.connect("ESP8266Client")) {Serial.println("connected");
client.subscribe("/ESP/LED");
} 
else {

Serial.print("failed, rc=");
Serial.print(client.state());
Serial.println(" try again in 5 seconds");
delay(5000);

return;
		}
	}
	client.loop();
	}

void callback(char* topic, byte* payload, unsigned int length) {
Serial.print("Message arrived [");
Serial.print(topic);
Serial.print("] ");
String msg = "";

int i=0;
while (i<length) msg += (char)payload[i++];
Serial.print("MSG: ");
Serial.println(msg);
if (msg == "GET") {
client.publish("/ESP/LED", (digitalRead(LED_PIN) ? "LEDON" : "LEDOFF"));  // subscribe ต้องตรงกับ publish 
Serial.println("Send !");
return;

}

digitalWrite(LED_PIN, (msg == "LEDON" ? HIGH : LOW));
Serial.println(msg);

}

