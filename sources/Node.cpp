#include "Node.hpp"
using namespace ariel;

// constructors
// Node::Node(int data, Node *nextPrime, Node *prevPrime)
// {
//     this->data = data;
//     this->nextPrime = nextPrime;
//     this->prevPrime = prevPrime;
//     this->isPrime = checkIsPrime(data);
// }
Node::Node(int data)
{
    this->data = data;
    this->nextPrime = nullptr;
    this->prevPrime = nullptr;
    this->isPrime = checkIsPrime(data);
}

// helper function
bool Node::checkIsPrime(int number)
{
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

// getters
int Node::getData()
{
    return this->data;
}
Node *Node::getNextPrime()
{
    return this->nextPrime;
}
Node *Node::getPrevPrime()
{
    return this->prevPrime;
}
bool Node::getIsPrime()
{
    return this->isPrime;
}

// setters
void Node::setData(int data)
{
    this->data = data;
}
void Node::setNextPrime(Node *nextPrime)
{
    this->nextPrime = nextPrime;
}
void Node::setPrevPrime(Node *prevPrime)
{
    this->prevPrime = prevPrime;
}

bool Node::operator==(const Node &other)
{
    return (this->data == other.data);
}
