#include "Console.h"
#include "Tests.h"
int main() {

	Tests_transaction test_transactions;
	Tests_repo test_repo;
	Tests_service test_service;

	test_transactions.test_transaction();
	cout << "Transaction tests work" << endl;
	test_repo.test_repo();
	cout << "Repo tests work" << endl;
	test_service.test_service();
	cout << "Service tests work" << endl;


	RepoSTL r = RepoSTL("Transactions_in.txt", "Transactions_out.txt");
	Service s = Service(r);
	Console c1=Console(s);


	c1.run();

}