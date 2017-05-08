kb::SceneGame::Numb::Numb(int x, int y, int digit, bool sign, Numb *prev) {
    position.x = x;
    position.y = y;
    alpha = 255;
    dalpha = 5;
    dy = 3;

    id_next = NULL;
    id_prev = NULL;
    if (id_prev = prev) {
        id_next = id_prev->getNext();
        if (id_next) id_next->setPrev(this);
        id_prev->setNext(this);
    }

    if (sign) str=L"+"; else str=L"-";

    if (digit) {
        int count = 0;
        char ch[15];
        for (int i = digit; i>0; i/=10) {
            ch[count++] = ((wchar_t)(i%10)+'0');
        }
        for (int i=count-1; i>=0; i--) {
            str += ch[i];
        }
    } else str+='0';

    font.loadFromFile("graphics/Rex_Bold.otf");
    text.setPosition(position);
    text.setFont(font);
    text.setCharacterSize(40);
    if (sign) {
        r = 53;
        g = 152;
        b = 219;
    }
    else {
        r = 137;
        g = 69;
        b = 71;
    }
    text.setString(str);

}

int kb::SceneGame::Numb::step() {
    alpha-=dalpha;
    position.y += dy;

    if (alpha<=0) {
        id_prev->setNext(id_next);
        if (id_next != NULL) {
            id_next->setPrev(id_prev);
        }
        delete this;
        return 0;
    }
    return 1;
}

int kb::SceneGame::Numb::setNext(Numb* next) {
    id_next = next;
    return 0;
}

int kb::SceneGame::Numb::setPrev(Numb* prev) {
    id_prev = prev;
    return 0;
}

int kb::SceneGame::Numb::draw(sf::RenderWindow *app) {
    text.setPosition(position);
    text.setColor(sf::Color(r, g, b, alpha));
    app->draw(text);
    return 0;
}

kb::SceneGame::Numb* kb::SceneGame::Numb::getNext() {
    return id_next;
}

kb::SceneGame::Numb::~Numb() {

}
