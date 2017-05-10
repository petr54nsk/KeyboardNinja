GCC       =  g++
FLAGS	  =  -Wall 
SFMLFLAGS =  -lsfml-graphics -lsfml-window -lsfml-system
APPNAME   =  application


all:
	mkdir -p bin
	g++ -g main.cpp -o bin/KeyNinja -lsfml-graphics -lsfml-window -lsfml-system
	cp -f -R graphics/ bin/
	cp -f -R resources/ bin/

clean:
	rm menu

scene_table_lead.o: data/scene_table_lead.cpp
	$(GCC) -c -o scene_table_lead.o data/scene_table_lead.cpp

main.o: main.cpp
	$(GCC) -c -o main.o main.cpp 

app: main.o scene_table_lead.o
	$(GCC) $(SFMLFLAGS) -o $(APPNAME) main.o scene_table_lead.o

run: $(APPNAME)
	 ./$(APPNAME)

menu:
	g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system -o menu