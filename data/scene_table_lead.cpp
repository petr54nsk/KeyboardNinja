bool SceneTableLead::init(sf::RenderWindow* app) {
    return 0;
}

char SceneTableLead::step() {
    eventProc(); // Обработчик событий
    return 0;
}

void SceneTableLead::draw() {
    return;
}

void SceneTableLead::destroy(Scene* scene_next) {
    return;
}
