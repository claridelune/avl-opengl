#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////

struct CBinNode
{
    CBinNode(int _v)
    { value = _v; nodes[0] = nodes[1] = 0;  }
    int value;
    CBinNode* nodes[2];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////

class CBinTree
{
public:
    CBinTree();
    ~CBinTree();
    bool Insert(int x);
    bool Remove(int x);
    void Print();
private:
    bool Find(int x, CBinNode**& p);
    CBinNode** Rep(CBinNode** p);
    void InOrderR(CBinNode* n);
    void PreOrderR(CBinNode* n);
    void PostOrderR(CBinNode* n);
    void ReverseR(CBinNode* n);
    CBinNode* m_root;
    bool m_b;
};

CBinTree::CBinTree()
{   m_root = 0;
    m_b = 0;
}

CBinTree::~CBinTree()
{
    // ?
}

bool CBinTree::Find(int x, CBinNode**& p)
{
    for ( p = &m_root ;
         *p && (*p)->value != x ;
         p = &( (*p)->nodes[ (*p)->value < x ] ) );
    return *p && (*p)->value == x;
}

bool CBinTree::Insert(int x)
{
    CBinNode** p;
    if ( Find(x,p) ) return 0;
    *p = new CBinNode(x);
    return 0;
}
bool CBinTree::Remove(int x)
{
    CBinNode** p;
    if ( !Find(x,p) ) return 0;
    if ( (*p)->nodes[0] && (*p)->nodes[1] )
    {
        CBinNode** q = Rep(p);
        (*p)->value = (*q)->value;
        p = q;
    }
    CBinNode* t = *p;
    *p = (*p)->nodes[ (*p)->nodes[0] == 0 ];
    delete t;
    return 1;
}

CBinNode** CBinTree::Rep(CBinNode** q)
{
    m_b = !m_b;
    q = &((*q)->nodes[!m_b]);
    while( (*q)->nodes[m_b] )
        q = &((*q)->nodes[m_b]);
    return q;
}

void CBinTree::InOrderR(CBinNode* n)
{
    if ( !n ) return;
    InOrderR(n->nodes[0]);
    cout<<n->value<<" ";
    InOrderR(n->nodes[1]);
}

void CBinTree::PreOrderR(CBinNode* n)
{
    if ( !n ) return;
    cout<<n->value<<" ";
    PreOrderR(n->nodes[0]);
    PreOrderR(n->nodes[1]);
}

void CBinTree::PostOrderR(CBinNode* n)
{
    if ( !n ) return;
    PostOrderR(n->nodes[0]);
    PostOrderR(n->nodes[1]);
    cout<<n->value<<" ";
}

void CBinTree::ReverseR(CBinNode* n)
{
    if ( !n ) return;
    ReverseR(n->nodes[1]);
    cout<<n->value<<" ";
    ReverseR(n->nodes[0]);
}
void CBinTree::Print()
{
    InOrderR(m_root);
    cout << "\n";
    PreOrderR(m_root);
    cout << "\n";
    PostOrderR(m_root);
    cout << "\n";
    ReverseR(m_root);
    cout<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    CBinTree t;
    
    /* t.Insert(30); t.Insert(20); t.Insert(40);
    t.Insert(15); t.Insert(25); t.Insert(35);
    t.Insert(50); t.Insert(40); t.Insert(42);
    t.Insert(40); t.Insert(47); t.Insert(30);
    t.Insert(20); t.Insert(21); t.Insert(22);
    t.Insert(20); */
    t.Insert(30); t.Insert(20); t.Insert(40);
    t.Insert(15); t.Insert(25); t.Insert(35);
    t.Insert(50);
    t.Print();
    /* cout<<"---\n";
    t.Remove(47); t.Print();
    t.Remove(40); t.Print();
    t.Remove(15); t.Print();
    t.Remove(20); t.Print();
    t.Remove(25); t.Print();
    t.Remove(30); t.Print(); */
}
