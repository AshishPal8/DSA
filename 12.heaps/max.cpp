#include <iostream>
#include <vector>

using namespace std;

int parent(int i) {
    return (i-1)/2;
}
int left(int i){
    return 2 * i + 1;
} 
int right(int i){
    return 2* i + 2;
}

void shiftUp(vector<int> &heap, int idx){
    while(idx > 0){
        int p = parent(idx);

        if(heap[p] >= heap[idx]) break;

        swap(heap[p], heap[idx]);
        idx = p;
    }
}

void shiftDown(vector<int> &heap, int idx, int n){
    while(true){
        int l = left(idx);
        int r = right(idx);
        int largest = idx;

        if(l < n && heap[l] > heap[largest]) largest = l;
        if(r > n && heap[r] > heap[largest]) largest = r;

        if(largest == idx) break;
        swap(heap[idx], heap[largest]);
        idx = largest;
    }
}

void insertHeap(vector<int> &heap, int k){
    heap.push_back(k);
    shiftUp(heap, heap.size() - 1);
}

int heapExtractMax(vector<int> &heap){
    if(heap.empty()) return 0;

    int maxValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    return maxValue;
}

void buildHeap(vector<int> & heap){
    int n = heap.size();
    for(int i = n/2-1; i >= 0; i++){
        shiftDown(heap, i, n);
    }
}

void heapSort(vector<int> & arr){
    buildHeap(arr);
    int n = arr.size();
    for(int end = n-1; end > 0; end--){
        swap(arr[0], arr[end]);
        shiftDown(arr, 0, end);
    }
}

int main () {
    vector<int> heap;

    insertHeap(heap, 20);
    insertHeap(heap, 15);
    insertHeap(heap, 30);
    insertHeap(heap, 40);
    insertHeap(heap, 10);
    insertHeap(heap, 50);

    for(int h : heap) {
        cout << h << " ";
    }
    cout << "\n";

    cout << "Max value: " << heapExtractMax(heap) << endl;

    for(int h : heap) {
        cout << h << " ";
    }
    cout << "\n";

    vector<int> arr = {3, 1, 6, 5, 2, 4};
    heapSort(arr);
    for(int a : arr){
        cout << a << " ";
    }
}