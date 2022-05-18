#include <iostream>
#include <math.h>
#include <iomanip>
//#include "solution.h"
using namespace std;

double geometricSum(int k) {

    //Base case
    if(k == 0)
        return 1;

    //Rec call
    double small_ans = geometricSum(k - 1);

    //Small calc
    return small_ans + (1 / pow(2,k));
}

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;
}
