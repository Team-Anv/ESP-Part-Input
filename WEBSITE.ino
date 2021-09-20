#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <EEPROM.h>
#include "login.h"
#include "user_interface.h"
#include "user_manerment.h"
#include "setting_network.h"
#include "device_information.h"
#include "timezone.h"
#include "config_type_resistor.h"
#include "string.h"
#include "stdio.h"
#include "math.h"
#include "configwifi.h"
#include "webshowip.h"
#include "renamewifi_ap.h"
#include <Arduino.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "FS.h"
#include <ESP8266mDNS.h>

#include <Ticker.h>
#include <time.h>
Ticker ticker;

AsyncWebServer server80(80);
AsyncWebServer server81(81);
AsyncEventSource events("/events");

#define EEPROM_SIZE 512

#define dPIN1 D0
#define dPIN2 D1
#define dPIN3 D2
#define dPIN4 D5
#define dPIN5 D6
#define dPIN6 D7
#define dPIN7 D8
#define dPIN8 D9
#define dPIN9 10
int PIND4 = 2;
/// config wifi
#define AdEE_Name_Wifi_Start 0
#define AdEE_Name_Wifi_End 32

#define AdEE_Pass_Wifi_Start 32
#define AdEE_Pass_Wifi_End 65

#define AdEE_User1_Start 65
#define AdEE_User1_End 81  // trong code chi < khong phai <= nen them ra 1 donvi
#define AdEE_Pass1_Start 81
#define AdEE_Pass1_End 97 
#define AdEE_User2_Start 97 
#define AdEE_User2_End 113
#define AdEE_Pass2_Start 113
#define AdEE_Pass2_End 129
#define AdEE_User3_Start 129
#define AdEE_User3_End 145
#define AdEE_Pass3_Start 145
#define AdEE_Pass3_End 161
#define AdEE_User4_Start 161
#define AdEE_User4_End 177
#define AdEE_Pass4_Start 177
#define AdEE_Pass4_End 193
#define AdEE_User5_Start 193
#define AdEE_User5_End 209
#define AdEE_Pass5_Start 209
#define AdEE_Pass5_End 225
////
#define AdEE_IPv4_Start 225
#define AdEE_IPv4_End 241

#define AdEE_Sub_Start 241
#define AdEE_Sub_End 257
#define AdEE_Gateway_Start 257
#define AdEE_Gateway_End 273
//
#define AdEE_ServerPort_Start 273    

#define AdEE_NameDevice_Start 274    
#define AdEE_NameDevice_End 305    
#define AdEE_NumDevice 305 

// start config when reset
#define AdEE_Status_Pin1 306
#define AdEE_Status_Pin2 307
#define AdEE_Status_Pin3 308
#define AdEE_Status_Pin4 309
#define AdEE_Status_Pin5 310
#define AdEE_Status_Pin6 311
#define AdEE_Status_Pin7 312
#define AdEE_Status_Pin8 313
 
#define AdEE_Status_D3 314
// mode status for each Pin ESP
#define AdEE_Status_PIN1_Start 315  
#define AdEE_Status_PIN1_End 318

#define AdEE_Status_PIN2_Start 318  
#define AdEE_Status_PIN2_End 321

#define AdEE_Status_PIN3_Start 321
#define AdEE_Status_PIN3_End 324

#define AdEE_Status_PIN4_Start 324
#define AdEE_Status_PIN4_End 327

#define AdEE_Status_PIN5_Start 327
#define AdEE_Status_PIN5_End 330

#define AdEE_Status_PIN6_Start 330
#define AdEE_Status_PIN6_End 333

#define AdEE_Status_PIN7_Start 333
#define AdEE_Status_PIN7_End 336

#define AdEE_Status_PIN8_Start 336
#define AdEE_Status_PIN8_End 339
///
#define AdEE_AP_SSID_Start 339
#define AdEE_AP_SSID_End 354
#define AdEE_AP_PASS_Start 354
#define AdEE_AP_PASS_End 369

#define AdEE_Status_Pin9 370   // Mode status pin G10 when reset

#define AdEE_Type_Resistor_Pin1 371
#define AdEE_Type_Resistor_Pin2 372
#define AdEE_Type_Resistor_Pin3 373
#define AdEE_Type_Resistor_Pin4 374
#define AdEE_Type_Resistor_Pin5 375
#define AdEE_Type_Resistor_Pin6 376
#define AdEE_Type_Resistor_Pin7 377
#define AdEE_Type_Resistor_Pin8 378

#define AdEE_Status_PIN9_Start 379  // mode status for each Pin ESP PIN G10
#define AdEE_Status_PIN9_End 382

String IPaddress;
String  str_ssid = "", str_pass = "";
int count_time=0;
bool Check_connectwifi=0;

//long last = 0;
const char* ssidapp = "ESP";
const char* passapp = "123456789";
bool IsData = false;
String Data = "";
///*************************khai bao cac bien***********************////
String DataJson = "";
String DataJson_one_para ="";
String DataJson_Network ="";

long pre_time = 0, pre_time_Err=0;
String Check_EEPROM_1 ="";
String Check_EEPROM_2 ="";
// bien tai khoan user
int id_user1 = 1;
int id_user2 = 2;
int id_user3 = 3;
int id_user4 = 4;
int id_user5 = 5;
String user1 = "admin";
String pass1 = "admin";
String user2 = "anv1";
String pass2 = "anv123";
String user3 = "anv2";
String pass3 = "anv234";


String user4 = "";
String pass4 = "";
String user5 = "";
String pass5 = "";
int Dodai_id =0;
String Save_user1 = "";
String Save_pass1 = "";
String Save_user2 = "";
String Save_pass2 = "";
String Save_user3 = "";
String Save_pass3 = "";
String Save_user4 = "";
String Save_pass4 = "";
String Save_user5 = "";
String Save_pass5 = "";


int serverPort = 80;
int IPv4_Octa1=0, IPv4_Octa2=0, IPv4_Octa3=0, IPv4_Octa4=0;
int Gateway_Octa1=0, Gateway_Octa2=0, Gateway_Octa3=0, Gateway_Octa4=0;
int Subnet_Octa1=0, Subnet_Octa2=0, Subnet_Octa3=0, Subnet_Octa4=0;
String GlobalIPv4Add ="192.168.1.187",GlobalSunet="255.255.255.0",GloablGateway="192.168.1.1" ,GlobalServerPort = "80",GlabalMac="D4:9A:A0:AA:5A:40" ,GlobalDNS="8.8.8.8", GlobalPreDNS="8.8.4.4";
bool getevent_network = false; // location setting network
bool get_eve_renamewifi = false;
bool get_eve_PinCh1=0, get_eve_PinCh2=0, get_eve_PinCh3=0, get_eve_PinCh4=0, get_eve_PinCh5=0, get_eve_PinCh6=0;
String Ctr_Pin[20];

//************************
const char* ssid = "Hoang OPPO A9 2020";
const char* pass = "doibaobuonvui";

//const char* ssid = "anvgroup";
//const char* pass = "anvgroup.vn";
boolean t=0;
int Channel=0; // 0: login, 1: UserInterface, 2: usermanerment, 3 settingNetwork
bool configwf = 0;


// *********khai bao bien cho DEvice Information
String NameDevice = "Control Center";
int NumDevice = 1, CountMode=0, Buff_CountMode =0;
String SeriDevice = "D4:9A:A0:AA:5A:40";
int NumIntOut[9];
int iShowPin[8];
bool CheckResistor = 0;

// bien cho timer1 de dieu khien led theo timer
volatile int itimeCh1=0,itimeCh2=0,itimeCh3=0,itimeCh4=0,itimeCh5=0,itimeCh6=0,itimeCh7=0,itimeCh8=0;

volatile int itimeReset =0;
bool readyCountReset = 0, Stop_btn=0;
float ftemp=0;
bool notify_Resistor = 0;

void KhoiTaolaiwifi();
void RestoreConfig();
void Write_JsonStatusPin(String ValueSen);
void AllWrite_JsonUserAndData(String ValueSen);
void Write_JsonUser(String DataU1, String DataPass1, String DataU2, String DataPass2, String DataU3, String DataPass3, String DataU4, String DataPass4,String DataU5, String DataPass5);
void Write_Json_one_para(String Name,String DataTranss);
void Write_JsonNetwork(String DataIPv4, String DataIPv4Sub, String DataGate, String DataSerPort, String DataMacAdd, String DataDNS, String DataPreDNS);
void Write_JsonInfor(String DataName, String DataNum, String DataSeri, String DataIn, String DataOut);
int Separate_String_IP(String inputString,int ptuso);

//**********************KHAI BAO HAM CON**********************////
void ConnectWiFi();
void tick();
void configwifikeyblynk();

void setMode_PIN_D3(boolean statusD3); // D3 la co Phim flash tren board
void setMode_PIN_D4(boolean statusD4);
void setMode_PIN_1(boolean statusP1);
void setMode_PIN_2(boolean statusP2);
void setMode_PIN_3(boolean statusP3);
void setMode_PIN_4(boolean statusP4);
void setMode_PIN_5(boolean statusP5);
void setMode_PIN_6(boolean statusP6);
void setMode_PIN_7(boolean statusP7);
void setMode_PIN_8(boolean statusP8);

int CountIntOut();

void ConfigPin_Default();
void Config_IO();
boolean Chong_Doi_D3();
float NutNhanD3();
void VaoUserInterface();
void Control_GPIO0();
void VaoLogin();
void AllClearEEPROM();
void ClearEEPROM(int StartClear, int EndClear);
void WriteEEPROM_iOneVal(int address,int value);
void WriteEEPROM_Acc(int Start_address, int end_address,String idvalue);
String ReadEEPROM(int RStart_address, int Rend_address,int Rleng_id);

// ISR to Fire when Timer is triggered
void ICACHE_RAM_ATTR onTime() {
  if(readyCountReset)
  {
    int Status1 = Chong_Doi_D3();
    if(Status1 ==true)
    {
        itimeReset++;
        Serial.print("itimereset: ");
        Serial.println(itimeReset);
        if(itimeReset == 5)
        {
          ticker.attach(0.1, tick);  // chơp chớp con led cho biết để rơi vào chế độ hoat dong
        }
        else if(itimeReset == 10)
            ticker.attach(0.3, tick);  // chơp chớp con led cho biết để rơi vào chế độ hoat dong   
    }
    else {
       Stop_btn = true;
       Serial.print("Stop_btn: ");
       Serial.println(Stop_btn);
       readyCountReset = 0;
    }
    
  }
  // Re-Arm the timer as using TIM_SINGLE
  timer1_write(5000000);//us
}

void setup() {
  Serial.begin(115200);
  EEPROM.begin(EEPROM_SIZE);
  setMode_PIN_D3(1);
  setMode_PIN_D4(0);
  //ghi EEProm note
  if(int(EEPROM.read(AdEE_Status_PIN1_Start)) == 255) 
  {
    WriteEEPROM_Acc(AdEE_Status_PIN1_Start,AdEE_Status_PIN1_End,"B"); //pin 1 cho D0 ko dung Input
    WriteEEPROM_Acc(AdEE_Status_PIN2_Start,AdEE_Status_PIN2_End,"B");
    WriteEEPROM_Acc(AdEE_Status_PIN3_Start,AdEE_Status_PIN3_End,"B");
    WriteEEPROM_Acc(AdEE_Status_PIN4_Start,AdEE_Status_PIN4_End,"B");
    WriteEEPROM_Acc(AdEE_Status_PIN5_Start,AdEE_Status_PIN5_End,"B");
    WriteEEPROM_Acc(AdEE_Status_PIN6_Start,AdEE_Status_PIN6_End,"B");
    WriteEEPROM_Acc(AdEE_Status_PIN7_Start,AdEE_Status_PIN7_End,"B");
    WriteEEPROM_Acc(AdEE_Status_PIN8_Start,AdEE_Status_PIN8_End,"B");
    WriteEEPROM_Acc(AdEE_Status_PIN9_Start,AdEE_Status_PIN9_End,"B");
  }
  
  if(int(EEPROM.read(AdEE_Type_Resistor_Pin1)) == 255)
  {
     Serial.println("ghi DL vao EEPROM phan resistor");
     WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin1,1);
     WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin2,1);
     WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin3,1);
     WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin4,1);
     WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin5,1);
     WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin6,1);
     WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin7,1);
     WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin8,1);
  }
  
  delay(100);
  Config_IO();
  Serial.print("Pin 1: "); Serial.println(int(EEPROM.read(AdEE_Status_Pin1)));
  Serial.print("Pin 2: "); Serial.println(int(EEPROM.read(AdEE_Status_Pin2)));
  Serial.print("Pin 3: "); Serial.println(int(EEPROM.read(AdEE_Status_Pin3)));
  Serial.print("Pin 4: "); Serial.println(int(EEPROM.read(AdEE_Status_Pin4)));
  Serial.print("Pin 5: "); Serial.println(int(EEPROM.read(AdEE_Status_Pin5)));
  Serial.print("Pin 6: "); Serial.println(int(EEPROM.read(AdEE_Status_Pin6)));
  Serial.print("Pin 7: "); Serial.println(int(EEPROM.read(AdEE_Status_Pin7)));
  Serial.print("Pin 8: "); Serial.println(int(EEPROM.read(AdEE_Status_Pin8)));
  
  if(int(EEPROM.read(AdEE_AP_SSID_Start)) == 255)
  {
      Serial.println("va phan ghi DL ssidapp vao EEPROM!");
      WriteEEPROM_Acc(AdEE_AP_SSID_Start,AdEE_AP_SSID_End,ssidapp);
      WriteEEPROM_Acc(AdEE_AP_PASS_Start,AdEE_AP_PASS_End,passapp);
  }
  ConnectWiFi();
  
  Serial.println("+++++++++++++++++++check wifi++++++++");
  Serial.print("Check wifi: ");
  Serial.println(Check_connectwifi);

  if (!Check_connectwifi)
  {
    configwf = true;
    ticker.attach(0.1, tick);  // chơp chớp con led cho biết để rơi vào chế độ configwifi
    configwifikeyblynk();     // hàm config

    // ham config IP tinh
    Serial.println("+++++++++++++++++++IP ++++++++");
    GlobalIPv4Add="", GloablGateway="",GlobalSunet ="";
    GlobalIPv4Add = WiFi.localIP().toString();
    GloablGateway = WiFi.gatewayIP().toString();
    GlobalSunet = WiFi.subnetMask().toString();
    WriteEEPROM_Acc(AdEE_IPv4_Start,AdEE_IPv4_End,GlobalIPv4Add);
    WriteEEPROM_Acc(AdEE_Sub_Start,AdEE_Sub_End,GlobalSunet);
    WriteEEPROM_Acc(AdEE_Gateway_Start,AdEE_Gateway_End,GloablGateway);
    EEPROM.write(AdEE_ServerPort_Start,serverPort);
    Serial.println(GlobalIPv4Add);
    ////
    KhoiTaolaiwifi();
    // add them o day
    Serial.println("khoi tao xong lan 1 phan config");
    
  }
  else if (Check_connectwifi)
  { 
    //WiFi.mode(WIFI_STA);
    Serial.println();
    Serial.println("Successfully connected to WIFI EEPROM");
    Serial.print("ssid: ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("+++++++++++++++++++IP when connect suceess ++++++++");

     KhoiTaolaiwifi();
     Serial.println("khoi tao lai wwifi lan 1 xong");
     delay(1000);
  }
  if (!configwf)
  {
    String conv_ssidapp="",conv_passapp="";
   ssidapp ="",passapp="";
   conv_ssidapp = ReadEEPROM(AdEE_AP_SSID_Start,AdEE_AP_SSID_End,Dodai_id).c_str();
   conv_passapp = ReadEEPROM(AdEE_AP_PASS_Start,AdEE_AP_PASS_End,Dodai_id).c_str();
   ssidapp = conv_ssidapp.c_str();
   passapp = conv_passapp.c_str();
   Serial.print("SSID app: "); Serial.println(ssidapp);
   Serial.print("PASS app: "); Serial.println(passapp);
    Serial.println("");
    WiFi.softAP(ssidapp, passapp);
    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);
    delay(5000);
  }
  else
  {
    delay(2000);
  }
 Serial.println("bat dau phan SPIFFS");
  if(!SPIFFS.begin()){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
  }
  
  // kich hoat timer
  timer1_attachInterrupt(onTime); // Add ISR Function
  timer1_enable(TIM_DIV16, TIM_EDGE, TIM_SINGLE);
  /* Dividers:
    TIM_DIV1 = 0,   //80MHz (80 ticks/us - 104857.588 us max)
    TIM_DIV16 = 1,  //5MHz (5 ticks/us - 1677721.4 us max)
    TIM_DIV256 = 3  //312.5Khz (1 tick = 3.2us - 26843542.4 us max)
  Reloads:
    TIM_SINGLE  0 //on interrupt routine you need to write a new value to start the timer again
    TIM_LOOP  1 //on interrupt the counter will start with the same value again
  */
  
  // Arm the Timer for our 1s Interval
  timer1_write(5000000); //0.5s thi 2500000 / 5 ticks per us from TIM_DIV16 == 500,000 us interval 
 
  if(int(EEPROM.read(AdEE_User1_Start))==255)
  {
    Serial.println("va phan ghi DL User1 vao EEPROM!");
    WriteEEPROM_Acc(AdEE_User1_Start,AdEE_User1_End,user1);
    WriteEEPROM_Acc(AdEE_Pass1_Start,AdEE_Pass1_End,pass1);
  }
   //      Num = (int)EEPROM.read(AdEE_NumDevice);
   
  if(int(EEPROM.read(AdEE_NameDevice_Start))==255)
  {
      Serial.println("va phan ghi DL Name Device vao EEPROM!");
      WriteEEPROM_Acc(AdEE_NameDevice_Start,AdEE_NameDevice_End,NameDevice);
      WriteEEPROM_iOneVal(AdEE_NumDevice,NumDevice);
  }
  Serial.println("khoi tao xong wifi");
  // ktra cach noi tro ntn
  iShowPin[0] = int(EEPROM.read(AdEE_Type_Resistor_Pin1));
  iShowPin[1] = int(EEPROM.read(AdEE_Type_Resistor_Pin2));
  iShowPin[2] = int(EEPROM.read(AdEE_Type_Resistor_Pin3));
  iShowPin[3] = int(EEPROM.read(AdEE_Type_Resistor_Pin4));
  iShowPin[4] = int(EEPROM.read(AdEE_Type_Resistor_Pin5));
  iShowPin[5] = int(EEPROM.read(AdEE_Type_Resistor_Pin6));
 //===================================================================================
  server81.on("/", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    request->send_P(200, "text/html", index_webshowip);
  });
  server81.on("/rename/AP", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    request->send_P(200, "text/html", RenameWifi);
  });
  server81.on("/renamewifi", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    String re_ssidapp, re_passapp;
    re_ssidapp ="", re_passapp="";
    if (request->hasParam("ssid") && request->hasParam("pass")){
         re_ssidapp = request->getParam("ssid")->value();
         re_passapp = request->getParam("pass")->value();
         WriteEEPROM_Acc(AdEE_AP_SSID_Start,AdEE_AP_SSID_End,re_ssidapp);
         WriteEEPROM_Acc(AdEE_AP_PASS_Start,AdEE_AP_PASS_End,re_passapp);
         get_eve_renamewifi = 1;
         Serial.println("ghi thanh cong lan 1");
      }
      else {
         re_ssidapp  = "No message sent";
      }
      Serial.println(re_ssidapp);
      
  });
  server81.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    request->send_P(200, "text/html", index_webshowip);
  });
  
  server81.on("/GetIP1", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    if (Check_connectwifi)
    {
      IPaddress =  WiFi.localIP().toString();
      request->send_P(200, "text/html", IPaddress.c_str());
    }
    else
    {
      request->send_P(200, "text/html", "1");
    }
  });
  
 //===================================================================================
server80.on("/boostrap/bootstrap.min.css",HTTP_GET, [](AsyncWebServerRequest *request){
    
    request->send(SPIFFS, "/bootstrap.min.css", "text/css");
     Serial.println("In ra: bootstrap.min.css");
  });
  
  server80.on("/boostrap/bootstrap-icons.css",HTTP_GET, [](AsyncWebServerRequest *request){
    
    request->send(SPIFFS, "/bootstrap-icons.css", "text/css");
     Serial.println("In ra: bootstrap-icons.css");
  });
  
   server80.on("/boostrap/all.min.css",HTTP_GET, [](AsyncWebServerRequest *request){
    
    request->send(SPIFFS, "/all.min.css", "text/css");
     Serial.println("In ra: all.min.css");
  });

  server80.on("/boostrap/jquery.min.js",HTTP_GET, [](AsyncWebServerRequest *request){
    
    request->send(SPIFFS, "/jquery.min.js", "text/js");
     Serial.println("In ra: jquery.min.js");
  }); 

  server80.on("/boostrap/bootstrap.bundle.min.js",HTTP_GET, [](AsyncWebServerRequest *request){
    
    request->send(SPIFFS, "/bootstrap.bundle.min.js", "text/js");
     Serial.println("In ra: bootstrap.bundle.min.js");
  });

   server80.on("/boostrap/popper.min.js",HTTP_GET, [](AsyncWebServerRequest *request){
    
    request->send(SPIFFS, "/popper.min.js", "text/js");
     Serial.println("In ra: popper.min.js");
  });

  server80.on("/boostrap/bootstrap.min.js",HTTP_GET, [](AsyncWebServerRequest *request){
    
    request->send(SPIFFS, "/bootstrap.min.js", "text/js");
     Serial.println("In ra: bootstrap.min.js");
  });

  server80.on("/boostrap/i18next.min.js",HTTP_GET, [](AsyncWebServerRequest *request){
    
    request->send(SPIFFS, "/i18next.min.js", "text/js");
     Serial.println("In ra: i18next.min.js");
  });
  
 server80.on("/boostrap/loader.js",HTTP_GET, [](AsyncWebServerRequest *request){
    
    request->send(SPIFFS, "/chartsloader.js", "text/js");
     Serial.println("In ra: chartloader");
  });

  server80.on("/bootstrap.min.css.map",HTTP_GET, [](AsyncWebServerRequest *request){
    
    request->send(SPIFFS, "/bootstrap.min.css.map", "text/map");
     Serial.println("In ra: map");
  });
  server80.on("bootstrap.min.css.map",HTTP_GET, [](AsyncWebServerRequest *request){
    
    request->send(SPIFFS, "/bootstrap.min.css.map", "text/map");
     Serial.println("In ra: map");
  });
  
  server80.on("/boostrap/bootstrap.min.css.map",HTTP_GET, [](AsyncWebServerRequest *request){
    
    request->send(SPIFFS, "/bootstrap.min.css.map", "text/map");
     Serial.println("In ra: map");
  });
 // boostrap
  server80.on("/logo_anvgroup",HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/logo_anvgroup.png", "image/png");
     Serial.println("In ra anh: logo_anvgroup");
  });
  server80.on("/logo_anvil",HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/logo_anvil.png", "image/png");
     Serial.println("In ra anh: logo Anvil");
  });
  server80.on("/footer",HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/footer.png", "image/png");
    Serial.println("In ra anh: footer");
});

  server80.on("/light_off",HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/light_off.png", "image/png");
    Serial.println("In ra light_off.png");
});
server80.on("/light_on",HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/light_on.png", "image/png");
  Serial.println("In ra light_on.png");
});
server80.on("/camera",HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/camera.png", "image/png");
  Serial.println("In ra camera.png");
});

server80.on("/temp",HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/temp.png", "image/png");
  Serial.println("In ra temp.png");
});
server80.on("/smoke",HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/smoke.png", "image/png");
  Serial.println("In ra smoke.png");
});
server80.on("/people_move",HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/people_move.png", "image/png");
  Serial.println("In ra people_move.png");
});
server80.on("/move_impact",HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/move_impact.png", "image/png");
  Serial.println("In ra move_impact.png");
});
server80.on("/distance",HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/distance.png", "image/png");
  Serial.println("In ra distance.png");
});
server80.on("/button",HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/button.png", "image/png");
  Serial.println("In ra button.png");
});
server80.on("/Bell",HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/Bell.png", "image/png");
  Serial.println("In ra Bell.png");
});
server80.on("/warning",HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/warning.png", "image/png");
  Serial.println("In ra warning.png");
});
server80.on("/impact",HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/impact.png", "image/png");
  Serial.println("In ra impact.png");
});

// ********* LOAD WEB cho tung trang*************************
server80.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest * request)
{
     Serial.println("trong phan favicon.ico");
      if(Channel ==0)
       request->send_P(200, "text/html", Login);
      else if(Channel ==1) 
         request->send_P(200, "text/html", UserInterface);
      else if(Channel ==2) 
         request->send_P(200, "text/html", ConfigTypeResistor);
      else if(Channel ==3)
        request->send_P(200, "text/html", SettingNetwork);
      else if(Channel ==4)
        request->send_P(200, "text/html", UserManerment);
      else if(Channel ==5)
        request->send_P(200, "text/html", DeviceInformation);
      else if(Channel ==6)
        request->send_P(200, "text/html", TimeZone);
});

server80.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
   Serial.println("no vao phan load web sau khi config thanh cong");
    request->send_P(200, "text/html", Login);
  });

/*****************  PHAN LOGIN ****************************************************** /
/* Upload du lieu phan Login  */
server80.on("/LLoadData/Login", HTTP_GET, [](AsyncWebServerRequest *request) {
     String sCheckOpenLogin;
      // bat key de check:
      if (request->hasParam("CheckOpen_wb_LD")){
         sCheckOpenLogin = request->getParam("CheckOpen_wb_LD")->value();
      }
      else {
          sCheckOpenLogin = "No message sent";
      }
      Serial.print("load Data JSON Login...");
      Serial.println(sCheckOpenLogin);
      if(sCheckOpenLogin=="0")
      {
        Save_user1="",Save_pass1="",Save_user2="",Save_pass2="", Save_user3="", Save_pass3="",Save_user4="",Save_pass4="",Save_user5="",Save_pass5="";
        Save_user1 = ReadEEPROM(AdEE_User1_Start,AdEE_User1_End,Dodai_id);
        Save_pass1 = ReadEEPROM(AdEE_Pass1_Start,AdEE_Pass1_End,Dodai_id);
        Save_user2 = ReadEEPROM(AdEE_User2_Start,AdEE_User2_End,Dodai_id);
        Save_pass2 = ReadEEPROM(AdEE_Pass2_Start,AdEE_Pass2_End,Dodai_id);
        Save_user3 = ReadEEPROM(AdEE_User3_Start,AdEE_User3_End,Dodai_id);
        Save_pass3 = ReadEEPROM(AdEE_Pass3_Start,AdEE_Pass3_End,Dodai_id);
        Save_user4 = ReadEEPROM(AdEE_User4_Start,AdEE_User4_End,Dodai_id);
        Save_pass4 = ReadEEPROM(AdEE_Pass4_Start,AdEE_Pass4_End,Dodai_id);
        Save_user5 = ReadEEPROM(AdEE_User5_Start,AdEE_User5_End,Dodai_id);
        Save_pass5 = ReadEEPROM(AdEE_Pass5_Start,AdEE_Pass5_End,Dodai_id);
        Write_JsonUser(Save_user1,Save_pass1,Save_user2,Save_pass2,Save_user3,Save_pass3,Save_user4,Save_pass4,Save_user5,Save_pass5); // truyen di mang
        request->send(200,"text/plain",DataJson);
        DataJson ="";
         Serial.println("truyen DL len thanh cong o phan Login");
      }
      else request->send(200,"text/plain","OK");
  });

server80.on("/api/login", HTTP_GET, [](AsyncWebServerRequest *request) {
     Channel = 0;
     request->send_P(200, "text/html", Login);
  });
  
  server80.on("/api/control", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", UserInterface);
    Channel = 1;
    Serial.println("vao control");
      
  });

// PHAN LUA CHON NOI TRO
server80.on("/GLoadData/select_resistor",HTTP_GET, [](AsyncWebServerRequest *request){ // Load len server sau moi lan updte
  String sCheckOpen_GD="", sChannelPin_Wb="";
  int iType_resistor;
      // bat key de check:
      if (request->hasParam("CheckOpen_wb_GD") && request->hasParam("PinCh")){
         sCheckOpen_GD = request->getParam("CheckOpen_wb_GD")->value();
         sChannelPin_Wb = request->getParam("PinCh")->value(); 
      }
      else {
          sCheckOpen_GD = "No message sent";
      }
      Serial.print("Check Open: ");
      Serial.println(sCheckOpen_GD);
      Serial.print("PinCh: ");
      Serial.println(sChannelPin_Wb);
      
      if(sCheckOpen_GD == "0")
      {
          Save_user1="",Save_pass1="",Save_user2="",Save_pass2="", Save_user3="", Save_pass3="",Save_user4="",Save_pass4="",Save_user5="",Save_pass5="";
          Save_user1 = ReadEEPROM(AdEE_User1_Start,AdEE_User1_End,Dodai_id);
          Save_pass1 = ReadEEPROM(AdEE_Pass1_Start,AdEE_Pass1_End,Dodai_id);
          Save_user2 = ReadEEPROM(AdEE_User2_Start,AdEE_User2_End,Dodai_id);
          Save_pass2 = ReadEEPROM(AdEE_Pass2_Start,AdEE_Pass2_End,Dodai_id);
          Save_user3 = ReadEEPROM(AdEE_User3_Start,AdEE_User3_End,Dodai_id);
          Save_pass3 = ReadEEPROM(AdEE_Pass3_Start,AdEE_Pass3_End,Dodai_id);
          Save_user4 = ReadEEPROM(AdEE_User4_Start,AdEE_User4_End,Dodai_id);
          Save_pass4 = ReadEEPROM(AdEE_Pass4_Start,AdEE_Pass4_End,Dodai_id);
          Save_user5 = ReadEEPROM(AdEE_User5_Start,AdEE_User5_End,Dodai_id);
          Save_pass5 = ReadEEPROM(AdEE_Pass5_Start,AdEE_Pass5_End,Dodai_id);
          Write_JsonUser(Save_user1,Save_pass1,Save_user2,Save_pass2,Save_user3,Save_pass3,Save_user4,Save_pass4,Save_user5,Save_pass5); // truyen di mang
          request->send(200,"text/plain",DataJson);
          DataJson ="";
      }
      else if(sCheckOpen_GD == "1")
      { 
          if(sChannelPin_Wb == "1")
         {
            iType_resistor=0;
            iType_resistor = int(EEPROM.read(AdEE_Type_Resistor_Pin1));
            Write_Json_one_para("Pin1",String(iType_resistor));
            request->send(200,"text/plain",DataJson_one_para);
         }
         else if(sChannelPin_Wb=="2")
         {
            iType_resistor=0;
            iType_resistor = int(EEPROM.read(AdEE_Type_Resistor_Pin2));
            Write_Json_one_para("Pin2",String(iType_resistor));
            request->send(200,"text/plain",DataJson_one_para);
         }
         else if(sChannelPin_Wb=="3")
         {
            iType_resistor=0;
            iType_resistor = int(EEPROM.read(AdEE_Type_Resistor_Pin3));
            Write_Json_one_para("Pin3",String(iType_resistor));
            request->send(200,"text/plain",DataJson_one_para);
         }
         else if(sChannelPin_Wb=="4")
         {
            iType_resistor=0;
            iType_resistor = int(EEPROM.read(AdEE_Type_Resistor_Pin4));
            Write_Json_one_para("Pin4",String(iType_resistor));
            request->send(200,"text/plain",DataJson_one_para);
         }
         else if(sChannelPin_Wb=="5")
         {
            iType_resistor=0;
            iType_resistor = int(EEPROM.read(AdEE_Type_Resistor_Pin5));
            Write_Json_one_para("Pin5",String(iType_resistor));
            request->send(200,"text/plain",DataJson_one_para);
         }
         else if(sChannelPin_Wb=="6")
         {
            iType_resistor=0;
            iType_resistor = int(EEPROM.read(AdEE_Type_Resistor_Pin6));
            Write_Json_one_para("Pin6",String(iType_resistor));
            request->send(200,"text/plain",DataJson_one_para);
         }
          else {
            Write_Json_one_para("OK","OK");
            request->send(200,"text/plain",DataJson_one_para);
          }
      }
});
server80.on("/api/config/resistor", HTTP_GET, [](AsyncWebServerRequest *request) {
           request->send_P(200, "text/html", ConfigTypeResistor);
           Channel = 2;
           Serial.println("Nhay vao phan config resistor");                         // Chung cho nut config trong network and nut system trong UI
           Serial.println(Channel); 
  });

server80.on("/api/setting/typeresistor",HTTP_GET, [](AsyncWebServerRequest *request){ // Load len server sau moi lan updte
    Serial.println("Vao setting ressistor");
    String sPin, sU, sP,sReceiveData;
      // bat key de check:
      if (request->hasParam("U") && request->hasParam("P") && request->hasParam("senddata") && request->hasParam("Pin")){
         sU = request->getParam("U")->value();
         sP = request->getParam("P")->value();
         sReceiveData = request->getParam("senddata")->value();
         sPin = request->getParam("Pin")->value();
      }
      else {
          sU = "No message sent";
      }
       Serial.println("Gia trị nhan ve: ");
        Serial.print("user nhan: ");
        Serial.println(sU);
        Serial.print("Pass nhan: ");
        Serial.println(sP);
        Serial.print("Data nhan: ");
        Serial.println(sReceiveData);
        
       user1 = "", pass1 = "",user2 ="",pass2 ="",user3 ="",pass3="",user4="", pass4 ="",user5 ="",pass5 = "";
      user1 = ReadEEPROM(AdEE_User1_Start,AdEE_User1_End,Dodai_id);
      pass1 = ReadEEPROM(AdEE_Pass1_Start,AdEE_Pass1_End,Dodai_id);
      user2 = ReadEEPROM(AdEE_User2_Start,AdEE_User2_End,Dodai_id);
      pass2 = ReadEEPROM(AdEE_Pass2_Start,AdEE_Pass2_End,Dodai_id);
      user3 = ReadEEPROM(AdEE_User3_Start,AdEE_User3_End,Dodai_id);
      pass3 = ReadEEPROM(AdEE_Pass3_Start,AdEE_Pass3_End,Dodai_id);
      user4 = ReadEEPROM(AdEE_User4_Start,AdEE_User4_End,Dodai_id);
      pass4 = ReadEEPROM(AdEE_Pass4_Start,AdEE_Pass4_End,Dodai_id);
      user5 = ReadEEPROM(AdEE_User5_Start,AdEE_User5_End,Dodai_id);
      pass5 = ReadEEPROM(AdEE_Pass5_Start,AdEE_Pass5_End,Dodai_id);
      Serial.println("Gia trị EEProm: ");
      Serial.print("user EPP: ");
      Serial.println(user1);
      Serial.print("Pass EPP: ");
      Serial.println(pass1);
      if((sU == user1 || sU == user2 || sU == user3 || sU == user4 || sU == user5) &&(sP == pass1 || sP == pass2 || sP == pass3 || sP == pass4 || sP == pass5))
      {
            if(sPin =="1")
            {
               if(sReceiveData == "Serial")
               {
                  WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin1,1);
                  Write_Json_one_para("Pin1","1");
                  iShowPin[0] = 1;
               }
               else {
                  WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin1,0);
                  Write_Json_one_para("Pin1","0");
                  iShowPin[0] = 0;
               }
               request->send(200, "text/html", DataJson_one_para);
            }
            else if(sPin =="2")
            {
              if(sReceiveData == "Serial")
               {
                  WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin2,1);
                  Write_Json_one_para("Pin2","1");
                  iShowPin[1] = 1;
               }
               else {
                  WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin2,0);
                  Write_Json_one_para("Pin2","0");
                  iShowPin[1] = 0;
               }
               request->send(200, "text/html", DataJson_one_para);
            }
            else if(sPin =="3")
            {
               if(sReceiveData == "Serial")
               {
                  WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin3,1);
                  Write_Json_one_para("Pin3","1");
                  iShowPin[2] = 1;
               }
               else {
                  WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin3,0);
                  Write_Json_one_para("Pin3","0");
                  iShowPin[2] = 0;
               }
               request->send(200, "text/html", DataJson_one_para);
            }
            else if(sPin =="4")
            {
               if(sReceiveData == "Serial")
               {
                  WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin4,1);
                  Write_Json_one_para("Pin4","1");
                  iShowPin[3] = 1;
               }
               else {
                  WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin4,0);
                  Write_Json_one_para("Pin4","0");
                  iShowPin[3] = 0;
               }
               request->send(200, "text/html", DataJson_one_para);
            }
            else if(sPin =="5")
            {
               if(sReceiveData == "Serial")
               {
                  WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin5,1);
                  Write_Json_one_para("Pin5","1");
                  iShowPin[4] = 1;
               }
               else {
                  WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin5,0);
                  Write_Json_one_para("Pin5","0");
                  iShowPin[4] = 0;
               }
               request->send(200, "text/html", DataJson_one_para);
            }
            else if(sPin =="6")
            {
               if(sReceiveData == "Serial")
               {
                  WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin6,1);
                  Write_Json_one_para("Pin6","1");
                  iShowPin[5] = 1;
               }
               else {
                  WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin6,0);
                  Write_Json_one_para("Pin6","0");
                  iShowPin[5] = 0;
               }
               request->send(200, "text/html", DataJson_one_para);
            }
      }
      else Serial.println("ban sai pass roi");
      
});
// **************  USER INTERFACE********************
server80.on("/GLoadData/UserInterface",HTTP_GET, [](AsyncWebServerRequest *request){ // Load len server sau moi lan updte
  String sCheckOpen_GD;
  
      // bat key de check:
      if (request->hasParam("CheckOpen_wb_GD")){
         sCheckOpen_GD = request->getParam("CheckOpen_wb_GD")->value();
        
      }
      else {
          sCheckOpen_GD = "No message sent";
      }
      
      if(sCheckOpen_GD == "0")
      {
         AllWrite_JsonUserAndData(String(ftemp));
         request->send(200,"text/plain",DataJson);
         DataJson = "";
         Serial.println("truyen DL len thanh cong o phan Giao Dien");
      }
      else if(sCheckOpen_GD == "1")
      {
        Write_JsonStatusPin(String(ftemp));
        request->send(200,"text/plain",DataJson);
         DataJson = "";
      }
});

//**************************** Dieu khien GPIO **************************

/*************************CONFIGURATE DEVICE****************************************/
server80.on("/api/system/Network", HTTP_GET, [](AsyncWebServerRequest *request) {
  Channel = 3;
  Serial.println("Nhay vao phan Bacsic information");                         // Chung cho nut config trong network and nut system trong UI
  Serial.println(Channel);
  request->send_P(200, "text/html", SettingNetwork);
  });
/**********************     NETWORK     **************************/
// *****************************Load phan Network***************************
  server80.on("/NetWkLoadData/Network",HTTP_GET, [](AsyncWebServerRequest *request){ 
  String sCheckOpen_NetWk;
  int Port;
      // bat key de check:
      if (request->hasParam("CheckOpen_wb_NetWk")){
         sCheckOpen_NetWk = request->getParam("CheckOpen_wb_NetWk")->value();
      }
      else {
          sCheckOpen_NetWk = "No message sent";
      }
      Serial.print("Da Nhay vao phan giao dien lay bien CheckOpenNetwork: ");
      Serial.println(sCheckOpen_NetWk);
      if(sCheckOpen_NetWk == "0")
      {
       
         // doc tu EEProm ra
         GlobalIPv4Add = ReadEEPROM(AdEE_IPv4_Start,AdEE_IPv4_End,Dodai_id);
         GlobalSunet = ReadEEPROM(AdEE_Sub_Start,AdEE_Sub_End,Dodai_id);
         GloablGateway = ReadEEPROM(AdEE_Gateway_Start,AdEE_Gateway_End,Dodai_id);
         Port = int(EEPROM.read(AdEE_ServerPort_Start));
         Serial.print("Port ne: ");
         Serial.println(Port);
         GlobalServerPort = String(Port);
         Write_JsonNetwork(GlobalIPv4Add,GlobalSunet,GloablGateway,String(GlobalServerPort),GlabalMac,GlobalDNS,GlobalPreDNS); // truyen di mang
         request->send(200,"text/plain",DataJson_Network);
         Serial.println("truyen DL len thanh cong o phan Network");
      }
});

  server80.on("/api/system/usermanerment", HTTP_GET, [](AsyncWebServerRequest *request) {
  Channel = 4;
  Serial.println("Nhay vao phan setting NetWork");
  Serial.println(Channel);
  request->send_P(200, "text/html", UserManerment);
  });
  
  server80.on("/api/system/infor", HTTP_GET, [](AsyncWebServerRequest *request) {
  Channel = 5;
  Serial.println("Nhay vao phan Device information");
  Serial.println(Channel);
  request->send_P(200, "text/html", DeviceInformation);
  });
  
  server80.on("/api/system/timezone", HTTP_GET, [](AsyncWebServerRequest *request) {
  Channel = 6;
  Serial.println("Nhay vao phan Bacsic ìnormation");
  Serial.println(Channel);
  request->send_P(200, "text/html", TimeZone);
  });

  // *****************day la phan setting Network ********************
server80.on("/api/setting/network",HTTP_GET, [](AsyncWebServerRequest *request){ // Load len server sau moi lan updte
   String  sIPv4AddESP, sIPv4SubESP, sIPv4GateESP; // location setting network
   // bat key de check:
     if (request->hasParam("IPv4_Add_Wb") && request->hasParam("IPv4_Sub_Wb") && request->hasParam("IPv4_Gate_Wb"))
     {
         sIPv4AddESP="",sIPv4SubESP="",sIPv4GateESP="";
         sIPv4AddESP = request->getParam("IPv4_Add_Wb")->value();
         sIPv4SubESP = request->getParam("IPv4_Sub_Wb")->value();
         sIPv4GateESP = request->getParam("IPv4_Gate_Wb")->value();

         WriteEEPROM_Acc(AdEE_IPv4_Start,AdEE_IPv4_End,sIPv4AddESP);
         WriteEEPROM_Acc(AdEE_Sub_Start,AdEE_Sub_End,sIPv4SubESP);
         WriteEEPROM_Acc(AdEE_Gateway_Start,AdEE_Gateway_End,sIPv4GateESP);
         
         getevent_network = true;  
    }
    else {
         sIPv4AddESP= "No message sent";
    }
    Serial.print("Dia chi IP nhan ve tu web: ");
    Serial.println(sIPv4AddESP);
   
});
  //*************************************Load Phan Usermanerment*******************************************
  server80.on("/U_LoadData/user",HTTP_GET, [](AsyncWebServerRequest *request){ // Load len server sau moi lan updte
   String sCheckStatusJSONESP;
   // bat key de check:
   if (request->hasParam("checkOpen")){
         sCheckStatusJSONESP = request->getParam("checkOpen")->value();
    }
    else {
         sCheckStatusJSONESP = "No message sent";
    }
    Serial.print("Gia trị nhan ve sCheckJSON: ");
    Serial.println(sCheckStatusJSONESP);
    if(sCheckStatusJSONESP == "0") {
      Save_user1 = "", Save_pass1 = "", Save_user2 ="", Save_pass2 ="",Save_user3 ="",Save_pass3="",Save_user4="", Save_pass4 ="",Save_user5 ="",Save_pass5 = "";
      Save_user1 = ReadEEPROM(AdEE_User1_Start,AdEE_User1_End,Dodai_id);
      Save_pass1 = ReadEEPROM(AdEE_Pass1_Start,AdEE_Pass1_End,Dodai_id);
      Save_user2 = ReadEEPROM(AdEE_User2_Start,AdEE_User2_End,Dodai_id);
      Save_pass2 = ReadEEPROM(AdEE_Pass2_Start,AdEE_Pass2_End,Dodai_id);
      Save_user3 = ReadEEPROM(AdEE_User3_Start,AdEE_User3_End,Dodai_id);
      Save_pass3 = ReadEEPROM(AdEE_Pass3_Start,AdEE_Pass3_End,Dodai_id);
      Save_user4 = ReadEEPROM(AdEE_User4_Start,AdEE_User4_End,Dodai_id);
      Save_pass4 = ReadEEPROM(AdEE_Pass4_Start,AdEE_Pass4_End,Dodai_id);
      Save_user5 = ReadEEPROM(AdEE_User5_Start,AdEE_User5_End,Dodai_id);
      Save_pass5 = ReadEEPROM(AdEE_Pass5_Start,AdEE_Pass5_End,Dodai_id);
      Write_JsonUser(Save_user1,Save_pass1,Save_user2,Save_pass2,Save_user3,Save_pass3,Save_user4,Save_pass4,Save_user5,Save_pass5); // truyen di mang
          
      request->send(200,"text/plain",DataJson);
      DataJson="";
    } else {
      request->send(200,"text/plain","Faile!");
      }
});

// Add them tai khoan cho Usermanerment
server80.on("/api/setting/account",HTTP_GET, [](AsyncWebServerRequest *request){ // Load len server sau moi lan updte
   String sUserESP, sPassESP, sidUser;
   int iid_User;
   // bat key de check:
   if (request->hasParam("id_user_wb") && request->hasParam("DataUser_wb") && request->hasParam("DataPass_wb")){
         sidUser = request->getParam("id_user_wb")->value();
         sUserESP = request->getParam("DataUser_wb")->value();
         sPassESP = request->getParam("DataPass_wb")->value();
    }
    else {
         sUserESP = "No message sent";
    }
    Serial.print("Gia trị nhan ve Acc: ");
    Serial.println(sidUser);
    Serial.println(sUserESP);
    Serial.println(sPassESP);
    iid_User = sidUser.toInt();
    if(iid_User < 6)
    {
        Save_user1 = ReadEEPROM(AdEE_User1_Start,AdEE_User1_End,Dodai_id);
    
        Save_user2 = ReadEEPROM(AdEE_User2_Start,AdEE_User2_End,Dodai_id);
       
        Save_user3 = ReadEEPROM(AdEE_User3_Start,AdEE_User3_End,Dodai_id);
        
        Save_user4 = ReadEEPROM(AdEE_User4_Start,AdEE_User4_End,Dodai_id);
        
        Save_user5 = ReadEEPROM(AdEE_User5_Start,AdEE_User5_End,Dodai_id);
        if(iid_User == id_user5)
        {
          if(Save_user5 == "")
          {
             user5 = sUserESP;
             pass5 = sPassESP;
             WriteEEPROM_Acc(AdEE_User5_Start,AdEE_User5_End,user5);
             WriteEEPROM_Acc(AdEE_Pass5_Start,AdEE_Pass5_End,pass5);
          }
          else iid_User--;
        }
        if(iid_User == id_user4)
        {
           if(Save_user4 == "")
           {
             user4 = sUserESP;
             pass4 = sPassESP;
             WriteEEPROM_Acc(AdEE_User4_Start,AdEE_User4_End,user4);
             WriteEEPROM_Acc(AdEE_Pass4_Start,AdEE_Pass4_End,pass4);
           }
           else iid_User--;
           
        }
        if(iid_User == id_user3)
        {
           if(Save_user3 == "")
           {
               user3 = sUserESP;
               pass3 = sPassESP;
               WriteEEPROM_Acc(AdEE_User3_Start,AdEE_User3_End,user3);
               WriteEEPROM_Acc(AdEE_Pass3_Start,AdEE_Pass3_End,pass3);
           }
           else iid_User--;
        }
        if(iid_User == id_user2)
        {
           if(Save_user2 == "")
           {
             user2 = sUserESP;
             pass2 = sPassESP;
             WriteEEPROM_Acc(AdEE_User2_Start,AdEE_User2_End,user2);
             WriteEEPROM_Acc(AdEE_Pass2_Start,AdEE_Pass2_End,pass2);
           }
           else iid_User--; 
        }
        
        if(iid_User == id_user1)
        {
           user1 = sUserESP;
           pass1 = sPassESP;
           WriteEEPROM_Acc(AdEE_User1_Start,AdEE_User1_End,user1);
           WriteEEPROM_Acc(AdEE_Pass1_Start,AdEE_Pass1_End,pass1);
        }
        request->send(200, "text/plain", "OK!");
    }
    else request->send(200, "text/plain", "you over Acc");
    
});

// phan modify tai khoan nguoi dung
server80.on("/api/modify/usermanerment",HTTP_GET, [](AsyncWebServerRequest *request){ // Load len server sau moi lan updte
  Serial.println("nhay vao phan modify ");
   String sUserESP, sPassESP, sidUser;
   int iid_User;
   // bat key de check:
   if (request->hasParam("id_row") && request->hasParam("DataUser_wb") && request->hasParam("DataPass_wb")){
         sidUser = request->getParam("id_row")->value();
         sUserESP = request->getParam("DataUser_wb")->value();
         sPassESP = request->getParam("DataPass_wb")->value();
    }
    else {
         sUserESP = "No message sent";
    }
    Serial.print("Gia trị nhan ve Acc: ");
    Serial.println(sidUser);
    Serial.println(sUserESP);
    Serial.println(sPassESP);
    iid_User = sidUser.toInt();
//    if(iid_User == id_user1)
//    {
//      Save_user1 = ReadEEPROM(AdEE_User1_Start,AdEE_User1_End,Dodai_id);
//      Save_pass1 = ReadEEPROM(AdEE_Pass1_Start,AdEE_Pass1_End,Dodai_id);
//       user1 = sUserESP;
//       pass1 = sPassESP;
//       if(Save_user1 != user1 || Save_pass1 != pass1)
//       {
//          WriteEEPROM_Acc(AdEE_User1_Start,AdEE_User1_End,user1);
//          WriteEEPROM_Acc(AdEE_Pass1_Start,AdEE_Pass1_End,pass1);
//       } 
//    }
    if(iid_User == id_user2)
    {
      Save_user2 = ReadEEPROM(AdEE_User2_Start,AdEE_User2_End,Dodai_id);
      Save_pass2 = ReadEEPROM(AdEE_Pass2_Start,AdEE_Pass2_End,Dodai_id);
      user2 = sUserESP;
      pass2 = sPassESP;
      if(Save_user2 != user2 || Save_pass2 != pass2)
      {
         WriteEEPROM_Acc(AdEE_User2_Start,AdEE_User2_End,user2);
         WriteEEPROM_Acc(AdEE_Pass2_Start,AdEE_Pass2_End,pass2);
      } 
    }
    if(iid_User == id_user3)
    {
      Save_user3 = ReadEEPROM(AdEE_User3_Start,AdEE_User3_End,Dodai_id);
      Save_pass3 = ReadEEPROM(AdEE_Pass3_Start,AdEE_Pass3_End,Dodai_id);
       user3 = sUserESP;
       pass3 = sPassESP;
       if(Save_user3 != user3 || Save_pass3 != pass3)
       {
          WriteEEPROM_Acc(AdEE_User3_Start,AdEE_User3_End,user3);
          WriteEEPROM_Acc(AdEE_Pass3_Start,AdEE_Pass3_End,pass3);
       }
       
    }
    if(iid_User == id_user4)
    {
      Save_user4 = ReadEEPROM(AdEE_User4_Start,AdEE_User4_End,Dodai_id);
      Save_pass4 = ReadEEPROM(AdEE_Pass4_Start,AdEE_Pass4_End,Dodai_id);
       user4 = sUserESP;
       pass4 = sPassESP;
        if(Save_user4 != user4 || Save_pass4 != pass4)
        {
          WriteEEPROM_Acc(AdEE_User4_Start,AdEE_User4_End,user4);
          WriteEEPROM_Acc(AdEE_Pass4_Start,AdEE_Pass4_End,pass4);
        } 
    }
    if(iid_User == id_user5)
    {
      Save_user5 = ReadEEPROM(AdEE_User5_Start,AdEE_User5_End,Dodai_id);
      Save_pass5 = ReadEEPROM(AdEE_Pass5_Start,AdEE_Pass5_End,Dodai_id);
       user5 = sUserESP;
       pass5 = sPassESP;
       if(Save_user5 != user5 || Save_pass5 != pass5)
       {
          WriteEEPROM_Acc(AdEE_User5_Start,AdEE_User5_End,user5);
          WriteEEPROM_Acc(AdEE_Pass5_Start,AdEE_Pass5_End,pass5);
       }
    }
    request->send(200, "text/plain", "OK!");
    Serial.println("Chinh sua xong phan modify");
});
// phan delete
server80.on("/api/delete/usermanerment",HTTP_GET, [](AsyncWebServerRequest *request){ // Load len server sau moi lan updte
  Serial.println("nhay vao phan modify ");
   String sidUser, sgetUser;
   int iid_User;
   // bat key de check:
   if (request->hasParam("id_row")&& request->hasParam("nameUser")){
         sidUser = request->getParam("id_row")->value();
         sgetUser = request->getParam("nameUser")->value();
    }
    else {
         sidUser = "No message sent";
    }
    Serial.print("Gia trị nhan ve Acc: ");
    Serial.println(sidUser);
    iid_User = sidUser.toInt();
    
    Save_user1 = ReadEEPROM(AdEE_User1_Start,AdEE_User1_End,Dodai_id);
    
    Save_user2 = ReadEEPROM(AdEE_User2_Start,AdEE_User2_End,Dodai_id);
   
    Save_user3 = ReadEEPROM(AdEE_User3_Start,AdEE_User3_End,Dodai_id);
    
    Save_user4 = ReadEEPROM(AdEE_User4_Start,AdEE_User4_End,Dodai_id);
    
    Save_user5 = ReadEEPROM(AdEE_User5_Start,AdEE_User5_End,Dodai_id);
    
//    if(sgetUser == Save_user1)
//    {
//      ClearEEPROM(AdEE_User1_Start,AdEE_User1_End);
//      ClearEEPROM(AdEE_Pass1_Start,AdEE_Pass1_End);
//    }
      if(iid_User != 1 && iid_User <6)
      {
         if(sgetUser == Save_user2)
          {
            ClearEEPROM(AdEE_User2_Start,AdEE_User2_End);
            ClearEEPROM(AdEE_Pass2_Start,AdEE_Pass2_End);
            
          }
          if(sgetUser == Save_user3)
          {
            ClearEEPROM(AdEE_User3_Start,AdEE_User3_End);
            ClearEEPROM(AdEE_Pass3_Start,AdEE_Pass3_End);
          }
          if(sgetUser == Save_user4)
          {
            ClearEEPROM(AdEE_User4_Start,AdEE_User4_End);
            ClearEEPROM(AdEE_Pass4_Start,AdEE_Pass4_End);
          }
          if(sgetUser == Save_user5)
          {
            ClearEEPROM(AdEE_User5_Start,AdEE_User5_End);
            ClearEEPROM(AdEE_Pass5_Start,AdEE_Pass5_End);
          }
          request->send(200, "text/plain", "OK!");
      }
      else request->send(200, "text/plain", "fail!");
});

//**************************************** PHAN NAY CAU HÌNH CHO GPIO InPut thi ko can**************************

server80.on("/api/setting/config/GPIO",HTTP_GET, [](AsyncWebServerRequest *request){ // Load len server sau moi lan updte
   String PinNumESP, SetModeESP, sStatu;
   PinNumESP ="",SetModeESP ="",sStatu="";
   
   if (request->hasParam("PinNum") && request->hasParam("SetMode") && request->hasParam("status")) {
         PinNumESP = request->getParam("PinNum")->value();
         SetModeESP = request->getParam("SetMode")->value();
         sStatu = request->getParam("status")->value();
    }
    else {
         Serial.println("Khong co DL nao nhan ve!!");
    }
    Serial.println(PinNumESP);
    Serial.println(SetModeESP);
       // thuc hien lenh dk o day
    if(PinNumESP =="1")
    {
       if(SetModeESP == "INPUT" && sStatu != ""){
               setMode_PIN_2(1); //D1
               WriteEEPROM_Acc(AdEE_Status_PIN2_Start,AdEE_Status_PIN2_End,sStatu);
               request->send(200, "text/plain", "Pin 1: Input | Mode: " + sStatu);
              
        }
        else if(SetModeESP == "OUTPUT" && sStatu != ""){ 
                request->send(200, "text/plain", "You cant config Output, Can you try again");
        } else {
          request->send(200, "text/plain", "You try again!");
        }
    }
    else if(PinNumESP =="2")
    {
       if(SetModeESP == "INPUT" && sStatu != ""){
               setMode_PIN_3(1); //D2
               WriteEEPROM_Acc(AdEE_Status_PIN3_Start,AdEE_Status_PIN3_End,sStatu);
               request->send(200, "text/plain", "Pin 2: Input | Mode: "+ sStatu);
        }
        else if(SetModeESP == "OUTPUT"){ 
          request->send(200, "text/plain", "You cant config Output, Can you try again"); 
        } else {
          request->send(200, "text/plain", "You try again!");
        }  
    }
    else if(PinNumESP =="3"){
        if(SetModeESP == "INPUT" && sStatu != ""){
               setMode_PIN_4(1);
               WriteEEPROM_Acc(AdEE_Status_PIN4_Start,AdEE_Status_PIN4_End,sStatu);
               request->send(200, "text/plain", "Pin 3: Input | Mode: " + sStatu);
        }
        else if(SetModeESP == "OUTPUT"){ 
          request->send(200, "text/plain", "You cant config Output, Can you try again");
        }
        else {
          request->send(200, "text/plain", "You try again!");
        }  
    }
    else if(PinNumESP =="4"){
        if(SetModeESP == "INPUT" && sStatu != ""){
               setMode_PIN_5(1);
               WriteEEPROM_Acc(AdEE_Status_PIN5_Start,AdEE_Status_PIN5_End,sStatu);
               request->send(200, "text/plain", "Pin 4: Input | Mode: "+sStatu);
        }
        else if(SetModeESP == "OUTPUT"){ 
            request->send(200, "text/plain", "You cant config Output, Can you try again");
        }
        else {
          request->send(200, "text/plain", "You try again!");
        } 
    }
    else if(PinNumESP =="5"){
        if(SetModeESP == "INPUT" && sStatu != ""){
               setMode_PIN_8(1);
               WriteEEPROM_Acc(AdEE_Status_PIN8_Start,AdEE_Status_PIN8_End,sStatu);
               request->send(200, "text/plain", "Pin 5: Input | Mode: "+sStatu);
        }
        else if(SetModeESP == "OUTPUT"){ 
           request->send(200, "text/plain", "You cant config Output, Can you try again");
        }
        else {
          request->send(200, "text/plain", "You try again!");
        } 
    }
    else if(PinNumESP =="6"){
        if(SetModeESP == "INPUT" && sStatu != ""){
               setMode_PIN_9(1);
               WriteEEPROM_Acc(AdEE_Status_PIN9_Start,AdEE_Status_PIN9_End,sStatu);
               request->send(200, "text/plain", "Pin 6: Input | Mode: "+ sStatu);
        }
        else if(SetModeESP == "OUTPUT"){ 
           request->send(200, "text/plain", "You cant config Output, Can you try again");
        }
        else {
          request->send(200, "text/plain", "You try again!");
        } 
    }
    else if(PinNumESP =="7"){
        if(SetModeESP == "INPUT" && sStatu != ""){
               setMode_PIN_7(1);
               WriteEEPROM_Acc(AdEE_Status_PIN7_Start,AdEE_Status_PIN7_End,sStatu);
               request->send(200, "text/plain", "Pin 7: Input | Mode: "+ sStatu);
        }
        else if(SetModeESP == "OUTPUT"){ 
            request->send(200, "text/plain", "You cant config Output, Can you try again");
        }
        else {
          request->send(200, "text/plain", "You try again!");
        } 
    }
     else if(PinNumESP =="8"){
        if(SetModeESP == "INPUT" && sStatu != ""){
               setMode_PIN_8(1);
                WriteEEPROM_Acc(AdEE_Status_PIN8_Start,AdEE_Status_PIN8_End,sStatu);
               request->send(200, "text/plain", "Pin 8: Input | Mode: "+sStatu);
        }
        else if(SetModeESP == "OUTPUT"){ 
               request->send(200, "text/plain", "You cant config Output, Can you try again");
        }
        else {
          request->send(200, "text/plain", "You try again!");
        } 
    }
    else {
      request->send(200, "text/plain", "You enter config that wrong! can you try again: ....");
    } 
});

//// *********phan nay la nut nhan cho button tat mo cac chan I/O********************
server80.on("/api/button",HTTP_GET, [](AsyncWebServerRequest *request){ // Load len server sau moi lan updte
    String sPinNo, sU, sP,sControl;
      // bat key de check:
      if (request->hasParam("Pin") && request->hasParam("U") && request->hasParam("P") && request->hasParam("control")){
         sPinNo = request->getParam("Pin")->value();
         sU = request->getParam("U")->value();
         sP = request->getParam("P")->value();
         sControl = request->getParam("control")->value();
      }
      else {
          sPinNo = "No message sent";
      }
       Serial.println("Gia trị nhan ve: ");
        Serial.print("user nhan: ");
        Serial.println(sU);
        Serial.print("Pass nhan: ");
        Serial.println(sP);
        Serial.print("Pin so nhan: ");
       Serial.println(sPinNo);
       Serial.print("Control nhan: ");
       Serial.println(sControl);
       user1 = "", pass1 = "",user2 ="",pass2 ="",user3 ="",pass3="",user4="", pass4 ="",user5 ="",pass5 = "";
      user1 = ReadEEPROM(AdEE_User1_Start,AdEE_User1_End,Dodai_id);
      pass1 = ReadEEPROM(AdEE_Pass1_Start,AdEE_Pass1_End,Dodai_id);
      user2 = ReadEEPROM(AdEE_User2_Start,AdEE_User2_End,Dodai_id);
      pass2 = ReadEEPROM(AdEE_Pass2_Start,AdEE_Pass2_End,Dodai_id);
      user3 = ReadEEPROM(AdEE_User3_Start,AdEE_User3_End,Dodai_id);
      pass3 = ReadEEPROM(AdEE_Pass3_Start,AdEE_Pass3_End,Dodai_id);
      user4 = ReadEEPROM(AdEE_User4_Start,AdEE_User4_End,Dodai_id);
      pass4 = ReadEEPROM(AdEE_Pass4_Start,AdEE_Pass4_End,Dodai_id);
      user5 = ReadEEPROM(AdEE_User5_Start,AdEE_User5_End,Dodai_id);
      pass5 = ReadEEPROM(AdEE_Pass5_Start,AdEE_Pass5_End,Dodai_id);
      Serial.println("Gia trị EEProm: ");
      Serial.print("user EPP: ");
      Serial.println(user1);
      Serial.print("Pass EPP: ");
      Serial.println(pass1);
       if((sU == user1 || sU == user2 || sU == user3 || sU == user4 || sU == user5) &&(sP == pass1 || sP == pass2 || sP == pass3 || sP == pass4 || sP == pass5))
       {
           if(sPinNo == "1" && sControl !="")
           {
              Ctr_Pin[0] = sControl;
              get_eve_PinCh1 = true;
              Serial.print("gia tri cua thang Ctr_Pin1: ");
              Serial.println(Ctr_Pin[0]);
              request->send(200, "text/plain", "ok");
           }
           else if(sPinNo == "2" && sControl !="")
           {
              Ctr_Pin[1] = sControl;
              get_eve_PinCh2 = true;
              Serial.print("gia tri cua thang Ctr_Pin2: ");
              Serial.println(Ctr_Pin[1]);
              request->send(200, "text/plain", "ok");
           }
           else if(sPinNo == "3" && sControl !="")
           {
              Ctr_Pin[2] = sControl;
              get_eve_PinCh3 = true;
              Serial.print("gia tri cua thang Ctr_Pin3: ");
              Serial.println(Ctr_Pin[2]);
               request->send(200, "text/plain", "ok");
           }
           else if(sPinNo == "4" && sControl !="")
           {
              Ctr_Pin[3] = sControl;
              get_eve_PinCh4 = true;
              Serial.print("gia tri cua thang Ctr_Pin4: ");
              Serial.println(Ctr_Pin[3]);
               request->send(200, "text/plain", "ok");
           }
           else if(sPinNo == "5" && sControl !="")
           {
              Ctr_Pin[4] = sControl;
              get_eve_PinCh5 = true;
              Serial.print("gia tri cua thang Ctr_Pin5: ");
              Serial.println(Ctr_Pin[4]);
               request->send(200, "text/plain", "ok");
           }
           else if(sPinNo == "6" && sControl !="")
           {
              Ctr_Pin[5] = sControl;
              get_eve_PinCh6 = true;
              Serial.print("gia tri cua thang Ctr_Pin6: ");
              Serial.println(Ctr_Pin[5]);
              request->send(200, "text/plain", "ok");
           }
           
           
       }
       else {
         Serial.println("ban sai pass roi!");
         request->send(200, "text/plain", "ok");
       }
       // thu hine lenh o day
       
});
//// ********* DEVICE INFORMATION **********
server80.on("/ILoadData/DeviceInf", HTTP_GET, [](AsyncWebServerRequest *request) {
    String sCheckOpen_Device;
    int Num, iCountIntOut;
      // bat key de check:
      if (request->hasParam("CheckOpen_wb_Inf")){
         sCheckOpen_Device = request->getParam("CheckOpen_wb_Inf")->value();
      }
     else {
          sCheckOpen_Device = "No message sent";
      }
      Serial.print("CheckOpen DeviceInf4: ");
      Serial.println(sCheckOpen_Device);
      if(sCheckOpen_Device == "0")
      {
         // doc tu EEProm ra name va Num
         NameDevice = ReadEEPROM(AdEE_NameDevice_Start,AdEE_NameDevice_End,Dodai_id);
         Num = (int)EEPROM.read(AdEE_NumDevice);
         
         iCountIntOut = CountIntOut();
         // SeriDevice la co dinh
         Write_JsonInfor(NameDevice,String(Num),SeriDevice,String(iCountIntOut),String(8-iCountIntOut));
         request->send(200,"text/plain",DataJson_Network);
         Serial.println("truyen DL len thanh cong o phan Information");
     }
     else request->send(200,"text/plain","Finish");
  });
  server81.begin();
  server80.begin();
  Serial.println("Finish!!!");
  ticker.attach(1, tick);  // chơp chớp con led cho biết để rơi vào chế độ hoat dong
}
////******************LOOP**************************
void loop() {
   if(get_eve_PinCh1)
   {
     get_eve_PinCh1 =0;
     // thu hien lenh
   }
   if(get_eve_PinCh2)
   {
     get_eve_PinCh2 =0;
     // thu hien lenh
   }
   if(get_eve_PinCh3)
   {
     get_eve_PinCh3 =0;
     // thu hien lenh
   }
   if(get_eve_PinCh4)
   {
     get_eve_PinCh4 =0;
     // thu hien lenh
   }
   if(get_eve_PinCh5)
   {
     get_eve_PinCh5 =0;
     // thu hien lenh
   }
   if(get_eve_PinCh6)
   {
     get_eve_PinCh6 =0;
     // thu hien lenh
   }
   
   if(WiFi.status() != WL_CONNECTED)
   {
      ticker.attach(0.1, tick);  // chơp chớp con led cho biết để rơi vào chế độ hoat dong
      KhoiTaolaiwifi();
      ticker.attach(1, tick);  // chơp chớp con led cho biết để rơi vào chế độ hoat dong
   }
   
   if(digitalRead(dPIN7)==1 || digitalRead(dPIN6)==0) // Chan D8 tren Board - xet phan input mach noi tiep
   {
       if(millis() - pre_time_Err >=100)
       {
          digitalWrite(dPIN1, !digitalRead(dPIN1));     // set pin to the opposite state
          pre_time_Err = millis();
       }
   }   
   
   if(digitalRead(dPIN6)==1 && digitalRead(dPIN7)==0) // Chan D7-dPIN6 tren Board - xet phan input mach song song- ch do binh thuong
   {
      digitalWrite(dPIN1, 0);     // set pin to the opposite state
   }

   if(millis() - pre_time > 5000)
   {
      int val = analogRead(A0);
      float vol = (float)val * 3.3/1024;
      ftemp = vol * 100.2f;
      //Serial.print("Temp: ");
      //Serial.println(ftemp);
      pre_time = millis();
   }
   if(getevent_network)
    {
        ticker.detach();
        getevent_network = false;
        Serial.println("bat dau cau hinh IP ESP: "); 
        KhoiTaolaiwifi();
        delay(1000);
        Serial.println("ket thuc cau hinh IP ESP: ");
        ticker.attach(1, tick);  // chơp chớp con led cho biết để rơi vào chế độ hoat dong  
    } 
    if(get_eve_renamewifi)
    {
      String conv_ssidapp="",conv_passapp="";
       get_eve_renamewifi = 0;
       ssidapp ="",passapp="";
       conv_ssidapp = ReadEEPROM(AdEE_AP_SSID_Start,AdEE_AP_SSID_End,Dodai_id);
       conv_passapp = ReadEEPROM(AdEE_AP_PASS_Start,AdEE_AP_PASS_End,Dodai_id);
       ssidapp = conv_ssidapp.c_str();
       passapp = conv_passapp.c_str();
       Serial.print("SSID app: "); Serial.println(ssidapp);
       Serial.print("PASS app: "); Serial.println(passapp);
        Serial.println("");
        WiFi.softAP(ssidapp, passapp);
        IPAddress IP = WiFi.softAPIP();
        Serial.print("AP IP address: ");
        Serial.println(IP);
        Serial.println("Rename wifi finish!");
        delay(1000);
    }
   NutNhanD3(); // cau hinh IP
   if(Stop_btn)
   {
      if(itimeReset<4)
      {
         readyCountReset = 0;
         itimeReset = 0;
         Stop_btn = 0; 
      }
      else if(itimeReset > 4 && itimeReset < 10){
        // thuc hien lenh o day 
          readyCountReset = 0;
          itimeReset = 0;
          Stop_btn = 0;
         ClearEEPROM(AdEE_Name_Wifi_Start,AdEE_Name_Wifi_End);
         ClearEEPROM(AdEE_Pass_Wifi_Start,AdEE_Pass_Wifi_End);
         ClearEEPROM(AdEE_IPv4_Start,AdEE_IPv4_End);
         ClearEEPROM(AdEE_Gateway_Start,AdEE_Gateway_End);
         ClearEEPROM(AdEE_Sub_Start,AdEE_Sub_End);
         Serial.println("Xoa xong");
         ESP.restart();   
      }
      else if(itimeReset >10)
      {
          // khoi phuc cai dat goc
          readyCountReset = 0;
          itimeReset = 0;
          Stop_btn = 0;
          RestoreConfig();
          Serial.println("Restore finish!");
          ESP.restart();  
      }
   }
}


///*****HAM CON*********************
//void ScanStatusPin()
//{
//  if(iShowPin[0]) // nt
//  {
//     if(digitalRead(dPIN2)) //D1 cam bien neu 1 impact - D8 ktra tro
//     {
//        
//     }
//  }
//  else //ss
//  {
//    
//  }
//  if(iShowPin[1])
//  {
//      
//  }
//  else 
//  {
//    
//  }
//  if(iShowPin[2])
//  {
//    
//  }
//  else
//  {
//    
//  }
//  if(iShowPin[3])
//  {
//    
//  }
//  else
//  {
//    
//  }
//  if(iShowPin[4])
//  {
//    
//  }
//  else
//  {
//    
//  }
//  if(iShowPin[5])
//  {
//    
//  }
//  else
//  {
//    
//  }
//}
void RestoreConfig()
{
          // Device Name
          NameDevice ="Control Center";
          WriteEEPROM_Acc(AdEE_NameDevice_Start,AdEE_NameDevice_End,NameDevice);
          WriteEEPROM_iOneVal(AdEE_NumDevice,NumDevice);
          // user name & pass word
          WriteEEPROM_Acc(AdEE_User1_Start,AdEE_User1_End,user1);
          WriteEEPROM_Acc(AdEE_Pass1_Start,AdEE_Pass1_End,pass1);
          ClearEEPROM(AdEE_User2_Start,AdEE_User2_End);
          ClearEEPROM(AdEE_Pass2_Start,AdEE_Pass2_End);
          ClearEEPROM(AdEE_User3_Start,AdEE_User3_End);
          ClearEEPROM(AdEE_Pass3_Start,AdEE_Pass3_End);
          ClearEEPROM(AdEE_User4_Start,AdEE_User4_End);
          ClearEEPROM(AdEE_Pass4_Start,AdEE_Pass4_End);
          ClearEEPROM(AdEE_User5_Start,AdEE_User5_End);
          ClearEEPROM(AdEE_Pass5_Start,AdEE_Pass5_End);
          // Status Pin
          WriteEEPROM_Acc(AdEE_Status_PIN1_Start,AdEE_Status_PIN1_End,"B"); // vi tri nay cho D0 nhung ko dung
          WriteEEPROM_Acc(AdEE_Status_PIN2_Start,AdEE_Status_PIN2_End,"B");
          WriteEEPROM_Acc(AdEE_Status_PIN3_Start,AdEE_Status_PIN3_End,"B");
          WriteEEPROM_Acc(AdEE_Status_PIN4_Start,AdEE_Status_PIN4_End,"B");
          WriteEEPROM_Acc(AdEE_Status_PIN5_Start,AdEE_Status_PIN5_End,"B");
          WriteEEPROM_Acc(AdEE_Status_PIN6_Start,AdEE_Status_PIN6_End,"B");
          WriteEEPROM_Acc(AdEE_Status_PIN7_Start,AdEE_Status_PIN7_End,"B");
          WriteEEPROM_Acc(AdEE_Status_PIN8_Start,AdEE_Status_PIN8_End,"B");
          WriteEEPROM_Acc(AdEE_Status_PIN9_Start,AdEE_Status_PIN9_End,"B");
          // lua chon cach noi tro la song song hay noi tiep
          WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin1,1);
          WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin2,1);
          WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin3,1);
          WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin4,1);
          WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin5,1);
          WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin6,1);
          WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin7,1);
          WriteEEPROM_iOneVal(AdEE_Type_Resistor_Pin8,1);
         
          setMode_PIN_1(0);
          setMode_PIN_2(1);
          setMode_PIN_3(1);
          setMode_PIN_4(1);
          setMode_PIN_5(1);
          setMode_PIN_6(1);
          setMode_PIN_7(1);
          setMode_PIN_8(1);
          setMode_PIN_9(1);
          // SSID & Pass
           WriteEEPROM_Acc(AdEE_Name_Wifi_Start,AdEE_Name_Wifi_End,"ESP8266");
           WriteEEPROM_Acc(AdEE_Pass_Wifi_Start,AdEE_Pass_Wifi_End,"123456789");
           ticker.attach(1, tick);  // chơp chớp con led cho biết để rơi vào chế độ hoat dong
}
boolean Chong_Doi_D3()// int char float ngoại trừ void
{
  int sta =!digitalRead(D3); // đọc trạng thái nút nhấn
  return sta;// khi co nhan nut la true
}
float NutNhanD3()
{
  int Status1 = Chong_Doi_D3();
  if(Status1 == true)
     readyCountReset = 1;
}

void ConfigPin_Default()
{
  setMode_PIN_1(0);
  setMode_PIN_2(1);
  setMode_PIN_3(1);
  setMode_PIN_4(1);
  setMode_PIN_5(1);
  setMode_PIN_6(1);
  setMode_PIN_7(1);
  setMode_PIN_8(1);
  setMode_PIN_9(1);
}
void Config_IO()
{
  ConfigPin_Default();
}

// ko biet vi sao ham nay tra ve chua dc can xem lai/ gio dang chay truc tip trong ctrinh con ra bat tien-> chua toi uu code
int Separate_String_IP(String inputString,int ptuso)
{
 int ivalue1, ivalue2, ivalue3, ivalue4; 
 int commaIndex = inputString.indexOf('.');
 int secondCommaIndex = inputString.indexOf('.', commaIndex+1);
 int thirdCommaIndex = inputString.indexOf('.', secondCommaIndex +1);
 
 String firstValue = inputString.substring(0, commaIndex);
 String secondValue = inputString.substring(commaIndex+1, secondCommaIndex);
 String thirdValue = inputString.substring(secondCommaIndex+1, thirdCommaIndex); //To the end of the string 
 String fourValue = inputString.substring(thirdCommaIndex+1); //To the end of the string
 ivalue1 =  firstValue.toInt();
 ivalue2 =  secondValue.toInt();
 ivalue3 =  thirdValue.toInt();
 ivalue4 =  fourValue.toInt();
 if(ptuso==1)
    return(ivalue1);
 else if(ptuso==2)
    return(ivalue2);
 else if(ptuso==3)
    return(ivalue3);
 else if(ptuso==4)
    return(ivalue4);

}

void Write_Json_one_para(String Name,String DataTranss) // truyen DataJson_one_para
{
  DataJson_one_para = "";
  // cấu trúc của JSON
  DynamicJsonBuffer jsonBuffer;
   //DataJson_one_para = "{\"" + Name + "\":\"" + DataTranss + "\"}";
  JsonObject& root = jsonBuffer.createObject(); 
  root[Name] = DataTranss;
  // kiem tra xem dinh dang json da dung chua
      if(!root.success()) {
      Serial.println("parseObject() failed");
  }
  root.printTo(DataJson_one_para);
  jsonBuffer.clear();
  Serial.print("Chuoi Json in ra - ham: ");
  Serial.println(DataJson_one_para);
}
// truyen mang JSON len web phan usermanerment
void AllWrite_JsonUserAndData(String ValueSen)
{
  String P[20],MP1,MP2,MP3,MP4,MP5,MP6,MP7,MP8;
  DataJson ="";
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  //Serial.println("Da Nhay vao phan giao dien lay bien");
  Save_user1 = "", Save_pass1 = "", Save_user2 ="", Save_pass2 ="",Save_user3 ="",Save_pass3="",Save_user4="", Save_pass4 ="",Save_user5 ="",Save_pass5 = "";
  Save_user1 = ReadEEPROM(AdEE_User1_Start,AdEE_User1_End,Dodai_id);
  Save_pass1 = ReadEEPROM(AdEE_Pass1_Start,AdEE_Pass1_End,Dodai_id);
  Save_user2 = ReadEEPROM(AdEE_User2_Start,AdEE_User2_End,Dodai_id);
  Save_pass2 = ReadEEPROM(AdEE_Pass2_Start,AdEE_Pass2_End,Dodai_id);
  Save_user3 = ReadEEPROM(AdEE_User3_Start,AdEE_User3_End,Dodai_id);
  Save_pass3 = ReadEEPROM(AdEE_Pass3_Start,AdEE_Pass3_End,Dodai_id);
  Save_user4 = ReadEEPROM(AdEE_User4_Start,AdEE_User4_End,Dodai_id);
  Save_pass4 = ReadEEPROM(AdEE_Pass4_Start,AdEE_Pass4_End,Dodai_id);
  Save_user5 = ReadEEPROM(AdEE_User5_Start,AdEE_User5_End,Dodai_id);
  Save_pass5 = ReadEEPROM(AdEE_Pass5_Start,AdEE_Pass5_End,Dodai_id);
  
  
  P[1] = digitalRead(dPIN2); //D1
  P[2] = digitalRead(dPIN3); //D2
  P[3] = digitalRead(dPIN4); //D5
  P[4] = digitalRead(dPIN5); //D6
  P[5] = digitalRead(dPIN8); //D9
  P[6] = digitalRead(dPIN9); //G10
  
  P[7] = digitalRead(dPIN6); //D7
  P[8] = digitalRead(dPIN7); //D8
  MP1="",MP2="",MP3="",MP4="",MP5="",MP6="";
  
  MP1 = ReadEEPROM(AdEE_Status_PIN2_Start,AdEE_Status_PIN2_End,Dodai_id);
  MP2 = ReadEEPROM(AdEE_Status_PIN3_Start,AdEE_Status_PIN3_End,Dodai_id);
  MP3 = ReadEEPROM(AdEE_Status_PIN4_Start,AdEE_Status_PIN4_End,Dodai_id);
  MP4 = ReadEEPROM(AdEE_Status_PIN5_Start,AdEE_Status_PIN5_End,Dodai_id);
  MP5 = ReadEEPROM(AdEE_Status_PIN8_Start,AdEE_Status_PIN8_End,Dodai_id);
  MP6 = ReadEEPROM(AdEE_Status_PIN9_Start,AdEE_Status_PIN9_End,Dodai_id);
  
  //Serial.println(MP1);
       root["u1"] = Save_user1;
       root["p1"] = Save_pass1;
       root["u2"] = Save_user2;
       root["p2"] = Save_pass2;
       root["u3"] = Save_user3;
       root["p3"] = Save_pass3;
       root["u4"] = Save_user4;
       root["p4"] = Save_pass4;
       root["u5"] = Save_user5;
       root["p5"] = Save_pass5;
       ///
       root["MP1"] = MP1;
       root["MP2"] = MP2;
       root["MP3"] = MP3;
       root["MP4"] = MP4;
       root["MP5"] = MP5;
       root["MP6"] = MP6;
       
       root["Pin1"] = P[1];
       root["Pin2"] = P[2];
       root["Pin3"] = P[3];
       root["Pin4"] = P[4];
       root["Pin5"] = P[5];
       root["Pin6"] = P[6];
       
       root["SS"] = P[7];
       root["NT"] = P[8];
       root["Val"] = ValueSen;
        
  // kiem tra xem dinh dang json da dung chua
      if(!root.success()) {
      Serial.println("parseObject() failed");
  }
  root.printTo(DataJson); 
}
void Write_JsonStatusPin(String ValueSen)
{
  String P[20],MP1,MP2,MP3,MP4,MP5,MP6,MP7,MP8;
  DataJson ="";
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  
  //P[0] = digitalRead(dPIN1);
  P[1] = digitalRead(dPIN2); // D1
  P[2] = digitalRead(dPIN3); //D2
  P[3] = digitalRead(dPIN4);// D5
  P[4] = digitalRead(dPIN5);// D6
  P[5] = digitalRead(dPIN6);// D7 - ktra tro SS
  P[6] = digitalRead(dPIN7);// D8 - ktra tro NT
  P[7] = digitalRead(dPIN8); // D9
  P[8] = digitalRead(dPIN9); // GPIO 10
  root["Pin1"] = P[1]; // D1
  root["Pin2"] = P[2]; // D2
  root["Pin3"] = P[3]; // D5
  root["Pin4"] = P[4]; // D6
  root["Pin5"] = P[7]; // D9
  root["Pin6"] = P[8]; // GPIO10
  root["SS"] = P[5];   // Ktra tro SS
  root["NT"] = P[6];  // ktra tro NT
  root["Val"] = ValueSen;
        
  // kiem tra xem dinh dang json da dung chua
      if(!root.success()) {
      Serial.println("parseObject() failed");
  }
  root.printTo(DataJson); 
}
void Write_JsonUser(String DataU1, String DataPass1, String DataU2, String DataPass2, String DataU3, String DataPass3, String DataU4, String DataPass4,String DataU5,String DataPass5)
{
  DataJson ="";
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
       root["user1"] = DataU1;
       root["pass1"] = DataPass1;
       root["user2"] = DataU2;
       root["pass2"] = DataPass2;
       root["user3"] = DataU3;
       root["pass3"] = DataPass3;
       root["user4"] = DataU4;
       root["pass4"] = DataPass4;
       root["user5"] = DataU5;
       root["pass5"] = DataPass5;
  // kiem tra xem dinh dang json da dung chua
      if(!root.success()) {
      Serial.println("parseObject() failed");
  }
  root.printTo(DataJson);
}
void Write_JsonNetwork(String DataIPv4, String DataIPv4Sub, String DataGate, String DataSerPort, String DataMacAdd, String DataDNS, String DataPreDNS)
{
  DataJson_Network ="";
  DynamicJsonBuffer jsonBufferNetwork;
  JsonObject& root = jsonBufferNetwork.createObject();
       root["IP"] = DataIPv4;
       root["Subnet"] = DataIPv4Sub;
       root["Gateway"] = DataGate;
       root["SerPort"] = DataSerPort;
       root["Mac"] = DataMacAdd;
       root["DNS"] = DataDNS;
       root["preDNS"] = DataPreDNS;
  // kiem tra xem dinh dang json da dung chua
      if(!root.success()) {
      Serial.println("parseObject() failed");
  }
  root.printTo(DataJson_Network);
}
void Write_JsonInfor(String DataName, String DataNum, String DataSeri, String DataIn, String DataOut)
{
    DataJson_Network ="";
    DynamicJsonBuffer jsonBufferInfor;
    JsonObject& root = jsonBufferInfor.createObject();
       root["Name"] = DataName;
       root["Num"] = DataNum;
       root["Seri"] = DataSeri;
       root["In"] = DataIn;
       root["Out"] = DataOut;
       
  // kiem tra xem dinh dang json da dung chua
      if(!root.success()) {
      Serial.println("parseObject() failed");
  }
  root.printTo(DataJson_Network);
  jsonBufferInfor.clear();
}


//*************EEPROM*******************************************//

void WriteEEPROM_Acc(int Start_address, int end_address,String idvalue)
{
 // clear EEPROM vung ghi
  for(int i = Start_address + 1; i< end_address; i++)
  {
      EEPROM.write(i,0);
      delay(1);
  }
  // Lưu độ dài vào EEPROM
  EEPROM.write(Start_address, idvalue.length());
  delay(1);
  ////luu DL vao EEPROM
  for (int i = Start_address + 1; i < idvalue.length() + Start_address + 1; i++)
  {
    EEPROM.write(i, idvalue[i - (Start_address + 1)]);
    delay(1);
  }
  EEPROM.commit();
  delay(2);
}
void WriteEEPROM_iOneVal(int address,int value)
{
  EEPROM.write(address,value);
  EEPROM.commit();
  delay(1);
}
// doc thi can dia chi/ do dai va bien luu
String ReadEEPROM(int RStart_address, int Rend_address,int Rleng_id)
{
  String Buffer_id = "";
  // read do dai
  Rleng_id = int(EEPROM.read(RStart_address));
  //read gia tri
  for (int i = RStart_address + 1; i < Rleng_id + RStart_address + 1; i++)
  {
    Buffer_id += (char)EEPROM.read(i); 
    delay(1);
  }
  return(Buffer_id);
}
void ClearEEPROM(int StartClear, int EndClear)
{
  for (int i = StartClear ; i < EndClear ; i++)
  {
    EEPROM.write(i, 0);delay(1);
  }
  EEPROM.commit();delay(1);
}
void AllClearEEPROM()
{
  for (int i = 0 ; i < EEPROM_SIZE ; i++)
  {
    EEPROM.write(i, 0);delay(1);
  }
  EEPROM.commit();delay(1);
}

// *****************************************SET MODE FOR GPIO*********************************************************
void setMode_PIN_1(boolean statusP1)  //D0
{
  if(statusP1)
  {
    pinMode(dPIN1,INPUT);
    NumIntOut[0] = 1; 
  }
  else {
    pinMode(dPIN1,OUTPUT);
    NumIntOut[0]=0;
  }
  WriteEEPROM_iOneVal(AdEE_Status_Pin1,NumIntOut[0]);
}
void setMode_PIN_2(boolean statusP2) //D1
{
  if(statusP2)
  {
    NumIntOut[1] = 1;
     pinMode(dPIN2,INPUT);
  }
  else {
   
    NumIntOut[1] = 0;
    pinMode(dPIN2,OUTPUT);
  }
  WriteEEPROM_iOneVal(AdEE_Status_Pin2,NumIntOut[1]);
}

void setMode_PIN_3(boolean statusP3) //D2
{
  if(statusP3)
  {
    NumIntOut[2] = 1;
    pinMode(dPIN3,INPUT);
  }
  else {
    NumIntOut[2] = 0;
    pinMode(dPIN3,OUTPUT);
  }
  WriteEEPROM_iOneVal(AdEE_Status_Pin3,NumIntOut[2]);
}
void setMode_PIN_D3(boolean statusD3)
{
  if(statusD3)
  {
    //StatusPinMode_D3 = 1;
    pinMode(D3,INPUT);
  }
  else {
    //StatusPinMode_D3 = 0;
    pinMode(D3,OUTPUT);
  }
  WriteEEPROM_iOneVal(AdEE_Status_D3,1);
}
void setMode_PIN_D4(boolean statusD4)
{
  if(statusD4)
  {
    //StatusPinMode_D3 = 1;
    pinMode(D4,INPUT);
  }
  else {
    //StatusPinMode_D3 = 0;
    pinMode(D4,OUTPUT);
  }
  //WriteEEPROM_iOneVal(AdEE_Status_D3,1);
}

void setMode_PIN_4(boolean statusP4)  // D5
{
  if(statusP4)
  {
    NumIntOut[3] = 1; 
    pinMode(dPIN4,INPUT);
  }
  else {
    NumIntOut[3] =0;
    pinMode(dPIN4,OUTPUT);
  }
  WriteEEPROM_iOneVal(AdEE_Status_Pin4,NumIntOut[3]);
}
void setMode_PIN_5(boolean statusP5) //D6
{
  if(statusP5)
  {
     NumIntOut[4] = 1;
    pinMode(dPIN5,INPUT);
  }  
  else {
    NumIntOut[4]=0;
    
    pinMode(dPIN5,OUTPUT);
  }
   WriteEEPROM_iOneVal(AdEE_Status_Pin5,NumIntOut[4]);
   
}
void setMode_PIN_6(boolean statusP6) //D7
{
  if(statusP6)
  {
     NumIntOut[5]=1;
    pinMode(dPIN6,INPUT);
  }
  else {
    NumIntOut[5]=0;
    
    pinMode(dPIN6,OUTPUT);
  }
   WriteEEPROM_iOneVal(AdEE_Status_Pin6,NumIntOut[5]);
   
}
void setMode_PIN_7(boolean statusP7) //D8
{
  if(statusP7)
  {
    NumIntOut[6]=1;
    pinMode(dPIN7,INPUT);
  } 
  else {
    NumIntOut[6]=0;
    pinMode(dPIN7,OUTPUT);
  }
   WriteEEPROM_iOneVal(AdEE_Status_Pin7,NumIntOut[6]);
}
void setMode_PIN_8(boolean statusP8)  //D9
{
  if(statusP8){
    NumIntOut[7]=1;
    pinMode(dPIN8,INPUT);
  }
  else {
    NumIntOut[7]=0;
    pinMode(dPIN8,OUTPUT);
  }
  WriteEEPROM_iOneVal(AdEE_Status_Pin8,NumIntOut[7]);
  
}
void setMode_PIN_9(boolean statusP9)  //G10
{
  if(statusP9){
    NumIntOut[8]=1;
    pinMode(dPIN9,INPUT);
  }
  else {
    NumIntOut[8]=0;
    pinMode(dPIN9,OUTPUT);
  }
  WriteEEPROM_iOneVal(AdEE_Status_Pin9,NumIntOut[8]);
  
}
// ket noi wifi
void ConnectWiFi()
{
  str_ssid = "";
  str_pass = "";
  ssid = "";
  pass = "";
  str_ssid = ReadEEPROM(AdEE_Name_Wifi_Start,AdEE_Name_Wifi_End,Dodai_id);
  str_pass = ReadEEPROM(AdEE_Pass_Wifi_Start,AdEE_Pass_Wifi_End,Dodai_id);
  
  ssid = str_ssid.c_str();
  pass = str_pass.c_str();
  Serial.print("str_ssid: ");
  Serial.println(ssid);
  Serial.print("str_pass: ");
  Serial.println(pass);
  
  WiFi.mode(WIFI_AP_STA); WiFi.disconnect(); WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    count_time++;
    if (count_time >= 20)
    {
      Check_connectwifi = false;
      Serial.println("");
      Serial.println("Not Connect to wifi");
      count_time = 0;
      break;
    }
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    Check_connectwifi = true;
    count_time = 0;
  }
  else
  {
    Check_connectwifi = false;
    count_time = 0;
  }
}
void tick()
{
  int state = digitalRead(PIND4);  // get the current state of GPIO1 pin
  digitalWrite(PIND4, !state);     // set pin to the opposite state
  
}

void configwifikeyblynk()
{
  String conv_ssidapp="",conv_passapp="";
  delay(1000);
  Serial.println("");
  // doc tu EEPROM ra
  ssidapp = "",passapp="";
   conv_ssidapp = ReadEEPROM(AdEE_AP_SSID_Start,AdEE_AP_SSID_End,Dodai_id);
   conv_passapp = ReadEEPROM(AdEE_AP_PASS_Start,AdEE_AP_PASS_End,Dodai_id);
   ssidapp = conv_ssidapp.c_str();
   passapp = conv_passapp.c_str();
   Serial.print("SSID app: "); Serial.println(ssidapp);
   Serial.print("PASS app: "); Serial.println(passapp);
  WiFi.softAP(ssidapp, passapp);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  delay(2000);
  
  server81.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
   Serial.println("phan nay la phan configwifi");  
   request->send_P(200, "text/html", ConfigWifi_html);
     
  });
  server81.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    request->send_P(200, "text/html", ConfigWifi_html);
  });
  server81.on("/GetIP", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    if (Check_connectwifi)
    {
      IPaddress =  WiFi.localIP().toString();
      request->send_P(200, "text/html", IPaddress.c_str());
    }
    else
    {
      request->send_P(200, "text/html", "1");
    }
  });
  
  // nhan Dl tu web ve
  server81.on("/configwifi", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    IsData = false;
    int paramsNr = request->params();  // check xem cos bao nhieu tham so dc nhan
    for (int i = 0; i < paramsNr; i++)
    {
      AsyncWebParameter* p = request->getParam(i);
      Data = "";
      Data = p->value();
      if (Data.indexOf("{") != -1 && Data.indexOf("}") != -1)
      {
        IsData = true;
      }

    }
    request->send_P(200, "text/html", ConfigWifi_html);
  });
  
  server81.begin();
  Serial.println("Server start wifi config");
  while (true)
  {
    delay(1);
    if (IsData)
    {
      StaticJsonBuffer<200> jsonBuffer;
      JsonObject& JSON = jsonBuffer.parseObject(Data);
      if (!JSON.success())
      {
        Serial.println("Data JSON Error!!!");
        return;
      }
      else
      {
        Serial.println("Data JSON");
        Serial.println();
        if (JSON.containsKey("SSID") && JSON.containsKey("PASS"))
        {
          Serial.println("Write EEPROM Config");
          
          String ssid_tem = JSON["SSID"];
          String pass_tem = JSON["PASS"];
          str_ssid = "";
          str_pass = "";
          ssid = "";
          pass = "";
          str_ssid = ssid_tem;
          str_pass = pass_tem;
          ssid = str_ssid.c_str();
          pass = str_pass.c_str();
          
          Serial.print("ssid_config: ");
          Serial.println(ssid);
          Serial.print("pass_config: ");
          Serial.println(pass);
          WiFi.begin(ssid, pass);
          
          while (WiFi.status() != WL_CONNECTED)
          {
            delay(500);
            Serial.print(".");
            count_time++;
            if (count_time >= 30)
            {
              Check_connectwifi = false;
              Serial.println("");
              Serial.println("Not Connect to WIFI WEBSERVER");
              count_time = 0;
              break;
            }
          }

          if (WiFi.status() == WL_CONNECTED)
          {
            Serial.println();
            Serial.print("Successfully connected to WIFI Webserver");
            Serial.println(ssid);
            Serial.print("IP address: ");
            Serial.println(WiFi.localIP());
            WriteEEPROM_Acc(AdEE_Name_Wifi_Start,AdEE_Name_Wifi_End,str_ssid);
            WriteEEPROM_Acc(AdEE_Pass_Wifi_Start,AdEE_Pass_Wifi_End,str_pass);
         
            ticker.detach();
            Check_connectwifi = true;
           
          }
          else
          {
            Check_connectwifi = false;
          }
        }
      }
      IsData = false;
    }
    if (Check_connectwifi)
    {
      //WiFi.mode(WIFI_STA);
      break;
    }
  }
}

int CountIntOut()
{
     for(int i=0;i<9;i++)
     {
        if(NumIntOut[i]) CountMode++;
     }
     Buff_CountMode = CountMode;
     CountMode =0; 
     Serial.print("Pin Int/out: ");
     Serial.println(Buff_CountMode);
     return(Buff_CountMode);   
}
void KhoiTaolaiwifi()
{
  int IP_Oc1,IP_Oc2,IP_Oc3,IP_Oc4, Sub_Oc1,Sub_Oc2, Sub_Oc3,Sub_Oc4, Gateway_Oc1, Gateway_Oc2, Gateway_Oc3, Gateway_Oc4;
          // doc tu EEPROM ra
      GlobalIPv4Add ="", GlobalSunet ="",GloablGateway ="";
      //GloablGateway = WiFi.gatewayIP().toString();
      GlobalIPv4Add = ReadEEPROM(AdEE_IPv4_Start,AdEE_IPv4_End,Dodai_id);
      GlobalSunet = ReadEEPROM(AdEE_Sub_Start,AdEE_Sub_End,Dodai_id);
      GloablGateway = ReadEEPROM(AdEE_Gateway_Start,AdEE_Gateway_End,Dodai_id);
      Serial.println(GlobalIPv4Add);
       Serial.println(GloablGateway);
      Serial.println(GlobalSunet);
     
      Serial.println("doc string");
      IP_Oc1 = Separate_String_IP(GlobalIPv4Add,1);
      IP_Oc2 = Separate_String_IP(GlobalIPv4Add,2);
      IP_Oc3 = Separate_String_IP(GlobalIPv4Add,3);
      IP_Oc4 = Separate_String_IP(GlobalIPv4Add,4);
      Sub_Oc1 = Separate_String_IP(GlobalSunet,1);
      Sub_Oc2 = Separate_String_IP(GlobalSunet,2);
      Sub_Oc3 = Separate_String_IP(GlobalSunet,3);
      Sub_Oc4 = Separate_String_IP(GlobalSunet,4);
      Gateway_Oc1 = Separate_String_IP(GloablGateway,1);
      Gateway_Oc2 = Separate_String_IP(GloablGateway,2);
      Gateway_Oc3 = Separate_String_IP(GloablGateway,3);
      Gateway_Oc4 = Separate_String_IP(GloablGateway,4);
      Serial.println(GlobalIPv4Add);
      Serial.println(GlobalSunet);
      Serial.println(GloablGateway);
      Serial.println("doc string");
      
      // Set your Static IP address
      IPAddress local_IP(IP_Oc1, IP_Oc2, IP_Oc3, IP_Oc4);
      // Set your Gateway IP address
      IPAddress gateway(Gateway_Oc1, Gateway_Oc2, Gateway_Oc3, Gateway_Oc4);
      
      IPAddress subnet(Sub_Oc1, Sub_Oc2, Sub_Oc3, Sub_Oc4);
      IPAddress primaryDNS(8, 8, 8, 8);   //optional
      IPAddress secondaryDNS(8, 8, 4, 4); //optional
       if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
        Serial.println("STA Failed to configure");
      }
      
      delay(1000);
      // doc tu eeprom ra ssid
       String sssid="", spass="";
       ssid = "";
       pass = "";
       sssid = ReadEEPROM(AdEE_Name_Wifi_Start,AdEE_Name_Wifi_End,Dodai_id);
       spass = ReadEEPROM(AdEE_Pass_Wifi_Start,AdEE_Pass_Wifi_End,Dodai_id);
       ssid = sssid.c_str();
       pass = spass.c_str();
       WiFi.disconnect(); 
       WiFi.begin(ssid, pass);
       //WiFi.mode(WIFI_STA);
          while (WiFi.status() != WL_CONNECTED)
          {
            delay(500);
            Serial.print(".");
            count_time++;
            if (count_time >= 30)
            {
              Check_connectwifi = false;
              Serial.println("");
              Serial.println("Not Connect to WIFI WEBSERVER");
              count_time = 0;
              break;
            }
          }
          if (WiFi.status() == WL_CONNECTED)
            Check_connectwifi = true;
          else
            Check_connectwifi = false;
            
          Serial.println("khoi dong hoan tat: ");
}
