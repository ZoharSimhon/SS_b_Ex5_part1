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
        // iterators
        class AscendingIterator;

        MagicalContainer();
        list<Node *>::iterator getBegin();
        list<Node *>::iterator getEnd();
        int size();
        void addElement(int number);
        void removeElement(int number);
        void printMagicalContainer();
        void printPrimes();
        ~MagicalContainer();
    };

    class MagicalContainer::AscendingIterator : public MagicalContainer
    {
    private:
        list<Node *>::iterator it_;
        MagicalContainer &container_;
        // constructor with container & iterator
        AscendingIterator(MagicalContainer &container, list<Node *>::iterator it);

    public:
        // Default constructor
        // AscendingIterator();

        // Copy constructor
        AscendingIterator(AscendingIterator const &otherAI);

        // constructor with container
        AscendingIterator(MagicalContainer &container);

        // Destructor
        ~AscendingIterator();

        // Assignment operator
        void operator=(AscendingIterator otherAI);

        // Equality comparison(operator==)
        bool operator==(AscendingIterator otherAI);

        // Inequality comparison(operator!=)
        bool operator!=(AscendingIterator otherAI);

        //  GT, LT comparison (operator>, operatorn<)
        bool operator>(AscendingIterator otherAI);
        bool operator<(AscendingIterator otherAI);

        // Dereference operator (operator*)
        int operator*() const;

        // Pre-increment operator (operator++)
        AscendingIterator &operator++();

        // begin(type): Returns the appropriate iterator pointing to the first element of the container
        MagicalContainer::AscendingIterator begin() const;

        // end(type): Returns the appropriate iterator pointing to the last element of the container.
        MagicalContainer::AscendingIterator end() const;
    };

}