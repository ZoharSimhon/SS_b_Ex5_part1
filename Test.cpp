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
        CHECK(!(ascIter1 != ascIter2));
        ++ascIter1; // increment in 1
        CHECK(ascIter1 != ascIter2);
        CHECK(!(ascIter1 == ascIter2));

        // greater then
        CHECK(ascIter1 > ascIter2);
        CHECK(!(ascIter2 > ascIter1));
        ++ascIter2; // increment in 1
        CHECK(!(ascIter1 > ascIter2));
        ++ascIter2; // increment in 2
        CHECK(ascIter2 > ascIter1);

        // less then
        CHECK(ascIter1 < ascIter2);
        CHECK(!(ascIter2 < ascIter1));
        ++ascIter1; // increment in 2
        CHECK(!(ascIter1 < ascIter2));
    }
}

TEST_SUITE("Class SideCrossIterator")
{
    TEST_CASE("Method: operator*")
    {
        MagicalContainer container;
        container.addElement(30);
        container.addElement(5);
        container.addElement(2);
        container.addElement(80);
        container.addElement(17);

        MagicalContainer::SideCrossIterator crossIter(container);
        // Order: 2 5 17 30 80
        // SideCross: 2 80 5 30 17

        // checking that the iterator is ordered
        CHECK(*crossIter == 2);
        ++crossIter;
        CHECK(*crossIter == 80);
        ++crossIter;
        CHECK(*crossIter == 5);
        ++crossIter;
        CHECK(*crossIter == 30);
        ++crossIter;
        CHECK(*crossIter == 17);

        // checking that we can't use operator* for nullptr
        ++crossIter;
        CHECK_THROWS(*crossIter);
        // checking that we can't use ++operator for nullptr
        CHECK_THROWS(++crossIter);
    }

    TEST_CASE("Comparison methods")
    {
        MagicalContainer container;
        container.addElement(30);
        container.addElement(5);
        container.addElement(2);
        container.addElement(80);
        container.addElement(17);

        MagicalContainer::SideCrossIterator crossIter1(container);
        MagicalContainer::SideCrossIterator crossIter2(container);

        // equality
        CHECK(crossIter1 == crossIter2);
        CHECK(!(crossIter1 != crossIter2));
        ++crossIter1; // increment in 1
        CHECK(crossIter1 != crossIter2);
        CHECK(!(crossIter1 == crossIter2));

        // greater then - check that it compares by location and not by value
        CHECK(crossIter1 > crossIter2);
        CHECK(!(crossIter2 > crossIter1));
        ++crossIter2; // increment in 1
        CHECK(!(crossIter1 > crossIter2));
        ++crossIter2; // increment in 2
        CHECK(crossIter2 > crossIter1);

        // less then
        CHECK(!(crossIter2 < crossIter1));
        ++crossIter1; // increment in 2
        CHECK(!(crossIter1 < crossIter2));
        ++crossIter1; // increment in 3
        CHECK(crossIter2 < crossIter1);
    }
}

TEST_SUITE("Class PrimeIterator")
{
    TEST_CASE("Method: operator*")
    {
        MagicalContainer container;
        container.addElement(101);
        container.addElement(18);
        container.addElement(3);
        container.addElement(7);
        container.addElement(28);

        MagicalContainer::PrimeIterator primeIter(container);

        // checking that the iterator is ordered
        CHECK(*primeIter == 3);
        ++primeIter;
        CHECK(*primeIter == 7);
        ++primeIter;
        CHECK(*primeIter == 101);

        // checking that we can't use operator* for nullptr
        ++primeIter;
        CHECK_THROWS(*primeIter);

        // checking that we can't use ++operator for nullptr
        CHECK_THROWS(++primeIter);
    }

    TEST_CASE("Comparison methods")
    {
        MagicalContainer container;
        container.addElement(101);
        container.addElement(18);
        container.addElement(3);
        container.addElement(7);
        container.addElement(28);

        MagicalContainer::PrimeIterator primeIter1(container);
        MagicalContainer::PrimeIterator primeIter2(container);

        // equality
        CHECK(primeIter1 == primeIter2);
        CHECK(!(primeIter1 != primeIter2));
        ++primeIter1; // increment in 1
        CHECK(primeIter1 != primeIter2);
        CHECK(!(primeIter1 == primeIter2));

        // greater then
        CHECK(primeIter1 > primeIter2);
        CHECK(!(primeIter2 > primeIter1));
        ++primeIter2; // increment in 1
        CHECK(!(primeIter1 > primeIter2));
        ++primeIter2; // increment in 2
        CHECK(primeIter2 > primeIter1);

        // less then
        CHECK(primeIter1 < primeIter2);
        CHECK(!(primeIter2 < primeIter1));
        ++primeIter1; // increment in 2
        CHECK(!(primeIter1 < primeIter2));
    }
}

TEST_SUITE("non-valid comparisons")
{
    TEST_CASE("Comparison by different iterators")
    {
        MagicalContainer container;
        container.addElement(12);
        container.addElement(2);
        container.addElement(18);
        container.addElement(29);

        MagicalContainer::AscendingIterator ascIter(container);
        MagicalContainer::SideCrossIterator crossIter(container);
        MagicalContainer::PrimeIterator primeIter(container);
        bool throwEror;

        // equality - check throw even that their value equals to 2
        CHECK_THROWS(throwEror = (ascIter == crossIter));
        CHECK_THROWS(throwEror = (ascIter == primeIter));
        CHECK_THROWS(throwEror = (primeIter == crossIter));

        // inequality - check throw even that their value isn't the same
        ++ascIter;   // equals to 12
        ++crossIter; // equals to 29
        // primeIter equals to 2
        CHECK_THROWS(throwEror = (ascIter != crossIter));
        CHECK_THROWS(throwEror = (ascIter != primeIter));
        CHECK_THROWS(throwEror = (primeIter != crossIter));

        // greater then
        CHECK_THROWS(throwEror = (ascIter > primeIter)); // correct
        CHECK_THROWS(throwEror = (primeIter > ascIter)); // not correct

        // // less then
        CHECK_THROWS(throwEror = (ascIter < crossIter));   // correct
        CHECK_THROWS(throwEror = (primeIter < ascIter));   // correct
        CHECK_THROWS(throwEror = (crossIter < primeIter)); // not correct
    }

    TEST_CASE("Comparison by different containers in AscendingIterator")
    {
        MagicalContainer container1;
        container1.addElement(12);
        container1.addElement(2);
        container1.addElement(18);
        container1.addElement(29);

        MagicalContainer container2;
        container2.addElement(18);
        container2.addElement(2);
        container2.addElement(20);
        container2.addElement(29);

        MagicalContainer::AscendingIterator ascIter1(container1);
        MagicalContainer::AscendingIterator ascIter2(container2);

        // equality - check throw even that their value equals to 2
        // CHECK_THROWS(ascIter1 == ascIter2); // correct

        // inequality - check throw even that their value isn't the same
        ++ascIter1; // equals to 12
        // ascIter2 equals to 2
        // CHECK_THROWS(ascIter1 != ascIter2); // correct

        // greater then
        // CHECK_THROWS(ascIter1 > ascIter2); // correct

        // less then
        // CHECK_THROWS(ascIter1 < ascIter2); // not correct
    }

    TEST_CASE("Comparison by different containers in SideCrossIterator")
    {
        MagicalContainer container1;
        container1.addElement(12);
        container1.addElement(2);
        container1.addElement(18);
        container1.addElement(29);

        MagicalContainer container2;
        container2.addElement(18);
        container2.addElement(2);
        container2.addElement(20);
        container2.addElement(29);

        MagicalContainer::SideCrossIterator crossIter1(container1);
        MagicalContainer::SideCrossIterator crossIter2(container2);
        bool throwEror;

        // equality - check throw even that their value equals to 2
        CHECK_THROWS(throwEror = (crossIter1 == crossIter2)); // correct

        // inequality - check throw even that their value isn't the same
        ++crossIter1; // equals to 29
        // crossIter2 equals to 2
        CHECK_THROWS(throwEror = (crossIter1 != crossIter2)); // correct

        // greater then
        CHECK_THROWS(throwEror = (crossIter1 > crossIter2)); // correct

        // less then
        CHECK_THROWS(throwEror = (crossIter1 < crossIter2)); // not correct
    }

    TEST_CASE("Comparison by different containers in PrimeIterator")
    {
        MagicalContainer container1;
        container1.addElement(12);
        container1.addElement(2);
        container1.addElement(18);
        container1.addElement(29);

        MagicalContainer container2;
        container2.addElement(18);
        container2.addElement(2);
        container2.addElement(20);
        container2.addElement(29);

        MagicalContainer::PrimeIterator primeIter1(container1);
        MagicalContainer::PrimeIterator primeIter2(container2);
        bool throwEror;

        // equality - check throw even that their value equals to 2
        CHECK_THROWS(throwEror = (primeIter1 == primeIter2)); // correct

        // inequality - check throw even that their value isn't the same
        ++primeIter1; // equals to 29
        // primeIter2 equals to 2
        CHECK_THROWS(throwEror = (primeIter1 != primeIter2)); // correct

        // greater then
        CHECK_THROWS(throwEror = (primeIter1 > primeIter2)); // correct

        // less then
        CHECK_THROWS(throwEror = (primeIter1 < primeIter2)); // not correct
    }
}