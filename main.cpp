#include <iostream>
using namespace std;

struct Linked_List
{
    struct Node
    {
        int data;
        Node* next;
        Node* prev;
        Node(int x) : data(x),next(nullptr),prev(nullptr) {}
    };

    Node* head;
    Node* tail;


    Linked_List() : head(nullptr),tail(nullptr) {}

    Node* Insert_Node(Node* Input_Node,int Input_Data)
    {
        if(Input_Node == nullptr)
        {
            Input_Node = new Node(Input_Data);
            tail = Input_Node;
            //std::cout << tail << std::endl;
            return Input_Node;
        }
        Input_Node->next = Insert_Node(Input_Node->next,Input_Data);
        Input_Node->next->prev = Input_Node;
        return Input_Node;
    }

    void insert(int Input_Data)
    {
        head = Insert_Node(head,Input_Data);
    }

    void Show_Head()
    {
        Node* temp = head;
        while(temp!=nullptr)
        {
            std::cout << "{" << temp->data << "} ";
            temp = temp->next;
        }
            std::cout << "\n";
        
    }

    void Show_Tail()
    {
        Node* temp = tail;
        while(temp!=nullptr)
        {
            std::cout << "{" << temp->data << "} ";
            temp = temp->prev;
        }
        std::cout << "\n";
    }


};



int main()
{
    Linked_List t;
    t.insert(4);
    t.insert(21);
    t.insert(43);
    t.Show_Head();
    t.Show_Tail();

    

}