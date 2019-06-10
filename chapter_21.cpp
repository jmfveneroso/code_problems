// =====================================================
// Book: Elements of programming interviews
// Problem 21.1: 500 doors
// =====================================================

/*

The perfect squares will be opened. A number that divides
n called k can always be paired with another number n/k
that evenly divides n. The only time this is not true is
when n/k = k, because the pair would be the number k.
So except for perfect squares, every number will have an
even number of divisors.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 21.2: 
// =====================================================


/*

(Wrong) On each trial we keep the best 3 and remove the two worse
cyclists. We can guarantee that the two worse cyclists
are definitely not in the winning team, because each of
them is necessarily worse than at least 3 cyclists.
In the first trial we will eliminate 2 cyclists out of
22 that need to be eliminated to find the best team. So,
we need to repeat this cycle 11 times. 

(Right) We perform five trials, selecting the tree best from each trial.
After five trials we will eliminate 10 contenders. Then, we
race the winners of each trial against each other. We remove
the two worse and the four cyclists that performed worse than
them in the first trial. This will amount to 6 eliminations.
At this point we know for sure one of the winners. There are
still 8 contenders. But we can eliminate the two that we know
are worse than the third cyclist in the second test and the 
one we know is worse than the second cyclist in the second test.
This leaves 5 cyclists, of which the best two can be defined with
a simple test.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 21.5: 
// =====================================================


/*

It is better to be first. We can simply count the total value 
of the odd coins and the even coins. At each time, we need only
select the coin that the sequence with a larger total value. If
we do this, the second player will never get the chance to select
a coin from this sequence and the victory is guaranteed.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 21.6: 
// =====================================================


/*

The first player. The first player can initiate building an
L shape in the board by selecting a tile in the diagonal. He
can force the reiteration of this pattern each time taking 
mirrored actions. At the end, the second player will be forced
to break the symmetry.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 21.9: 
// =====================================================


/*

We want argmin_{m} = sum_{i=0}^{n-1} r_i |d_i - m|. This
is equal to argmin_{m} = |sum_{i=0}^{n-1} r_i d_i - m sum_{i=0}^{n-1}|. 
This is smallest when sum_{i=0}^{n-1} r_i d_i = m sum_{i=0}^{n-1}, therefore
m = \frac{\sum_{i=0}^{n-1} r_i d_i}{\sum_{i=0}^{n-1}}.

Actually is the locations that separates the median of residents. My way
finds the best location if it were continuous.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 21.10: Gasup problem
// =====================================================


/*

We start with enough gas to complete the cycle. At each city
we note the amount of gas that we have at that point and record
the city where we were with the minimum amount of gas. By starting 
at that city, we guarantee that at any point we will never have less
gas than at the start so we can complete the journey.

*/
