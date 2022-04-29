#pragma once


std::vector<sf::RectangleShape> createField(std::vector<int> actionlist, int cellsize, int cellnum);
int getNeighbour(int currentcell, std::vector<int> actionlist);
std::vector<int> nextStep(std::vector<int> actionlist);