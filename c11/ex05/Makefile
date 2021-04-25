CC = gcc
CFLAGS = -Wall -Werror -Wextra

TARGET = do-op
INCDIR = includes

SRC = srcs/main.c srcs/utils/ft_strlen.c srcs/utils/add.c srcs/utils/minus.c srcs/utils/mul.c srcs/utils/modular.c srcs/utils/div.c

OBJECTS = $(SRC:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

clean :
	rm -f $(OBJECTS);

fclean : clean
	rm -f $(TARGET);

re : clean all
