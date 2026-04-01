#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

vector<int> inorder(TreeNode *root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<TreeNode*> st;
    TreeNode* node = root;
    while(true){
       if(node != NULL){
        st.push(node);
        node=node->left;
       }
       else{
        if(st.empty()) break;
        node = st.top();
        ans.push_back(node->data);
        node=node->right;
       }
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int> result = inorder(root);
    for(int val : result){
        cout << val << " ";
    }
    return 0;
}