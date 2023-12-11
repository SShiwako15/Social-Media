#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList  

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList : public linkedListType<Type>

{
public:
    bool search(const Type& searchItem) const;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the 
    //               list, otherwise the value false is 
    //               returned.

    void insertFirst(const Type& newItem);

    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    //               inserted at the beginning of the list,
    //               last points to the last node in the  
    //               list, and count is incremented by 1.

    void insertLast(const Type& newItem);
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem 
    //               is inserted at the end of the list,
    //               last points to the last node in the 
    //               list, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing 
    //               deleteItem is deleted from the list.
    //               first points to the first node, last
    //               points to the last node of the updated 
    //               list, and count is decremented by 1.
};


template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
    nodeType<Type>* current = this->first; //pointer to traverse the list
    bool found = false;

    // current = first; //set current to point to the first 
                      //node in the list

    while (current != nullptr && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type>* newNode = new nodeType<Type>; // Create a new node

    newNode->info = newItem;        // Store the new item in the node
    newNode->link = this->first;     // Insert newNode before first

    this->first = newNode;           // Make first point to the actual first node
    this->count++;                   // Increment count

    if (this->last == nullptr)       // If the list was empty, newNode is also the last node
        this->last = newNode;
}


template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type>* newNode = new nodeType<Type>; // Create a new node

    newNode->info = newItem;     // Store the new item in the node
    newNode->link = nullptr;      // Set the link field of newNode to nullptr

    if (this->first == nullptr)   // If the list is empty, newNode is both the first and last node
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;             // Increment count
    }
    else                           // The list is not empty, insert newNode after last
    {
        this->last->link = newNode; // Insert newNode after last
        this->last = newNode;       // Make last point to the actual last node
        this->count++;             // Increment count
    }
}



template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type>* current = this->first; // Pointer to traverse the list
    nodeType<Type>* trailCurrent = nullptr; // Pointer just before current
    bool found = false;

    if (this->first == nullptr) // Case 1: The list is empty.
    {
        cout << "Cannot delete from an empty list." << endl;
    }
    else
    {
        if (this->first->info == deleteItem) // Case 2: Node to be deleted is the first node
        {
            current = this->first;
            this->first = this->first->link;
            this->count--;

            if (this->first == nullptr) // The list has only one node
                this->last = nullptr;

            delete current;
        }
        else // Case 3: Search the list for the node with the given info
        {
            found = false;
            trailCurrent = this->first; // Set trailCurrent to point to the first node
            current = this->first->link; // Set current to point to the second node

            while (current != nullptr && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                {
                    found = true;
                }
            }

            if (found) // If found, delete the node
            {
                trailCurrent->link = current->link;
                this->count--;

                if (this->last == current) // Node to be deleted was the last node
                {
                    this->last = trailCurrent; // Update the value of last
                }

                delete current; // Delete the node from the list
            }
            else
            {
                cout << "The item to be deleted is not in the list." << endl;
            }
        }
    }
}
#endif