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
    int check = 0;
    int color = 0;

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
