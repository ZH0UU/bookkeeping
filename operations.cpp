#include <chrono>
#include <ctime>
#include "common.h"
#include "account_item.h"
//---------------------buillding---------------------
void loadDataFromFile(vector<AccountItem> &items)
{
	ifstream input(FILENAME);
	// get data
	AccountItem item;
	while (input >> item.itemType >> item.amount)
	{
		getline(input, item.detail);
		items.push_back(item);
	}
	input.close();
}

void accounting(vector<AccountItem> &items)
{
	// input checking
	char key = readMenuSelection(3);
	switch (key)
	{
	case '1': // incomes
		income(items);
		break;
	case '2': // expand
		expand(items);
		break;
	default:
		break;
	}
}
// income
void income(vector<AccountItem> &items)
{
	AccountItem item;
	item.itemType = INCOME;
	// input
	cout << "\n Please input income: ";
	item.amount = readAmount();
	printf("\nNotes: ");
	getline(cin, item.detail);
	// add to vector
	items.push_back(item);
	insertIntoFile(item);
	printf("\n---------------Billing success!-------------\n");
	cout << endl;
	printf("Press Enter to return to main menu.....");
	string line;
	getline(cin, line);
}
void expand(vector<AccountItem> &items)
{
	AccountItem item;
	item.itemType = EXPAND;
	// input
	cout << "\n Please input expand: ";
	item.amount = -readAmount();
	printf("\nNotes: ");
	getline(cin, item.detail);
	// add to vector
	items.push_back(item);
	insertIntoFile(item);
	printf("\n---------------Billing success!-------------\n");
	cout << endl;
	printf("Press Enter to return to main menu.....");
	string line;
	getline(cin, line);
}
void insertIntoFile(const AccountItem &item)
{
	// out to file Append
	ofstream output(FILENAME, ios::out | ios::app);
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	output << std::ctime(&now_c) << "\t" << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
	output.close();
}

//---------------------query---------------------
void query(const vector<AccountItem> &items)
{
	// input checking
	char key = readMenuSelection(4);
	switch (key)
	{
	case '1': // all
		queryItems(items);
		break;
	case '2': // income
		queryItems(items, INCOME);
		break;
	case '3': // expand
		queryItems(items, EXPAND);
		break;
	default:
		break;
	}
}
//--------query function--------
void queryItems(const vector<AccountItem> &items)
{
	// print title
	printf("\n-----------------Query Result-----------------\n");
	cout << "Type\tAmount\tNotes" << endl;
	// print data
	int total = 0;
	for (auto item : items)
	{
		printItem(item);
		total += item.amount;
	}
	// out total
	printf("\n-----------------------------------------------\n");
	cout << "Total: " << total << endl;
	printf("Press Enter to return to main menu.....");
	string line;
	getline(cin, line);
}
void queryItems(const vector<AccountItem> &items, const string type)
{
	// print title
	printf("\n-----------------Query Result-----------------\n");
	cout << "Type\tAmount\tNotes" << endl;
	// print data
	int total = 0;
	for (auto item : items)
	{
		if (item.itemType == type)
		{
			printItem(item);
			total += item.amount;
		}
	}
	// out total
	printf("\n-----------------------------------------------\n");
	cout << ((type == INCOME) ? "Income: " : "Expand: ") << total << endl;
	printf("Press Enter to return to main menu.....");
	string line;
	getline(cin, line);
}
void printItem(const AccountItem &item)
{
	cout << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
}
