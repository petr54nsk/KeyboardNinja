// Игровая сцена ===============================================================
namespace kb {

class SceneGame : public Scene {
private:
    void eventProc();

    sf::Sprite *image_index;
    sf::Texture* image_texture;

    FILE *words_file;
    std::wstring words[10];

    sf::Font* font;
    sf::Text* text;
    sf::Text* input_text;

    int word_num;
    int current_pos_text;

    sf::Keyboard::Key key_pressed;
    sf::Keyboard::Key key_released;

public:
    bool init(sf::RenderWindow* app);
    char step();
    void draw();
    void destroy(Scene*);
};

};
