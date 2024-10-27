#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
Texture texture;
Sprite sprite[4];
int main() {
	texture.loadFromFile("rcircle.png");
	for (int i = 0; i < 4; i++) {
		sprite[i].setTexture(texture);
		sprite[i].setScale(0.1, 0.1);
	}
	//Para posicionar en las esquinas teniendo en cuenta el tamaño en pixeles de la imagen, en los valores de setPosition se hace un cálculo: A los márgenes se le resta el resultado de multiplicar el tamaño ya sea de alto o ancho de la imagen por la escala de la misma.
	//Por ejemplo, si nuestra imagen es 128x128 y queremos posicionarlo en la margen superior derecha, restariamos 128 al 800 (eje x)
	//Esto funciona muy bien para no calcular manualmente cada vez que usamos setScale.
	sprite[0].setPosition(0, 0);
	sprite[1].setPosition(800 - (sprite[1].getTexture()->getSize().x * sprite[1].getScale().x), 0);
	sprite[2].setPosition(800 - (sprite[2].getTexture()->getSize().x * sprite[2].getScale().x), 600 - (sprite[2].getTexture()->getSize().y * sprite[2].getScale().y));
	sprite[3].setPosition(0, 600 - (sprite[3].getTexture()->getSize().y * sprite[3].getScale().y));
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Actividad 1 - 4 dots");
	// Loop principal
	while (App.isOpen())
	{
		App.clear();
		for (int i = 0; i < 4; i++) {
			App.draw(sprite[i]);
		}
		App.display();
	}
	return 0;
}
