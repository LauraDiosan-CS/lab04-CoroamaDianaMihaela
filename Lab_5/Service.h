#pragma once
#include "RepoSTL.h"
#include "Transaction.h"
#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>

bool tempFunction(T param, vector<Transaction> b, int i, int c = 0) {
	if (std::is_same<T, char*>::value)
		return strcmp((char*)param, b[i].get_type()) == 0;
	else if (std::is_same<T, int>::value && c == 0)
		return b[i].get_day() == (int)param;
	else
		return b[i].get_day() >= (int)param && b[i].get_day() <= c;
};


template <typename D>

bool show_function_bool(D param, vector<Transaction> b, int i, int op = 0) {
	if (std::is_same<D, char*>::value)
		return strcmp((char*)param, b[i].get_type()) == 0;
	else if (std::is_same<D, int>::value && op == 1)
		return b[i].get_sum() == (int)param;
	else
		return b[i].get_sum() >= (int)param;

};


template <typename G>

bool sum_sold_bool(G param, vector<Transaction> b, int i)
{
	if (std::is_same<G, char*>::value)
		return strcmp((char*)param, b[i].get_type()) == 0;
	else if (std::is_same<G, const char*>::value)
		return strcmp((const char*)param, b[i].get_type()) == 0;
	else if (std::is_same<G, int>::value )
		return b[i].get_day() == (int)param;
	

};

template <typename H>

bool function_keep_bool(H param, vector<Transaction> b, int i,int sum)
{
	if (sum != 0) {

		
		return (strcmp((char*)param, b[i].get_type()) != 0) || (b[i].get_sum() > sum);
	}
	else
	{
		return strcmp((char*)param, b[i].get_type()) != 0;
	}


};

class Service {
	RepoSTL r;
public:
	///ATTENTION:
	///TEMPLATE PT DELETE: FOLOSITOARE LA MINIMALIZAREA CODULUI
	template <typename B>

	void delete_transaction_updated(B param,int d=0)
	{
		int size = this->get_size_repo();
		vector<Transaction> transactions = this->get_all();
		for (int i = 0; i < size;) {
			if (tempFunction(param, transactions, i,d)) {
				this->r.delete_transaction(transactions[i]);
				size--;
			}
			else
			{
				i++;
			}
		}

	};

	///-----------------------------------------------

	template <typename C>

	void array_with_transactions(C param, Transaction transactions[], int& length,int op=0)
	{
		length = 0;
		int size = this->r.get_size();
		Transaction auxiliar;
		vector<Transaction> full_transactions = this->r.get_all();
		for (int i = 0; i < size; i++)
		{	
			if (show_function_bool(param,full_transactions,i,op))
			{
				auxiliar = full_transactions[i];
				transactions[length++] = auxiliar;
			}
		}

	};

	//--------------------------------------------

	template <typename F>

	int sum_sold(F param, int op=0)
	{
		int counter = 0;
		int size = this->r.get_size();
		vector<Transaction> transactions = this->r.get_all();
		for (int i = 0; i < size; i++) {
			if (sum_sold_bool(param,transactions,i)) {
				if (op == 1) {
					if (sum_sold_bool("in", transactions, i))
						counter += transactions[i].get_sum();
					else
						counter -= transactions[i].get_sum();
				}
				else counter += transactions[i].get_sum();
			}
		}
		return counter;


	};

	//---------------------------------------------

	template <typename E>

	void keep_by_param(E param,int sum=0) {

		int size = this->r.get_size();
		vector<Transaction> transactions = this->r.get_all();
		for (int i = 0; i < size; ) {
			if (function_keep_bool(param,transactions,i,sum)) {
				this->r.delete_transaction(transactions[i]);
				size--;
			}
			else {
				i++;
			}

		}
	};

	//--------------------------------------------
	Service();
	Service(RepoSTL repo);


	//-------------------------------------------

	void add_transaction(int day, int sum, char* type, char* description);
	vector<Transaction> get_all();

	///--------------------------------------------

	int get_size_repo();


	///--------------------

	void delete_transaction_CHAR_updated(char* type);
	void delete_transaction_day_updated(int day);
	void delete_transaction_b_update(int day1, int day2);

	//-----------------------------------

	void replace_sum_in_transaction(int replaced_sum, int day, char* type, char* description);
	void array_with_transactions_by_type(char* type,Transaction transactions[],int &length);
	void array_with_transaction_sum_b(Transaction transactions[], int &length,int sum);
	void array_with_transaction_sum_equal(Transaction transactions[], int& length,int sum);

	///------------------------------------------


	int sold_by_day(int day);
	int sum_by_type(char* type);
	Transaction most_valuable_by_day(int day);
	void keep_by_type(char* type);
	void keep_by_type_and_sum(char* type,int sum);

	

	
};

