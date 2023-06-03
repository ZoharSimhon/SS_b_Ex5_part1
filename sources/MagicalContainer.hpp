#pragma once
#include "Node.hpp"
#include <list>

namespace ariel
{
    class MagicalContainer
    {
    private:
        // list<Node *> numbers_;
        Node *firstPrime_;
        Node *last_;
        Node *first_;
        size_t size_;

        // helper functions
        void addPrimeNumber(Node *newNode);
        void addCompositeNumber(Node *newNode);
        void insertToPrimes(Node *prevPrime, Node *newNode);
        void insertToNumbers(Node *prev, Node *newNode);
        void removeFromPrimes(Node *deletedNode);
        void removeFromNumbers(Node *deletedNode);

    public:
        // iterators
        // class AscendingIterator;
        // class SideCrossIterator;

        MagicalContainer();
        // getters
        Node *getBegin();
        Node *getEnd();
        Node *getFirstPrime();

        int size();
        void addElement(int number);
        void removeElement(int number);
        void printMagicalContainer();
        void printPrimes();
        ~MagicalContainer();
    };

    // class MagicalContainer::AscendingIterator
    // {
    // private:
    //     list<Node *>::iterator it_;
    //     MagicalContainer &container_;
    //     // constructor with container & iterator
    //     AscendingIterator(MagicalContainer &container, list<Node *>::iterator it);

    // public:
    //     // Default constructor
    //     // AscendingIterator();

    //     // Copy constructor
    //     AscendingIterator(AscendingIterator const &otherAI);

    //     // constructor with container
    //     AscendingIterator(MagicalContainer &container);

    //     // Destructor
    //     ~AscendingIterator();

    //     // Assignment operator
    //     AscendingIterator operator=(AscendingIterator otherAI);

    //     // Equality comparison(operator==)
    //     bool operator==(AscendingIterator otherAI);

    //     // Inequality comparison(operator!=)
    //     bool operator!=(AscendingIterator otherAI);

    //     //  GT, LT comparison (operator>, operatorn<)
    //     bool operator>(AscendingIterator otherAI);
    //     bool operator<(AscendingIterator otherAI);

    //     // Dereference operator (operator*)
    //     int operator*() const;

    //     // Pre-increment operator (operator++)
    //     AscendingIterator &operator++();

    //     // begin(type): Returns the appropriate iterator pointing to the first element of the container
    //     MagicalContainer::AscendingIterator begin() const;

    //     // end(type): Returns the appropriate iterator pointing to the last element of the container.
    //     MagicalContainer::AscendingIterator end() const;
    // };

    // class MagicalContainer::SideCrossIterator
    // {
    // private:
    //     Node *it_;
    //     MagicalContainer &container_;
    //     // constructor with container & iterator
    //     // AscendingIterator(MagicalContainer &container, list<Node *>::iterator it);

    // public:
    //     // Default constructor
    //     // AscendingIterator();

    //     // Copy constructor
    //     SideCrossIterator(SideCrossIterator const &otherAI);

    //     // constructor with container
    //     SideCrossIterator(MagicalContainer &container);

    //     // Destructor
    //     ~SideCrossIterator();

    //     // Assignment operator
    //     SideCrossIterator operator=(SideCrossIterator otherAI);

    //     // Equality comparison(operator==)
    //     bool operator==(SideCrossIterator otherAI);

    //     // Inequality comparison(operator!=)
    //     bool operator!=(SideCrossIterator otherAI);

    //     //  GT, LT comparison (operator>, operatorn<)
    //     bool operator>(SideCrossIterator otherAI);
    //     bool operator<(SideCrossIterator otherAI);

    //     // Dereference operator (operator*)
    //     int operator*() const;

    //     // Pre-increment operator (operator++)
    //     SideCrossIterator &operator++();

    //     // begin(type): Returns the appropriate iterator pointing to the first element of the container
    //     MagicalContainer::SideCrossIterator begin() const;

    //     // end(type): Returns the appropriate iterator pointing to the last element of the container.
    //     MagicalContainer::SideCrossIterator end() const;
    // };

}