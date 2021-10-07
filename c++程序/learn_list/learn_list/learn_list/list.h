#include "stdio.h"

template <typename T> 
struct ListNode 
{ 
    T data; 
    ListNode<T>* pred; 
    ListNode<T>* succ;
    ListNode() {}
    ListNode(T e, ListNode<T>* p = NULL, ListNode<T>* s = NULL);
    ListNode<T>* insertAsPred(T const& e); 
    ListNode<T>* insertAsSucc(T const& e); 
};

template <typename T> 
class List 
{
private:
    int _size; 
    ListNode<T>* header; 
    ListNode<T>* trailer; 
    void init();
    int clear();
    void copyNodes(ListNode<T>*, int); //�����б�����λ��p���n��

public:
    List();
    ~List(); //�ͷţ�����ͷ��β�ڱ����ڵģ����нڵ�

    int size() const { return _size; } //��ģ
    bool empty() const { return _size <= 0; } //�п�
    ListNode<T>* first() const { return header->succ; }
    ListNode<T>* last() const { return trailer->pred; } 
    bool valid(ListNode<T>* p){ return p && (trailer != p) && (header != p);}
    
    ListNode<T>* insertAsFirst(T const& e); //��e�����׽ڵ����
    ListNode<T>* insertAsLast(T const& e); //��e����ĩ�ڵ����
    ListNode<T>* insertAfter(ListNode<T>* p, T const& e); //��e����p�ĺ�̲��루After��
    ListNode<T>* insertBefore(ListNode<T>* p, T const& e); //��e����p��ǰ�����루Before��
    T remove(ListNode<T>* p); //ɾ���Ϸ�λ��p���Ľڵ�,���ر�ɾ���ڵ�
}; 


template <typename T>
ListNode<T>::ListNode(T e, ListNode<T>* p, ListNode<T>* s)
{
    data = e;
    pred = p;
    succ = s;
}

template <typename T>
ListNode<T>* ListNode<T>::insertAsPred(T const& e)
{
    ListNode<T>* x = new ListNode(e, pred, this);
    pred->succ = x;
    pred = x;
    return x;
}

template <typename T>
ListNode<T>* ListNode<T>::insertAsSucc(T const& e)
{
    ListNode<T>* x = new ListNode(e, this, succ); //�����½ڵ�
    succ->pred = x;
    succ = x;
    return x;
}


template <typename T>
void List<T>::init()
{
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer; header->pred = NULL;
    trailer->pred = header; trailer->succ = NULL;
    _size = 0;
}

template <typename T>
List<T>::List()
{
    init();
}

template <typename T>
List<T>::~List()
{
    clear();
    delete header;
    delete trailer;
}

template <typename T>
int List<T>::clear()
{
    int oldSize = _size;
    while (0 < _size)
        remove(header->succ);
    return oldSize;
}

template <typename T>
ListNode<T>* List<T>::insertAsFirst(T const& e)
{
    _size++;
    return header->insertAsSucc(e);
}

template <typename T>
ListNode<T>* List<T>::insertAsLast(T const& e)
{
    _size++;
    return trailer->insertAsPred(e);
}

template <typename T>
ListNode<T>* List<T>::insertAfter(ListNode<T>* p, T const& e)
{
    _size++;
    return p->insertAsSucc(e);
}

template <typename T>
ListNode<T>* List<T>::insertBefore(ListNode<T>* p, T const& e)
{
    _size++;
    return p->insertAsPred(e);
}

template <typename T>
T List<T>::remove(ListNode<T>* p)
{
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    _size--;
    return e;
}

