.PHONY: all clean fclean re bonus

BLUE =\033[0;38;5;123m
LIGHT_PINK = \033[0;38;5;200m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[1;38;5;110m
GREEN = \033[1;32;111m
LIGHT_GREEN = \033[0;38;5;121m
LIGHT_RED = \033[0;38;5;110m
FLASH_GREEN = \033[33;32m
WHITE_BOLD = \033[37m
GREY = \033[3;90m
ORANGE = \033[3;91m

all:
	@make -C Checker
	@make -C Push_Swap

clean:
	@make -C Checker clean
	@make -C Push_Swap clean

fclean:
	@make -C Checker fclean
	@make -C Push_Swap fclean

re: fclean all