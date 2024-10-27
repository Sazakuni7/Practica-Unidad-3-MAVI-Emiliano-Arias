#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
Texture textureFondo;
Sprite sprite;
int main() {
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Actividad 3 - Fondo");
	textureFondo.loadFromFile("fondo.jpg");
	sprite.setTexture(textureFondo);
	//Vector2u es un constructor para manipular vectores bidimensionales con enteros *sin signo*
	Vector2u windowSize = App.getSize();
	Vector2u textureSize = textureFondo.getSize();
	float scaleX = (float)windowSize.x / textureSize.x;
	float scaleY = (float)windowSize.y / textureSize.y;
	sprite.setScale(scaleX, scaleY);
	// Loop principal
	while (App.isOpen())
	{
		App.clear();
		App.draw(sprite);
		App.display();
	}
	return 0;
}
