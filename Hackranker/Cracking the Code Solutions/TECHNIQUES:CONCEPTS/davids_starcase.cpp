#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Pure recursion - runs too low at roughly 3^n
int recursiveStepCount(int stepsLeft){

    if(stepsLeft == 0){
        return 1;
    } else if(stepsLeft < 0){
        return 0;
    }

    return recursiveStepCount(stepsLeft - 1) + recursiveStepCount(stepsLeft - 2) + recursiveStepCount(stepsLeft - 3);
}

// Dynamic programming bottom up approach
int dynamicStepCount(int totalSteps){
    int stepLog[totalSteps + 1] = {0};
    stepLog[0] = 1;
    stepLog[1] = 1;
    stepLog[2] = 2;

    for(int i = 3; i <= totalSteps; i++){
        stepLog[i] = stepLog[i - 1] + stepLog[i - 2] + stepLog[i - 3];
    }

    return stepLog[totalSteps];
}

// Dynamic programming top down memorization approach
int memStepCount(int stepsLeft, int * stepLog){

     if(stepsLeft == 0 || stepsLeft == 1){
        return 1;
    } else if(stepsLeft < 0){
        return 0;
    }

    if(stepLog[stepsLeft] == 0){
        stepLog[stepsLeft] = memStepCount(stepsLeft - 1, stepLog) + memStepCount(stepsLeft - 2, stepLog)
            + memStepCount(stepsLeft - 3, stepLog);
    }

    return stepLog[stepsLeft];
}

int main(){
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        int stepLog[n + 1] = {0};
        printf("%i\n" , memStepCount(n, stepLog));
        //printf("%i\n" , dynamicStepCount(n));
    }
    return 0;
}
