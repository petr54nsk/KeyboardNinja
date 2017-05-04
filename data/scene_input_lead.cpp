bool SceneInputLead::init(sf::RenderWindow* app) {
    return 0;
}

char SceneInputLead::step() {
    eventProc(); // Обработчик событий
    return 0;
}

void SceneInputLead::draw() {
    return;
}

void SceneInputLead::destroy(Scene* scene_next) {
    return;
}
