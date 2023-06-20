.PHONY : clean
CC = g++
RM = rm 
EXE = a.out

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

$(EXE) : $(OBJS)
	$(CC) -o $@ $^
%.o : %.cpp
	$(CC) -o $@ -c $^

clean:
	$(RM) $(EXE) $(OBJS)