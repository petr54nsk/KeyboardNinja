// Сцена главного меню =========================================================
class SceneMainMenu : public Scene {
private:
    sf::Font* font;
    sf::Text* text;

    sf::Sprite *image_index;
    sf::Texture* image_texture;
    // сюда пихать переменные для сцены меню
    // int new_var;
    // int new_function(int, int);

public:
    bool init(sf::RenderWindow* app);
    char step();
    void draw();
    void destroy(Scene*);
};
