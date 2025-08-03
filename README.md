# Legend of SeePlusia

Legend of SeePlusia is a C++ SDL2 adventure game where you play as Zeldana, a warrior on a quest to rescue Prince Lazy from the Wizard’s Castle. Explore the mythical world of SeePlusia, collect crystals, avoid dangers, and manage your apples to survive!

## 🧙 Game Overview
- **Start Location:** Enchanted Forest with 20 apples.
- **Goal:** Collect 4 mythical Objectos Crystals from specific locations and rescue Prince Lazy from the Wizard’s Castle.
- **Movement:** Use arrow keys (north, south, east, west) to move between locations.
- **Danger Zones:** Avoid Sands of Quick (instant death) and manage apples carefully.
- **Win Condition:** Reach the Wizard’s Castle with all 4 crystals.

## 🎮 Game Rules
- **Movement:**
  - Only valid moves (as per the map) are allowed. Invalid moves consume 1 apple.
  - Valid moves consume apples as indicated by the map arrows.
- **Apples Orchard:** Visiting adds 6 apples to your inventory.
- **Sands of Quick:** Entering results in instant loss.
- **Bridge of Death:** Locked until all 4 crystals are collected.
- **Eisten Tunnel:** Requires 3 crystals to cross.
- **Game Over:**
  - If you run out of apples, die in quicksand, or get stuck without all crystals.

## 🕹 Controls
- **Arrow Keys:** Move Zeldana in the desired direction.
- **Game Status:**
  - Apples remaining
  - Crystals collected
  - Game state: Running, Lost, or Won

## 🛠️ How to Compile & Run
### Using VS Code (Recommended)
1. Open the `Seeplusia` folder in VS Code (`File -> Open Folder`).
2. Press **F5** to build and run the game.

### Using Terminal (Linux/Windows)
1. Open a terminal in the `Seeplusia` folder.
2. Compile the game:
   
   **Linux:**
   ```bash
   g++ *.cpp -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o seeplusia
   ```
   **Windows (MinGW):**
   ```bash
   g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
   ```
3. Run the game:
   - **Linux:** `./seeplusia`
   - **Windows:** `a.exe`

> **Note:** If you get missing DLL errors on Windows, copy all DLLs from `C:\mingw_dev_lib\bin` to your game folder.

## 📁 Project Structure
```
Legend-of-SeePlusia/
├── Seeplusia/
│   ├── main.cpp           # SDL2 game loop and setup
│   ├── seeplusia.cpp      # Game logic (implement your moves here)
│   ├── seeplusia.hpp      # Game logic header
│   ├── mover.cpp          # Handles movement and rendering
│   ├── mover.hpp          # Movement header
│   ├── assests.png        # Game sprites
│   ├── beat.wav           # (Optional) Game music
│   └── how to compile.txt # Compilation instructions
├── main.tex               # Assignment description (LaTeX)
├── main.pdf               # Assignment description (PDF)
└── ...
```

## ✏️ Your Task
- Implement the `makeMove(string direction)` function in `seeplusia.cpp`.
- Follow all game rules and modularize your code.
- Track apples, crystals, and game state.
- Add extra features for fun if you wish!

## 📺 Game Status Display
- **Apples:** Remaining apples
- **Crystals:** Number of crystals collected
- **Game State:** Running, Lost, or Won

## 📚 Acknowledgement
This assignment is adapted from the work of [Naveed Ejaz](https://twitter.com/nav_ejaz).

---
Enjoy your adventure in SeePlusia!
