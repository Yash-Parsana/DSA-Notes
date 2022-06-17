struct MyNode      
{
    int key, val, freq;
    MyNode *next, *prev;
    MyNode() : key(-1), val(-1), freq(0), next(nullptr), prev(nullptr) {}
    MyNode(int k, int v) : key(k), val(v), freq(1), next(nullptr), prev(nullptr) {}
    MyNode(int k, int v, MyNode *n, MyNode *p) : key(k), val(v), freq(1), next(n), prev(p) {}
};

class LFUCache 
{
    unordered_map<int, MyNode*> fewpf;           // map to store the most recently used node in the list of a particular frequency
    unordered_map<int, MyNode*> keyadd;        // map to store address of a particular frequency
    MyNode *head, *tail;                                        // dummy nodes 
    int capacity, size;
    
    void set(MyNode *current)
    {
        int f = current->freq;
        while(fewpf[f] == NULL) 
            f--;
        MyNode *n = fewpf[f];
        current->prev = n->prev;
        current->next = n;
        n->prev->next = current;
        n->prev = current;
        fewpf[current->freq] = current;
    }
    
    public:
    LFUCache(int cap) 
    {
        capacity = cap; size = 0;
        head = new MyNode(); tail = new MyNode();
        head->next = tail; tail->prev = head;
        fewpf[0] = tail;
    }
    
    int get(int key) 
    {
        if(keyadd[key] == NULL)
            return -1;
        MyNode *current = keyadd[key];
        if(fewpf[current->freq] == current)
        {    
            if(current->next->freq == current->freq)
                fewpf[current->freq] = current->next;
            else
                fewpf[current->freq] = NULL;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        current->freq += 1;
        set(current);
        return current->val;
    }
    
    void put(int key, int value) 
    {
        if(capacity == 0)
            return;
        MyNode *current;
        if(keyadd[key] != NULL)
        {
            current = keyadd[key];
            current->val = value;
            if(fewpf[current->freq] == current)
            {    
                if(current->next->freq == current->freq)
                    fewpf[current->freq] = current->next;
                else
                    fewpf[current->freq] = NULL;
            }
            current->freq += 1;
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        else 
        {
            current = new MyNode(key, value);
            if(size < capacity)
                size++;
            else
            {
                MyNode *n = tail->prev;
                keyadd[n->key] = NULL;
                if(fewpf[n->freq] == n)
                    fewpf[n->freq] = NULL;
                tail->prev = n->prev;
                n->prev->next = tail;
            }
            keyadd[key] = current;
        }
        set(current);
    }
};