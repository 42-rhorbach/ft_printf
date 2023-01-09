# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rhorbach <rhorbach@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/14 12:49:02 by rhorbach      #+#    #+#                  #
#    Updated: 2023/01/09 15:05:05 by rhorbach      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADERFILES = libft.h ft_printf.h
NORMFLAGS = -Wall -Wextra -Werror $(if $(DEBUG),-g -fsanitize=address)
OBJDIR = obj
FILES =						\

BONUSFILES =						\

ifdef BONUS
FILES += $(BONUSFILES)
endif

OBJFILES = $(addprefix $(OBJDIR)/,$(FILES:c=o))

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJFILES) $(LIBFT)
	ar -rcs $(NAME) $(OBJFILES)

$(LIBFT):
	$(MAKE) -C $(dir $(LIBFT))

obj/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	$(CC) -c $(NORMFLAGS) -o $@ $<

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	$(MAKE) all BONUS=1


ifdef DEBUG
test: $(NAME)
	gcc $(NORMFLAGS) main.c -L. -l ftprintf -o DEBUG_ft_printf
else
test:
	$(MAKE) test DEBUG=1
endif

.PHONY: all clean fcleam re test bonus
