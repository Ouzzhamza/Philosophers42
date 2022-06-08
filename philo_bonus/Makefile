CC     = cc

CFLAGS  = -Wall -Wextra -Werror 

MSRC   = main.c philosopher_bonus.c err_exit_bonus.c death_bonus.c ft_atoi_bonus.c ft_strlen_bonus.c \
		get_time_bonus.c exiting_bonus.c printing_bonus.c sleep_bonus.c ft_strcmp.c

MOBJ   = $(MSRC:%.c=%.o)

%.o	    :%.c mandatory/philosopher.h
		@$(CC) $(CFLAGS) -c $< -o $@

NAME    = philo_bonus
BNAME   = philosopher_bonus

bonus     : $(NAME)

$(NAME) : $(MOBJ)
		  @$(CC) $(CFLAGS) $(MOBJ) -o $(NAME)
		  @echo "$(GREEN)BONUS DONE$(RESET)"

clean    : 
		  @ rm -f $(MOBJ)
		   @echo "$(YELLOW)bonus object files$(TAB)$(RED)were deleted.$(RESET)"

fclean   : clean
		   @ rm -f $(NAME)
		   @echo "$(RED)DELETED.$(RESET)"

re       : fclean bonus

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