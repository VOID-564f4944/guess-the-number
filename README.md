# \# Guess The Number 🎯

# 

# A C++ console-based number guessing game where the player tries to guess a randomly generated number within a limited number of attempts based on the selected difficulty.

# 

# This project is based on the roadmap.sh challenge:

# 👉 https://roadmap.sh/projects/number-guessing-game

# 

# \---

# 

# \## 📌 Features

# 

# \* Three difficulty levels:

# 

# &#x20; \* Easy (10 attempts)

# &#x20; \* Medium (7 attempts)

# &#x20; \* Hard (5 attempts)

# \* Random number generation using `std::mt19937`

# \* Robust input validation with stream recovery

# \* Feedback system:

# 

# &#x20; \* "Try higher"

# &#x20; \* "Try lower"

# &#x20; \* "Correct"

# \* Replay system (play multiple rounds without restarting the program)

# \* Attempt tracking per round

# \* Execution time measurement using `std::chrono`

# \* High score tracking per difficulty (session-based)

# 

# \---

# 

# \## 🛠️ Technologies Used

# 

# \* C++ (C++17)

# \* Standard Library:

# 

# &#x20; \* `<iostream>`

# &#x20; \* `<random>`

# &#x20; \* `<chrono>`

# &#x20; \* `<limits>`

# \* Visual Studio

# \* Git + GitHub

# 

# \---

# 

# \## 🚀 How to Run

# 

# 1\. Clone the repository:

# 

# &#x20;  ```bash

# &#x20;  git clone https://github.com/VOID-564f4944/guess-the-number.git

# &#x20;  ```

# 

# 2\. Navigate to the project folder:

# 

# &#x20;  ```bash

# &#x20;  cd guess-the-number

# &#x20;  ```

# 

# 3\. Compile the program (using g++ or any C++17 compiler):

# 

# &#x20;  ```bash

# &#x20;  g++ guess-the-number.cpp -std=c++17 -o game

# &#x20;  ```

# 

# 4\. Run the executable:

# 

# &#x20;  ```bash

# &#x20;  ./game

# &#x20;  ```

# 

# \*(Alternatively, open the project in Visual Studio and run it directly.)\*

# 

# \---

# 

# \## 🎮 How to Play

# 

# 1\. Select a difficulty level

# 2\. The program generates a number between 1 and 100

# 3\. Enter your guesses within the allowed attempts

# 4\. Receive feedback after each guess:

# 

# &#x20;  \* "Try higher" if your guess is too low

# &#x20;  \* "Try lower" if your guess is too high

# 5\. Win by guessing the correct number within the attempt limit

# 6\. View your performance:

# 

# &#x20;  \* Number of attempts used

# &#x20;  \* Time taken

# 7\. Choose to replay or quit

# 

# \---

# 

# \## 📈 Improvements from v1.0

# 

# \* Converted single-run gameplay into a replayable game loop

# \* Added robust input validation and error handling

# \* Introduced execution time measurement

# \* Implemented per-difficulty high score tracking (session-based)

# \* Improved overall user interaction and flow

# 

# \---

# 

# \## ⚠️ Limitations

# 

# \* High scores are not persisted between sessions

# \* Game logic and input/output are tightly coupled

# 

# \---

# 

# \## 🧠 What I Learned

# 

# \* Handling input stream errors in C++

# \* Using `std::mt19937` correctly for randomness

# \* Measuring execution time with `std::chrono`

# \* Designing a replayable game loop

# \* Iterating on a project using versioning (v1.0 → v2.0)

# 

# \---

# 

# \## 📜 License

# 

# This project is licensed under the MIT License.



