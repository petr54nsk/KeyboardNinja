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
    font->loadFromFile("graphics/font.ttf");

    text = new sf::Text("Main Menu",*font,26);
    text->setPosition(200, 20);
    text->setColor(sf::Color::White);

    // Инициализация изображения
    image_texture = new sf::Texture;
    image_texture->loadFromFile("graphics/image.png");
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

    return 0;
}

/* Функция для вывода информации на экран. Выполняется как и Step на каждой
итерации главного цикла*/
void kb::SceneMainMenu::draw() {
    app->draw(*text);        // Вывод текста
    app->draw(*image_index); // Зачем я это пишу? Всё очевидно
    return;
}

/* Функция закрытия (смены) сцены */
void kb::SceneMainMenu::destroy() {
    // Очистка памяти
    delete (font);
    delete (text);

    delete (image_texture);
    delete (image_index);

    // Смена сцены
    scene = scene_game;
    scene->init(app);
    return;
}

//int kb::SceneMainMenu::new_function(int a, int b) {...}
