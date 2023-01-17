#include "header/Lev2.h"
#include <iostream>

using namespace std;


int main()
{
    cout << "===============================================================" << endl;
    cout << getMinValue({1, 4, 2}, {5, 4, 4}) << endl;
    cout << "===============================================================" << endl;

    string answer = isBracket("(()(") ? "true" : "false";
    cout << answer << endl;
    cout << "===============================================================" << endl;
    return 0;
}