kb::SceneGame::Numb::Numb(int x, int y, int digit, bool sign, Numb *next, sf::Font* font) {
    position.x = x;
    position.y = y;
    alpha = 255;
    dalpha = 5;
    dy = 1;

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

    text.setPosition(position);
    text.setFont(*font);
    text.setCharacterSize(40);
    text.setColor(sf::Color(45, 62, 80));
    text.setString(str);

}

int kb::SceneGame::Numb::step() {
    alpha-=dalpha;
    position.y += dy;

    if (alpha<=0) delete this;
    return 0;
}

int kb::SceneGame::Numb::draw(sf::RenderWindow *app) {
    text.setPosition(position);
    text.setColor(sf::Color(45, 62, 80, alpha));
    app->draw(text);
    return 0;
}

kb::SceneGame::Numb::~Numb() {

}
