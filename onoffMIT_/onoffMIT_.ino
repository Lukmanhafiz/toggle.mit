#include <WiFi.h>
#include <WebSocketsClient.h>

WebSocketsClient webSocket;

const char* ssid = "NOC";
const char* pass = "noc2023!";
const char* host = "192.168.223.68"; // IP Node-RED
const int port = 1880;

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  if (type == WStype_TEXT) {
    String msg = String((char*)payload);
    Serial.println("Dari Node-RED: " + msg);

    if (msg == "ON") {
      digitalWrite(2, HIGH);
    } else if (msg == "OFF") {
      digitalWrite(2, LOW);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  webSocket.begin(host, port, "/luk");
  webSocket.onEvent(webSocketEvent);
  webSocket.setReconnectInterval(5000);
}

void loop() {
  webSocket.loop();
}