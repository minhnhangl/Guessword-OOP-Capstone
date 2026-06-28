# 🎮 GuessWord - Capstone OOP

## Giới thiệu

GuessWord là một trò chơi đoán từ được xây dựng bằng ngôn ngữ **C++** nhằm áp dụng các kiến thức của môn **Lập trình hướng đối tượng (Object-Oriented Programming - OOP)**.

Người chơi sẽ lựa chọn độ khó, đoán các từ đã bị ẩn một số ký tự và tích lũy điểm số sau mỗi câu trả lời đúng.

---

# Chức năng

- Đọc dữ liệu từ file `words.txt`
- Chọn độ khó:
  - Easy
  - Medium
  - Hard
- Ẩn số lượng ký tự theo từng độ khó
- Người chơi nhập đáp án
- Kiểm tra đúng/sai
- Cộng điểm khi trả lời đúng
- Hiển thị kết quả cuối game
- Có thể bỏ qua từ (Skip)
- Có thể thoát game (Quit)

---

# Cấu trúc project

```
Project.Guessword
│
├── data
│   └── words.txt
│
├── include
│   ├── Game.h
│   ├── Word.h
│   ├── Player.h
│   ├── Score.h
│   ├── Difficulty.h
│   ├── EasyDifficulty.h
│   ├── MediumDifficulty.h
│   └── HardDifficulty.h
│
├── src
│   ├── Game.cpp
│   ├── Word.cpp
│   ├── Player.cpp
│   └── Score.cpp
│
├── main.cpp
└── README.md
```

---

# Mô tả các lớp

## Game

Là lớp điều khiển toàn bộ chương trình.

Chức năng:

- Đọc danh sách từ
- Chọn độ khó
- Điều khiển quá trình chơi
- Hiển thị kết quả

---

## Word

Quản lý một từ trong game.

Bao gồm:

- Đáp án
- Từ đã bị ẩn
- Kiểm tra đáp án
- Ẩn ký tự

---

## Player

Quản lý thông tin người chơi.

Bao gồm:

- Tên người chơi
- Điểm số

---

## Score

Quản lý điểm.

Chức năng:

- Cộng điểm
- Lấy điểm
- Nạp chồng toán tử

---

## Difficulty

Lớp trừu tượng dùng để xác định số lượng ký tự cần ẩn.

Các lớp kế thừa:

- EasyDifficulty
- MediumDifficulty
- HardDifficulty

---

# Kiến thức OOP áp dụng

## 1. Encapsulation (Đóng gói)

Các thuộc tính được khai báo `private` và truy cập thông qua các hàm `public`.

Ví dụ:

- Player
- Word
- Score

---

## 2. Inheritance (Kế thừa)

```
Difficulty
      ▲
      │
 ┌────┼────┐
 │    │    │
Easy Medium Hard
```

Ba lớp độ khó kế thừa từ lớp `Difficulty`.

---

## 3. Polymorphism (Đa hình)

Sử dụng con trỏ:

```cpp
Difficulty* difficulty;
```

Con trỏ sẽ trỏ đến:

- EasyDifficulty
- MediumDifficulty
- HardDifficulty

tùy theo lựa chọn của người chơi.

---

## 4. Composition (Quan hệ chứa)

```
Game
 ├── Player
 ├── vector<Word>
 └── Difficulty*
```

```
Player
 └── Score
```

---

## 5. STL

Project sử dụng:

```cpp
vector<Word>
```

để lưu danh sách từ.

---

## 6. File I/O

Sử dụng:

```cpp
ifstream
```

để đọc dữ liệu từ file:

```
data/words.txt
```

---

# Luồng hoạt động của chương trình

```
main()

↓

Tạo Game

↓

Đọc words.txt

↓

Người chơi chọn độ khó

↓

Nhập tên

↓

Ẩn ký tự

↓

Người chơi đoán

↓

Đúng → cộng điểm

↓

Sai → nhập lại

↓

Hết từ hoặc Quit

↓

Hiển thị kết quả
```

---

# Hướng dẫn chạy chương trình

Biên dịch:

```bash
g++ main.cpp src/Game.cpp src/Word.cpp src/Player.cpp src/Score.cpp -Iinclude -o GuessWord
```

Chạy trên Windows:

```powershell
.\GuessWord.exe
```

---

# Ví dụ

```
Choose difficulty: 2

Enter your name:
Minh

Word: __llo

Your answer:
hello

Correct!
```

---

# Hướng phát triển

Trong tương lai có thể bổ sung:

- Chọn từ ngẫu nhiên
- Ẩn ký tự ngẫu nhiên
- Lưu điểm cao (High Score)
- Đếm thời gian
- Giao diện đẹp hơn
- Chơi nhiều vòng

---

# Kết luận

Thông qua project này, nhóm đã vận dụng các kiến thức về Lập trình hướng đối tượng như đóng gói, kế thừa, đa hình, quan hệ chứa, STL và xử lý file để xây dựng một trò chơi đoán từ đơn giản. Đây là cơ hội giúp nhóm rèn luyện kỹ năng lập trình, làm việc nhóm và sử dụng Git/GitHub trong quá trình phát triển phần mềm.

---

## Công nghệ sử dụng

- C++
- Visual Studio Code
- Git
- GitHub
- STL
- File I/O

---

## Giấy phép

Project được thực hiện nhằm mục đích học tập trong môn **Lập trình hướng đối tượng (OOP)**.