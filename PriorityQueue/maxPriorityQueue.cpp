#include<iostream>
#include<vector>

using namespace std;
class PriorityQueue {
    // Declare the data members here
    vector<int>pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here

        //push_back element
        pq.push_back(element);

        int childIndex = getSize() - 1;

        while(childIndex > 0){
            int parentIndex =  (childIndex - 1) / 2;

            if(pq[parentIndex] < pq[childIndex]){
                //swap
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else    //element is at correct position
                break;

            childIndex = parentIndex;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty() == true)
            return 0;
        
        return pq[0];
    }

    int removeMax() {
        
        //check if pq is empty
        if(getSize() == 0)
            return 0; //return 0 as pq is empty
        
        int ans = pq[0];
        pq[0] = pq[getSize() - 1];

        //delete last element
        pq.pop_back();

        //initialise parentIndex, LCI, RCI and MaxIndex;
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        int maxIndex = parentIndex;

        while(leftChildIndex < getSize()){

            //compare lci and Mi
            if(pq[leftChildIndex] > pq[maxIndex])
                maxIndex = leftChildIndex;
            
            if(pq[rightChildIndex] > pq[maxIndex])
                maxIndex = rightChildIndex;

            if(maxIndex == parentIndex)
                break;
            
            //swap maxIndex and parentIndex value
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[maxIndex];
            pq[maxIndex] = temp;

            //Update values
            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size() == 0;
    }

    void display(){
        for(int i = 0; i < getSize(); i++)
            cout << pq[i] << " ";
    }
};

int main(){

    PriorityQueue p;

    for(int i = 50; i >= 10; i= i - 10)
        p.insert(i);

    // p.insert(25);
    p.display();
    cout << p.removeMax() << endl;
    cout << p.removeMax() << endl;

    p.display();
}