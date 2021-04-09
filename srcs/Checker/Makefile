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

HEADER = ../../Includes

HEADER_DEPENDENCIES =  ../../Dependencies/libft/includes/

DEPENDENCIES = ../../Dependencies/libft/libft.a ../../Dependencies/push_swap.a

SRCS_NAME = main.c

SRC_PATH = srcs/

SRCS = $(addprefix $(SRC_PATH), $(SRCS_NAME))

FLAG = -Wall -Werror -Wextra -O3 -g3 #-fsanitize=address#-fsanitize=undefined

OBJ_NAME = ${SRCS_NAME:.c=.o}

OBJ_PATH = ../../bin/checker/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

NAME = checker

all: libft $(OBJ_PATH) $(HEADER) $(NAME)

$(NAME): $(OBJ) $(HEADER) $(HEADER_DEPENDENCIES)
	@gcc $(FLAG) $(OBJ) -o $(NAME) -I ${HEADER} -I ${HEADER_DEPENDENCIES} ${DEPENDENCIES} 
	@printf "	\033[2K\r\033[1;38;5;110mChecker\t\t: \033[0;38;5;121mUpdated\n\033[0m"

$(OBJ_PATH):
	@mkdir -p ../../bin/ 2> /dev/null
	@mkdir -p ../../bin/checker/ 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) $(HEADER_DEPENDENCIES) Makefile
	@printf "\33[2K\r$(ORANGE)Compiling...	\033[37m$<\033[36m \033[0m"
	@gcc $(FLAG) -g3 -I ${HEADER} -I ${HEADER_DEPENDENCIES} -c $< -o $@

libft:
	@test -f ../../Dependencies/libft/libft.a || make -C ../../Dependencies/libft/

lib:
	@make -C ../ lib

norme:
	@norminettev2

clean:
	@test -f ../../Dependencies/libft/libft.a || make -C ../../Dependencies/libft clean
	@printf "\33[2K\r$(ORANGE)Deleting checker srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting checker srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting checker srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting checker srcs/...	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting checker srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting checker srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting checker srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(ORANGE)Deleting checker srcs/...	\033[37m"
	@sleep 0.1
	@rm -rf ${OBJ_PATH}
	@printf "\33[2K\r$(ORANGE)Deleted successfully!\n\033[0m"

fclean: clean
	@rm -rf ${NAME} ${DEPENDENCIES}

re: fclean all