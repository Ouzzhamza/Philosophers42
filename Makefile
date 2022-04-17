CC     = CC

CFLAGS  = -Wall -Wetra -Werror

UFILE  = /useful
USRC   = 
UFILES = $(addprefix $(UFILE), $(USRC))
UOBJ   = $(UPATH:%.c=:%.o)


MFILE  = /mandatory
MSRC   = main.c /
MFILES = $(addprefix $(MFILE), $(MSRC))
MOBJ   = $(MFILE:%.c=:%.o)


BFILE  = /bonus
BSRC   = 
BFILES = $(addprefix $(BFILE), $(BSRC))
MSRC   = 
BOBJ   = $(BFILE:%.c=:%.o)


%.o	    :%.c mandatory/philosopher.h bonus/philosopher_bonus.h
		$(CC) $(CFLAGS) -c $< -o $@

all     : NAME
bonus   : BNAME
NAME    : philosopher
BNAME   : philosopher_bonus

$(NAME) : $(MOBJ) $(UOBJ)
		  $(CC) $(CFLAGS) $(MOBJ) $(UOBJ) -o $(NAME)
		  @echo "$(CHANGE)∰$(RESET)\c"


$(BNAME) : $(BMOBJ) $(UOBJ)
		   $(CC) $(CFLAGS) $(BMOBJ) $(UOBJ) -o $(BNAME)
		   @echo "$(CHANGE)∰$(RESET)\c"



clean    : rm -f $(MOBJ) $(UOBJ) $(BOBJ)
		   @echo "$(YELLOW)object files$(TAB)$(RED)were deleted.$(RESET)\n"

fclean   : clean
			rm -f $(NAME) $(BNAME)
			@echo "$(NAME):$(TAB)$(YELLOW)$(NAME1)$(TAB)$(RED)was  deleted.$(RESET)"

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