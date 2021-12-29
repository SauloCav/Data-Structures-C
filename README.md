# Data-Structures-C

<strong>Some Data Structures developed in C</strong>

<strong>Stack:</strong></br>
A stack is an abstract data type that holds an ordered, linear sequence of items. In contrast to a queue, a stack is a last in, first out (LIFO) structure. A real-life example is a stack of plates: you can only take a plate from the top of the stack, and you can only add a plate to the top of the stack. If you want to reach a plate that is not on the top of the stack, you need to remove all of the plates that are above that one. In the same way, in a stack data structure, you can only access the element on the top of the stack. The element that was added last will be the one to be removed first. Therefore, to implement a stack, you need to maintain a pointer to the top of the stack (the last element to be added).

<strong>Queue:</strong></br>
A queue is an abstract data type that holds an ordered, linear sequence of items. You can describe it as a first in, first out (FIFO) structure; the first element to be added to the queue will be the first element to be removed from the queue. New elements are added to the back or rear of the queue. When an element is removed, the remaining elements do not move up to take the empty space. To keep the order of the queue you need to maintain a pointer to the front, which indicates the element at the front of the queue, and one to the rear, which indicates the element at the back of the queue.

<strong>Circular Queue:</strong></br>
A circular queue is the extended version of a regular queue where the last element is connected to the first element. Thus forming a circle-like structure. The circular queue solves the major limitation of the normal queue. In a normal queue, after a bit of insertion and deletion, there will be non-usable empty space.</br>
Circular Queue works by the process of circular increment i.e. when we try to increment the pointer and we reach the end of the queue, we start from the beginning of the queue.

<strong>Static List:</strong></br>
A list is an abstract data type that describes a linear collection of data items in some order, in that each element occupies a specific position in the list. The order could be alphabetic or numeric or it could just be the order in which the list elements have been added. Unlike a set, the elements of a list do not need to be unique.</br>
Lists are used in a wide variety of situations. Many of us use to-do lists to keep ourselves organised. You may use a shopping list to make sure you don’t forget to buy something when you visit the supermarket. If you use a streamed music service, you probably have several playlists.

<strong>Linked List:</strong></br>
A linked list is a dynamic data structure, which means that the size of the list can change at run time. You can imagine a linked list as a chain where each link is connected to the next one to form a sequence with a start and an end.</br>
Each element in a linked list is called a node. Each node stores:</br>
-- The data relating to the element</br>
-- A pointer to the next node</br>
There is also a separate pointer that indicates the first element in the list (the head of the list). This has a null value when the list is empty. The next node pointer of the last element in the list always points to a null value to mark the end of the list.

<strong>Ordered Linked List:</strong></br>
Follows the same principles as linked lists but has its elements ordered. This ordering can be done in different ways.

<strong>Binary Tree:</strong></br>
A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child. A recursive definition using just set theory notions is that a (non-empty) binary tree is a tuple (L, S, R), where L and R are binary trees or the empty set and S is a singleton set containing the root. Some authors allow the binary tree to be the empty set as well.</br>
From a graph theory perspective, binary (and K-ary) trees as defined here are arborescences. A binary tree may thus be also called a bifurcating arborescence—a term which appears in some very old programming books, before the modern computer science terminology prevailed. It is also possible to interpret a binary tree as an undirected, rather than a directed graph, in which case a binary tree is an ordered, rooted tree.

<strong>Binary Search Tree:</strong></br>
A binary search tree is a rooted tree where the nodes of the tree are ordered. If the order is ascending (low to high), the nodes of the left subtree have values that are lower than the root, and the nodes of the right subtree have values that are higher than the root. This property is true for any node of the tree; the nodes of its left subtree will have values that are lower, and the nodes of its right subtree will have values that are higher.
