#include <iostream>
#include <fstream>
#include <cstring>
#include <SFML/Graphics.hpp>

int const WINDOW_W = 1200;
int const WINDOW_H = 600;
int const NUMBERS = 30;

struct results {
	std::string name;
	int score;
};

struct Rect {
	int x;
	int y;
};

std::istream  & operator>>(std::istream & is, results & res) {
	is >> res.name >> res.score;
	return is;
}

std::ostream & operator<<(std::ostream & out, results & res) {
	out << res.name << " " << res.score << std::endl;
	return out;
}

void createFileResult();

bool addNewResult(results res[], results newres);

void writeFileResult(results res[]);

results *readFileResult();

bool tablWindow();

int main(int argc, char *argv[]) {
	if(argc - 1) {
		if(!strcmp(argv[1], "new")) createFileResult();
		if(!strcmp(argv[1], "start")) tablWindow();
	}
}

bool addNewResult(results res[], results new_res) {
	int buff;
	for(int i = 0; i < NUMBERS; i++) {
		if(res[i].score < new_res.score) {
			for(int j = NUMBERS - 1; j > i; j--) {
				res[j] = res[j-1];
			}
			res[i] = new_res;
			return 1;
		}
	}
	return 0;
}

void createFileResult() {
	std::ofstream fout("results.txt");
	results null_res;
	null_res.name = "name";
	null_res.score = 0;
	for(int i = 0; i < NUMBERS; i++) {
		fout << null_res;
	}
	fout.close();
}

results *readFileResult() {
	results *res = new results[NUMBERS];
	std::ifstream fin("results.txt");
	for(int i = 0; i < NUMBERS; i++) {
		fin >> res[i];
	}
	fin.close();
	return res;
}

void writeFileResult(results res[]) {
	std::ofstream fout("results.txt");
	for(int i = 0; i < NUMBERS; i++) {
		fout << res[i];
	}
	fout.close();
}

bool tablWindow() {
	sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "game");
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
	background_top_texture.loadFromFile("background_top.png");
	background_top_sprite.setTexture(background_top_texture);
	if(NUMBERS <= 8) background_top_sprite.setTextureRect(sf::IntRect(0, 0, 1200, 300 + ((NUMBERS - 2) / 2) * 100));
	Rect background_top_rect;
	background_top_rect.x = 0;
	background_top_rect.y = 0;
	if(NUMBERS > 8) {
		background_middle_texture.loadFromFile("background_middle.png");
		background_middle_texture.setRepeated(true);
		background_middle_sprite.setTexture(background_middle_texture);
		background_middle_sprite.setTextureRect(sf::IntRect(0, 0, 1200, ((NUMBERS - 8) / 2) * 100));
	}
	Rect background_middle_rect;
	background_middle_rect.x = 0;
	background_middle_rect.y = 600;
	background_bottom_texture.loadFromFile("background_bottom.png");
	background_bottom_sprite.setTexture(background_bottom_texture);
	Rect background_bottom_rect;
	background_bottom_rect.x = 0;
	background_bottom_rect.y = 600 + (((NUMBERS - 8) / 2) * 100);
	tablhead_texture.loadFromFile("tablhead.png");
	tablhead_sprite.setTexture(tablhead_texture);
	Rect tablhead_rect;
	tablhead_rect.x = 300;
	tablhead_rect.y = 200;
	tabl_texture.loadFromFile("tabl.png");
	tabl_texture.setRepeated(true);
	tabl_sprite.setTexture(tabl_texture);
	tabl_sprite.setTextureRect(sf::IntRect(0, 0, 600, ((NUMBERS / 2) - 1) * 100));
	Rect tabl_rect;
	tabl_rect.x = 300;
	tabl_rect.y = 200 + 50;
	tablnohead_texture.loadFromFile("tablnohead2.png");
	tablnohead_sprite.setTexture(tablnohead_texture);
	Rect tablnohead_rect;
	tablnohead_rect.x = 300;
	tablnohead_rect.y = 250 + (((NUMBERS / 2) - 1) * 100);
	sf::Event event;
	while(window.isOpen()) {
		window.clear();
		window.pollEvent(event);
		background_top_sprite.setPosition(sf::Vector2f(background_top_rect.x, background_top_rect.y));
		if(NUMBERS > 8) background_middle_sprite.setPosition(sf::Vector2f(background_middle_rect.x, background_middle_rect.y));
		background_bottom_sprite.setPosition(sf::Vector2f(background_bottom_rect.x, background_bottom_rect.y));
		tablhead_sprite.setPosition(sf::Vector2f(tablhead_rect.x, tablhead_rect.y));
		tabl_sprite.setPosition(sf::Vector2f(tabl_rect.x, tabl_rect.y));
		tablnohead_sprite.setPosition(sf::Vector2f(tablnohead_rect.x, tablnohead_rect.y));
		if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window.close();
		if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S && background_bottom_rect.y > 600 - 300) {
			background_middle_rect.y -= 10;
			background_top_rect.y -= 10;
			background_bottom_rect.y -= 10;
			tablhead_rect.y -= 10;
			tabl_rect.y -= 10;
			tablnohead_rect.y -= 10;
		}
		if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W && background_top_rect.y < 0) {
			background_middle_rect.y += 10;
			background_top_rect.y += 10;
			background_bottom_rect.y += 10;
			tablhead_rect.y += 10;
			tabl_rect.y += 10;
			tablnohead_rect.y += 10;
		}
		window.draw(background_top_sprite);
		if(NUMBERS > 8) window.draw(background_middle_sprite);
		window.draw(background_bottom_sprite);
		window.draw(tablhead_sprite);
		window.draw(tabl_sprite);
		window.draw(tablnohead_sprite);
		window.display();
	}
	return 0;
}

