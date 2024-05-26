#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Point {
public:
    int X, Y;
    sf::Color Cvet;

    void Init(int XN, int YN, sf::Color Color) {
        X = XN;
        Y = YN;
        Cvet = Color;
    }

    virtual void Show(sf::RenderWindow& window) {}
    virtual void Hide(sf::RenderWindow& window) {}

    void Locat(int& XL, int& YL) {
        XL = X;
        YL = Y;
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
            Show(window);
            window.display();
            sf::sleep(sf::milliseconds(300));
        } while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
    }
};

class Krug : public Point {
public:
    unsigned short Radius;
    sf::CircleShape shape;

    Krug(int XN, int YN, unsigned short R, sf::Color Color) : shape(R) {
        Init(XN, YN, Color);
        Radius = R;
        shape.setFillColor(Cvet);
        shape.setPosition(static_cast<float>(X), static_cast<float>(Y));
    }

    void Show(sf::RenderWindow& window) override {
        window.draw(shape);
    }

    void Hide(sf::RenderWindow& window) override {
        shape.setFillColor(sf::Color::Black);
        window.draw(shape);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    Krug TestKrug(150, 40, 50, sf::Color::Red);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        TestKrug.Fly(100, window);
        window.display();
    }

    return 0;
}