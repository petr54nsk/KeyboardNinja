#ifndef SCENE_
#define SCENE_

#include "scene.hpp"

//Основной интерфейс класса
bool kb::Scene::init(sf::RenderWindow* app, kb::Scene *id) {
    return 0;
}

char kb::Scene::step() {
    return 0;
}

void kb::Scene::draw() {
    return;
}

char kb::Scene::destroy() {
    free(id_scene);
    id_scene = new kb::SceneMainMenu;
    id_scene->init(app,id_scene);
}

//Реализация остальных сцен
#include "scene_game.cpp"
#include "scene_main_menu.cpp"

#endif
