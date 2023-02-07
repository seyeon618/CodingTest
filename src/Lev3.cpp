//
// Created by yscat on 2023-02-07.
//
#include "../header/Lev3.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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
