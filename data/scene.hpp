#include <stdio.h>
#define SCREEN_HEIGHT 640
#define SCREEN_WIDTH 1200

namespace kb {
// SCENE (BASE) ================================================================
class Scene {
private:

protected:
    sf::RenderWindow* app;

public:
    virtual bool init(sf::RenderWindow* app);
    virtual char step();
    virtual void draw();
    virtual void destroy();

};

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
    void destroy();
};

// Игровая сцена ===============================================================
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
    void destroy();
};

};