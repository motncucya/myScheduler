PROGRAM = myScheduler
SRCS = main.cpp parse.cpp scheduler.cpp show.cpp
CXX		= g++
CFLAGS	= -O2 -Wall -std=c++17
OBJS	= $(SRCS:.cpp=.o)

#.PHONY: all clean
all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS)  -o $@

clean:
	rm -rf $(OBJS) $(PROGRAM)