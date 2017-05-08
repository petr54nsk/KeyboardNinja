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
    int check1 = 1;
    int color1 = 0;
    int check2 = 0;
    int color2 = 0;
    int check3 = 0;
    int color3 = 0;
    int check4 = 0;
    int check5 = 0;
    int check6 = 0;

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
