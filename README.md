# 🎮 Tic-Tac-Toe in C

A console-based implementation of the classic **Tic-Tac-Toe** game, written in **C** using only the standard library. This project was built as a learning exercise in structured programming, recursion, and basic game logic — and it's a fun little game to play with a friend.

![Language](https://img.shields.io/badge/language-C-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Platform](https://img.shields.io/badge/platform-terminal-lightgrey.svg)

---

## ✨ Features

- **Two-player mode** — Play locally with a friend on the same machine.
- **Random symbol assignment** — A random draw decides who plays as `X` and who plays as `O` at the start of each game.
- **Input validation** — The game rejects out-of-range values and prevents players from choosing an already occupied cell.
- **Full win detection** — Checks for victories across all rows, all columns, and both diagonals.
- **Draw detection** — Correctly announces a tie ("Velha") when all nine cells are filled without a winner.
- **Clean console board** — Displays an intuitive 3×3 grid showing either the player's symbol or the position number (e.g., `11`, `12`, `13`).
- **Menu system** — Start a new game or exit gracefully from the main menu.

---

## 🛠️ Technologies

- **Language:** C (C99 or later)
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`, `time.h` (all standard)
- **Interface:** Command-line / terminal

---

## 🚀 How to Compile and Run

```bash
# Clone the repository
git clone https://github.com/your-username/tic-tac-toe-c.git
cd tic-tac-toe-c

# Compile with GCC
gcc -o tic-tac-toe src/main.c

# Run the game
./tic-tac-toe
