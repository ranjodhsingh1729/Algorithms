#include <bits/stdc++.h>
using namespace std;

#define parent(i) (i+1)/2-1
#define left(i) 2*(i+1)-1
#define right(i) 2*(i+1)+1-1

struct Node {
    int cost;
    int symb;
    Node *left = nullptr;
    Node *right = nullptr;
};

class Heap {
    public:
    vector<Node *> hp;

    Heap() {}
    Heap(vector<Node *> &temp) {
        for (auto &i: temp)
            hp.push_back(i);
        build_heap();
    }

    Node *extract_min() {
        Node *temp = hp.front();
        swap(hp.front(), hp.back());
        hp.pop_back();
        heapify(0);
        return temp;
    }

    void heapify(int i) {
        int mni = i;
        if (left(i) < hp.size() && hp[left(i)]->cost < hp[mni]->cost)
            mni = left(i);
        if (right(i) < hp.size() && hp[right(i)]->cost < hp[mni]->cost)
            mni = right(i);

        if (i != mni) {
            swap(hp[i], hp[mni]);
            heapify(mni);
        }
    }

    void build_heap() {
        for (int i = hp.size()/2; i >= 0; i--)
            heapify(i);
    }

    void reverse_heapify(int i) {
        if (parent(i) >= 0 && hp[i]->cost < hp[parent(i)]->cost) {
            swap(hp[i], hp[parent(i)]);
            reverse_heapify(parent(i));
        }
    }

    void insert(Node *x) {
        hp.push_back(x);
        reverse_heapify(hp.size()-1);
    }
};

int main() {
    int n;
    cin >> n;

    Heap A;
    Node *x;
    for (int i = 0; i < n; i++) {
        x = new Node;
        x->symb = i;
        cin >> x->cost;
        A.insert(x);
    }

    Node *a, *b, *c;
    while (A.hp.size() > 1) {
        a = A.extract_min();
        b = A.extract_min();

        c = new Node;
        c->right = b;
        c->left = a;
        c->cost = a->cost + b->cost;
        A.insert(c);
    }

    string y;
    vector<pair<int, string>> ans;

    auto dfs = [&](auto &&self, Node *x) -> void {
        if (x->left) {
            y.push_back('0');
            self(self, x->left);
            y.pop_back();
        }
        if (x->right) {
            y.push_back('1');
            self(self, x->right);
            y.pop_back();
        }
        
        if (!x->right && !x->left) {
            ans.push_back({x->symb, y});
        }
    };


    x = A.extract_min();
    dfs(dfs, x);
    for (auto &i: ans) {
        cout << i.first << " : " << i.second << '\n';
    }
    cout << '\n';

    return 0;
}