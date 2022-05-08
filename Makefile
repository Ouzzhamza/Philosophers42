CC     = cc

CFLAGS  = -Wall -Wextra -Werror

MFILE  = mandatory/
UFILE  = useful/
# BFILE  = bonus /

MSRC   = main.c philosopher.c exit.c \
USRC   = death.c ft_atoi.c ft_strlen.c get_time.c \
# BSRC   = 

MPATH = $(addprefix $(MFILE), $(MSRC))
UPATH = $(addprefix $(UFILE), $(USRC))
# BFILES = $(addprefix $(BFILE), $(BSRC))


MOBJ   = $(MPATH:%.c=%.o)
UOBJ   = $(UPATH:%.c=%.o)

# BOBJ   = $(BFILE:%.c=:%.o)
%.o	    :%.c mandatory/philosopher.h
		$(CC) $(CFLAGS) -c $< -o $@


NAME    = philosopher
BNAME   = philosopher_bonus

all     : $(NAME)


# bonus   : BNAME

$(NAME) : $(MOBJ) $(UOBJ)
		  $(CC) $(MOBJ) $(UOBJ) -o $(NAME)
		  @echo "$(CHANGE)∰$(RESET)\c"


# $(BNAME) : $(BMOBJ) $(UOBJ)
# 		   $(CC) $(CFLAGS) $(BMOBJ) $(UOBJ) -o $(BNAME)
# 		   @echo "$(CHANGE)∰$(RESET)\c"


clean    : 
		   rm -f $(MOBJ)
		   @echo "$(YELLOW)object files$(TAB)$(RED)were deleted.$(RESET)"

fclean   : clean
		   rm -f $(NAME)
		   @echo "$(NAME)$(RED)DELETED.$(RESET)"

re       : fclean all

.PHONY   : all bonus clean fclean re
# .SILENT  :


GREEN = \033[0;32m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CHANGE = \033[0;35m
TAB = "\	"