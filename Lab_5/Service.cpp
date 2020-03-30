//adăugarea unei tranzacții în lista de tranzacții
//o ex.adaugă 100 out pizza - este adăugată o tranzație de tip out în valoarea de
//100 RON pentru ziua curentă cu descrierea ”pizza”
//o ex.inserează 25 100 in salar - inserează o tranzacție de tip in pentru ziua 25 în
//valaorea de 100 RON cu descrierea salar

#include "Service.h"
#include "Transaction.h"
#include <iostream>
#include <type_traits>
#include <chrono>
using namespace std;



Service::Service()
{
	this->r = RepoSTL();
	
}

Service::Service(RepoSTL repo)
{
	this->r = repo;
}

void Service::add_transaction(int day, int sum, char* type, char* description) {

	Transaction t = Transaction(day, sum, type, description);
	this->r.add_transaction(t);


}


vector<Transaction> Service::get_all()
{
	return this->r.get_all();

}

int Service::get_size_repo()
{
	return this->r.get_size();
}


void Service::delete_transaction_CHAR_updated(char* type)
{///Ia tipul introdus si sterge toate tranzactiile cu acel tip
	this->delete_transaction_updated(type);
}

void Service::delete_transaction_day_updated(int day)
{
	this->delete_transaction_updated(day);
}

void Service::delete_transaction_b_update(int day1, int day2)
{
	this->delete_transaction_updated(day1, day2);
}

void Service::replace_sum_in_transaction(int replaced_sum, int day, char* type, char* description)
{
	int size = this->r.get_size();
	vector<Transaction> transactions = this->r.get_all();
	for (int i = 0; i < size; i++) {
		if (transactions[i].get_day() == day && strcmp(transactions[i].get_type(), type) == 0 && strcmp(transactions[i].get_description(), description) == 0)
		{
			Transaction old_transaction=Transaction(day, transactions[i].get_sum(), type, description);
			Transaction new_transaction=Transaction(day ,replaced_sum,type,description);
			this->r.update_transaction(old_transaction, new_transaction);
		}
			
	}

}





void Service::array_with_transactions_by_type(char* type, Transaction transactions[], int& length)
{
	this->array_with_transactions(type, transactions, length);
}

void Service::array_with_transaction_sum_b(Transaction transactions[], int& length, int sum)
{

	this->array_with_transactions(sum, transactions, length);
}

void Service::array_with_transaction_sum_equal(Transaction transactions[], int& length, int sum)
{
	int op = 1;
	this->array_with_transactions(sum, transactions, length, op);
}



int Service::sold_by_day(int day)
{
	int sold = this->sum_sold(day,1);
	return sold;

}

int Service::sum_by_type(char* type)
{
	int sum = this->sum_sold(type);
	return sum;

}

Transaction Service::most_valuable_by_day(int day)
{
	int size = this->r.get_size();
	vector<Transaction> transactions = this->r.get_all();
	Transaction most_valuable_transaction;
	int max_value = 0;
	for (int i = 0; i < size; i++) {
		if (transactions[i].get_day() == day && transactions[i].get_sum() > max_value) {
			most_valuable_transaction = transactions[i];
			max_value = transactions[i].get_sum();
		}
	}
	return most_valuable_transaction;
}



void Service::keep_by_type(char* type)
{
	this->keep_by_param(type);

}

void Service::keep_by_type_and_sum(char* type, int sum)
{
	this->keep_by_param(type,sum);

}

