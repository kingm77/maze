#include "Process.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Node.h"


Maze getMaze(std::string path, Node& start, Node& end)
{
    std::string line {};
	std::ifstream mapFile(path, std::ios::in);
    Maze maze = Maze();
    auto row {0};
    if (!mapFile.is_open()) {
        std::cerr << "Could not open the file - '"
            << path << "'" << std::endl;
        exit(-1);
    }

    while (getline(mapFile, line)) {
        auto mazeLine = std::vector<char>();

        for (size_t col = 0; col < line.size(); col++)
        {
            if(line[col] != '\n') {

                if(line[col] == '1') start = Node(row, col);

                else if (line[col] == '2') end = Node(row, col);
                
                mazeLine.push_back(line[col]);
            }
        }
        maze.push_back(mazeLine);
        row++;
    }

	return maze;
}

void addInOpenList(Node& elm, NodeList& openList, NodeMap& openListNodeMap)
{
    openList.push_back(elm);
    openListNodeMap.insert(std::pair<Position, Node>{elm.getPosition(), elm});
}

bool isValidPosition(int xCord, int yCord, int nbRow, int nbCol)
{
    return (xCord >= 0) && (xCord < nbRow) && (yCord >= 0)
        && (yCord < nbCol);
}

Path aStar(Maze maze, Node startNode, Node endNode)
{
    const int nbRow = static_cast<int>(maze.size());
    const int nbCol = static_cast<int>(maze[0].size());

    NodeMap closeListNodeMap{};
    NodeMap openListNodeMap{};
    NodeList openList = NodeList();
    NodeList closeList = NodeList();

    addInOpenList(startNode, openList, openListNodeMap);

    while (openList.size() > 0)
    {
        std::sort(openList.begin(), openList.end());
        auto currNode = openList[0];
        openList.erase(openList.begin());
        closeList.push_back(currNode);
        closeListNodeMap.insert(std::pair<Position, Node>{currNode.getPosition(), currNode});

        if (currNode == endNode) {

            Path path = Path();
            while (currNode != startNode) {
                path.push_back(currNode.getPosition());
                currNode = closeListNodeMap.find(currNode.getParent())->second;
            }

            std::reverse(path.begin(), path.end());
            return path;
        }

        auto xCord = currNode.getPosition().first;
        auto yCord = currNode.getPosition().second;

        auto neighborsPositions = {
            Position(xCord - 1, yCord),
            Position(xCord + 1, yCord),
            Position(xCord, yCord - 1),
            Position(xCord, yCord + 1),
            Position(xCord - 1, yCord + 1),
            Position(xCord - 1, yCord - 1),
            Position(xCord + 1, yCord + 1),
            Position(xCord + 1, yCord - 1),
        };

        for (auto& neighborPosition : neighborsPositions) {
            auto neighborXCord = neighborPosition.first;
            auto neighborYCord = neighborPosition.second;
            if (!isValidPosition(neighborXCord, neighborYCord, nbRow, nbCol)) continue;

            auto val = maze[neighborXCord][neighborYCord];

            if (val == '*' || closeListNodeMap.count(neighborPosition)) continue;

            Node neighborNode = Node(neighborXCord, neighborYCord, currNode.getPosition());

            neighborNode.calculateG(startNode);
            neighborNode.calculateH(endNode);
            neighborNode.calculateF();
            auto it = openListNodeMap.find(neighborPosition);
            if (it != openListNodeMap.end()) {
                auto elm_find = it->second;
                if (elm_find < neighborNode) {
                    openList.push_back(neighborNode);
                    it->second = neighborNode;
                }
            }
            else
                addInOpenList(neighborNode, openList, openListNodeMap);
        }
    }
    return Path();
}