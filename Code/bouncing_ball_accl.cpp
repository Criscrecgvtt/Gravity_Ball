#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>


int main()
{
    //Definicion variables ventana
    unsigned int windowsize = 1000;
    const int max_x = windowsize, max_y = windowsize/2, min_x = 0, min_y = 0;
    float radius = 10;
    float x = 500.f-radius;
    float y =900;
    int mov_x = 0, mov_y = -3;

   //Creo ventana y circulo
    sf::Vector2f position(x, y);
    sf::RenderWindow window(sf::VideoMode({windowsize, windowsize}), "Bouncing Ball!");
    window.setVerticalSyncEnabled(true);
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(position);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        position = circle.getPosition();//posición actual  del circulo
        x = position.x; 
        y = position.y;
       
          if (y == min_y){//parte superior que es 0
            mov_y *= -1;
          }
           if (y == windowsize){//inf
            mov_y *= -1;
          }
          

        //pasamos las coordenadas actuales (x,y) al objeto circulo1
        sf::Vector2f movePos(mov_x, mov_y);
        circle.move(movePos);
        window.clear();
        window.draw(circle);
        window.display();
    }
}