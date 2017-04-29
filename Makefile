GCC       =  g++
FLAGS	  =  -Wall 
SFMLFLAGS =  -lsfml-graphics -lsfml-window -lsfml-system
APPNAME   =  application

all: app

clean:
	rm -rf *.o
	rm -r bin

main.o: main.cpp
	$(GCC) -c -o main.o main.cpp 

app: main.o
	$(GCC) $(SFMLFLAGS) -o $(APPNAME) main.o 

run: $(APPNAME)
	 ./$(APPNAME)

romantest:
	mkdir -p bin
	g++ data/tabl.cpp -o bin/tabltest -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
	cp -f graphics/background_bottom.png bin/background_bottom.png
	cp -f graphics/background_middle.png bin/background_middle.png
	cp -f graphics/background_top.png bin/background_top.png
	cp -f graphics/tabl.png bin/tabl.png
	cp -f graphics/tablhead.png bin/tablhead.png
	cp -f graphics/tablnohead2.png bin/tablnohead2.png
	cp -f graphics/radiance.woff bin/radiance.woff