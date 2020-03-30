#pragma once
#include "Service.h"
class Console {
private:
	Service s;
	void menu_main();
	void menu_secondary_1();
	void menu_secondary_2();
	void menu_secondary_3();
	void menu_secondary_4();
	void menu_secondary_5();

	int read_int();
	char read_op();
	char* read_p_char();


	void add_transaction(char op);
	void show_transaction();
	int get_current_day();

	void delete_update_type();
	void delete_transaction_day();
	void delete_transaction_between_days();
	void replace_sum_in_transaction();


	void show_by_given_type();
	void show_array_with_tran_sum_over();
	void show_array_with_tran_equal();


	void sold_for_the_day();
	void sum_by_type();
	void most_valuable_transaction_by_day();
	void keep_by_type();
	void keep_by_type_and_sum();
public:
	Console(Service s);                                                                                                                                      
	int run();
	
	
	
	

};
