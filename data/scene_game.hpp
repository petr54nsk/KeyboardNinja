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

        Button(wchar_t, Button*, sf::Keyboard::Key, int, int);
        ~Button();
    };

    class Rect {
    private:
        sf::RectangleShape shape;
        sf::Vector2f position;
        sf::Vector2f size;
        int r,g,b;
        int state;
        int alpha;
    public:
        Rect();
        int step(int, int);
        int draw(sf::RenderWindow *);
        ~Rect();
    };

    class Numb {
    private:
        Numb *id_next;
        sf::Text text;
        std::wstring str;
        sf::Vector2f position;
        int dy;
        int alpha;
        int dalpha;
    public:
        Numb(int, int, int, bool, Numb*, sf::Font*);
        int step();
        int draw(sf::RenderWindow *);
        ~Numb();
    };

    bool fillStrings();
    void eventProc();
    bool checkPressedKey(sf::Keyboard::Key key, wchar_t ch);
    int drawButtons();
    int stepButtons();
    int clearButtons();
    int createButtons();
    int procNumbs();
    int addIntToStr(std::wstring*, int);

    int distance;
    int ddistance;
    int distance_min;

    int speed;
    int dspeed;
    int speed_max;

    int score;
    int sents_max;
    int level;

    Button* head_button_stack;
    Rect* rectangleShape;
    Numb* head_numb_stack;

    sf::Sprite *image_index;
    sf::Texture* image_texture;
    sf::Sprite image_button;
    sf::Texture button_texture;
    sf::Sprite background_index;
    sf::Texture background_texture;

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
