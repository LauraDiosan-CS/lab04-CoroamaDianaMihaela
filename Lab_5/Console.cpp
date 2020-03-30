#include "Transaction.h"
#include "Tests.h"
#include "Repo.h"
#include "Console.h"
#include <iostream>
#include <chrono>

using namespace std;

void Console::menu_main()
{
	cout << "a. Add a transaction" << endl;
	cout << "b. Modify a transaction" << endl;
	cout << "c. Identiy transaction based on atributes" << endl;
	cout << "d. Obtaining a characterstic of transactions" << endl;
	cout << "e. Filter through transactions" << endl;
	cout << "f. Exit" << endl;
}

void Console::menu_secondary_1() {
	cout << "1. Add- write the transaction you wish to add with the exception of its date, which will be automatially imputed." << endl;
	cout << "2. Insert- write the transaction you wish to add with all of its atributes" << endl;

}

void Console::menu_secondary_2() {
	cout << "1. Delete all transactions with the given day" << endl;
	cout << "2. Delete all transactions between two days" << endl;
	cout << "3. Delete all transactions with the given type" << endl;
	cout << "4. Replace the sum in a transaction with it's atributes given" << endl;
}

void Console::menu_secondary_3() {
	cout << "1. Show all the transactions that have the same type" << endl;
	cout << "2. Show transactions with sum over the imputed value" << endl;
	cout << "3. Show transactions with sum equal to the imputed value" << endl;
	cout << "4. Show the sold for the given day " << endl;
	cout << "5. Print all transactions" << endl;

}

void Console::menu_secondary_4()
{
	cout << "1. Shows the total sum of all the transactions of a type" << endl;
	cout << "2. Shows the most valuable transaction of the out type from an imputed day" << endl;
}

void Console::menu_secondary_5()
{
	cout << "1. Only the transactions with the type imputed are kept" << endl;
	cout << "2. Only the transactions with the type and sum imputed are kept" << endl;

}


Console::Console(Service s)
{
	this->s = s;
}

int Console::run() {


	while (true)
	{
		this->menu_main();
		char op = read_op();

		if (op == 'a') {
			this->menu_secondary_1();
			char op2 = read_op();
			if (op2 == '1') {
				this->add_transaction(op2);
			}
			else if (op2 == '2') {
				this->add_transaction(op2);
			}
		}

		else if (op == 'b') {
			this->menu_secondary_2();

			char op2 = read_op();

			if (op2 == '1') {
				this->delete_transaction_day();
			}
			else if (op2 == '2') {
				this->delete_transaction_between_days();
			}
			else if (op2 == '3') {
				this->delete_update_type();
			}
			else if (op2 == '4') {
				this->replace_sum_in_transaction();
			}

		}

		else if (op == 'c') {
			this->menu_secondary_3();

			char op2 = read_op();

			if (op2 == '1') {
				this->show_by_given_type();
			}
			else if (op2 == '2') {
				this->show_array_with_tran_sum_over();
			}
			else if (op2 == '3') {
				this->show_array_with_tran_equal();
			}
			else if (op2 == '4') {
				this->sold_for_the_day();
			}
			else if (op2 == '5') {
				this->show_transaction();
			}


		}

		else if (op == 'd') {
			this->menu_secondary_4();

			char op2 = read_op();

			if (op2 == '1') {
				this->sum_by_type();
			}
			else if (op2 == '2') {
				this->most_valuable_transaction_by_day();
			}

		}

		else if (op == 'e') {
			this->menu_secondary_5();

			char op2 = read_op();

			if (op2 == '1') {
				this->keep_by_type();
			}
			else if (op2 == '2') {
				this->keep_by_type_and_sum();
			}
		}

		else if (op == 'f') {
			return 0;
		}
	}
}


int Console::read_int() {
	int a;
	cin >> a;
	return a;
}

char Console::read_op() {
	cout << "Enter option: ";
	char a;
	cin >> a;
	return a;
}

char* Console::read_p_char()
{
	char b[100];
	cin >> b;
	char* a = new char[strlen(b) + 1];
	strcpy_s(a, strlen(b) + 1, b);
	return a;
}

void Console::add_transaction(char op)
{
	int day;
	if (op == '2') {
		cout << "Day: ";
		day = read_int();
	}
	else {
		day = this->get_current_day();
	}
	cout << "Sum: ";
	int sum = read_int();
	cout << "Type: ";
	char* type = read_p_char();
	cout << "Description: ";
	char* description = read_p_char();

	this->s.add_transaction(day, sum, type, description);


}

void Console::show_transaction()
{
	int size = this->s.get_size_repo();
	vector<Transaction> transactions = this->s.get_all();
	for (int i = 0; i < size; i++) {
		cout << transactions[i];

	}


}

int Console::get_current_day()
{
	time_t now = time(0);

	tm* ltm = localtime(&now);

	return ltm->tm_mday;
}




void Console::delete_update_type()
{
	char* type = read_p_char();
	this->s.delete_transaction_CHAR_updated(type);

	delete[] type;

}

void Console::delete_transaction_day()
{
	cout << "The day by which the transactions will be erased: ";
	int day = read_int();
	this->s.delete_transaction_day_updated(day);
}

void Console::delete_transaction_between_days()
{
	cout << "Day 1: " << endl;
	int day_1 = read_int();
	cout << "Day 2: " << endl;
	int day_2 = read_int();
	this->s.delete_transaction_b_update(day_1, day_2);
}

void Console::replace_sum_in_transaction()
{
	cout << "Imput the attributes of the transaction that you wish to change" << endl;
	cout << "Day: ";
	int day = read_int();
	cout << "Type: ";
	char* type = read_p_char();
	cout << "Description: ";
	char* description = read_p_char();
	cout << "The sum with which to change it: ";
	int sum = read_int();
	this->s.replace_sum_in_transaction(sum, day, type, description);
}




void Console::show_array_with_tran_sum_over()
{
	int length = 0;
	Transaction transaction[100];
	cout << "The sum which the transactions have to be better than" << endl;
	int sum = read_int();
	this->s.array_with_transaction_sum_b(transaction, length, sum);
	for (int i = 0; i < length; i++)
		cout << transaction[i] << " ";
}

void Console::show_array_with_tran_equal()
{
	int length = 0;
	Transaction transactions[100];
	cout << "Imput the sum which the transactions have to be equal to: " << endl;
	int sum = read_int();
	this->s.array_with_transaction_sum_equal(transactions, length, sum);
	for (int i = 0; i < length; i++)
		cout << transactions[i] << endl;
}

void Console::show_by_given_type()
{
	Transaction transactions[100];
	char* type = read_p_char();
	int length = 0;
	this->s.array_with_transactions_by_type(type, transactions, length);
	for (int i = 0; i < length; i++)
		cout << transactions[i];

	delete[] type;

}




void Console::sold_for_the_day()
{
	cout << "The day for the sold: ";
	int day = read_int();
	cout << this->s.sold_by_day(day) << endl;
}

void Console::sum_by_type()
{
	cout << "The type for calculating the sum: " << endl;
	char* type = read_p_char();
	cout << this->s.sum_by_type(type) << endl;

	delete[] type;
}

void Console::most_valuable_transaction_by_day()
{
	cout << "The day for searching the most valuable " << endl;
	int day = read_int();
	Transaction t = this->s.most_valuable_by_day(day);
	cout << t;
}

void Console::keep_by_type()
{
	cout << "The type of the transactions that you wish to keep: " << endl;
	char* type = read_p_char();
	this->s.keep_by_type(type);
	delete[] type;
}

void Console::keep_by_type_and_sum()
{
	cout << "The type of the transactions that you wish to keep: " << endl;
	char* type = read_p_char();
	cout << "The sum of the transactions that you wish to keep: " << endl;
	int sum = read_int();

	this->s.keep_by_type_and_sum(type, sum);
	delete[] type;
}



