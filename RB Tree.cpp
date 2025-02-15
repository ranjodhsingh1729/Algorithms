#include <bits/stdc++.h>
#define MAXLEN 1000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

enum color { red, black };

class Node {
    public:
        color col;
        int key, val;
        Node *l, *r, *p;

        Node(int key, int val, color col = black, Node *p = nullptr) {
            this->l = this->r = nullptr;
            this->key = key, this->val = val, this->col = col, this->p = p;
        }

        int get_height() {
            // Leaf Node Have Height 0 and NULLPTRs Have Height -1
            int lheight = l ? l->get_height() : -1;
            int rheight = r ? r->get_height() : -1;
            return max(lheight, rheight) + 1;
        }

        // If Exists Returns The Matching Node
        // Otherwise Returns The p Node Where It Should Be Inserted
        Node *find(int key) {
            Node *temp = this;
            while (temp) {
                if (key < temp->key) {
                    if (temp->l)
                        temp = temp->l;
                    else
                        break;
                } else if (key > temp->key) {
                    if (temp->r)
                        temp = temp->r;
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
            while (temp->l)
                temp = temp->l;
            return temp;
        }

        // By Property of BST
        Node *find_max() {
            Node *temp = this;
            while (temp->r)
                temp = temp->r;
            return temp;
        }
        
        // Returns Next Greater Node
        Node *inorder_successor() {
            // Min Node In Right Subtree
            if (r) 
                return r->find_min();
            
            // If No Right Subtree Find A Greater p
            Node *temp = this;
            while (temp->p && temp == temp->p->l)
                temp = temp->p;
            
            // No Greater p ==> No Inorder Successor
            return temp == this ? nullptr : temp;
        }

        // Returns Prev Lesser Node
        Node *inorder_predecessor() {
            // Max Node in Left Subtree
            if (l) 
                return l->find_max();

            // If No Left Subtree Find A Lesser p
            Node *temp = this;
            while (temp->p && temp == temp->p->r)
                temp = temp->p;

            // No Lesser p ==> No Inorder Predecessor
            return temp == this ? nullptr : temp;
        }

        void inorder_traversal(void (*call_back)(Node *temp)) {
            if (l) l->inorder_traversal(call_back);
            call_back(this);
            if (r) r->inorder_traversal(call_back);
        }

        void preorder_traversal(void (*call_back)(Node *temp)) {
            call_back(this);
            if (l) l->preorder_traversal(call_back);
            if (r) r->preorder_traversal(call_back);       
        }

        void postorder_traversal(void (*call_back)(Node *temp)) {
            if (l) l->postorder_traversal(call_back);
            if (r) r->postorder_traversal(call_back);       
            call_back(this);
        }

        // Performs A LL Rotation As Follows:
        // Right Child Takes Position of Current Node
        // Current Node Becomes Left Child of Its Right Child
        // Left Child of Current Node's Right Child Becomes New Right Child of Current Node
        Node *ll_rotate() {
            // r definately exists
            Node *temp = this->r;
            // this->p may not exist
            temp->p = this->p;
            this->p = temp;
            // temp->l may not exist
            this->r = temp->l;
            temp->l = this;
            if (this->r)
                this->r->p = this;
            // Attaching parent
            if (temp->p) {
                if (this == temp->p->l) {
                    temp->p->l = temp;
                } else {
                    temp->p->r = temp;
                }
            }
            // if root changes
            return temp;
        }

        // Performs A RR Rotation As Follows:
        // Left Child Takes Position of Current Node
        // Current Node Becomes Right Child of Its Left Child
        // Right Child of Current Node's Left Child Becomes New Left Child of Current Node
        Node *rr_rotate() {
            // l definately exists
            Node *temp = this->l;
            // this->p may not exist
            temp->p = this->p;
            this->p = temp;
            // temp->r may not exist
            this->l = temp->r;
            temp->r = this;
            if (this->l)
                this->l->p = this;
            // Attaching parent
            if (temp->p) {
                if (this == temp->p->l) {
                    temp->p->l = temp;
                } else {
                    temp->p->r = temp;
                }
            }
            // if root changes
            return temp;
        }

        Node *insert_fixup() {
            Node *z = this, *u, *temp;
            while (z->p && z->p->col == red) {
                if (z->p == z->p->p->l) {
                    u = z->p->p->r;
                    if (u && u->col == red) {
                        z->p->p->col = red;
                        z->p->col = u->col = black;
                        z = z->p->p;
                    } else {
                        if (z == z->p->r) {
                            z = z->p;
                            z->ll_rotate();
                        }
                        z->p->col = black;
                        z->p->p->col = red;
                        temp = z->p->p->rr_rotate();
                    }
                } else {
                    u = z->p->p->l;
                    if (u && u->col == red) {
                        z->p->p->col = red;
                        z->p->col = u->col = black;
                        z = z->p->p;
                    } else {
                        if (z == z->p->l) {
                            z = z->p;
                            z->rr_rotate();
                        }
                        z->p->col = black;
                        z->p->p->col = red;
                        temp = z->p->p->ll_rotate();
                    }
                }
            }
            if (!z->p)
                z->col = black;
            if (temp && !temp->p)
                temp->col = black;
            return (temp && temp->p ? nullptr : temp);
        }

        Node *insert(int key, int val) {
            Node *z = new Node(key, val, red);
            Node *p = this->find(key);
            if (p->key > z->key) {
                p->l = z, z->p = p;
            } else if (p->key < z->key) {
                p->r = z, z->p = p;
            } else {
                cout << "DUPLICATE KEY" << endl; return this;
            }

            Node *temp = nullptr;
            if (p->col == red)
                temp = z->insert_fixup();
            return temp ? temp : this;
        }

};

void print_node(Node *x) {
    if (x->col == black) {
        cout << x->val << ' '; 
    } else {
        cout << '"' << x->val << '"' << ' ';
    }
    // if (x->l)
    //     cout << "L: " << x->l->val << ' ';
    // if (x->r)
    //     cout << "R: " << x->r->val << ' ';
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

    return 0;
}