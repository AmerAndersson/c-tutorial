# However, linked lists also have a few disadvantages:

There is no "random" access - it is impossible to reach the nth item in the array without first iterating over all items up until that item. This means we have to start from the beginning of the list and count how many times we advance in the list until we get to the desired item.
Dynamic memory allocation and pointers are required, which complicates the code and increases the risk of memory leaks and segment faults.
Linked lists have a much larger overhead over arrays, since linked list items are dynamically allocated (which is less efficient in memory usage) and each item in the list also must store an additional pointer.

  // *******************************************************
  // LinkedList =  Nodes are in 2 parts (data + address)
  //                        Nodes are in non-consecutive memory locations
  //                        Elements are linked using pointers
            
  //    advantages?
  //    1. Dynamic Data Structure (allocates needed memory while running)
  //    2. Insertion and Deletion of Nodes is easy. O(1) 
  //    3. No/Low memory waste
  
  //    disadvantages?
  //    1. Greater memory usage (additional pointer)
  //    2. No random access of elements (no index [i])
  //    3. Accessing/searching elements is more time consuming. O(n)
  
  //    uses?
  //    1. implement Stacks/Queues
  //    2. GPS navigation
  //    3. music playlist
  // *******************************************************
