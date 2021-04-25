CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

INCDIR = includes

TARGET = libft.a
SOURCES = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET) : $(OBJECTS)
	ar cr $@ $(OBJECTS)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCDIR}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${TARGET}

re: fclean all
