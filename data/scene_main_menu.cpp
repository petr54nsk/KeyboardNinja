// Сцена главного меню =========================================================
/* При необходимости ввода новых глобальных переменных
(доступных во всех функция класса), объявлять их в разделе
private объекта класса SceneMainMenu (scene.hpp).
Туда же пихать объявления функций. */

/* Функция инициализации. Аргументы:
app - указатель на SFML-окно */
bool kb::SceneMainMenu::init(sf::RenderWindow* app) {
    this->app = app;

    // Инициализация текста
    font = new sf::Font;
    font->loadFromFile("graphics/Rex_Bold.otf");

    text = new sf::Text("KeyboardNinja",*font,85);
    text->setPosition(368, 42);
    text->setColor(sf::Color(82, 102, 111));

    new_game = new sf::Text("Новая игра",*font,75);
    new_game->setPosition(431, 242);
    new_game->setColor(sf::Color(252, 255, 245));

    score = new sf::Text("Таблица рекордов",*font,75);
    score->setPosition(324, 359);
    score->setColor(sf::Color(252, 255, 245));

    exit = new sf::Text("Выход",*font,75);
    exit->setPosition(516, 479);
    exit->setColor(sf::Color(252, 255, 245));

    // Инициализация изображения
    image_texture = new sf::Texture;
    image_texture->loadFromFile("graphics/menu_backbround.png");
    image_index = new sf::Sprite(*image_texture);
    image_index->setTexture(*image_texture);

    return 0;
}

/* Шаг. Функция предназначена для отделения вычислений от вывода информации
на экран */
char kb::SceneMainMenu::step() {

    // Смена сцены при нажатии
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        destroy(); // Дефолтная функция закрытия сцены
        return 1;
    }
if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
{ 
    if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 221 && sf::Mouse::getPosition(*app).y < 324){
        destroy(); // Дефолтная функция закрытия сцены
        return 1;   
    }
    if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 338 && sf::Mouse::getPosition(*app).y < 442){
        destroy();
        return 1;
    }
    if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 455 && sf::Mouse::getPosition(*app).y < 568){
        app->close(); // Функция закрытия окна
        return 1;
    }
    return 0;}
}

/* Функция для вывода информации на экран. Выполняется как и Step на каждой
итерации главного цикла*/
void kb::SceneMainMenu::draw() {
    app->draw(*image_index); // Зачем я это пишу? Всё очевидно
    app->draw(*text);
    app->draw(*new_game);
    app->draw(*score);
    app->draw(*exit);
    return;
}

/* Функция закрытия (смены) сцены */
void kb::SceneMainMenu::destroy() {
    // Очистка памяти
//    delete (font);
//    delete (text);

    delete (image_texture);
    delete (image_index);

    // Смена сцены
    scene = scene_game;
    scene->init(app);
    return;
}

//int kb::SceneMainMenu::new_function(int a, int b) {...}