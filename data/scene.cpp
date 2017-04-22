#ifndef SCENE_
#define SCENE_

#include "scene.hpp"

kb::Scene *scene;
kb::SceneMainMenu *scene_main_menu;
kb::SceneGame *scene_game;

//Основной интерфейс класса
bool kb::Scene::init(sf::RenderWindow* app) {
    return 0;
}

char kb::Scene::step() {
    return 0;
}

void kb::Scene::draw() {
    return;
}

void kb::Scene::destroy() {
    return;
}

//Реализация остальных сцен
#include "scene_game.cpp"
#include "scene_main_menu.cpp"

#endif
