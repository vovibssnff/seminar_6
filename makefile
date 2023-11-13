CC = gcc
CFLAGS = -Wall -Werror

# List of source files
SOURCES = main.c victor_vector.c

# List of object files
OBJECTS = $(SOURCES:.c=.o)

# Executable name
EXECUTABLE = main

# Default target
all: $(EXECUTABLE)

# Linking step
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

# Compilation step
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Run the executable
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Clean up
clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
