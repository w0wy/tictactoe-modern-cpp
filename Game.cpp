#include <limits>

#include "Game.h"

namespace tictactoe
{
void Game::run()
{
	// as long as there's a move to be made
	while(currentMark_ != Mark::None)
	{
		board_.draw(); // draw the board
		int input = getInput(); // get input from player
		board_.update(input, currentMark_); // update the board
		update(); // update the game state
	}

	// game is ended, show the player the board
	board_.draw();

	// provide end message, either win, either tie
	if (winnerMark_ == Mark::None)
		std::cout << "Game eneded. It's a tie!\n";
	else
		std::cout << "The winner is player with mark " << winnerMark_;
}

int Game::getInput() const
{
	std::cout << "Current turn is " << currentMark_ <<". Please enter position to add mark: ";
	int position = 0;
	while(!(std::cin >> position) ||
		(position > 9 || position < 1) ||
		(board_.get()[position-1] != Mark::None))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please provide positions between 1 and 9 that are not already marked.\n";
	}

	return position;
}

void Game::update()
{
	auto board = board_.get();
	// check against the WinMatrix
	for(const auto win : WinMatrix)
	{
		int xMark = 0, oMark = 0;
		for (const auto pos : win)
		{
			if (board[pos] == Mark::None)
				break;

			// count the marks on the board
			// at positions/indexes from the WinMatrix
			board[pos] == Mark::X ? ++xMark : ++oMark;
		}
		// if any combination taken from the WinMatrix
		// is present on the board, then we have a winner
		if (xMark == 3) { currentMark_ = Mark::None; winnerMark_ = Mark::X; return; }
		if (oMark == 3) { currentMark_ = Mark::None; winnerMark_ = Mark::O; return; }
	}

	// if there is no space on the board anymore
	// there is no winner, it's a tie
	if (std::all_of(board.begin(), board.end(),
		[](const auto mark){ return mark != Mark::None; }))
	{
		currentMark_ = Mark::None;
		return;
	}

	// change the turn to the next player
	currentMark_ == Mark::X ? currentMark_ = Mark::O : currentMark_ = Mark::X;
}
}  // namespace tictactoe