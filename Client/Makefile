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

SRC_NAME = $(sort main.cpp Error.cpp Grid.cpp Key.cpp Player.cpp Grid_capture.cpp	\
			Player_human.cpp Player_ia.cpp Window.cpp Client.cpp FreeThree.cpp		\
			Grid_countStone.cpp CountWin.cpp)
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./incs/
OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

CC = clang++
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = $(addprefix -L,)
LDLIBS = -I/usr/local/opt/qt/include -lncurses

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@printf "%-50s" "create executable "$(notdir $@)...
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)
	@printf "\e[1;32m[OK]\e[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@printf "%-50s" "compiling "$(notdir $<)...
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@printf "\e[1;32m[OK]\e[0m\n"

clean:
	@printf "%-50s" "deleting objects..."
	@$(RM) $(OBJ)
	@printf "\e[1;32m[OK]\e[0m\n"

fclean: clean
	@printf "%-50s" "deleting executable..."
	@$(RM) $(NAME)
	@printf "\e[1;32m[OK]\e[0m\n"

re: fclean all
