#include <bits/stdc++.h>
#define MAXLEN 1000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

class Node {
    public:
        int key, val;
        Node *lchild, *rchild, *parent;

        Node(int key, int val, Node *parent = nullptr) {
            this->lchild = this->rchild = nullptr;
            this->key = key, this->val = val, this->parent = parent;
        }

        int get_height() {
            // Leaf Node Have Height 0 and NULLPTRs Have Height -1
            int lheight = lchild ? lchild->get_height() : -1;
            int rheight = rchild ? rchild->get_height() : -1;
            return max(lheight, rheight) + 1;
        }

        // BF(N) = H(Rchild) - H(Lchild)
        int balance_factor() {
            // Leaf Node Have Height 0 and NULLPTRs Have Height -1
            int lheight = lchild ? lchild->get_height() : -1;
            int rheight = rchild ? rchild->get_height() : -1;
            return (rheight - lheight);
        }

        // If Exists Returns The Matching Node
        // Otherwise Returns The Parent Node Where It Should Be Inserted
        Node *find(int key) {
            Node *temp = this;
            while (temp) {
                if (key < temp->key) {
                    if (temp->lchild)
                        temp = temp->lchild;
                    else
                        break;
                } else if (key > temp->key) {
                    if (temp->rchild)
                        temp = temp->rchild;
                    else
                        break;
                } else {
                    break;
                }
            }
            return temp;
        }

        // By Property of BST
        Node *find_min() {
            Node *temp = this;
            while (temp->lchild)
                temp = temp->lchild;
            return temp;
        }

        // By Property of BST
        Node *find_max() {
            Node *temp = this;
            while (temp->rchild)
                temp = temp->rchild;
            return temp;
        }
        
        // Returns Next Greater Node
        Node *inorder_successor() {
            // Min Node In Right Subtree
            if (rchild) 
                return rchild->find_min();
            
            // If No Right Subtree Find A Greater Parent
            Node *temp = this;
            while (temp->parent && temp == temp->parent->lchild)
                temp = temp->parent;
            
            // No Greater Parent ==> No Inorder Successor
            return temp == this ? nullptr : temp;
        }

        // Returns Prev Lesser Node
        Node *inorder_predecessor() {
            // Max Node in Left Subtree
            if (lchild) 
                return lchild->find_max();

            // If No Left Subtree Find A Lesser Parent
            Node *temp = this;
            while (temp->parent && temp == temp->parent->rchild)
                temp = temp->parent;

            // No Lesser Parent ==> No Inorder Predecessor
            return temp == this ? nullptr : temp;
        }

        void inorder_traversal(void (*call_back)(Node *temp)) {
            if (lchild) lchild->inorder_traversal(call_back);
            call_back(this);
            if (rchild) rchild->inorder_traversal(call_back);
        }

        void preorder_traversal(void (*call_back)(Node *temp)) {
            call_back(this);
            if (lchild) lchild->preorder_traversal(call_back);
            if (rchild) rchild->preorder_traversal(call_back);       
        }

        void postorder_traversal(void (*call_back)(Node *temp)) {
            if (lchild) lchild->postorder_traversal(call_back);
            if (rchild) rchild->postorder_traversal(call_back);       
            call_back(this);
        }

        // Performs A LL Rotation As Follows:
        // Right Child Takes Position of Current Node
        // Current Node Becomes Left Child of Its Right Child
        // Left Child of Current Node's Right Child Becomes New Right Child of Current Node
        Node *ll_rotate() {
            // rchild definately exists
            Node *temp = this->rchild;
            // this->parent may not exist
            temp->parent = this->parent;
            this->parent = temp;
            // temp->lchild may not exist
            this->rchild = temp->lchild;
            temp->lchild = this;
            if (this->rchild)
                this->rchild->parent = this;
            // For Attaching Parent in Calling Function
            return temp;
        }

        // Performs A RR Rotation As Follows:
        // Left Child Takes Position of Current Node
        // Current Node Becomes Right Child of Its Left Child
        // Right Child of Current Node's Left Child Becomes New Left Child of Current Node
        Node *rr_rotate() {
            // lchild definately exists
            Node *temp = this->lchild;
            // this->parent may not exist
            temp->parent = this->parent;
            this->parent = temp;
            // temp->rchild may not exist
            this->lchild = temp->rchild;
            temp->rchild = this;
            if (this->lchild)
                this->lchild->parent = this;
            // For Attaching Parent in Calling Function
            return temp;
        }

        // When Imbalanced Parent And Its Child Have Different Heavy Sides
        // Parent is Left Heavy and Child is Right Heavy. Child is Balanced First
        Node *lr_rotate() {
            // lchild definately exists
            this->lchild = this->lchild->ll_rotate();
            return this->rr_rotate();
        }
        
        // When Imbalanced Parent And Its Child Have Different Heavy Sides
        // Parent is Right Heavy and Child is Left Heavy. Child is Balanced First
        Node *rl_rotate() {
            // rchild definately exists
            this->rchild = this->rchild->rr_rotate();
            return this->ll_rotate();
        }
        
        // Main Balancing Routine Shared By Both Insert and Delete
        Node *balance() {
            // Go Up The Tree Checking All Ancesstors for Imbalance
            Node *curr = this, *prev = this, *temp;
            while (curr = curr->parent) {
                if (abs(curr->balance_factor()) > 1) break;
                prev = curr;
            }
            // Reached Root, No Changes Required
            if (!curr) return nullptr;
            // Imbalanced Node Found, Balance Appropriatly
            int a = curr->balance_factor();
            int b = prev->balance_factor();
            if (a < 1 && b <= 0) temp = curr->rr_rotate();
            if (a < 1 && b > 0) temp = curr->lr_rotate();
            if (a > 1 && b < 0) temp = curr->rl_rotate();
            if (a > 1 && b >= 0) temp = curr->ll_rotate();
            // If The Parent Exists, Attach It To Its New Child
            // Note: Curr's Parent is Temp Now
            // Its Temp's Parent (Curr's Ex Parent) Which Needs Correction
            if (temp->parent) {
                if (temp->parent->lchild == curr) {
                    temp->parent->lchild = temp;
                } else {
                    temp->parent->rchild = temp;
                }
                return nullptr;
            }
            // If No Parent, Return New Root
            return temp;
        }

        // Inserts A Node 'x' in Tree Root 'this'
        Node *insert(int key, int val) {
            // Allocate New Node
            Node *x = new Node(key, val);
            // Find Suitable Insertion Position
            Node *curr = this->find(x->key);
            // Insert At The Found Position
            if (x->key < curr->key) {
                curr->lchild = x, x->parent = curr;
            } else if (x->key > curr->key) {
                curr->rchild = x, x->parent = curr;
            } else {
                cout << "DUPLICATE KEY" << endl; return this;
            }
            // Insertion Did Not Cause A Change In Height
            if (curr->lchild && curr->rchild) return this;

            // Balance The Tree
            // If A New Root is Returned Return That
            // Otherwise Return The Current Root Node
            Node *temp = curr->balance();
            return temp ? temp : this;
        }

        // Deletes Node 'x' in The Tree Root 'this'
        Node *__remove(Node *x) {
            Node *p, *temp = nullptr;
            // Case 1: x has both childs
            // replace x with its inorder successor
            // remove the inorder successor with a recursive call
            // Case 2: x has left child only
            // attach x's parent to x's left child directly and delete x
            // Case 3: x has right child only
            // attach x's parent to x's right child directly and delete x
            // Case 4: x has no children
            // set the appropriate child pointer of x's parent to null and delete x
            if (x->lchild && x->rchild) {
                p = x->rchild;
                while (p->lchild)
                    p = p->lchild;
                x->key = p->key;
                x->val = p->val;
                temp = this->__remove(p);
            } else if (x->lchild && !x->rchild) {
                p = x->parent;
                x->lchild->parent = p; 
                if (p) {
                    if (p->lchild == x) 
                        p->lchild = x->lchild;
                    else
                        p->rchild = x->lchild;
                    temp = p->balance();
                } else {
                    temp = x->lchild;
                }
                delete x;
            } else if (!x->lchild && x->rchild) {
                p = x->parent;
                x->rchild->parent = p;
                if (p) {
                    if (p->lchild == x) 
                        p->lchild = x->rchild;
                    else
                        p->rchild = x->rchild;
                    temp = p->balance();
                } else {
                    temp = x->rchild;
                }
                delete x;
            } else {
                p = x->parent;
                if (p) {
                    if (p->lchild == x) 
                        p->lchild = nullptr;
                    else
                        p->rchild = nullptr;
                    temp = p->balance();
                } else {
                    temp = nullptr;
                }
                delete x;
            }
            // If Deletion Causes A Change of Root Return New Root Otherwise Return Current Root
            return temp ? temp : this;
        }

        // Interface for Internal __remove
        Node *remove(int key) {
            Node *x = this->find(key);
            if (key != x->key) {
                cout << "KEY NOT FOUND" << endl; return this;
            }
            return this->__remove(x);
        }
};

void print_node(Node *x) {
    cout << x->val << ' ';
    // if (x->lchild)
    //     cout << "L: " << x->lchild->val << ' ';
    // if (x->rchild)
    //     cout << "R: " << x->rchild->val << ' ';
    // cout << endl;
}

int main() {
    int n;
    int arr[MAXLEN];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "INSERTING NODES...\n";
    void (*zemp)(Node*) = &print_node;
    Node *temp, *root = new Node(arr[0], arr[0]);
    for (int i = 1; i < n; i++) {
        root = root->insert(arr[i], arr[i]);
        cout << "PRE:- "; root->preorder_traversal(zemp); cout << endl;
    }

    cout << "REMOVING NODES...\n";
    for (int i = 1; i < n; i++) {
        root = root->remove(arr[i]);
        cout << "PRE:- "; root->preorder_traversal(zemp); cout << endl;
    }

    return 0;
}