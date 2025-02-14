class ProductOfNumbers {
public:
    struct Node{
        int val;
        Node* next;
        Node* prev;
        Node(int x){
            val=x;
            next=NULL;
            prev=NULL;
        }
    };
    Node* head;
    Node* tail;
public:
    ProductOfNumbers() {
        head = nullptr;
        tail = nullptr;
    }
    
    void add(int num) {
        if(head==nullptr){
            head= new Node(num);
            tail=head;
        }
        else{
            Node* n = new Node(num);
            tail->next=n;
            n->prev=tail;
            tail=n;
        }
    }
    
    int getProduct(int k) {
        int prod=1;
        Node* temp = tail;
        if(tail!=NULL){
            while(k--){
                if(temp) prod*=temp->val;
                temp=temp->prev;
            }
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */