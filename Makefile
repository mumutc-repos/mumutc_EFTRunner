CXX = g++

CFLAGS = -std=c++0x

SRCS=*.cpp
OBJS=$(SRCS:.cpp=.o)

OBJS1=main1.o sys_SM.o
EXEC1=main1

OBJS2=main2.o sys_SM.o
EXEC2=main2

all:$(OBJS) $(EXEC1) $(EXEC2)

$(EXEC1): $(OBJS1) 
	$(CXX) $^ -o $@

$(EXEC2): $(OBJS2) 
	$(CXX) $^ -o $@

$(OBJS): $(SRCS)
	$(CXX) $(CFLAGS) -c $^

clean:
	rm *.o
