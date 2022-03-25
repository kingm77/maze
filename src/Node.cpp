#include "Node.h"
#include <math.h>

Node::Node(int xCord, int yCord, Position parent)
{
	position = Position(xCord, yCord);
	f = 0;
	g = 0;
	h = 0;
	this->parent = parent;
}

Node::Node(int xCord, int yCord)
{
	parent = Position();
	position = Position(xCord, yCord);
	f = 0;
	g = 0;
	h = 0;
}

Node::Node(){
	parent = Position();
	position = Position();
	f = 0;
	g = 0;
	h = 0;
}

void Node::setG(double newG)
{
	g = newG;
}

void Node::setH(double newH)
{
	h = newH;
}

void Node::setF(double newF)
{
	f = newF;
}

void Node::setPosition(Position newPos)
{
	position = newPos;
}

void Node::setParent(Position newParent)
{
	parent = newParent;
}

double Node::getH()
{
	return h;
}

double Node::getG()
{
	return g;
}

double Node::getF()
{
	return f;
}

Position Node::getPosition()
{
	return position;
}

Position Node::getParent()
{
	return parent;
}

double Node::calculateG(Node startNode)
{
	this->g = std::abs(this->position.first - startNode.position.first)
			    +
			    std::abs(this->position.second - startNode.position.second);
	/*this->g = (
		sqrt((this->position.first - startNode.position.first)
			*
			(this->position.first - startNode.position.first)
			+
			(this->position.second - startNode.position.second)
			*
			(this->position.second - startNode.position.second)
		)
		);*/

	return g;
}

double Node::calculateH(Node endNode)
{
	this->h = std::abs(this->position.first - endNode.position.first)
			  +
			  std::abs(this->position.second - endNode.position.second);
	/*this->h = (
					sqrt(     (this->position.first - endNode.position.first) 
							  * 
							  (this->position.first - endNode.position.first)
							  + 
							  (this->position.second - endNode.position.second) 
							  * 
							  (this->position.second - endNode.position.second)
							)
		      );*/

	return h;
}

double Node::calculateF()
{
	f = g + h;
	return f;
}

bool Node::operator==(const Node& aNode)
{
	return this->position == aNode.position;
}

bool Node::operator!=(const Node& aNode)
{
	return this->position != aNode.position;
}

bool Node::operator>(const Node& aNode)
{
	return f > aNode.f;
}

bool Node::operator<(const Node& aNode)
{
	return f < aNode.f;
}

bool Node::operator>=(const Node& aNode)
{
	return f >= aNode.f;
}

bool Node::operator<=(const Node& aNode)
{
	return f <= aNode.f;
}
