#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
struct List
{
    node *head;
    node *tail;
};

node *CreateNode(int a)
{
    node *p = new node;
    p->data = a;
    p->next = NULL;
    return p;
}

void CreateEmptyList(List &l)
{
    l.head = NULL;
    l.tail = NULL;
}
void AddHead(List &l, node *p)
{
    if (l.head == NULL)
    {
        l.head = p;
        l.tail = l.head;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

void AddTail(List &l, node *p)
{
    if (l.head == NULL)
    {
        l.head = p;
        l.tail = l.head;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}
void PrintList(List l)
{
    for (node *p = l.head; p != NULL; p = p->next)
        cout << p->data << "\n";
}
int main()

{

    List l;

    CreateEmptyList(l);

    AddTail(l, CreateNode(1));

    AddTail(l, CreateNode(2));

    AddTail(l, CreateNode(3));

    AddHead(l, CreateNode(4));

    AddHead(l, CreateNode(5));

    PrintList(l);

    return 0;
}