#include "scene_game/button.cpp"
#include "scene_game/rect.cpp"
#include "scene_game/numb.cpp"

// INIT ========================================================================
bool kb::SceneGame::init(sf::RenderWindow* app) {
    this->app = app;
    srand(time(0));

    key_pressed = sf::Keyboard::Unknown;
    distance = 230;
    distance_min = 10;

    speed = 2;
    speed_max = 25;

    score = 0;
    sents_max = 4;
    level = 0;

    is_failed_word = is_failed_sent = 0;

    rectangleShape = new Rect();

    font = new sf::Font;
    font->loadFromFile("graphics/Rex_Bold.otf");

    head_numb_stack = new Numb(200, 400, 25, 0, NULL);

    text_button.setPosition(200,300);
    text_button.setFont(*font);
    text_button.setCharacterSize(100);
    text_button.setColor(sf::Color(45, 62, 80));

    text = new sf::Text(L"String",*font,26);
    text->setPosition(405, 90);
    text->setColor(sf::Color(53, 152, 219));

    input_text = new sf::Text(L"",*font,26);
    input_text->setPosition(405, 90);
    input_text->setColor(sf::Color(236, 240, 241));
    input_text->setStyle(sf::Text::Underlined);

    image_texture = new sf::Texture;
    image_texture->loadFromFile("graphics/image.png");
    image_index = new sf::Sprite(*image_texture);
    image_index->setTexture(*image_texture);
    image_index->setPosition(5, -15);

    button_texture.loadFromFile("graphics/gamescene/block.png");
    image_button.setTexture(button_texture);
    image_button.setPosition(0,300);

    background_texture.loadFromFile("graphics/gamescene/background.png");
    background_index.setTexture(background_texture);
    background_index.setPosition(1100,0);

    words_file = fopen("resources/words.txt", "rt+");

    fillStrings();

    for(int i=0; i < GAME_NUM_SENT; i++) {
        if (i<=sent_num) sent_array[i] = 1; else sent_array[i] = 0;
    }
    sent_array[0] = 0;
    fclose (words_file);
    if (sent_num < sents_max) sents_max = sent_num;
    if (!(ddistance = (distance-distance_min)/(sent_num-1))) ddistance = 1;
    if (!(dspeed = (speed_max-speed)/(sent_num-1))) dspeed = 1;

    createButtons();

    return 0;
}

void kb::SceneGame::eventProc() {
    sf::Event event;
    key_released = sf::Keyboard::Unknown;
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

        if (output_str[current_sent][current_pos_text+1] == ' ') {
            if (!is_failed_word) score += 50;
            is_failed_word = 0;
        }

        current_pos_text += 1;
        score += 25;
        key_released = sf::Keyboard::Unknown;

        if (current_pos_text > lett_num[current_sent] - 2) {

            if (!is_failed_sent) score += 100;
            is_failed_sent = 0;

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

            if (++level > sents_max) allow=2;
            if ((distance-=ddistance)<distance_min) distance = distance_min;
            if ((speed+=dspeed)>speed_max) speed = speed_max;
            createButtons();
        }
    } else {
        if (key_released != sf::Keyboard::Unknown &&
            key_released != sf::Keyboard::LShift &&
            key_released != sf::Keyboard::RShift) {
            score -= 15;
            is_failed_word = 1;
            is_failed_sent = 1;
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
    if (allow==2 || is_game_over || score<0) {
        destroy(scene_main_menu);
        return 1;
    }

    return 0;
}

// DRAW ========================================================================
void kb::SceneGame::draw() {
    rectangleShape->draw(app);
    drawButtons();
    app->draw(background_index);

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(790, 150)); //Width and height
    rect.setPosition(385, 20); //Position
    rect.setFillColor(sf::Color(45, 62, 80)); //Color
    app->draw(rect);

    rect.setSize(sf::Vector2f(355 , 150)); //Width and height 356
    rect.setPosition(20, 20); //Position
    rect.setFillColor(sf::Color(41, 127, 184));
    app->draw(rect);

    rect.setSize(sf::Vector2f(1160 , 50)); //Width and height 356
    rect.setPosition(20, 570); //Position
    rect.setFillColor(sf::Color(45, 62, 80));
    app->draw(rect);

    //app->draw(*image_index);
    app->draw(*text);
    app->draw(*input_text);


    sf::Text score_text(L"Score: ",*font,26);
    score_text.setPosition(35,66);
    score_text.setColor(sf::Color(45, 62, 80));
    std::wstring score_str = L"Счет: ";
    addIntToStr(&score_str,score);

    score_str += L"\nУровень: ";
    addIntToStr(&score_str,level);
    score_str += L" из ";
    addIntToStr(&score_str,sents_max);
    score_text.setString(score_str);
    app->draw(score_text);

    procNumbs();
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
        p = new Button(output_str[current_sent][current_button_num++],
                       head_button_stack, key_pressed, i*distance, speed);
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
        int is_release_key = checkPressedKey(key_released, p->getChar());
        if (key_released != sf::Keyboard::Unknown &&
            key_released != sf::Keyboard::LShift &&
            key_released != sf::Keyboard::RShift && !is_release_key) {
            is_release_key = 2;
        }
        move_flag += p->process(key_pressed, is_key_true, is_release_key, prev_id, head_numb_stack);
        passive_objects_count += p->step(score, head_numb_stack);
    }

    if (move_flag) {
        p = head_button_stack;
        while (p = p->getNext()) {p->move(-move_flag,0);}
    }

    if (passive_objects_count > max_allowed_objects) is_game_loose = 1;
    rectangleShape->step(passive_objects_count,speed);

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

int kb::SceneGame::procNumbs() {
    Numb *p = head_numb_stack->getNext();
    while(p) {
        Numb *buffer = p->getNext();
        if (p->step()) p->draw(app);
        p = buffer;
    }
    return 0;
}

int kb::SceneGame::addIntToStr(std::wstring *str, int numb) {

    if (numb) {
        int count = 0;
        char ch[15];
        for (int i = numb; i>0; i/=10) {
            ch[count++] = ((wchar_t)(i%10)+'0');
        }
        for (int i=count-1; i>=0; i--) {
            *str += ch[i];
        }
    } else *str+='0';

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
