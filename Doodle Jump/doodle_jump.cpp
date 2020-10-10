#include <SFML\Graphics.hpp>
#include <random>
#include <ctime>
#include<time.h>
#include<iostream>

//add delay() here

int main()
{
    printf("\n ::::::::::::::::::::::::::::::::::WELCOME to the DOODLE JUMP game::::::::::::::::::::::::::::::::::\n");
    delay(3);
    printf("\n The doodle is trapped somewhere to the south of the EARTH and is trying to jumping the platforms to reach the Earth\n");
    delay(5);
    printf("\n::::::::::Help Doodle escape this deadly trap and escort him to EARTH by making correct moves::::::::\n");
    delay(4);
    printf("\n::::::::::::::::::::::::::::::::::::::::::::INSTRUCTIONS::::::::::::::::::::::::::::::::::::::::::::\n");
    delay(1.5);
    printf("\n ****************************Use arrow keys to move left or right***********************************\n");
    delay(2);
    printf("\n *****************The DOODLE jumps automatically after hitting the green platform*******************\n");
    delay(3);
    printf("\n **************Keep on jumping over the platforms to gain heights and score points******************\n");
    delay(5);
    printf("\n ***WARNING : Don't miss a platform else you fall into the infinite space and get trapped there.****\n");
    delay(5);
    printf("\n*************************************GET READY.......LET'S BEGIN*************************************");
    delay(2);
    printf("\n");

	sf::RenderWindow window(sf::VideoMode(500, 700), "Doodle Jump", sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Texture backgroundTexture;
	sf::Texture playerTexture;
	sf::Texture platformTexture;
	backgroundTexture.loadFromFile("images/background.jpg");
	playerTexture.loadFromFile("images/doodle.png");
	platformTexture.loadFromFile("images/platform.png");
	sf::Sprite background(backgroundTexture);
	sf::Sprite player(playerTexture);
	sf::Sprite platform(platformTexture);

	sf::RectangleShape gameoverBackground(sf::Vector2f(500, 700));
	gameoverBackground.setFillColor(sf::Color::Blue);

	sf::Font font;
	font.loadFromFile("font/EvilEmpire.ttf");
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::Yellow);
	sf::Text gameoverText;
	gameoverText.setFont(font);
	gameoverText.setString(" Game Over......... '_'");
	gameoverText.setCharacterSize(50);
	gameoverText.setFillColor(sf::Color::Red);

	// initialize platforms
	sf::Vector2u platformPosition[10];
	std::uniform_int_distribution<unsigned> x(0, 500 - platformTexture.getSize().x);
	std::uniform_int_distribution<unsigned> y(100, 700);
	std::default_random_engine e(time(0));
	for (size_t i = 0; i < 10; ++i)
	{
		platformPosition[i].x = x(e);
		platformPosition[i].y = y(e);
	}

	// player's position and down velocity
	int playerX = 250;
	int playerY = 151;
	float dy = 0;
	int height = 150;
	int score = 0;

	// player's bounding box. It should modify according to the image size
	const int PLAYER_LEFT_BOUNDING_BOX = 20;
	const int PLAYER_RIGHT_BOUNDING_BOX = 60;
	const int PLAYER_BOTTOM_BOUNDING_BOX = 70;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			playerX -= 4;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			playerX += 4;
		if (playerX > 500)
			playerX = 0;
		if (playerX < -40)
			playerX = window.getSize().x - playerTexture.getSize().x;
		if (playerY == height && dy < (-1.62))
		{
			score += 1;
			scoreText.setString("Score = " + std::to_string(score));
		}

		// player's jump mechanism
		dy += 0.2;
		playerY += dy;

		if (playerY < height)
			for (size_t i = 0; i < 10; ++i)
			{
				playerY = height;
				platformPosition[i].y -= dy;  // vertical translation
				if (platformPosition[i].y > 700) // set new platform on the top
				{
					platformPosition[i].y = 0;
					platformPosition[i].x = x(e);
				}

			}
		// detect jump on the platform
		for (size_t i = 0; i < 10; ++i)
		{
			if ((playerX + PLAYER_RIGHT_BOUNDING_BOX > platformPosition[i].x) && (playerX + PLAYER_LEFT_BOUNDING_BOX < platformPosition[i].x + platformTexture.getSize().x)        // player's horizontal range can touch the platform
				&& (playerY + PLAYER_BOTTOM_BOUNDING_BOX > platformPosition[i].y) && (playerY + PLAYER_BOTTOM_BOUNDING_BOX < platformPosition[i].y + platformTexture.getSize().y)  // player's vertical   range can touch the platform
				&& (dy > 0)) // player is falling
			{
				dy = -10;
			}

		}
		player.setPosition(playerX, playerY);

		window.draw(background);
		window.draw(player);

		// set and draw platforms
		for (size_t i = 0; i < 10; ++i)
		{
			platform.setPosition(platformPosition[i].x, platformPosition[i].y);
			window.draw(platform);
		}

		// game over
		if (playerY > 700)
		{
			gameoverText.setPosition(30, 200);
			scoreText.setPosition(150, 400);
			goto gameover;
		}
		window.draw(scoreText);
		window.display();
	}

	// Game Over
  
  //add Game Over: here
	gameover:
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.draw(gameoverBackground);
		window.draw(gameoverText);
		window.draw(scoreText);
		window.display();
		
	}
  
    return 0;
}
