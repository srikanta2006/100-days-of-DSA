#include<iostream>
#include<vector>
using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

TreeNode* createTree(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    return root;
}

vector<int> getInorder(TreeNode* root){
    vector<int> inorder;
    TreeNode* curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            inorder.push_back(curr->val);
            curr=curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right!=NULL){
                prev->right==NULL;
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
            prev->right = curr;
            curr=curr->left;
            }
        }
    }
    return inorder;
}

int main(){
    TreeNode* root = createTree();
    vector<int> inorder = getInorder(root);
    for(int i=0; i<inorder.size(); i++){
        cout<<inorder[i]<<" ";
    }
    return 0;
}