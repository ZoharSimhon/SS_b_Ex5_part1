#include "MagicalContainer.hpp"

using namespace ariel;

// constructor with container
MagicalContainer::Iterator::Iterator(const MagicalContainer &container, int type, Node *it)
    : container_(container), type_(type), it_(it) {}

// Dereference operator (operator*)
int MagicalContainer::Iterator::operator*() const
{
    return this->it_->getData();
}
// Equality comparison(operator==)
bool MagicalContainer::Iterator::operator==(const Iterator &otherIt) const
{
    if (this->type_ != otherIt.type_)
        throw runtime_error("Can't compare different iterators");

    if (&this->container_ != &otherIt.container_)
        throw runtime_error("Can't compare iterators from different containers");

    if (this->it_ == otherIt.it_)
        return true;

    return false;
}
// Inequality comparison(operator!=)
bool MagicalContainer::Iterator::operator!=(const Iterator &otherIt) const
{
    return !(*this == otherIt);
}
//  GT, LT comparison (operator>, operatorn<)
bool MagicalContainer::Iterator::operator>(const Iterator &otherIt) const
{
    if (this->type_ != otherIt.type_)
        throw runtime_error("Can't compare different iterators");

    if (&this->container_ != &otherIt.container_)
        throw runtime_error("Can't compare iterators from different containers");

    if (this->it_->getData() > otherIt.it_->getData())
        return true;

    return false;
}
bool MagicalContainer::Iterator::operator<(const Iterator &otherIt) const
{
    return !(*this > otherIt || *this == otherIt);
}
// // Assignment operator
// Iterator &MagicalContainer::Iterator::operator=(Iterator otherIt)
// {
    
//     if (this->type_ != otherIt.type_)
//         throw runtime_error("Can't assign different iterators");

//     if (this != &otherIt)
//     {
//         if (&this-container_ != &otherIt.container_)
//             throw runtime_error("Can't assign iterators from different containers");

//         this->it_ = otherIt.it_;
//     }
//     return *this;
// }

// getters
Node *MagicalContainer::Iterator::getIt() const
{
    return this->it_;
}
const MagicalContainer &MagicalContainer::Iterator::getContainer() const
{
    return this->container_;
}
int MagicalContainer::Iterator::getType() const
{
    return this->type_;
}

// setters
void MagicalContainer::Iterator::setIt(Node *it)
{
    this->it_ = it;
}