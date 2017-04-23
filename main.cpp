// Стрелки <Лево / Право> - смена сцены ========================================

#include <iostream>
#include <SFML/Graphics.hpp>
#include "data/scene.cpp"
#include <string>

using namespace std;

int main() {
    sf::RenderWindow app(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "KeyboardNinja", sf::Style::Titlebar | sf::Style::Close);

    app.setFramerateLimit(60);

    //Инициализация сцены
    scene_main_menu = new kb::SceneMainMenu;
    scene_main_menu->init(&app);

    scene_game = new kb::SceneGame;
    scene_game->init(&app);

    scene = scene_main_menu;

    while (app.isOpen())
    {
        //Обработчик событий
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
        }

        //Очистка экрана
        app.clear();

        //Вывод текущей сцены
        scene->draw();

        scene->step();

        //Отображение выведенного изображения
        app.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) app.close();
    }

    return 0;
}
