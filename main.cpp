#include "main.hpp"

int main() {
    sf::RenderWindow app(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "KeyboardNinja", sf::Style::Titlebar | sf::Style::Close);
    app.setFramerateLimit(60);

    //Инициализация сцен
    //initAllScenes(app);

    while (app.isOpen())
    {
        app.clear();
        //scene_table_lead->draw();
        //scene_table_lead->step();
        app.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) app.close();
    }
    return 0;
}

int initAllScenes(sf::RenderWindow &app) {  // Рома, доволен? Адрес - не указатель )0))
    scene_main_menu = new kb::SceneMainMenu;
    scene_main_menu->init(&app);

    scene_game = new kb::SceneGame;
    scene_game->init(&app);

    scene_table_lead = new SceneTableLead;
    scene_table_lead->init(app);

    scene_input_lead = new kb::SceneInputLead;
    scene_input_lead->init(&app);
    return 0;
}

#include "data/scene_game.cpp"
#include "data/scene_main_menu.cpp"
#include "data/scene_table_lead.cpp"
#include "data/scene_input_lead.cpp"