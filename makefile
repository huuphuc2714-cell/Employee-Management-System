CPP = g++ 

CFLAGS = -Wall -g -O2 -I include 
VPATH = src 

INC = $(wildcard include/*.h)
SRCS = $(wildcard *.cpp) $(wildcard src/*.cpp) 
OBJS = $(patsubst %.cpp,%.o,$(notdir $(SRCS))) 

all: QuanLyNhanSu.exe

QuanLyNhanSu.exe: $(OBJS) 
	$(CPP) $(CFLAGS) $^ -o QuanLyNhanSu.exe

%.o: %.cpp $(INC)
	$(CPP) -c $(CFLAGS) $< -o $@

.PHONY: run clean 

run: QuanLyNhanSu.exe
	./QuanLyNhanSu.exe

clean: 
	-del /Q /F QuanLyNhanSu.exe *.o 