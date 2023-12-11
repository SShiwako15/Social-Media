/*
* Project Description:
In this project, you will design and implement a simplified social media network
using the principles of graph data structures. The network will consist of
individuals and relationships between them will be modeled as edges in a graph.
Each person will be represented as a node (vertex), and relationships
(friendships) will be represented as edges between nodes.
Key Components:
1. Person Class:
- Create a Person class to represent each individual in the social network.
- Include member variables for the person's name and a set of friends or
connections.
2. SocialMediaNetwork Class:
- Implement a SocialMediaNetwork class to manage the entire social network.
- Utilize the classes included in the Examples of Chapter 11 Graph to complete
the implementation of this project.
3. Functionality:
- Adding People:
- Implement a function to add individuals to the social network dynamically.
- Ensure that a person is not added more than once.
- Adding Friendships:
- Create a function to establish friendships between individuals.
- Ensure that friendships are bidirectional; if person A is friends with person B,
then person B should also be friends with person A.
- Displaying Friends:
- Develop a function to display the friends of a particular person.
- Provide feedback if the person is not found in the network.
- Sorting:
- Implement a sorting algorithm of your choice to organize the relationships
within each person's friend list.
- Displaying the Entire Network:
CMPS 231 – Data Structures | Group Project II | Fall Semester 2023
- Develop a function to display the entire social media network, showing each
person and their respective connections.
4. Input Validation:
- Ensure that the program validates inputs, such as ensuring the number of
movies or the number of friends is non-negative.
*/

#include <iostream>
#include "unorderedLinkedList.h"

