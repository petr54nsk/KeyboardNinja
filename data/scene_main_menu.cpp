// Сцена главного меню =========================================================
/* При необходимости ввода новых глобальных переменных, объявлять их в разделе
private объекта класса SceneMainMenu (schene.hpp) */

/* Функция инициализации. Аргументы:
app - указатель на SFML-окно
id  - указатель на переменную класса Scene, обрабатываемую в основном цикле
программы. (см. main.cpp)*/
bool kb::SceneMainMenu::init(sf::RenderWindow* app, kb::Scene *id) {
    this->app = app;
    id_scene = id;

    font = new sf::Font;
    font->loadFromFile("graphics/font.ttf");

    text = new sf::Text("Keyboard Ninja",*font,26);
    text->setPosition(20, 20);
    text->setColor(sf::Color::White);

    return 0;
}

/* Шаг. Функция предназначена для отделения вычислений от вывода информации
на экран */
char kb::SceneMainMenu::step() {

    // Смена сцены при нажатии
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        destroy();
        return 1;
    }

    return 0;
}

/* Функция для вывода информации на экран. Выполняется как и Step на каждой
итерации главного цикла*/
void kb::SceneMainMenu::draw() {
    app->draw(*text);
    return;
}

void kb::SceneMainMenu::destroy() {
    /*printf("%d",scene);
    free(scene);

    scene = new kb::SceneGame;
    scene->init(app,id_scene);*/
    scene = scene1;
    return;
}
