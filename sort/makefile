.PHONY : clean
CC = g++
RM = rm 
# CFLAGS = -Wall -g
CFLAGS = -g


# 源文件目录
DIR_SRC = ./src

# 头文件目录
DIR_INC = ./include

# 目标文件目录
DIR_OBJ = ./obj

# 可执行文件目录
DIR_BIN = ./bin


SRCS = $(wildcard ${DIR_SRC}/*.cpp)
OBJS = $(patsubst %.cpp,$(DIR_OBJ)/%.o,$(notdir $(SRCS)))

TARGET = $(DIR_BIN)/main 

all: $(TARGET)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.cpp
	$(CC) $(CFLAGS) -o $@ -I${DIR_INC} -c $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(TARGET) $(DIR_OBJ)/*.o
