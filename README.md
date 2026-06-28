# 🎮 GuessWord - Capstone Project (Object-Oriented Programming)

## Giới thiệu

**GuessWord** là trò chơi đoán từ được xây dựng bằng ngôn ngữ **C++** nhằm áp dụng các kiến thức của môn **Lập trình hướng đối tượng (OOP)**.

Trong trò chơi, người chơi sẽ lựa chọn độ khó, nhập tên, đoán các từ đã bị ẩn một số ký tự và nhận điểm khi trả lời đúng. Ngoài ra, chương trình còn có cơ chế **Bonus**: nếu trả lời đúng **2 câu liên tiếp**, người chơi sẽ được cộng thêm **1 điểm thưởng**.

---

# Thành viên nhóm

| Thành viên   | Công việc                             |
| ------------ | ------------------------------------- |
| Minh Nhân    | Tích hợp project, Game Module, GitHub |
| Khang Nguyễn | Word Module                           |
| Tiến Phan    | Difficulty Module                     |
| Lịch Trần    | Player & Score Module                 |
| Quốc Trung   | Main.cpp & Test game                  |


---

# Mục tiêu của project

* Áp dụng các kiến thức lập trình hướng đối tượng.
* Thực hành xây dựng project nhiều file.
* Làm quen với Git và GitHub.
* Phát triển một trò chơi console đơn giản.

---

# Chức năng

* Đọc dữ liệu từ file `words.txt`
* Chọn mức độ khó:

  * Easy
  * Medium
  * Hard
* Ẩn ký tự theo từng mức độ khó
* Nhập tên người chơi
* Kiểm tra đáp án
* Cộng điểm khi trả lời đúng
* Bonus 1 điểm nếu trả lời đúng 2 câu liên tiếp
* Có thể Skip từ hiện tại
* Có thể Quit game bất kỳ lúc nào
* Hiển thị kết quả cuối game

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

# Các lớp trong project

## Game

Lớp điều khiển toàn bộ trò chơi.

Chức năng:

* Đọc file từ vựng
* Chọn độ khó
* Điều khiển vòng lặp game
* Quản lý người chơi
* Hiển thị kết quả cuối game

---

## Word

Quản lý một từ trong trò chơi.

Bao gồm:

* Đáp án
* Từ đã bị ẩn
* Kiểm tra đáp án
* Ẩn ký tự theo độ khó

---

## Player

Quản lý thông tin người chơi.

Bao gồm:

* Tên
* Điểm số

---

## Score

Quản lý điểm.

Bao gồm:

* Cộng điểm
* Lấy điểm
* Nạp chồng toán tử
* Friend Function

---

## Difficulty

Lớp trừu tượng xác định số lượng ký tự cần ẩn.

Các lớp kế thừa:

* EasyDifficulty
* MediumDifficulty
* HardDifficulty

---

# Kiến thức OOP áp dụng

## 1. Encapsulation (Đóng gói)

Các thuộc tính đều được khai báo `private`.

Ví dụ:

* Word
* Player
* Score

Việc truy cập dữ liệu được thực hiện thông qua Getter và Setter.

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

Con trỏ này sẽ trỏ đến:

* EasyDifficulty
* MediumDifficulty
* HardDifficulty

tùy theo lựa chọn của người chơi.

---

## 4. Composition (HAS-A)

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

Game chứa Player và danh sách Word.

Player chứa Score.

---

## 5. Operator Overloading

Project sử dụng nạp chồng toán tử:

```cpp
Score operator+(const Score&);
```

Được sử dụng để tính điểm thưởng (Bonus) khi người chơi trả lời đúng hai câu liên tiếp.

---

## 6. Friend Function

Project sử dụng:

```cpp
friend ostream& operator<<(ostream&, const Score&);
```

Để hiển thị trực tiếp đối tượng `Score` bằng:

```cpp
cout << player.getScore();
```

---

## 7. STL

Project sử dụng:

```cpp
vector<Word>
```

để lưu danh sách từ.

---

## 8. File I/O

Sử dụng:

```cpp
ifstream
```

để đọc dữ liệu từ:

```
data/words.txt
```

---

# Luồng hoạt động

```
main()

↓

Tạo đối tượng Game

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

Đúng 2 câu liên tiếp → Bonus 1 điểm

↓

Sai → nhập lại

↓

Skip / Quit (nếu người chơi lựa chọn)

↓

Hiển thị kết quả
```

---

# Hướng dẫn chạy chương trình

Biên dịch:

```bash
g++ main.cpp src/Game.cpp src/Word.cpp src/Player.cpp src/Score.cpp -Iinclude -o GuessWord
```

Chạy:

Windows:

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

Word: tea____

Your answer:
teacher

Correct!

***** BONUS *****
2 correct answers in a row!

Current Score: 3 points
```

---

# Hướng phát triển

Trong tương lai project có thể bổ sung:

* Chọn từ ngẫu nhiên
* Ẩn ký tự ngẫu nhiên
* Lưu bảng xếp hạng
* Chơi nhiều người
* Đếm thời gian
* Giao diện đồ họa

---

# Kết luận

Thông qua project này, nhóm đã áp dụng các kiến thức về lập trình hướng đối tượng như đóng gói, kế thừa, đa hình, quan hệ chứa, nạp chồng toán tử, friend function, STL và xử lý file để xây dựng một trò chơi đoán từ đơn giản.

Ngoài kiến thức lập trình, nhóm còn rèn luyện kỹ năng làm việc nhóm, quản lý mã nguồn bằng Git/GitHub và tổ chức một dự án theo cấu trúc chuẩn của C++.

---

# Công nghệ sử dụng

* C++
* Visual Studio Code
* Git
* GitHub
* STL
* File I/O

---

# License

Project được thực hiện nhằm mục đích học tập trong môn **Lập trình hướng đối tượng (OOP)**.
