/*
Сцена игры
*/

bool kb::SceneGame::init(sf::RenderWindow* app, kb::Scene *id) {
    this->app = app;
    id_scene = id;

    image_texture = new sf::Texture;
    image_texture->loadFromFile("graphics/image.png");

    image_index = new sf::Sprite(*image_texture);
    image_index->setTexture(*image_texture);

    return 0;
}

char kb::SceneGame::step() {

    // Смена сцены при нажатии
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        free(id_scene);
        id_scene = new kb::SceneMainMenu;
        id_scene->init(app,id_scene);
        return 1;
    }

    return 0;
}

void kb::SceneGame::draw() {
    app->draw(*image_index);
    return;
}
