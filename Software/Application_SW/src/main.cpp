#include <SFML/Graphics.hpp>

int main( int argc, char** argv )
{
	sf::Window window(sf::VideoMode(640, 400), "My First Game", sf::Style::Titlebar|sf::Style::Close);	
	sf::Event ev;

	// Game Loop
	while(window.isOpen()){
		//Event Loop
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			
			case sf::Event::KeyPressed:
				if(ev.key.code == sf::Keyboard::Escape) window.close();
				break;
			}
		}
		// Update

		//Render
		window.display();
	}

	return 0;
}



/*
Old Stuff
sf::RenderWindow appWindow( sf::VideoMode( 800, 600, 32 ), "App" );
	sf::Event appEvent;
	
	while ( appWindow.isOpen() )
	{
		while ( appWindow.pollEvent( appEvent ) )
		{
			if ( appEvent.type == sf::Event::Closed )
				appWindow.close();
		}

		appWindow.clear();
		appWindow.display();
	}

*/