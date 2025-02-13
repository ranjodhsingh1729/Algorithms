#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


#define parent(n) (n)/2
#define lchild(n) 2*(n)
#define rchild(n) 2*(n)+1


class MinHeap {
    int n;
    int mn;
    int *arr;

    public:
        MinHeap(int mn) : n(0), mn(mn) {
            arr = new int[mn];
        }

        MinHeap(int mn, int n, int inp[]) : n(n), mn(mn) {
            arr = new int[mn];
            memcpy(arr, inp, n*sizeof(int));
            print();
            build();
        }

        int minimum() {
            return arr[0];
        }

        int extract_minimum() {
            swap(arr[0], arr[--n]);
            heapify(0);
            return arr[n];
        }

        void decrease_key(int new_key) {
        }

        void heapify(int x) {
            int l, r, tmp;
            while (true) {
                l = lchild(x+1)-1;
                r = rchild(x+1)-1;

                tmp = x;
                if (l < n && arr[l] < arr[x])
                    tmp = l;
                if (r < n && arr[r] < arr[l])
                    tmp = r;

                if (x == tmp) break;

                swap(arr[x], arr[tmp]);
                x = tmp;
            }
        }

        void build() {
            for (int i = n/2; i >= 0; i--) {
                heapify(i);
            }
        }

        void print() {
            for (int i = 0; i < n; i++) {
                cout << arr[i] << ' ';
            }
            cout << '\n';
        }

        ~MinHeap() {
            delete[] arr;
        }
};


// class MinPriorityQueue {

//     public:
//         MinPriorityQueue() {

//         }
//         MinPriorityQueue() {
            
//         }
//         MinPriorityQueue() {
            
//         }

//         void insert() {
//             // pending
//         }

//         int minimum() {
//             return ;
//         }

//         int extract_minimum() {
//             return 0;
//         }

//         void decrease_key() {

//         }
// };



int main() {
    
    
    return 0;
}
