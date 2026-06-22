NAME = simplylib.a

SRCDIR = src
OBJDIR = .obj
INCDIR = include

SRCS = vector/vector_init.c \
	   vector/vector_at.c \
	   vector/vector_free.c \
	   vector/vector_front.c \
	   vector/vector_back.c \
	   vector/vector_size.c \
	   vector/vector_capacity.c \
	   vector/vector_reserve.c \
	   vector/vector_shrink.c \
	   vector/vector_clear.c \
	   vector/vector_empty.c \
	   vector/vector_resize.c \
	   vector/vector_push_back.c \
	   vector/vector_pop_back.c \
	   vector/vector_insert.c \
	   vector/vector_erase.c \
	   vector/vector_begin.c \
	   vector/vector_end.c \
	   vector/get_header.c \

OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CFLAGS = -Werror -Wextra -Wall -pedantic -MD -MP -I $(INCDIR) -g3 -DNDEBUG=1
AR = ar -rcs
DEPFLAGS = -MMD -MP

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
