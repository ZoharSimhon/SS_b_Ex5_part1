#include "doctest.h"
#include <stdexcept>
#include <stddef.h>
#include <iostream>
#include <sstream>

#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_SUITE("Class MagicalContainer")
{
    TEST_CASE("Constructor")
    {
        CHECK_NOTHROW(MagicalContainer container2);

        MagicalContainer container;
        CHECK(container.size() == 0);
    }

    TEST_CASE("Method: addElement")
    {
        MagicalContainer container;

        // Adding a single element
        container.addElement(17);
        CHECK(container.size() == 1);

        // Adding multiple elements
        container.addElement(2);
        container.addElement(23);
        container.addElement(25);
        CHECK(container.size() == 4);
    }

    TEST_CASE("Method: removeElement")
    {
        MagicalContainer container;

        // removing from an empty container
        CHECK_THROWS(container.removeElement(7));

        // removing a single element
        container.addElement(20);
        CHECK_NOTHROW(container.removeElement(20));
        CHECK(container.size() == 0);

        // removing prime number
        container.addElement(19);
        CHECK_NOTHROW(container.removeElement(19));
        CHECK(container.size() == 0);

        // removing multiple elements
        container.addElement(2);     // 1 element
        container.addElement(20);    // 2 elements
        container.addElement(25);    // 3 elements
        container.addElement(12);    // 4 elements
        container.removeElement(2);  // 3 elements
        container.removeElement(20); // 2 elements
        container.removeElement(25); // 1 element
        CHECK(container.size() == 1);

        // removing non-exist element
        CHECK_THROWS(container.removeElement(100));
    }
}

TEST_SUITE("Class AscendingIterator")
{
    TEST_CASE("Method: operator*")
    {
        MagicalContainer container;
        container.addElement(12);
        container.addElement(1);
        container.addElement(18);
        container.addElement(29);

        MagicalContainer::AscendingIterator ascIter(container);

        // checking that the iterator is ordered
        CHECK(*ascIter == 1);
        ++ascIter;
        CHECK(*ascIter == 12);
        ++ascIter;
        CHECK(*ascIter == 18);
        ++ascIter;
        CHECK(*ascIter == 29);

        // checking that we can't use operator* for nullptr
        ++ascIter;
        CHECK_THROWS(*ascIter);
    }

    TEST_CASE("Comparison methods")
    {
        MagicalContainer container;
        container.addElement(12);
        container.addElement(1);
        container.addElement(18);
        container.addElement(29);

        MagicalContainer::AscendingIterator ascIter1(container);
        MagicalContainer::AscendingIterator ascIter2(container);

        // equality
        CHECK(ascIter1 == ascIter2);
        CHECK(!(ascIter1 == ascIter2));
        ++ascIter1;
        CHECK(ascIter1 != ascIter2);
        CHECK(!(ascIter1 != ascIter2));


    }
}