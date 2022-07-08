using namespace std;

template <typename T>
class BinaryTreeNode{
    public:

    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    //contructor
    BinaryTreeNode(T data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    //Destructor
    ~BinaryTreeNode(){

        delete left;
        delete right;
    }

};