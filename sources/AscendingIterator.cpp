// #include "MagicalContainer.hpp"
// using namespace ariel;

// // Default constructor
// // MagicalContainer::AscendingIterator::AscendingIterator()
// // {
// // }

// // constructor with container
// MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
//     : container_(container), it_(container.getBegin()) {}

// // constructor with container & iterator
// MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container, list<Node *>::iterator it)
//     : container_(container), it_(it) {}

// // Copy constructor
// MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer::AscendingIterator const &otherAI)
//     : container_(otherAI.container_), it_(otherAI.it_) {}

// // Destructor
// MagicalContainer::AscendingIterator::~AscendingIterator() {}

// // Assignment operator
// MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator=(AscendingIterator otherAI)
// {
//     if (this != &otherAI)
//     {
//         if (&this->container_ != &otherAI.container_)
//             throw runtime_error("Can't assign iterators from different containers");

//         this->it_ = otherAI.it_;
//     }
//     return *this;
// }

// // Equality comparison(operator==)
// bool MagicalContainer::AscendingIterator::operator==(AscendingIterator otherAI)
// {
//     if (&this->container_ != &otherAI.container_)
//         throw runtime_error("Can't compare iterators from different containers");

//     if (this->it_ == otherAI.it_)
//         return true;

//     return false;
// }

// // Inequality comparison(operator!=)
// bool MagicalContainer::AscendingIterator::operator!=(AscendingIterator otherAI)
// {
//     return !(*this == otherAI);
// }

// //  GT, LT comparison (operator>, operatorn<)
// bool MagicalContainer::AscendingIterator::operator>(AscendingIterator otherAI)
// {
//     if (&this->container_ != &otherAI.container_)
//         throw runtime_error("Can't compare iterators from different containers");

//     if ((*this->it_)->getData() > (*otherAI.it_)->getData())
//         return true;

//     return false;
// }
// bool MagicalContainer::AscendingIterator::operator<(AscendingIterator otherAI)
// {
//     return !(*this > otherAI || *this == otherAI);
// }

// // Dereference operator (operator*)
// int MagicalContainer::AscendingIterator::operator*() const
// {
//     return (*this->it_)->getData();
// }

// // Pre-increment operator (operator++)
// MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
// {
//     if (*this->it_ == nullptr)
//         throw runtime_error("out of range");

//     ++this->it_;
//     return *this;
// }

// // begin(type): Returns the appropriate iterator pointing to the first element of the container
// MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const
// {
//     return AscendingIterator(this->container_);
// }

// // end(type): Returns the appropriate iterator pointing to the last element of the container.
// MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const
// {
//     return AscendingIterator(this->container_, this->container_.getEnd());
// }
