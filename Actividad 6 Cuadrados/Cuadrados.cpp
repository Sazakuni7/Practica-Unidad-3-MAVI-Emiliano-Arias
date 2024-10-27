#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
Texture texture_r, texture_b, texture_y, texture_g;
Sprite sprite_r, sprite_b, sprite_y, sprite_g;
int main() {
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Actividad 6 - Cuadrados");
	texture_r.loadFromFile("cuad_red.png");
	texture_b.loadFromFile("cuad_blue.png");
	texture_y.loadFromFile("cuad_yellow.png");
	texture_g.loadFromFile("cuad_grey.png");

	sprite_r.setTexture(texture_r);
	sprite_b.setTexture(texture_b);
	sprite_y.setTexture(texture_y);
	sprite_g.setTexture(texture_g);

	sprite_r.setScale(400.f / sprite_r.getGlobalBounds().width, 300.f / sprite_r.getGlobalBounds().height);
	sprite_b.setScale(400.f / sprite_b.getGlobalBounds().width, 300.f / sprite_b.getGlobalBounds().height);
	sprite_y.setScale(400.f / sprite_y.getGlobalBounds().width, 300.f / sprite_y.getGlobalBounds().height);
	sprite_g.setScale(400.f / sprite_g.getGlobalBounds().width, 300.f / sprite_g.getGlobalBounds().height);

	sprite_r.setPosition(0, 0);
	sprite_b.setPosition(400, 0);
	sprite_y.setPosition(0, 300);
	sprite_g.setPosition(400, 300);
	// Loop principal
	while (App.isOpen())
	{
		App.clear();
		App.draw(sprite_r);
		App.draw(sprite_b);
		App.draw(sprite_y);
		App.draw(sprite_g);
		App.display();
	}
	return 0;
}
