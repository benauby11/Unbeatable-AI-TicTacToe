# TicTacToe

## Overview
TicTacToe is an interactive console-based Tic Tac Toe game, where you can test your skills against a challenging AI opponent. This project is built using C++ and implements the Minimax algorithm with alpha-beta pruning to provide an optimized and competitive game experience.

## Inspiration
This project was inspired by Professor Mohammed Alam's Python-based Tic Tac Toe implementation, which laid the groundwork for creating a more sophisticated AI opponent in C++.

## Features
- **Play Against AI**: Face off against an intelligent AI that uses the Minimax algorithm with alpha-beta pruning to make optimal moves.
- **Efficient Decision Making**: The alpha-beta pruning technique optimizes the Minimax algorithm, reducing the number of possible moves the AI has to evaluate, which results in faster and more efficient decision-making.
- **Interactive Gameplay**: The game is fully interactive, allowing you to make moves using the console and immediately see the AI's response.
- **Simple and Clean UI**: Built as a console application, it focuses on a straightforward and user-friendly interface.

## Running the Game
To run the game on your local machine, follow these steps:

1. Clone the repository to your local machine:
   ```bash
   git clone <repository-url> 

2. Open the project in your preferred IDE. This project was designed to run on any local IDE that supports C++.

3. Compile and run the game. If using a command line, this can be done with:
    ```bash
    g++ -o TicTacToe main.cpp
    ./TicTacToe

4. Play the game by following the instructions in the console. 


## How It Works
The AI uses the Minimax algorithm, a backtracking algortihm commonly used in decision-making and game theory. Minimax works by using DFS to explore all possible moves, choosing the move that maximizes the chances of winning (or minimizes the chances of losing, epending on whose turn it is).

To improve the efficiency of the algorithm, alpha-beta pruning is applied. This reduces the number of moves that the algorithm needs to check by eliminating branches that are guaranteed to be worse than previously explored options.
