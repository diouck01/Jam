##
## EPITECH PROJECT, 2022
## MY_MAKEFILE
## File description:
## An _ a the start of the variable means
## that you don't need to modify this variable.
##

NAME = DardDesVilles
CC = g++
ROOT =
OUTPUT =
SRC_FILE_EXT = .cpp

#SRC
SRC_DIRS_REC = src/
SRC_DIRS =
SRC_FILES =

#INCLUDE
INCLUDE_DIRS_REC = include/
INCLUDE_DIRS =

#FLAGS
FLAGS = -g -g3 -Wextra -Wall -Werror -W -std=c++20 -lsfml-window -lsfml-system

#LIB
LIB_DIRS =
LIB_FLAGS =
LIB_INCL_PATH = include

#EXCLUDED
GLOB_EXCL_DIRS = ./bonus/
GLOB_EXCL_FILES =

#TEST
TEST_NAME = test_$(NAME)
TEST_FLAGS = --coverage -lcriterion
TEST_DIRS_REC = tests
TEST_DIRS =
TEST_FILES =
TEST_EXCL_DIRS =
TEST_EXCL_FILES = main.cpp
# Note: Folders should be write like this "folder/" and not "./folder/".
GCOV_EXCL = --exclude tests/

#OTHER
ECHO = echo -e
CLS_LINE = echo -ne "\r\033[0K"

DEFLT	=	"\033[00m"
PINK	=	"\033[0;36m"
GREEN	=	"\033[1;32m"
TEAL	=	"\033[1;36m"
RED 	=	"\033[0;31m"
BLUE	=	"\033[34m"
PURPLE	=	"\033[0;35m"
BLINK 	= 	"\033[1;92m"
SBLINK	= 	"\033[0m"
INVERT  =	"\033[7m"


# ---------------------- AUTO GENERATED DATA, DON'T TOUCH ----------------------
# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------

_ROOT = $(shell \
if [[ "$(ROOT)" == */ ]]; then \
	echo "$(ROOT)"; \
else \
	tmp=$(ROOT); \
	if [[ -n $$tmp ]]; then \
		echo "$(ROOT)/"; \
	else \
		echo "$(ROOT)"; \
	fi \
fi)

# Include
_INCLUDE_DIRS_REC_SUBDIRS = $(foreach dir, $(INCLUDE_DIRS_REC), \
	$(shell find $(_ROOT)$(dir) -type d 2>/dev/null))
_INCLUDE = $(INCLUDE_DIRS) $(_INCLUDE_DIRS_REC_SUBDIRS)
_INCLUDE_GCC = $(foreach dir,$(_INCLUDE),-I$(dir))


# Lib
_LIB = $(LIB_DIRS)
_LIB_GCC = $(foreach dir,$(_LIB),-L$(dir))
_FIND_LIB_EXCL_DIRS = $(foreach dir,$(_LIB),-not -path "$(dir)*")


# Excluded
_FIND_GLOB_EXCL_DIRS = $(foreach dir,$(GLOB_EXCL_DIRS),-not -path "$(dir)*")
_FIND_GLOB_EXCL_FILES = $(foreach file,$(GLOB_EXCL_FILES),-not -iname "$(file)")


# Tests
_FIND_TEST_EXCL_DIRS = $(foreach dir,$(TEST_EXCL_DIRS),-not -path "$(dir)*")
_FIND_TEST_EXCL_FILES = $(foreach dir,$(TEST_EXCL_FILES),-not -iname "$(dir)*")
_TEST_DIRS_FILES = $(foreach dir, $(TEST_DIRS), \
	$(shell find $(_ROOT)$(dir)/ -maxdepth 1 -type f -name "*$(SRC_FILE_EXT)" \
	$(_FIND_GLOB_EXCL_DIRS) $(_FIND_TEST_EXCL_DIRS) $(_FIND_LIB_EXCL_DIRS) \
	$(_FIND_GLOB_EXCL_FILES) $(_FIND_TEST_EXCL_FILES) 2>/dev/null))
_TEST_DIRS_FILES_REC = $(foreach dir, $(TEST_DIRS_REC), \
	$(shell find $(_ROOT)$(dir)/ -type f -name "*$(SRC_FILE_EXT)" \
	$(_FIND_GLOB_EXCL_DIRS) $(_FIND_TEST_EXCL_DIRS) $(_FIND_LIB_EXCL_DIRS) \
	$(_FIND_GLOB_EXCL_FILES) $(_FIND_TEST_EXCL_FILES) 2>/dev/null))
_TEST_SRC_DIRS_FILES = $(foreach dir, $(SRC_DIRS), \
	$(shell find $(_ROOT)$(dir)/ -maxdepth 1 -type f -name "*$(SRC_FILE_EXT)" \
	$(_FIND_GLOB_EXCL_DIRS) $(_FIND_TEST_EXCL_DIRS) $(_FIND_LIB_EXCL_DIRS) \
	$(_FIND_GLOB_EXCL_FILES) $(_FIND_TEST_EXCL_FILES) 2>/dev/null))
_TEST_SRC_DIRS_FILES_REC = $(foreach dir, $(SRC_DIRS_REC), \
	$(shell find $(_ROOT)$(dir)/ -type f -name "*$(SRC_FILE_EXT)" \
	$(_FIND_GLOB_EXCL_DIRS) $(_FIND_TEST_EXCL_DIRS) $(_FIND_LIB_EXCL_DIRS) \
	$(_FIND_GLOB_EXCL_FILES) $(_FIND_TEST_EXCL_FILES) 2>/dev/null))
_TEST = $(TEST_FILES) $(_TEST_DIRS_FILES) $(_TEST_DIRS_FILES_REC) \
	$(_TEST_SRC_DIRS_FILES) $(_TEST_SRC_DIRS_FILES_REC)
_FIND_TEST_SRC_EXCL_FILES = $(foreach file,$(_TEST),-not -iname "$(file)")


# Src
_SRC_DIRS_FILES = $(foreach dir, $(SRC_DIRS), \
	$(shell find $(_ROOT)$(dir)/ -maxdepth 1 -type f -name "*$(SRC_FILE_EXT)" \
	$(_FIND_GLOB_EXCL_DIRS) $(_FIND_LIB_EXCL_DIRS) \
	$(_FIND_GLOB_EXCL_FILES) $(_FIND_TEST_SRC_EXCL_FILES) 2>/dev/null))
_SRC_DIRS_FILES_REC = $(foreach dir, $(SRC_DIRS_REC), \
	$(shell find $(_ROOT)$(dir)/ -type f -name "*$(SRC_FILE_EXT)" \
	$(_FIND_GLOB_EXCL_DIRS) $(_FIND_LIB_EXCL_DIRS) \
	$(_FIND_GLOB_EXCL_FILES) $(_FIND_TEST_SRC_EXCL_FILES) 2>/dev/null))
_SRC = $(SRC_FILES) $(_SRC_DIRS_FILES) $(_SRC_DIRS_FILES_REC)

# Obj
_OBJ = $(_SRC:$(SRC_FILE_EXT)=.o)

# ---------------------- ################################ ----------------------
# ---------------------- ################################ ----------------------
# ---------------------- ################################ ----------------------

all: lib
	@$(ECHO) $(BLINK)$(PURPLE)"[COMPILING: $(NAME)]"$(DEFLT)
	@make object --no-print-directory && \
	make build --no-print-directory

object:$(NAME)
%.o : %$(SRC_FILE_EXT)
	@if [ -f $@ ]; then rm $@; fi
	@$(CLS_LINE)
	@$(CC) -o $@ -c $< $(_INCLUDE_GCC) $(_LIB_GCC) $(LIB_FLAGS) $(FLAGS) && \
	($(ECHO) -n $(BLINK)" [OK]"$(DEFLT) $<) || \
	($(ECHO) -n $(RED)" [KO]"$(DEFLT) $< "\n\n\n\n\n\n");
$(NAME):$(_OBJ)
	@($(CLS_LINE) ; $(ECHO) $(BLUE)" [OBJECT COMPILATION FINISHED]"$(DEFLT))

build:
	@$(CC) $(_OBJ) -o $(NAME) $(_INCLUDE_GCC) $(_LIB_GCC) \
	$(LIB_FLAGS) $(FLAGS) && \
	($(CLS_LINE) ; $(ECHO) $(BLINK)" [OK]"$(DEFLT) $(NAME)) || \
	$(ECHO) $(RED) "[KO]" $(DEFLT)$(NAME);

compil:
	$(CC) $(_SRC) -o $(NAME) $(_INCLUDE_GCC) $(_LIB_GCC) $(LIB_FLAGS) $(FLAGS)

clean:
	@find . -name "*.o" $(_FIND_LIB_EXCL_DIRS) -delete \
		-or -name "*~" -delete && \
	$(ECHO) $(BLINK) "[CLEAN DONE]" $(DEFLT)

fclean: clean_test_file clean
	@find .	-name "*.a" $(_FIND_LIB_EXCL_DIRS) -delete \
		-or -name "*.exe" -delete \
		-or -name "a.out" -delete \
		-or -name "*.so" -delete  \
		-or -name "vgcore*" -delete
	@$(ECHO) $(GREEN) "All temporal file deleted!" $(DEFLT)
	@find -maxdepth 1 -name $(NAME) -delete
	@$(ECHO) $(GREEN) "Executable deleted!" $(DEFLT)

re: fclean all

install: all
	@sudo mv $(NAME) /usr/bin/
	@$(ECHO) $(GREEN) "Program installed!" $(DEFLT)

uninstall:
	@sudo rm -i /usr/bin/$(NAME)
	@$(ECHO) $(GREEN) "Program deleted!" $(DEFLT)

lib: FORCE
	@for lib_dir in $(LIB_DIRS); do \
		$(ECHO) $(BLINK)$(PURPLE)"[COMPILING LIBRARIES IN: $$lib_dir]"$(DEFLT);\
		dirs=$$(find $$lib_dir -maxdepth 1 -mindepth 1 -type d 2>/dev/null); \
		for lib_path in $$dirs; do \
			$(ECHO) $(BLINK)$(BLUE)"[COMPILING LIBRARY: $$lib_path]"$(DEFLT);\
			make -C $$lib_path --no-print-directory; \
			lib_name=$$(basename $$lib_path); \
			mkdir -p $(LIB_INCL_PATH)$$lib_name; \
			cp -r $$lib_path/include/* $(LIB_INCL_PATH)$$lib_name; \
			cp $$lib_path/*.a $$lib_dir; \
		done \
	done

lib_clean:
	@find .	-name "*.a" -delete
	@$(ECHO) $(GREEN) "[.a static libraries files deleted.]" $(DEFLT)
	@for lib_dir in $(LIB_DIRS); do \
		$(ECHO) $(BLINK)$(PURPLE)"[CLEANING LIBRARIES IN $$lib_dir]"$(DEFLT); \
		dirs=$$(find $$lib_dir -maxdepth 1 -mindepth 1 -type d 2>/dev/null); \
		for lib_path in $$dirs; do \
			$(ECHO) $(BLINK)$(BLUE)"[CLEANING LIBRARY : $$lib_path]"$(DEFLT); \
			make -C $$lib_path fclean --no-print-directory; \
			lib_name=$$(basename $$lib_path); \
			rm -rf $(LIB_INCL_PATH)$$lib_name; \
		done \
	done

lib_re: lib_clean lib

clean_test_file:
	@find .	-name "*.gcno" -delete \
		-or -name "*.gcda" -delete \
		-or -name "*.gcov" -delete
	@find -maxdepth 1 -name $(TEST_NAME) -delete

unit_tests: clean_test_file lib
	@$(CC) -o $(TEST_NAME) $(_TEST) \
	$(_INCLUDE_GCC) $(_LIB_GCC) $(LIB_FLAGS) $(FLAGS) $(TEST_FLAGS)

run_exec -i:
	@./$(TEST_NAME)

tests_run: unit_tests run_exec

coverage:
	@tmp=$(_ROOT)
	@if [[ -n $$tmp ]]; then \
		gcovr -r $(_ROOT) $(GCOV_EXCL); \
	else \
		gcovr $(GCOV_EXCL); \
	fi

branches:
	@tmp=$(_ROOT)
	@if [[ -n $$tmp ]]; then \
		gcovr -r $(_ROOT) $(GCOV_EXCL) --branches; \
	else \
		gcovr $(GCOV_EXCL) --branches; \
	fi

test_log: coverage branches

test: unit_tests
	@make run_exec --no-print-directory -i
	@make coverage --no-print-directory
	@make branches --no-print-directory

show:
	@$(ECHO) $(BLINK)$(PURPLE)"[HEADER]"$(DEFLT)
	@$(ECHO) "  NAME     : $(NAME)"
	@$(ECHO) "  ROOT     : $(_ROOT)"
	@$(ECHO) "  FILE_OUT : $(OUTPUT)"
	@$(ECHO) "  COMPILER : $(CC)"
	@$(ECHO) "  FLAGS    : $(FLAGS)"
	@$(ECHO) "  SRC_DIRS : $(SRC_DIRS) $(SRC_DIRS_REC)"
	@$(ECHO) "  INCL_DIRS: $(_INCLUDE)"
	@$(ECHO) "  LIB_DIRS : $(LIB_DIRS)"
	@$(ECHO) "  LIB_FLAGS: $(LIB_FLAGS)"

show_file:
	@$(ECHO) $(BLINK)$(PURPLE)"[FILE]"$(DEFLT)
	@$(ECHO) "  INCLUDE:"
	@for file in $(INCLUDE_DIRS); do $(ECHO) "\t$$file"; done
	@for file in $(INCLUDE_DIRS_REC); do $(ECHO) "\t$$file (+SUB DIRS)"; done
	@$(ECHO) "  SRC_DIRECTORIES:"
	@for file in $(SRC_DIRS); do $(ECHO) "\t$$file"; done
	@for file in $(SRC_DIRS_REC); do $(ECHO) "\t$$file (+SUB DIRS)"; done
	@$(ECHO) "  SRC_FILE:"
	@for file in $(_SRC); do $(ECHO) "\t$$file"; done

show_all: show show_file

FORCE: