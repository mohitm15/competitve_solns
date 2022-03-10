#include<bits/stdc++.h>
using namespace std;
#define ll long long int

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
int absolute(int a,int b)
{
	if (a>=b) return a-b;
	else return b-a;
}

struct TreeNode 
{
    int val;
	int heightofnode;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Insert function definition. 
TreeNode* createNode(int value)
{
	TreeNode* a = new TreeNode(value);
	// a->val = value;
	// a->left = NULL;
	// a->right = NULL;
	return a;
}
///////////////////////1
TreeNode* insertNode(TreeNode *root, int value) 
{ 
	if(!root) 
	    return new TreeNode(value); 
	 

	if(value > root->val) 
		root->right = insertNode(root->right, value); 
	else
		root->left = insertNode(root->left, value); 
	
    return root; 
} 
/////////////////////2
void Inorder(TreeNode *root) 
{ 
	if(!root) 
	{ 
		return; 
	} 
	Inorder(root->left); 
	cout << root->val << endl; 
	Inorder(root->right); 
} 	
/////////////////////3
void inorderWithVectorUtil(TreeNode *A,vector<int> &vec)
{
	if(A == NULL) return ;
	//vec.push_back(A->val); //preorder
	inorderWithVectorUtil(A->left,vec);
	vec.push_back(A->val);  //inorder
	inorderWithVectorUtil(A->right,vec);
	//vec.push_back(A->val);//postorder
}
vector<int> inorderWithVector(TreeNode*A)
{
	vector<int> ans;
	inorderWithVectorUtil(A,ans);
	return ans;
}
/////////////////////4
int sumOfAllNodes(TreeNode* A)
{
	if(A == NULL) return 0;
	return A->val + sumOfAllNodes(A->left)+sumOfAllNodes(A->right);
}
/////////////////////5
int diffOfEvenOdddLevelValuesSum(TreeNode *A)
{	
	if(A==NULL) return 0;
	return A->val - diffOfEvenOdddLevelValuesSum(A->left) - diffOfEvenOdddLevelValuesSum(A->right);
}
/////////////////////6
int numberOfAllNodes(TreeNode* A)
{
	if(A == NULL) return 0;
	return 1 + numberOfAllNodes(A->left)+numberOfAllNodes(A->right);
}
/////////////////////7
int numberOfLeafNodes(TreeNode* A)
{
	if(A == NULL) return 0;
	if(A->left == NULL && A->right == NULL) return 1;
	return numberOfLeafNodes(A->left)+numberOfLeafNodes(A->right);
}
/////////////////////8
int heightofTree(TreeNode *A)	//IMPORTANT
{
	if(A == NULL) return -1;
	return max(heightofTree(A->left),heightofTree(A->right))+ 1;
}
/////////////////////
void printElementsAtGivenLevel(TreeNode *A,int level)
{
	if(A == NULL) return;
	if(level == 1) cout<<A->val<<"d ";
	printElementsAtGivenLevel(A->left,level-1);
	printElementsAtGivenLevel(A->right,level-1);
}
////////////////
void printLevelOrder(TreeNode*A)
{
	if(A == NULL) return;
	int h = heightofTree(A);
	for(int i = 0;i<=h;i++)
	{
		printElementsAtGivenLevel(A,i+1);
		cout<<endl;
	}
}

void printLevelOrderUsingQueue(TreeNode* A)	//IMPORTANT
{
	if(A == NULL) return ;
	queue<TreeNode*> q;
	q.push(A);
	while(true)
	{
		int cnt = q.size();
		if(cnt == 0)
			break;
		while(cnt>0)
		{
			TreeNode *queuefirst = q.front();
			q.pop();
			cout<<queuefirst->val<<" ";
			if(queuefirst->left !=NULL)
				q.push(queuefirst->left);
			if(queuefirst->right !=NULL)
				q.push(queuefirst->right);
			cnt--;
		}
		cout<<endl;
	}
}
////////////// in reverse order
void printLevelReverseOrderUsingQueue(TreeNode* A) {
	if(A==NULL) return;
	queue<TreeNode*> q;
	stack<TreeNode*> s;
	q.push(A);
	while(true)
	{
		int cnt = q.size();
		if(cnt == 0) break;
		while(cnt > 0) {
			TreeNode *queuefront = q.front();
			q.pop();
			//cout<<queuefront->val<<" ";
			s.push(queuefront);
			if(queuefront->right != NULL) 
				q.push(queuefront->right);
			if(queuefront->left != NULL ) 
				q.push(queuefront->left);
			cnt--;
		}
		//cout<<endl;
	}
	while(s.size() != 0) {
		if(s.size() == 1) //to avoid last comma in answer
			cout<<s.top()->val;
		else
			cout<<s.top()->val<<", ";
		s.pop();
	}
	cout<<endl;
}
////////////////////
int maxLevelleft = 0;
void leftView(TreeNode* A,int currentlevel)	//IMPORTANT
{
	if(A == NULL) return ;
	//cout<<"AT "<<A->val<<" : cv - "<<currentlevel<<" , maxl - "<<maxLevelleft<<endl;
	if(currentlevel>=maxLevelleft)
	{
		cout<<A->val<<" ";
		maxLevelleft++; 
	}
	leftView(A->left,currentlevel+1);
	leftView(A->right,currentlevel+1);
}
//////////////////
int maxLevelRight=0;
void rightView(TreeNode*A ,int currentLevel)
{
	if(A == NULL) return ;
	
	if(currentLevel>=maxLevelRight)
	{
		cout<<A->val<<" ";
		maxLevelRight++;
	}
	rightView(A->right,currentLevel+1);
	rightView(A->left,currentLevel+1);
}
/////////////////////

void inorderWithoutRecursion(TreeNode* A)	//IMPORTANT
{
	if (A == NULL) return ;

	stack<TreeNode* > stk;
	while (A!=NULL)
	{
		stk.push(A);
		A = A->left;
	}
	while (stk.size()>0)
	{
		cout<<stk.top()->val<<" ";
		TreeNode *t = stk.top();
		stk.pop();
		if(t->right!=NULL)
		{
			TreeNode* temp = t->right;
			while(temp!=NULL)
			{
				stk.push(temp);
				//cout<<stk.top()->val<<" ";
				temp = temp->left;
			}
		}
	}

}
/////////////////////
void postorderWithoutRecursion(TreeNode* A)	//IMPORTANT
{
	if(A == NULL) return ;
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	s1.push(A);
	while(s1.size()>0)
	{
		TreeNode* t = s1.top();
		s1.pop();
		if(t->left != NULL) s1.push(t->left);
		if(t->right != NULL) s1.push(t->right);
		s2.push(t);
	}
	while(!s2.empty())
	{
		cout<<s2.top()->val<<" ";
		s2.pop();
	}
}

/////////////////////

TreeNode* mirrorTree(TreeNode *A)
{
	if(A == NULL) return NULL;
	TreeNode * temp = A->left;
	A->left = A->right;
	A->right = temp;
	mirrorTree(A->left);
	mirrorTree(A->right);
	return A;
}
///////////////////
bool checkIdenticalTrees(TreeNode *A,TreeNode*A1)
{
	if(A == NULL && A1==NULL) return true;
	if (A== NULL || A1 == NULL) return false;
	return A->val!= A1->val && checkIdenticalTrees(A->left,A1->left) && checkIdenticalTrees(A->right,A1->right);
}
////////////////////

int getLevelFromNode(TreeNode* A,int value,int level)
{
	if (A==NULL) return 0;
	int l;
	if(A->val == value)
		return level;	
	l  = getLevelFromNode(A->left,value,level+1);
	if(l!=0)
		return l;
	l = getLevelFromNode(A->right,value,level+1);
	return l;
}
//////////////

void topView(TreeNode *A)
{
	if(A==NULL) return ;

	map<int,int> mp;
	queue<TreeNode*> q;
	q.push(A);
	while(!q.empty())
	{
		TreeNode * temp  = q.front();
		q.pop();
		int hd = temp->heightofnode;
        
		//it is inserting the ans in map, the ans includes the first value Only for each heoghtofnode pointer 
        if(mp.find(hd)==mp.end())  //if value not found in map 	
            mp[hd] = temp->val;
        
        if(temp->left !=NULL)
        {
            temp->left->heightofnode = hd -1;
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            temp->right->heightofnode = hd+1;
            q.push(temp->right);
        }
	}
    for(auto it=mp.begin();it!=mp.end();it++)	
    {
        cout<<it->second<<" ";
    }
    cout<<endl;
}

void topView1(TreeNode* A) {
	if(A == NULL) return;

	queue<TreeNode*> q;
	map<int,int> mp;
	q.push(A);
	while(q.size()>0) {
		TreeNode *temp = q.front();
		q.pop();

		int hd = temp->heightofnode;

		if(mp.find(hd) == mp.end()){
			mp[hd] = temp->val;
		}

		if(temp->left!=NULL) {
			q.push(temp->left);
			temp->left->heightofnode = hd-1;
		}
		if(temp->right !=NULL) {
			q.push(temp->right);
			temp->right->heightofnode = hd+1;
		}
	}

	for(auto it=mp.begin();it!=mp.end();it++)
	{
		cout<<it->second<<" ";
	}

}
////////////
void verticalTree(TreeNode* A)	//IMPORTANT
{
    if(A==NULL) return ;
    map<int,vector<int>> mp;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        int hd = temp->heightofnode;
        
        if(mp.find(hd)==mp.end())
            mp[hd].push_back(temp->val);
        else
            mp[hd].push_back(temp->val);

        if(temp->left!=NULL)
        {
            temp->left->heightofnode = hd-1;
            q.push(temp->left);
        }
        
        if(temp->right!=NULL)
        {
            temp->right->heightofnode = hd+1;
            q.push(temp->right);
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++)	
        {
            cout<<it->first<<" : ";
            for(int i=0;i<it->second.size();i++)
            {
                cout<<it->second[i]<<" ";
            }
            cout<<endl;
        }
}
////////////

void printLevelOrderSum(TreeNode* A)	//IMPORTANT
{
	if(A == NULL) return ;
	queue<TreeNode*> q;
	q.push(A);
	while(true)
	{
		int cnt = q.size();
		int sum = 0;
		if(cnt == 0)
			break;
		while(cnt>0)
		{
			TreeNode *queuefirst = q.front();
			q.pop();
			sum+=queuefirst->val;
			if(queuefirst->left !=NULL)
				q.push(queuefirst->left);
			if(queuefirst->right !=NULL)
				q.push(queuefirst->right);
			cnt--;
		}
		cout<<sum<<endl;
	}
}
////////////

bool searchElement(TreeNode* A,int value)
{
	if(A == NULL) return 0;
	if(A->val == value ) return 1;
	return searchElement(A->left,value) ||searchElement(A->right,value);
}

bool searchElementIterative(TreeNode* A,int value)
{
	if(A == NULL) return false ;
	queue<TreeNode*> q;
	q.push(A);
	bool ans = false;
	while(q.size()>0)
	{
		TreeNode *temp = q.front();
		q.pop();
		if(temp->val == value)
			ans = true;
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
	return ans;
}
///////////

void printLeafNodes(TreeNode *A) {
	if(A == NULL) return;
	if(A->left == NULL && A->right == NULL) cout<<A->val<<" ";
	printLeafNodes(A->left);
	printLeafNodes(A->right);
}
//////////
void printSpiral(TreeNode* A)
{
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;

	s1.push(A);
	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			if(A == NULL) return;
			TreeNode *temp1 = s1.top();
			s1.pop();
			cout<<temp1->val<<" ";
			if(temp1->right!=NULL)
				s2.push(temp1->right);
			if(temp1->left!=NULL)
				s2.push(temp1->left);
		}
		cout<<endl;
		while(!s2.empty())
		{
			if(A == NULL) return;
			TreeNode *temp2 = s2.top();
			s2.pop();
			cout<<temp2->val<<" ";
			if(temp2->left!=NULL)
				s1.push(temp2->left);
			if(temp2->right!=NULL)
				s1.push(temp2->right);
		}
		cout<<endl;
	}
}
///////////

bool checkMirrorTree(TreeNode* A1,TreeNode*A2)
{
	if(A1==NULL && A2 == NULL) return true;
	if(A1==NULL || A2 == NULL) return false;
	return A1->val == A2->val && checkMirrorTree(A1->left,A2->right) && checkMirrorTree(A1->right,A2->left);
}

///////////

bool isIsomorphicTree(TreeNode*A, TreeNode *B)
{
	if(A == NULL && B ==  NULL) return true;
	if(A == NULL || B == NULL ) return false;
	if(A->val!=B->val) return false;
	return isIsomorphicTree(A->left,B->right)&& isIsomorphicTree(A->right,B->left) || isIsomorphicTree(A->left,B->left) && isIsomorphicTree(A->right,B->right);
}

///////////
//same as printLevelOrder
int heightOfTreeIterative(TreeNode* A)	//IMPORTANT
{
	int ht=0;
	if(A == NULL) return 0 ;
	queue<TreeNode*> q;
	q.push(A);
	while(true)
	{
		int cnt = q.size();
		if(cnt == 0)
			break;
		while(cnt>0)
		{
			TreeNode *queuefirst = q.front();
			q.pop();
			//cout<<queuefirst->val<<" ";
			if(queuefirst->left !=NULL)
				q.push(queuefirst->left);
			if(queuefirst->right !=NULL)
				q.push(queuefirst->right);
			cnt--;
		}
		ht++;
		//cout<<endl;
	}
	return ht;
}


/////////////////////
int mx = -1;
int diameter(TreeNode *A)	//IMPORTANT
{
	
	if(A == NULL) return 0;
	if(A->left ==NULL && A->right == NULL) return 1;
	int lh = diameter(A->left);
	int rh = diameter(A->right);
	mx = max(mx,lh+rh+1);	
	return max(lh,rh)+1;
}
void printDiameter(TreeNode *A) {
	int answer = diameter(A);
	cout<<"diameter = "<<mx<<endl;
}
////////
 
int isHeightBalanced(TreeNode*A)	//IMPORTANT
{
	int diff = 0;
	if(A == NULL) return 0;
	if(A->left == NULL && A->right == NULL) return 1;
	int lh = isHeightBalanced(A->left);
	int rh = isHeightBalanced(A->right);
	if(lh == -1 || rh == -1 || absolute(lh,rh)>1)
		return -1;
	else
		return max(lh,rh)+1;
}
/////////////////////////

void printEveryRootToLeafPath(TreeNode* A,vector<int> &temp,int index)	//IMPORTANT
{
	if(A == NULL) return;
	temp[index]=A->val;
	if(A->left == NULL && A->right== NULL)
	{
		for(int i=0;i<=index;i++)
		cout<<temp[i]<<" ";
		cout<<endl;
	}
	printEveryRootToLeafPath(A->left,temp,index+1);
	printEveryRootToLeafPath(A->right,temp,index+1);
	
}
////////////////

//*********************

int searchElementInInorder(TreeNode*A,vector<int>&in)
{
	int val = A->val;
	for(int i=0;i<in.size();i++)
	{
		if(in[i] == val)
		{
			return i;
		}
	}
}
int cnt=0;
TreeNode * treeFromPreorderAndInorder(vector<int>&pre,vector<int>&in,int start,int end)
{
	if(start>end) return NULL;
	TreeNode *root = createNode(pre[cnt++]);
	int index = searchElementInInorder(root,in);
	root->left = treeFromPreorderAndInorder(pre,in,start,index-1);
	root->right = treeFromPreorderAndInorder(pre,in,index+1,end);
	return root;
}
//**********************

bool isRootToSumMatchesForGivenNumber(TreeNode* A,int givenvalue)
{
	if(A == NULL) return false;
	int nodevalue = A->val;
	if(A->left == NULL && A->right == NULL && nodevalue == givenvalue) return true;
	return isRootToSumMatchesForGivenNumber(A->left,givenvalue-nodevalue) || isRootToSumMatchesForGivenNumber(A->right,givenvalue-nodevalue);
}
///////

vector<int> ans;
vector<int> rootToLeafSumValues(TreeNode* A,vector<int> &temp,int index)
{
	if(A == NULL) return ans;
	temp[index]=A->val;
	if(A->left == NULL && A->right== NULL)
	{
		int sm= 0;
		for(int i=0;i<=index;i++)
		sm+=temp[i];
		ans.push_back(sm);
	}
	rootToLeafSumValues(A->left,temp,index+1);
	rootToLeafSumValues(A->right,temp,index+1);
	return ans;	
}
void rootToLeafSumValues_other_approach(TreeNode*A,int s)
{
	if(A == NULL) return ;
	if(A->left == NULL && A->right == NULL )
		{
			cout<<s+A->val<<endl;
			s = s-(A->val);
		}
	rootToLeafSumValues_other_approach(A->left,s+A->val);
	rootToLeafSumValues_other_approach(A->right,s+A->val);
}
////////////////

int mn_ht = INT_MAX;	//IMPORTANT
int minHeightOfTree(TreeNode*A,vector<int>&temp,int index)
{

	if(A == NULL) return 0;
	temp[index] = A->val;
	if(A->left == NULL && A->right == NULL)
	{
		mn_ht = min(mn_ht,index);
	}
	minHeightOfTree(A->left,temp,index+1);
	minHeightOfTree(A->right,temp,index+1);
	return mn_ht;
}
//my approach
int minHeightOfTree_other_approach(TreeNode *A)
{
	if(A == NULL) return 1;
	if(A->left == NULL && A->right == NULL ) return 1;
	int lh = minHeightOfTree_other_approach(A->left);
	int rh = minHeightOfTree_other_approach(A->right);
	return min(lh,rh)+1;
}
///////////////////
int leafsm = 0;
int leafNodeSum(TreeNode *A)
{
	if(A == NULL) return leafsm;
	if(A->left ==NULL && A->right ==NULL) 	
		leafsm = leafsm+A->val;
	leafNodeSum(A->left);
	leafNodeSum(A->right);
}

int leftleafsm = 0;
int leftLeafNodeSum(TreeNode *A,bool left)
{
	if(A == NULL) return leftleafsm;
	if(A->left == NULL && A->right==NULL && left==true)
		leftleafsm =leftleafsm+ A->val;
	leftLeafNodeSum(A->left,true);
	leftLeafNodeSum(A->right,false);
}
///////////

int minDistanceFromLeafToRoot(TreeNode*A)//SImilar to min height
{
	if(A == NULL) return 1;
	if(A->left ==NULL && A->right == NULL) return 1;
	int lh = minDistanceFromLeafToRoot(A->left);
	int rh = minDistanceFromLeafToRoot(A->right);
	return min(lh,rh)+1;
}


///////////////

int levelofleaf;

bool checkIfAllNodesAreSameLevel(TreeNode* A,int level) //IMP
{
	if(A == NULL) return 0;
	if(A->left == NULL && A->right == NULL)
	{
		if(levelofleaf == 0)
		{
			levelofleaf = level;
			return true;
		}
		return levelofleaf == level;
	}
	return checkIfAllNodesAreSameLevel(A->left,level+1) && checkIfAllNodesAreSameLevel(A->right,level+1);
}
///////////////////

int currenLevel=-1;
int a = 0;
int getDeepestLeftLeafNode(TreeNode*A, int level,bool left)
{
	if(A == NULL) return a;
	if(A->left == NULL && A->right == NULL && left == true && level>currenLevel)
	{
		a = A->val;
		currenLevel = level;
	}
	getDeepestLeftLeafNode(A->left,level+1,true);
	getDeepestLeftLeafNode(A->right,level+1,false);
	return a;
}

/////////////////////

bool rootToLeafSequencePresent(TreeNode*A,vector<int>seq,int level)//IMP
{
	if(A==NULL) return false;
	if(A->left == NULL && A->right==NULL ) 
	{
		if(level == seq.size()-1) return true;
	}
	if(A->val != seq[level] && seq.size()>=level) return false;
	return rootToLeafSequencePresent(A->left,seq,level+1) || rootToLeafSequencePresent(A->right,seq,level+1);
}

////////////

bool ancesstorOfGivenNode(TreeNode*A,int givenValue)  //IMP
{
	if(A == NULL) return false;
	if(A->val == givenValue) return true;
	if(ancesstorOfGivenNode(A->left,givenValue)|| ancesstorOfGivenNode(A->right,givenValue))
	{
		cout<<A->val<<" ";
		return true;
	}
	else return false;
}

///////////////

bool parentNodeValueOfNode(TreeNode*A, int givenValue)
{
	if(A == NULL) return false;
	if(A->val == givenValue) return true;
	if(parentNodeValueOfNode(A->left,givenValue) || parentNodeValueOfNode(A->right,givenValue))
		{
			cout<<A->val<<endl;
			return false;
		}
	else
		return false;
}	
////////////

void siblingOfGivenNode(TreeNode*A, int givenValue)
{
	if(A == NULL || A->val==givenValue) return ;
	if(A->left!=NULL)  
	{
		if(A->left->val == givenValue) 
			{
				if(A->right!=NULL)
					cout<<A->right->val<<endl;  
				else
					cout<<"NULL node"<<endl;
			}
	}
	if(A->right!=NULL) 
	{	if(A->right->val == givenValue)
		{
			if(A->left!=NULL)
				cout<<A->left->val<<endl; 
			else
				cout<<"NULL node"<<endl;	
		}
	}
	
	siblingOfGivenNode(A->left,givenValue);
	siblingOfGivenNode(A->right,givenValue);

}

///////////////
bool checkIfTwoNodesAreSibling(TreeNode*A,int gV1,int gV2){
	if(A == NULL) return false;
	if(A->left!=NULL && A->right!=NULL)
	{
		if( (A->left->val == gV1 && A->right->val == gV2) || (A->left->val == gV2 && A->right->val == gV1)) 
			return true;
	}
	return checkIfTwoNodesAreSibling(A->left,gV1,gV2) || checkIfTwoNodesAreSibling(A->right,gV1,gV2);
}
//////
TreeNode* lowestCommonAncesstor(TreeNode*A ,int n1,int n2) // very IMPORTANT
{
	if(A == NULL) return NULL;
	if(A->val == n1 || A->val == n2) return A;
	TreeNode * leftLCA = lowestCommonAncesstor(A->left,n1,n2);
	TreeNode * rightLCA = lowestCommonAncesstor(A->right,n1,n2);
	if(leftLCA!=NULL && rightLCA!=NULL) return A;
	if(leftLCA!=NULL) return leftLCA;
	else rightLCA;
}
/////

int findLevel(TreeNode*A,int gV,int level) //IMP
{
	if(A == NULL) return -1;
	if(A->val == gV) return level;
	int left = findLevel(A->left,gV,level+1);
	if(left == -1)
		return findLevel(A->right,gV,level+1);
	return left;
}
int distanceBetweenTwoNodes(TreeNode*A,int n1,int n2)
{
	TreeNode * lcaNode = lowestCommonAncesstor(A,n1,n2)	;
	int a = findLevel(A,n1,0);
	int b = findLevel(A,n2,0);
	int root_to_lca = findLevel(A,lcaNode->val,0);
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<root_to_lca<<endl;
	int aaannnsss = a+b - (2*(root_to_lca));	
	return aaannnsss;
}

//////////////
//VERY IMPORTANT
void printNodesAtKDistanceFromParent(TreeNode*A,int k )
{
	if(A == NULL) return;
	if(k == 0) cout<<A->val<<" ";
	printNodesAtKDistanceFromParent(A->left,k-1);
	printNodesAtKDistanceFromParent(A->right,k-1);

}
int printAllNodesAtDistance_K_FromGivenNodeUtil(TreeNode* A,TreeNode* targetNode,int k)
{
	if(A == NULL) return -1;
	if(A == targetNode) 
	{
		printNodesAtKDistanceFromParent(A,k);
		return 0;
	}

	int leftDist = printAllNodesAtDistance_K_FromGivenNodeUtil(A->left,targetNode,k);

	if(leftDist != -1)
	{
		if(leftDist+1 == k) cout<<A->val<<" ";
		else
		{
			printNodesAtKDistanceFromParent(A->right,k-2-leftDist);
		}
		return leftDist+1;

	}
	int rightDist = printAllNodesAtDistance_K_FromGivenNodeUtil(A->right,targetNode,k);

	if(rightDist!= -1)
	{
		if(rightDist+1 == k) cout<<A->val<<" ";
		else
		{
			printNodesAtKDistanceFromParent(A->left,k-2-rightDist);
		}
		return rightDist+1;
	}
	return -1;
}
int printAllNodesAtDistance_K_FromGivenNode(TreeNode* A,TreeNode* targetNode,int k)
{
	if(targetNode == NULL || A == NULL || k<0) return -1;

	return printAllNodesAtDistance_K_FromGivenNodeUtil(A,targetNode,k);
}
///////////////////

void serializeBinaryTree(TreeNode *A,vector<int> &serial)
{
	if(A == NULL)
	{
		serial.push_back(-1);
		return;
	}
	serial.push_back(A->val);
	serializeBinaryTree(A->left,serial);
	serializeBinaryTree(A->right,serial);
}

///////////////////////
// TreeNode* prev = NULL;
// bool isTreeBST(TreeNode*A)
// {
// 	if(A == NULL) return true;
// 	if(isTreeBST(A->left) == false) return false;
// 	if(prev!=NULL && prev->val > A->val) return false;
// 	prev = A;
// 	return isTreeBST(A->right);
// }

////////

void getRightNodeOfGivenValue(TreeNode*A,int givenValue)
{
	if(A == NULL) return;
	vector<TreeNode*> v;
	v.push_back(A);
	bool f =false;
	while(true)
	{
		int cnt = v.size();
		if(cnt == 0)
			break;
		for(int i=0;i<v.size();i++)
		{
			//cout<<v[i]->val<<" ";
			if(v[i]->val == givenValue)
			{
				f = true;
				if(i<(v.size()-1))
				{
					cout<<v[i+1]->val<<endl;
					break;
				}
				if(i==(v.size()-1))
				cout<<"no right node"<<endl;
			}
		}
		while(cnt>0)
		{
			TreeNode *temp = v.front();
			v.erase(v.begin());
			if(temp->left!=NULL)
				v.push_back(temp->left);
			if(temp->right!=NULL)
				v.push_back(temp->right);
			cnt--;
		}
		//cout<<endl;
		if(f == true) break;
	}
	if (f == false) cout<<"No Right Node"<<endl;

}

////////////

bool ifParentIsSumOfChildrenForAllNode(TreeNode*A)
{
	if(A == NULL || A->left == NULL && A->right == NULL) return true;
	int a = A->left==NULL?0:A->left->val;
	int b = A->right == NULL?0:A->right->val;
	return (a+b == A->val) && ifParentIsSumOfChildrenForAllNode(A->left)&& ifParentIsSumOfChildrenForAllNode(A->right);
}
///////////

vector<int> diagonalSum(TreeNode *A)
{
	vector<int> ans;
	if(A == NULL) return ans;
	queue<TreeNode*> q;
	q.push(A);
	while(true)
	{
		int s=0;
		int size = q.size();
		if(size == 0) break;
		while(size>0)
		{
			TreeNode* temp = q.front();
			q.pop();
			while(temp!=NULL)
			{
				s += temp->val;
				if(temp->left!=NULL) 
					q.push(temp->left);
				temp=temp->right;
			}
			size-=1;
		}
		ans.push_back(s);
	}
	return ans;
}
///////////

int maxSumBetweenAnyTwoLeafUtil(TreeNode*A,int maxSum)
{
	if(A == NULL ) return 0;
	if(A->left == NULL && A->right == NULL) return A->val;
	int l = maxSumBetweenAnyTwoLeafUtil(A->left,maxSum);
	int r = maxSumBetweenAnyTwoLeafUtil(A->right,maxSum);
	if(A->left!=NULL && A->right!=NULL)
	{
		if((l+r+A->val)>maxSum)
			{
			maxSum = l+r+A->val;
			cout<<maxSum<<endl;
			}
		return max(l,r)+A->val;
	}
	return (A->left!=NULL)?l+A->val:r+A->val;
}
int maxSumBetweenAnyTwoLeaf(TreeNode*A)
{
	int maxSum = -1;
	maxSumBetweenAnyTwoLeafUtil(A,maxSum);
	return maxSum;
}

////////////////
//includes input of positive and negative values
int getMaxSumPathValue(TreeNode* A)
{
	int mxe = 0;
	if(A == NULL) return 0;
	if(A->left == NULL && A->right==NULL) return A->val;

	int l = getMaxSumPathValue(A->left);
	int r = getMaxSumPathValue(A->right);
	int max_one = max(A->val, A->val+max(l,r));
	int max_two = max(max_one, l+r+A->val);
	mxe = max(mxe,max_two);
	return mxe;
}
//////////////////

vector<int> ca;
void printPathEqualToTheGivenSum(TreeNode *A,int givenValue)
{
	if(A == NULL) return;
	ca.push_back(A->val);
	printPathEqualToTheGivenSum(A->left,givenValue);
	printPathEqualToTheGivenSum(A->right,givenValue);
	int sm = 0;
	for(int i=ca.size()-1;i>=0;i--)
	{
		sm+= ca[i];
		if(sm == givenValue)
		{
			for(int j = i;j<ca.size();j++)
			cout<<ca[j]<<" ";
		}
	}
	cout<<endl;
	ca.erase(ca.end()-1);
}
///////////////

void averageOfEachLevel(TreeNode *A)
{
	if(A == NULL) return;
 	queue<TreeNode*> q;
	q.push(A);
	while(true)
	{
		int cnt = q.size();
		int deno = cnt;
		if(cnt == 0) break;
		int s = 0;
		while(cnt >0)
		{
			TreeNode *temp = q.front();
			q.pop();
			s = s+(temp->val);
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
			cnt--;
		}
		float avg = s/deno;
		cout<<avg<<endl;
	}
}
//////////

vector<int> vec;
void rootToLeafSumIsEqualToGivenSum(TreeNode*A,int givenSum)
{
	if(A == NULL) return;
	vec.push_back(A->val);
	if(A->left== NULL && A->right == NULL)
	{
		if(givenSum  == 0)
		{
			for(int i=0;i<vec.size();i++)
			cout<<vec[i]<<" ";
		}
	}
	else
	{
		rootToLeafSumIsEqualToGivenSum(A->left,givenSum-(A->left->val));
		rootToLeafSumIsEqualToGivenSum(A->right,givenSum-(A->right->val));	
	}
	//cout<<endl;
	vec.erase(vec.end()-1);
}
//////////////

map<int,int>mp;
bool CheckIfThereExistsPairForGivenSum(TreeNode*A,int givenSum)
{
	if(A == NULL ) return false;
	if(mp.find(givenSum - (A->val)) == mp.end())
	{
		mp[givenSum - (A->val)] = 1;
	}
	else
	{
		return true;
	}
	return CheckIfThereExistsPairForGivenSum(A->left,givenSum) || CheckIfThereExistsPairForGivenSum(A->right,givenSum);
}

int  main()
{
    ios::sync_with_stdio(false);
    TreeNode *root = NULL; 
	// root = insertNode(root, 50); 
	// insertNode(root, 30); 
	// insertNode(root, 20); 
	// insertNode(root, 40); 
	// insertNode(root, 70); 
	// insertNode(root, 60); 
	// insertNode(root, 80);
	root = createNode(2);
	root->left = createNode(7);
	root->right = createNode(5);
	root->left->left = createNode(12);
	root->left->right = createNode(6);
	root->left->right->left = createNode(5);
	root->left->right->right = createNode(11);
	root->right->right = createNode(9);
	root->right->right->left = createNode(4);

	// TreeNode *root1 = NULL;
	// root1 = createNode(2);
	// root1->left = createNode(7);
	// root1->right = createNode(5);
	// root1->left->left = createNode(12);
	// root1->left->right = createNode(6);
	// root1->left->right->left = createNode(5);
	// root1->left->right->right = createNode(11);
	// root1->right->right = createNode(9);
	// root1->right->right->left = createNode(4);


    //Function from here...
	//Inorder(root); 
	// vector<int> v = inorderWithVector(root);
	// for(auto vu: v)
	// {
	// 	cout<<vu<<" -> ";
	// }
	// cout<<endl;
	//cout<<"sumofAllNodes = " <<sumOfAllNodes(root)<<endl;
	//cout<<diffOfEvenOdddLevelValuesSum(root)<<endl;
	//cout<<"numofAllNodes = " <<numberOfAllNodes(root)<<endl;
	//cout<<"numofLeafNodes = " <<numberOfLeafNodes(root)<<endl;
	//cout<<"Height of the tree = " <<heightofTree(root)<<endl;
	//printElementsAtGivenLevel(root,3);
	//printLevelOrder(root);
	//printLevelOrderUsingQueue(root);
	//printLevelReverseOrderUsingQueue(root);
	// cout<<"leftview = ";
	// leftView(root,0);
	// cout<<endl;
	// cout<<"Rightview = ";
	// rightView(root,0);
	// cout<<endl;
	//inorderWithoutRecursion(root);
	//postorderWithoutRecursion(root);
	// root = mirrorTree(root);
	// bool status = checkIdenticalTrees(root,root1);
	// cout<<status<<endl;
	//  int x = getLevelFromNode(root,11,0);
	//  cout<<"level = "<<x<<endl;
	// topView1(root);
	// verticalTree(root);
	// printLevelOrderSum(root);
	// bool ans = searchElement(root,9);
	// cout<<ans<<endl;
	// bool ans = searchElementIterative(root,9);
	// cout<<ans<<endl;
	//printLeafNodes(root);
	//printSpiral(root);
	// int ht = heightOfTreeIterative(root);
	// cout<<ht<<endl;
	//  printDiameter(root);
	// if(isHeightBalanced(root)== -1)cout<<"Not Balanced"<<endl;
	// else cout<<"Balanced "<<endl;
	// bool ans = isRootToSumMatchesForGivenNumber(root,26);
	// cout<<ans<<endl;
	//  vector<int> temp(10);
	//  printEveryRootToLeafPath(root,temp,0);
	
	// vector<int> sumRtoL; 
	// sumRtoL = rootToLeafSumValues(root,temp,0);
	// for(auto b:) sumRtoL
	// cout<<b<<" ";
	// int ic = minHeightOfTree(root,temp,0);
	// cout<<ic<<endl;
	// int mmm = minHeightOfTree_other_approach(root);
	// cout<<mmm<<endl;
	// int  p = leafNodeSum(root);
	// cout<<p<<endl;
	// int  p = leftLeafNodeSum(root,true);
	// cout<<p<<endl;
	int q = minDistanceFromLeafToRoot(root);
	cout<<q<<endl;
	// bool we=checkIfAllNodesAreSameLevel(root,0);
	// cout<<we<<endl;
	// int a = getDeepestLeftLeafNode(root,0,true);
	// cout<<a<<endl;
	// vector<int> seq = {2,5,9,4};
	// bool qw = rootToLeafSequencePresent(root,seq,0);
	// cout<<qw<<endl;
	// bool er = ancesstorOfGivenNode(root,9);
	// bool rt = parentNodeValueOfNode(root,11);
	//siblingOfGivenNode(root,9);
	// bool ty = checkIfTwoNodesAreSibling(root,10,5);
	// cout<<ty<<endl;
	// TreeNode* ask  = lowestCommonAncesstor(root,4,11);
	// cout<<ask->val<<endl;
	// int lee = distanceBetweenTwoNodes(root,12,11);
	// cout<<lee<<endl;
	// TreeNode* giveNode = root->left;
	// int k = 2;
	// int elements = printAllNodesAtDistance_K_FromGivenNode(root,giveNode,k);
	// if(elements == -1)cout<<"No elements found"<<endl;
	// vector<int> serilinmain;
	// serializeBinaryTree(root,serilinmain);
	// for(auto x:serilinmain)
	// cout<<x<<" ";
	// cout<<endl;
	// bool yu = isTreeBST(root);
	// cout<<yu<<endl;
	// getRightNodeOfGivenValue(root,12);
	// bool ui = ifParentIsSumOfChildrenForAllNode(root);
	// cout<<ui<<endl;
	// vector<int> rreess = diagonalSum(root);
	// for(auto x:rreess)
	// 	cout<<x<<" ";
	// 	cout<<endl;
	//maxSumBetweenAnyTwoLeaf(root);
	// int aws = getMaxSumPathValue(root);
	// cout<<aws<<endl;
	//printPathEqualToTheGivenSum(root,6);
	//averageOfEachLevel(root);
	//rootToLeafSumIsEqualToGivenSum(root,20);
    return 0;
}
