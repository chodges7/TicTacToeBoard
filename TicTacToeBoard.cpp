#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == O)
    return (Piece)X;
  else
    return (Piece)O;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location.
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/
Piece TicTacToeBoard::placePiece(int row, int column) {
  if(row < BOARDSIZE && row > -1) {
    if(column < BOARDSIZE && column > -1) {
      if(board[row][column] == Blank) {
        board[row][column] = turn;
        turn = toggleTurn();
        return turn;
      }
      else {
        return board[row][column];
      }
    }
  }
  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row < BOARDSIZE && row > -1) {
    if(column < BOARDSIZE && column > -1) {
      return board[row][column];
    }
  }
  return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  if(board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
    return board[0][0]; // top row
  }
  else if(board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
    return board[1][0]; // middle row
  }
  else if(board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
    return board[2][0]; // bottom row
  }
  else if(board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
    return board[0][0]; // left column
  }
  else if(board[0][1] == board[1][1] && board[1][1] == board[2][1]) {
    return board[0][1]; // middle column
  }
  else if(board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
    return board[0][2]; // right column
  }
  else if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0]; // \ diagonal
  }
  else if(board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
    return board[2][0]; // / diagonal
  }
  // If no one's won yet check if board is empty
  for(int i = 0; i < BOARDSIZE; i++) {
    for(int j = 0; j < BOARDSIZE; j++) {
      if(board[i][j] == Blank) {
        return Invalid;
      }
    }
  }
  return Blank; // cat's game
}
