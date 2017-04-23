#ifndef SCENE_
#define SCENE_

#include "scene.hpp"
#include "scene_main_menu.hpp"
#include "scene_game.hpp"
#include "scene_table_lead.hpp"
#include "scene_input_lead.hpp"

kb::Scene *scene;
kb::SceneMainMenu *scene_main_menu;
kb::SceneGame *scene_game;
kb::SceneTableLead *scene_table_lead;
kb::SceneInputLead *scene_input_lead;

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

void kb::Scene::destroy(Scene* scene_next) {
    return;
}

//Реализация остальных сцен
#include "scene_game.cpp"
#include "scene_main_menu.cpp"
#include "scene_table_lead.cpp"
#include "scene_input_lead.cpp"

#endif
