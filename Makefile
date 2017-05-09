GCC       =  g++
FLAGS	  =  -Wall 
SFMLFLAGS =  -lsfml-graphics -lsfml-window -lsfml-system
APPNAME   =  application


all:
	mkdir -p bin
	g++ -g main.cpp -o bin/KeyNinja -lsfml-graphics -lsfml-window -lsfml-system
	cp -f graphics/background_bottom.png bin/background_bottom.png
	cp -f graphics/background_middle.png bin/background_middle.png
	cp -f graphics/background_top.png bin/background_top.png
	cp -f graphics/tabl.png bin/tabl.png
	cp -f graphics/tablhead.png bin/tablhead.png
	cp -f graphics/tablnohead2.png bin/tablnohead2.png
	cp -f graphics/radiance.woff bin/radiance.woff
	mkdir -p bin/graphics
	cp -f graphics/menu.png bin/graphics/menu.png
	cp -f graphics/font.TTF bin/graphics/font.TTF
	cp -f graphics/image.png bin/graphics/image.png
	cp -f graphics/button_input_table.png bin/button_input_table.png
	cp -f graphics/field_input.png bin/field_input.png
	cp -f graphics/background_input_table.png bin/background_input_table.png
	cp -f graphics/input_window.png bin/input_window.png

clean:
	rm -rf *.o
	rm -r bin

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