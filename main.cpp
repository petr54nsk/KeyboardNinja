#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "data/scene.cpp"
int const WINDOW_W = 1200;
int const WINDOW_H = 600;
// int initAllScenes(sf::RenderWindow &app);

int main() {
    sf::RenderWindow app(sf::VideoMode(WINDOW_W, WINDOW_H), "KeyboardNinja", sf::Style::Titlebar | sf::Style::Close);
    app.setFramerateLimit(60);

    //Инициализация сцен
    // initAllScenes(app);

    scene_main_menu = new kb::SceneMainMenu;
    scene_main_menu->init(&app);

    scene_game = new kb::SceneGame;
    scene_game->init(&app);

    scene_table_lead = new kb::SceneTableLead;
    scene_table_lead->init(&app);

    scene_input_lead = new kb::SceneInputLead;
    scene_input_lead->init(&app);

    scene = scene_main_menu;


    while (app.isOpen())
    {
        app.clear();
        scene_table_lead->draw();
        scene_table_lead->step();
        app.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) app.close();
    }
    return 0;
}

/*int initAllScenes(sf::RenderWindow &app) {  // Рома, доволен? Адрес - не указатель )0))
    
    return 0;
}*/
