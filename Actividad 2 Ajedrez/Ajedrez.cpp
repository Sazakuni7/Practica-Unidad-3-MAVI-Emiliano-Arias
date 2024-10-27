#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
Texture texture_w, texture_b;
Sprite sprite_w, sprite_b;
int main() {
	sf::RenderWindow App(sf::VideoMode(800, 800, 32),
		"Actividad 2 - Ajedrez");
	texture_w.loadFromFile("chessw.png");
	texture_b.loadFromFile("chessb.png");
	sprite_w.setTexture(texture_w);
	sprite_b.setTexture(texture_b);
	//Se re-escalan los sprites para que midan 100x100 cada uno, asi puedan entrar 8 en cada fila y columna
	//En caso de que no se permitiera re-escalar, se necesitaria una ventana de 1024x1024 para que los sprites de 128x128 quepan
	sprite_w.setScale(100.f / sprite_w.getGlobalBounds().width,
		100.f / sprite_w.getGlobalBounds().height);
	sprite_b.setScale(100.f / sprite_b.getGlobalBounds().width,
		100.f / sprite_b.getGlobalBounds().height);
	// Loop principal
	while (App.isOpen())
	{
		App.clear();
		for (int fila = 0; fila < 8; fila++) {
			for (int colum = 0; colum < 8; colum++) {
				if ((fila + colum) % 2 == 0) {
					sprite_w.setPosition(colum * 100, fila * 100);
					App.draw(sprite_w);
				}
				else {
					sprite_b.setPosition(colum * 100, fila * 100);
					App.draw(sprite_b);
				}
			}
		}
		App.display();
	}
	return 0;
}
