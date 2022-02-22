#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}

struct ListNode
{
    int val;
    ListNode *random;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) {};
};

ListNode* createNode(int value)
{
    ListNode *a = new ListNode(value);
    return a;
}

ListNode *insertNode(int value,ListNode* A)
{
    if(A == NULL) 
        return createNode(value);
    else
        A->next = insertNode(value,A->next);
    return A;
}

//////////1
void printList(ListNode *A)
{
    while(A!=NULL)
    {
        cout<<A->val<<" ";
        A =A->next; 
    }
}
//////////2
ListNode* insertAtFront(ListNode *A,int value)
{
    ListNode *curr= createNode(value);
    curr->next =A;
    return curr;
}
//////////3
void insertAtPosition(ListNode*A,int value,int position)
{

    int cnt  = 0;
    ListNode *newNode = createNode(value);
    ListNode *travel = A;
    if(A == NULL)
    {
        A = newNode;
        return;
    }
    if(position == 1 && A!=NULL)
    {
        newNode->next = A;
        
    }
    else
    {
        while(true)
        {
            if(cnt == (position-2))
                break;
            travel = travel->next;
            cnt++;
        }
        newNode->next = travel->next;
        travel->next = newNode;   
    }
}
//////////4
void deleteLastNode(ListNode* A)
{
    ListNode* prev;
    while(A->next!=NULL)
    {
        prev = A;
        A = A->next;
    }
    prev->next = NULL;
}
//////////5
void deleteFrontNode(ListNode* A)
{
    ListNode *curr = A->next;
    A->next = NULL;
    A = curr;
    printList(A);
}
//////////6
int sizeofList(ListNode* A)
{
    int cnt = 0;
    while(A!=NULL)
    {
        cnt++;
        A = A->next;
    }
    return cnt;
}
//////////7
void deleteAtGivenPosition(ListNode* A,int pos)
{
    ListNode* curr = A;
    ListNode* prev;
    if(pos == 1)
    {
        curr = A->next;
        A->next = NULL;
        A = curr;
    }
    else
    {
        pos-=1;
        while(1)
        {
            pos-=1;
            prev = curr;
            curr= curr->next;
            if(pos == 0)
            {
                prev->next = curr->next;
                curr->next = NULL;
                break;
            }
        }
    }
    printList(A);
}
//////////8
ListNode* rotateListClockwiseByKNodes(ListNode*A,int k)
{
    if(A == NULL || k<0) return A;
    int size = sizeofList(A);
    k = k%size;
    if(k==0) return A;
    int i = 1;
    ListNode* tmp  = A;
    while(i<(size-k))
    {
        tmp = tmp->next;
        i++;
    }
    ListNode* mohit = tmp->next;
    tmp->next = NULL;
    ListNode* newhead = mohit;
    while(mohit->next!=NULL)
    {
        mohit = mohit->next;
    }
    mohit->next = A;
    return newhead;
}
//////////9
ListNode *rotateListAntiClockwiseByKNodes(ListNode* A,int k)
{
    if(k<0 || A==NULL) return A;
    int size = sizeofList(A);
    k = k%size;
    if(k==0) return A;
    int i = 1;
    ListNode* tmp = A;
    while(i<k)
    {
        tmp=tmp->next;
        i++;
    }
    ListNode *mohit = tmp->next;
    tmp->next=NULL;
    ListNode *newhead = mohit;
    while(mohit->next!=NULL)
    {
        mohit = mohit->next;
    }
    mohit->next = A;
    return newhead;
}
//////////10
ListNode* reverseLinkedListRecursively(ListNode*A)
{
    if(A == NULL || A->next == NULL) 
    return A;

    ListNode* temp = reverseLinkedListRecursively(A->next);
    A->next->next = A;
    A->next = NULL;

    return temp;
}
//////////11
ListNode* middleNodeOfList(ListNode*A)
{
    if(A == NULL ) return NULL;
    ListNode *p = A;
    ListNode *q = A->next;
    while(q!=NULL && q->next!=NULL)
    {
        p = p->next;
        q = q->next->next;
    }
    return p;
}
//////////12
ListNode * mergeLinkedList(ListNode *firsthalf,ListNode *secondhalf)
{
    if(firsthalf == NULL) return secondhalf;
    if(secondhalf == NULL) return firsthalf;
    ListNode *temp = NULL;
    if(firsthalf->val < secondhalf->val)
    {
        temp = firsthalf;
        firsthalf = firsthalf->next;
    }
    else
    {
        temp= secondhalf;
        secondhalf = secondhalf->next;
    }
    ListNode *finalList = temp;
    while(firsthalf!=NULL && secondhalf!=NULL)
    {
        if(firsthalf->val < secondhalf->val)
        {
            temp->next = firsthalf;
            firsthalf = firsthalf->next;
        }
        else
        {
            temp->next = secondhalf;
            secondhalf = secondhalf->next;
        }
        temp = temp->next;  
    }
    if(firsthalf == NULL) 
        temp->next = secondhalf;
    else
        temp->next = firsthalf;
        
    return finalList;
}
ListNode* sortLinkedList(ListNode*A)
{
    if(A ==NULL || A->next==NULL) return A;
    ListNode *mid = middleNodeOfList(A);
    ListNode* secondhalf = mid->next;
    mid->next = NULL;
    mergeLinkedList(sortLinkedList(A),sortLinkedList(secondhalf));
}
//////////13
ListNode* mergeTwoSortedLinkList(ListNode*A,ListNode *B)
{
    if(A ==NULL) return B;
    if(B ==NULL) return A;
    ListNode *temp = NULL;
    if(A->val< B->val)
    {
        temp = A;
        A = A->next;
    }
    else
    {
        temp = B;
        B = B->next;
    }
    ListNode* finalList = temp;
    while(A!=NULL && B!=NULL)
    {
        if(A->val< B->val)
        {
            temp->next = A;
            A = A->next;
        }
        else
        {
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }
    if(A!=NULL) 
    {
        temp->next = A;
    }
    else
    {
        temp->next = B;
    }
    return finalList;
}
//////////14
ListNode* unionOfTwoList(ListNode*A,ListNode*B)
{
    A = sortLinkedList(A);
    B = sortLinkedList(B);
    if(A == NULL) return B;
    if(B == NULL) return A;
    ListNode *temp = NULL;
    if(A->val < B->val)
    {
        temp = A;
        A = A->next;
    }
    else if(A->val > B->val)
    {
        temp = B;
        B = B->next;
    }
    else
    {
        temp = A;
        A  =A->next;
        B = B->next;
    }
    ListNode *finalList = temp;
    while(A!=NULL && B!=NULL)
    {
        if(A->val< B->val)
        {
            temp->next = A;
            A = A->next;
        }
        else if(A->val > B->val)
        {
            temp->next = B;
            B = B->next;
        }
        else
        {
            temp->next = A;
            A =A->next;
            B=B->next;
        }
        temp = temp->next;
    }
    if(A!=NULL) 
    {
        temp->next = A;
    }
    else
    {
        temp->next = B;
    }
    return finalList;
}
//////////15 yeh problem de rahah hai
ListNode* intersectionOfTwoList(ListNode*A, ListNode*B)
{
    A = sortLinkedList(A);
    B = sortLinkedList(B);
    if(A == NULL || B == NULL) return NULL ;
    ListNode *temp = createNode(0);
    //if(temp!=NULL)
    ListNode* finalList = temp;
    while(A!=NULL && B!=NULL)
    {
        if(A->val< B->val)
        {
            A = A->next;
        }
        else if(A->val > B->val)
        {
            B = B->next;
        }
        else
        {
            temp=A;
            temp = temp->next;
            A = A->next;
            B = B->next;
        }
        //cout<<"mm--";
    }
    finalList = finalList->next;
    return finalList;
}
//////////16
ListNode* getLowestIntersectionNode(ListNode*A,ListNode*B)
{
    A = sortLinkedList(A);
    B = sortLinkedList(B);
    ListNode *temp = NULL;
    while(A!=NULL && B!=NULL)
    {
        if(A->val < B->val) A = A->next;
        else if(A->val > B->val) B = B->next;
        else
        {
            temp = A;
            temp->next = NULL;
            return temp;
        }
    }
    return NULL;
}
//////////17
ListNode* removeDuplicatedFromSortedList(ListNode*A)
{
    if(A == NULL || A->next == NULL) return A;
    if (A->val == A->next->val)
    {
        if(A->next->next!=NULL)
        {
            A->next = A->next->next;
            removeDuplicatedFromSortedList(A);
        }
    }
    else
    {
        removeDuplicatedFromSortedList(A->next);
    }
    return A;
}
//////////18
//uses hashmap
ListNode* removeDuplicatesFromUnsortedList(ListNode*A)
{
    if(A == NULL || A->next ==NULL) return A;
    ListNode *curr = A;
    ListNode *prev = NULL;
    unordered_set<int> uset;
    while(curr!=NULL)
    {
        if(uset.find(curr->val)!= uset.end()) //founded
        {
            prev->next = curr->next;
        }
        else
        {
            uset.insert(curr->val);
        }
        prev= curr;
        curr = curr->next;
    }
    return A;
}
//////////19
ListNode * getKthNode(ListNode*A, int k)
{
    if(A == NULL || A->next==NULL || k<=0)
        return NULL;
    int size = sizeofList(A);
    if(k>size) return NULL;
    int i= 1;
    while(i<k)
    {
        A = A->next;
        i++;
    }
    return A;
}
//////////20
ListNode * getKthNodeFromLast(ListNode*A, int k)
{
    if(A == NULL || A->next==NULL || k<=0)
        return NULL;
    int size = sizeofList(A);
    if(k>size) return NULL;
    int i= 1;
    while(i<=(size-k))
    {
        A = A->next;
        i++;
    }
    return A;
}
//////////21
bool ifLoopPresent(ListNode* A)
{
    if(A == NULL || A->next == NULL) return false;
    ListNode *slow=A;ListNode *fast = A;
    while(fast->next !=NULL && fast->next->next !=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow->val == fast->val)
            return true;
    }
    return false;
}
//////////22
int getLengthofLoop(ListNode *A)
{
    if(A == NULL) return -1;
    ListNode* slow = A;ListNode *fast = A;
    int len = 0;
    while(fast->next !=NULL && fast->next->next !=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow->val == fast->val)
            break;
    }
    if(slow == fast)
    {
        while(slow->next!=fast)
        {
            len++;
            slow = slow->next;
        }
        len+=1;
    }
    return len;
}
//////////23
ListNode* removeLoop(ListNode*A)
{
    if(A == NULL || A->next ==NULL) return 0;
    ListNode* slow=A;
    ListNode* fast =A;
    ListNode* st = A;
    while(fast->next!=NULL && fast->next->next!=NULL) 
    {
        slow = slow->next;
        fast =fast->next->next;
        if(slow->val == fast->val)
        break;
    }
    if(slow == fast)
    {
        ListNode* meetingPt = fast;
        while (A->next != meetingPt->next)
        {
            A=A->next;
            meetingPt = meetingPt->next;
        }
        meetingPt->next = NULL;
    }
    return st;
}
//////////24
ListNode* removeMiddleNode(ListNode *A)
{
    if(A == NULL) return NULL;
    ListNode *slow = A;
    ListNode *fast = A;
    ListNode *slowprev =NULL;
    while(fast!=NULL && fast->next !=NULL)
    {
        slowprev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    slowprev->next = slow->next;
    slow->next = NULL;
    return A;
}
//////////25
bool ifListisPallindrome(ListNode *A)
{
    if(A ==NULL || A->next == NULL) return true;
    ListNode *slow = A;
    ListNode *fast = A;
    ListNode *start = A;
    stack<ListNode*> stk;
    while(fast->next !=NULL && fast->next->next !=NULL )
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    while(start !=slow->next)
    {
        stk.push(start);
        start=start->next;
    }
    if(fast->next == NULL) stk.pop();
    slow = slow->next;
    while(slow!=NULL)
    {
        //cout<<"sl:"<<slow->val<<"  stk "<<stk.top()->val<<endl;
        if(slow->val != stk.top()->val)
            return false;
        else
        {
            stk.pop();
            slow = slow->next;
        }
    }
    return true;
}
//////////26
ListNode* deleteNodeWithGreaterValuesOnTheirRightSide(ListNode*A)
{
    if(A == NULL || A->next == NULL) return A;
    ListNode* rev = reverseLinkedListRecursively(A);
    ListNode* temp = rev;
    int mx = temp->val;
    while(temp->next!=NULL)
    {
        if(temp->next->val >mx)
        {
            mx = temp->next->val;
            temp = temp->next;
        }
        else
        {
            temp->next = temp->next->next;
        }
    }
    A = reverseLinkedListRecursively(rev);
    return A;
}
//////////27
bool checkIfListAreIdentical(ListNode*A,ListNode*B)
{
    if(A == NULL && B == NULL ) return true;
    if(A == NULL || B == NULL ) return false;
    while(A != NULL)
    {
        if(A->val != B->val) return false;
        A = A->next;
        B = B->next;
    }
    return true;
}
//////////28
ListNode* pairwiseSwap(ListNode *A)
{
    ListNode *ans = A;
    if(A ==NULL && A->next == NULL) return A;
    while(A!=NULL && A->next!=NULL)
    {
        int temp  = A->val;
        A->val = A->next->val;
        A->next->val = temp;
        A = A->next->next;
    }
    return ans;
}
//////////29
ListNode* deleteAlternateNode(ListNode *A)
{
    ListNode *ans = A;
    if(A == NULL || A->next==NULL) return A;
    while (A->next!=NULL && A!=NULL)
    {
        A->next = A->next->next;
        A =A->next;
    }
    return ans;
}
//////////30
ListNode* moveLastNodeToFront(ListNode *A)
{
    if(A ==NULL || A->next == NULL) return A;
    ListNode* curr = A;
    ListNode* prev = NULL;
    while (curr->next!=NULL)
    {
        prev=curr;
        curr =curr->next;
    }
    prev->next = NULL;
    curr->next = A;
    return curr;
}
//////////31 Not working
ListNode* swapGivenTwoNodes(ListNode*A,int gv1,int gv2)
{
    if(A == NULL || A->next==NULL) return A;
    ListNode* t1 = A;
    ListNode* t2 = A;
    ListNode* prev1 = NULL;
    ListNode* prev2 = NULL;
    while(t1!=NULL)
    {
        prev1 = t1;
        t1 = t1->next;
        if(t1->val == gv1)
            break;
    }
    ListNode* start =NULL;
    while(t2!=NULL)
    {
        prev2 = t2;
        t2 = t2->next;
        if(t2->val = gv2)
            break;
    }
    if(t1 == NULL || t2==NULL) return start;

    if(prev1!=NULL)
        prev1->next = t2;
    else
        start = t2;

    if(prev2!=NULL)
        prev2->next = t1;
    else
        start = t1;

    ListNode* temp =t1->next;
    t1->next = t2->next;
    t2->next = temp;

    return start;
    
}
//////////32
ListNode* intersectionPointOfTwoLinkedList(ListNode* A,ListNode* B)
{
    if(A == NULL || A->next == NULL || B == NULL || B->next == NULL) return NULL;
    ListNode* Acopy = A;
    ListNode* Bcopy = B;
    int s1 = sizeofList(A);
    int s2 = sizeofList(B);
    if(s1>s2)
    {
        int pp = s1-s2;
        while(pp--)
            Acopy = Acopy->next;
    }
    else
    {
        int cc = s2-s1;
        while(cc--)
            Bcopy = Bcopy->next; 
    }
    while(Acopy!=NULL && Bcopy!=NULL)
    {
        if(Acopy->val == Bcopy->val)
            return Acopy;
    }
    return NULL;
}
//////////33
ListNode* reverseLinkedList(ListNode *A)
{
    if(A == NULL || A->next == NULL) return A;
    ListNode* prev = NULL;
    ListNode* curr = A;
    ListNode* nextnode = NULL;
    while (curr!=NULL)
    {
        nextnode = curr->next;
        curr->next =prev;
        prev = curr;
        curr = nextnode;
    }
    return prev;
}
//////////34
ListNode* reverseInGroupOfKelements(ListNode *A,int k)
{
    if(A == NULL || A->next== NULL || k<0) return A;
    ListNode* prev = NULL;
    ListNode* curr = A;
    ListNode* nextNode = NULL;
    int i = 0;
    while(curr!=NULL && i<k)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev =curr;
        curr = nextNode;
        i++;
    }
    if(nextNode!=NULL)
    {
        A->next = reverseInGroupOfKelements(nextNode,k);
    }
    return prev;
}
//////////35 yeh galat de raha ans
ListNode* reverseInGroupOfKelementsAlternatively(ListNode *A,int k)
{
    if(A ==NULL || A->next==NULL || k<0) return A;
    ListNode* prev = NULL;
    ListNode* curr = A;
    ListNode* nextNode = NULL;
    int i = 0;
    while(curr!=NULL && i<k)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev =curr;
        curr = nextNode;
        i++;
    }
    i = 0 ;
    if(nextNode!=NULL)
    {
        A->next = nextNode;
        curr = nextNode;
        while(curr!=NULL && i< (k-1))
        {
            curr = curr->next;
            i++;
        }
        if(curr!=NULL)
        {
            curr->next = reverseInGroupOfKelementsAlternatively(curr->next,k);
        }
    }
    return prev;
}
//////////36
ListNode* seperateEvenOddNodes(ListNode * A)
{
    if(A ==NULL || A->next == NULL) return A;
    ListNode* evenSt = NULL;
    ListNode* evenEnd = NULL;
    ListNode* oddSt = NULL;
    ListNode* oddEnd = NULL;
    ListNode* curr = A;
    while(curr!=NULL)
    {
        if(curr->val&1)//odd value
        {
            if(oddSt == NULL)
            {
                oddSt = curr;
                oddEnd = oddSt;
            }
            else
            {
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }
        else//even values
        {
            if(evenSt == NULL)
            {
                evenSt = curr;
                evenEnd = evenSt;
            }
            else
            {
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        }
        curr  =  curr->next;
    }
    evenEnd->next = oddSt;
    oddEnd->next=NULL;
    return evenSt;
}
//////////37
ListNode* seperateAlternateNodes(ListNode* A)
{
    if(A ==NULL || A->next == NULL) return A;
    ListNode* firstSt = NULL;
    ListNode* firstEnd= NULL;
    ListNode* secSt = NULL;
    ListNode* secEnd = NULL;
    ListNode* curr = A;
    int cnt = 0;
    while(curr!=NULL)
    {
        if(cnt&1)
        {
            if(firstSt == NULL)
            {
                firstSt = curr;
                firstEnd = firstSt;
            }
            else
            {
                firstEnd->next = curr;
                firstEnd = firstEnd->next;
            }
        }
        else
        {
            if(secSt == NULL)
            {
                secSt  = curr;
                secEnd = secSt;
            }
            else
            {
                secEnd->next = curr;
                secEnd = secEnd->next;
            }
        }
        cnt++; 
        curr = curr->next;
    }
    firstEnd->next = secSt;
    secEnd->next = NULL;
    return firstSt;
}
//////////38
ListNode* pairwiseSwapNodes(ListNode*A )
{
    if(A == NULL || A->next== NULL) return A;
    ListNode* prev = NULL;
    ListNode* curr = A;
    ListNode* nextNode = NULL;
    int i = 0;
    while(curr!=NULL && i<2)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev =curr;
        curr = nextNode;
        i++;
    }
    if(nextNode!=NULL)
    {
        A->next = reverseInGroupOfKelements(nextNode,2);
    }
    return prev;
}
//////////39
ListNode* mergeAlternateNodesOfTwoList(ListNode* A,ListNode* B)
{
    ListNode *temp = NULL;
    if(A == NULL && B==NULL) return NULL;
    if(A == NULL) return B;
    if(B == NULL) return A;
    temp = A;
    A = A->next;
    ListNode * finalList = temp;
    while(A!=NULL && B!=NULL)
    {
        temp->next = B;
        B = B->next;
        temp = temp->next;

        temp->next = A;
        A = A->next;
        temp = temp->next;
    }
    if(A==NULL)
    {
        while(B!=NULL)
        {
            temp->next = B;
            B = B->next;
        }
    }
    else
    {
        while (A!=NULL)
        {
            temp->next = A;
            A = A->next;
        }
        
    }
    
    return finalList;
}
//////////40
int getNumberAfterAddingOneToList(ListNode* A)
{
    if(A == NULL) return 1;
    int rs = A->val + getNumberAfterAddingOneToList(A->next);
    A->val = rs%10;
    return rs/10;
}
ListNode* PlusOneLinkedList(ListNode *A)
{
    int c = getNumberAfterAddingOneToList(A);
    if (c == 1)
    {
        ListNode *begin = createNode(1);
        begin->next = A;
        return begin;
    }
    return A;
}
//////////41 vry imp
ListNode* addTwoLinkedList(ListNode *A,ListNode *B)
{
    if(A == NULL) return B;
    if(B == NULL) return A;
    A = reverseLinkedList(A);
    B = reverseLinkedList(B);
    int dig = (A->val + B->val )%10;
    int carry = (A->val + B->val)/10;
    ListNode *temp = createNode(dig);
    ListNode *finalList = temp;
    while(A->next!=NULL && B->next!=NULL)
    {
        A = A->next;
        B = B->next;
        dig = (A->val + B->val +carry )%10;
        carry = (A->val + B->val+carry)/10;
        temp->next = createNode(dig);
        temp = temp->next;
    }
    if(A->next==NULL)
    {
        while(B->next!=NULL)
        {
            B=B->next;
            dig = (B->val+carry)%10;
            carry = (B->val+carry)/10;
            temp->next = createNode(dig);
            temp = temp->next;
        }
    }
    else if(B->next==NULL)
    {
        while (A->next!=NULL)
        {
            A = A->next;
            dig = (A->val + carry)%10;
            carry = (A->val + carry)/10;
            temp->next = createNode(dig);
            temp= temp->next;
        }
        
    }
    
    if(carry > 0)
    temp->next = createNode(carry);
    finalList = reverseLinkedList(finalList);
    return finalList;
}
//////////42 very imp
ListNode* subtractTwoLinkedList(ListNode *A,ListNode *B)
{
    if(A == NULL) return B;
    if(B == NULL) return A;
    int size1 = sizeofList(A);
    int size2 = sizeofList(B);
    if(size2>size1)
    {
        ListNode *t = A;
        A = B;
        B = t;
    }
    A = reverseLinkedList(A);
    B = reverseLinkedList(B);
    int dig = 0;
    int carry = 0;
    ListNode *temp = NULL;
    if(A->val-carry >= B->val)
    {
        dig = A->val - B->val;
        carry = 0;
        temp = createNode(dig);
    }
    else
    {
        dig = (A->val-carry)+10 - B->val;
        carry = 1;
        temp = createNode(dig);
    }
    ListNode *finalList = temp;
    while(A->next!=NULL && B->next!=NULL)
    {
        A= A->next;
        B = B->next;
        if(A->val-carry >= B->val)
        {
            dig = A->val-carry- B->val;
            carry = 0;
            temp->next = createNode(dig);
        }
        else
        {
            dig = (A->val-carry)+10 - B->val;
            carry = 1;
            temp->next = createNode(dig);
        }
        temp = temp->next;
    }
    if(B->next == NULL)
    {
        while(A->next!=NULL)
        {
            A = A->next;
            dig = A->val - carry;
            temp->next = createNode(dig);
            temp = temp->next;
        }
    }
    finalList = reverseLinkedList(finalList);
    return finalList;
}
//////////43
ListNode* makeMiddleNodeAsHead(ListNode *A)
{
    if(A == NULL || A->next == NULL) return A;
    ListNode* slow = A;
    ListNode* fast = A->next;
    ListNode* prev = NULL;
    ListNode* head = A;
    while(fast!=NULL && fast->next!=NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    slow->next = head;
    head = slow;
    return head;
}
//////////44 
ListNode* insertGivenNodeAtMiddle(ListNode* A,int gV)
{
    ListNode* temp = createNode(gV);
    if(A == NULL || A->next==NULL) return A;
    ListNode *slow = A;
    ListNode *fast = A->next;
    ListNode *slowprev = NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        slowprev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    slowprev->next = temp;
    temp->next = slow;
    return A;
}
//////////45
ListNode* intersectionOfTwoListHashing(ListNode * A,ListNode* B)
{
    if(A == NULL && B==NULL) return NULL;
    if(A == NULL || B==NULL ) return NULL;
    ListNode *temp = createNode(0);
    ListNode* ans = temp;
    unordered_map<int,int> ump;
    while (A!=NULL)
    {
        if(ump.find(A->val)==ump.end())
        {
            ump[A->val]=1;
        }
        A = A->next;
    }   
    while(B!=NULL)
    {
        if(ump.find(B->val)!=ump.end())
        {
            temp->next = createNode(B->val);
            temp = temp->next;
        }
        B = B->next;
    }
    ans = ans->next;
    //printList(temp);
    return ans;
}
//////////46
int countPairOfGivenSumFromTwoLinkedList(ListNode* A,ListNode*B,int givenSum)
{
    if(A == NULL && B == NULL) return 0;
    unordered_map<int,int> umap;
    while(B!=NULL)
    {
        if(umap.find(B->val)== umap.end())
            umap[B->val]=1;
        B= B->next;
    }
    int ans = 0;
    while(A!=NULL)
    {
        if(umap.find(givenSum - (A->val))!=umap.end())
            ans++;
        A = A->next;
    }
    return ans;
}   
//////////47
int sumOfLastNnodes(ListNode*A,int n)
{
    if(A== NULL) return 0;
    ListNode *back = A;
    ListNode *forw = A;

    while(n--)
        forw = forw->next;

    while(forw!=NULL)
    {
        forw = forw->next;
        back = back->next;
    }
    int s =0;
    while(back!=NULL)
    {
        s+= back->val;
        back = back->next;
    }
    return s;
}
//////////48
ListNode* removeEveryKthNode(ListNode *A,int k)
{
    if(A==NULL || k<=1) return NULL;
    ListNode* prev = NULL;
    ListNode* ans = A;
    int cnt = 1;
    while(A!=NULL)
    {
        prev = A;
        if((cnt+1)%k == 0)
        {
            A = A->next;
            prev->next = prev->next->next;
            cnt++;
        }
        cnt++;
        A = A->next;
    }
    return ans;
}
//////////49
void deleteThisOnlyNode(ListNode *A)
{
    if(A->next == NULL || A==NULL) return;
    A->val = A->next->val;
    A->next = A->next->next;
}
//////////50
ListNode* deleteLastOccurenceOfGivenNode(ListNode* A,int gV)
{
    if(A == NULL) return NULL;
    ListNode *start = A;
    ListNode *finalans = A;
    ListNode *temp = NULL;
    while (A!=NULL)
    {
        if(A->val == gV)
            temp = A;
        A = A->next;
    }
    if(temp == NULL) return start;
    if(temp == start)
    {
        start= start->next;
        return start;
    }
    if(temp->next == NULL)
    {
        while(start->next->next!=NULL)
            start = start->next;
        start->next = NULL;
        return finalans;
    }
    temp->val = temp->next->val;
    temp->next = temp->next->next;
    return start;
    
}
//////////51 need to work again
ListNode* sortingAnAbsoluteSortedList(ListNode* A)
{
    if(A ==NULL || A->next == NULL) return A;
    ListNode* posSt = NULL;
    ListNode* posEnd = NULL;
    ListNode* negSt = NULL;
    ListNode* negEnd = NULL;
    ListNode* curr = A;
    while(curr!=NULL)
    {
        if(curr->val < 0)//neg value
        {
            if(negSt == NULL)
            {
                negSt = curr;
                negEnd = negSt;
            }
            else
            {
                negEnd->next = curr;
                negEnd = negEnd->next;
            }
        }
        else//pos values
        {
            if(posSt == NULL)
            {
                posSt = curr;
                posEnd = posSt;
            }
            else
            {
                posEnd->next = curr;
                posEnd = posEnd->next;
            }
        }
        curr  =  curr->next;
    }
    negSt = reverseLinkedList(negSt);
    negSt->next = posSt;
    posEnd->next=NULL;
    //printList(negSt);
    printList(negEnd);
    printList(posSt);
    //printList(posEnd);
    return negSt;
}
//////////52
ListNode* clonningTheListRandomPionter(ListNode*A)
{
    if(A == NULL) return A;
    ListNode* curr = A;
    ListNode* clonecurr = NULL;
    unordered_map<ListNode*,ListNode*> umap;
    while (curr!=NULL)
    {
        clonecurr = createNode(curr->val);
        umap[curr]=clonecurr;
        curr = curr->next;
    }
    curr = A;
    while(curr!=NULL)
    {
        clonecurr = umap[curr];
        clonecurr->next = umap[curr->next];
        clonecurr->random = umap[curr->random];
        curr = curr->next;
    }
    return A;
}
//////////53
ListNode* mergeTwoSortedLinkListInReverseOrder(ListNode*A,ListNode*B)
{
    if(A ==NULL && B == NULL) return NULL;
    ListNode *temp = NULL;
    if(A->val< B->val)
    {
        temp = A;
        A = A->next;
    }
    else
    {
        temp = B;
        B = B->next;
    }
    temp->next = NULL;
    ListNode* finalList = temp;
    while(A!=NULL && B!=NULL)
    {
        if(A->val< B->val)
        {
            ListNode* alpha = createNode(A->val);
            alpha->next = temp;
            temp = alpha;
            A = A->next;
        }
        else
        {
            ListNode* beta = createNode(B->val);
            beta->next = temp;
            temp = beta;
            B = B->next;
        }
        //temp = temp->next;
    }
    if(B!=NULL) 
    {
        while(B!=NULL)
        {
            ListNode* beta = createNode(B->val);
            beta->next = temp;
            temp = beta;
            B = B->next;
        }
    }
    else
    {
        while(A!=NULL)
        {
            ListNode* alpha = createNode(A->val);
            alpha->next = temp;
            temp = alpha;
            A = A->next;
        }
    }
    return temp; 
}
//////////54
ListNode* moveAllOccurenceOfElementToLast(ListNode* A,int gV)
{
    if(A == NULL) return NULL;
    ListNode* last  = A;
    while(last->next!=NULL)
        last = last->next;
    ListNode* curr = A;
    ListNode* tail = last;
    ListNode* prev = NULL;
    while(curr!=tail)
    {
        if(curr->val ==  gV && prev!=NULL)
        {
            ListNode* nextNode = curr->next;
            prev->next = curr->next;
            last->next = curr;
            last = last->next;
            curr->next = NULL;
            curr = nextNode;
        }
        else if(curr->val == gV && prev == NULL)
        {
            ListNode* nextNode = curr->next;
            last->next = curr;
            curr->next = NULL;
            last = last->next;
            curr = nextNode;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return A;
}
//////////55
ListNode* zigzagList(ListNode* A)
{
    if(A == NULL || A->next==NULL) return A;
    ListNode* curr = A;
    bool f = true;
    while (curr->next!=NULL)
    {
        if(f == true)
        {
            if(curr->val > curr->next->val)
            {
                int temp = curr->val;
                curr->val = curr->next->val;
                curr->next->val = temp;
            }
        }
        else
        {
            if(curr->val < curr->next->val)
            {
                int temp = curr->val;
                curr->val = curr->next->val;
                curr->next->val = temp;
            }
        }
        curr = curr->next;
        f = !f;
    }
    return A;
}
//////////56
ListNode* rearrangeListInPlace(ListNode *A)
{
    if(A == NULL ) return NULL;
    ListNode* first = A;
    ListNode* mid = middleNodeOfList(A);
    ListNode* second = mid->next;
    ListNode* ans = createNode(0); 
    mid->next = NULL;
    second = reverseLinkedList(second);
    while(first!=NULL || second!=NULL)
    {
        if(first!=NULL)
        {
            ans->next = first;
            first = first->next;
            ans = ans->next;
        }
        if(second!=NULL)
        {
            ans->next = second;
            second = second->next;
            ans = ans->next;
        }
    }

    ListNode*finalList = ans->next;
    return finalList;
}
//////////57
ListNode* pointToNextGreaterNodeWithRandomPointer(ListNode* A)
{
    if(A == NULL) return NULL;
    ListNode* curr = A;
    while (curr!=NULL)
    {
        curr->random = curr->next;
        curr = curr->next;
    }
    A = sortLinkedList(A);
    return A;
}
//////////58
int getCommonElementCount(ListNode *a,ListNode* b)
{
    if(a == NULL || b == NULL ) return 0;

    int ans = 0;
    while(a!=NULL && b!=NULL)
    {
        if(a->val == b->val)
        {
            ans++;
        }
        else
        {
            break;
        }
        a=a->next;
        b=b->next;
    }
    return ans;
}
int lengthOfLongestPallindromicList(ListNode *A)
{
    if(A == NULL) return 0;
    if(A->next == NULL) return 1;

    ListNode* prev =NULL;
    ListNode* curr = A;
    ListNode* nextNode = NULL;
    int res = 1;

    while(curr!=NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        res = max(res, 2* getCommonElementCount(prev,nextNode)+1);
        res = max(res, 2* getCommonElementCount(curr,nextNode));
        prev = curr;
        curr = nextNode;
    }
    return res;
}
//////////59
pair<int,int> minMaxElementOfList(ListNode* A)
{
    pair<int,int> ans;
    if(A == NULL)
    {
        ans.first = 0;
        ans.second = 0;
    }
    ans.first = INT_MAX;
    ans.second =INT_MIN;
    while(A!=NULL)
    {
        ans.first = min(ans.first,A->val);
        ans.second = max(ans.second,A->val);
        A = A->next;
    }
    return ans;
}
//////////60
ListNode* deleteLargetNode(ListNode *A)
{
    if(A == NULL || A->next == NULL) return NULL;
    ListNode *prev = NULL;
    ListNode *curr = A;
    ListNode *prevlarge = NULL;
    ListNode *large = A;
    int mx = INT_MIN;
    while(curr!=NULL)
    {
        if(curr->val > mx)
        {
            mx = curr->val;
            large = curr;
            prevlarge = prev;
        }
        prev = curr;
        curr = curr->next;
    }
    if(large->next!=NULL && prevlarge!=NULL) //middle node
    {
        prevlarge->next = large->next;
        large->next = NULL;
    }
    else if(large->next!=NULL && prevlarge==NULL) //st node
    {
        A = A->next;
    }
    else  //end node
        prevlarge->next = NULL;
    
    return A;
}
//////////61
ListNode* reverseListFromGivenPosition(ListNode *A,int st,int en)
{
    if(A == NULL || st<0 || en<0 || st>en) return NULL;
    ListNode* curr = A;
    ListNode* prev = NULL;

    for(int i =1 ; curr!=NULL && i<st;i++)
    {
        prev=curr;
        curr = curr->next;
    }
    if(curr == NULL) return A;

    ListNode* prevSt = prev;
    ListNode* prevEnd  = curr;
    ListNode* nextNode = NULL;

    for(int i= 0;curr!=NULL && i<= en-st ; i++)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    if(st !=1)
        prevSt->next = prev;
    prevEnd->next = curr;

    return st==1?prev:A;
}

int main()
{
    ios::sync_with_stdio(false);
    ListNode *head = NULL;
    head = insertNode(1,head);
    head = insertNode(2,head);
    head = insertNode(3,head);
    head = insertNode(2,head);
    head = insertNode(1,head);
    head = insertNode(3,head);
    //head = insertNode(68,head);
    //head->next->next->next->next->next = head->next;
    ListNode *head2 = NULL;
    head2 = insertNode(211,head2);
    head2 = insertNode(4,head2);
    head2 = insertNode(1502,head2);
    head2 = insertNode(27,head2);
    head2 = insertNode(67,head2);

    cout<<"Original List 1 = ";
    printList(head);
    cout<<endl;
    cout<<"Original List 2 = ";
    printList(head2);
    cout<<endl;
    //head = insertNode(22,head);
    //printList(head);
    // head = insertAtFront(head,44);
    // printList(head);
    //insertAtPosition(head,36,1);
    //deleteLastNode(head);
    //deleteFrontNode(head); print in the funvtion
    //printList(head);
    //deleteAtGivenPosition(head,3);
    // int c = sizeofList(head);
    // cout<<c<<endl;
    // ListNode *ans = rotateListClockwiseByKNodes(head,2);
    // printList(ans);
    // ListNode *ans = rotateListAntiClockwiseByKNodes(head,3);
    // printList(ans);
    // ListNode *ans = reverseLinkedListRecursively(head);
    // printList(ans);
    // ListNode* es = middleNodeOfList(head);
    // cout<<es->val<<endl;
    // ListNode* sortedList = sortLinkedList(head);
    // printList(sortedList);
    ListNode *mergedlist = mergeTwoSortedLinkList(head,head2);
    printList(mergedlist);
    // ListNode* ans = intersectionOfTwoList(head,head2);
    // printList(ans);
    // ListNode* re = getLowestIntersectionNode(head,head2);
    // cout<<re->val<<endl;
    // ListNode * rt = removeDuplicatedFromSortedList(head);
    // printList(head);
    // ListNode* yu = removeDuplicatesFromUnsortedList(head);
    // printList(yu);
    // ListNode* ui = getKthNode(head2,3);
    // cout<<ui->val<<endl;
    // ListNode* io = getKthNodeFromLast(head2,3);
    // cout<<io->val<<endl;
    // bool tt = ifLoopPresent(head);
    // cout<<tt<<endl;
    // int op = getLengthofLoop(head);
    // cout<<op<<endl;
    // ListNode* as =removeLoop(head);
    // printList(as);
    // ListNode *sd = removeMiddleNode(head);
    // printList(sd);
    // bool df = ifListisPallindrome(head);
    // cout<<df<<endl;
    // ListNode *fg = deleteNodeWithGreaterValuesOnTheirRightSide(head);
    // printList(fg);
    // ListNode *gh = pairwiseSwap(head);
    // printList(gh);
    // ListNode*hj = deleteAlternateNode(head);
    // printList(hj);
    // ListNode *jk = moveLastNodeToFront(head);
    // printList(jk);
    // ListNode *kl = swapGivenTwoNodes(head,99,39);
    // printList(kl);
    // ListNode *zx = intersectionPointOfTwoLinkedList(head,head2);
    // cout<<zx->val<<endl;
    // ListNode *xc = reverseLinkedList(head);
    // printList(xc);
    // ListNode *cv = reverseInGroupOfKelements(head,3);
    // printList(cv);
    // ListNode *vb = reverseInGroupOfKelementsAlternatively(head,2);
    // printList(vb);
    // ListNode* bn = seperateEvenOddNodes(head);
    // printList(bn);
    // ListNode* nm  = seperateAlternateNodes(head);
    // printList(nm);
    // ListNode* qw = pairwiseSwapNodes(head);
    // printList(qw);
    // ListNode * we = mergeAlternateNodesOfTwoList(head,head2);
    // printList(we);
    // ListNode * qwe = PlusOneLinkedList(head);
    // printList(qwe);
    // ListNode* wer = addTwoLinkedList(head,head2);
    // printList(wer);
    // ListNode *ert = subtractTwoLinkedList(head,head2);
    // printList(ert);
    // ListNode* tyu = makeMiddleNodeAsHead(head);
    // printList(tyu);
    // ListNode* yui = insertGivenNodeAtMiddle(head,100);
    // printList(yui);
    // ListNode* uio = intersectionOfTwoListHashing(head,head2);
    // printList(uio);
    // int iop = countPairOfGivenSumFromTwoLinkedList(head,head2,24);
    // cout<<iop<<endl;
    // int asd = sumOfLastNnodes(head,3);
    // cout<<asd<<endl;
    // ListNode* sdf = removeEveryKthNode(head,3);
    // printList(sdf);
    // ListNode* dfg = deleteLastOccurenceOfGivenNode(head,13);
    // printList(dfg);
    // ListNode*  fgh = sortingAnAbsoluteSortedList(head);
    // printList(fgh);
    // ListNode* ghj = mergeTwoSortedLinkListInReverseOrder(head,head2);
    // printList(ghj);
    // ListNode* hjk = moveAllOccurenceOfElementToLast(head,2);
    // printList(hjk);
    // ListNode *jkl = zigzagList(head);
    // printList(jkl);
    // ListNode* zxc = rearrangeListInPlace(head);
    // printList(head);
    // ListNode *xcv = pointToNextGreaterNodeWithRandomPointer(head);
    // printList(xcv);
    // int cvb = lengthOfLongestPallindromicList(head);
    // cout<<"length = "<<cvb<<endl;
    // pair<int,int> vbn= minMaxElementOfList(head2);
    // cout<<vbn.first<<" "<<vbn.second<<endl;
    // ListNode *bnm = deleteLargetNode(head2);
    // printList(bnm);
    // ListNode *qwer = reverseListFromGivenPosition(head2,2,4);
    // printList(qwer);
    return 0;

}