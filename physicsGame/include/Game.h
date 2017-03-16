#pragma once
#include <chrono>
#include <SFML/Graphics.hpp>

using namespace std::chrono_literals;

class Game
{
public:
	Game();
	void run();

private:
	void update();
	void render();

	
	sf::RenderWindow m_window;
	int m_frames{0};			//count frames passed during execution
};

