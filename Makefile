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

SRCS_NAME	=	new_push_stack.c push.c swap.c rotate.c r_rotate.c push_swap_utils.c

HEADER		=	Includes/

HEADER_DEPENDENCIES =  Dependencies/libft/includes/

SRC_PATH	=	srcs/

SRCS		=	$(addprefix $(SRC_PATH), $(SRCS_NAME))

OBJ_NAME = ${SRCS_NAME:.c=.o}

OBJ_PATH = bin/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

NAME = push_swap.a

all: $(OBJ_PATH) $(NAME)
	@make -C Checker
	@make -C Push_Swap

$(NAME): $(OBJ) $(HEADER)
	@ar rcs ${NAME} ${OBJ}
	@mv ${NAME} Dependencies/.
	@printf "	\033[2K\r\033[1;38;5;110mpush_swap.a\t: \033[0;38;5;121mUpdated\n\033[0m"

$(OBJ_PATH):
	@mkdir -p bin/ 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) Makefile
	@printf "\33[2K\r$(ORANGE)Compiling...	\033[37m$<\033[36m \033[0m"
	@gcc $(FLAG) -g3 -I ${HEADER} -I ${HEADER_DEPENDENCIES} -c $< -o $@

clean:
	@rm -rf ${OBJ_PATH}
	@make -C Checker clean
	@make -C Push_Swap clean

fclean:
	@rm -rf ${OBJ_PATH} Dependencies/${NAME}
	@make -C Checker fclean
	@make -C Push_Swap fclean

re: fclean all