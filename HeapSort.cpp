#include <bits/stdc++.h>

#define MAXLEN 100

#define parent(x) ((x)/2)
#define left_child(x) ((x)*2)
#define right_child(x) ((x)*2 + 1)

using namespace std;
typedef long long ll;


// void max_heapify(int i, int n, int arr[]) {
//     int l = left_child(i);
//     int r = right_child(i);

//     int m;
//     if (l < n && r < n) {
//         m = arr[i] >= arr[l] ? (arr[i] >= arr[r] ? i : r) : (arr[l] > arr[r] ? l : r);
//     } else if (l < n) {
//         m = arr[i] >= arr[l] ? i : l;
//     } else {
//         m = i;
//     }

//     if (i != m) {
//         int temp;
//         temp = arr[i];
//         arr[i] = arr[m];
//         arr[m] = temp;

//         max_heapify(m, n, arr);
//     }
// }

void max_heapify(int i, int n, int arr[]) {
    int l = left_child(i); // 2*i
    int r = right_child(i); // 2*i + 1

    int m = i;
    if (l <= n && arr[l-1] > arr[i-1]) {
        m = l;
    }
    if (r <= n && arr[r-1] > arr[m-1]) {
        m = r;
    }

    if (i != m) {
        int temp;
        temp = arr[i-1];
        arr[i-1] = arr[m-1];
        arr[m-1] = temp;

        max_heapify(m, n, arr);
    }
}

void min_heapify(int i, int n, int arr[]) {
    int l = left_child(i);
    int r = right_child(i);

    int m = i;
    if (l <= n && arr[l-1] < arr[i-1]) {
        m = l;
    }
    if (r <= n && arr[r-1] < arr[m-1]) {
        m = r;
    }

    if (i != m) {
        int temp;
        temp = arr[i-1];
        arr[i-1] = arr[m-1];
        arr[m-1] = temp;

        min_heapify(m, n, arr);
    }
}

void max_heapify_iterative(int i, int n, int arr[]) {
    int l, r, m, temp;
    while (true) {
        l = left_child(i);
        r = right_child(i);

        m = i;
        if (l <= n && arr[l-1] > arr[i-1]) {
            m = l;
        }
        if (r <= n && arr[r-1] > arr[m-1]) {
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

void min_heapify_iterative(int i, int n, int arr[]) {
    int l, r, m, temp;
    while (true) {
        l = left_child(i);
        r = right_child(i);

        m = i;
        if (l <= n && arr[l-1] < arr[i-1]) {
            m = l;
        }
        if (r <= n && arr[r-1] < arr[m-1]) {
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

void build_max_heap(int n, int arr[]) {
    for (int i = n/2+1; i > 0; i--) {
        max_heapify_iterative(i, n, arr);
    }
}

void build_min_heap(int n, int arr[]) {
    for (int i = n/2+1; i > 0; i--) {
        min_heapify_iterative(i, n, arr);
    }
}

void heapsort(int n, int arr[]) {
    build_max_heap(n, arr); // O(n)

    int temp;
    for (int i = n-1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        max_heapify_iterative(1, i, arr);
    }
}


int main() {
    int n;
    cin >> n;
    int arr[MAXLEN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapsort(n, arr);

    for (auto &x: arr) {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}