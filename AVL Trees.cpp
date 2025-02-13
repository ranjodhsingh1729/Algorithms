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
            int lheight = lchild ? lchild->get_height() : -1;
            int rheight = rchild ? rchild->get_height() : -1;
            return max(lheight, rheight) + 1;
        }

        int balance_factor() {
            int lheight = lchild ? lchild->get_height() : -1;
            int rheight = rchild ? rchild->get_height() : -1;
            return (rheight - lheight);
        }

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

        Node *find_min() {
            Node *temp = this;
            while (temp->lchild)
                temp = temp->lchild;
            return temp;
        }

        Node *find_max() {
            Node *temp = this;
            while (temp->rchild)
                temp = temp->rchild;
            return temp;
        }
        
        Node *inorder_successor() {
            if (rchild) 
                return rchild->find_min();
            
            Node *temp = this;
            while (temp->parent && temp == temp->parent->lchild)
                temp = temp->parent;
            
            if (temp == this)
                return nullptr;
            else
                return temp;
        }

        Node *inorder_predecessor() {
            if (lchild) 
                return lchild->find_max();

            Node *temp = this;
            while (temp->parent && temp == temp->parent->rchild)
                temp = temp->parent;

                if (temp == this)
                return nullptr;
            else
                return temp;
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
            return temp;
        }

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
            return temp;
        }

        Node *lr_rotate() {
            // lchild definately exists
            this->lchild = this->lchild->ll_rotate();
            return this->rr_rotate();
        }

        Node *rl_rotate() {
            // rchild definately exists
            this->rchild = this->rchild->rr_rotate();
            return this->ll_rotate();
        }

        Node *balance() {
            Node *temp = this, *zemp, *prev;
            while (temp = temp->parent) {
                if (abs(temp->balance_factor()) > 1) break;
                prev = temp;
            }
            if (!temp) return nullptr;
            
            int a = temp->balance_factor();
            int b = prev->balance_factor();
            if (a < 1 && b <= 0) zemp = temp->rr_rotate();
            if (a < 1 && b > 0) zemp = temp->lr_rotate();
            if (a > 1 && b < 0) zemp = temp->rl_rotate();
            if (a > 1 && b >= 0) zemp = temp->ll_rotate();
            
            if (zemp->parent) {
                if (zemp->parent->lchild == temp) {
                    zemp->parent->lchild = zemp;
                } else {
                    zemp->parent->rchild = zemp;
                }
                return nullptr;
            }

            return zemp;
        }

        Node *insert(Node *x) {
            Node *temp = this->find(x->key);
            if (x->key < temp->key) {
                temp->lchild = x, x->parent = temp;
            } else if (x->key > temp->key) {
                temp->rchild = x, x->parent = temp;
            } else {
                cout << "DUPLICATE KEY" << endl; return this;
            }
            if (temp->lchild && temp->rchild) return this;

            Node *zemp = temp;
            zemp = temp->balance();
            return zemp ? zemp : this;
        }

        Node *remove(Node *x) {
            Node *temp, *zemp = nullptr;
            if (x->lchild && x->rchild) {
                temp = x->rchild;
                while (temp->lchild)
                    temp = temp->lchild;
                x->key = temp->key;
                x->val = temp->val;
                return this->remove(temp);
            } else if (x->lchild && !x->rchild) {
                temp = x->parent;
                x->lchild->parent = temp; 
                if (temp) {
                    if (temp->lchild == x) 
                        temp->lchild = x->lchild;
                    else
                        temp->rchild = x->lchild;
                    zemp = temp->balance();
                }
                delete x;
            } else if (!x->lchild && x->rchild) {
                temp = x->parent;
                x->rchild->parent = temp;
                if (temp) {
                    if (temp->lchild == x) 
                        temp->lchild = x->rchild;
                    else
                        temp->rchild = x->rchild;
                    zemp = temp->balance();
                }
                delete x;

            } else {
                temp = x->parent;
                if (temp) {
                    if (temp->lchild == x) 
                        temp->lchild = nullptr;
                    else
                        temp->rchild = nullptr;
                    zemp = temp->balance();
                }
                delete x;
            }
            return zemp ? zemp : this;
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

    Node *temp, *root = new Node(arr[0], arr[0]);
    for (int i = 1; i < n; i++) {
        temp = new Node(arr[i], arr[i]);
        root = root->insert(temp);
    }

    void (*zemp)(Node*) = &print_node;
    cout << "ROOT:- "; print_node(root); cout << endl;
    cout << "PRE:- "; root->preorder_traversal(zemp); cout << endl;
    cout << "IN:- "; root->inorder_traversal(zemp); cout << endl;
    cout << "POST:- "; root->postorder_traversal(zemp); cout << endl;

    for (int i = 1; i < n; i++) {
        if (root->val == arr[i])
            continue;
        temp = root->find(arr[i]);
        root = root->remove(temp);
        cout << "PRE:- "; root->preorder_traversal(zemp); cout << endl;

    }


    return 0;
}