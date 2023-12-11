#ifndef H_Person
#define H_Person

#include <iostream>
#include "graphType.h"
using namespace std;

class Person:public graphType
{
protected:
	string name;
	int age;

public:
	Person();
	Person(string, int);
	Person(const Person&);
	~Person();

	void setName(string);
	void setAge(int);

	string getName() const;
	int getAge() const;

	void print() const;
	void printName() const;
	void printAge() const;

	Person& operator=(const Person&);
	bool operator==(const Person&) const;
	bool operator!=(const Person&) const;
	bool operator<(const Person&) const;
	bool operator<=(const Person&) const;
	bool operator>(const Person&) const;
	bool operator>=(const Person&) const;

	friend ostream& operator<<(ostream&, const Person&);
	friend istream& operator>>(istream&, Person&);
};

Person::Person()
{
	name = "";
	age = 0;
}

Person::Person(string n, int a)
{
	name = n;
	age = a;
}

Person::Person(const Person& p)
{
	name = p.name;
	age = p.age;
}

Person::~Person()
{
}

void Person::setName(string n)
{
	name = n;
}

void Person::setAge(int a)
{
	age = a;
}

string Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

void Person::print() const
{
	cout << name << " " << age << endl;
}

void Person::printName() const
{
	cout << name << endl;
}

void Person::printAge() const
{
	cout << age << endl;
}

Person& Person::operator=(const Person& p)
{
	name = p.name;
	age = p.age;
	return *this;
}

bool Person::operator==(const Person& p) const
{
	return (name == p.name && age == p.age);
}

bool Person::operator!=(const Person& p) const
{
	return (name != p.name || age != p.age);
}

bool Person::operator<(const Person& p) const
{
	return (name < p.name || (name == p.name && age < p.age));
}

bool Person::operator<=(const Person& p) const
{
	return (name < p.name || (name == p.name && age <= p.age));
}

bool Person::operator>(const Person& p) const
{
	return (name > p.name || (name == p.name && age > p.age));
}

bool Person::operator>=(const Person& p) const
{
	return (name > p.name || (name == p.name && age >= p.age));
}

ostream& operator<<(ostream& os, const Person& p)
{
	os << p.name << " " << p.age << endl;
	return os;
}

istream& operator>>(istream& is, Person& p)
{
	is >> p.name >> p.age;
	return is;
}

#endif
