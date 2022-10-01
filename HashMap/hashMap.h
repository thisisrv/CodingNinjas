#include<string>
using namespace std;

template <typename V>
class MapNode{

    public:
    
    string key;
    V value;
    MapNode<V>* next;

    //constructor
    MapNode(string key, V value){
        this -> key = key;
        this -> value = value;
        next = NULL;
    }

    //destructor
    ~MapNode(){
        delete next;
    }
};

template<typename V>
class ourmap{

    MapNode<V>** buckets;
    int numBuckets;
    int count;

    public:

    //contructor
    ourmap(){
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        //initialise by NULL
        for(int i = 0; i < numBuckets; i++)
            buckets[i] = NULL;
    }

    //destructor
    ~ourmap(){
        for(int i = 0; i < numBuckets; i++)
            delete buckets[i];

        delete [] buckets;
    }


    //Fns
    int size(){
        return count;
    }

    private:
    int getBucketIndex(string key){
        int coeff = 1;
        int hashcode = 0;

        for(int i = key.length(); i >= 0; i--){
    
            hashcode += key[i] * coeff;
            hashcode = hashcode % numBuckets;
            coeff *= 37;
            coeff = coeff % numBuckets;
        }

        return hashcode % numBuckets;
    }

    void rehash(){
        //create temp and point to buckets
        MapNode<V>** temp = buckets;

        //double size for buckets
        buckets = new MapNode<V>*[2 * numBuckets];

        //initialise as NULL
        for(int i = 0; i < 2 * numBuckets; i++)
            buckets[i] = NULL;

        int oldBucketCount = numBuckets;
        count = 0;
        numBuckets *= 2;

        //insert elements
        for(int i = 0; i < oldBucketCount; i++){
            MapNode<V>* head = temp[i];

            while(head != NULL){
                insert(head -> key, head -> value);
                head = head -> next;
            }
        }

        //delete temp array
        for(int i = 0; i < oldBucketCount; i++){
            MapNode<V>* head = temp[i];
            delete head;
        }

        delete[] temp;
    }

    public:
    //insert fn
    void insert(string key, V value){

        //get index using hashcode
        int bucketIndex = getBucketIndex(key);

        //get head of bucket[bucketindex]
        MapNode<V>* head = buckets[bucketIndex];

        //Loop and update bucket value if key already present
        while(head != NULL){
            if(head -> key == key){
                head -> value = value;
                return;
            }
            head = head -> next;
        }

        //if key not present make node and insert in front
        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key, value);
        node -> next = head;
        buckets[bucketIndex] = node;
        count++;

        //rehashing
        double loadFactor = (1.0 * count) / numBuckets;

        if(loadFactor > 0.7)
            rehash();
    }


    //remove fn
    V remove(string key){
        //get index using hashcode
        int bucketIndex = getBucketIndex(key);

        //get head of bucket[bucketindex]
        MapNode<V>* prev = NULL;
        MapNode<V>* head = buckets[bucketIndex];

        //Loop and delete bucket value if key is present
        while(head != NULL){
            if(head -> key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head -> next;
                }
                else{
                    prev -> next = head -> next;
                }

                //Delete element
                head -> next = NULL;
                V value = head -> value;
                delete head;
                count --;
                return value;

            }
            prev = head;
            head = head -> next;
        }

        return 0;
    }

    //get value
    V getValue(string key){
        //get index using hashcode
        int bucketIndex = getBucketIndex(key);

        //get head of bucket[bucketindex]
        MapNode<V>* head = buckets[bucketIndex];

        //Loop and update bucket value if key already present
        while(head != NULL){
            if(head -> key == key){
                return head -> value;
            }
            head = head -> next;
        }

        return 0;
    }

    double getLoadFactor(){
        return (1.0 * count) / numBuckets;
    }
};