// Сцена главного меню =========================================================
class SceneMainMenu : public Scene {
private:
    sf::Font* font;
    sf::Text* text;
	sf::Text* new_game;
	sf::Text* score;
	sf::Text* exit1;
    sf::Sprite *image_index;
    sf::Texture *image_texture;
    int check1;
    int color1;
    int check2;
    int color2;
    int check3;
    int color3;
    int check4;
    int check5;
    int check6;

    // сюда пихать переменные для сцены меню
    // int new_var;
    // int new_function(int, int);

public:
    bool init(sf::RenderWindow* app);
    void draw();
    void destroy(Scene*);
    void eventProc();
    char step();
};
