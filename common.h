#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#define INCOME "income"
#define EXPAND "expand"
#define FILENAME "AccountBook.txt"
using namespace std;
// General Function

void showMainMenu();
void showAccountingMenu();
void showQueryMenu();
// Menu Function

// Input Checking Function
char readMenuSelection(int options);
char readQuitConfirm();
int readAmount(); 
