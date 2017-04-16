#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640

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
};

// SCENE0 ======================================================================
class Scene0 : public Scene {
private:
    sf::Font* font;
    sf::Text* text;

public:
    bool init(sf::RenderWindow* app, Scene *id);
    char step();
    void draw();
};

// SCENE1 ======================================================================
class Scene1 : public Scene {
private:
    sf::Sprite *image_index;
    sf::Texture* image_texture;

public:
    bool init(sf::RenderWindow* app, Scene *id);
    char step();
    void draw();
};

};
