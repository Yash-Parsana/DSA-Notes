class node{
    public:
        int val;
        int key;
        node* pre;
        node* next;
    
        node(int data,int k)
        {
            val=data;
            key=k;
            pre=NULL;
            next=NULL;
        }
    
};

class LRUCache {
public:
    node* head,*tail;
    unordered_map<int,node*> m;
    LRUCache(int c) {

        head=new node(-1,-1);
        c--;
        node* temp=head;
        while(c--)
        {
            node *n=new node(-1,-1);
            temp->next=n;
            n->pre=temp;
            temp=temp->next;        
        }
        tail=temp;
        
    }
    
    int get(int key) {
        
        if(m.find(key)!=m.end())
        {
            int temp= m[key]->val;
            
            if(m[key]==tail) return temp;
            if(m[key]==head)
            {
                node*temp=head;
                head=head->next;
                head->pre=NULL;
                temp->next=NULL;
                tail->next=temp;
                temp->pre=tail;
                tail=tail->next;
            }
            else
            {
                node* temp=m[key];
                
                temp->pre->next=temp->next;
                temp->next->pre=temp->pre;
                tail->next=temp;
                temp->pre=tail;
                tail=tail->next;
            }
            return temp;
        
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        
        
        if(head->next==NULL)
        {
            head->val=value;
            m.erase(head->key);
            head->key=key;
            m[key]=head;
            return;
        }
        
        
        if(m.find(key)!=m.end())
        {
            if(m[key]==tail)
            {
                tail->val=value;
                return;
            }
            else if(m[key]!=head)
            {
                node* temp=m[key];
                temp->pre->next=temp->next;
                temp->next->pre=temp->pre;
                tail->next=temp;
                temp->pre=tail;
                tail=tail->next;
                tail->val=value;
                return;
            }
        }
        
        head->val=value;
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        head->pre=NULL;
        tail->next=temp;
        temp->pre=tail;
        tail=tail->next;
        m.erase(temp->key);
        
        temp->key=key;
        m[key]=temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */