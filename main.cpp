// Стрелки <Лево / Право> - смена сцены ========================================

#include <iostream>
#include <SFML/Graphics.hpp>
#include "data/scene.cpp"

using namespace std;

int main() {
    sf::RenderWindow app(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "KeyboardNinja");

    app.setFramerateLimit(60);

    //Инициализация сцены
    scene0 = new kb::SceneMainMenu;
    scene0->init(&app,scene0);

    scene1 = new kb::SceneGame;
    scene1->init(&app,scene1);

    scene = scene0;

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
