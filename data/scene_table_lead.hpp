struct results {
	std::string name;
	int score;
};

std::istream  & operator>>(std::istream & is, results & res) {
	is >> res.name >> res.score;
	return is;
}

std::ostream & operator<<(std::ostream & out, results & res) {
	out << res.name << " " << res.score << std::endl;
	return out;
}


class SceneTableLead: public Scene {
private:
	struct Rect {
		int x;
		int y;
	};

	void createFileResult();

	bool addNewResult(results res[], results newres);

	void writeFileResult(results res[]);

	results *readFileResult();

	std::string convToString(int number);
	static int const NUMBERS = 30;
	sf::RenderWindow *window;
	sf::Texture background_top_texture;
	sf::Texture background_middle_texture;
	sf::Texture background_bottom_texture;
	sf::Texture tablhead_texture;
	sf::Texture tabl_texture;
	sf::Texture tablnohead_texture;
	sf::Sprite background_top_sprite;
	sf::Sprite background_middle_sprite;
	sf::Sprite background_bottom_sprite;
	sf::Sprite tablhead_sprite;
	sf::Sprite tabl_sprite;
	sf::Sprite tablnohead_sprite;
	Rect background_top_rect;
	Rect background_middle_rect;
	Rect background_bottom_rect;
	Rect tablhead_rect;
	Rect tabl_rect;
	Rect tablnohead_rect;
	sf::Text name[NUMBERS + 1];
	sf::Text numb[NUMBERS + 1];
	sf::Text score[NUMBERS + 1];
	Rect name_rect[NUMBERS + 1];
	Rect numb_rect[NUMBERS + 1];
	Rect score_rect[NUMBERS + 1];
	sf::Event event;
	sf::Font font;
	static int const mouse_wheel_speed = 20;
    void destroy();
public:
    bool init(sf::RenderWindow & app);
    char step();
    void draw();
};
