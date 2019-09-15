#include <iostream>
using namespace std;
class FloatList
{
private:
	// Declare a structure for the list
		struct ListNode
		{
		    float value;
		    struct ListNode *next;
        };
        ListNode *head;	// List head pointer
public:
	FloatList(void)	// Constructor
	{ head = NULL; }
	~FloatList(void); // Destructor
	void appendNode(float);
	void deleteNode(float);
	void displayList(void);
};
void FloatList::appendNode(float num)
{
    ListNode *newNode, *nodePtr;
    // Allocate a new node & store num
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = NULL;

    // If there are no nodes in the list
	// make newNode the first node
	if (head == NULL)
        head = newNode;
    else	// Otherwise, insert newNode at end
    {
        // Initialize nodePtr to head of list
        nodePtr = head;
        // Find the last node in the list
        while (nodePtr->next != NULL)
            nodePtr = nodePtr->next;
            // Insert newNode as the last node
        nodePtr->next = newNode;
    }
}

void FloatList::displayList(void)
{
      ListNode  *nodePtr;
      nodePtr = head;
      while (nodePtr != NULL)
      {
           cout << nodePtr->value << endl;
           nodePtr = nodePtr->next;
       }
}

void FloatList::deleteNode(float num)
{
    ListNode *nodePtr, *previousNode;

    // If the list is empty, do nothing.
    if (head == NULL)
        return;
    // Determine if the first node is the one to be deleted
    if (head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
   	else
   	{
   	    // Initialize nodePtr to head of list
   	    nodePtr = head;
   	    // Skip all nodes whose value member is
   	    // not equal to num.
   	    while(nodePtr!= NULL && nodePtr->value != num)
   	    {
   	        previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        //if end of linked list has been reached, and
        //value has not been found
        if(nodePtr == NULL)
            cout<<num<<" not found\n\n";

        // Else if the value has been found
        else
        {   // Link the previous node to the node after
            // nodePtr, then delete nodePtr.
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
	}
}

FloatList::~FloatList(void)
{
    ListNode *nodePtr, *nextNode;
    nodePtr = head;
	while (nodePtr != NULL)
	{
	    nextNode = nodePtr->next;
	    delete nodePtr;
		nodePtr = nextNode;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    FloatList list;
    list.appendNode(44);
    list.appendNode(22);
    list.appendNode(2);
    list.deleteNode(70);

    list.displayList();

    return 0;
}
