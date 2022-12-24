#include <iostream>
using namespace std;


// Stack using arrays
class StackArr
{
    int Top, MaxStack;
    int* array;

public:
    StackArr(int size)
    {
        MaxStack = size;
        array = new int[size];
        Top = 0;
    }

    bool StackFull()
    {
        return (this->Top == this->MaxStack);
    }

    void Push(int data)
    {
        if (StackFull())
        {
            cout << "Stack OverFlow";
        }
        else
        {
            array[this->Top] = data;
            this->Top++;
        }
    }

    bool StackEmpty()
    {
        return (this->Top == 0);
    }

    int Pop()
    {
        if (StackEmpty())
        {
            cout << "Stack UnderFlow";
        }
        else
        {
            Top--;
            int data = array[this->Top];
            return data;
        }
    }
    int Peek()
    {
        if (StackEmpty())
        {
            cout << "No Item to return";
        }
        else
        {
            return array[this->Top - 1];
        }
    }
    void Display()
    {
        if (Top == 0)
        {
            cout << "Stack UnderFlow" << endl;
        }
        else
        {
            for (int i = Top - 1; i >= 0; i--)
            {
                cout << array[i] << endl;
            }
        }

    }
};

// Stack using linked list
class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class StackLL
{
    Node* Top;  // Head 
public:
    StackLL()
    {
        Top = NULL;
    }
    void Push(int data)
    {
        Node* node = new Node(data);
        node->data = data;
        node->next = Top;
        Top = node;
    }
    bool StackEmpty()
    {
        return Top == NULL;
    }

    int Pop()
    {
        if (Top == NULL)
        {
            cout << "Stack UnderFlow";
        }
        else
        {
            Node* firstNode = Top;
            int data = firstNode->data;
            Top = firstNode->next;
            delete[]firstNode;
            return data;
        }
    }

    int Peek()
    {
        if (Top == NULL)
        {
            cout << "Stack UnderFlow" << endl;
        }
        else
        {
            return Top->data;
        }
    }

    void Display()
    {
        Node* CurrrentNode = Top;
        if (Top == NULL)
        {
            cout << "Stack UnderFlow" << endl;
        }
        else
        {
            while (CurrrentNode)
            {
                cout << CurrrentNode->data << "\n";
                CurrrentNode = CurrrentNode->next;
            }
        }
        cout << endl;
    }
};







int main()
{
    cout << "Trying Stack with array:" << endl;
    StackArr* mystack = new StackArr(5);
    mystack->Push(1);
    mystack->Push(2);
    mystack->Push(3);
    mystack->Push(4);
    mystack->Push(5);


    cout << "The Peak element at Stack is: " << mystack->Peek() << endl;
    mystack->Display();
    cout << endl;

    mystack->Pop();
    mystack->Pop();
    mystack->Pop();

    cout << "The Peak element at Stack is: " << mystack->Peek() << endl;
    mystack->Display();
    cout << endl;

    cout << "trying Stack with Linked List:" << endl;
    StackLL* stack = new StackLL();
    stack->Push(1);
    stack->Push(2);
    stack->Push(3);
    stack->Push(4);
    stack->Push(5);

    cout << "The Peak element at Stack is: " << stack->Peek() << endl;
    stack->Display();
    cout << endl;

    stack->Pop();
    stack->Pop();
    stack->Pop();

    cout << "The Peak element at Stack is: " << stack->Peek() << endl;
    stack->Display();
    cout << endl;

}
