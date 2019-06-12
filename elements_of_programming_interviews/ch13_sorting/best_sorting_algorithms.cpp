// =====================================================
// Book: Elements of programming interviews
// Problem 13.1: Best sorting algorithms
// =====================================================

// What is the best sorting algorithm when sorting:

// 1. A large array whose entries are random numbers

// Quick sort. It is very unlikely that this array will
// contain numbers in exactly reverse order, which is
// quick sorts worst case. On average it should run in
// n log(n) time complexity.

// 2. A small array of numbers

// Selection sort, insertion sort. The overhead of doing 
// recursive calls is probably not worth it when we want 
// to sort an array of just a few numbers.

// 3. A large array that is almost sorted

// Insertion sort. It only has to perform more than one 
// comparison when an element is not in the correctly sorted
// order. Min heap sort if we can guarantee that a number is 
// at most k steps from its final position.

// 4. A large collection of integers that are drawn from a 
// small range.

// Counting sort. Since the number of values is small we 
// keep count of the number of keys with each value and 
// reconstruct the array with the observed counts in the 
// correct order.

// 5. A large collection of numbers most of which are 
// duplicates 

// Tree sort. We keep a linked list at each tree leaf and add
// another node for duplicates. Or keep a count if we do not
// need the actual element.

// 6. Stability is required

// Merge sort. Merge sort is stable while quick sort is not.
