//
// Created by seyeon on 2023-01-17.
//
#include "../header/Lev2.h"
#include <algorithm>
#include <bitset>
#include <iostream>
#include <numeric>
#include <map>
#include <string>
#include <vector>

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

vector<int> islandTrip(vector<string> mapOfIsland){
    vector<vector<pair<int, bool>>> vecMaps;
    for(int i=0; i<mapOfIsland.size(); i++){
        vector<pair<int, bool>> vecMap;
        for(int j=0; j<mapOfIsland[i].size(); j++) {
            if (mapOfIsland[i][j] == 'X')
                vecMap.push_back(make_pair<int, bool>(0, true));
            else
                vecMap.push_back(make_pair<int, bool>(mapOfIsland[i][j] - '0', false));
        }
        vecMaps.push_back(vecMap);
    }

    vector<int> vecAnswer;
    for(int i=0; i<vecMaps.size(); i++){
        for(int j=0; j<vecMaps[i].size(); j++){
            int islandSum = dfs(vecMaps, i, j);
            if(islandSum > 0)
                vecAnswer.push_back(islandSum);
        }
    }

    if(vecAnswer.size() <= 0)
        return {-1};

    sort(vecAnswer.begin(), vecAnswer.end());
    return vecAnswer;
}

int dfs(vector<vector<pair<int, bool>>>& vecMap, int i, int j){
    if(i < 0 || j < 0 || i >= vecMap.size() || j >= vecMap[0].size())
        return 0;

    if(vecMap[i][j].first == 0 || vecMap[i][j].second)
        return 0;

    vecMap[i][j].second = true;

    return vecMap[i][j].first + dfs(vecMap, i+1, j) + dfs(vecMap, i-1, j) + dfs(vecMap, i, j+1) + dfs(vecMap, i, j-1);
}

int performanceReview(vector<vector<int>> scores){
    const auto vecTemp = scores[0];
    int nTempSum = vecTemp[0] + vecTemp[1];

    sort(scores.begin(), scores.end(), cmp);

    int answer = 1;
    int nMinVal = 0;
    for(int i=0; i<scores.size(); i++){
        if(vecTemp[0] < scores[i][0] && vecTemp[1] < scores[i][1])
            return -1;

        if(nMinVal <= scores[i][1]){
            int nSum = scores[i][0] + scores[i][1];
            if(nTempSum < nSum){
                answer++;
            }
            nMinVal = scores[i][1];
        }
    }

    return answer;
}

bool cmp(vector<int> a, vector<int> b){
    return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
}