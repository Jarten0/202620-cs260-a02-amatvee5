# Writeup

## Part 1
1A)
For each item in `other`, copy the given item and `push` it onto the main list.
Then, clear `other` and/or delete it.

1B)
The iteration over `other` takes linear time, and each `push` takes amortized
constant time, resulting in linear time for the process of insertion.
The `clear` takes constant time.
Thus, the Big-O time complexity for the `combine` algorithm on array lists is linear time O(n).

## Part 2
2A)
Create a new, empty list.
For each item in the list, compare it to `itemToMatch.state`, and if they're
equal, copy that item into the new list.
Then return the new list.

2B)
Each comparison takes constant time.
Each insertion to the new list with `push` takes amortized constant time.
Since the number of constant time operations computed are equal to the amount of items in the list,
the overall algorithm takes linear time.
Thus, the Big-O for `extractAllMatches` is linear time O(n).

## Part 4
4A)
Join the two lists by setting the pointer of the first list's `tail` to the second list's `head`.
Then, set the first `tail` pointer to the `tail` node of the second list.
Finally, set the pointers of the second list to null,
such that the second list no longer references any previous nodes.

4B)
Each pointer takes constant time to be updated.
Since only four pointers ever need to be changed,
the Big-O for `combine` on a linked list takes constant time O(1).

## Part 5
5A)
First, create a new list.
Then, iterate over each node by tracking a node with a pointer,
and update that pointer to each next node until the pointer becomes null.
For each node that is iterated over, check if the node's address's state is equal to `itemToMatch.state`.
If so, insert the node to the end of the new list.
Once iteration is finished, return the new list.

5B)
Each comparison takes constant time.
Appending to the end of the new list takes constant time.
Doing those actions for each item in the linked list results
in the Big-O for `extractAllMatches` being linear time O(n).

