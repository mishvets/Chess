# name of the executable file

NAME		:= chess

# project directories

SRC_DIR     = ./src/
OBJ_DIR     = ./obj/
INC_DIR     = ./inc/
LIB_DIR     = ./

# project source files

SRC             := $(SRC_DIR)main.cpp
SRC             += $(SRC_DIR)


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
	$(CC) $(OBJ) -o $(NAME) -lncurses

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC_DIR)%.hpp
	$(CC) $(CC_FLAGS) $(HEADER_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

reclean: fclean all
	rm -f $(OBJ)