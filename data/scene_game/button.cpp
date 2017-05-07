kb::SceneGame::Button::Button(wchar_t let, Button* next, sf::Keyboard::Key key, int x_moved, int speed) {
    id_next = next;
    letter = let;
    letter_key = key;

    dx = -speed;
    dy = 0;
    position.x = SCREEN_WIDTH + x_moved;
    position.y = 200;

    color = sf::Color(255,255,255);

    active = 0;
}

kb::SceneGame::Button* kb::SceneGame::Button::getNext() {
    return id_next;
}

int kb::SceneGame::Button::setNext(kb::SceneGame::Button* next) {
    id_next = next;
    return 0;
}

sf::Color kb::SceneGame::Button::getColor() {
    return color;
}

wchar_t kb::SceneGame::Button::getChar() {
    return letter;
}

sf::Vector2f kb::SceneGame::Button::getPosition() {
    return position;
}

kb::SceneGame::Button::~Button() {

}

int kb::SceneGame::Button::keyCheck(sf::Keyboard::Key) {
    return 0;
}

int kb::SceneGame::Button::setActive(bool value) {
    active = value;
    return 0;
}


int kb::SceneGame::Button::process(sf::Keyboard::Key key, bool is_key_true, bool is_release_key, Button* prev) {
    int moved = 0;
    if (getNext() == NULL) active = 1;

    if (active) {
        if (position.x > SCREEN_WIDTH) {
            moved = position.x - SCREEN_WIDTH;
            position.x = SCREEN_WIDTH;
        }

        if (is_key_true) {
            color = sf::Color(252,221,79);
        } else
        color = sf::Color(232,76,61);

        if (is_release_key) {
            prev->setNext(getNext());
            delete this;
            return 0;
        }

        if (key == sf::Keyboard::Unknown)
        color = sf::Color(255,255,255);
    }

    return moved;
}

int kb::SceneGame::Button::step() {
    Button* next_object = getNext();

    bool is_not_move = 0;
    bool place_free = 1;
    if (next_object) {
        sf::Vector2f next_position = next_object->getPosition();
        if (position.x + dx <= next_position.x + 117) place_free = 0;
    }
    if ((position.x + dx > 20) && (place_free))
    position.x += dx; else is_not_move = 1;

    position.y -= dy;
    return is_not_move;
}

int kb::SceneGame::Button::move(int _x, int _y) {
    if (!active) position.x += _x;
    position.y += _y;
    return 0;
}
