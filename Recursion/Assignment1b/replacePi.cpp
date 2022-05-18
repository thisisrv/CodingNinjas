#include<iostream>
using namespace std;

int strlength(char input[]){
    int count = 0;
    for(int i = 0; input[i] != '\0'; i++)
        count ++;
    return count;
}
void replace(char input[]){
    //Base case
    if(strlength(input) == 0)
        return;

    //Rec call
    replace(input + 1);

    //Small calc
    //check 0th and 1st index
    if(input[0] == 'p' && input[1] == 'i'){
        //move elements by 2
        for(int i = strlength(input); i >= 2; i--)
            input[i + 2] = input[i];

        //Add 3.14
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }

}
int main(){
    char input[1000];
    cin >> input;

    replace(input);
    cout << input << endl;
}