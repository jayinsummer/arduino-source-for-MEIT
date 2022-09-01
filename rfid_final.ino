#include <SPI.h> // RFID는 SPI통신을 하기 때문에 사용
#include <MFRC522.h> // RFID를 사용할 수 있는 헤더파일
#include <SoftwareSerial.h> // MP3모듈이 시리얼 통신을 때문에 사용
#include <DFPlayer_Mini_Mp3.h> // MP3모듈을 사용할 수 있는 헤더파일

#define RST_PIN 9 // reset핀은 9번으로 설정
#define SS_PIN 10 // SlaveSelect핀은 10번으로 설정
#define RST2 7 // reset핀은 7번 설정
#define SS2 8 // SlaveSelect핀은 8번 설정
#define ledred 4 // 빨간색 신호등 불
#define ledgreen 2 // 초록색 신호등 불
int c = 0; // 카운터 의미로써 사용하기 위한 변수

MFRC522 mfrc(SS_PIN, RST_PIN); // MFR522를 사용해 RFID의 Slave //Select와 Reset핀을 지정하여 mfrc1 객체 생성MFRC522 mfrc2(SS2, RST2); // MFR522를 사용해 RFID의
//Slave Select와 Reset핀을 지정하여 mfrc2 객체 생성

void setup() // 초기 설정
{
Serial.begin(9600); //아두이노 통신 속도 설정 9600bps
SPI.begin(); // SPI 초기화 (SPI통신을 사용하겠다.)
mfrc.PCD_Init(); // RFID1 모듈 초기화
pinMode(ledred , OUTPUT); // 빨간색 신호등 세팅
pinMode(ledgreen , OUTPUT); // 초록색 신호등 세팅
mp3_set_serial (Serial); // mp3모듈에 9600bps 통신 속도 설정
delay(1); // 스피커 소리 크기 세팅시간 1ms
mp3_set_volume (30); // 스피커 소리 크기 최대 30
} // setup 끝

void loop()
{
  for(int a=0; a < 30; a++) // 빨간불 15초
  {
    digitalWrite(ledred , HIGH);
    digitalWrite(ledgreen , LOW);
    delay(500);
    
    if ( mfrc.PICC_IsNewCardPresent() && mfrc.PICC_ReadCardSerial() )
    {
      c=1;

      if(24<=a) //13초 이후
      {break;}

      mp3_play (1); //‘빨간불이니 잠시만 기다려주세요.’
      delay(3000);
      a=a+6;
    }

  } // 빨간불 끝
  
  if(c == 0)
  {
    for(int b=0; b<20; b++) //초록불 10초
    {
      digitalWrite(ledred, LOW);
      digitalWrite(ledgreen, HIGH);
      delay(500);
      
      if ( mfrc.PICC_IsNewCardPresent() && mfrc.PICC_ReadCardSerial() )
      {
        c=1;

        if(14<=b)
        {break;}

        mp3_play (3); // ‘초록불이니 다음신호를 기다려주세요.’
        delay(3000);
        b=b+6;
      }

    }
    
    return;
  
  } // 보행자 신호 종료
  
  if(c == 1)
  {
    digitalWrite(ledred, LOW);
    digitalWrite(ledgreen, HIGH);
    c=0;
    mp3_play (2); //‘초록불이 되었습니다, 조심히 건너가세요.’
    delay(4100);
    
    for(int b=0; b<12; b=b+3)
    {
      mp3_play (4); // ‘삐삐삐삑 삐삐삐삑’
      delay(2900);

      if ( mfrc.PICC_IsNewCardPresent() && mfrc.PICC_ReadCardSerial() )
      { c=1; }
           
    }
    
  } //초록불 끝

}
