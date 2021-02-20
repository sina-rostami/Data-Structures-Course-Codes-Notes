#include <iostream>
#include <vector>

struct Node
{
    int num;
    Node *left_child;
    Node *right_child;
    Node(int n) : num(n), left_child(nullptr), right_child(nullptr){};
    Node(int n, Node *l, Node *r) : num(n), left_child(l), right_child(r){};
    void touch_node() const
    {
        std::cout << num << " -> ";
    }
};

struct BinaryTree
{
    Node *root;
    BinaryTree(Node *r) : root(r){};
    void post_order_traversal() const
    {
        do_post_order_traversal(root);
    }

private:
    void do_post_order_traversal(const Node *t_root) const
    {
        // base case
        if (t_root == nullptr)
            return;
        if (t_root->left_child == nullptr && t_root->right_child == nullptr)
        {
            t_root->touch_node();
            return;
        }

        // recursion step
        do_post_order_traversal(t_root->left_child);
        do_post_order_traversal(t_root->right_child);
        t_root->touch_node();
    }
};

int main()
{
    std::vector<Node> vc;
    int t_num;

    do
    {
        std::cin >> t_num;
        vc.emplace_back(t_num);
    } while (t_num != -1);
    vc.pop_back();

    std::size_t tree_index = 1;
    for (std::size_t i = 0; i < vc.size() && tree_index < vc.size(); ++i)
    {
        vc[i].left_child = (vc[tree_index].num != 0) ? &vc[tree_index] : nullptr;
        tree_index++;
        if (tree_index == vc.size())
            break;
        vc[i].right_child = (vc[tree_index].num != 0) ? &vc[tree_index] : nullptr;
        tree_index++;
    }

    BinaryTree bt(&vc[0]);
    bt.post_order_traversal();
}