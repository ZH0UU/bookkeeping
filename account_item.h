#include "common.h"
// define the struct of account item
struct AccountItem
{
	string itemType;
	int amount;
	string detail;
};

// Date Operation Function
void loadDataFromFile(vector<AccountItem>& items);
// bookkeeping
void accounting(vector<AccountItem>& items);
void insertIntoFile(const AccountItem& item);
void income(vector<AccountItem>& items);
void expand(vector<AccountItem>& items);
// query
void query(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items, const string type);
void printItem(const AccountItem& item);
