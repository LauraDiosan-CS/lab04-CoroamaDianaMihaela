#include "RepoSTL.h"
#include <fstream>

RepoSTL::RepoSTL()
{
	this->filename_in = NULL;
	this->filename_out = NULL;
}

RepoSTL::RepoSTL(const char* filename_in,const char* filename_out)
{
	this->filename_in = new char[strlen(filename_in) + 1];
	this->filename_out = new char[strlen(filename_out) + 1];

	strcpy_s(this->filename_in, strlen(filename_in) + 1, filename_in);
	strcpy_s(this->filename_out, strlen(filename_out) + 1, filename_out);
	this->load_from_file();
	this->save_to_file();
}

RepoSTL::RepoSTL(const RepoSTL& repo)
{	///copy constructor
	this->filename_in = new char[strlen(repo.filename_in) + 1];
	this->filename_out = new char[strlen ( repo.filename_out ) + 1];

	strcpy_s(this->filename_in, strlen(repo.filename_in) + 1, repo.filename_in);
	strcpy_s(this->filename_out, strlen(repo.filename_out) + 1, repo.filename_out);

}

RepoSTL::~RepoSTL()
{/*	if(this->filename_in!=NULL){
	delete[] this->filename_in;
	this->filename_in = NULL;

}	
if (this->filename_out != NULL) {
	delete[] this->filename_out;
	this->filename_out = NULL;
}*/

this->transactions.clear();
}

void RepoSTL::set_filename_in(const char* filename_in)
{
	if (this->filename_in != NULL)
	{
		delete[] this->filename_in;
}
	if (filename_in != NULL)
	{
		this->filename_in = new char[strlen(filename_in) + 1];
		strcpy_s(this->filename_in, strlen(filename_in) + 1, filename_in);
	}
	else
		this->filename_in = NULL;

}

void RepoSTL::set_filename_out(const char* filename_out)
{
	if (this->filename_out != NULL)
	{
		delete[] this->filename_out;
	}
	if (filename_in != NULL)
	{
		this->filename_out = new char[strlen(filename_out) + 1];
		strcpy_s(this->filename_out, strlen(filename_out) + 1, filename_out);
	}
	else
		this->filename_out = NULL;
	
}



void RepoSTL::add_transaction(Transaction t)
{
	this->transactions.push_back(t);
	this->save_to_file();
}

void RepoSTL::delete_transaction(Transaction t)
{
	vector<Transaction>::iterator it;

	it = find(this->transactions.begin(),this->transactions.end(), t);
	if (!(it == this->transactions.end()))
	{
		this->transactions.erase(it);

	}
	this->save_to_file();

}

void RepoSTL::update_transaction(Transaction& old_transaction, Transaction& new_transaction)
{
	vector<Transaction>::iterator it;
	it = find(this->transactions.begin(), this->transactions.end(), old_transaction);
	if (!(it == this->transactions.end())) {
		*it = new_transaction;

	}
	this->save_to_file();
}

vector<Transaction> RepoSTL::get_all()
{
	return this->transactions;
}



void RepoSTL::load_from_file()
{
	if (this->filename_in != NULL)
	{
		this->transactions.clear();
		ifstream f(this->filename_in);
		int day;
		int sum;
		char* type = new char[4];
		char* description = new char[20];

		while (!f.eof()) {
			f >> day >> sum >> type >> description;
			if (strlen(type) > 0) {
				this->transactions.push_back(Transaction(day, sum, type, description));
			}

		}
		delete[] type;
		delete[] description;
		f.close();
	}
	else
		this->transactions.clear();
}

void RepoSTL::save_to_file()
{
	if (this->filename_out != NULL) {
		ofstream f(this->filename_out);
		int size = this->transactions.size();
		for(int i=0;i<size;i++)
		{
			f << this->transactions[i] << endl;
		}
		f.close();

	}
}

//Transaction RepoSTL::get_transaction_at_position(int position)
//{
//	if (position < 0 || position > this->transactions.size() - 1)
//	{
//		char type[] = "None";
//		char description[] = "None";
//		return Transaction(0, 0, type, description);
//	}
//	return this->transactions[position];
//}

int RepoSTL::get_size()
{
	return this->transactions.size();
}

RepoSTL& RepoSTL::operator=(const RepoSTL& repo)
{
	this->set_filename_in(repo.filename_in);
	this->set_filename_out(repo.filename_out);
	this->load_from_file();
	
	return *this;
}

