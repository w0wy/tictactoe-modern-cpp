#ifndef TICTACTOE_BOARD_H_
#define TICTACTOE_BOARD_H_

#include <array>

#include "Misc.h"

namespace tictactoe
{
class Board
{
public:
	void draw() const;
	void update(int pos, Mark mark);
	const std::array<Mark, 9> get() const;

private:
	std::array<Mark, 9> board_{};
};
}  // namespace tictactoe

#endif  // TICTACTOE_BOARD_H_