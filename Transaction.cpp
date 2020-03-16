#include "Transaction.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;
Transaction::Transaction()
{
	this->day = 0;
	this->sum = 0;
	this->type = NULL;
	this->description = NULL;

}

Transaction::Transaction(int day, int sum, char* type, char* description)
{
	this->day = day;
	this->sum = sum;
	this->type = new char[1 + strlen(type)];
	strcpy_s(this->type, 1 + strlen(type), type);
	this->description = new char[1 + strlen(description)];
	strcpy_s(this->description, 1 + strlen(description), description);

}

Transaction::Transaction(const Transaction& t)
{
	this->day = t.day;
	this->sum = t.sum;
	this->type = new char[1 + strlen(t.type)];
	strcpy_s(this->type, 1 + strlen(t.type), t.type);
	this->description = new char[1 + strlen(t.description)];
	strcpy_s(this->description, 1 + strlen(t.description), t.description);

}

Transaction::~Transaction()
{
	if (this->type)
	{
		delete[] this->type;
		this->type = NULL;

	}
	if (this->description) {
		delete[] this->description;
		this->description = NULL;
	}

}

int Transaction::get_day() {
	return this->day;
}

int Transaction::get_sum() {
	return this->sum;
}

char* Transaction::get_type() {

	return this->type;
}

char* Transaction::get_description() {

	return this->description;
}

void Transaction::set_day(int day) {
	this->day = day;
}

void Transaction::set_sum(int sum) {
	this->sum = sum;

}

void Transaction::set_type(char* type) {
	this->type = new char[1 + strlen(type)];
	strcpy_s(this->type, 1 + strlen(type), type);
}

void Transaction::set_description(char* description) {
	this->description = new char[1 + strlen(description)];
	strcpy_s(this->description, 1 + strlen(description), description);
}


Transaction& Transaction::operator=(const Transaction& t) {
	this->set_day(t.day);
	this->set_sum(t.sum);
	this->set_type(t.type);
	this->set_description(t.description);
	return *this;
}

ostream& operator<<(ostream& os, const Transaction& s)
{
	os << s.day << " " << s.sum<< " " <<s.type<<" "<<s.description;
	return os;
}

bool Transaction:: operator==(const Transaction& t) {
	return (this->day==t.day) && (this->sum==t.sum) && (strcmp(this->type,t.type) == 0) && (strcmp(this->description, t.description)==0);
}