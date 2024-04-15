CC = g++
CFLAGS = -std=c++11 -Wall -w
LDFLAGS =

SRCDIR = .
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,output/%.o,$(SRCS))
EXEC = TUBES_OOP

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

output/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f output/*.o $(EXEC)

.PHONY: all clean
