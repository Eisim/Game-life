#include<iostream>
#include<SFML/Graphics.hpp>

std::vector<sf::RectangleShape> createField(std::vector<int> actionlist, int cellsize, int cellnum) {
    std::vector<sf::RectangleShape> cells;

    for (int y = 0; y < cellnum; y++) {
        for (int x = 0; x < cellnum; x++) {
            //appending new cell
            cells.push_back(sf::RectangleShape(sf::Vector2f(cellsize * x, cellsize * y)));
            //setting settings for last appended cell
            cells[cells.size() - 1].setSize(sf::Vector2f(cellsize, cellsize));
            //connecting actionlist and cells. 1=>Life ;0=>Dead
            (actionlist[cells.size()-1] == 1) ? cells[cells.size() - 1].setFillColor(sf::Color::Green) : cells[cells.size() - 1].setFillColor(sf::Color::Black);
            cells[cells.size() - 1].setPosition(cellsize * x, cellsize * y);
        }
    }
    return cells;
}

int getNeighbour(int currentcell,std::vector<int> actionlist) {


std::vector<int> nextStep(std::vector<int> actionlist) {
    std::vector<int> newactionlist;
    int cellnum = sqrt(actionlist.size());
    for (int i = 0; i < actionlist.size(); i++) {
        int currentcell = actionlist[i];
        int neighcount = getNeighbour(currentcell, actionlist);
        if (currentcell == 0) {
            if (neighcount == 3)
                newactionlist.push_back(1);
            else { newactionlist.push_back(0); }
        }
        else if(currentcell==1){
                
            if(neighcount==2 || neighcount==3){ newactionlist.push_back(1); }
            newactionlist.push_back(0);
        }

    }
   
    return newactionlist;
}