#ifndef TICTACTOE_GAME_H_
#define TICTACTOE_GAME_H_

#include "Board.h"
#include "Misc.h"

namespace tictactoe
{
class Game
{
public:
	void run();
	int getInput();
	void update();
private:
	Board board_{};
	Mark currentMark_{Mark::X};
	Mark winnerMark_{Mark::None};
};
}  // namespace tictactoe

#endif  // TICTACTOE_GAME_H_