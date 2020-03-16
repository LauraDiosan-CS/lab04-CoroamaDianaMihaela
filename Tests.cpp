#include "Tests.h"
#include "Transaction.h"
#include "Repo.h"
#include <cassert>

void test_transaction_gets() {
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Transaction transaction = Transaction(1, 23, type, description);
	assert(transaction.get_day() == 1);
	assert(transaction.get_sum() == 23);
	assert(strcmp(transaction.get_type(),"in")==0);
	assert(strcmp(transaction.get_description(),"descriere")==0);
	

}

void test_transaction_sets() {
	char* type = new char[1 + strlen("in")];
	strcpy_s(type, 1 + strlen("in"), "in");
	char* description = new char[1 + strlen("descriere")];
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Transaction transaction = Transaction(1, 23, type, description);
	
	transaction.set_day(2);
	transaction.set_sum(24);
	type = new char[1 + strlen("out")];
	description = new char[1 + strlen("descriere_2")];

	strcpy_s(description, 1 + strlen("descriere_2"), "descriere_2");
	strcpy_s(type, 1 + strlen("out"), "out");


	transaction.set_description(description);
	transaction.set_type(type);
	
	
	assert(transaction.get_day() == 2);
	assert(transaction.get_sum() == 24);
	assert(strcmp(transaction.get_type(), "out") == 0);
	assert(strcmp(transaction.get_description(), "descriere_2") == 0);




}

void test_repo() {
	Repo r = Repo();
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");

	
	Transaction transaction_1= Transaction(1, 23, type, description);
	r.add_transaction(transaction_1);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("descriere_2")];

	strcpy_s(type_2, 1 + strlen("out"), "out");

	strcpy_s(description_2, 1 + strlen("descriere_2"), "descriere_2");


	Transaction transaction_2 = Transaction(1, 23, type_2, description_2);
	r.add_transaction(transaction_2);

	

	assert(r.get_size() == 2);
	assert(r.get_all()[0] == transaction_1);
	assert(r.get_all()[1] == transaction_2);

	
}