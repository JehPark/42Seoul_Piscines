CC = gcc
CFLAGS = -Wall -Werror -Wextra

TARGET = bsq
INCLUDES = includes
SOURCES = srcs/error.c srcs/file.c srcs/main.c srcs/logic.c srcs/utils/ft_m.c srcs/utils/ft_putstr.c srcs/utils/ft_natoi.c srcs/utils/ft_strlen.c srcs/utils/ft_strcat.c srcs/utils/ft_error_msg.c
OBJECTS = $(SOURCES:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	${CC} $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(TARGET)

re : clean all
