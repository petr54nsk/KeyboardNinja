// Игровая сцена ===============================================================
class SceneGame : public Scene {
private:
    sf::Sprite *image_index;
    sf::Texture* image_texture;
    
    FILE *words_file;
    char words[10][10];

    sf::Font* font;
    sf::Text* text;

public:
    bool init(sf::RenderWindow* app);
    char step();
    void draw();
    void destroy(Scene*);
};
