.PHONY : clean
RM = rm 
CC = g++ 
EXE = a.out

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

$(EXE) : $(OBJS)
	$(CC) -o $@ $^
%.o : %.cpp 
	$(cc) -o $@ -c $^
clean:
	$(RM) $(OBJS) $(EXE)