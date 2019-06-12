// =====================================================
// Book: Elements of programming interviews
// Problem 19.1: Creating photomosaics
// =====================================================

/*

The image is defined by a A = M x N matrix.

The tiles are defined by B_i = X_i x Y_i matrices.

The goal is to fill image A with a set of tiles
B in a way to approximate the target image as closely
as possible. 

We could determine that we want to maximize the number
of covered pixels and minimize that number of 
incorrectly covered pixels in A. 

The problem of setting tiles is likely to be NP-complete,
so a brute force approach would only be viable for
small images. One possibility is to use a greedy algorithm,
selecting the tile covers the most number of pixels without 
covering incorrect pixels at each iteration and stopping 
when there are no more pixels to cover.

We could also train a machine learning model to produce
tiled pictures and evaluate their quality with human
assessors. We could have some examples of pictures that 
were tiles by humans and then we would train a supervised
neural network to fill a grid producing a mosaic.

If all mosaics are square, we could compute a distance between
the n x n squares from the source image and each tile, selecting
the most appropriate tile at each timestep. Depending on the choice
of distance function, the tiles can be selected efficiently with
a binary tree, producing a O(n log(m)) solution where n is the 
number of squares in the source image and m is the number of tiles.
*/

// =====================================================
// Book: Elements of programming interviews
// Problem 19.4: Spell Checker
// =====================================================

/*

In a spell checker service, we want to suggest words to a user 
according to her typos. So, at each moment, we want to check
the closest words to the words typed by the user if they are 
not already present in the dictionary. This distance could be
computed with the Levenshtein distance algorithm. But it is 
a cumbersome computation.

The best information about typos can be obtained from user data.
When a user types a word and then later corrects that word, this is
a strong information that the first word was a typo. Of course, a
user may simply change a word for a better choice to improve the 
text. To account for these changes that were not made because of 
typos for each new word, we check if it is present in the dictionary.
If it is not, we keep track of that word. If the user changes the
word at any moment after typing it, we store the new word in a 
database.

Later, with another text or another user, we can simply check the 
database for the correct words collected in previous typos from all
the users. If the typo is not present in the database, we could suggest
words using the Levenshtein distance.

In addition to historic data, we could use a hash table to look for
similar words with m or less Levenshtein distances from the original
word. This would account to O(n m^2) lookups where n is the size of the
text. This lookup would match a great number of words. They could be
ranked according to the most common typos. Their text frequency. We
could also model the keyboard with a graph connecting key that are close
to each other and calculating the distance between words according to 
their distance in the keyboard.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 19.12: Online advertising system
// =====================================================

/*

Advertisements have to be somewhat related to the user's information
needs, so we need a solution that selects advertisements to the query.
The vector space model is a simple yet effective approach for comparing
documents according to their term frequencies. We could use the vector
space model to compare queries and advertisements and select the first
k documents that have the smallest distances to present to the user.

We could do lazy loading of advertisements so the user experience will
not be impacted by the ad server latency.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 19.15: Distributing large files
// =====================================================

/*

A single lab machine processes the articles, so it will likely be 
overburdened. There is no way to avoid copying each one of the 
1000 articles to a server in the datacenter at least once, but we 
should avoid copying articles from the processing machine to the
datacenter as much as possible.

A solution would be to queue articles in the processing machine and
copy them to one of the 1000 servers in a round robin arrangement. That
is, each article would be copied to a different server only once. Then,
each one of the 1000 servers would propagate the change to the other
999 servers that do not have the new article. This should be much faster
than copying from the source machine since they are all in the same location.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 19.2: Search Engine
// =====================================================

/* 

We store each word in a hash table, where each entry leads to
a list with all the documents that contain that term. 
This hash table can be built in O(n) time. Also, we assign an
id for each document and store the ids in sorted order in the
hash table. The sorting of these lists take in total O(n log(n)) time.

For a given query, we traverse the lists for each term,
and keep a list of documents that contain all the terms. To perform
this search faster, we could store the list sizes, start with the
smallest list and search the other term lists for the documents in
the first list. Since document lists are sorted, we can compare 
term lists in linear time. Some improvements can be made by jumping
a few terms when looking for the next document. We can, for example, 
store together with each document id a pointer to the element that
is k positions ahead to avoid having to look at each document in the 
list.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 19.5: Stemming
// =====================================================

/* 

Porter's stemming algorithm is a simple and effective approach
for stemming words in English. Portuguese stemming is more 
challenging.

There are multiple rules. 

Remove plurals: 
s -> 0 : wizards becomes wizard

Remove infinitive suffix: 
ing -> 0 : going becomes go

etc.

*/

// =====================================================
// Book: Elements of programming interviews
// Problem 19.8: Copyright infringement
// =====================================================

/*

Machine learning is a good way of solving this problem. We could
use a LSTM that builds a vector representation of a video processing
frames sequentially. By taking the LSTM internal states in various
points during the video we can perform a cosine distance comparison
with videos processed in the same fashion stored in the database.

If we were not to employ machine learning. We could first check for
key frames with a hash function. Every video in the database could be 
sampled every k seconds. A hash function could produce hashes for the
sampled frames and these hashes could be stored in a database. For every
video that we want to check, we can process every frame with the hash
function and match entries in the database.

It would take too much space to store every frame in the database. But
if we sample a video every ten seconds, for example, the number of hashes
will be much smaller. Since we are calculating hashes for every frame in the
copyrighted video, we are guaranteed to strike a video that was illegally
uploaded to YouTV.

*/

int main() {
  cout << "Done." << endl;
  return 0;
}
