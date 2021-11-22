// https://leetcode.com/problems/delete-node-in-a-bst/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* getSuccessor(TreeNode* root){
        root = root->right;
        while(root != NULL && root->left != NULL){
            root = root->left;
        }
        
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)    return NULL;
        if(root->val >  key)    root->left = deleteNode(root->left, key);
        else if(root->val <key) root->right = deleteNode(root->right, key);
        else{
            if(root->left == NULL && root->right== NULL)    return NULL;
            else if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;                
            }else if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }else{
                TreeNode* succ = getSuccessor(root);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }
        return root;        
    }
};



// Both are same

// Time Complexity : O(h) - h = height of the tree.
// (Worst case Time Complexity : O(n) )

// Code :

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            if(key < root->val) root->left = deleteNode(root->left, key);     //We frecursively call the function until we find the target node
            else if(key > root->val) root->right = deleteNode(root->right, key);       
            else{
                if(!root->left && !root->right) return NULL;          //No child condition
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;    //One child contion -> replace the node with it's child
					                                                //Two child condition   
                TreeNode* temp = root->left;                        //(or) TreeNode *temp = root->right;
                while(temp->right != NULL) temp = temp->right;     //      while(temp->left != NULL) temp = temp->left;
                root->val = temp->val;                            //       root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);  //        root->right = deleteNode(root->right, temp);		
            }
        return root;
    }   
};