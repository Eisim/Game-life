#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include"algs.h"

int main()
{
    bool start = false;
    const int FPS = 2;
    int standartscreensize = 800;
    int cellnum = 20;
    int cellsize=(int)standartscreensize/cellnum;
    standartscreensize = cellsize * cellnum;

    sf::RenderWindow window(sf::VideoMode(standartscreensize, standartscreensize), "Game life");
    
    std::vector<sf::RectangleShape> cells;
    std::vector<sf::RectangleShape> grid;

    std::vector<int> actionlist;

    //creating grid
    for (int x = 0; x <= cellnum; x++) {
        sf::RectangleShape line1(sf::Vector2f(standartscreensize, 5));//vertical line
        line1.setPosition(sf::Vector2f(cellsize * x, 0));
        line1.setFillColor(sf::Color::Black);
        sf::RectangleShape line2(sf::Vector2f(standartscreensize, 5));//horizontal line
        line2.setPosition(sf::Vector2f(0, cellsize * x));
        line2.setFillColor(sf::Color::Black);
        line1.rotate(90);
        grid.push_back(line1);
        grid.push_back(line2);

    }
    
    //actionlist random filling 
    for (int x = 0; x < cellnum; x++) {
        for (int y = 0; y < cellnum; y++) {
            actionlist.push_back(rand() % 2);
        }
    }
    //filling cells array;
    cells = createField(actionlist,cellsize,cellnum);
    
    while (window.isOpen())
    {
        sf::Vector2u size = window.getSize();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && sf::Keyboard::Space)start = !start;

            if (event.type == sf::Event::MouseButtonPressed) {
                int x = (int)sf::Mouse::getPosition(window).x/cellsize, y = (int)sf::Mouse::getPosition(window).y/cellsize;
                
                //std::cout << x << " " << y << std::endl;
                
                //change cellmode;
                actionlist[x + y * cellnum] = (actionlist[x + y * cellnum]+1) % 2;
                std::cout << getNeighbour(x + y * cellnum, actionlist)<<"--"<<x<<":"<<y<<"\n";
                
            }


        }
        
        
        if (start)
            actionlist = nextStep(actionlist);
        cells = createField(actionlist, cellsize, cellnum);
        

        window.clear();
        for(int i=0;i<cellnum*cellnum;i++)
            window.draw(cells[i]);
        for (int i = 0; i < grid.size(); i++)
            window.draw(grid[i]);
        window.setFramerateLimit(FPS);
        window.display();
    }

    return 0;

}