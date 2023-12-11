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
	void addPerson(string, int);
	void deletePerson(string);
	void addFriend(string, string);
	void deleteFriend(string, string);
	void printFriends(string);
	void printPerson(string);

private:
	unorderedLinkedList<Person> network;
};

void SocialMediaNetwork::createNetwork()
{
	string name;
	int age;
	ifstream infile;
	infile.open("network.txt");
	if (!infile)
	{
		cout << "Cannot open input file." << endl;
		return;
	}
	while (!infile.eof())
	{
		infile >> name;
		infile >> age;
		addPerson(name, age);
	}
	infile.close();
}

void SocialMediaNetwork::printNetwork()
{
	network.print();
}

void SocialMediaNetwork::deleteNetwork()
{
	network.destroyList();
}

void SocialMediaNetwork::addPerson(string name, int age)
{
	Person p(name, age);
	network.insertLast(p);
}

void SocialMediaNetwork::deletePerson(string username)
{
	Person p;
	p.setName(username);
	network.deleteNode(p);
}

void SocialMediaNetwork::addFriend(string username1, string username2)
{
	Person p1;
	Person p2;
	p1.setName(username1);
	p2.setName(username2);
	network.insertLast(p1);
	network.insertLast(p2);
}

void SocialMediaNetwork::deleteFriend(string username1, string username2)
{
	Person p1;
	Person p2;
	p1.setName(username1);
	p2.setName(username2);
	network.deleteNode(p1);
	network.deleteNode(p2);
}

void SocialMediaNetwork::printFriends(string username)
{
	Person p;
	p.setName(username);
	network.printFriends(p);
}

#endif