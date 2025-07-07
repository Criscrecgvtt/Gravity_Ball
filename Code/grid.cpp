#include <SFML/Graphics.hpp>
void drawGrid(sf::RenderWindow& win, int rows, int cols){
    // initialize values
    int numLines = rows+cols-2;
    sf::VertexArray grid(sf::PrimitiveType::Lines, 2*(numLines));
    win.setView(win.getDefaultView());
    auto size = win.getView().getSize();
    float rowH = size.y/rows;
    float colW = size.x/cols;
    // row separators
    for(int i=0; i < rows-1; i++){
        int r = i+1;
        float rowY = rowH*r;
        grid[i*2].position = {0, rowY};
        grid[i*2+1].position = {size.x, rowY};
    }
    // column separators
    for(int i=rows-1; i < numLines; i++){
        int c = i-rows+2;
        float colX = colW*c;
        grid[i*2].position = {colX, 0};
        grid[i*2+1].position = {colX, size.y};
    }
    // draw it
    win.draw(grid);
}
int main()
{
    //Definicion variables ventana
    unsigned int windowsize = 1000;
    const int max_x = windowsize, max_y = windowsize, min_x = 0, min_y = 0;
    
   //Creo ventana y 
    sf::RenderWindow window(sf::VideoMode({windowsize, windowsize}), "SFML works!");
    window.setVerticalSyncEnabled(true);
   

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
       
        window.clear();
        drawGrid(window,10,10);
        window.display();
    }
}