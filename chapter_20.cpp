// =====================================================
// Book: Elements of programming interviews
// Problem 20.6: Reservoir sampling
// =====================================================

/*

We store the first k elements. Then we include the next
packet with probability (k/n). If the packet is selected,
we drop a random packet from the stored list with 
probability 1/k for each element. By induction, we can
prove that the probability of every set will be the same.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 20.1: Random Permutations
// =====================================================

/*

By swapping each element with a different element in the 
array we get n^n permutations. For an array with 3 elements
we get 27=3^3 permutations. That is, the first element
can be swapped with three different elements, then the 
second element can be swapped with three different elements,
and so on. However there are 6 different permutations of
an array with 3 elements. Since 27 is not divisible by 6,
then some permutations must be more probable than others.
So the final array is not random. This happens because of
the initial configuration of the array. If we could guarantee
that the initial configuration was also random, then we would
have 6 * 27 possibilities and the final configurations would
be random. But this reasoning is circular since we must
assume that the array is random to begin with.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 20.3: Random Permutations 2
// =====================================================

/*

We could call the function n-1 times. Each time we select
an element and remove it from the array. This way each time
we call the function to produce an index x and select an
element from the remaining array performing a modulo operation
in the array size.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 20.5: Non Uniform RNG
// =====================================================

/*

We can simply express the t probabilities in terms of a cumulative
distribution. Then for t_0 the values from 0 to P(t_0), P(t_0) included, 
would map to t_0, then the values from P(t_0)+ to "P(t_0) + P(t_1)" would map to
t_1 and so on until we reach the interval P(t_0) + ... + P(t_{k-1}) to 
P(t_0) + ... + P(t_k) which is equal to one. This way we have a mapping function
F(x) that maps any value from 0 to 1 to a value t_i in proportion to each
value probability.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 20.7: Online Sampling
// =====================================================

/*

First, we generate a subset of k random numbers with the procedure described in
the last problem. This will be array A. Then, we generate an array with k indices 
from 1 to k in order and use the randomization procedure again to shuffle this array. We
will call it array B. For each element in B we take the element in A with that position
producing the final array.

The book solution is: keep a hash table with keys from 1 to n-1. For each index, we generate
a random number r from i to n-1. If the entry is not in the hash table we add it in position
i to the final array and store the key r with value i in the hash table. If r is in the hash
table we add hash[r] to the final array and set hash[r] to i. This way we are always drawing
new values from the remaining values after taking key r at time i.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 20.4: Nonuniform RNG
// =====================================================

/*

We select the smallest integer for which 2^i >= (a - b + 1).
We draw i samples from our binary generator, and each sample
encodes one bit of the sought integer + a = R. In the end, if
a <= R <= b, we can return it. If not, we draw another sample,
until one is in the interval a - b. The probability that we
will have to repeat the sampling is lower than 50%. In the limit,
the probability that we will draw at least one valid sample 
converges to 100%. After four iterations, the probability that
we will have obtained a valid sample is already 93.75%, after
seven iterations it is above 99%.

*/
