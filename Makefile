GCC       =  g++
FLAGS	  =  -Wall
SFMLFLAGS =  -lsfml-graphics -lsfml-window -lsfml-system
APPNAME   =  application

all: app

clean:
	rm -rf *.o

main.o: main.cpp
	$(GCC) -c -o main.o main.cpp

app: main.o
	$(GCC) $(SFMLFLAGS) -o $(APPNAME) main.o

run: $(APPNAME)
	 ./$(APPNAME)
