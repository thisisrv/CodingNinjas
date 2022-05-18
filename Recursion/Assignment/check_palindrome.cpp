#include <iostream>
//#include "solution.h"
using namespace std;

int length(char input[]){

    int count = 0;
    for(int i = 0; input[i] != '\0' ;i++)
        count++;

    return count;
}

bool helperfn(char input[], int start_index, int end_index){

    //Base case
    if(start_index >= end_index)
        return true;

    //small calc
    if(input[start_index] == input[end_index]){
        //Check remaining string
        bool checkremaining = helperfn(input, start_index + 1, end_index - 1);
        return checkremaining;
    }
    else
        return false;
}
bool checkPalindrome(char input[]) {

    //We need a helper fn here
    return helperfn(input, 0, length(input) - 1);

}
int main() {
    char input[50];
    cin >> input;

    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
