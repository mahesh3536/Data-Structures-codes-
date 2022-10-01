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
    cout << "Enter the data for inserting in left of" << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter the data for inserting in right of" << data << endl;
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
int main()
{
    node *root = NULL;
    root = buildtree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelordertraversal(root);
    vector<int> v;
    sum1(root, v);
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
}