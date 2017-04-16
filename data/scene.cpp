#ifndef SCENE_
#define SCENE_

#include "scene.hpp"

// SCENE (BASE CLASS) ==========================================================

bool kb::Scene::init(sf::RenderWindow* app, kb::Scene *id) {
    return 0;
}

char kb::Scene::step() {
    return 0;
}

void kb::Scene::draw() {
    return;
}

// SCENE 0 =====================================================================

bool kb::Scene0::init(sf::RenderWindow* app, kb::Scene *id) {
    this->app = app;
    id_scene = id;

    font = new sf::Font;
    font->loadFromFile("graphics/font.ttf");

    text = new sf::Text("Keyboard Ninja",*font,26);
    text->setPosition(20, 20);
    text->setColor(sf::Color::White);

    return 0;
}

char kb::Scene0::step() {

    // Смена сцены при нажатии
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        delete id_scene;
        id_scene = new kb::Scene1;
        id_scene->init(app,id_scene);
        return 1;
    }

    return 0;
}

void kb::Scene0::draw() {
    app->draw(*text);
    return;
}


// SCENE 1 =====================================================================

bool kb::Scene1::init(sf::RenderWindow* app, kb::Scene *id) {
    this->app = app;
    id_scene = id;

    image_texture = new sf::Texture;
    image_texture->loadFromFile("graphics/image.png");

    image_index = new sf::Sprite(*image_texture);
    image_index->setTexture(*image_texture);

    return 0;
}

char kb::Scene1::step() {

    // Смена сцены при нажатии
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        delete id_scene;
        id_scene = new kb::Scene0;
        id_scene->init(app,id_scene);
        return 1;
    }

    return 0;
}

void kb::Scene1::draw() {
    app->draw(*image_index);
    return;
}

#endif
