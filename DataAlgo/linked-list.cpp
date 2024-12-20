#include<bits/stdc++.h>
using namespace std;

namespace CP{
    template <typename T>
    class node{
        public:
            T data;
            node *next;
            node() : 
                data(T()), next(NULL) {};
            node(const T& data, node* next) :
                data(T(data)),next(next){}
    };
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    CP::node<int> *p = NULL;
    p = new CP::node<int>(10,NULL);
    CP::node<int> *q;
    q = new CP::node<int>(20,NULL);
    CP::node<int> *r;
    r = new CP::node<int>(30,NULL);
    CP::node<int> *s;
    s = new CP::node<int>(40,NULL);
    p->next = q;
    q->next = r;
    r->next = s;
    // r->next = new CP::node<int>(50,new CP::node<int>(60,NULL));
    cout << "p: "  << p->data << ' ' << p->next << '\n';
    cout << "q: "  << q->data << ' ' << q->next << '\n';
    cout << "q->next: "  << q->next->data << ' ' << q->next->next << "\n\n";
    p = p->next->next;
    q = p;
    q = q->next;
    cout << "p: "  << p->data << ' ' << p->next << '\n';
    cout << "q: "  << q->data << ' ' << q->next << '\n';
    if(q->next == NULL) cout << "q->next: NULL\n";
    return 0;
}