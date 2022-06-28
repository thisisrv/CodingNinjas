using namespace std;
class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public:

    //Create constructor;
    StackUsingArray(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    //Return size of stack
    int size(){
        return nextIndex;
    }

    //return true is stack is empty
    bool isempty(){
        if(nextIndex == 0)
            return true;
        else
            return false;
    }

    //Insert element in stack
    void push(int element){
        //check if stack is full
        if(nextIndex == capacity){
            int *newstack = new int[capacity * 2];

            //copy elements from data to newstack
            for(int i = 0; i < capacity; i++)
                newstack[i] = data[i];

            delete [] data;
            data = newstack;
            capacity *= 2;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    //Delete element in stack
    int pop(){
        if(isempty()){
            cout << "Stack is empty" << endl;
            return -1;
        }

        nextIndex--;
        return data[nextIndex];
    }

    //Return top element
    int top(){
        if(isempty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return data[nextIndex - 1];
    }

};