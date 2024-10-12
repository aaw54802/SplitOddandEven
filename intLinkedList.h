
#include "linkedList.h"
#include "unorderedLinkedList.h"

class intLinkedList : public unorderedLinkedList<int> {
public:
    void splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList);
};

void intLinkedList::splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList) {
    nodeType<int>* current = this->first;  // Pointer to traverse the original list
    nodeType<int>* evenTail = nullptr;     // Tail of the evensList
    nodeType<int>* oddTail = nullptr;      // Tail of the oddsList

    // Traverse the original list and move nodes to evensList or oddsList
    while (current != nullptr) {
        nodeType<int>* nextNode = current->link;  // Save the next node
        current->link = nullptr;  // Disconnect the current node from the list

        // Check if the current node contains an even or odd value
        if (current->info % 2 == 0) {
            // Add to the evens list
            if (evensList.first == nullptr) {
                evensList.first = current;
                evenTail = current;
            }
            else {
                evenTail->link = current;
                evenTail = current;
            }
        }
        else {
            // Add to the odds list
            if (oddsList.first == nullptr) {
                oddsList.first = current;
                oddTail = current;
            }
            else {
                oddTail->link = current;
                oddTail = current;
            }
        }

        // Move to the next node
        current = nextNode;
    }

    // Update last and count for both evensList and oddsList
    if (evenTail != nullptr) {
        evensList.last = evenTail;
    }
    evensList.count = this->count;

    if (oddTail != nullptr) {
        oddsList.last = oddTail;
    }
    oddsList.count = this->count;

    // The original list is now empty
    this->first = nullptr;
    this->last = nullptr;
    this->count = 0;
}
