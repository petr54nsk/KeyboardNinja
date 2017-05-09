#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "data/scene.cpp"

int main() {
    setlocale(LC_CTYPE, ""); // добавление русской расскладки
    sf::RenderWindow app(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "KeyboardNinja", sf::Style::Titlebar | sf::Style::Close);
    app.setFramerateLimit(60);
    app.setVerticalSyncEnabled(true);

    //Инициализация сцен
    scene_game = new SceneGame();
    //scene_game->init(&app);
    scene_table_lead = new SceneTableLead;
    //scene_table_lead->init(&app);
    scene_input_lead = new SceneInputLead;
    scene_main_menu = new SceneMainMenu;
    scene_main_menu->init(&app);

    scene = scene_main_menu;

    while (app.isOpen())
    {
        app.clear(sf::Color(236, 240, 241));
        scene->draw();
        scene->step();
        app.display();
    }
    return 0;
}
