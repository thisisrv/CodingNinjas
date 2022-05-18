#include <iostream>
//#include "solution.h"
using namespace std;
int strlength(char input[]){
    int count = 0;
    for(int i = 0; input[i] != '\0'; i++)
        count ++;
    return count;
}
int helperfn(char input[], int end_index){
    //base case
    if(end_index == 0)
        return input[end_index] - '0';

    //rec call
    int small_ans = helperfn(input, end_index - 1);

    //Small calc
    return small_ans * 10 + (input[end_index] - '0');

}
int stringToNumber(char input[]){
    return helperfn(input, strlength(input) - 1);
}
int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}