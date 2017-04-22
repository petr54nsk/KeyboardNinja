/*
Сцена игры
*/

// INIT ========================================================================
bool kb::SceneGame::init(sf::RenderWindow* app, kb::Scene *id) {
    this->app = app;
    id_scene = id;

    //FILE *words_file;
    //char words[10][10][10];

    image_texture = new sf::Texture;
    image_texture->loadFromFile("graphics/image.png");
    image_index = new sf::Sprite(*image_texture);
    image_index->setTexture(*image_texture);

    words_file = fopen("resources/words.txt", "r");

    int letter_num = 0;
    int word_num = 0;
    int sent_num = 0;
    char ch;
    int go = 1;
    while(!feof(words_file) && go) {
        ch = fgetc(words_file);
        switch (ch) {
            case ' ': {
                word_num++;
                letter_num = 0;
                break;
            }
            case '\n': {
                //letter_num = word_num = 0;
                //sent_num++;
                go = 0;
                break;
            }
            default: {
                //words[sent_num][word_num][letter_num++] = ch;
                words[word_num][letter_num++] = ch;
                break;
            }
        }

        // DEBAG INFO
        printf("sent: %d, word: %d, letter: %d\n", sent_num, word_num, letter_num);
    }

    return 0;
}

// STEP ========================================================================
char kb::SceneGame::step() {

    // Смена сцены при нажатии
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        destroy();
        return 1;
    }

    return 0;
}

// DRAW ========================================================================
void kb::SceneGame::draw() {
    app->draw(*image_index);
    return;
}

// DESTROY =====================================================================
void kb::SceneGame::destroy() {
    /*fclose(words_file);
    printf("%d",scene);
    free(scene);

    scene = new kb::SceneMainMenu;
    scene->init(app,id_scene);*/
    scene = scene0;
    return;
}
