# Project Three

A ring queue is a finite-sized queue that never gets full and never grows past a certain size. 
Instead, once the queue operates at full capacity, the newest element replace the oldest element. A simple application of a ring queue 
consists of keeping track of the most recent values in some stream of numbers, the older values are automatically thrown away when 
newer ones are added. For example, one might use a ring queue to get the average of the N most recently processed numbers.

The purpose of this assignment is to implement to ring queue and a ring queue iterator. 

Just like a regular queue, elements can be pushed [on the back of the queue] and popped [off the front]. However, unlike a regular queue:
1. A ring queue keeps only the N most recently pushed elements.
2. push_back()and pop_front() are used instead of push() and pop() to support using generic algorithms and back_inserter.
3. push_front() on a full ring queue adds the new element and removes the oldest (i.e., the one at the front).
4. Iterator access to the queue is supported with begin() and end().

