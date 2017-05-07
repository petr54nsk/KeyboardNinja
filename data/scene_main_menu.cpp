// Сцена главного меню =========================================================
/* При необходимости ввода новых глобальных переменных
(доступных во всех функция класса), объявлять их в разделе
private объекта класса SceneMainMenu (scene.hpp).
Туда же пихать объявления функций. */

/* Функция инициализации. Аргументы:
app - указатель на SFML-окно */
bool SceneMainMenu::init(sf::RenderWindow* app) {
    this->app = app;

    // Инициализация текста
 font = new sf::Font;
    font->loadFromFile("graphics/Rex_Bold.otf");

    text = new sf::Text("KeyboardNinja",*font,85);
    text->setPosition(368, 42);
    text->setColor(sf::Color(44, 62, 80));

    new_game = new sf::Text(L"Новая игра",*font,75);
    new_game->setPosition(441, 232);
    new_game->setColor(sf::Color(236, 240, 241));

    score = new sf::Text(L"Таблица рекордов",*font,75);
    score->setPosition(334, 349);
    score->setColor(sf::Color(236, 240, 241));

    exit1 = new sf::Text(L"Выход",*font,75);
    exit1->setPosition(526, 469);
    exit1->setColor(sf::Color(236, 240, 241));

    // Инициализация изображения
    image_texture = new sf::Texture;
    image_texture->loadFromFile("graphics/menu_backbround.png");
    image_index = new sf::Sprite(*image_texture);
    image_index->setTexture(*image_texture);

    return 0;
}

/* Шаг. Функция предназначена для отделения вычислений от вывода информации
на экран */
char SceneMainMenu::step() {

    // Смена сцены при нажатии
if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 221 && sf::Mouse::getPosition(*app).y < 324){
    new_game->setColor(sf::Color(231, 76, 60));
}else {new_game->setColor(sf::Color(236, 240, 241));}
if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 338 && sf::Mouse::getPosition(*app).y < 442){
    score->setColor(sf::Color(231, 76, 60));
    }else{score->setColor(sf::Color(236, 240, 241));}
    if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 455 && sf::Mouse::getPosition(*app).y < 568){
    exit1->setColor(sf::Color(231, 76, 60));
    }else{exit1->setColor(sf::Color(236, 240, 241));}


if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
{ 
    if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 221 && sf::Mouse::getPosition(*app).y < 324){
        destroy(scene_game);
        return 1;   
    }
    if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 338 && sf::Mouse::getPosition(*app).y < 442){
        destroy(scene_table_lead);
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
void SceneMainMenu::draw() {
    app->draw(*image_index); // Зачем я это пишу? Всё очевидно
    app->draw(*text);
    app->draw(*new_game);
    app->draw(*score);
    app->draw(*exit1);
    return;
}

/* Функция закрытия (смены) сцены */
void SceneMainMenu::destroy(Scene* next_scene) {
    // Очистка памяти
    //delete (font);
    //delete (text);
    //delete (new_game);
    //delete (score);
    //delete (exit1);
    delete (image_texture);
    delete (image_index);

    // Смена сцены
    scene = next_scene;
    scene->init(app);
    return;
}

//int kb::SceneMainMenu::new_function(int a, int b) {...}
