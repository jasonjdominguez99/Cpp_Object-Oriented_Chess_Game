// OOPCpp_Final_Assignment_Chess/chess_board.h
//
// Header file for chess_board class
// 
// Author: Jason Dominguez
// Created: 23/04/2021
// Last modified: 
// 24/04/2021
// - Added function to return the chess board
// 25/04/2021
// - Changed raw pointers to smart shared_ptr pointer
// - Started using vector for chess board rather than array
// 02/05/2021
// - Changed [] operator overload to work with editing value
//   in chess_board vector, to allow for pawn promotion
//   changing a chess piece
// - Created enum for move types to allow for en passant
//   and castling functionality
// 19/05/2021
// - Changed all chess piece related shared pointers to 
//   unique, using move semantics for passing to functions


#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H


#include <iostream>
#include <vector>
#include <memory>


// Forward declarations
namespace pcs {
    class chess_piece;
}


// Class and function definitions
namespace brd {
    int board_position_to_index(std::string position);
    std::string board_index_to_position(int position_index);
    
    enum move_type {standard, en_passant, castling};

    class board
    {
        // Friend function for overloading the output operator
        friend std::ostream & operator<<(std::ostream &output, const board &b);

    private:
        std::vector<std::unique_ptr<pcs::chess_piece>> chess_board;

    public:
        board();
        board(const board &board_to_copy);
        ~board() {};

        void move_piece(int initial_position, int final_position, move_type move);
        std::unique_ptr<pcs::chess_piece> operator[](int idx) const;
        std::vector<std::unique_ptr<pcs::chess_piece>> get_board() const;

    };  
}

#endif