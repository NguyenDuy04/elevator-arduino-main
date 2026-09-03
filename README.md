# Chạy được hay không thì không biết nhé cả nhà

# No idea if it actually runs or not, though!

### Chi phi nguyên vật liệu mỗi chỗ mỗi khác nên mình không biết đâu. Mình mua hết tất cả mọi thứ, cả đồ mình có là 975.000đ nha.</br>

### Nếu các bạn làm theo cái này của mình thì chúc các bạn thành công nha.

# Thư viện cần cài

```bash
AccelStepper
MFRC522
Adafruit MCP23X17
LiquidCrystal_I2C
Servo
```

# Danh sách vật liệu:

- Vi điều khiển:
  - 1 × Arduino Uno R3
- Điều khiển chuyển động:
  - 1 × Động cơ bước 28BYJ-48 5V
  - 1 × Mạch điều khiển ULN2003
- Cửa thang máy:
  - 1 × Servo SG90 hoặc MG90S (MG90S khỏe hơn SG90 nếu cửa hơi nặng)
- Cảm biến:
  - 4 × Cảm biến hồng ngoại LM393
- Bố trí:

```bash
Tầng 4  -> A3
Tầng 3  -> A2
Tầng 2  -> A1
Tầng 1  -> A0
```

- Hiển thị:
  - 1 × LCD 16x2 I2C
- RFID:
  - 1 × RC522 RFID
  - 1–2 × Thẻ RFID hoặc móc khóa RFID
- Nút bấm:
  - 4 × Nút nhấn chọn tầng hoặc 4 × Nút nhấn có LED chọn tầng

```
Tầng 1
Tầng 2
Tầng 3
Tầng 4
```

- Đèn báo tầng:
  - 4 × LED 5mm (Màu tùy ý) kèm 4 × Điện trở 220Ω.
- Mở rộng chân:
  - 1 × MCP23017 (Cái này tùy ý bạn chọn nha).
- Nguồn (Rất quan trọng): Không nên cấp nguồn động cơ từ cổng USB Arduino.
  - 1 × Nguồn 5V 2A hoặc 5V 3A
- Nguồn này cấp cho:

```
ULN2003
Servo
Arduino
```

và nối chung với GND.

# Phần cơ khí:

- Khung:
  - Tấm Alu
  - Nhôm hộp mini hoặc V nhôm
  - Ke góc
- Cabin:
  - Formex 3mm hoặc mica
- Hệ truyền động:
  - Cách dễ nhất: (Mình làm cái này nha)
    - Dây cước câu cá
    - Puly nhựa
  - Cách đẹp hơn:
    - Dây curoa GT2
    - Puly GT2
- Ray dẫn hướng:

### Để cabin không lắc:

- Thanh nhôm U nhỏ
- Thanh trượt mini
- Điện:
  - Breadboard
  - Dây dupont
  - Domino điện (nếu cần)
- Công cụ:
  - Keo nến
  - Keo 502
  - Khoan mini
  - Mỏ hàn
  - Thiếc hàn

# Mô hình hiện tại:

```
Quét RFID
    ↓
Chọn tầng
    ↓
 Đóng cửa
    ↓
Di chuyển
    ↓
LED báo tầng
    ↓
LCD cập nhật tầng
    ↓
 Mở cửa
    ↓
 Đóng cửa
```

# Cấu trúc thư mục

```
Elevator.ino
│
├── MotorStepper
│   ├── moveUp()
│   ├── moveDown()
│   └── stop()
│
├── ServoDoor
│   ├── openDoor()
│   └── closeDoor()
│
├── FloorSensors
│   └── getCurrentFloor()
│
├── FloorLED
│   └── updateFloorLed()
│
├── DisplayLCD
│   └── showFloor()
│
└── ElevatorController
    ├── processButtons()
    ├── moveToFloor()
    └── stateMachine()
```

# Mapping chân

```
RFID RC522
D10 SDA(SS)
D11 MOSI
D12 MISO
D13 SCK
D9 RST

Stepper ULN2003
D2 IN1
D3 IN2
D4 IN3
D5 IN4

Servo SG90
D6

LM393
A0 Floor1
A1 Floor2
A2 Floor3
A3 Floor4

LCD + MCP23017
A4 SDA
A5 SCL

MCP23017
GPA0 = Button tầng 1
GPA1 = Button tầng 2
GPA2 = Button tầng 3
GPA3 = Button tầng 4

GPB0 = LED tầng 1
GPB1 = LED tầng 2
GPB2 = LED tầng 3
GPB3 = LED tầng 4
```

# Trong thư viện:

```
GPA0 -> 0
GPA1 -> 1
GPA2 -> 2
GPA3 -> 3

GPB0 -> 8
GPB1 -> 9
GPB2 -> 10
GPB3 -> 11
```

# Kiến trúc State Machine

```
enum ElevatorState {
    WAIT_RFID,
    IDLE,
    MOVING_UP,
    MOVING_DOWN,
    DOOR_OPENING,
    DOOR_OPEN,
    DOOR_CLOSING
};
```

# RFID

### Luồng:

```
Khởi động
    ↓
Quét thẻ
    ↓
Thẻ hợp lệ ?
├─ Không
│ LCD: Access Denied
│
└─ Có
    ↓
Cho phép bấm tầng
```
