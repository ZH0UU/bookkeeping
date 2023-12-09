#include "common.h"
#include "account_item.h"
int main()
{
	// 1.loading data
	vector<AccountItem> items;
	loadDataFromFile(items);
	bool quit = false;
	while (!quit)
	{
		// 2. menu
		showMainMenu();
		// 3. input checking
		char key = readMenuSelection(3);
		switch (key)
		{
		case '1': // bookkeeping
			showAccountingMenu();
			accounting(items);
			break;
		case '2': // query
			showQueryMenu();
			query(items);
			break;
		case '3': // quit
			cout << "\nAre you sure to quit? (Y/N):";
			if ('Y' == readQuitConfirm())
				quit = true;
			break;
		default:
			break;
		}
		cout << endl;
	}
}
