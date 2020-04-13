# name of the executable file

NAME		:= unitTest

# project directories

SRC_DIR     = ./src/
OBJ_DIR     = ./obj/
INC_DIR     = ./inc/
LIB_DIR     = ./

# project source files

SRC             := $(SRC_DIR)main.cpp
SRC             += $(SRC_DIR)AFigure.cpp
SRC             += $(SRC_DIR)Bishop.cpp
SRC             += $(SRC_DIR)Game.cpp
SRC             += $(SRC_DIR)King.cpp
SRC             += $(SRC_DIR)Knight.cpp
SRC             += $(SRC_DIR)Pawn.cpp
SRC             += $(SRC_DIR)Player.cpp
SRC             += $(SRC_DIR)Queen.cpp
SRC             += $(SRC_DIR)Rook.cpp
SRC             += $(SRC_DIR)BishopTest.cpp
SRC             += $(SRC_DIR)KingTest.cpp
SRC             += $(SRC_DIR)KnightTest.cpp
SRC             += $(SRC_DIR)PawnTest.cpp
SRC             += $(SRC_DIR)QueenTest.cpp
SRC             += $(SRC_DIR)RookTest.cpp


# project object files

OBJ		        = $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)


# header flags

HEADER_FLAGS    := -I $(INC_DIR)


# compilation flags

CC_FLAGS        := -Wall -Wextra -Werror

# compiler

CC              := clang++

# rules

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(CC_FLAGS) $(HEADER_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

reclean: fclean all
	rm -f $(OBJ)