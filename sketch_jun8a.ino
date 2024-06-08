#define TRIG_PIN 11  // 초음파 센서 트리거 핀
#define ECHO_PIN 12 // 초음파 센서 에코 핀
#include <Adafruit_NeoPixel.h> // NeoPixel LED 라이브러리 헤더
#define PIN 13     // NeoPixel LED 핀
#include <SoftwareSerial.h>
SoftwareSerial BTserial(9,10);

int v;      //속도
int vmax;       //최대 속도
int Sigpin =  3;  // 신호 입력 핀
int speakerpin=7;


Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800); // NeoPixel LED 객체 생성

int ledBright = 255; // 초기 LED 밝기 (최대 255)

void  setup ()
{
  Serial.begin ( 9600 );
  BTserial.begin(9600);
  pinMode (Sigpin , INPUT);
  strip.begin(); // NeoPixel LED 초기화
  strip.show();  // 모든 LED 끄기
  pinMode(13, OUTPUT); // LED 제어핀 출력으로 설정

//아두이노와 pc간의 시리얼 통신 초기화 
  pinMode(11, OUTPUT);  // 초음파 센서 트리거 핀 출력으로 설정
  pinMode(12, INPUT);  // 초음파 센서 에코 핀 입력으로 설정
  Serial.begin(9600); // 시리얼 통신 시작
}
void  loop ()
{ 
  int distance = 0; // 거리 변수 초기화
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // 에코 신호 지속 시간 측정 및 거리 계산
  distance = pulseIn(ECHO_PIN, HIGH) / 58.2;
  // 시리얼 모니터에 거리 출력
  Serial.println(distance);
  BTserial.print(distance);
  //delay(1000);
  unsigned  long T;          // 주기
  double f;                 // 주파수 
  char s [ 20 ];               // Serial 출력 Length
  vmax = 0 ;
  while (digitalRead (Sigpin)); 
  while ( ! digitalRead (Sigpin));
 
  T =pulseIn (Sigpin , HIGH) + pulseIn (Sigpin , LOW); // 주기 측정
  f = 1 / ( double ) T;            // 주파수 측정
  v = int ((f * 1e6) /44.0 *3600/1000);    // 속도 측정   
  vmax = max (v, vmax);       // 속도의 Max값 측정
  sprintf (s, "% 3d km / h" , vmax);  // Serial 출력
  Serial.println (s);        // Serial 출력
  delay ( 100 );              // Delay 500m/s 

  if (vmax>35){
    tone(speakerpin,500,1000);
   // delay(1000);
    Serial.println("차량이 접근하는중");
  }
  if (distance < 300) { // 거리가 매우 가까울 때 
    for(int i=0; i<24; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0)); // RGB 값 (빨강, 녹색, 파랑)
  }
  strip.show(); // Update the strip to show the changes

    
  } else if (distance > 300 ) { //거리가 조금 가까울 때 
    for(int i=0; i<24; i++) {
    strip.setPixelColor(i, strip.Color(0, 255, 0)); // RGB 값 (빨강, 녹색, 파랑)
  }
  strip.show(); // Update the strip to show the changes

  }}