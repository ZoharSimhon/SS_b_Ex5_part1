#pragma once
#include "Node.hpp"
#include <list>

#define Ascending 1
#define SideCross 2
#define Prime 3

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
        class Iterator;

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

    // abstract claa
    class MagicalContainer::Iterator
    {
    private:
        Node *it_;
        const MagicalContainer &container_;
        int type_;

    public:
        // constructor with container
        Iterator(const MagicalContainer &container, int type);
        // Dereference operator (operator*)
        int operator*() const;
        // Equality comparison(operator==)
        bool operator==(const Iterator &otherIt) const;
        // Inequality comparison(operator!=)
        bool operator!=(const Iterator &otherIt) const;
        //  GT, LT comparison (operator>, operatorn<)
        bool operator<(const Iterator &otherIt) const;
        bool operator>(const Iterator &otherIt) const;

        // virtual methods
        // Pre-increment operator (operator++)
        virtual Iterator &operator++() = 0;
        // begin(type): Returns the appropriate iterator pointing to the first element of the container
        virtual Iterator &begin() const = 0;
        // end(type): Returns the appropriate iterator pointing to the last element of the container
        virtual Iterator &end() const = 0;
    };

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