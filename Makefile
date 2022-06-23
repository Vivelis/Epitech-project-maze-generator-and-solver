##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile of project
##

NAME_1	=	solver/solver
NAME_2	=	generator/generator

TESTBIN	=	tests/testbin.sh
TESTTMP	=	res_generator.txt	\
			res_solver.txt

MAKEFLAGS	+=	--no-print-directory
.PHONY: all clean fclean re run_test clean_test

all:
	@$(MAKE) -C solver
	@printf "\e[1;34mFinished compiling solver\e[0m\n"
	@$(MAKE) -C generator
	@printf "\e[1;34mFinished compiling generator\e[0m\n"

clean_test:
	@rm -f $(TESTTMP)
	@printf "\e[1;33mFinished cleaning test tmp files\e[0m\n"

clean: clean_test
	@$(MAKE) clean -C solver
	@printf "\e[1;33mFinished cleaning solver\e[0m\n"
	@$(MAKE) clean -C generator
	@printf "\e[1;33mFinished cleaning generator\e[0m\n"

fclean:	clean_test
	@$(MAKE) fclean -C solver
	@$(MAKE) fclean -C generator

run_test: all
	@./$(TESTBIN) 10 10
	@./$(TESTBIN) 100 100
	@./$(TESTBIN) 1000 1000
	@./$(TESTBIN) 10000 10000
	@./$(TESTBIN) 10 10 perfect
	@./$(TESTBIN) 100 100 perfect
	@./$(TESTBIN) 1000 1000 perfect
	@./$(TESTBIN) 10000 10000 perfect

re: fclean all
