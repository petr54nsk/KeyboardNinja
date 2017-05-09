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
	font_button.loadFromFile("graphics/font.TTF");
	text1.setString(L"Счет:");
	text2.setString(L"Введите ваше имя:");
	text1.setPosition(sf::Vector2f(330, 230));
	text2.setPosition(sf::Vector2f(330, 300));
	text1.setFont(font);
	text2.setFont(font);
	text1.setColor(sf::Color(0, 0, 0));
	text2.setColor(sf::Color(0, 0, 0));
	background.setColor(sf::Color(235, 235, 255));
	input_name.setPosition(sf::Vector2f(625, 300));
	input_name.setFont(font);
	input_name.setColor(sf::Color(0, 0, 0));
	new_score.setPosition(sf::Vector2f(750, 230));
	new_score.setColor(sf::Color(0, 0, 0));
	text_button1.setFont(font_button);
	text_button2.setFont(font_button);
	text_button1.setString(L"Меню");
	text_button2.setString(L"Таблица");
	text_button1.setColor(sf::Color(255, 255, 255));
	text_button2.setColor(sf::Color(255, 255, 255));
	text_button1.setPosition(sf::Vector2f(410, 365));
	text_button2.setPosition(sf::Vector2f(690, 365));
	new_score.setFont(font);
	new_res.score = -200;
	res = readFileResult();
	green = 0;
	red = 0;
	field_input_bl = 1;
	check1 = 1;
    color1 = 0;
    check2 = 0;
    color2 = 0;
    check3 = 0;
    color3 = 0;
    check4 = 0;
    check5 = 0;
    check6 = 0;
    return 0;
}

char SceneInputLead::step() {
    eventProc(); // Обработчик событий
    return 0;
}

void SceneInputLead::draw() {
	colorFun();
	while(window->pollEvent(event)) {
		if(event.type == sf::Event::Closed) window->close();
		if(event.type == sf::Event::KeyPressed) {
//			if(event.key.code == sf::Keyboard::Escape) 
			if(field_input_bl && event.key.code == sf::Keyboard::Return) {
				field_input_bl = 0;
				green = addNewResult(res, new_res);
				if(!green) red = 1;
				writeFileResult(res);
				scene_table_lead->refresh();
			}
			if(field_input_bl && event.key.code == sf::Keyboard::BackSpace && new_res.name.size() > 0) new_res.name.resize(new_res.name.size() - 1);
		}
		if(field_input_bl && event.type == sf::Event::TextEntered && new_res.name.size() < 16) {
			if((event.text.unicode >= 'A' && event.text.unicode <= 'Z') || (event.text.unicode >= 'a' && event.text.unicode <= 'z'))new_res.name += event.text.unicode;
		}
	}
	if(sf::Mouse::getPosition(*window).x > 375 && sf::Mouse::getPosition(*window).x < 525 && sf::Mouse::getPosition(*window).y > 360 && sf::Mouse::getPosition(*window).y < 410) {
        text_button1.setColor(sf::Color(color1, color2, color3));
    } else {
    	text_button1.setColor(sf::Color(255, 255, 255));
    }
    if(sf::Mouse::getPosition(*window).x > 675 && sf::Mouse::getPosition(*window).x < 825 && sf::Mouse::getPosition(*window).y > 360 && sf::Mouse::getPosition(*window).y < 410) {
        text_button2.setColor(sf::Color(color1, color2, color3));
    } else {
    	text_button2.setColor(sf::Color(255, 255, 255));
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    	if(sf::Mouse::getPosition(*window).x > 375 && sf::Mouse::getPosition(*window).x < 525 && sf::Mouse::getPosition(*window).y > 360 && sf::Mouse::getPosition(*window).y < 410) {
        	scene = scene_main_menu;
        }
    	if(sf::Mouse::getPosition(*window).x > 675 && sf::Mouse::getPosition(*window).x < 825 && sf::Mouse::getPosition(*window).y > 360 && sf::Mouse::getPosition(*window).y < 410) {
        	scene = scene_table_lead;
        }
    }
	if(green) {
		if(window_input_color.r != 95) window_input_color.r-=10;
		if(window_input_color.g != 255) window_input_color.g+=10;
		if(window_input_color.b != 95) window_input_color.b-=20;
	}
	if(red) {
		if(window_input_color.r !=255) window_input_color.r+=10;
		if(window_input_color.g !=95) window_input_color.g-=10;
		if(window_input_color.b !=95) window_input_color.b-=20;
	}
	new_score.setString(convToString(new_res.score));
	input_name.setString(new_res.name);
	window_input.setColor(window_input_color);
	window->draw(background);
	window->draw(window_input);
	window->draw(field_input);
	window->draw(text1);
	window->draw(text2);
	window->draw(input_name);
	window->draw(new_score);
	for(int i = 0; i < 2; i++) window->draw(button[i]);
	window->draw(text_button1);
	window->draw(text_button2);
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

int SceneInputLead::addNewResult(results res[], results new_res_funck) {
	for(int i = 0; i < NUMBERS; i++) {
		if(res[i].score < new_res_funck.score) {
			std::cout << res[i] << std::endl << new_res_funck << std::endl;
			for(int j = NUMBERS - 1; j > i; j--) {
				res[j] = res[j-1];
			}
			res[i] = new_res_funck;
			return i+1;
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
	new_res.score = score_buff;
	new_res.name.resize(0);
}

void SceneInputLead::colorFun() {
	if(check1==1 && color1<252 && check4==0) {
        color1+=4;
    }
    if(color1==252 && check4==0) {
        check2=1;
    }
    if(check2==1 && color2<252 && check4==0) {
        color2+=4;
    }
    if(color2==252 && color1>0 && check4==0) {
        check1=0;
        color1-=4;
    }
    if(color2==252 && color1==0 && check4==0) {
        check3=1;
    }
    if(check3==1 && color3<252 && check4==0){
        color3+=4;
    }
    if(color2==252 && color3==252 && check4==0) {
        check2=0;
    }
    if(check2==0 && color3==252 && check4==0) {
        color2-=4;
    }
    if(check3==1 && color2==0 && check4==0) {
        check4=1;
    }
    if(check4==1 && color2==0 && check5==0) {
        color1+=4;
    }
    if(check4==1 && color1==252 && check5==0) {
        check5=1;
    }
    if(check4==1 && check5==1 && color1==252 && check6==0) {
        color3-=4;
    }
    if(check4==1 && check5==1 && color3==0 && check6==0) {
        check6=1;
    }
    if(check4==1 && check5==1 && color3==0 && check6==1) {
        color1-=4;
    }
    if(check4==1 && check5==1 && color1==0 && check6==1) {
        check1 = 1;
        color1 = 0; 
        check2 = 0; 
        color2 = 0; 
        check3 = 0; 
        color3 = 0; 
        check4 = 0; 
        check5 = 0; 
        check6 = 0;
    }
}