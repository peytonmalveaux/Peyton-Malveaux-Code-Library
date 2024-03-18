CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = command.o main.o
TARGET = project1
all: $(TARGET)
$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~
