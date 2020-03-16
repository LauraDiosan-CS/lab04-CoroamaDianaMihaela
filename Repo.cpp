#include "Repo.h"
#include <cstddef>


Repo::Repo()
{

	this->n = 0;

}

Repo::~Repo() {

	this->n = 0;
}
void Repo::add_transaction(Transaction t) {
	this->transactions[this->n++] = t;


}
Transaction* Repo::get_all() {

	return this->transactions;
}

int Repo::get_size() {

	return this->n;

}
