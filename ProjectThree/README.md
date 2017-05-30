# Project Three

A ring queue is a finite-sized queue that never gets full and never grows past a certain size. 
Instead, once the queue operates at full capacity, the newest element replace the oldest element. A simple application of a ring queue 
consists of keeping track of the most recent values in some stream of numbers, the older values are automatically thrown away when 
newer ones are added. For example, one might use a ring queue to get the average of the N most recently processed numbers.

The purpose of this assignment is to implement to ring queue and a ring queue iterator. 
