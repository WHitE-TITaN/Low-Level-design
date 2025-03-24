# 🎲 Snake & Ladders - C++ Implementation

A simple console-based **Snake & Ladders** game built in C++ with object-oriented principles. The game allows multiple players to compete and features randomly generated snakes and ladders on a 10x10 board.

## 📜 Features
- Multiplayer support.
- Randomly generated **snakes** 🐍 and **ladders** 🪜.
- Uses **string-based seeding** for rolling the dice.
- **Turn-based gameplay** with win condition at position 100.
- Object-oriented design using classes like `board`, `player`, and `gameState`.

## 🏗️ Project Structure
```
├── src/
│   ├── main.cpp          # Entry point of the game
│   ├── board.h           # Board implementation (snakes, ladders, movement logic)
│   ├── player.h          # Player class (name, position, movement)
│   ├── gameState.h       # Game state management
│   ├── specialEntity.h   # Dice rolling & entity generation (snakes/ladders)
├── README.md             # Documentation
```

## 🎮 How to Play
1. **Compile & Run**:
    ```sh
    g++ -o SnakeGame Snake-N-Ladders.cpp
    ./SnakeGame
    ```
2. **Enter number of players.**
3. **Take turns rolling the dice** by entering a lucky string.
4. **Move across the board** based on dice results.
5. **Watch out for snakes 🐍 and ladders 🪜!**
6. First player to reach position `100` wins! 🏆

## ⚙️ Compilation & Execution
### Using g++
```sh
g++ -o SnakeGame main.cpp
./SnakeGame
```
### Using CMake
```sh
mkdir build && cd build
cmake ..
make
./SnakeGame
```

## 🔧 Customization
- Modify **board size** by changing the `BoardSize` in `board.h`.
- Change **number of snakes/ladders** in `generateSnake()` and `generateLadders()`.

## 🚀 Future Improvements
- Add a graphical interface (using SFML or SDL).
- Implement AI players.
- Save game state for resuming later.

## 📜 License
This project is open-source. Feel free to modify and distribute!

---
💡 **Contributions & Feedback** are welcome! 🎉

# Screen Short Start Game 🏃‍♂️💨
---
![Screenshot 2025-03-18 001755](https://github.com/user-attachments/assets/0d0963e2-5309-4366-a8b9-839438dab134)

---
# Screen Short End Game 🐲🪜👑
---
![Screenshot 2025-03-18 002550](https://github.com/user-attachments/assets/94543f8d-a4dc-4c3a-9257-efcc9c91cc8a)

---
# THANKYOU❤️

