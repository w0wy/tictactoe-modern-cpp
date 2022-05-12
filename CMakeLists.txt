cmake_minimum_required(VERSION 3.22)

project(TicTacToe)

add_executable(${PROJECT_NAME}
	Board.cpp
	Game.cpp
	main.cpp
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
