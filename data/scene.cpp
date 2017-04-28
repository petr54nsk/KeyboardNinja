#include "scene.hpp"
#include "scene_main_menu.hpp"
#include "scene_game.hpp"
#include "scene_table_lead.hpp"
#include "scene_input_lead.hpp"

// GLOBAL VARIABLES
kb::Scene *scene;                     // глобальный указатель на текущую сцену
kb::SceneMainMenu *scene_main_menu;   // Main Menu
kb::SceneGame *scene_game;            // Game Scene
SceneTableLead *scene_table_lead; // Table Leaders
kb::SceneInputLead *scene_input_lead; // Input new Leader

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

void kb::Scene::eventProc() {
    sf::Event event;
    while (app->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            app->close();
    }

    return;
}

//Реализация остальных сцен
#include "scene_game.cpp"
#include "scene_main_menu.cpp"
#include "scene_table_lead.cpp"
#include "scene_input_lead.cpp"
