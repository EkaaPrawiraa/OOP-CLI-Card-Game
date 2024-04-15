
PROGRAM = TUBES_OOP


CXX = g++


CXXFLAGS = -std=c++11 -Wall


SRCDIR = src


SRCS = $(shell find $(SRCDIR) -type f -name '*.cpp')


OBJS = $(SRCS:%.cpp=%.o)


all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(PROGRAM)
