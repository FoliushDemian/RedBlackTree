#import "Node.cpp"

typedef Node *NodePtr;

class RBTree {
public:
    NodePtr root = nullptr;
public:
    void insert(int data) {
        if (root == nullptr) { //case 1
            root = new Node(data, nullptr);
            root->color = BLACK;
        } else {
            bool notInserted = true;
            NodePtr runNode = this->root;
            while (notInserted) {
                if (data < runNode->data) {
                    if (runNode->left == nullptr) {
                        runNode->left = new Node(data, runNode);
                        notInserted = false;
                        runNode->left->balanceTree();
                    } else {
                        runNode = runNode->left;
                    }
                } else {
                    if (runNode->right == nullptr) {
                        runNode->right = new Node(data, runNode);
                        notInserted = false;
                        runNode->right->balanceTree();
                    } else {
                        runNode = runNode->right;
                    }
                }
            }
            while (this->root->parent != nullptr) {
                this->root = this->root->parent;
            }
        }
    }
};