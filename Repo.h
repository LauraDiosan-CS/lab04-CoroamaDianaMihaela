#pragma once
#include "Transaction.h"
#include <cstddef>
class Repo {
private:
	int n;
	Transaction transactions[10];
public:
	Repo();
	~Repo();
	void add_transaction(Transaction t);
	Transaction* get_all();
	int get_size();
};
