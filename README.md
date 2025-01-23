# Radix Sort Algorithm

**Radix Sort** is a non-comparative sorting algorithm that works by grouping numbers based on their individual digits, proceeding from the least significant digit (LSD) to the most significant digit (MSD). It is particularly efficient for sorting integers or strings of uniform length.

---

## **How Radix Sort Works**

1. **Digit Grouping**:
   - Start by sorting the numbers based on the least significant digit (LSD).
   - Continue sorting for the next significant digits, one at a time, until all digits are processed.

2. **Stable Sort**:
   - Each digit-level sorting uses a stable sorting algorithm, such as Counting Sort.

3. **Result**:
   - After all passes, the array is completely sorted.

---

## **Features**
- Efficient for sorting integers and strings.
- Works best when the range of digits is small (e.g., base 10 for decimal numbers).
- Stable sort, meaning it preserves the order of elements with equal keys.

---

## **Complexity Analysis**

| **Best Case**          | **Worst Case**         | **Average Case**       |
|-------------------------|------------------------|-------------------------|
| O(n * k)               | O(n * k)              | O(n * k)               |

- **n**: Number of elements in the array.
- **k**: Number of digits in the largest number.

### **Space Complexity**
- O(n + b), where **b** is the base (e.g., 10 for decimal numbers).

---

## **Code Implementation**

### Radix Sort Implementation in C

```c
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting Sort used in Radix Sort
void countingSort(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Update count[i] to store actual position of this digit
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

// Radix Sort Function
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Perform counting sort for each digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Driver Code
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    radixSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
