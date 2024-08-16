/*main.cpp*/

//
// The main program for the TicTacToe game
//
// Benjamin Auby
//

#include "TicTacToe.cpp"
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>

class eval{
    public:
    int position;
    double score;

    eval(int Position, double Score)
        : position(Position), score(Score){
        }
};

char helper(char letter){
    if (letter == 'O'){
        return 'X';
    }
    else{
        return 'O';
    }
}

//
// minimax()
//
// takes a board, depth, and uses alpha/beta pruning to run the minimax algorithm recursively on each possible move
//
eval minimax(TicTacToe &board, double depth, double alpha, double beta, bool maximizing_player, char ai_player){
    if (depth == 0){
        return eval(-1, 0);
    }

    double neginf = -numeric_limits<double>::infinity();
    double posinf = numeric_limits<double>::infinity();

    if (maximizing_player == true){
        eval MaxEval = eval(-1, neginf);
        for (int move : board.available_moves()){
            board.Board[move] = ai_player;
            eval new_eval = eval(-1, 0);
            if (board.check_winner(move, ai_player)){
                new_eval = eval(-1, 1 * (depth + 1));
            }
            else {
                new_eval = minimax(board, depth - 1, alpha, beta, false, ai_player);
            }
            board.Board[move] = ' ';
            if (MaxEval.score < new_eval.score){
                MaxEval.score = new_eval.score;
                MaxEval.position = move;
            }
            alpha = max(alpha, new_eval.score);
            if (beta <= alpha){
                break;
            }
        }
        return MaxEval;
        
    }

    else{
        eval MinEval = eval(-1, posinf);
        for (int move : board.available_moves()){
            board.Board[move] = helper(ai_player);
            eval new_eval = eval(-1, 0);
            if (board.check_winner(move, helper(ai_player))){
                new_eval = eval(-1, -1 * (depth + 1));
            }
            else {
                new_eval = minimax(board, depth - 1, alpha, beta, true, ai_player);
            }
            board.Board[move] = ' ';
            if (MinEval.score > new_eval.score){
                MinEval.score = new_eval.score;
                MinEval.position = move;
            }
            beta = min(beta, new_eval.score);
            if (beta <= alpha){
                break;
            }
        }
        return MinEval;
    }
}

//
// human_first()
//
// runs a game where the human goes first, followed by the AI
//
void human_first(){
    TicTacToe game = TicTacToe();
    cout << "Initial Board:" << endl;
    game.print_board();

    char letter = 'X';
    double neginf = -numeric_limits<double>::infinity();
    double posinf = numeric_limits<double>::infinity();
    while (game.empty_squares_available()){
        if (letter == 'O'){
            int square = minimax(game, game.num_empty_squares(), neginf, posinf, true, 'O').position;
            if (square == -1){
                cout << "Draw!" << endl;
                break;
            }
            game.make_move(square, letter);
            cout << "AI (O) chooses square " << square + 1 << endl;
        }
        else{
            bool valid_square = false;
            while (!valid_square){
                int input;
                cout << letter << "'s turn. Input move (1-9): " << endl;
                cin >> input;
                int square = input - 1;
                vector<int> possible_moves = game.available_moves();
                bool possible = find(begin(possible_moves), end(possible_moves), square) != end(possible_moves);
                if (possible == false){
                    cout << "Invalid move. Try again." << endl;
                }
                else{
                    game.make_move(square, letter);
                    valid_square = true;
                }
            }
        }
        game.print_board();

        if (game.Winner != ' '){
            cout << letter << " wins!" << endl;
            break;
        }

        if (letter == 'O'){
            letter = 'X';
        }
        
        else {
            letter = 'O';
        }
    }
    if (game.empty_squares_available() == false && game.Winner == ' ') {
        cout << "It's a draw." << endl;
    }
}

int main() {
    cout << R"(
     Modes of play available:

    hh: Human vs. human
    ha: Human vs. AI
    ah: AI vs. Hooman - AI makes first move
    aa: AI vs. AI)" << endl;

    bool valid_move = false;
    string mode;

    while (!valid_move) {
        cout << "\nEnter preferred mode of play (e.g., aa): ";
        cin >> mode;

        if (mode == "ha") {
            valid_move = true;
            if (mode == "ha") {
                human_first();}
            /*} else if (mode == "ah") {
                play_game_ai_moves_first();
            } else {
                play_game_ai_vs_ai();
            }*/
        } else {
            std::cout << "\nInvalid option entered. Try again." << std::endl;
        }
    }

    return 0;
}