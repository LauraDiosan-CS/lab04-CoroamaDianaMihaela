#pragma once
class Tests_transaction {
private:
	void test_transaction_gets();
	void test_transaction_sets();
	void test_transaction_operator();
public:
	void test_transaction();

};

class Tests_repo {
	
private:
	void test_repo_add();
	void test_repo_delete();
	void test_repo_update();
public:
	void test_repo();


};

class Tests_service {

private:
	void test_add_transaction();

	void test_delete__transaction_by_day();
	void test_delete_transaction_between_days();
	void test_delete_transaction_by_type();
	void test_replace_sum_in_transaction();

	void test_array_with_transaction_by_type();
	void test_array_with_transaction_over_value();
	void test_array_with_transaction_equal_value();

	void test_sold_by_day();
	void test_sum_by_type();
	
	void test_keep_by_type();
	void test_keep_by_type_and_sum();

	
public:
	void test_service();
};