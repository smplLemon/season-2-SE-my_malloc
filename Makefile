CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
SOURCES = main_malloc.c source/*.c
TARGET = main_malloc
CC = gcc
	
$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^
.PHONY:
	fclean

fclean:
	@rm -f $(OBJECTS) $(TARGET)