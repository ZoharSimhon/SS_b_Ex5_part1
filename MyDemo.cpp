#include <iostream>
#include "sources/MagicalContainer.hpp"
using namespace ariel;
int main()
{
    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    container.printMagicalContainer();

    std::cout << "Size of container: " << container.size() << std::endl;

    // Remove an element from the container and display the size
    container.removeElement(17);
    container.printMagicalContainer();
    std::cout << "Size of container after removing an element: " << container.size() << std::endl;
    container.printPrimes();
}