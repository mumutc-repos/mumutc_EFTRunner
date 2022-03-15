CXX = g++

CFLAGS = -std=c++0x

SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp, %.o, $(SRCS))

EXEC1=main1
EXEC2=main2

MOBJS=main1.o main2.o
SOBJS=$(filter-out $(MOBJS), $(OBJS))

# all:
#	@echo $(OBJS)
#	@echo $(MOBJS)
#	@echo $(SOBJS)
all:$(OBJS) $(EXEC1) $(EXEC2)

$(EXEC1): main1.o $(SOBJS)  
	$(CXX) $^ -o $@

$(EXEC2): main2.o $(SOBJS) 
	$(CXX) $^ -o $@

$(OBJS): $(SRCS)
	$(CXX) $(CFLAGS) -c $^

.PHONY:clean
clean:
	rm *.o $(EXEC1) $(EXEC2)
