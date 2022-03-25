#pragma once
#include <vector>
#include <string>
#include <map>
#include "Node.h"

typedef std::vector<Node> NodeList;
typedef std::vector <std::vector<char>> Maze;
typedef std::vector<Position> Path;
typedef std::map <Position, Node> NodeMap;


Maze getMaze(std::string path, Node& start, Node& end);
void addInOpenList(Node& elm, NodeList& openList, NodeMap& openListNodeMap);
bool isValidPosition(int xCord, int yCord, int nbRow, int nbCol);
Path aStar(Maze maze, Node startNode, Node endNode);
