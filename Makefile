##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

  CC			= 		g++

  BIN           =       a.out
  FLAG          =       -W -Wall -Werror -W -std=c++20 -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

  INCLUDE       =       -I./include

  SRC           =	main.cpp

  OBJ           =       $(SRC:.cpp=.o)
  OBJMAIN       =       $(MAIN:.cpp=.o)
  OBJTEST       =       $(SRC_TEST:.cpp=.o)
  LIB           =       --coverage -lcriterion

  all: 	bin

  bin:          $(OBJ)
	@$(CC) -o $(BIN) $(OBJ) $(FLAG)
	@echo -e ${YELLOW} "[FINISHED] " ${DEFAULT} $(BIN)

  .c.o:
	@$(CC) $(INCLUDE) $(FLAG) -c $< -o $@
	@echo -e ${GREEN} "[OK]" ${DEFAULT} $<
  clean:
	@rm -f $(OBJ)
	@rm -f *.gcno
	@rm -f *.gcda
	@echo -e ${PURPLE} "[CLEANED]" ${DEFAULT}
  fclean:       clean
	@rm -f $(BIN)
	@rm -f unit_test
	@rm -f *.a

  re:           fclean all

  .PHONY: all clean fclean re

DEFAULT = "\033[00m"
GREEN = "\033[1;32m"
TEAL = "\033[1;36m"
RED = "\033[1;31m"
BLACK = "\033[1;30m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
PURPLE = "\033[1;35m"
WHITE = "\033[1;37m"
