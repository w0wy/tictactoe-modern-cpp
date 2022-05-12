#include <sstream>
#include <iostream>

#include "Board.h"

namespace
{
	constexpr int MaxMarks = 9;
}

namespace tictactoe
{
void Board::draw() const
{
	std::stringstream stream;
	stream << "-   -   -\n";
	for (auto iter = 1; iter <= MaxMarks; iter++)
	{
		stream << "| ";

		// if there's no Mark yet, show the index of the box
		if (board_[iter-1] == Mark::None)
			stream << iter;
		else
			stream << board_[iter-1];

		// if the index is 3, 6 or 9, just end the row
		if (iter % 3 == 0)
		{
			stream << "|\n";
			stream << "-   -   -\n";
		}	
	}
	
	// show the board to the screen
	std::cout << stream.str();
}

void Board::update(int pos, Mark mark)
{
	board_[pos-1] = mark;
}

const std::array<Mark, 9> Board::get() const
{
	return board_;
}
}  // namespace tictactoe