# 2033. Minimum Operations to Make a Uni-Value Grid

##  Problem Statement

You are given a 2D grid of size `m x n` and an integer `x`.

In one operation, you can:

* Add `x` to any element
* Subtract `x` from any element

A **uni-value grid** means all elements are equal.

👉 Return the **minimum number of operations** required to make the grid uni-value.
👉 If it's not possible, return `-1`.

---

##  Key Observations

### 1. Feasibility Condition

All elements must have the **same remainder when divided by `x`**:

```
grid[i][j] % x must be equal for all elements
```

If not →  return `-1`

---

### 2. Why Median?

To minimize total operations:

* We want to minimize

  ```
  Σ |a[i] - target|
  ```
* The best target is the **median** of the array.

---

##  Approach

1. Flatten the 2D grid into a 1D array
2. Check feasibility using modulo condition
3. Sort the array
4. Choose the **median**
5. Calculate total operations:

   ```
   operations += |value - median| / x
   ```

---

##  Algorithm

```cpp
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;

        // Step 1: Flatten grid
        for (auto &row : grid) {
            for (int val : row) {
                arr.push_back(val);
            }
        }

        // Step 2: Check feasibility
        int rem = arr[0] % x;
        for (int val : arr) {
            if (val % x != rem) return -1;
        }

        // Step 3: Sort
        sort(arr.begin(), arr.end());

        // Step 4: Find median
        int median = arr[arr.size() / 2];

        // Step 5: Count operations
        int operations = 0;
        for (int val : arr) {
            operations += abs(val - median) / x;
        }

        return operations;
    }
};
```

---

##  Complexity Analysis

| Type  | Complexity           |
| ----- | -------------------- |
| Time  | O(n log n) (sorting) |
| Space | O(n)                 |

---

##  Example

### Input

```
grid = [[2,4],[6,8]], x = 2
```

### Output

```
4
```

---

##  Interview Insights

* This is a variation of:

  * Minimum moves to equal array elements
  * Median-based optimization problems
* Key trick:
  👉 **Minimize absolute difference → Use median**

---

##  Edge Cases

* Single element grid → answer is `0`
* All elements already equal → `0`
* Different mod values → `-1`

---

##  Tags

`Array` `Sorting` `Math` `Greedy`

---

