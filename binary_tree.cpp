#include <bits/stdc++.h>
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
node *buildtree(node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the data for intering in left" << data << endl;
    root->left = buildtree(root->left);
    cout << "enter the data for intering in right" << data << endl;
    root->right = buildtree(root->right);
    return root;
}
void levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        // cout<<temp->data<<" ";
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
void sum1(node *root, vector<int> &v)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    int sum = 0;
    while (!q.empty())
    {
        node *temp = q.front();
        // cout<<temp->data<<" ";
        q.pop();
        if (temp == NULL)
        {
            // cout<<endl;
            v.push_back(sum);
            sum = 0;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            sum = sum + temp->data;

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
// LNR
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
vector<int> inorder1(node *&root)
{
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    inorder1(root->left);
    v.push_back(root->data);
    inorder1(root->right);
}
// NLR
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// LRN IN POSTORDER
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    // cout<<root->data<<" ";
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void buildFromlevelorder(node *&root)
{
    queue<node *> q;
    // q.push(root);
    cout << "Enter data root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter left node for:" << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "Enter right node for:" << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

node *insertinbst(node *&root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertinbst(root->right, d);
    }
    else
    {
        root->left = insertinbst(root->left, d);
    }
    return root;
}
 void takeinput(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertinbst(root, data);
        cin >> data;
    }
}
node *minvalueinbst(node *&root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
node *maxvalueinbst(node *&root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
node *deletefrombst(node *&root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            node *temp = (root->left);
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            node *temp = (root->right);
            delete root;
            return temp;
        }
        else
        {
            int temp = minvalueinbst(root->right)->data;
            root->data = temp;
            root->right = deletefrombst(root->right, temp);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deletefrombst(root->left, val);
    }
    else
    {
        root->right = deletefrombst(root->right, val);
    }
}
// inorder traaversal in bst all ways comes in sorting manner
int main()
{
    node *root = NULL;
    cout << "Enter data to create" << endl;
    buildtree(root);
    cout << "Printing the BST" << endl;
    levelordertraversal(root);
    // cout<<endl;
    //  inorder(root);
    //  cout<<endl;
    // root=buildtree(root);
    // levelordertraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    /*
    root=buildtree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelordertraversal(root);
    inorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";
    postorder(root);
    */
    // preorder(root);
    /*cout<<endl<<minvalueinbst(root)->data;
    cout<<endl<<maxvalueinbst(root)->data<<endl;
    deletefrombst(root,21);
    levelordertraversal(root);*/
    //    vector<int> v1;
    //    v1=inorder1(root);
    //    for (int i = 0; i < v1.size(); i++)
    //    {
    //         cout<<v1[i]<<" ";
    //    }
    vector<int> v;
    sum1(root, v);
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
