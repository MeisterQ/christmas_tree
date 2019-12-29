#include <ESP8266WiFi.h>            // WiFi Library
#include <PubSubClient.h>           // MQTT Library
#include <Adafruit_NeoPixel.h>      // Neopixel Library
#include <ArduinoOTA.h>             // OTA Library

/*
  ------------------------ Neopixel --------------------------
*/

#define PIN 4          // Pin der Neopixels
#define NUMPIXELS 25    // Anzahl der Neopixels   

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);   // Einstellung für Neopixel

/*
  ------------------------ Mosquitto --------------------------
*/

const char* mqtt_server = "xxx.xxx.xxx.xxx";                        // MQTT Server IP

WiFiClient espClient;                                             // WiFi client
PubSubClient client(espClient);                                   // Client für MQTT

/* topics */
#define HELLIGKEIT_TOPIC    "smarthome/Weihnachtsbaum/helligkeit"
#define FARBE_TOPIC         "smarthome/Weihnachtsbaum/farbe"
#define PIR_TOPIC           "smarthome/Weihnachtsbaum/status"
#define ALARM_TOPIC         "smarthome/Weihnachtsbaum/aktiv"
#define LICHT_TOPIC         "smarthome/Weihnachtsbaum/helligkeit2"
#define LICHT_TX_TOPIC      "smarthome/Weihnachtsbaum/helligkeitTX"
#define MQTT_TOPIC          "smarthome/Weihnachtsbaum/benachrichtigung"
#define DAUER_TOPIC         "smarthome/Weihnachtsbaum/dauer_an"
#define DEBUG_TOPIC         "smarthome/Weihnachtsbaum/debug"
#define MODUS_TOPIC         "smarthome/Weihnachtsbaum/modus"
#define ONOFF_TOPIC         "smarthome/Weihnachtsbaum/onoff"
#define ALARM_TOPIC2        "smarthome/Weihnachtsbaum/alarm"

/*
  ---------------------- WLan Einstellungen ------------------
*/

const char* ssid = "xxxx";                    // WLan Name
const char* password = "xxxx";            // WLan Passwort

IPAddress ip(192, 168, 2, 149);                   // IP mit der sich der ESP in das Netzwerk verbinden soll
IPAddress gateway(192, 168, 2, 1);                // Gateway des Netzwerks
IPAddress subnet(255, 255, 255, 0);               // Subnetmask
IPAddress dns(192, 168, 2, 169);

/*
  ---------------------- Variablen ----------------------
*/

#define DEBUG           // Debug
#define buttonPin 16    // Pin des Tasters

bool buttonState = true;
bool tasterStatus = false;
bool alarmStatus = true;
bool mqttStatus = false;
bool neoPixelAus = true;
bool neoPixelAn = false;
bool neoPixelIstAn = false;
bool neoPixelIstAus = false;
bool dauerLicht = false;
bool dauerLichtAn = false;
bool dauerLichtAus = false;
bool onoff = true;
bool licht = 0;
bool alarm = false;
bool neoPixelWeissAn = false;
bool neoPixelRotAn = false;
bool neoPixelGruenAn = false;
bool neoPixelBlauAn = false;
bool neoPixelGelbAn = false;
bool withoutWifi = false;

byte helligkeit = 5;    // Helligkeit der Neopixel
byte old_helligkeit;    // Letzte Helligkeit
byte old_farbe;         // Letzte Farbe
byte farbe = 1;         // Farbe der Neopixel
byte payload[3];
byte mqttFreigabe = 0;
byte blinkDelay = 200;
byte steps = 0;
byte tasterCount = 2;
byte alarmZyklen = 0;
byte alarmZyklen2 = 0;
byte ledMode = 2;
byte old_ledMode = 0;

int intervalTemp = 0;
int buttonState1;
int lastButtonState = LOW;
int delayval = 100;     // Delay für Neopixel Schleife
int ergebnis = 0;
int connects;
int connectsMQTT;
int maxConnects = 5;
int delay2val = 50;
int reading = 0;
int lichtTemp = 0;
int lichtTXTemp = 0;
int lichtTX = 0;

#define BRIGHTNESS 50
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;
unsigned long previousMillis5 = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
const long interval = 1000;
long interval2 = 10000;
const long interval3 = 10000;
const long interval4 = 10000;
const long interval5 = 1000;
char debugMsg[5]; // String für Runtime
char Mode[5];


void setup()
{
  Serial.begin(115200);
  delay(2000);
  pixels.begin();                 // Neopixel initialisieren
  wifiSettings();                 // Wifi Konfigurieren
  mqttSettings();                 // MQTT Konfigurieren
  OTAsettings();                  // OTA Konfigurieren

  pinMode(16, INPUT_PULLDOWN_16);      // Pin 22 als Eingang mit Pullup definieren
  if (withoutWifi == false)
  {
    mqttconnect();                  // MQTT-Verbindung aufbauen
    helligkeit = 100;
  }
  serialAusgabe();                // Ausgabe im Seriellen Monitor
  client.publish(DEBUG_TOPIC, "Setup Done");    // Nachricht an MQTT-Server schicken
  digitalWrite(16, LOW);
}


void loop()
{
  if (withoutWifi == false)
  {
    ArduinoOTA.handle();            // OTA Handle
    mqttHandle();                   // Sende Daten an MQTT Server
    modeWithWifi();
    dauerlicht();                   // Dauerlicht-Funktion
  }
  if (withoutWifi == true)
  {
    modeWithoutWifi();
  }

  sensor();                       // Sensor einlesen an Digitalpin
  yield();
}
