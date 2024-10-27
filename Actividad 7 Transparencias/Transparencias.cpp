#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
Texture texture_b, texture_r;
Sprite sprite_b, sprite_r[4];
int main() {
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Actividad 7 - Transparencias");
	//CIRCULOS ROJOS
	texture_r.loadFromFile("rcircle.png");
	for (int i = 0; i < 4; i++) {
		sprite_r[i].setTexture(texture_r);
		sprite_r[i].setScale(0.1, 0.1);
	}
	sprite_r[0].setPosition(0, 0);
	sprite_r[1].setPosition(800 - (sprite_r[1].getTexture()->getSize().x * sprite_r[1].getScale().x), 0);
	sprite_r[2].setPosition(800 - (sprite_r[2].getTexture()->getSize().x * sprite_r[2].getScale().x), 600 - (sprite_r[2].getTexture()->getSize().y * sprite_r[2].getScale().y));
	sprite_r[3].setPosition(0, 600 - (sprite_r[3].getTexture()->getSize().y * sprite_r[3].getScale().y));
	//CIRCULO AZUL
	texture_b.loadFromFile("bcircle.png");
	sprite_b.setTexture(texture_b);
	sf::Vector2u windowSize = App.getSize();
	sf::Vector2u textureSize = texture_b.getSize();
	float posX = (windowSize.x - textureSize.x) / 2.0f;
	float posY = (windowSize.y - textureSize.y) / 2.0f;
	sprite_b.setPosition(posX, posY);

	while (App.isOpen())
	{
		App.clear();
		for (int i = 0; i < 4; i++) {
			App.draw(sprite_r[i]);
		}
		App.draw(sprite_b);
		App.display();
	}
	return 0;
}
