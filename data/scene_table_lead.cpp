bool SceneTableLead::init(sf::RenderWindow &app) {
	window = app;
	background_top_texture.loadFromFile("background_top.png");
	background_top_sprite.setTexture(background_top_texture);
	if(NUMBERS <= 8) background_top_sprite.setTextureRect(sf::IntRect(0, 0, 1200, 300 + ((NUMBERS - 2) / 2) * 100));
	background_top_rect.x = 0;
	background_top_rect.y = 0;
	if(NUMBERS > 8) {
		background_middle_texture.loadFromFile("background_middle.png");
		background_middle_texture.setRepeated(true);
		background_middle_sprite.setTexture(background_middle_texture);
		background_middle_sprite.setTextureRect(sf::IntRect(0, 0, 1200, ((NUMBERS - 8) / 2) * 100));
	}
	background_middle_rect.x = 0;
	background_middle_rect.y = 600;
	background_bottom_texture.loadFromFile("background_bottom.png");
	background_bottom_sprite.setTexture(background_bottom_texture);
	background_bottom_rect.x = 0;
	background_bottom_rect.y = 600 + (((NUMBERS - 8) / 2) * 100);
	tablhead_texture.loadFromFile("tablhead.png");
	tablhead_sprite.setTexture(tablhead_texture);
	tablhead_rect.x = 300;
	tablhead_rect.y = 200;
	tabl_texture.loadFromFile("tabl.png");
	tabl_texture.setRepeated(true);
	tabl_sprite.setTexture(tabl_texture);
	tabl_sprite.setTextureRect(sf::IntRect(0, 0, 600, ((NUMBERS / 2) - 1) * 100));
	tabl_rect.x = 300;
	tabl_rect.y = 200 + 50;
	tablnohead_texture.loadFromFile("tablnohead2.png");
	tablnohead_sprite.setTexture(tablnohead_texture);
	tablnohead_rect.x = 300;
	tablnohead_rect.y = 250 + (((NUMBERS / 2) - 1) * 100);
	results *res = readFileResult();
	sf::Color a4(164, 164, 164);
	sf::Color d0(208, 208, 208);
	sf::Font font;
	std::cout << res[1];
	std::cout << res[2];
	numb[0].setString("Numb");
	name[0].setString("Name");
	score[0].setString("MMR");
	font.loadFromFile("radiance.woff");
	numb[0].setColor(a4);
	name[0].setColor(a4);
	score[0].setColor(a4);
	numb_rect[0].x = 315;
	numb_rect[0].y = 203;
	name_rect[0].x = 405;
	name_rect[0].y = 203;
	score_rect[0].x = 790;
	score_rect[0].y = 203;
	numb[0].setFont(font);
	name[0].setFont(font);
	score[0].setFont(font);
	for(int i = 1; i < NUMBERS + 1; i++) {
		numb[i].setString(convToString(i));
		name[i].setString(res[i - 1].name);
		score[i].setString(convToString(res[i - 1].score));
		numb[i].setColor(a4);
		name[i].setColor(d0);
		score[i].setColor(a4);
		numb[i].setCharacterSize(30);
		name[i].setCharacterSize(30);
		score[i].setCharacterSize(30);
		numb[i].setFont(font);
		name[i].setFont(font);
		score[i].setFont(font);
		numb_rect[i].x = 345;
		numb_rect[i].y = 203 + (i * 50);
		name_rect[i].x = 405;
		name_rect[i].y = 203 + (i * 50);
		score_rect[i].x = 800;
		score_rect[i].y = 203 + (i * 50);
	}
	sf::Event event;
    return 0;
}

char SceneTableLead::step() {
 //   eventProc(); // Обработчик событий
    return 0;
}

void SceneTableLead::draw() {
	window.clear();
	window.pollEvent(event);
	for(int i = 0; i < NUMBERS + 1; i++) {
		numb[i].setPosition(sf::Vector2f(numb_rect[i].x, numb_rect[i].y));
		score[i].setPosition(sf::Vector2f(score_rect[i].x, score_rect[i].y));
		name[i].setPosition(sf::Vector2f(name_rect[i].x, name_rect[i].y));
	}
	background_top_sprite.setPosition(sf::Vector2f(background_top_rect.x, background_top_rect.y));
	if(NUMBERS > 8) background_middle_sprite.setPosition(sf::Vector2f(background_middle_rect.x, background_middle_rect.y));
	background_bottom_sprite.setPosition(sf::Vector2f(background_bottom_rect.x, background_bottom_rect.y));
	tablhead_sprite.setPosition(sf::Vector2f(tablhead_rect.x, tablhead_rect.y));
	tabl_sprite.setPosition(sf::Vector2f(tabl_rect.x, tabl_rect.y));
	tablnohead_sprite.setPosition(sf::Vector2f(tablnohead_rect.x, tablnohead_rect.y));
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window.close(); //destroy();
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S && background_bottom_rect.y > 600 - 300) {
		background_middle_rect.y -= 10;
		background_top_rect.y -= 10;
		background_bottom_rect.y -= 10;
		tablhead_rect.y -= 10;
		tabl_rect.y -= 10;
		tablnohead_rect.y -= 10;
		for(int i = 0; i < NUMBERS + 1; i++) {
			numb_rect[i].y -= 10;
			score_rect[i].y -= 10;
			name_rect[i].y -= 10;
		}
	}
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W && background_top_rect.y < 0) {
		background_middle_rect.y += 10;
		background_top_rect.y += 10;
		background_bottom_rect.y += 10;
		tablhead_rect.y += 10;
		tabl_rect.y += 10;
		tablnohead_rect.y += 10;
		for(int i = 0; i < NUMBERS + 1; i++) {
			numb_rect[i].y += 10;
			score_rect[i].y += 10;
			name_rect[i].y += 10;
		}
	}
	window.draw(background_top_sprite);
	if(NUMBERS > 8) window.draw(background_middle_sprite);
	window.draw(background_bottom_sprite);
	window.draw(tablhead_sprite);
	window.draw(tabl_sprite);
	window.draw(tablnohead_sprite);
	for(int i = 0; i < NUMBERS + 1; i++) {
		window.draw(numb[i]);
		window.draw(score[i]);
		window.draw(name[i]);
	}
	window.display();
    return;
}

void SceneTableLead::destroy() {
    return;
}

std::string SceneTableLead::convToString(int number)
{
	std::stringstream ss;
	ss << number;
	return ss.str();
}

bool SceneTableLead::addNewResult(results res[], results new_res) {
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

void SceneTableLead::createFileResult() {
	std::ofstream fout("results.txt");
	results null_res;
	null_res.name = "name";
	null_res.score = 0;
	for(int i = 0; i < NUMBERS; i++) {
		fout << null_res;
	}
	fout.close();
}

results *SceneTableLead::readFileResult() {
	results *res = new results[NUMBERS];
	std::ifstream fin("results.txt");
	for(int i = 0; i < NUMBERS; i++) {
		fin >> res[i];
	}
	fin.close();
	return res;
}

void SceneTableLead::writeFileResult(results res[]) {
	std::ofstream fout("results.txt");
	for(int i = 0; i < NUMBERS; i++) {
		fout << res[i];
	}
	fout.close();
}
