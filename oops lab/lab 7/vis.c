#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int value;
    int listIndex;
    int elementIndex;
} HeapNode;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(HeapNode heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].value < heap[smallest].value)
        smallest = left;

    if (right < size && heap[right].value < heap[smallest].value)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void buildMinHeap(HeapNode heap[], int size) {
    for (int i = (size - 1) / 2; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

int smallestRange(int** lists, int listsSize, int* listsColSize) {
    int rangeStart = 0, rangeEnd = INT_MAX;
    int max = INT_MIN;
    HeapNode* heap = (HeapNode*)malloc(listsSize * sizeof(HeapNode));

    for (int i = 0; i < listsSize; i++) {
        heap[i].value = lists[i][0];
        heap[i].listIndex = i;
        heap[i].elementIndex = 0;
        if (lists[i][0] > max) {
            max = lists[i][0];
        }
    }

    buildMinHeap(heap, listsSize);

    while (1) {
        HeapNode root = heap[0];
        int min = root.value;

        if (max - min < rangeEnd - rangeStart) {
            rangeStart = min;
            rangeEnd = max;
        }

        if (root.elementIndex + 1 >= listsColSize[root.listIndex]) {
            break;
        }

        root.elementIndex++;
        root.value = lists[root.listIndex][root.elementIndex];

        if (root.value > max) {
            max = root.value;
        }

        heap[0] = root;
        minHeapify(heap, listsSize, 0);
    }

    free(heap);
    printf("The minimum range is %d-%d\n", rangeStart, rangeEnd);
    return 0;
}

int main() {
    int list1[] = { 3, 6, 8, 10, 15 };
    int list2[] = { 1, 5, 12 };
    int list3[] = { 4, 8, 15, 16 };
    int list4[] = { 2, 6 };
    int* lists[] = { list1, list2, list3, list4 };
    int listsColSize[] = { 5, 3, 4, 2 };

    smallestRange(lists, 4, listsColSize);

    return 0;
}
