class SceneInputLead : public Scene  {
private:
	static int const NUMBERS = 30;
	sf::RenderWindow *window;
	int new_score;
	std::string new_name;
	results *readFileResult();
	bool addNewResult(results res[], results new_res);
	void writeFileResult(results res[]);
	sf::Texture background_texture;
	sf::Texture window_input_texture;
	sf::Texture field_input_texture;
	sf::Texture button_texture;
	sf::Sprite background;
	sf::Sprite window_input;
	sf::Sprite field_input;
	sf::Sprite button[2];
	sf::Color window_input_color;
	sf::Event event;
	sf::Text text1;
	sf::Text text2;
	sf::Font font;
	sf::Font font_button;
	sf::Text test;
public:
	void shipScore(int score_buff);
    bool init(sf::RenderWindow &app);
    char step();
    void draw();
};

/*button_input_table.png
field_input.png
background_input_table.png
input_window.png
radiance.woff
font.TTF*/