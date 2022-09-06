#include<vector>
#include<iostream>

using namespace std;

class PriorityQueue{

    vector<int> pq;

    public:

    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){

        //check if pq is empty
        if(isEmpty() == true)
            return 0;

        return pq[0];
    }

    void display(){
        for(int i = 0; i < getSize(); i++)
            cout << pq[i] << " ";
    }

    //Insert fn
    void insert(int element){

        //add into array
        pq.push_back(element);

        //compare child value with parent
        int childIndex = getSize() - 1;

        while(childIndex > 0){

            int parentIndex = (childIndex - 1) / 2;

            //compare values of child and parent
            if(pq[childIndex] < pq[parentIndex]){
                //swap
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
                break;

            //Update childIndex
            childIndex = parentIndex;
        }
    }

    int removeMin(){
        //check pq is empty
        if(isEmpty() == true)
            return -1; //Queue is empty
        
        //Swap elements at 0 and last index
        int temp = pq[0];
        pq[0] = pq[getSize() - 1];
        pq[getSize() - 1] = temp;

        //pop last index value
        pq.pop_back();

        //Calculate parent and child indexes
        int parentIndex = 0;
    
        while(parentIndex < getSize()){
            
            int minIndex;
            int leftchildIndex = 2*parentIndex + 1;
            int rightchildIndex = 2*parentIndex + 2;

            //check both are under scope 
            if(leftchildIndex < getSize() && rightchildIndex < getSize()){
                cout << "Inside";
                if(pq[leftchildIndex] < pq[rightchildIndex])
                    minIndex = leftchildIndex;
                else
                    minIndex = rightchildIndex;
                
                //swap parentIndex value and minIndex value
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[minIndex];
                pq[minIndex] = temp;

                parentIndex = minIndex;
            }

            else if(leftchildIndex < getSize()){
                
                //swap parentIndex value and leftchildIndex value if parentIndex value > leftchildIndex value
                if(pq[leftchildIndex] < pq[parentIndex]){
                    
                    int temp = pq[parentIndex];
                    pq[parentIndex] = pq[leftchildIndex];
                    pq[leftchildIndex] = temp;
                    parentIndex = leftchildIndex;
                }
                else
                    break;
            }

            else{
                break;
            }
            
        }

        return temp;
    }
};

int main(){
    PriorityQueue pq;

    for(int i = 10; i < 50; i = i + 10)
        pq.insert(i);

    pq.display();
    cout << endl;
    cout << pq.removeMin() << endl;
    pq.display();
    pq.removeMin();
    cout << endl;
    pq.display();
}