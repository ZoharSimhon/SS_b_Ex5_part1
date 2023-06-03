#include "MagicalContainer.hpp"
using namespace ariel;

// helper functions
void MagicalContainer::addPrimeNumber(Node *newNode)
{
    Node *prev = nullptr;

    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        // found the place to insert
        if ((*it)->getData() >= newNode->getData())
        {
            // add the number to the first value
            if (prev == nullptr)
            {
                // update the next to the current first prime
                newNode->setNextPrime(this->firstPrime);
                // change the next Node
                if (this->firstPrime != nullptr)
                    firstPrime->setPrevPrime(newNode);
                // update the first
                this->firstPrime = newNode;
            }
            // add the number in the middle
            else
            {
                // define the next prime
                Node *next = prev->getNextPrime();
                // update the prev & next of the new Node
                newNode->setNextPrime(next);
                newNode->setPrevPrime(prev);
                // change the prev Node
                prev->setNextPrime(newNode);
                // change the next Node
                if (next != nullptr)
                    next->setPrevPrime(newNode);
                // update the last prime
                else
                    this->lastPrime = newNode;
            }

            // insert the new Node to the container
            numbers.insert(it, newNode);
            return;
        }

        // update the last prime
        if ((*it)->getIsPrime())
            prev = *it;
    }

    // update the prev of the new Node
    newNode->setPrevPrime(prev);

    // update the first prime
    if (this->firstPrime == nullptr)
        this->firstPrime = newNode;

    // insert the new Node to the container
    numbers.emplace_back(newNode);
}
void MagicalContainer::addCompositeNumber(Node *newNode)
{
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        // found the place to insert
        if ((*it)->getData() >= newNode->getData())
        {
            numbers.insert(it, newNode);
            return;
        }
    }
    numbers.emplace_back(newNode);
}

MagicalContainer::MagicalContainer()
{
    this->firstPrime = nullptr;
    this->lastPrime = nullptr;
}

int MagicalContainer::size()
{
    return this->numbers.size();
}

void MagicalContainer::addElement(int number)
{
    // create new Node
    Node *newNode = new Node(number);
    if (newNode->getIsPrime())
        addPrimeNumber(newNode);
    else
        addCompositeNumber(newNode);
}

void MagicalContainer::removeElement(int number)
{
    // if (newNode->getIsPrime())
    //     removePrimeNumber(number);
    // else
    //     removeCompositeNumber(number);

    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        if ((*it)->getData() == number)
        {
            // change the pointers
            if ((*it)->getIsPrime())
            {
                Node *prev = (*it)->getPrevPrime();
                Node *next = (*it)->getNextPrime();
                // update the prev
                if (prev != nullptr)
                {
                    prev->setNextPrime(next);
                }
                // update the next
                if (next != nullptr)
                {
                    next->setPrevPrime(prev);
                }
                // update the head
                if (this->firstPrime == (*it))
                {
                    this->firstPrime = next;
                }
                // update the teal
                if (this->lastPrime == (*it))
                {
                    this->lastPrime = prev;
                }
            }

            // remove from the list
            numbers.remove(*it);
            return;
        }
    }
    // didn't found the number
}

void MagicalContainer::printMagicalContainer()
{
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        cout << (*it)->getData() << ",";
    }
    cout << endl;
}

void MagicalContainer::printPrimes()
{
    Node *curr = this->firstPrime;
    while (curr != nullptr)
    {
        cout << curr->getData() << ",";
        curr = curr->getNextPrime();
    }
    cout << endl;
}
