//
// Created by seyeon on 2023-01-17.
//

#ifndef CODINGTEST_LEV2_H
#define CODINGTEST_LEV2_H
#include <vector>
#include <string>

using namespace std;

int getMinValue(vector<int> vecA, vector<int> vecB);

bool isBracket(const string& strBracket);

//! repeat binary tranformation
vector<int> repeatBinaryTrans(string strText);

//! expression of number
int getExpressionOfNumber(int nNum);

//! least common multiple of list
int getLeastCommonMultipleOfList(vector<int> vecNum);

//! island trip
vector<int> islandTrip(vector<string> mapOfIsland);
int dfs(vector<vector<pair<int, bool>>>&, int i, int j);

//! performance review
int performanceReview(vector<vector<int>> score);
bool cmp(vector<int> a, vector<int> b);
#endif //CODINGTEST_LEV2_H