enum Colors {
    BLACK,
    RED
};

class Node {
public:
    int data;
    Node *parent;
    Node *left;
    Node *right;
    Colors color;

    Node(int data, Node *parent) {
        this->data = data;
        this->parent = parent;
        this->left = nullptr;
        this->right = nullptr;
        this->color = RED;
    }

    void leftRotate() {

        Node *thisParent = this->parent;
        this->parent = this->right;
        this->right->parent = thisParent;

        if (thisParent != nullptr) {
            if (thisParent->left == this) {
                thisParent->left = this->right;
            } else {
                thisParent->right = this->right;
            }
        }

        Node *leftChild = this->right->left;
        this->right->left = this;
        this->right = leftChild;
        if (leftChild != nullptr) {
            leftChild->parent = this;
        }
    }

    void rightRotate() {

        Node *thisParent = this->parent;
        this->parent = this->left;
        this->left->parent = thisParent;

        if (thisParent != nullptr) {
            if (thisParent->left == this) {
                thisParent->left = this->left;
            } else {
                thisParent->right = this->left;
            }
        }

        Node *rightChild = this->left->right;
        this->left->right = this;
        this->left = rightChild;
        if (rightChild != nullptr) {
            rightChild->parent = this;
        }
    }

    Colors unclesColor() {
        if (this->parent->parent->left != this->parent) {
            if (this->parent->parent->left != nullptr) {
                return this->parent->parent->left->color;
            } else
                return BLACK;
        } else {
            if (this->parent->parent->right != nullptr) {
                return this->parent->parent->right->color;
            } else
                return BLACK;
        }
    }

    void balanceTree() {

        if (this->parent->color != BLACK) {// case 3
            if (this->unclesColor() == RED) { //case 3.1
                this->parent->color = BLACK;
                this->parent->parent->left->color = BLACK;
                if (this->parent->parent->parent != nullptr) {
                    this->parent->parent->color = RED;
                }
            } else { // case 3.2
                if(this->parent == this->parent->parent->right) {
                    if(this->parent->right == this) { //case 3.2.1
                    this->parent->parent->leftRotate();
                    this->parent->color = BLACK;
                    this->parent->left->color = RED;
                    } else { //case 3.2.2
                        this->parent->rightRotate();
                        this->parent->leftRotate();
                        this->color = BLACK;
                        this->left->color = RED;
                    }
                } else {
                    if(this->parent->left == this) { // case 3.2.3
                        this->parent->parent->rightRotate();
                        this->parent->color = BLACK;
                        this->parent->right->color = RED;
                    } else { //case 3.2.4
                        this->parent->leftRotate();
                        this->parent->rightRotate();
                        this->color = BLACK;
                        this->right->color = RED;
                    }
                }
            }
        }
    }
};
