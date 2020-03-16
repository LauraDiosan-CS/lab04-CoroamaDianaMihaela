#pragma once
//Gestiune conturi bancare
//John vrea să - și gestioneze conturile bancare și are nevoie de o aplicație care să - i
//permită stocarea și vizualizarea tranzacțiilor bancare efectuate în contul său în timpul
//unei luni calendaristice.Fiecare tranzacție este identificată prin : ziua din lună când a
//fost efectuată(întreg între 1 și 28 / 29 / 30 / 31), suma de bani(întreg pozitiv), tip(in - au
//	intrat bani în cont - sau out - au ieșit bani din cont) și descriere.Creați o aplicație care
//	să - l ajute pe John oferindu - i următoarele funcționalități :
#include <ostream>

using namespace std;

class Transaction
{
private:
	int day;
	int sum;
	char* type;
	char* description;

public:
	Transaction();
	Transaction(int day, int sum, char* type, char* description);
	Transaction(const Transaction& t);
	~Transaction();
	int get_day();
	int get_sum();
	char* get_type();
	char* get_description();
	void set_day(int day);
	void set_sum(int sum);
	void set_type(char* type);
	void set_description(char* description);
	Transaction& operator=(const Transaction& t);
	bool operator==(const Transaction& s);
	friend ostream& operator<<(ostream& os, const Transaction& s);


};
