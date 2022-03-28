// PathFinding.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "Process.h"
#include "Node.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{

	if(argc < 2){
		std::cerr << "missing arguments" << std::endl;
		exit(-1);
	}

	auto mazeFilePath = argv[1];
	auto end = Node();
	auto start = Node();
	auto maze = getMaze(mazeFilePath, start, end);
	auto p = aStar(maze, start, end);

	for (size_t i = 0; i < maze.size(); i++)
	{
		for (size_t j = 0; j < maze[0].size(); j++)
		{
			if (std::count(p.begin(), p.end(), std::pair<int, int>{i, j})) std::cout << "P";

			else std::cout << maze[i][j];
		}
		std::cout << std::endl;
	}
}
