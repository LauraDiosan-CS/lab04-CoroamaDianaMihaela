#pragma once
#include "Transaction.h"
#include <vector>
class RepoSTL
{	private:
	vector<Transaction> transactions;
	char* filename_in;
	char* filename_out;

public:
	RepoSTL();
	RepoSTL(const char* filename_in,const char* filename_out);
	RepoSTL(const RepoSTL& repo);
	~RepoSTL();

	void set_filename_in(const char* filename_in);
	void set_filename_out(const char* filename_out);

	void add_transaction(Transaction t);
	void delete_transaction(Transaction t);
	void update_transaction(Transaction& old_transaction,Transaction& new_transaction);
	vector<Transaction> get_all();

	void load_from_file();
	void save_to_file();

	/*Transaction get_transaction_at_position(int position);*/
	int get_size();

	RepoSTL& operator=(const RepoSTL& repo);
	



};