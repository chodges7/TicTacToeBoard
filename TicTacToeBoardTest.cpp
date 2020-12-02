/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, place_piece_test) {
  TicTacToeBoard myTicTacToe;
  int row = 1;
  int col = 1;
  Piece nextTurn = myTicTacToe.placePiece(row, col);
	ASSERT_EQ(nextTurn, O);
}

TEST(TicTacToeBoardTest, invalid_place_piece_test) {
  TicTacToeBoard myTicTacToe;
  int row = 10;
  int col = 10;
  Piece nextTurn = myTicTacToe.placePiece(row, col);
	ASSERT_EQ(nextTurn, Invalid);
}

TEST(TicTacToeBoardTest, toggle_turn_test) {
  TicTacToeBoard board;
  Piece out;
  out = board.toggleTurn();

	ASSERT_EQ(out, 'O');
}

TEST(TicTacToeBoardTest, alt_toggle_turn_test) {
  TicTacToeBoard board;
	int row = 0;
	int column = 0;
  Piece out;
	board.placePiece(row, column);
  out = board.toggleTurn();

	ASSERT_EQ(out, 'X');
}

TEST(TicTacToeBoardTest, invalid_get_piece_test) {
  TicTacToeBoard board;
	int row = 10;
	int column = 10;
  Piece out;
	out = board.getPiece(row, column);

	ASSERT_EQ(out, Invalid);
}

TEST(TicTacToeBoardTest, blank_get_piece_test) {
  TicTacToeBoard board;
	int row = 0;
	int column = 0;
  Piece out;
	out = board.getPiece(row, column);

	ASSERT_EQ(out, Blank);
}

TEST(TicTacToeBoardTest, x_get_piece_test) {
  TicTacToeBoard board;
	int row = 0;
	int column = 0;

	board.placePiece(row, column);

  Piece out;
	out = board.getPiece(row, column);

	ASSERT_EQ(out, X);
}

TEST(TicTacToeBoardTest, Invalid_get_winner_test) {
  TicTacToeBoard board;

  Piece out;
	out = board.getWinner();

	ASSERT_EQ(out, Blank);
}

TEST(TicTacToeBoardTest, x_top_row_winner_test) {
  TicTacToeBoard board;
	int row;
	int column;

	row = 0;
	column = 0;
	board.placePiece(row, column); // X

	row = 1;
	column = 0;
	board.placePiece(row, column); // O

	row = 0;
	column = 1;
	board.placePiece(row, column); // X

	row = 1;
	column = 2;
	board.placePiece(row, column); // O

	row = 0;
	column = 2;
	board.placePiece(row, column); // X

	Piece out;
	out = board.getWinner();

	ASSERT_EQ(out, X);
}

TEST(TicTacToeBoardTest, x_middle_row_winner_test) {
  TicTacToeBoard board;
	int row;
	int column;

	row = 1;
	column = 0;
	board.placePiece(row, column); // X

	row = 0;
	column = 0;
	board.placePiece(row, column); // O

	row = 1;
	column = 1;
	board.placePiece(row, column); // X

	row = 0;
	column = 2;
	board.placePiece(row, column); // O

	row = 1;
	column = 2;
	board.placePiece(row, column); // X

	Piece out;
	out = board.getWinner();

	ASSERT_EQ(out, X);
}

TEST(TicTacToeBoardTest, x_bottom_row_winner_test) {
  TicTacToeBoard board;
	int row;
	int column;

	row = 2;
	column = 0;
	board.placePiece(row, column); // X

	row = 0;
	column = 0;
	board.placePiece(row, column); // O

	row = 2;
	column = 1;
	board.placePiece(row, column); // X

	row = 1;
	column = 1;
	board.placePiece(row, column); // O

	row = 2;
	column = 2;
	board.placePiece(row, column); // X

	Piece out;
	out = board.getWinner();

	ASSERT_EQ(out, X);
}

TEST(TicTacToeBoardTest, x_left_col_winner_test) {
  TicTacToeBoard board;
	int row;
	int column;

	row = 0;
	column = 0;
	board.placePiece(row, column); // X

	row = 2;
	column = 2;
	board.placePiece(row, column); // O

	row = 1;
	column = 0;
	board.placePiece(row, column); // X

	row = 1;
	column = 1;
	board.placePiece(row, column); // O

	row = 2;
	column = 0;
	board.placePiece(row, column); // X

	Piece out;
	out = board.getWinner();

	ASSERT_EQ(out, X);
}

TEST(TicTacToeBoardTest, x_middle_col_winner_test) {
  TicTacToeBoard board;
	int row;
	int column;

	row = 0;
	column = 1;
	board.placePiece(row, column); // X

	row = 0;
	column = 0;
	board.placePiece(row, column); // O

	row = 1;
	column = 1;
	board.placePiece(row, column); // X

	row = 1;
	column = 0;
	board.placePiece(row, column); // O

	row = 2;
	column = 1;
	board.placePiece(row, column); // X

	Piece out;
	out = board.getWinner();

	ASSERT_EQ(out, X);
}

TEST(TicTacToeBoardTest, x_right_col_winner_test) {
  TicTacToeBoard board;
	int row;
	int column;

	row = 0;
	column = 2;
	board.placePiece(row, column); // X

	row = 0;
	column = 0;
	board.placePiece(row, column); // O

	row = 1;
	column = 2;
	board.placePiece(row, column); // X

	row = 0;
	column = 1;
	board.placePiece(row, column); // O

	row = 2;
	column = 2;
	board.placePiece(row, column); // X

	Piece out;
	out = board.getWinner();

	ASSERT_EQ(out, X); // This is wrong
}

TEST(TicTacToeBoardTest, x_left_diag_winner_test) {
  TicTacToeBoard board;
	int row;
	int column;

	row = 0;
	column = 0;
	board.placePiece(row, column); // X

	row = 0;
	column = 1;
	board.placePiece(row, column); // O

	row = 1;
	column = 1;
	board.placePiece(row, column); // X

	row = 1;
	column = 2;
	board.placePiece(row, column); // O

	row = 2;
	column = 2;
	board.placePiece(row, column); // X

	Piece out;
	out = board.getWinner();

	ASSERT_EQ(out, X);
}

TEST(TicTacToeBoardTest, x_right_diag_winner_test) {
  TicTacToeBoard board;
	int row;
	int column;

	row = 0;
	column = 2;
	board.placePiece(row, column); // X

	row = 0;
	column = 1;
	board.placePiece(row, column); // O

	row = 1;
	column = 1;
	board.placePiece(row, column); // X

	row = 1;
	column = 2;
	board.placePiece(row, column); // O

	row = 2;
	column = 0;
	board.placePiece(row, column); // X

	Piece out;
	out = board.getWinner();

	ASSERT_EQ(out, X);
}

TEST(TicTacToeBoardTest, cats_game_winner_test) {
  TicTacToeBoard board;
	int row;
	int column;

	row = 0;
	column = 1;
	board.placePiece(row, column); // X

	row = 0;
	column = 0;
	board.placePiece(row, column); // O

	row = 1;
	column = 0;
	board.placePiece(row, column); // X

	row = 0;
	column = 2;
	board.placePiece(row, column); // O

	row = 1;
	column = 1;
	board.placePiece(row, column); // X

	row = 1;
	column = 2;
	board.placePiece(row, column); // O

	row = 2;
	column = 2;
	board.placePiece(row, column); // X

	row = 2;
	column = 1;
	board.placePiece(row, column); // O

	row = 2;
	column = 0;
	board.placePiece(row, column); // X

	Piece out;
	out = board.getWinner();

	ASSERT_EQ(out, Blank); // Blank in cat's game
}
