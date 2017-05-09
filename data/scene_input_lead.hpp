class SceneInputLead : public Scene  {
private:

public:
    void shipScore(int score_buff) {};
    bool init(sf::RenderWindow* app);
    char step();
    void draw();
    void destroy(Scene*);
};
