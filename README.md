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




Tài liệu thiết kế:

- Bản vẽ kỹ thuật (PDF)
- <img width="916" height="617" alt="image" src="https://github.com/user-attachments/assets/3a3577f8-7b50-4b26-a84f-99fec88612f5" />

- File đế để in 3D (STL)
- <img width="670" height="461" alt="image" src="https://github.com/user-attachments/assets/afa21efd-4952-420b-b315-d1ebe6a089d0" />

- File thiết kế Fusion 360 (f3d)
- <img width="695" height="502" alt="image" src="https://github.com/user-attachments/assets/2994ec7f-cbea-48f4-8789-1701a3c26696" />

## Cấu trúc thư mục

- `code/` mình dùng cho Wokwi như sau:
-  Chương trình Arduino: [code/sketch.ino](code/sketch.ino)
  
-  [diagram.json](https://github.com/user-attachments/files/33414737/diagram.json)




## Nguồn mô hình 3D

Mô hình 3D của servo, HC-SR04 và Arduino Nano mình tải được từ trình duyệt GrabCAD, chỉ dùng để minh họa và kiểm tra độ khớp của đế với hốc. Phần thiết kế đế, hốc để đựng Arudino hay Servo, Cảm Biến là của mình.

## Ghi chú về quá trình làm

Trong quá trình làm dự án mình có sử dụng dùng AI để giải thích nguyên lý, gợi ý code và hướng dẫn từng bước khi dùng Autodesk Fusion. Phần đấu dây, chạy mô phỏng, tìm và sửa lỗi, cũng như thao tác dựng mô hình đế trên Autodesk Fusion là mình tự thực hiện, thử nghiệm và sửa sai trong suốt quá trình làm.

## Bài viết chi tiết (Coming Soon)

