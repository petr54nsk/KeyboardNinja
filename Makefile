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

romantest:
	g++ data/tabl.cpp -o bin/tabltest -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
	cp -f resources/textures/background_bottom.png bin/background_bottom.png
	cp -f resources/textures/background_middle.png bin/background_middle.png
	cp -f resources/textures/background_top.png bin/background_top.png
	cp -f resources/textures/tabl.png bin/tabl.png
	cp -f resources/textures/tablhead.png bin/tablhead.png
	cp -f resources/textures/tablnohead2.png bin/tablnohead2.png
