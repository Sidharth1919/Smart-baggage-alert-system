#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

const char* ssid = ""; //Enter wifi hotspot name// 
const char* password = ""; //Enter wifi hotspot password//
#define BOTtoken "" //Paste telegram BOT token//
#define CHAT_ID "" //Paste Telegram chat ID//
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

void setup()

{

Serial.begin(115200);

Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT); 
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  bot.sendMessage(CHAT_ID, "Bot started up", "");



delay(100);

Serial.println("Setup done");

}

void loop()

{

  Serial.println("scan start");


  int n = WiFi.scanNetworks();

  Serial.println("scan done");

  if (n == 0) 
  {

    Serial.println("no networks found");

  } 
  else 
  {

      Serial.print(n);

      Serial.println(" networks found");

    for (int i = 0; i < n; ++i) {

//delay(10);
if((WiFi.SSID(i))=="S")
{
int count;
  Serial.print(WiFi.SSID(i));
  Serial.println(WiFi.RSSI(i));
  if(WiFi.RSSI(i)<-10)
  {
    delay(10000);

    //count=count+1;
    //if
    //if(count==10)
    if(WiFi.RSSI(i)<-20 || WiFi.status() != WL_CONNECTED )
    {

      Serial.println("low signal");
    
      bot.sendMessage(CHAT_ID, "Did you forget your luggage?", "");
      Serial.println("Message sent");
      

      
    }
    
  }
  
}


}

}

Serial.println("");
\

delay(1000);

}