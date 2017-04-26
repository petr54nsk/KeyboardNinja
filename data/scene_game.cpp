/*
Сцена игры
*/

// INIT ========================================================================
bool kb::SceneGame::init(sf::RenderWindow* app) {
    this->app = app;

    font = new sf::Font;
    font->loadFromFile("graphics/Rex_Bold.otf");

    text = new sf::Text(L"String",*font,26);
    text->setPosition(200, 90);
    text->setColor(sf::Color(25, 52, 64));

    input_text = new sf::Text(L"",*font,26);
    input_text->setPosition(200, 90);
    input_text->setColor(sf::Color(153, 176, 200));
    input_text->setStyle(sf::Text::Underlined);

    //text->setString(str);

    image_texture = new sf::Texture;
    image_texture->loadFromFile("graphics/image.png");
    image_index = new sf::Sprite(*image_texture);
    image_index->setTexture(*image_texture);
    image_index->setPosition(5, -15);

    words_file = fopen("resources/words.txt", "rt+");

    word_num = 0;
    current_pos_text = -1;
    wchar_t ch;
    words[0]=L"";
    do {
        ch = fgetwc(words_file);
        switch (ch) {
            case L' ': {
                word_num++;
                words[word_num] = L"";
                break;
            }
            /*case L'\n': {
                sent_num++;
                break;
            }*/
            default: {
                words[word_num] += ch;
                break;
            }
        }

        // DEBAG INFO
    } while (!feof(words_file));

    text->setString(words[0]);
    return 0;
}

void kb::SceneGame::eventProc() {
    sf::Event event;
    while (app->pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::Closed: {
                app->close();
                break;
            }
            case sf::Event::KeyPressed: {
                key_pressed = event.key.code;
                std::cout << key_pressed << " ";
                break;
            }
            case sf::Event::KeyReleased: {
                key_released = event.key.code;
                break;
            }
        }
    }

    return;
}

// STEP ========================================================================
char kb::SceneGame::step() {
    key_pressed = key_released = sf::Keyboard::Unknown;
    eventProc(); // Обработчик событий

    std::wstring outputStr = L"";
    for(int i=0; i<=word_num; i++) {
        outputStr += words[i];
        outputStr += L' ';
    }
    text->setString(outputStr);

    if (key_pressed!=sf::Keyboard::Unknown) {
        current_pos_text += 1;
    }

    std::wstring inputStr = L"";
    if (current_pos_text!=-1) {
        for(int i=0; i<=current_pos_text; i++) {
            inputStr += outputStr[i];
            //inputStr += L' ';
        }
    }
    input_text->setString(inputStr);

    // Смена сцены при нажатии
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        destroy(scene_main_menu);
        return 1;
    }

    return 0;
}

// DRAW ========================================================================
void kb::SceneGame::draw() {
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(1200 - 40, 150)); //Width and height
    rect.setPosition(20, 20); //Position
    rect.setFillColor(sf::Color(82, 102, 111)); //Color
    app->draw(rect);
    //rect.setTexture(&image1);

    app->draw(*image_index);
    app->draw(*text);
    app->draw(*input_text);
    return;
}

// DESTROY =====================================================================
void kb::SceneGame::destroy(Scene* next_scene) {
    delete (image_texture);
    delete (image_index);
    fclose (words_file);

    scene = next_scene;
    scene->init(app);
    return;
}
