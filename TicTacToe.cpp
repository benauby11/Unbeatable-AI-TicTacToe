/*TicTacToe.cpp*/

//
// A class for a TicTacToe board,
// including a board and the current winner
//
// Benjamin Auby
// Inspiration from Professor Mohammed Alam's CS 348 Class
//

#include <vector>
#include <iostream>

using namespace std;


class TicTacToe {
public:
    std::vector<char> Board;
    char Winner;


//
// Constructor
//
TicTacToe()
    : Board(9, ' '), Winner(' ')
    {
    }

//
// print_board
//
// prints out the current board
//
void print_board(){
    for (int i = 0; i<3; i++){
        cout << '|' << this->Board[i * 3] << '|' << this->Board[(i * 3) + 1] << '|' << this->Board[(i * 3) + 2] << endl;
    }
}

//
// available_moves
//
// returns a list of open spots left on the board
//
vector<int> available_moves(){
    vector<int> moves;
    for (int i = 0; i < 9; i++){
        if (this->Board[i] == ' '){
            moves.push_back(i);
        }
    }
    return moves;
}

// 
// empty_squares_available
//
// returns true if there is an empty square left on the board, false if not
//
bool empty_squares_available(){
    for (int i = 0; i < 9; i++){
        if (this->Board[i] == ' '){
            return true;
        }
    }
    return false;
}

//
// num_empty_squares
//
// returns the number of empty squares on the board
//
int num_empty_squares(){
    int result = 0;
    for (int i = 0; i < 9; i++){
        if (this->Board[i] == ' '){
            result += 1;
        }
    }
    return result;
}

//
// make_move
//
// updates the board based on the given square and letter
// returns true if the move is successful, false if not
//
bool make_move(int square, char letter){
    if (this->Board[square] == ' '){
        this->Board[square] = letter;
        if (this->check_winner(square, letter) == true){
            this->Winner = letter;
        }
        return true;
    }
    return false;
}

//
// check_winner
//
// checks if the current board has a winner or not
bool check_winner(int square, char letter){
    int row_int = square / 3;
    bool row = true;
    for (int i = row_int * 3; i < row_int * 3 + 3; i++){
        if (this->Board[i] != letter){
            row = false;
            break;
        }
    }
    if (row == true){
        return true;
    }

    int col_int = square % 3;
    bool col = true;
    for (int i = col_int; i < 9; i += 3){
        if (this->Board[i] != letter){
            col = false;
            break;
        }
    }
    if (col == true){
        return true;
    }

    if (square % 2 == 0){
        bool left = true;
        bool right = true;
        for (int i = 0; i < 9; i += 4){
            if (this->Board[i] != letter){
                left = false;
                break;
            }
        }
        for (int j = 2; j < 7; j += 2){
            if (this->Board[j] != letter){
                right = false;
                break;
            }
        }
        if (left == true || right == true){
            return true;
        }
    }
    return false;
}

};