# ♟ Chess Game in C++ with Raylib GUI

![Chess](https://img.shields.io/badge/C%2B%2B-Raylib%20Chess-blueviolet.svg)

## Table of Contents

* [📌 Description](#-description)
* [🎮 Features](#-features)
* [🛠 Installation](#-installation)
* [🚀 Usage](#-usage)
* [🎯 Controls](#-controls)
* [📁 Project Structure](#-project-structure)
* [📦 Requirements](#-requirements)
* [🤝 Contributing](#-contributing)
* [👤 Author](#-author)

---

## 📌 Description

*Chess* is a visually interactive, rule-complete, two-player chess game built with *C++* using *Object-Oriented Programming principles. The GUI is rendered via the [Raylib](https://www.raylib.com/) library, providing a smooth and responsive visual experience. Game mechanics such as **check, **checkmate, **stalemate, **castling, **en passant, and **promotion* are fully supported.

Players interact through a *click-based interface* with *real-time visual feedback*, enhancing usability and game clarity.

---

## 🎮 Features

### ✔ Gameplay

* ✅ Full rule-based chess mechanics
* ✅ Click-based 2-player interface
* ✅ Real-time state tracking:

  * Check, Checkmate, Stalemate
  * En Passant
  * Castling
  * Pawn Promotion
* 📅 Load game state from file (grid.txt)

### 🖼 Visual Interface

* Raylib-powered GUI
* Custom PNG-based chess pieces:

  * 🖼 bishop-B.png, bishop-W.png
  * 🖼 king-B.png, king-W.png
  * (other piece images included)


---

## 🛠 Installation

### 📅 Clone the Repository

bash
git clone https://github.com/SaraAbidHussain/Chess.git
cd Chess


### ⚙ Compile the Project

Make sure [Raylib](https://www.raylib.com/) is installed.

#### On *Windows* (MinGW)

bash
g++ bscs24112Source.cpp bscs24112_*.cpp -o ChessGame -lraylib -lopengl32 -lgdi32 -lwinmm


#### On *Linux*

bash
g++ bscs24112Source.cpp bscs24112_*.cpp -o ChessGame -lraylib -lGL -lm -lpthread -ldl -lrt -lX11


### ▶ Run the Game

bash
./ChessGame


---

## 🚀 Usage

1. Launch the executable.
2. Choose to:

   * Start a new game
   * Load a saved game from grid.txt
3. Click on a piece to highlight its valid moves.
4. Play turn by turn.
5. Endgame notifications (Check, Checkmate, Stalemate) appear as applicable.

---

## 🎯 Controls

| Action           | Method                       |
| ---------------- | ---------------------------- |
| Select a piece   | Click on a piece        |
| View valid moves | Highlights in green          |
| Capture opponent | Click red-highlighted square |
| Save/Load Game   | Via file.txt manually      |

---

## 📁 Project Structure


├── bscs24112Source.cpp<br>
├── bscs24112Piece.{h,cpp}<br>
├── bscs24112King.{h,cpp}<br>
├── bscs24112Queen.{h,cpp}<br>
├── bscs24112Bishop.{h,cpp}<br>
├── bscs24112Knight.{h,cpp}<br>
├── bscs24112Rook.{h,cpp}<br>
├── bscs24112Pawn.{h,cpp}<br>
├── bscs24112Board.{h,cpp}<br>
├── bscs24112Header.h<br>
├── grid.txt (save/load state)<br>
├── *.png (chess piece images)<br>


---

## 📦 Requirements

* C++ compiler (e.g. g++, clang++)
* [Raylib](https://www.raylib.com/) (graphics library)
* PNG support for images
* Works on *Windows* and *Linux*

---

## 📸 Images & Assets

All chess piece images (bishop-B.png, king-W.png, etc.) are located in the repo. You can download them via:

🔗 [GitHub Repo Link](https://github.com/SaraAbidHussain/Chess.git)

> Images are rendered automatically during runtime using Raylib.

---

## 🤝 Contributing

Contributions are welcome! If you'd like to enhance GUI, or add new features:

1. Fork the repository
2. Create a new branch
3. Submit a pull request

---

## 👤 Author

*Sara Abid*
[GitHub Profile](https://github.com/SaraAbidHussain)

---

Enjoy the game and feel free to customize or expand!
*Happy Coding ♟👡*