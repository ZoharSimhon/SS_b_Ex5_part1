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
    container.addElement(29);

    container.printMagicalContainer();

    std::cout << "Size of container: " << container.size() << std::endl;

    // Remove an element from the container and display the size
    container.removeElement(29);
    container.printMagicalContainer();
    std::cout << "Size of container after removing an element: " << container.size() << std::endl;
    container.printPrimes();

    // Use AscendingIterator to display elements in ascending order
    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter(container);

    for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
    {
        std::cout << *it << ' '; // 2 3 9 17 25
    }
    std::cout << std::endl;
    auto it = ascIter.begin();
    auto it2 = ascIter.begin();
    ++it2;
    if(it<it2){
        cout <<"LT"<<endl;
    }
    if(it2<it){
        cout <<"NLT"<<endl;
    }
    ++it;
        if(it==it2){
        cout <<"EQ"<<endl;
    }
    if(it2!=it){
        cout <<"NEq"<<endl;
    }
    ++it;
    if(it>it2){
        cout <<"GT"<<endl;
    }
    if(it2>it){
        cout <<"NGT"<<endl;
    }

    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 3 17 
    }
    std::cout << std::endl;

    auto itp = primeIter.begin();
    auto itp2 = primeIter.begin();
    ++itp2;
    if(itp<itp2){
        cout <<"LT"<<endl;
    }
    if(itp2<itp){
        cout <<"NLT"<<endl;
    }
    ++itp;
        if(itp==itp2){
        cout <<"EQ"<<endl;
    }
    if(itp2!=itp){
        cout <<"NEq"<<endl;
    }
    ++itp;
    if(itp>itp2){
        cout <<"GT"<<endl;
    }
    if(itp2>itp){
        cout <<"NGT"<<endl;
    }


}