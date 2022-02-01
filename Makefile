CXX = g++

CFLAGS = -std=c++0x

SRCS=*.cpp
OBJS=$(SRCS:.cpp=.o)
EXEC=main

all:$(EXEC) $(OBJS)

$(EXEC): $(OBJS) 
	$(CXX) $(OBJS) -o $@

$(OBJS): $(SRCS)
	$(CXX) $(CFLAGS) -c $^

clean:
	rm *.o
