#include <iostream>

struct Node
{
    int m_Data;
    Node *m_Next = NULL;
};

class LinkedList
{
private:
    int m_Size = 0;
    Node *m_Head = NULL;
    Node *m_Tail = NULL;

public:
    //Insertion in the Linked List
    //Note: Insertion at the End of the List
    void PushBack(int Item)
    {
        if (m_Size == 0)
        {
            m_Head = new Node;
            m_Head->m_Data = Item;
            m_Tail = m_Head;
        }
        else
        {
            m_Tail->m_Next = new Node;
            m_Tail->m_Next->m_Data = Item;
            m_Tail = m_Tail->m_Next;
        }

        ++m_Size;
    }

public:
    //Traversal of the List
    //Print the List (from Start to End) onto the console
    void Traverse()
    {

        if (m_Size == 0)
        {
            std::cout << "[WARNING]: LIST IS EMPTY. CANNOT TRAVERSE!" << std::endl;
            return; //Exit the current function, Cause No Need to Continue (to Traversal)
        }

        // Explaining the Loop
        // for (
        //		TempNode which will Store the Address that the m_Head have;
        //		Loop until TempNode is not NULL;
        //		after each Iteration, TempNode will get the address of the Next Node
        //		)
        for (Node *TempNode = m_Head; TempNode != NULL; TempNode = TempNode->m_Next)
        {
            std::cout << TempNode->m_Data << "  ";
        }
        std::cout << std::endl;
    }

    void PopBack()
    {
        if (m_Size == 0)
        {
            std::cout << "[WARNING]: LIST IS EMPTY. CANNOT POP!" << std::endl;
            return; //Exit the current function, Cause No Need to Continue (to pop operation)
        }

        else if (m_Size == 1)
        {
            delete m_Head;
            m_Head = m_Tail = NULL;
        }

        else    // if List Size if greater than 1, then we have to find the 2nd last Node
        {
            Node *TempNode;
            for (TempNode = m_Head; TempNode->m_Next != m_Tail; TempNode = TempNode->m_Next)
                ;

            delete TempNode->m_Next;
            TempNode->m_Next = NULL;
            m_Tail = TempNode;
        }

        --m_Size;
    }

public:
    int Size()
    {
        return m_Size;
    }
};

int main()
{
    LinkedList List;

    std::cout << "Size: " << List.Size() << std::endl; // Size should be 0
    List.Traverse();

    List.PushBack(13);
    List.PushBack(14);
    List.PushBack(15);
    List.PushBack(16);
    List.PushBack(17);
    List.PushBack(18);

    List.Traverse();
    std::cout << "Size: " << List.Size() << std::endl; // Size should be 6

    List.PushBack(19);
    List.PushBack(20);

    List.Traverse();
    std::cout << "Size: " << List.Size() << std::endl; // Size should be 8

    List.PopBack();

    List.Traverse();
    std::cout << "Size: " << List.Size() << std::endl; // Size should be 7

}
