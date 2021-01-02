#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <time.h>
#include <random>
#include <string>
#include <array>
#include <cstdlib>

class Ball : public sf::CircleShape
{
public:
    int Vx;
    int Vy;
    int HEIGHT = 800;
    int WIDTH = 1200;

    Ball()
    {
        sf::CircleShape();
        this->setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
        this->setPosition(rand() % 800 + 100, rand() % 300 + 100);
        this->setRadius(rand() % 5 + 1);

        Vy = rand() % 5 + 1;
        Vx = rand() % 5 + 1;

        if (rand() % 2 == 0)
        {
            Vy *= -1;
        }

        if (rand() % 2 == 0)
        {
            Vx *= -1;
        }
    }

    void moveBall()
    {
        if (this->getPosition().x < 0 || this->getPosition().x + this->getGlobalBounds().width > WIDTH)
        {
            Vx *= -1;
            std::cout << "*-1\n";
        }
        else if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > HEIGHT)
        {
            Vy *= -1;
            std::cout << "*-1\n";
        }

        this->move(Vx, Vy);
    }
};

void boom(Ball &ball_1, Ball &ball_2)
{
    if (ball_1.getRadius() >= ball_2.getRadius())
    {
        ball_1.setRadius(ball_1.getRadius() + ball_2.getRadius());
        ball_2.setRadius(0);

        ball_1.Vx = (ball_1.Vx + ball_1.Vx) / 2;
        ball_2.Vx = 0;
        ball_1.Vy = (ball_1.Vy + ball_1.Vy) / 2;
        ball_2.Vy = 0;

        // ball_1.setPosition((ball_1.getPosition().x + ball_2.getPosition().x) / 2, (ball_1.getPosition().y + ball_2.getPosition().y) / 2);
        ball_2.setPosition(1, 1);
        std::cout << "BOOM 1\n";
    }
    else
    {
        Ball temp = ball_1;
        ball_1 = ball_2;
        ball_2 = temp;

        ball_1.setRadius(ball_1.getRadius() + ball_2.getRadius());
        ball_2.setRadius(0);

        ball_1.Vx = (ball_1.Vx + ball_1.Vx) / 2;
        ball_2.Vx = 0;
        ball_1.Vy = (ball_1.Vx + ball_1.Vx) / 2;
        ball_2.Vy = 0;

        // ball_1.setPosition((ball_1.getPosition().x + ball_2.getPosition().x) / 2, (ball_1.getPosition().y + ball_2.getPosition().y) / 2);
        ball_2.setPosition(1, 1);
        std::cout << "BOOM 2\n";
    }
}

bool inter(Ball ONE, Ball TWO)
{
    if (ONE.getGlobalBounds().intersects(TWO.getGlobalBounds()))
    {
        // std::cout<<"Nachodzi! \n";
        return true;
    }
    else
    {
        return false;
    }
}

int main(int, char const **)
{
    srand(time(NULL));
    std::array<Ball, 40> arrayOfBalls;
    for (int i = 0; i < arrayOfBalls.size() - 1; i++)
    {
        // arrayOfBalls[i].setPosition(rand()%800+100, rand()%500+400);
        std::cout << arrayOfBalls[i].getPosition().x << "  " << arrayOfBalls[i].getPosition().y << std::endl;
    }

    sf::RenderWindow window(sf::VideoMode(1200, 800), "BALLS");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {

        window.clear();

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }

        int temp = 1;

        for (int i = 0; i < arrayOfBalls.size() - 1; i++)
        {
            for (int j = temp; j < arrayOfBalls.size() - 1; j++)
            {
                if (inter(arrayOfBalls[i], arrayOfBalls[j]))
                {
                    boom(arrayOfBalls[i], arrayOfBalls[j]);
                }
            }
            ++temp;
        }

        temp = 1;

        for (auto &element : arrayOfBalls)
        {
            element.moveBall();
            window.draw(element);
        }
        window.display();
    }
}