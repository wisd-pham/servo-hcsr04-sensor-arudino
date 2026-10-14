# Servo-hcsr04-sensor-arudino
# Servo xoay theo khoảng cách bàn tay (Arduino Nano + HC-SR04)

Đưa tay lại gần hoặc ra xa cảm biến HC-SR04, servo sẽ quay theo một góc tương ứng. Đây là dự án đầu tiên trong chuỗi dự án cơ khí - điện tử mình tự làm để xây dựng portfolio. Dự án tiếp theo mình dự định làm là tháo và tìm hiểu một chiếc laptop HP.

![Render đế gắn đủ linh kiện](https://github.com/user-attachments/assets/9066a3b9-e14b-4329-90f8-2c4738dc58f6)

## Tiến độ

- [x] Mô phỏng mạch và code trên Wokwi
- [x] Thiết kế đế trên Fusion 360 và bản vẽ kỹ thuật 2D
- [ ] Lắp ráp phần cứng thật, kiểm tra và quay video demo

## Linh kiện

- Arduino Nano
- Cảm biến siêu âm HC-SR04
- Servo SG90 (loại quay 180 độ)
- Breadboard và dây jumper

## Mô phỏng trên Wokwi

Trong lúc chờ linh kiện thật, mình cho chạy thử toàn bộ mạch và code ngay trên trình duyệt: [mở project trên Wokwi](https://wokwi.com/projects/476366574048400385)

Bấm nút ▶ để chạy, rồi bấm vào cảm biến HC-SR04 và kéo thanh trượt khoảng cách, servo sẽ quay theo.

## Nguyên lý hoạt động

HC-SR04 sẽ đóng vai trò đo khoảng cách bằng sóng siêu âm. Arduino đổi khoảng cách đó thành một góc từ 0 đến 180 độ bằng hàm `map()`, rồi ra lệnh cho servo quay tới góc vừa tính được.

## Thiết kế cơ khí

Mình thiết kế một chiếc đế bằng Fusion 360 để gắn servo, cảm biến và Arduino Nano.

![Đế hoàn chỉnh, góc nghiêng](https://github.com/user-attachments/assets/88e9dac5-a1e0-40a3-becb-1ded91289657)

![Đế hoàn chỉnh, nhìn từ trước](https://github.com/user-attachments/assets/e2f672ef-234c-4cfb-8027-f628831556b4)

Mô hình 3D và STL của đế:

![Mô hình đế, góc nhìn 1](https://github.com/user-attachments/assets/ab80fee0-c09f-416d-99b5-d5cd4c0436ca)

![Mô hình đế, góc nhìn 2](https://github.com/user-attachments/assets/288adfaf-a5d1-4e04-8af8-3cae0519d84a)



Tài liệu thiết kế:

- Bản vẽ kỹ thuật (PDF)
- <img width="916" height="617" alt="image" src="https://github.com/user-attachments/assets/3a3577f8-7b50-4b26-a84f-99fec88612f5" />

- File đế để in 3D (STL)
- <img width="670" height="461" alt="image" src="https://github.com/user-attachments/assets/afa21efd-4952-420b-b315-d1ebe6a089d0" />

- File thiết kế Fusion 360 (f3d)
- <img width="695" height="502" alt="image" src="https://github.com/user-attachments/assets/2994ec7f-cbea-48f4-8789-1701a3c26696" />

## Cấu trúc thư mục

- `code/`: chương trình Arduino và sơ đồ Wokwi{
  "version": 1,
  "author": "Anonymous maker",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-nano", "id": "nano", "top": 0, "left": 0, "attrs": {} },
    { "type": "wokwi-hc-sr04", "id": "ultrasonic1", "top": -123.3, "left": -13.7, "attrs": {} },
    {
      "type": "wokwi-servo",
      "id": "servo1",
      "top": -22,
      "left": -198.8,
      "rotate": 180,
      "attrs": {}
    }
  ],
  "connections": [
    [ "nano:9", "ultrasonic1:TRIG", "green", [ "h-0.5", "v-33.6" ] ],
    [ "nano:5V", "ultrasonic1:VCC", "red", [ "v-72", "h-67.7" ] ],
    [ "ultrasonic1:ECHO", "nano:10", "green", [ "h-10.4", "v33.6" ] ],
    [ "ultrasonic1:GND", "nano:GND.1", "black", [ "h114", "v91.2" ] ],
    [ "servo1:GND", "nano:GND.1", "black", [ "h19.2", "v28.8", "h134.9" ] ],
    [ "servo1:V+", "nano:5V", "green", [ "v28.7", "h134.9" ] ],
    [ "servo1:PWM", "nano:6", "green", [ "h0" ] ]
  ],
  "dependencies": {}
} [diagram.json](https://github.com/user-attachments/files/33414737/diagram.json)


Code mà mình dùng trong Wowki như sau:
[Upl#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
Servo myServo;

const int minDist = 2;   // cm - khoảng cách gần nhất
const int maxDist = 30;  // cm - khoảng cách xa nhất

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(6);
  Serial.begin(9600);
}

long readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // timeout 30ms
  long distance = duration * 0.034 / 2;
  return distance;
}

void loop() {
  long distance = readDistance();
  distance = constrain(distance, minDist, maxDist);

  int angle = map(distance, minDist, maxDist, 0, 180);
  myServo.write(angle);

  Serial.print("Khoang cach: ");
  Serial.print(distance);
  Serial.print(" cm -> Goc: ");
  Serial.println(angle);

  delay(100);
}


oading sketch.ino code…]()


- `thiet-ke/`: file thiết kế, file STL, bản vẽ PDF

## Nguồn mô hình 3D

Mô hình 3D của servo, HC-SR04 và Arduino Nano mình tải được từ trình duyệt GrabCAD, chỉ dùng để minh họa và kiểm tra độ khớp của đế với hốc. Phần thiết kế đế, hốc để đựng Arudino hay Servo, Cảm Biến là của mình.

## Ghi chú về quá trình làm

Trong quá trình làm dự án mình có sử dụng dùng AI để giải thích nguyên lý, gợi ý code và hướng dẫn từng bước khi dùng Autodesk Fusion. Phần đấu dây, chạy mô phỏng, tìm và sửa lỗi, cũng như thao tác dựng mô hình đế trên Autodesk Fusion là mình tự thực hiện, thử nghiệm và sửa sai trong suốt quá trình làm.

## Bài viết chi tiết (Coming Soon)

