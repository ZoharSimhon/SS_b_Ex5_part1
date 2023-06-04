#include "MagicalContainer.hpp"
using namespace ariel;

// Default constructor
// MagicalContainer::PrimeIterator::PrimeIterator()
// {
// }

// constructor with container
MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container)
    : Iterator(container, Prime, container.firstPrime_) {}

// constructor with container & iterator
MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container, Node *it)
    : Iterator(container, Prime, it) {}

// Copy constructor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer::PrimeIterator const &otherP)
    : Iterator(otherP.getContainer(), Prime, otherP.getIt()) {}

// Assignment operator
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator=(PrimeIterator otherP)
{
    if (this->getType() != otherP.getType())
        throw runtime_error("Can't assign different iterators");

    if (this != &otherP)
    {
        if (&this->getContainer() != &otherP.getContainer())
            throw runtime_error("Can't assign iterators from different containers");

        this->setIt(otherP.getIt());
    }
    return *this;
}

// Pre-increment operator (operator++)
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if (this->getIt() == nullptr)
        throw runtime_error("out of range");

    this->setIt(this->getIt()->getNextPrime());
    return *this;
}

// begin(type): Returns the appropriate iterator pointing to the first element of the container
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::begin() const
{
    PrimeIterator* beginIt = new PrimeIterator(this->getContainer());
    return *beginIt;
}

// end(type): Returns the appropriate iterator pointing to the last element of the container.
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::end() const
{
    PrimeIterator* endIt = new PrimeIterator(this->getContainer(), nullptr);
    return *endIt;
}
