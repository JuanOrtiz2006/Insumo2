
#include <Firebase_ESP_Client.h>
#include <WiFi.h>
#include <addons/TokenHelper.h>
#include <ArduinoJson.h>
#define FIREBASE_USE_PSRAM

//Conectar a una red WiFi 
const char* WIFI_SSID = "Xiaomi 13T";//el nombre de la red
const char* WIFI_PASSWORD = "1034596ot";//la contraseña de la red
//Recursos de Firebase
const char* API_KEY = "AIzaSyCyZitMUTuDAaClzBZMsvG64D2qUfegrYM";
const char* FIREBASE_PROJECT_ID = "iot-ionic-9e800";
//CONFIGURAR UN EMAIL Y CONTRASEÑA EN AUTHENTICATION de Firebase
const char* USER_EMAIL = "esp32@prueba.com";
const char* USER_PASSWORD = "1034596";

//Define Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
int led=18,led2=19,led3=21;

void setup() {

   Serial.begin(115200);
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);//Verificamos la version
  setupWiFi();//Llamamos la funcion de configuración wifi
  setupFirebase();//Llamamos la funcion de configuración Firebase
  
  //Leds de prueba  
  pinMode (led, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);

 
}

void loop(){
  digitalWrite()
String path = "controlLed";//RUTA DE COLECCION
  FirebaseJson json;

  if (Firebase.Firestore.getDocument(&fbdo, FIREBASE_PROJECT_ID, "", path.c_str(), "")) {

    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, fbdo.payload().c_str());

    if (!error) {
      for (JsonObject document : doc["documents"].as<JsonArray>()) {
        const char* document_name = document["name"];//PARAMETRO NOMBRE
        Serial.print(document);
        const bool state = document["fields"]["encender"]["booleanValue"];//PARAMETRO DE CAMPOS A REVISAR
        Serial.print(" : ");
        if (strstr(document_name, "controlLed1") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(led,1): digitalWrite(led,0);
          state ? Serial.println("LED1 On") : Serial.println("LED1 OFF");
        }
        if (strstr(document_name, ";controlLed2") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(led2,1) : digitalWrite(led2,0);
          state ? Serial.println("LED2 On") : Serial.println("LED2 OFF");
          }
        if (strstr(document_name, "controlLed3") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          state ? digitalWrite(led3,1) : digitalWrite(led3,0);
          state ? Serial.println("LED3 On") : Serial.println("LED3 OFF");
        }
		}
	}
  }
}


//Funcion para configuara WiFi
void setupWiFi() {
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
}

void setupFirebase() {
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.token_status_callback = tokenStatusCallback;  // Ver addons/TokenHelper.h
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}
