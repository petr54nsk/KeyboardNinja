// Сцена главного меню =========================================================
/* При необходимости ввода новых глобальных переменных
(доступных во всех функция класса), объявлять их в разделе
private объекта класса SceneMainMenu (scene.hpp).
Туда же пихать объявления функций. */

/* Функция инициализации. Аргументы:
app - указатель на SFML-окно */
bool SceneMainMenu::init(sf::RenderWindow* app) {
    this->app = app;

    check1 = 1;
    color1 = 0;
    check2 = 0;
    color2 = 0;
    check3 = 0;
    color3 = 0;
    check4 = 0;
    check5 = 0;
    check6 = 0;

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
void SceneMainMenu::eventProc() {
    sf::Event event;
    while (app->pollEvent(event))
    {
        if (event.type == sf::Event::Closed){
            app->close();}
    }
}

char SceneMainMenu::step(){
    eventProc();

    if (check1==1 && color1<252 && check4==0){
        color1+=4;}
    if (color1==252 && check4==0){
        check2=1;}
    if (check2==1 && color2<252 && check4==0){
        color2+=4;}
    if (color2==252 && color1>0 && check4==0){
        check1=0;color1-=4;}
    if (color2==252 && color1==0 && check4==0){
        check3=1;}
    if (check3==1 && color3<252 && check4==0){
        color3+=4;}
    if (color2==252 && color3==252 && check4==0){
        check2=0;}
    if (check2==0 && color3==252 && check4==0){
        color2-=4;}
    if (check3==1 && color2==0 && check4==0){
        check4=1;}
    if (check4==1 && color2==0 && check5==0){
        color1+=4;}
    if (check4==1 && color1==252 && check5==0){
        check5=1;}
    if (check4==1 && check5==1 && color1==252 && check6==0){
        color3-=4;}
    if (check4==1 && check5==1 && color3==0 && check6==0){
        check6=1;}
    if (check4==1 && check5==1 && color3==0 && check6==1){
        color1-=4;}
    if (check4==1 && check5==1 && color1==0 && check6==1){
        check1 = 1; color1 = 0; check2 = 0; color2 = 0; check3 = 0; color3 = 0; check4 = 0; check5 = 0; check6 = 0;}

    if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 221 && sf::Mouse::getPosition(*app).y < 324){
        new_game->setColor(sf::Color(color1, color2, color3));
    }else {new_game->setColor(sf::Color(236, 240, 241));}
    if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 338 && sf::Mouse::getPosition(*app).y < 442){
        score->setColor(sf::Color(color1, color2, color3));
    }else{score->setColor(sf::Color(236, 240, 241));}
    if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 455 && sf::Mouse::getPosition(*app).y < 568){
        exit1->setColor(sf::Color(color1, color2, color3));
    }else{exit1->setColor(sf::Color(236, 240, 241));}

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 221 && sf::Mouse::getPosition(*app).y < 324){
        scene_game = new SceneGame();
        scene_game->init(app);
        scene = scene_game;
    }
    if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 338 && sf::Mouse::getPosition(*app).y < 442){
        destroy(scene_table_lead);}
    if(sf::Mouse::getPosition(*app).x > 310 && sf::Mouse::getPosition(*app).x <920 && sf::Mouse::getPosition(*app).y > 455 && sf::Mouse::getPosition(*app).y < 568){
        app->close();} // Функция закрытия окна
    }

    return 0;
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
    //delete (image_texture);
    //delete (image_index);

    // Смена сцены
    scene = next_scene;
    return;
}

//int SceneMainMenu::new_function(int a, int b) {...}
