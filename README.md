# Hangman

## Description
A standalone console-based Hangman game implemented in C++.
This repo contains the Hangman gameplay logic, and the player must guess letters until the secret word is fully revealed or attempts run out.

## How to Play
1. Build the project using the provided source files.
2. Run the compiled executable.
3. Enter one letter at a time.
4. Correct letters are revealed in the hidden word.
5. Wrong guesses reduce the remaining attempts.

## Rules
- The player starts with `word length - 1` attempts.
- Correct guesses reveal matching letters.
- Wrong guesses reduce the attempt count.
- Win by guessing the full word before attempts reach zero.

## Required Files
- `HangmanGame.h`
- `Game.h`
- `Hangman.cpp`
- `words.txt`

## Build Instructions
```bash
g++ main.cpp -o Hangman.exe
```

## Run
```bash
./Hangman.exe
```

## Notes
- If `words.txt` is missing or empty, the game uses a fallback word list.
- This game is designed for console input/output only.
