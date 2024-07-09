# 시각 장애인을 위한 자동 음향 신호기
![image](https://github.com/jayinsummer/arduino-source-for-MEIT/assets/112365313/38499421-7f31-45ad-97f6-182654d98cb0)

## 🚦프로젝트 소개
숙명여자대학교 <하드웨어 소프트웨어 융합대회 MEIT>의 장려상 수상작입니다.
일반 횡단보도에서 뿐만이 아니라 이러한 비신호 횡단보도에서도 활용할 수 있는 음향신호기를 제작하였습니다.

## 🚦제작 목적
오늘날 대부분의 음향신호기는 신호등 기둥에 부착되어있고, 점자 보도블록은 횡단보도 앞의 바닥에 설치되어 있습니다.
시각장애인이 음향신호기의 안내를 받기 위해서는 버튼을 눌러야만 하는데, 음향신호기와 점자 보도블록이 떨어져 있어 버튼을 찾는 것 자체가 쉽지 않은 일입니다.
따라서 저희는 시각장애인들이 조금 더 안전하고 편리하게 횡단보도를 이용할 수 있는 방법을 고안하고자 하였습니다.
![image](https://github.com/jayinsummer/arduino-source-for-MEIT/assets/112365313/cdb329da-e26b-41e7-9b04-80d41467b64c)

## 🚦소프트웨어
하드웨어 통제를 위한 코드와 신호등 알고리즘을 구현하였습니다.
![image](https://github.com/jayinsummer/arduino-source-for-MEIT/assets/112365313/9c6e5d90-a024-4fed-b7a2-ccb384c52b06)
<hr/>
![image](https://github.com/jayinsummer/arduino-source-for-MEIT/assets/112365313/4ba1595a-ca0e-4f4e-8708-9f920fb9ad35)

## 🚦하드웨어
#### 1. RFID 모듈 사용
구매한 제품이 정품 hm-10과 호환되지 않아 일부 AT 명령어에 응답하지 않았던 것으로 확인됨.
따라서 비콘 대신 rfid 모듈을 이용하여 버튼을 누르지 않아도 되는 시각장애인용 횡단보도 음향신호기를 제작.
![image](https://github.com/jayinsummer/arduino-source-for-MEIT/assets/112365313/563d1c1d-9bfc-4cd8-956e-e675513241b4)

#### 2. 태그가 인식되면 신호등 LED에서 정지 혹은 보행 불빛이 나오도록 설정
![image](https://github.com/jayinsummer/arduino-source-for-MEIT/assets/112365313/2b5ccf8f-ae96-4121-8b2c-aaafba6d4e2f)

