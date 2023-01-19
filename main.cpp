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

    vector<int> vecResult = repeatBinaryTrans("110010101001");
    cout << "Number of times: " << vecResult[0] << endl;
    cout << "Number of zeroes removed: " << vecResult[1] << endl;
    cout << "===============================================================" << endl;

    cout << "Expression of number: " << getExpressionOfNumber(15) << endl;
    cout << "===============================================================" << endl;
    return 0;
}