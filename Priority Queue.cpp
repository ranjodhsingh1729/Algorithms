#include <bits/stdc++.h>

#define MAXLEN 100
#define parent(x) ((x)/2)
#define left_child(x) ((x)*2)
#define right_child(x) ((x)*2 + 1)

using namespace std;

typedef struct {
    int ind;
    int key;
    int val;
} obj;

typedef struct  {
    int size;
    obj heap[];
} priorityq;

void max_heapify_iterative(int i, int n, obj arr[]) {
    obj temp;
    int l, r, m;
    while (true) {
        l = left_child(i); // 2*i
        r = right_child(i); // 2*i + 1

        m = i;
        if (l <= n && arr[l-1].key > arr[i-1].key) {
            m = l;
        }
        if (r <= n && arr[r-1].key > arr[m-1].key) {
            m = r;
        }

        if (i != m) {
            temp = arr[i-1];
            arr[i-1] = arr[m-1];
            arr[m-1] = temp;
        } else {
            break;
        }

        i = m;
    }
}

void build_max_heap(int n, obj arr[]) {
    for (int i = n/2+1; i > 0; i--) {
        max_heapify_iterative(i, n, arr);
    }
}

obj* pq_maximum(priorityq &pq) {
    if (pq.size < 1) {
        cout << "Heap Underflow" << '\n';
        return NULL;
    }
    return &pq.heap[0];
}

obj* pq_extract_maximum(priorityq &pq) {
    obj *mx = pq_maximum(pq);
    pq.heap[0] = pq.heap[pq.size-1];
    pq.size--;
    max_heapify_iterative(1, pq.size, pq.heap);

    return mx;
}

void pq_insert(obj x, priorityq &pq) {

}

void pq_increse_key(obj x, priorityq &pq) {

}

int main() {
    priorityq pq;
    cin >> pq.size;

    for (int i = 0; i < pq.size; i++) {
        pq.heap[i].ind = i;
        cin >> pq.heap[i].key;
        cin >> pq.heap[i].val;
    }

    return 0;
}