#include <iostream>
//#include "solution.h"
using namespace std;
int strlength(char input[]){
    int count = 0;
    for(int i = 0; input[i] != '\0'; i++)
        count ++;
    return count;
}
void pairStar(char input[]) {
    //Base case
    if(strlength(input) == 0 || strlength(input) == 1)
        return;

    //Rec call
    pairStar(input + 1);

    //Small calc
    //Check on first two index if same then add * in between them
    if(input[0] == input[1]){
        //Shift elements to right by 1
        for(int i = strlength(input); i >= 1; i--)
            input[i + 1] = input[i];

        input[1] = '*';
    }
}
int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
