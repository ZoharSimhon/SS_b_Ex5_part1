#include "MagicalContainer.hpp"
using namespace ariel;

// Default constructor
// MagicalContainer::AscendingIterator::AscendingIterator()
// {
// }

// constructor with container
MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container)
    : Iterator(container, Ascending, container.first_) {}

// constructor with container & iterator
MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container, Node *it)
    : Iterator(container, Ascending, it) {}

// Copy constructor
// MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer::AscendingIterator const &otherAI)
//     : container_(otherAI.container_), it_(otherAI.it_), type_(Ascending) {}

// Assignment operator
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator=(AscendingIterator otherAI)
{
    if (this->getType() != otherAI.getType())
        throw runtime_error("Can't assign different iterators");

    if (this != &otherAI)
    {
        if (&this->getContainer() != &otherAI.getContainer())
            throw runtime_error("Can't assign iterators from different containers");

        this->setIt(otherAI.getIt());
    }
    return *this;
}

// Pre-increment operator (operator++)
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (this->getIt() == nullptr)
        throw runtime_error("out of range");

    this->setIt(this->getIt()->getNext());
    return *this;
}

// begin(type): Returns the appropriate iterator pointing to the first element of the container
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin() const
{
    AscendingIterator* beginIt = new AscendingIterator(this->getContainer());
    return *beginIt;
}

// end(type): Returns the appropriate iterator pointing to the last element of the container.
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end() const
{
    AscendingIterator* endIt = new AscendingIterator(this->getContainer(), nullptr);
    return *endIt;
}
