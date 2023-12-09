#include "common.h"
char readMenuSelection(int options)
{
	string str;
	// judgement
	while (true)
	{
		getline(cin, str);
		if (str[0] - '0' <= 0 || str[0] - '0' > options || 1 != str.size())
			printf("Wrong input! Please choose again!  ^-^\n");
		else
			break;
	}
	return str[0];
}

char readQuitConfirm()
{
	// get input and judgment
	string str;
	// judgement
	while (true)
	{
		getline(cin, str);
		if ((toupper(str[0]) != 'Y' && toupper(str[0]) != 'N') || 1 != str.size())
			printf("Wrong input! Please choose again!(Y/N)  ^-^\n");
		else
			break;
	}

	return toupper(str[0]);
}
int readAmount()
{
	int amount;
	string str;
	while (true)
	{
		getline(cin, str);
		try
		{
			amount = stoi(str);
			break;
		}
		catch (invalid_argument e)
		{
			printf("Wrong input! Please choose again! ^-^\n");
		}
	}
	return amount;
}
