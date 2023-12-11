#ifndef H_SocialMediaNetwork
#define H_SocialMediaNetwork
//SocialMediaNetwork class to manage the entire social network
#include <iostream>
#include "Person.h"
#include <fstream>
#include <iomanip>
#include "linkedList.h"
#include "unorderedLinkedList.h"
#include "linkedQueue.h"

class SocialMediaNetwork : public graphType
{
public:
	void createNetwork();
	void printNetwork();
	void deleteNetwork();
	void addPerson(string, string);
	void deletePerson(string);
	void addFriend(string, string);
	void deleteFriend(string, string);
	void printFriends(string);
	void printPerson(string);

private:
	unorderedLinkedList<Person> network;

};

#endif