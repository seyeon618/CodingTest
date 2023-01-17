//
// Created by seyeon on 2023-01-17.
//
#include "../header/Lev2.h"
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int getMinValue(vector<int> vecA, vector<int> vecB)
{
    //    sort(vecA.begin(), vecA.end());
    //    sort(vecB.rbegin(), vecB.rend());
    //
    //    int nSum = 0;
    //    for(int i=0; i<vecA.size(); i++)
    //        nSum += (vecA[i] * vecB[i]);
    //
    //    return nSum;

    sort(vecA.begin(), vecA.end());
    sort(vecB.rbegin(), vecB.rend());

    return inner_product(vecA.begin(), vecA.end(), vecB.begin(), 0);
}

bool isBracket(const string& strBracket)
{
    int nStack = 0;
    int nBracket = 0;
    for(int i=0; i<strBracket.size(); i++)
    {
        if(nStack < 0)
            return false;

        if(strBracket[i] == '(') {
            nStack++;
        }
        else {
            nStack--;
            nBracket++;
        }
    }

    return nStack == 0;
}