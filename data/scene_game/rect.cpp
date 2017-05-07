kb::SceneGame::Rect::Rect() {
    position.x = 20;
    position.y = 175;
    size.x = 358;
    size.y = 390;
    r = 195;
    g = 66;
    b = 66;
    state = 0;
    alpha = 255;
}

int kb::SceneGame::Rect::step(int loosed, int mspeed) {
    state = loosed;
    int dx = (int)(mspeed*2.5);
    int dalpha = 5;

    switch (state) {
        case 0: {
            if (size.x - dx > 0) size.x -= dx; //else size.x = 0;
            if (alpha - dalpha > 0) alpha -= dalpha; //else alpha = 0;
            break;
        }
        case 1: {
            if (size.x + dx < 120) size.x += dx; else
            if (size.x < 120) size.x = 120;
            if (alpha + dalpha < 100) alpha += dalpha; //else alpha = 100;
            break;
        }
        case 2: {
            if (size.x + dx < 237) size.x += dx; else
            if (size.x < 237) size.x = 237;
            if (alpha + dalpha < 190) alpha += dalpha; //else alpha = 190;
            break;
        }
        case 3: {
            if (size.x + dx < 355) size.x += dx; else
            if (size.x < 355) size.x = 355;
            if (alpha + dalpha < 255) alpha += dalpha; //else alpha = 255;
            break;
        }
    }
    return 0;
}

int kb::SceneGame::Rect::draw(sf::RenderWindow *app) {
    shape.setSize(size); //Width and height
    shape.setPosition(position); //Position
    shape.setFillColor(sf::Color(r, g, b, alpha)); //Color
    app->draw(shape);
    return 0;
}

kb::SceneGame::Rect::~Rect() {

}
