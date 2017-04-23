// Игровая сцена ===============================================================
namespace kb {

class SceneGame : public Scene {
private:
    sf::Sprite *image_index;
    sf::Texture* image_texture;
    FILE *words_file;
    char words[10][10];

public:
    bool init(sf::RenderWindow* app);
    char step();
    void draw();
    void destroy(Scene*);
};

};
