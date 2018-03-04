#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/28 17:10:02 by fpasquer          #+#    #+#              #
#    Updated: 2018/02/26 12:24:48 by fpasquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Gomoku_client

SRC_NAME = $(sort main.cpp Error.cpp Key.cpp Player.cpp Player_human.cpp			\
			Player_ia.cpp Window.cpp Client.cpp Grid.cpp)

SRC_NAME_TOOL = $(sort Captures.cpp Cell.cpp CountStone.cpp FreeThree.cpp			\
		HaveWin.cpp)

SRC_PATH = ./srcs/
SRC_PATH_TOOL = ../Tools_srcs/
OBJ_PATH = ./objs/
OBJ_PATH_TOOL = ../Tools_objs/
INC_PATH = ./incs/
INC_PATH_TOOL = ../Tools_incs/
OBJ_NAME = $(SRC_NAME:.cpp=.o)
OBJ_NAME_TOOL = $(SRC_NAME_TOOL:.cpp=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
SRC_TOOL = $(addprefix $(SRC_PATH_TOOL),$(SRC_NAME_TOOL))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_TOOL = $(addprefix $(OBJ_PATH_TOOL),$(OBJ_NAME_TOOL))
INC = $(addprefix -I,$(INC_PATH))
INC_TOOL = $(addprefix -I,$(INC_PATH_TOOL))

CC = g++
CFLAGS = -Wall -Wextra -Werror -O3 -march=native
LDFLAGS = $(addprefix -L,)
LDLIBS = -I/usr/local/opt/qt/include -lncurses

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_TOOL)
	@printf "%-50s" "create executable "$(notdir $@)...
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJ) $(OBJ_TOOL) -o $(NAME)
	@printf "\e[1;32m[OK]\e[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@printf "%-50s" "compiling "$(notdir $<)...
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@printf "\e[1;32m[OK]\e[0m\n"

$(OBJ_PATH_TOOL)%.o: $(SRC_PATH_TOOL)%.cpp
	@printf "%-50s" "compiling "$(notdir $<)...
	@mkdir -p $(OBJ_PATH_TOOL)
	@$(CC) $(CFLAGS) $(INC_TOOL) -o $@ -c $<
	@printf "\e[1;32m[OK]\e[0m\n"

clean:
	@printf "%-50s" "deleting objects..."
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_TOOL)
	@printf "\e[1;32m[OK]\e[0m\n"

fclean: clean
	@printf "%-50s" "deleting executable..."
	@$(RM) $(NAME)
	@printf "\e[1;32m[OK]\e[0m\n"

re: fclean all
