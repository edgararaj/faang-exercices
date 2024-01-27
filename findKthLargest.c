#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define LEFT_CHILD(i) (i*2 + 1)
#define RIGHT_CHILD(i) (i*2 + 2)
#define PARENT(i) ((i-1)/2)

// 0 1 2 3 4 5 6
// 1 1 2 1 2 1 2
//           0
//         /   \
//       1      2
//     / \     /  \
//   3    4   5     6

struct heap {
    int* arr;
    int size;
    int used;
};

void swap(int* h, int f, int t) {
    int temp = h[t];
    h[t] = h[f];
    h[f] = temp;
}

void bubbleUpHeap(struct heap* h, int i) {
    while (i > 0 && h->arr[PARENT(i)] < h->arr[i]) {
        swap(h->arr, i, PARENT(i));
        i = PARENT(i);
    }
}

void bubbleDownHeap(struct heap* h, int i) {
    while (i < h->used) {
        int left = LEFT_CHILD(i);
        int right = RIGHT_CHILD(i);
        int biggest = i;
        if (left < h->used && h->arr[left] > h->arr[biggest]) {
            biggest = left;
        }
        if (right < h->used && h->arr[right] > h->arr[biggest]) {
            biggest = right;
        }
        if (biggest != i) {
            swap(h->arr, i, biggest);
            i = biggest;
        } else {
            break;
        }
    }
}

int getMaxHeap(struct heap* h) {
  int max = h->arr[0];
  h->arr[0] = h->arr[--h->used];
  bubbleDownHeap(h, 0);
  return max;
}

void insertHeap(struct heap* h, int i) {
    if (h->used >= h->size) {
        h->size *= 2;
        h->arr = realloc(h->arr, sizeof(int) * h->size);
    }
    h->arr[h->used] = i;
    bubbleUpHeap(h, h->used++);
}

void createHeap(struct heap* h, int numsSize) {
    h->size = numsSize;
    h->used = 0;
    h->arr = malloc(sizeof(int) * h->size);
}

int findKthLargest(int* nums, int numsSize, int k) {
    struct heap h;
    createHeap(&h, numsSize);
    for (int i = 0; i < numsSize; i++) {
        insertHeap(&h, nums[i]);
    }
    int max;
    for (int i = 0; i < k; i++) {
        max = getMaxHeap(&h);
    }
    return max;
}

int main()
{
    int nums[] = {3,2,1,5,6,4};
    int k = 2;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = findKthLargest(nums, numsSize, k);
    printf("%d\n", result);
    return 0;
}
