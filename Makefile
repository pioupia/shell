NAME = shell
HEADER = ./includes/
CC = gcc
CFLAGS = -Werror -Wall -Wextra -g -I $(HEADER)
SOURCES = src/main.c \
				src/builtin/console.c \
				src/builtin/env.c \
				src/builtin/strings.c \
				src/parser/parser.c \
				src/builtin/exec.c


OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)


# Target to clean up after us
clean:
				rm -rf $(OBJECTS)
				rm -rf $(NAME)
