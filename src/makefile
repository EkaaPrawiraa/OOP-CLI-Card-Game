ifeq ($(OS),Windows_NT)
    RM = cmd //C del /q
    MKDIR = mkdir
else
    RM = rm -f
    MKDIR = mkdir -p
endif

CC = g++
CFLAGS = -std=c++11 -Wall -w -g
LDFLAGS =

SRCDIR = .
# Include Storage/Storage.hpp and exclude Storage.cpp from the list of source files
SRCS = $(filter-out $(SRCDIR)/Storage.cpp, $(wildcard $(SRCDIR)/*.cpp)) $(SRCDIR)/Storage/Storage.hpp
OBJS = $(patsubst $(SRCDIR)/%.cpp,output/%.o,$(SRCS))
EXEC = TUBES_OOP

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

output/%.o: $(SRCDIR)/%.cpp | output
	$(CC) $(CFLAGS) -c $< -o $@

output:
	$(MKDIR) output

clean:
	$(RM) output/*.o $(EXEC)

.PHONY: all clean
