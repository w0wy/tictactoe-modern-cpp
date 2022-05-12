#include <limits>

#include "Game.h"

namespace tictactoe
{
void Game::run()
{
	while(currentMark_ != Mark::None)
	{
		board_.draw();
		int input = getInput();
		board_.update(input, currentMark_);
		update();
	}

	board_.draw();
	switch(winnerMark_)
	{
		case Mark::None:
			std::cout << "No winner, it's a tie!\n";
		break;
		case Mark::X:
			std::cout << "Winner is player with mark X!\n";
		break;
		case Mark::O:
			std::cout << "Winner is player with mark O!\n";
		break;
	}
}

int Game::getInput()
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

	for(const auto win : WinMatrix)
	{
		int xMark = 0, oMark = 0;
		for (const auto pos : win)
		{
			if (board[pos] == Mark::None)
				break;

			board[pos] == Mark::X ? ++xMark : ++oMark;
		}
		if (xMark == 3) { currentMark_ = Mark::None; winnerMark_ = Mark::X; return; }
		if (oMark == 3) { currentMark_ = Mark::None; winnerMark_ = Mark::O; return; }
	}

	if (std::all_of(board.begin(), board.end(), [](const auto mark){ return mark != Mark::None; }))
	{
		currentMark_ = Mark::None;
		return;
	}

	currentMark_ == Mark::X ? currentMark_ = Mark::O : currentMark_ = Mark::X;
}
}  // namespace tictactoe