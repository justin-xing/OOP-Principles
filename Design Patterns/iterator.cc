class List {
    struct Node {
        int data;
        Node *next;
        Node() : data{data}, next{nullptr} {}
        ~Node() {delete next;}
    };

    Node *theList;
    
    public:
        class Iterator {
            Node *p;
            
            public:
                Iterator(Node *p): p{p} {}
                int &operator*() { return p->data; }
                bool operator == (Iterator &other) {
                    return (p == other.p);
                }
                bool operator != (Iterator &other) {
                    return !(*this == other);
                }
                Iterator &operator ++ () {
                    p = p->next;
                    return *this;
                }
        };

        Iterator begin() const { return Iterator{theList}; }

        Iterator end() const {return Iterator{nullptr}; }
};