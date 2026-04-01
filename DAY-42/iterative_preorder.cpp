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

vector<int> preorder(TreeNode *root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        ans.push_back(node->data);
        if(node->right !=NULL) st.push(node->right);
        if(node->left !=NULL) st.push(node->left);
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int> result = preorder(root);
    for(int val : result){
        cout << val << " ";
    }
    return 0;
}