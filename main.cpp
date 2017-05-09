#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "data/scene.cpp"
int const WINDOW_W = 1200;
int const WINDOW_H = 600;

int main() {
    setlocale(LC_CTYPE, ""); // добавление русской расскладки
    sf::RenderWindow app(sf::VideoMode(WINDOW_W, WINDOW_H), "KeyboardNinja", sf::Style::Titlebar | sf::Style::Close);
    app.setFramerateLimit(60);
    app.setVerticalSyncEnabled(true);

    scene_main_menu = new SceneMainMenu;
    scene_main_menu->init(&app);

    scene_game = new SceneGame();

    scene_table_lead = new SceneTableLead;
    scene_table_lead->init(app);

    scene_input_lead = new SceneInputLead;
    scene_input_lead->init(app);

    scene = scene_input_lead;

    while (app.isOpen())
    {
        app.clear(sf::Color(236, 240, 241));
        scene->draw();
        scene->step();
        app.display();
    }
    return 0;
}
