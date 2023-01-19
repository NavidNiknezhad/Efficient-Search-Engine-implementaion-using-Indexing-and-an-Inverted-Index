# Efficient-Search-Engine-implementaion-using-Indexing-and-an-Inverted-Index
Design and implement a search engine using indexing and an inverted index data structure, featuring efficient searching and insertion/deletion with AVL tree and pre-order traversal.

##Introduction

Search engines are a vital piece of technology in our current day-to-day life. Search engines are applications where the user inputs a sequence of characters and, as a result, inputs suggestions as a list of words/phrases will appear in the input panel for quick access. This list would dynamically update when it gets more characters' input.

This assignment is about implementing a time-efficient search engine using a technology named "indexing". To simply implement this, we need to use a data structure called an "inverted index". An inverted index looks like a dictionary that records frequency, location, or other information for each word/phrase from their data sources.

##Algorithm Description

1. Indexing(): Initialize the AVL tree and read in the input files.
2. AVL_Traverse_preorder(fprint): Traverse the AVL tree in preorder, printing out the word/phrase and its corresponding index.

##Data Structure Description

1. AVL tree: I used the AVL tree as a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes.
2. Data Node: I used this to hold the addresses of the next two nodes (left and right) using pointers, and in this way, every node is connected.
3. Vector: I used a vector to store the file names and another vector to store the location for each word/phrase within each document.
4. List: I used a list to store names and access any number of input files.

##Complexity Analysis

In searching, with the inverted index, whenever a user searches for a word, thesearch engine knows which documents contain the word and where without having to traverse the original files. This makes search much more efficient with a time complexity of O(log N). This would be the same for Insertion and deletion, which are also O(log N).

##Conclusion

In conclusion, I have implemented a time-efficient search engine using the technology of indexing and a data structure called an inverted index. I have used an AVL tree as the main data structure to store the indices and have implemented a pre-order traversal to print out the word/phrase and its corresponding index. I have also used vectors and lists to store file names and locations, and to access input files. The time complexity of searching, insertion and deletion is O(log N) which makes the search engine efficient. Overall, this assignment has helped me understand the concept of indexing and its implementation in search engines.
