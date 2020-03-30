#pragma once
#include "Transaction.h"
#include <cstddef>

class Repo {
private:
	int n;
	Transaction transactions[10];
	int money_paid;
public:
	Repo();
	~Repo();
	void add_transaction(Transaction t);
	Transaction* get_all();
	int get_size();
	int get_money_paid();
	void delete_transaction(Transaction t);
	/*bool search_transaction(const Transaction &t);*/
	void update_transaction(Transaction t1, Transaction t2);
	
};
