// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/



// The Idea is As They Given us Inorder and Postorder

// as we Know Inorder Fallow --> Left_subtree => Root_Node => Right_subtree Traverse
// ans Postorder Fallow --> Left_subtree => Right_subtree =>Root_Nodetraverse
// using Postorder_array We can Find Root_Node Which always lay in Postorder_array last Possition
// After Finding That Root_Node ,First we are going to divide Inorder_array Into Two Part and Postorder Array
// into Two part .

// Then We are going to use Both of the arrays left part to Figur Out Left_subtree
// and Both of the arraysRigth Part to Figur out Right_subtree

// We are going to recursively do so until One Of the array dose not got empty
// Let's take an Example

// inorder   = [4 2 5 1 6 3 7]
// postorder = [4 5 2 6 7 3 1]

// So root would be 1 here and Left array which lay left of 1 is [4 2 5] and Right of 1 is [6 3 7]
// so left_inorder_array =  [4 2 5] and right_inorder_arry = [6 3 7]

// using 6 [ which is just rigth of 1] we are going to devide Postorder_array into two part
// [4 5 2] and [6 7 3]


// 1st Phase=>        
//                    1

//                /        \

//             [4 2 5]   [6 3 7]       <= inorder array
//             [4 5 2]   [6 7 3]       <= postorder array
// Now we have new freash problem like need to make tree by using inorder = [4 2 5] && postorder = [4 5 2] for left subtree
// AND inorder = [6 3 7] && postorder = [6 7 3] for right subtree
// **now same process we need to do again and again until One Of the array dose not got empty
// Rest of the Process show in a diagram Form :)

// 2nd Phase =>
//                        1

//                   /        \
//                  2          3
//             [4]    [5]   [6]   [7]       <= inorder array
//             [4]    [5]   [6]   [7]       <= postorder array
// 3rd Phase =>
// 1

//            /    \
//           2      3

//         /  \    /  \             <==== Answer

//        4    5  6    7 
// in the helper function, IN_SI and IN_EI : starting index and ending index for the inorder vector
// POST_SI and POST_EI : starting and ending idx for the postorder vector !! (to mark up the part of vector in consideration for that phase of recursion)



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
    TreeNode* solver(vector<int>& inorder, vector<int>& postorder, int inS, int inE, int postS, int postE){
        if(inS > inE)   return NULL;
        TreeNode* root = new TreeNode(postorder[postE]);
        int rootInd;
        for(int i=inS; i<=inE; i++){
            if(inorder[i] == root->val){
                rootInd = i;
                break;
            }
        }
        int LinS = inS;
        int LinE = rootInd-1;
        int LpostS = postS;
        int LpostE = LpostS + LinE - LinS;
        int RinS = rootInd+1;
        int RinE = inE;       
        int RpostE = postE-1;
        int RpostS = LpostE+1;
        root->left = solver(inorder, postorder, LinS, LinE, LpostS, LpostE);
        root->right = solver(inorder, postorder, RinS, RinE, RpostS, RpostE);
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return solver(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};