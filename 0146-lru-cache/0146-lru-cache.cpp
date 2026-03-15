class LRUCache {
public:

    class Node{
        public:
        int key,value;
        Node* next;
        Node* prev;

        Node(int k,int val){
            value=val;
            key=k;
            
        }

    };

    unordered_map<int,Node*> temp;
    int size;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        size=capacity;

        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->next=tail;
        tail->prev=head;
    }

    void remove(Node* node){

        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void insert(Node* node){
        node->next=head->next;
        node->prev=head;

        head->next->prev=node;
        head->next=node;

    }
    
    int get(int key) {
       
       if(temp.count(key)){

        Node* node=temp[key];
        int ans=node->value;
        remove(node);
        insert(node);
        return ans;

       }else{
        return -1;
       }
        
    }
    
    void put(int key, int value) {
        
        if(temp.count(key)){
            Node* node=temp[key];
            remove(node);
            temp.erase(key);
        }

        if(temp.size()==size){
            Node* node=tail->prev;
            remove(node);
            temp.erase(node->key);
        }

        Node* node=new Node(key,value);
        insert(node);
        temp[key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */