#include <stdio.h>
#define SCREEN_HEIGHT 640
#define SCREEN_WIDTH 1200

// SCENE (BASE) ================================================================
class Scene {
private:

protected:
    sf::RenderWindow* app;
    virtual void eventProc();

public:
    virtual bool init(sf::RenderWindow* app);
    virtual char step();
    virtual void draw();
    virtual void destroy(Scene*);
};