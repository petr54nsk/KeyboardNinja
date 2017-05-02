// Игровая сцена ===============================================================
#define GAME_NUM_WORDS 15
#define GAME_NUM_SENT 15

namespace kb {

class SceneGame : public Scene {
private:
    void eventProc();
    bool checkPressedKey(sf::Keyboard::Key key, wchar_t ch);

    class Button {
    private:
        Button *id_next;
        int x,y,dx,dy;
        bool active;
        wchar_t letter;
        sf::Keyboard::Key letter_key;
    public:
        Button(wchar_t, Button*);
        ~Button();
        int keyCheck(sf::Keyboard::Key);
        int step();
    };

    sf::Sprite *image_index;
    sf::Texture* image_texture;

    FILE *words_file;
    std::wstring words[GAME_NUM_SENT][GAME_NUM_WORDS];
    int word_num[GAME_NUM_WORDS];
    int lett_num[GAME_NUM_SENT];
    int current_sent;
    int sent_num;
    int current_pos_text;
    int sent_array[GAME_NUM_SENT];

    sf::Font* font;
    sf::Text* text;
    sf::Text* input_text;

    sf::Keyboard::Key key_pressed;
    sf::Keyboard::Key key_released;

public:
    bool init(sf::RenderWindow* app);
    char step();
    void draw();
    void destroy(Scene*);
};

};
