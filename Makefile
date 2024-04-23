NAME	:= pipex
CFLAGS	:= -g -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBFT 	:= ./libft

HEADERS	:= -I./include -I$(LIBFT)
LIBS	:= $(LIBFT)/libft.a
SRCS	:= pipex.c
OBJS	:= ${SRCS:.c=.o}

all: libft $(NAME)

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: clean all

.PHONY: all, clean, fclean, re, libft