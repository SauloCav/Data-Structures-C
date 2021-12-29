# Data-Structures-C

<strong>Some Data Structures developed in C</strong>

<strong>Stack:</strong></br>
A stack is an abstract data type that holds an ordered, linear sequence of items. In contrast to a queue, a stack is a last in, first out (LIFO) structure. A real-life example is a stack of plates: you can only take a plate from the top of the stack, and you can only add a plate to the top of the stack. If you want to reach a plate that is not on the top of the stack, you need to remove all of the plates that are above that one. In the same way, in a stack data structure, you can only access the element on the top of the stack. The element that was added last will be the one to be removed first. Therefore, to implement a stack, you need to maintain a pointer to the top of the stack (the last element to be added).

<strong>Queue:</strong></br>
A queue is an abstract data type that holds an ordered, linear sequence of items. You can describe it as a first in, first out (FIFO) structure; the first element to be added to the queue will be the first element to be removed from the queue. New elements are added to the back or rear of the queue. When an element is removed, the remaining elements do not move up to take the empty space. To keep the order of the queue you need to maintain a pointer to the front, which indicates the element at the front of the queue, and one to the rear, which indicates the element at the back of the queue.

<strong>Circular Queue:</strong></br>
A circular queue is the extended version of a regular queue where the last element is connected to the first element. Thus forming a circle-like structure. The circular queue solves the major limitation of the normal queue. In a normal queue, after a bit of insertion and deletion, there will be non-usable empty space.</br>
Circular Queue works by the process of circular increment i.e. when we try to increment the pointer and we reach the end of the queue, we start from the beginning of the queue.

<strong>Linked List:</strong></br>
A linked list is a dynamic data structure, which means that the size of the list can change at run time. You can imagine a linked list as a chain where each link is connected to the next one to form a sequence with a start and an end.</br>
Each element in a linked list is called a node. Each node stores:</br>
-- The data relating to the element</br>
-- A pointer to the next node</br>
There is also a separate pointer that indicates the first element in the list (the head of the list). This has a null value when the list is empty. The next node pointer of the last element in the list always points to a null value to mark the end of the list.
