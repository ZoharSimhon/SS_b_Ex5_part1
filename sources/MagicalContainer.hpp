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
        class AscendingIterator;
        class PrimeIterator;
        class SideCrossIterator;

        MagicalContainer();
        // getters
        Node *getBegin() const;
        Node *getEnd() const;
        Node *getFirstPrime() const;

        int size();
        void addElement(int number);
        void removeElement(int number);
        void printMagicalContainer();
        void printPrimes();
        ~MagicalContainer();
    };

    // abstract class
    class MagicalContainer::Iterator
    {
    private:
        Node *it_;
        const MagicalContainer &container_;
        int type_;

    public:
        // constructor with container
        Iterator(const MagicalContainer &container, int type, Node *it);
        // Dereference operator (operator*)
        virtual int operator*() const;
        // Equality comparison(operator==)
        bool operator==(const Iterator &otherIt) const;
        // Inequality comparison(operator!=)
        bool operator!=(const Iterator &otherIt) const;
        //  GT, LT comparison (operator>, operatorn<)
        bool operator<(const Iterator &otherIt) const;
        bool operator>(const Iterator &otherIt) const;

        // getters
        Node *getIt() const;
        const MagicalContainer &getContainer() const;
        int getType() const;

        // setters
        void setIt(Node *it);

        // virtual methods
        // Pre-increment operator (operator++)
        virtual Iterator &operator++() = 0;
        // begin(type): Returns the appropriate iterator pointing to the first element of the container
        virtual Iterator &begin() const = 0;
        // end(type): Returns the appropriate iterator pointing to the last element of the container
        virtual Iterator &end() const = 0;
    };

    // ordered iterstor
    class MagicalContainer::AscendingIterator : public Iterator
    {
    private:
        // constructor with container & iterator
        AscendingIterator(const MagicalContainer &container, Node *it);

    public:
        // Default constructor
        // AscendingIterator();

        // Copy constructor
        AscendingIterator(AscendingIterator const &otherAI);

        // constructor with container
        AscendingIterator(const MagicalContainer &container);

        // Assignment operator
        AscendingIterator operator=(AscendingIterator otherAI);

        // Destructor
        ~AscendingIterator() {}

        // override methods
        // Pre-increment operator (operator++)
        AscendingIterator &operator++() override;
        // begin(type): Returns the appropriate iterator pointing to the first element of the container
        AscendingIterator &begin() const override;
        // end(type): Returns the appropriate iterator pointing to the last element of the container
        AscendingIterator &end() const override;
    };

    // primes iterstor
    class MagicalContainer::PrimeIterator : public Iterator
    {
    private:
        // constructor with container & iterator
        PrimeIterator(const MagicalContainer &container, Node *it);

    public:
        // Default constructor
        // PrimeIterator();

        // Copy constructor
        PrimeIterator(PrimeIterator const &otherPI);

        // constructor with container
        PrimeIterator(const MagicalContainer &container);

        // Assignment operator
        PrimeIterator operator=(PrimeIterator otherPI);

        // Destructor
        ~PrimeIterator() {}

        // override methods
        // Pre-increment operator (operator++)
        PrimeIterator &operator++() override;
        // begin(type): Returns the appropriate iterator pointing to the first element of the container
        PrimeIterator &begin() const override;
        // end(type): Returns the appropriate iterator pointing to the last element of the container
        PrimeIterator &end() const override;
    };

    // SideCross iterstor
    class MagicalContainer::SideCrossIterator : public Iterator
    {
    private:
        Node *lastIt_;
        size_t counter_;
        // constructor with container & iterator
        SideCrossIterator(const MagicalContainer &container, Node *it);

    public:
        // Default constructor
        // SideCrossIterator();

        // Copy constructor
        SideCrossIterator(SideCrossIterator const &otherSCI);

        // constructor with container
        SideCrossIterator(const MagicalContainer &container);

        // Assignment operator
        SideCrossIterator operator=(SideCrossIterator otherSCI);

        // Destructor
        ~SideCrossIterator() {}

        // override methods
        // Dereference operator (operator*)
        int operator*() const override;
        // Pre-increment operator (operator++)
        SideCrossIterator &operator++() override;
        // begin(type): Returns the appropriate iterator pointing to the first element of the container
        SideCrossIterator &begin() const override;
        // end(type): Returns the appropriate iterator pointing to the last element of the container
        SideCrossIterator &end() const override;
    };
}