#include <iostream>
using namespace std;

template <typename T>
class Nod 
{
public:
    T data;
    Nod* nxt;
    Nod* prv;

    Nod(T val) : data(val), nxt(nullptr), prv(nullptr) {}
};

template <typename T>
class Que 
{
private:
    Nod<T>* frnt;
    Nod<T>* rear;
    int sz;

public:
    Que() : frnt(nullptr), rear(nullptr), sz(0) {}

    ~Que() 
    {
        while (!isEmpty()) 
        {
            dequeue();
        }
    }

    void enqueue(T val)
    {
        Nod<T>* newNod = new Nod<T>(val);
        if (isEmpty()) 
        {
            frnt = rear = newNod;
        } 
        else
        {
            rear->nxt = newNod;
            newNod->prv = rear;
            rear = newNod;
        }
        sz++;
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Nod<T>* tmp = frnt;
        frnt = frnt->nxt;
        if (frnt) 
        {
            frnt->prv = nullptr;
        } else {
            rear = nullptr;
        }
        delete tmp;
        sz--;
    }

    T peek() const 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty." << endl;
            return T();
        }
        return frnt->data;
    }

    bool isEmpty() const 
    {
        return sz == 0;
    }

    int getSize() const 
    {
        return sz;
    }
};

int main() 
{
    Que<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.peek() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;
    cout << "Queue size after dequeue: " << q.getSize() << endl;

    return 0;
}

