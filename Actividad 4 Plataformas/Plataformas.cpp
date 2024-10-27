#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
Texture texture;
int main() {
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Actividad 4 - Plataformas");
	texture.loadFromFile("plataforma.jpg");
	sf::RectangleShape plataformas[8];
	plataformas[0].setSize(sf::Vector2f(40, 180));
	plataformas[1].setSize(sf::Vector2f(40, 200));
	plataformas[2].setSize(sf::Vector2f(40, 220));
	plataformas[3].setSize(sf::Vector2f(40, 240));
	plataformas[4].setSize(sf::Vector2f(40, 260));
	plataformas[5].setSize(sf::Vector2f(40, 280));
	plataformas[6].setSize(sf::Vector2f(40, 300));
	plataformas[7].setSize(sf::Vector2f(280, 40));
	for (int i = 0; i < 7; i++) {
		plataformas[i].setTexture(&texture);
		plataformas[i].setPosition(i * 50, 600 - plataformas[i].getSize().y); // Coloca las plataformas en la parte inferior de la ventana
	}
	float AlturaPenultimaPlat = plataformas[6].getSize().y; //Almacenar altura de penúltima plataforma
	float posicionPenultimaPlat = 600 - AlturaPenultimaPlat; //Almacenar posicion de penúltima plataforma
	plataformas[7].setTexture(&texture); // Asignar la textura
	plataformas[7].setPosition(350 + plataformas[6].getSize().x, posicionPenultimaPlat - plataformas[7].getSize().y / 2); // Ajustar última plataforma a la derecha y flotando de la penúltima
	// Loop principal
	while (App.isOpen())
	{
		App.clear(sf::Color::White);
		for (int i = 0;i < 8; i++) {
			App.draw(plataformas[i]);
		}
		App.display();
	}
	return 0;
}
