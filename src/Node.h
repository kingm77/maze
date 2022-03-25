#pragma once
#include <tuple>


typedef std::pair <int, int> Position;

class Node
{
	public:
		Node(int xCord, int yCord, Position parent);
		Node(int xCord, int yCord);
		Node();

		void setG(double newG);
		void setH(double newH);
		void setF(double newF);
		void setPosition(Position newPos);
		void setParent(Position newParent);

		double getH();
		double getG();
		double getF();
		Position getPosition();
		Position getParent();

		double calculateG(Node startNode);
		double calculateH(Node endNode);
		double calculateF();

		bool operator ==(const Node& aNode);
		bool operator !=(const Node& aNode);
		bool operator >(const Node& aNode);
		bool operator <(const Node& aNode);
		bool operator >=(const Node& aNode);
		bool operator <=(const Node& aNode);

	private:
		double g, h, f;    
		Position position;
		Position parent;
};

