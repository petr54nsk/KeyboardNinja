bool SceneInputLead::init(sf::RenderWindow & app) {
	window = &app;
	background_texture.loadFromFile("background_input_table.png");
	window_input_texture.loadFromFile("input_window.png");
	field_input_texture.loadFromFile("field_input.png");
	button_texture.loadFromFile("button_input_table.png");
	background.setTexture(background_texture);
	window_input.setTexture(window_input_texture);
	field_input.setTexture(field_input_texture);
	for(int i = 0; i < 2; i++) button[i].setTexture(button_texture);
	background.setPosition(sf::Vector2f(0, 0));
	window_input.setPosition(sf::Vector2f(300, 150));
	field_input.setPosition(sf::Vector2f(620, 300));
	button[0].setPosition(sf::Vector2f(375, 360));
	button[1].setPosition(sf::Vector2f(675, 360));
	window_input_color.r = 235; window_input_color.g = 235; window_input_color.b = 255;
	font.loadFromFile("radiance.woff");
	font_button.loadFromFile("font.TTF");
	text1.setString("Score:");
	text2.setString("Print your name: ");
	text1.setPosition(sf::Vector2f(330, 230));
	text2.setPosition(sf::Vector2f(330, 300));
	text1.setFont(font);
	text2.setFont(font);
	text1.setColor(sf::Color(0, 0, 0));
	text2.setColor(sf::Color(0, 0, 0));
	background.setColor(sf::Color(235, 235, 255));
	test.setString("AAAAAAAAAAA13");
	test.setPosition(sf::Vector2f(625, 300));
	test.setFont(font);
	test.setColor(sf::Color(0, 0, 0));
    return 0;
}

char SceneInputLead::step() {
    eventProc(); // Обработчик событий
    return 0;
}

void SceneInputLead::draw() {
	while(window->pollEvent(event)) {
		if(event.type == sf::Event::Closed) window->close();
		if(event.type == sf::Event::KeyPressed) {
			if(event.key.code == sf::Keyboard::Escape) {
				if(window_input_color.r > 150) window_input_color.r-=15;
				if(window_input_color.g < 250) window_input_color.g+=15;
				if(window_input_color.b > 150) window_input_color.b-=15;
			}
		}
	}
	window_input.setColor(window_input_color);
	window->draw(background);
	window->draw(window_input);
	window->draw(field_input);
	window->draw(text1);
	window->draw(text2);
	window->draw(test);
	for(int i = 0; i < 2; i++) window->draw(button[i]);
    return;
}

results *SceneInputLead::readFileResult() {
	results *res = new results[NUMBERS];
	std::ifstream fin("results.txt");
	for(int i = 0; i < NUMBERS; i++) {
		fin >> res[i];
	}
	fin.close();
	return res;
}

bool SceneInputLead::addNewResult(results res[], results new_res) {
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

void SceneInputLead::writeFileResult(results res[]) {
	std::ofstream fout("results.txt");
	for(int i = 0; i < NUMBERS; i++) {
		fout << res[i];
	}
	fout.close();
}

void SceneInputLead::shipScore(int score_buff) {
	new_score = score_buff;
}

