NAME = example

SRCDIR = .
OBJDIR = obj
INCDIR = .

SRCS =	$(addprefix $(SRCDIR)/, \
		example.c )

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

CFLAGS = -Wall -Wextra -Werror -pedantic -I $(INCDIR) -g
LDFLAGS = -lX11 -lXext -lm -lz
DEPFLAGS = -MMD -MP
MAKEFLAGS = --no-print-directory


all: $(NAME)

fast: CFLAGS += -Ofast
fast: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

refast: fclean
	make fast

bonus: all

-include $(DEPS)

.PHONY: all clean fclean re bonus FORCE
