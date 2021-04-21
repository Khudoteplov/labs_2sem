#include <iostream>

struct ListPair{
    int num;
    ListPair *tail;
};

struct List{
    ListPair *head;
};

List new_list(){
    List *q = new List;
    q->head = nullptr;
    return *q;
}

List new_list(List const &lst){
    List *q = new List;
    ListPair *t = lst.head;
    if (t == nullptr){
        q->head = nullptr;
    }
    else{
        ListPair *n = new ListPair, *p;
        q->head = n;
        while (t != nullptr){
            if (t->tail != nullptr){
                p = new ListPair;
                n->tail = p;
                n->num = t->num;
                n = p;
                t = t->tail;
            }
            else{
                n->num = t->num;
                n->tail = nullptr;
                t = t->tail;
            }
        }
    }

    return *q;
}

List push_list(List &lst, int num){
    auto *q = new ListPair;
    q->num = num;
    q->tail = lst.head;
    lst.head = q;
    return lst;
}

int pop_list(List &lst){
    int t = (lst.head)->num;
    ListPair *q = lst.head;
    lst.head = q->tail;
    delete q;
    return t;
}

int peak_list(List const &lst){
    return (lst.head)->num;
}

void delete_list(List &lst){
    ListPair *t;
    while (lst.head!= nullptr){
        t = lst.head;
        lst.head = (lst.head)->tail;
        delete t;
    }
    delete &lst;
}

bool is_empty(List const &lst){
    return (lst.head == nullptr);
}

List reverse_list(List &lst){
    ListPair *t = lst.head, *p = nullptr, *v;
    while (t != nullptr){
        v = new ListPair;
        v->tail = p;
        v->num = t->num;
        p = v;
        t =t->tail;
    }

    t = lst.head;
    lst.head = p;
    while (t!= nullptr){
        v = t;
        t = t->tail;
        delete v;
    }

    return lst;
}
