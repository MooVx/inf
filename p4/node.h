#ifdef NODE
#define NODE

template <class T>
class Node{
    private:
        T _data;
        Node *_prior, *_next;

        Node( const T &data, Node *prior, Node *next ){
            _data=data;
            _prior=prior;
            _next=next;
        }

        friend class List<T>;
        virtual ~Node(){};
};


#endif // !NODE