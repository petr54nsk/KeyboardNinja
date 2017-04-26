bool kb::SceneInputLead::init(sf::RenderWindow* app) {
    return 0;
}

char kb::SceneInputLead::step() {
    eventProc(); // Обработчик событий
    return 0;
}

void kb::SceneInputLead::draw() {
    return;
}

void kb::SceneInputLead::destroy(Scene* scene_next) {
    return;
}
