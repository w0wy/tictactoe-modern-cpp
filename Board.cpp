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

		if (board_[iter-1] == Mark::None)
			stream << iter;
		else
			stream << board_[iter-1];

		if (iter % 3 == 0)
		{
			stream << "|\n";
			stream << "-   -   -\n";
		}	
	}
	
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