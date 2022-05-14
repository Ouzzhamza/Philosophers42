CC     = cc

CFLAGS  = -Wall -Wextra -Werror -g

MSRC   = main.c philosopher.c err_exit.c death.c ft_atoi.c ft_strlen.c get_time.c exiting.c printing.c sleep.c

MOBJ   = $(MSRC:%.c=%.o)

%.o	    :%.c mandatory/philosopher.h
		@$(CC) $(CFLAGS) -c $< -o $@

NAME    = philo
BNAME   = philosopher_bonus

all     : $(NAME)

$(NAME) : $(MOBJ)
		  @$(CC) $(MOBJ) -o $(NAME)
		  @echo "$(GREEN)DONE$(RESET)"

clean    : 
		  @ rm -f $(MOBJ)
		   @echo "$(YELLOW)object files$(TAB)$(RED)were deleted.$(RESET)"

fclean   : clean
		   @ rm -f $(NAME)
		   @echo "$(RED)DELETED.$(RESET)"

re       : fclean all

.PHONY   : all bonus clean fclean re
 .SILENT  :


GREEN = \033[0;32m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CHANGE = \033[0;35m
TAB = "\	"