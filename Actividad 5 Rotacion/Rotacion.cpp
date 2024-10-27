#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
Texture texture;
Sprite sprite;
int main() {
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Actividad 5 - Rotacion");
	texture.loadFromFile("cuad_red.png");
	sprite.setTexture(texture);
	//Investigu� que el siguiente metodo comentado tambi�n resuelve la actividad, y consiste en que getGlobalBounds obtiene las dimensiones del sprite despu�s
	// de aplicar escalados o transformaciones. Tanto este como el m�todo usado son necesarios para fijar el origen del sprite al centro del mismo y as� poder rotar
	// desde un punto m�s conveniente.
	//sf::FloatRect bounds = sprite.getGlobalBounds();
	//sprite.setOrigin(bounds.width / 2, bounds.height / 2);
	Vector2u size = sprite.getTexture()->getSize();
	sprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	sprite.setPosition(400, 300);
	sprite.rotate(60.f);
	// Loop principal
	while (App.isOpen())
	{
		App.clear();
		App.draw(sprite);
		App.display();
	}
	return 0;

}
