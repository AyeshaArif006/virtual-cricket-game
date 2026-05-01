# virtual-cricket-game
A terminal-based cricket simulation game in C++ with toss, batting and match result logic.
# About
Virtual Cricket Game is a fun, interactive command-line cricket simulator. Two teams face off in a randomized match with toss, batting innings, wide balls, wickets and a final result  all in your terminal.
# Features

- Custom team names with duplicate validation
- Coin toss (heads/tails) with random result
- Toss winner chooses to bat or ball
- Configurable overs (1–5)
- Random ball-by-ball simulation (runs, wides, wickets)
- Target-based second innings with chase detection
- Final match result announcement
 # How to Compile & Run

```bash
# Compile
g++ -o cricket cricket.cpp

# Run
./cricket
```

Requires a C++ compiler (g++ recommended). No external libraries needed.
# Gameplay

1. Enter number of overs (1–5)
2. Enter names for both teams
3. Team 1 calls the toss (heads/tails)
4. Toss winner chooses to bat or ball
5. First innings plays out ball by ball
6. Second team chases the target
7. Winner is announced!
# Project Structure
virtual-cricket-game/
├── cricket.cpp   # Main source file
└── README.md    # Project documentation
# Tech Stack
C++ · Standard Library (iostream, cstdlib, ctime, string)


