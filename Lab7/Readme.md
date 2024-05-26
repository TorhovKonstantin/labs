# Лабораторная работа №7

Задача 1 

Необходимо перевести программу с Паскаля на C++

Код исходной программы: https://github.com/TorhovKonstantin/labs/blob/main/Lab7/lab7.1.cpp

Результаты решения:

![image](https://github.com/TorhovKonstantin/labs/assets/122263721/552f2430-ba29-4ddb-8d1d-5066fb4f2fd6)


Задача 2

Дополнить набор методов одного из классов функциями,которые выполняют сужение-расширение вырезанного сектора на фигурах и
смену цветов фигур одновременно с перемещением

Для добавления функциональности сужения и расширения сектора фигуры, а также смены цвета во время перемещения, мы можем расширить класс Krug. Необходимо добавить методы ChangeSize и ChangeColor, которые будут изменять размер и цвет круга соответственно:

```c++
class Krug : public Point {
    // ... существующие члены класса ...

    // Метод для изменения размера круга
    void ChangeSize(int delta) {
        Radius += delta;
        shape.setRadius(static_cast<float>(Radius));
        shape.setOrigin(static_cast<float>(Radius), static_cast<float>(Radius)); // Чтобы центр круга оставался на месте
    }

    // Метод для изменения цвета круга
    void ChangeColor(sf::Color newColor) {
        Cvet = newColor;
        shape.setFillColor(Cvet);
    }

    // Переопределенный метод Fly с изменением размера и цвета
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
```

Код исходной программы: https://github.com/TorhovKonstantin/labs/blob/main/Lab7/lab7.2.cpp
