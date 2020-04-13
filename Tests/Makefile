# name of the executable file

NAME		:= unitTest

# project directories

SRC_DIR     = ../src/
SRC_DIR_TEST     = ./src/
OBJ_DIR     = ./obj/

INC_DIR     = ./inc/
LIB_DIR     = ./

# project source files

SRC_T             := $(SRC_DIR_TEST)main.cpp
SRC_T             += $(SRC_DIR_TEST)BishopTest.cpp
SRC_T             += $(SRC_DIR_TEST)KingTest.cpp
SRC_T             += $(SRC_DIR_TEST)KnightTest.cpp
SRC_T             += $(SRC_DIR_TEST)PawnTest.cpp
SRC_T             += $(SRC_DIR_TEST)QueenTest.cpp
SRC_T             += $(SRC_DIR_TEST)RookTest.cpp
SRC             := $(SRC_DIR)AFigure.cpp
SRC             += $(SRC_DIR)Bishop.cpp
SRC             += $(SRC_DIR)Game.cpp
SRC             += $(SRC_DIR)King.cpp
SRC             += $(SRC_DIR)Knight.cpp
SRC             += $(SRC_DIR)Pawn.cpp
SRC             += $(SRC_DIR)Player.cpp
SRC             += $(SRC_DIR)Queen.cpp
SRC             += $(SRC_DIR)Rook.cpp


# project object files

OBJ_T		        = $(SRC_T:$(SRC_DIR_TEST)%.cpp=$(OBJ_DIR)%.o)
OBJ		        = $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)


# header flags

HEADER_FLAGS    := -I $(INC_DIR)


# compilation flags

CC_FLAGS        := -Wall -Wextra -Werror

# compiler

CC              := clang++

# rules

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_T)
	$(CC) $(OBJ_T) $(OBJ)  -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(CC_FLAGS) $(HEADER_FLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR_TEST)%.cpp
	$(CC) $(CC_FLAGS) $(HEADER_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

reclean: fclean all
	rm -f $(OBJ)