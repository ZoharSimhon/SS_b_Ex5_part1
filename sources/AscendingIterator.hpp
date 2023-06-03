// #pragma once

// #include "MagicalContainer.hpp"

// namespace ariel
// {

//     class MagicalContainer::AscendingIterator : public Iterator
//     {
//     private:
//         // list<Node *>::iterator it_;
//         // MagicalContainer &container_;
//         // // constructor with container & iterator
//         // AscendingIterator(MagicalContainer &container, list<Node *>::iterator it);

//     public:
//         // Default constructor
//         // AscendingIterator();

//         // Copy constructor
//         AscendingIterator(AscendingIterator const &otherAI);

//         // constructor with container
//         AscendingIterator(MagicalContainer &container);

//         // Destructor
//         ~AscendingIterator();

//         // Assignment operator
//         AscendingIterator operator=(AscendingIterator otherAI);

//         // Equality comparison(operator==)
//         bool operator==(AscendingIterator otherAI);

//         // Inequality comparison(operator!=)
//         bool operator!=(AscendingIterator otherAI);

//         //  GT, LT comparison (operator>, operatorn<)
//         bool operator>(AscendingIterator otherAI);
//         bool operator<(AscendingIterator otherAI);

//         // Dereference operator (operator*)
//         int operator*() const;

//         // Pre-increment operator (operator++)
//         AscendingIterator &operator++();

//         // begin(type): Returns the appropriate iterator pointing to the first element of the container
//         MagicalContainer::AscendingIterator begin() const;

//         // end(type): Returns the appropriate iterator pointing to the last element of the container.
//         MagicalContainer::AscendingIterator end() const;
//     };

// }