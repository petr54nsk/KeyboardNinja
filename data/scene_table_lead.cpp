bool kb::SceneTableLead::init(sf::RenderWindow* app) {
    return 0;
}

char kb::SceneTableLead::step() {
    eventProc(); // Обработчик событий
    return 0;
}

void kb::SceneTableLead::draw() {
    return;
}

void kb::SceneTableLead::destroy(Scene* scene_next) {
    return;
}
