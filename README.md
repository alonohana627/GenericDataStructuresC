# Generic Data Structures in C
Generic in C is hard. I don't believe void pointers is a proper way, cast from malloc is stupid ([as you can see here](https://stackoverflow.com/questions/605845/do-i-cast-the-result-of-malloc/605858#605858)) but I did it to do something little bit more sophisticated than put a value of integer and call it a day. Due to that, I did it with void pointers (which little bit more sophisticated). As a student, I must know how to implement various DSA in various languages.

Everything in C is manual, so unlike Java (where I can define that a variable must be comparable) in the AVL tree a person must include his own function to compare between values. Which means, in many cases, the DSA here are depended on the users.

For now we got:
- Generic Doubly Linked List
- Generic Stack
- Generic Queue
- Generic AVL Tree - self balanced tree

Future DSA:
- Generic Heap
- Merge/Quick sort (multithreaded)
- Radix, Counting and Bucket sort
- Binary search
- Dynamic Programming Examples

TODO:
- Add my Generic Dynamic Array
- Add proper iterators based on macros
- Add proper unit tests
