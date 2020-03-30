#include "Tests.h"
#include "Transaction.h"
#include "Service.h"
#include "RepoSTL.h"
#include <cassert>


void Tests_transaction::test_transaction_gets() {
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Transaction transaction = Transaction(1, 23, type, description);
	assert(transaction.get_day() == 1);
	assert(transaction.get_sum() == 23);
	assert(strcmp(transaction.get_type(), "in") == 0);
	assert(strcmp(transaction.get_description(), "descriere") == 0);


}

void Tests_transaction::test_transaction_sets() {
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];


	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Transaction transaction = Transaction(1, 23, type, description);

	transaction.set_day(2);
	transaction.set_sum(24);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("descriere_2")];

	strcpy_s(description_2, 1 + strlen("descriere_2"), "descriere_2");
	strcpy_s(type_2, 1 + strlen("out"), "out");


	transaction.set_description(description_2);
	transaction.set_type(type_2);


	assert(transaction.get_day() == 2);
	assert(transaction.get_sum() == 24);
	assert(strcmp(transaction.get_type(), "out") == 0);
	assert(strcmp(transaction.get_description(), "descriere_2") == 0);

	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;
}

void Tests_transaction::test_transaction_operator()
{
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];


	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Transaction transaction_1 = Transaction(1, 23, type, description);
	Transaction transaction_2 = Transaction(1, 23, type, description);


	assert(transaction_1 == transaction_2);
	transaction_2.set_day(2);
	assert(not(transaction_1 == transaction_2));
	delete[] type;
	delete[] description;


}

void Tests_transaction::test_transaction()
{
	this->test_transaction_gets();
	this->test_transaction_sets();
	this->test_transaction_operator();
}


//----------------------------------------------

void Tests_repo::test_repo_add() {

	RepoSTL r = RepoSTL();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Transaction transaction_1 = Transaction(1, 23, type, description);

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

	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;
}

void Tests_repo::test_repo_delete()
{
	RepoSTL r = RepoSTL();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Transaction transaction_1 = Transaction(1, 23, type, description);

	r.add_transaction(transaction_1);


	assert(r.get_size() == 1);
	assert(r.get_all()[0] == transaction_1);


	r.delete_transaction(transaction_1);

	assert(r.get_size() == 0);

	delete[] type;
	delete[] description;

}

void Tests_repo::test_repo_update()
{
	RepoSTL r = RepoSTL();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	Transaction transaction_1 = Transaction(1, 23, type, description);

	r.add_transaction(transaction_1);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("descriere_2")];

	strcpy_s(type_2, 1 + strlen("out"), "out");

	strcpy_s(description_2, 1 + strlen("descriere_2"), "descriere_2");


	Transaction transaction_2 = Transaction(2, 24, type_2, description_2);

	r.update_transaction(transaction_1, transaction_2);

	assert(r.get_size() == 1);
	assert(r.get_all()[0] == transaction_2);


	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;
}

void Tests_repo::test_repo()
{
	this->test_repo_delete();
	this->test_repo_add();
	this->test_repo_update();
}

///------------------------------------------------


void Tests_service::test_service()
{
	this->test_add_transaction();
	this->test_delete__transaction_by_day();
	this->test_delete_transaction_between_days();
	this->test_delete_transaction_by_type();
	this->test_replace_sum_in_transaction();

	this->test_array_with_transaction_by_type();
	this->test_array_with_transaction_over_value();
	this->test_array_with_transaction_equal_value();
	this->test_sold_by_day();
	this->test_sum_by_type();
	this->test_keep_by_type();
	this->test_keep_by_type_and_sum();
}



void Tests_service::test_add_transaction()
{
	Service s = Service();
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("descriere")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("descriere"), "descriere");


	s.add_transaction(1, 2, type, description);

	assert(s.get_size_repo() == 1);

	delete[] type;
	delete[] description;

}



void Tests_service::test_delete__transaction_by_day()
{
	Service s = Service();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("pizza")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("pizza"), "pizza");

	s.add_transaction(1, 2, type, description);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("yogurt")];

	strcpy_s(type_2, 1 + strlen("out"), "out");

	strcpy_s(description_2, 1 + strlen("yogurt"), "yogurt");


	s.add_transaction(2, 3, type_2, description_2);

	assert(s.get_size_repo() == 2);
	s.delete_transaction_day_updated(1);
	assert(s.get_size_repo() == 1);
	assert(s.get_all()[0].get_day() == 2);
	assert(s.get_all()[0].get_sum() == 3);
	assert(strcmp(s.get_all()[0].get_type(), type_2) == 0);
	assert(strcmp(s.get_all()[0].get_description(), description_2) == 0);

	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;

}

void Tests_service::test_delete_transaction_between_days()
{
	Service s = Service();
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("pizza")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("pizza"), "pizza");

	s.add_transaction(1, 2, type, description);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("yogurt")];

	strcpy_s(type_2, 1 + strlen("out"), "out");

	strcpy_s(description_2, 1 + strlen("yogurt"), "yogurt");


	s.add_transaction(5, 3, type_2, description_2);

	assert(s.get_size_repo() == 2);
	s.delete_transaction_b_update(1, 3);
	assert(s.get_size_repo() == 1);
	assert(s.get_all()[0].get_day() == 5);
	assert(s.get_all()[0].get_sum() == 3);
	assert(strcmp(s.get_all()[0].get_type(), type_2) == 0);
	assert(strcmp(s.get_all()[0].get_description(), description_2) == 0);

	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;

}

void Tests_service::test_delete_transaction_by_type()
{
	Service s = Service();
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("pizza")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("pizza"), "pizza");

	s.add_transaction(1, 2, type, description);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("yogurt")];

	strcpy_s(type_2, 1 + strlen("out"), "out");

	strcpy_s(description_2, 1 + strlen("yogurt"), "yogurt");


	s.add_transaction(5, 3, type_2, description_2);


	char* type_3 = new char[1 + strlen("in")];
	strcpy_s(type_3, 1 + strlen("in"), "in");

	assert(s.get_size_repo() == 2);
	s.delete_transaction_CHAR_updated(type_3);
	assert(s.get_size_repo() == 1);
	assert(s.get_all()[0].get_day() == 5);
	assert(s.get_all()[0].get_sum() == 3);
	assert(strcmp(s.get_all()[0].get_type(), type_2) == 0);
	assert(strcmp(s.get_all()[0].get_description(), description_2) == 0);


	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;
	delete[] type_3;

}

void Tests_service::test_replace_sum_in_transaction()
{
	Service s = Service();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("pizza")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("pizza"), "pizza");
	
	
	s.add_transaction(1, 2, type, description);

	int sum_replace = 24;
	

	Transaction t(1, sum_replace, type, description);
	s.replace_sum_in_transaction(sum_replace,1, type, description);

	assert(s.get_all()[0] == t);
	assert(s.get_all()[0].get_sum() == sum_replace);
	assert(s.get_all()[0].get_day() == 1);
	assert(strcmp(s.get_all()[0].get_type(), type) == 0);
	assert(strcmp(s.get_all()[0].get_description(), description) == 0);


	delete[] type;
	delete[] description;

}




void Tests_service::test_array_with_transaction_by_type()
{
	Service s = Service();
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("pizza")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("pizza"), "pizza");

	Transaction t1 = Transaction(1, 2, type, description);
	s.add_transaction(1, 2, type, description);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("yogurt")];

	strcpy_s(type_2, 1 + strlen("out"), "out");
	strcpy_s(description_2, 1 + strlen("yogurt"), "yogurt");

	Transaction t2 = Transaction(2, 3, type_2, description_2);
	s.add_transaction(2, 3, type_2, description_2);


	char* type_3 = new char[1 + strlen("in")];
	char* description_3 = new char[1 + strlen("fruit")];

	strcpy_s(type_3, 1 + strlen("in"), "in");
	strcpy_s(description_3, 1 + strlen("fruit"), "fruit");

	Transaction t3 = Transaction(3, 4, type_3, description_3);
	s.add_transaction(3, 4, type_3, description_3);

	char* type_4 = new char[1 + strlen("in")];
	strcpy_s(type_4, 1 + strlen("in"), "in");

	Transaction transactions[100];
	int length = 0;
	s.array_with_transactions_by_type(type_4, transactions, length);
	assert(length == 2);
	assert(transactions[0] == t1);
	assert(transactions[1] == t3);




	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;
	delete[] type_3;
	delete[] type_4;
}

void Tests_service::test_array_with_transaction_over_value()
{
	Service s = Service();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("pizza")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("pizza"), "pizza");

	Transaction t1 = Transaction(1, 10, type, description);
	s.add_transaction(1, 10, type, description);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("yogurt")];

	strcpy_s(type_2, 1 + strlen("out"), "out");
	strcpy_s(description_2, 1 + strlen("yogurt"), "yogurt");

	Transaction t2 = Transaction(2, 25, type_2, description_2);
	s.add_transaction(2, 25, type_2, description_2);


	char* type_3 = new char[1 + strlen("in")];
	char* description_3 = new char[1 + strlen("fruit")];

	strcpy_s(type_3, 1 + strlen("in"), "in");
	strcpy_s(description_3, 1 + strlen("fruit"), "fruit");

	Transaction t3 = Transaction(3, 30, type_3, description_3);
	s.add_transaction(3, 30, type_3, description_3);



	Transaction transactions[100];
	int length = 0;
	int sum = 20;
	s.array_with_transaction_sum_b(transactions, length, sum);
	assert(length == 2);
	assert(transactions[0] == t2);
	assert(transactions[1] == t3);




	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;
	delete[] type_3;

}

void Tests_service::test_array_with_transaction_equal_value()
{
	Service s = Service();
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("pizza")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("pizza"), "pizza");

	Transaction t1 = Transaction(1, 10, type, description);
	s.add_transaction(1, 10, type, description);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("yogurt")];

	strcpy_s(type_2, 1 + strlen("out"), "out");
	strcpy_s(description_2, 1 + strlen("yogurt"), "yogurt");

	Transaction t2 = Transaction(2, 26, type_2, description_2);
	s.add_transaction(2, 26, type_2, description_2);


	char* type_3 = new char[1 + strlen("in")];
	char* description_3 = new char[1 + strlen("fruit")];

	strcpy_s(type_3, 1 + strlen("in"), "in");
	strcpy_s(description_3, 1 + strlen("fruit"), "fruit");

	Transaction t3 = Transaction(3, 26, type_3, description_3);
	s.add_transaction(3, 26, type_3, description_3);



	Transaction transactions[100];
	int length = 0;
	int sum = 26;
	s.array_with_transaction_sum_equal(transactions, length, sum);
	assert(length == 2);
	assert(transactions[0] == t2);
	assert(transactions[1] == t3);




	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;
	delete[] type_3;


}



void Tests_service::test_sold_by_day()
{	
	Service s = Service();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("pizza")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("pizza"), "pizza");


	s.add_transaction(1, 10, type, description);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("yogurt")];

	strcpy_s(type_2, 1 + strlen("out"), "out");
	strcpy_s(description_2, 1 + strlen("yogurt"), "yogurt");

	
	s.add_transaction(1, 5, type_2, description_2);


	char* type_3 = new char[1 + strlen("in")];
	char* description_3 = new char[1 + strlen("fruit")];

	strcpy_s(type_3, 1 + strlen("in"), "in");
	strcpy_s(description_3, 1 + strlen("fruit"), "fruit");

	Transaction t3 = Transaction(3, 26, type_3, description_3);
	s.add_transaction(3, 26, type_3, description_3);



	int sold = s.sold_by_day(1);
	assert(sold == 5);
	int sold_2 = s.sold_by_day(3);
	assert(sold_2 == 26);



	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;
	delete[] type_3;

}

void Tests_service::test_sum_by_type()
{
	Service s = Service();
	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("pizza")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("pizza"), "pizza");

	
	s.add_transaction(1, 13, type, description);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("yogurt")];

	strcpy_s(type_2, 1 + strlen("out"), "out");
	strcpy_s(description_2, 1 + strlen("yogurt"), "yogurt");

	
	s.add_transaction(2, 3, type_2, description_2);


	char* type_3 = new char[1 + strlen("in")];
	char* description_3 = new char[1 + strlen("fruit")];

	strcpy_s(type_3, 1 + strlen("in"), "in");
	strcpy_s(description_3, 1 + strlen("fruit"), "fruit");


	s.add_transaction(3, 2, type_3, description_3);

	char* type_4 = new char[1 + strlen("in")];
	strcpy_s(type_4, 1 + strlen("in"), "in");

	int sum = s.sum_by_type(type_4);
	assert(sum == 15);
	




	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;
	delete[] type_3;
	delete[] type_4;
}

void Tests_service::test_keep_by_type()
{
	Service s = Service();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("pizza")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("pizza"), "pizza");

	Transaction t1=Transaction(1, 2, type, description);
	s.add_transaction(1, 2, type, description);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("yogurt")];

	strcpy_s(type_2, 1 + strlen("out"), "out");
	strcpy_s(description_2, 1 + strlen("yogurt"), "yogurt");

	Transaction t2 = Transaction(5, 3, type_2, description_2);
	s.add_transaction(5, 3, type_2, description_2);

	char* type_3 = new char[1 + strlen("in")];
	char* description_3 = new char[1 + strlen("fruit")];

	strcpy_s(type_3, 1 + strlen("in"), "in");
	strcpy_s(description_3, 1 + strlen("fruit"), "fruit");

	Transaction t3 = Transaction(3, 4, type_3, description_3);
	s.add_transaction(3, 4, type_3, description_3);

	char* type_4 = new char[1 + strlen("in")];
	strcpy_s(type_4, 1 + strlen("in"), "in");

	
	s.keep_by_type(type_4);
	assert(s.get_size_repo() == 2);
	assert(s.get_all()[0] == t1);
	assert(s.get_all()[1] == t3);


	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;
	delete[] type_3;
	delete[] type_4;
}

void Tests_service::test_keep_by_type_and_sum()
{
	Service s = Service();

	char* type = new char[1 + strlen("in")];
	char* description = new char[1 + strlen("pizza")];

	strcpy_s(type, 1 + strlen("in"), "in");
	strcpy_s(description, 1 + strlen("pizza"), "pizza");

	Transaction t1 = Transaction(1, 27, type, description);
	s.add_transaction(1, 27, type, description);

	char* type_2 = new char[1 + strlen("out")];
	char* description_2 = new char[1 + strlen("yogurt")];

	strcpy_s(type_2, 1 + strlen("out"), "out");
	strcpy_s(description_2, 1 + strlen("yogurt"), "yogurt");

	Transaction t2 = Transaction(5, 3, type_2, description_2);
	s.add_transaction(5, 3, type_2, description_2);

	char* type_3 = new char[1 + strlen("in")];
	char* description_3 = new char[1 + strlen("fruit")];

	strcpy_s(type_3, 1 + strlen("in"), "in");
	strcpy_s(description_3, 1 + strlen("fruit"), "fruit");

	Transaction t3 = Transaction(3, 27, type_3, description_3);
	s.add_transaction(3, 27, type_3, description_3);

	char* type_4 = new char[1 + strlen("in")];
	strcpy_s(type_4, 1 + strlen("in"), "in");

	int sum = 27;

	s.keep_by_type_and_sum(type_4,27);
	assert(s.get_size_repo() == 2);
	assert(s.get_all()[0] == t1);
	assert(s.get_all()[1] == t3);


	delete[] type;
	delete[] description;
	delete[] type_2;
	delete[] description_2;
	delete[] type_3;
	delete[] type_4;
}




