#include "Game.h"
#include <iostream>


Game::Game()
:m_window(sf::VideoMode(1024, 768), "TODO: Game Name")
{
}

void Game::run()
{
	const std::chrono::nanoseconds FRAMETIME(16666667);		// Equal to 16.66ms or 1000/60
	using clock = std::chrono::high_resolution_clock;
	
	auto gameTimeStart  = clock::now();						// Total runtime of the program
	auto frameTimeStart = clock::now();		
	std::chrono::nanoseconds accumulator(0ns);				// Time passed since the last update

	while (m_window.isOpen())
	{
		if (clock::now() - frameTimeStart > std::chrono::milliseconds(1))
		{
			auto deltaTime = clock::now() - frameTimeStart;		// Time passed for last loop
			frameTimeStart = clock::now();						// Reset
			accumulator += deltaTime;							// Add time passed last loop
		}
									

		sf::Event event;
		while (m_window.pollEvent(event))					// Gets all events
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}
		
		while (accumulator >= FRAMETIME)					// Update if enough time has passed
		{
			accumulator -= FRAMETIME;						
			update();
			
		}
		render();										// Render ever loop
	}

	// For checkign what the fps was
	auto timePassed = clock::now() - gameTimeStart;
	auto millisPassed = std::chrono::duration_cast<std::chrono::milliseconds>(timePassed);
	std::cout << "milliseconds passed: " << millisPassed.count() << std::endl;
	std::cout << "frames passed: " << m_frames << std::endl;
	std::cout << "frames per second: "	<< (float) m_frames / ( (float)millisPassed.count() /1000.f);
}

void Game::update()
{
	m_frames++;
}

void Game::render()
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	m_window.clear();
	m_window.draw(shape);
	m_window.display();
}

