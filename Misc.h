#ifndef TICTACTOE_MISC_H_
#define TICTACTOE_MISC_H_

#include <iostream>

namespace tictactoe
{
constexpr std::array<std::array<int, 3>, 8> WinMatrix{{
	// horizontal
	{0, 1, 2},
	{3, 4, 5},
	{6, 7, 8},

	// vertical
	{0, 3, 6},
	{1, 4, 7},
	{2, 5, 8},

	// diagonal
	{0, 4, 8},
	{2, 4, 6}
}}; 

enum class Mark
{
	None,
	X,
	O
};

inline std::ostream& operator<<(std::ostream& os, Mark mark)
{
	switch(mark)
	{
		case Mark::None:
			os << "None";
		break;
		case Mark::X:
			os << "X";
		break;
		case Mark::O:
			os << "O";
		break;
	};

	return os;
}

}  // namespace tictactoe

#endif  // TICTACTOE_MISC_H_