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

HEADER =  ../../Includes

HEADER_DEPENDENCIES =  ../../Dependencies/libft/includes/

DEPENDENCIES = ../../Dependencies/libft/libft.a ../../Dependencies/push_swap.a

SRCS_NAME = main.c algorithms/first_algo.c algorithms/merge_sort/merge_sort.c algorithms/merge_sort/find_position.c \
			algorithms/merge_sort/push_b_algo.c pattern.c

SRC_PATH = srcs/

SRCS = $(addprefix $(SRC_PATH), $(SRCS_NAME))

FLAG = -Wall -Werror -Wextra -O3 -g3 #-fsanitize=address#-fsanitize=undefined

OBJ_NAME = ${SRCS_NAME:.c=.o}

OBJ_PATH = ../../bin/push_swap/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

NAME = push_swap

all: libft $(OBJ_PATH) $(HEADER) $(NAME)

$(NAME): $(OBJ) $(HEADER) $(HEADER_DEPENDENCIES)
	@gcc $(FLAG) $(OBJ) -o $(NAME) -I ${HEADER} -I ${HEADER_DEPENDENCIES} ${DEPENDENCIES} 
	@printf "	\033[2K\r\033[1;38;5;110mPushSwap\t: \033[0;38;5;121mUpdated\n\033[0m"

$(OBJ_PATH):
	@mkdir -p ../../bin/ 2> /dev/null
	@mkdir -p ../../bin/push_swap/ 2> /dev/null
	@mkdir -p ../../bin/push_swap/algorithms/ 2> /dev/null
	@mkdir -p ../../bin/push_swap/algorithms/merge_sort/ 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) $(HEADER_DEPENDENCIES) Makefile
	@printf "\33[2K\r$(ORANGE)Compiling...	\033[37m$<\033[36m \033[0m"
	@gcc $(FLAG) -g3 -I ${HEADER} -I ${HEADER_DEPENDENCIES} -c $< -o $@

libft:
	@test -f ../../Dependencies/libft/libft.a || make -C ../../Dependencies/libft/

norme:
	@norminettev2

clean:
	@test -f ../../Dependencies/libft/libft.a || make -C ../../Dependencies/libft clean
	@printf "\33[2K\r$(ORANGE)Deleting PushSwap srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting PushSwap srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting PushSwap srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting PushSwap srcs/...	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting PushSwap srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting PushSwap srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting PushSwap srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting PushSwap srcs/...	\033[37m"
	@sleep 0.1
	@rm -rf ${OBJ_PATH}
	@printf "\33[2K\r$(ORANGE)Deleted successfully!\n\033[0m"

fclean: clean
	@rm -rf ${NAME} ${DEPENDENCIES}

re: fclean all