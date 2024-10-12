#include <iostream>
#include "intLinkedList.h"

int main() {
    intLinkedList list, evensList, oddsList;
    int number;

    // Input integers into the list
    std::cout << "Enter integers ending with -999" << std::endl;
    std::cin >> number;
    while (number != -999) {
        list.insertLast(number);
        std::cin >> number;
    }

    // Use the split function
    list.splitEvensOddsList(evensList, oddsList);

    // Use iterators to display the lists
    std::cout << "evensList: ";
    for (auto it = evensList.begin(); it != evensList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "oddsList: ";
    for (auto it = oddsList.begin(); it != oddsList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
