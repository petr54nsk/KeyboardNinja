namespace kb {

class SceneTableLead : public Scene  {
private:

public:
    bool init(sf::RenderWindow* app);
    char step();
    void draw();
    void destroy(Scene*);
};

};
