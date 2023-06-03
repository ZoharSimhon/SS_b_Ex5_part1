// #include "MagicalContainer.hpp"
// using namespace ariel;

// // Default constructor
// // MagicalContainer::SideCrossIterator::SideCrossIterator()
// // {
// // }

// // constructor with container
// MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
//     : container_(container), it_(container.getFirstPrime()) {}

// // constructor with container & iterator
// // MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, Node *it)
// //     : container_(container), it_(it) {}

// // Copy constructor
// MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer::SideCrossIterator const &otherAI)
//     : container_(otherAI.container_), it_(otherAI.it_) {}

// // Destructor
// MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

// // Assignment operator
// MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator=(SideCrossIterator otherAI)
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
// bool MagicalContainer::SideCrossIterator::operator==(SideCrossIterator otherAI)
// {
//     if (&this->container_ != &otherAI.container_)
//         throw runtime_error("Can't compare iterators from different containers");

//     if (this->it_ == otherAI.it_)
//         return true;

//     return false;
// }

// // Inequality comparison(operator!=)
// bool MagicalContainer::SideCrossIterator::operator!=(SideCrossIterator otherAI)
// {
//     return !(*this == otherAI);
// }

// //CHANGED!!!!!!!!!!
// //  GT, LT comparison (operator>, operatorn<)
// bool MagicalContainer::SideCrossIterator::operator>(SideCrossIterator otherAI)
// {
//     if (&this->container_ != &otherAI.container_)
//         throw runtime_error("Can't compare iterators from different containers");

//     // if ((*this->it_)->getData() > (*otherAI.it_)->getData())
//     if (this->it_->getData() > otherAI.it_->getData())
//         return true;

//     return false;
// }
// bool MagicalContainer::SideCrossIterator::operator<(SideCrossIterator otherAI)
// {
//     return !(*this > otherAI || *this == otherAI);
// }

// // Dereference operator (operator*)
// int MagicalContainer::SideCrossIterator::operator*() const
// {
//     return this->it_->getData();
// }

// // // Pre-increment operator (operator++)
// // MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
// // {
// //     if (*this->it_ == nullptr)
// //         throw runtime_error("out of range");

// //     ++this->it_;
// //     return *this;
// // }

// // // begin(type): Returns the appropriate iterator pointing to the first element of the container
// // MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
// // {
// //     return SideCrossIterator(this->container_);
// // }

// // // end(type): Returns the appropriate iterator pointing to the last element of the container.
// // MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
// // {
// //     return SideCrossIterator(this->container_, this->container_.getEnd());
// // }
