// Подключение графической библиотеки
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

#include <string>
#include <fstream>

using namespace std::chrono_literals;

int main()
{
    // Создание окна с известными размерами и названием
    sf::RenderWindow window(sf::VideoMode(800, 600), L"Первая программа!");
    
    // Круглая фигура радиусом 100 px
    sf::CircleShape shape(100.0);   // 100.0 - double, 100.f - float
    shape.setOrigin(100, 100);
    // Задание цвета фигуре
    shape.setFillColor(sf::Color::Green);
    int shape_x = 0, shape_y = 0;
    shape.setPosition(shape_x, shape_y);

    // Прямоугольник
    sf::RectangleShape shape2(sf::Vector2f(100, 200));
    shape2.setFillColor(sf::Color::Red);
    shape2.setPosition(500, 500);
    shape2.setOrigin(50, 100);

    // Цикл работает до тех пор, пока окно открыто
    while (window.isOpen())
    {
        // Переменная для хранения события
        sf::Event event;
        // Цикл по всем событиям
        while (window.pollEvent(event))
        {
            // Обработка событий
            // Если нажат крестик, то
            if (event.type == sf::Event::Closed)
                // окно закрывается
                window.close();
        }

        shape_x++;
        shape_y++;
        if (shape_y > 600)
            shape_y = 600;
        shape.setPosition(shape_x, shape_y);

        // Очистить окно от всего
        window.clear();

        // Перемещение фигуры в буфер
        window.draw(shape);
        window.draw(shape2);

        // Отобразить на окне все, что есть в буфере
        window.display();

        std::this_thread::sleep_for(40ms);
    }

    return 0;
}