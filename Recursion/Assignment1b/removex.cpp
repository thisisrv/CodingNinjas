#include<iostream>
using namespace std;
int strlength(char input[]){
    int count = 0;
    for(int i = 0; input[i] != '\0'; i++)
        count ++;
    return count;
}

void removex(char input[]){
    //Base case
    if(input[0] == '\0')
        return;

    //Rec call
    removex(input + 1);

    //Small calc
    //check on 0th index for x if found shift string to left by 1
    if(input[0] == 'x'){
        for(int i = 1; i <= strlength(input); i++)
            input[i - 1] = input[i];
    }
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removex(input);
    cout << input << endl;
}
