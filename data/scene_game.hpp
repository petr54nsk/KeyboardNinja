// Игровая сцена ===============================================================
#define GAME_NUM_WORDS 15
#define GAME_NUM_SENT 15

namespace kb {

class SceneGame : public Scene {
private:

    class Button {
    private:
        int dx,dy;
        sf::Vector2f position;
        bool active;
        wchar_t letter;
        sf::Keyboard::Key letter_key;
        sf::Color color;
        Button *id_next;
    public:
        Button* getNext();
        sf::Vector2f getPosition();
        sf::Color getColor();
        wchar_t getChar();

        int setNext(Button*);
        int move(int,int);
        int keyCheck(sf::Keyboard::Key);
        int process(sf::Keyboard::Key, bool, bool, Button*);
        int step();
        int setActive(bool);

        Button(wchar_t, Button*, sf::Keyboard::Key, int);
        ~Button();
    };

    bool fillStrings();
    void eventProc();
    bool checkPressedKey(sf::Keyboard::Key key, wchar_t ch);
    int drawButtons();
    int stepButtons();
    int clearButtons();
    int createButtons();

    Button* head_button_stack;

    sf::Sprite *image_index;
    sf::Texture* image_texture;
    sf::Sprite image_button;
    sf::Texture button_texture;

    FILE *words_file;
    std::wstring output_str[GAME_NUM_SENT];
    int lett_num[GAME_NUM_SENT];
    int current_sent;
    int sent_num;
    int current_pos_text;
    int sent_array[GAME_NUM_SENT];

    sf::Font* font;
    sf::Text* text;
    sf::Text* input_text;
    sf::Text text_button;

    sf::Keyboard::Key key_pressed;
    sf::Keyboard::Key key_released;

public:
    bool init(sf::RenderWindow* app);
    char step();
    void draw();
    void destroy(Scene*);
};

};
