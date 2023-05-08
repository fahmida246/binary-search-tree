#include <iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node* insertIntoBst(node *root, int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }
    if(d<root->data){
        root->left = insertIntoBst(root->left,d);
    }
    else{
        root->right = insertIntoBst(root->right,d);
    }
    return root;
}
node* minVal(node *root){
    node *temp = root;
    while(temp->left!=0){
        temp= temp->left;
    }
    return temp;
}
node* deleteFromBst(node* root, int val){
    if(root==0){
        return root;
    } // base case
    if(root->data== val){
            //0 child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return 0;
            }
            //1 child 2 case
            //left child
            if(root->left!= NULL && root->right ==NULL){
                node * temp = root->left;
                delete root;
                return temp;
            }
             //1 child 2 case
            //right child
            if(root->left == NULL&& root->right !=NULL){
                node * temp = root->right;
                delete root;
                return temp;
            }
            //2 child
            // right theke chuto delete
            if(root->left != NULL && root->right!= NULL){
                int mini = minVal(root->right)->data;
                root->data = mini;
                root->right = deleteFromBst(root->right, mini); // mini value take proper jaegae replace korar por mini k delete
            return root;
            }

    } // delete operation
    else if(val<root->data){
        root->left = deleteFromBst(root->left,val);
        return root;
    }
    else{
        root->right = deleteFromBst(root->right,val);
        return root;
    }
}
void takeInput(node* &root){
    int data;
    cin>>data;
    while(data!= -1){
        root = insertIntoBst(root, data);
        cin>>data;
    }
}
int searchInBst(node *root, int data){
    if(root==0){
        return 0;//false
    }
    if(root->data == data){
        return 1;
    }
    if(data<root->data){
        return searchInBst(root->left,data);
    }
    else{
        return searchInBst(root->right, data);
    }
}

node* maxVal(node *root){
    node *temp = root;
    while(temp->right!=0){
        temp= temp->right;
    }
    return temp;
}
int isBST(struct node* node)
{
    if (node == NULL)
        return 1;

    /* false if the max of the left is > than us */
    if (node->left != NULL
        && maxVal(node->left)->data > node->data)
        return 0;

    /* false if the min of the right is <= than us */
    if (node->right != NULL
        && minVal(node->right)->data < node->data)
        return 0;

    /* false if, recursively, the left or right is not a BST
     */
    if (!isBST(node->left) || !isBST(node->right))
        return 0;

    /* passing all that, it's a BST */
    return 1;
}
int kthsmall(node* root, int i, int k){
    if(root==NULL){
        return -1;
    }
    //l
    int left = kthsmall(root->left, i,k);
    if(left!= -1){
        return left;
    }
    //n
    i++;
    if(i==k){
        return root->data;
    }
    //r
    return kthsmall(root->right,i,k);
}
void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if(temp== NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);

            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    node *root = 0;
    cout<<"enter data to create bst"<<endl;
    takeInput(root);
    cout<<"print level order values";
    levelOrderTraversal(root);
    int s = searchInBst(root, 1);
    cout<<s;
    cout<<"max value";
    cout<<maxVal(root)->data;
    cout<< "min value";
    cout<<minVal(root)->data;
    root = deleteFromBst(root,50);
levelOrderTraversal(root);
int result = isBST(root);
cout<<result<<endl;
int kth = kthsmall(root,0,2); //kth largest hole (n-k)+1 th smalled hoe 3rd high hole 6th low bola jae
cout<<kth;
   // cout << "Hello world!" << endl;
    return 0;
}
