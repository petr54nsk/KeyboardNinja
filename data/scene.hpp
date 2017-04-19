#define SCREEN_HEIGHT 640
#define SCREEN_WIDTH 1200

namespace kb {

// SCENE (BASE) ================================================================
class Scene {
private:

protected:
    sf::RenderWindow* app;
    Scene* id_scene;

public:
    virtual bool init(sf::RenderWindow* app, Scene *id);
    virtual char step();
    virtual void draw();
    virtual char destroy();
};

// Сцена главного меню =========================================================
class SceneMainMenu : public Scene {
private:
    sf::Font* font;
    sf::Text* text;
    // сюда пихать переменные для сцены меню

public:
    bool init(sf::RenderWindow* app, Scene *id);
    char step();
    void draw();
};

// Игровая сцена ===============================================================
class SceneGame : public Scene {
private:
    sf::Sprite *image_index;
    sf::Texture* image_texture;

public:
    bool init(sf::RenderWindow* app, Scene *id);
    char step();
    void draw();
};

};
