/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void solve_one(TreeNode* root, string &result) {
        if (root == NULL) {
            result += "null,";
            return;
        }
        
        result += to_string(root->val) + ",";
        solve_one(root->left, result);
        solve_one(root->right, result);
    }
    
     TreeNode* solve_two(const string &data, int &i) {
        if (i >= data.length()) return NULL;
        
        // Extract value until comma
        string val = "";
        while (i < data.length() && data[i] != ',') {
            val += data[i];
            i++;
        }
        i++; // Skip the comma
        
        if (val == "null") return NULL;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = solve_two(data, i);
        root->right = solve_two(data, i);
        
        return root;
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        solve_one(root, result);
        if (!result.empty() && result.back() == ',') {
            result.pop_back(); // Remove trailing comma
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         int i = 0;
        return solve_two(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));