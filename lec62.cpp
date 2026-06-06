#include <iostream>
#include <queue>
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

node *buildTree(node *root)
{
    cout << "enter the data : " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "enter the data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data for right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void LevelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void ReverseLevelOrderTraversal(node *root,queue<node *> &q)
{
    if(q.empty()){
        return ;
    }

    node* temp = q.front() ;
    q.pop() ;
    if(temp==NULL&&!q.empty()){
        q.push(NULL) ;
    }
    if(temp!=NULL&&temp->left){
        q.push(temp->left) ;
    }
    if(temp!=NULL&&temp->right){
        q.push(temp->right) ;
    }

    ReverseLevelOrderTraversal(q.front(),q) ;
    if(temp==NULL){
        cout << endl ;
    }
    else{
        cout << temp->data << " " ;
    }
    
}

int main()
{

    node *root = NULL;
    // copy and paste the below data in terminal in order to avoid writing after every call again and again
    // entering data 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    // printing
    cout << "printing the level order traversal output : " << endl;
    LevelOrderTraversal(root);

    // reverse printing
    queue<node *> q ;
    q.push(root) ;
    q.push(NULL) ;
    cout << "printing the reverse level order traversal output : " << endl;
    ReverseLevelOrderTraversal(root,q);

    return 0;
}