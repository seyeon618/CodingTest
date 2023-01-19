//
// Created by seyeon on 2023-01-17.
//
#include "../header/Lev2.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bitset>

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

vector<int> repeatBinaryTrans(string strText){
    int nZeroCnt = 0;
    int nTransCnt = 0;

    auto to_binary = [](int nNum) {
        string strBinaryText;
        while(nNum != 0){
            strBinaryText += nNum % 2 == 0 ? "0" : "1";
            nNum /= 2;
        }
        reverse(strBinaryText.begin(), strBinaryText.end());
        return strBinaryText;
    };

    while(strText != "1") {
        for (int i = 0; i < strText.size(); i++) {
            cout << strText[i] << endl;
            if (strText.at(i) == '0') {
                strText.erase(strText.begin() + i);
                nZeroCnt++;
            }
        }
        cout << strText.size() << endl;
        strText = to_binary(strText.size());
        cout << strText << endl;

        nTransCnt++;
    }
    return {nZeroCnt, nTransCnt};
}

int getExpressionOfNumber(int nNum)
{
    int nCount = 0;
    for(int i=1; i<=nNum; i++)
    {
        int nSum = 0;
        for(int j=i; j<=nNum; j++)
        {
            nSum += j;
            if(nSum == nNum) {
                nCount++;
                break;
            }
            if(nSum > nNum)
                break;
        }
    }
    return nCount;
}

int getLeastCommonMultipleOfList(vector<int> vecNum){
    int nCnt = 1;
    while(true){
        int nVal = nCnt * vecNum[vecNum.size()-1];
        bool bOk = true;
        for(int i = 0; i < vecNum.size()-1; i++) {
            bOk = bOk && (nVal % vecNum[i] == 0);
        }

        if(bOk)
            return nVal;

        nCnt++;
    }
}