#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <cmath>

class Point {
public:
    int X, Y;

    Point(int x = 0, int y = 0) : X(x), Y(y) {}

    void Locat(int& x, int& y) {
        x = X;
        y = Y;
    }
};

class Krug : public Point {
private:
    int Radius;
    sf::Color Cvet;
    sf::CircleShape shape;

public:
    Krug(int x, int y, int radius, sf::Color cvet) : Point(x, y), Radius(radius), Cvet(cvet) {
        shape.setRadius(static_cast<float>(Radius));
        shape.setFillColor(Cvet);
        shape.setOrigin(static_cast<float>(Radius), static_cast<float>(Radius));
        shape.setPosition(static_cast<float>(X), static_cast<float>(Y));
    }

    void Show(sf::RenderWindow& window) {
        window.draw(shape);
    }

    void Hide(sf::RenderWindow& window) {
        shape.setFillColor(sf::Color::Transparent);
        window.draw(shape);
        shape.setFillColor(Cvet);
    }

    void ChangeSize(int delta) {
        Radius += delta;
        shape.setRadius(static_cast<float>(Radius));
        shape.setOrigin(static_cast<float>(Radius), static_cast<float>(Radius));
    }

    void ChangeColor(sf::Color newColor) {
        Cvet = newColor;
        shape.setFillColor(Cvet);
    }

    void Fly(int Cost, sf::RenderWindow& window) {
        Show(window);
        srand(static_cast<unsigned>(time(nullptr)));
        do {
            int XX, YY;
            Locat(XX, YY);
            do {
                XX = XX + static_cast<int>(round((rand() / static_cast<double>(RAND_MAX) - 0.5) * Cost));
            } while (XX <= 0 || XX >= window.getSize().x);
            do {
                YY = YY + static_cast<int>(round((rand() / static_cast<double>(RAND_MAX) - 0.5) * Cost));
            } while (YY <= 0 || YY >= window.getSize().y);
            Hide(window);
            X = XX;
            Y = YY;
            ChangeSize(rand() % 20 - 10); // Изменение размера на случайное значение в пределах [-10, 10]
            ChangeColor(sf::Color(rand() % 255, rand() % 255, rand() % 255)); // Случайный цвет
            Show(window);
            window.display();
            sf::sleep(sf::milliseconds(300));
        } while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Krug Program");
    Krug krug( 200, 300, 50, sf::Color::Red); // Инициализация круга с центром в (200, 300), радиусом 50 и красным цветом

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        krug.Fly(10, window); // Вызов метода Fly с параметром Cost равным 10
        window.display();
    }

    return 0;
}