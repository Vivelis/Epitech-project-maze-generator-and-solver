##
## EPITECH PROJECT, 2021
## The Marvelous Libmy
## File description:
## Makefile
##

#library name
LIB	=	libdante.a

#library sources
SRC	=	sources/print_map.c			\
		sources/sqstr.c				\
		sources/read_file.c			\
		sources/my_puterror.c		\
		sources/get_str_info.c		\
		sources/my_strncpy.c		\
		sources/count_char_in_str.c	\
		sources/count_idx.c			\
		sources/my_str_to_array.c
HDR	=	includes/lib.h

#Compiler and Linker
CC	= cc
OBJ	=	$(SRC:.c=.o)

#obj file path
BUILDDIR=	obj
SRCDIR	=	my

#tests data
TESTBIN	=	lib_tests
TESTSRC	=	tests/unit_tests.c
TESTOBJ	=	$(TESTSRC:.c=.o)

#flags
CFLAGS	=	-Wall -Wextra
IFLAGS	=	-Iincludes
DEBUGFLAGS	=	-g3
TESTFLAGS	=	-lcriterion
MAKEFLAGS	+=	--no-print-directory

#------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#------------------------------------------------------------------------------

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $^\
	&& printf "[\033[1;35mcompiled\033[0m]% 50s\n" $< |  tr ' ' '.'\
	|| printf "[\033[1;31merror\033[0m]% 50s\n" $< |  tr ' ' '.'

all: $(LIB)

$(LIB): $(OBJ)
	@ar rc $(LIB) $(OBJ)
	@printf "\e[1;36mFinished compiling library\e[0m\n"

clean:
	@rm -f *~
	@rm -f *#
	@rm -f $(OBJ)
	@rm -f $(TESTOBJ)
	@printf "\e[0;33mDeleted all .o in $(LIB)\e[0m\n"

fclean: clean
	@rm -f $(LIB)
	@rm -f $(TESTBIN)
	@printf "\e[0;33mDeleted $(LIB)\e[0m\n"
	@printf "\e[1;32mDeleted all .o in $(LIB) and $(LIB)\e[0m\n"

re: fclean all

debug: fclean $(OBJ)
	@$(CC) -o $(LIB) $(OBJ) $(IFLAGS) $(CFLAGS) $(DEBUGFLAGS)
	@echo -e "\e[1;36mFinished compiling $(LIB) $@\e[0m"

lib_unit_tests: $(OBJ) $(TESTOBJ)
	@$(CC) -o $(TESTBIN) $(OBJ) $(TESTOBJ) $(IFLAGS) $(CFLAGS) $(TESTFLAGS)
	@echo -e "\e[1;36mFinished compiling $(TESTBIN) $@\e[0m"

lib_run_tests: lib_unit_tests
	./$(TESTBIN)

.PHONY: all clean fclean re
