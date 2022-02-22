		
#include <bits/stdc++.h> 
using namespace std; 

class Node{
	public:
	int data;
	Node *next;
};

void insertAtFront(Node **head_ref,int newdata)
{
	Node *newNode = new Node();
	newNode->data = newdata;
	newNode->next = *(head_ref);
	*(head_ref) = newNode;
}

void insertAtIndex(Node **head_ref,int newdata,int index)
{
	int cnt=0;
	Node *newNode = new Node();
	Node *travel = *(head_ref);
	newNode->data = newdata;
	if(*head_ref == NULL)
	{
		*head_ref = newNode;
		return;
	}
	while(1)
	{
		if(cnt ==(index-2))
		break;
		travel = travel->next;
		cnt++;
		//cout<<"yo";
	}
	newNode->next = travel->next;
	travel->next = newNode;
}

void insertAtLast(Node **head_ref,int newdata)
{
	Node *newNode = new Node();
	Node *last = *head_ref;
	newNode->data = newdata;
	newNode->next =NULL;
	if(*(head_ref)==NULL)
	{
		*head_ref = newNode;
		return;
	}
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next =newNode;
	return;
}

void deleteNode(Node **head_ref, int key)
{
	Node *traverse = *(head_ref),*prev;

	if(traverse->data == key && traverse != NULL)
	{
		*(head_ref)= traverse->next;
		traverse->next = NULL;
		free(traverse);
		return;
	}
	while(traverse->data != key)
	{
		prev =traverse;
		traverse = traverse->next;
		//cout<<"uo";
	}
	prev->next = traverse->next;
	traverse->next = NULL;
	return;
}

void searchNode(Node **(head_ref),int key )
{
	Node *traverse= *(head_ref);
	while(traverse->next != NULL)
	{
		if(traverse->data == key)
		{
			cout<<"FOundded"<<endl;
			return;
		}
		else
		traverse=traverse->next;
	}
	cout<<"Not founded"<<endl;
	return;
}

void printList(Node *n)
{
	while(n!=NULL)
	{
		cout<<n->data<<"->";
		n=n->next;
	}
	cout<<endl;
}

void printReverse(Node **head_ref)
{
	Node *last = *(head_ref);
	stack<int> s;
	while(last !=NULL)
	{
		s.push(last->data);
		last=last->next;
	}
	while(s.empty() == false)
	{
		cout<<s.top()<<"<-";
		s.pop();
	}
	cout<<endl;
}

void reverseList(Node **head_ref)
{
	Node *current = *(head_ref);
	Node *prev = NULL , *next = NULL;
	while(current != NULL)
	{
		next= current->next;
		current->next = prev;
		prev = current;
		current =next;
	}
	*head_ref = prev;
	return ;
}
Node* swap(Node *p1 , Node *p2)
{
	Node *temp = p2->next;
	p2->next = p1;
	p1->next = temp;
	return p2;
}
int bubbleSort(Node **head_ref,int size)
{
	Node **h;
	for(int i=0;i<=size;i++)
	{	

		int swapp=0;
		for(int j=0;j< size-i-1;j++)
		{
			h = head_ref;
			Node *back = *h;
			Node *forth = back->next;
			if(back->data > forth->data)
			{
				*h = swap(back,forth);
				swapp =1;
			}
			h = &(*h)->next;
		}
		if (swapp = 0)
		break;
	}
}

/* Driver code*/
int main() 
{ 
	Node *head=NULL;
	int v1,value,v2,v3,v4,v5,delkey,searchkey;
	cin>>v1>>v2>>v3>>v4>>v5;
	insertAtLast(&head, v1);
	insertAtLast(&head, v2);
	insertAtLast(&head, v3);
	insertAtLast(&head, v4);
	insertAtLast(&head, v5);
	printList(head);
	//cin>>value;
	//insertAtIndex(&head, value,4);
	//printList(head);
	//cin>>delkey;
	// deleteNode(&head,delkey);
	// printList(head);
	// cin>>searchkey;
	// searchNode(&head,searchkey);
	//printReverse(&head);
	//reverseList(&head);
	//printList(head);
	bubbleSort(&head,5);
	printList(head);
	return 0; 
} 

