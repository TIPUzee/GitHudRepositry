#include <iostream>

struct Node
{
	int m_Data;
	Node* m_Next = NULL;
};


class LinkedList
{
private:
	int m_Size = 0;
	Node* m_Head = NULL;
	Node* m_Tail = NULL;

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

		m_Size++;
	}

public:
	//Traversal of the List
	//Print the List (from Start to End) onto the console
	void Traverse()
	{
		// Explaining the Loop
		// for (
		//		TempNode which will Store the Address that the m_Head have; 
		//		Loop until TempNode is not NULL; 
		//		after each Iteration, TempNode will get the address of the Next Node
		//		)
		for (Node* TempNode = m_Head; TempNode != NULL; TempNode = TempNode->m_Next)
		{
			std::cout << TempNode->m_Data << "  ";
		}
	}

};



int main()
{
	LinkedList List;
	List.PushBack(13);
	List.PushBack(14);
	List.PushBack(15);
	List.PushBack(16);
	List.PushBack(17);
	List.PushBack(18);

	List.Traverse();
	
	List.PushBack(19);
	List.PushBack(20);

	List.Traverse();
}