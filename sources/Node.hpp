#pragma once
#include <iostream>

using namespace std;

namespace ariel
{
    class Node
    {
    private:
        int data;
        Node *nextPrime;
        Node *prevPrime;
        bool isPrime;

        // helper functions
        bool checkIsPrime(int number);

    public:
        // constructors
        // Node(int data, Node *nextPrime, Node *prevPrime);
        Node(int data);

        // getters
        int getData();
        Node *getNextPrime();
        Node *getPrevPrime();
        bool getIsPrime();
        // setters
        void setData(int data);
        void setNextPrime(Node *nextPrime);
        void setPrevPrime(Node *prevPrime);
        bool operator==(const Node &other);
    };
}