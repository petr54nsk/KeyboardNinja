#include "scene_game/button.cpp"

// INIT ========================================================================
bool kb::SceneGame::init(sf::RenderWindow* app) {
    this->app = app;
    srand(time(0));

    key_pressed = sf::Keyboard::Unknown;

    font = new sf::Font;
    font->loadFromFile("graphics/Rex_Bold.otf");

    text_button.setPosition(200,300);
    text_button.setFont(*font);
    text_button.setCharacterSize(100);
    text_button.setColor(sf::Color(25, 52, 64));

    text = new sf::Text(L"String",*font,26);
    text->setPosition(200, 90);
    text->setColor(sf::Color(25, 52, 64));

    input_text = new sf::Text(L"",*font,26);
    input_text->setPosition(200, 90);
    input_text->setColor(sf::Color(153, 176, 200));
    input_text->setStyle(sf::Text::Underlined);

    image_texture = new sf::Texture;
    image_texture->loadFromFile("graphics/image.png");
    image_index = new sf::Sprite(*image_texture);
    image_index->setTexture(*image_texture);
    image_index->setPosition(5, -15);

    button_texture.loadFromFile("graphics/gamescene/block.png");
    image_button.setTexture(button_texture);
    image_button.setPosition(0,300);

    words_file = fopen("resources/words.txt", "rt+");

    fillStrings();

    for(int i=0; i < GAME_NUM_SENT; i++) {
        if (i<=sent_num) sent_array[i] = 1; else sent_array[i] = 0;
    }
    sent_array[0] = 0;
    fclose (words_file);

    createButtons();

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
                break;
            }
            case sf::Event::KeyReleased: {
                key_pressed = sf::Keyboard::Unknown;
                key_released = event.key.code;
                break;
            }
        }
    }

    return;
}

// STEP ========================================================================
char kb::SceneGame::step() {
    eventProc(); // Обработчик событий

    text->setString(output_str[current_sent]);
    bool is_game_over = stepButtons();

    int allow = 0;
    if (checkPressedKey(key_released, output_str[current_sent][current_pos_text+1])) {
        current_pos_text += 1;
        key_released = sf::Keyboard::Unknown;

        if (current_pos_text > lett_num[current_sent] - 2) {
            sent_array[current_sent] = 0;
            current_pos_text = -1;

            int l_pos, r_pos;
            l_pos = r_pos  = rand()%sent_num;
            while(!allow) {
                if (!l_pos && r_pos==sent_num-1) {
                    allow=2;
                    destroy(scene_main_menu);
                    return 1;
                }
                if (sent_array[l_pos]) {
                    allow=1;
                    current_sent = l_pos;
                    break;
                }
                if (sent_array[r_pos]) {
                    allow=1;
                    current_sent = r_pos;
                    break;
                }

                if (l_pos - 1 >= 0) l_pos--;
                if (r_pos + 1 < sent_num) r_pos++;
            }

            createButtons();
        }
    }

    std::wstring input_str = L"";
    if (current_pos_text!=-1) {
        for(int i=0; i<=current_pos_text; i++) {
            input_str += output_str[current_sent][i];
        }
    }

    input_text->setString(input_str);

    // Смена сцены при нажатии
    if (allow==2) {
        destroy(scene_main_menu);
        return 1;
    }

    if (is_game_over) {
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

    app->draw(*image_index);
    app->draw(*text);
    app->draw(*input_text);

    drawButtons();
    return;
}

// DESTROY =====================================================================
void kb::SceneGame::destroy(Scene* next_scene) {
    scene = next_scene;
    scene->init(app);

    delete scene_game;
    scene_game = new kb::SceneGame();
    return;
}

int kb::SceneGame::createButtons() {
    Button *p;
    int current_button_num = 0;
    key_released = sf::Keyboard::Unknown;

    if (head_button_stack) delete head_button_stack;
    head_button_stack = NULL;

    for(int i=0;i<=lett_num[current_sent];i++) {
        p = new Button(output_str[current_sent][current_button_num++], head_button_stack, key_pressed, i);
        head_button_stack = p;
    }

    return 0;
}

int kb::SceneGame::drawButtons() {
    if (!head_button_stack) return 1;

    Button *p = head_button_stack;
    while (p = p->getNext()) {
        text_button.setString(p->getChar());

        sf::Vector2f pos = p->getPosition();
        image_button.setColor(p->getColor());
        image_button.setPosition(pos);
        pos.x += 24;
        pos.y -= 2;
        text_button.setPosition(pos);

        app->draw(image_button);
        app->draw(text_button);
    }
    return 0;
}

int kb::SceneGame::stepButtons() {
    if (!head_button_stack) return 1;

    int passive_objects_count = 0;
    int is_game_loose = 0;
    const int max_allowed_objects = 3;

    int move_flag = 0;
    Button *p = head_button_stack;
    Button *prev_id = p;
    while (p->getNext()) {
        prev_id = p;
        p = p->getNext();
        bool is_key_true = checkPressedKey(key_pressed, p->getChar());
        bool is_release_key = checkPressedKey(key_released, p->getChar());
        move_flag += p->process(key_pressed, is_key_true, is_release_key, prev_id);
        passive_objects_count += p->step();
    }

    if (move_flag) {
        p = head_button_stack;
        while (p = p->getNext()) {p->move(-move_flag,0);}
    }

    if (passive_objects_count > max_allowed_objects) is_game_loose = 1;

    return is_game_loose;
}

int kb::SceneGame::clearButtons() {
    if (!head_button_stack) return 1;

    Button *p = head_button_stack;
    Button *buffer;
    while (p != NULL) {
        buffer = p;
        p = p->getNext();
        delete buffer;
    }

    return 0;
}

bool kb::SceneGame::fillStrings() {
    wchar_t ch;
    sent_num = 0;
    current_sent = 0;
    output_str[sent_num] = L"";
    lett_num[sent_num] = 0;
    current_pos_text = -1;

    do {
        ch = fgetwc(words_file);
        switch (ch) {
            case L'\n': {
                output_str[++sent_num]=L"";
                break;
            }
            case 'z': {
                output_str[++sent_num]=L"";
                break;
            }
            default: {
                output_str[sent_num] += ch;
                lett_num[sent_num]++;
                break;
            }
        }

    } while (!feof(words_file));
    return 0;
}

bool kb::SceneGame::checkPressedKey(sf::Keyboard::Key key, wchar_t ch) {
    switch (ch) {
        case L'д' : {if (key == sf::Keyboard::L) return 1; break;}
        case L'й' : {if (key == sf::Keyboard::Q) return 1; break;}
        case L'ц' : {if (key == sf::Keyboard::W) return 1; break;}
        case L'у' : {if (key == sf::Keyboard::E) return 1; break;}
        case L'к' : {if (key == sf::Keyboard::R) return 1; break;}
        case L'е' : {if (key == sf::Keyboard::T) return 1; break;}
        case L'н' : {if (key == sf::Keyboard::Y) return 1; break;}
        case L'г' : {if (key == sf::Keyboard::U) return 1; break;}
        case L'ш' : {if (key == sf::Keyboard::I) return 1; break;}
        case L'щ' : {if (key == sf::Keyboard::O) return 1; break;}
        case L'з' : {if (key == sf::Keyboard::P) return 1; break;}

        case L'х' : {if (key == sf::Keyboard::LBracket) return 1; break;}
        case L'ъ' : {if (key == sf::Keyboard::RBracket) return 1; break;}

        case L'ф' : {if (key == sf::Keyboard::A) return 1; break;}
        case L'ы' : {if (key == sf::Keyboard::S) return 1; break;}
        case L'в' : {if (key == sf::Keyboard::D) return 1; break;}
        case L'а' : {if (key == sf::Keyboard::F) return 1; break;}
        case L'п' : {if (key == sf::Keyboard::G) return 1; break;}
        case L'р' : {if (key == sf::Keyboard::H) return 1; break;}
        case L'о' : {if (key == sf::Keyboard::J) return 1; break;}
        case L'л' : {if (key == sf::Keyboard::K) return 1; break;}
        case L'ж' : {if (key == sf::Keyboard::SemiColon) return 1; break;}
        case L'э' : {if (key == sf::Keyboard::Quote) return 1; break;}

        case L'я' : {if (key == sf::Keyboard::Z) return 1; break;}
        case L'ч' : {if (key == sf::Keyboard::X) return 1; break;}
        case L'с' : {if (key == sf::Keyboard::C) return 1; break;}
        case L'м' : {if (key == sf::Keyboard::V) return 1; break;}
        case L'и' : {if (key == sf::Keyboard::B) return 1; break;}
        case L'т' : {if (key == sf::Keyboard::N) return 1; break;}
        case L'ь' : {if (key == sf::Keyboard::M) return 1; break;}
        case L'б' : {if (key == sf::Keyboard::Comma) return 1; break;}
        case L'ю' : {if (key == sf::Keyboard::Period) return 1; break;}
        case L'.' : {if (key == sf::Keyboard::Slash) return 1; break;}
        case L' ' : {if (key == sf::Keyboard::Space) return 1; break;}
        case L',' : {
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
            && sf::Keyboard::isKeyPressed(sf::Keyboard::Slash))
                return 1;
            break;
        }
        case L'-' : {if (key == sf::Keyboard::Dash) return 1; break;}

        case L'`' : {if (key == sf::Keyboard::Tilde) return 1; break;}
        case L'"' : {
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
            && sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                return 1;
            break;
        }
    }
    return 0;
}
