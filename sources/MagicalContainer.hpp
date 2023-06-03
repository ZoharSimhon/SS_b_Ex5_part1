#pragma once
#include "Node.hpp"
#include <list>

namespace ariel
{
    class MagicalContainer
    {
    private:
        list<Node *> numbers;
        Node *lastPrime;
        Node *firstPrime;

        // helper functions
        void addPrimeNumber(Node *newNode);
        void addCompositeNumber(Node *newNode);

    public:
        MagicalContainer();
        int size();
        void addElement(int number);
        void removeElement(int number);
        void printMagicalContainer();
        void printPrimes();
        // ~MagicalContainer();
    };

    // MagicalContainer::~MagicalContainer()
    // {
    // }

}