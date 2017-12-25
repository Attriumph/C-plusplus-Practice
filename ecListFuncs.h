// ecListFuncs.h
// CSCI 455 Fall 2017, Extra Credit assignment
// You do not need to modify or submit this file.

#ifndef EC_LIST_FUNCS_H
#define EC_LIST_FUNCS_H

#include <iostream>
#include <cctype>
#include <string>

using namespace std;


//*************************************************************************
// Node type used for lists
struct Node {
  int data;
  Node *next;

  Node(int item);
  Node(int item, Node *n);

};


typedef Node * ListType;

//*************************************************************************
// Utility functions used by the test driver code
//    (these are defined in ectest.cpp)

// inserts val at the front of list
// PRE: list is a well-formed list
void insertFront(Node *&list, int val);

// makes list into an empty list
//   reclaiming memory used by nodes 
// PRE: list is a well-formed list
// POST: list' is NULL
void clearList(Node * &list);

// prints list elements, space separated, ending with '\n'
// prints empty list as "<empty>"
// PRE: list is a well-formed list
void printList(Node *list);



//*************************************************************************
// Functions you need to write for this assignment:
//   (implementations go in ecListFuncs.cpp)



/*
 * numRuns
 *
 * PRE: list is a well-formed list.
 *
 * returns the number of runs in the list.
 *   A run is an ajacecent sequence two or more of the same values all in a row.
 *
 * Examples:
 *  list                   numRuns(list)
 *
 *    ()                    0
 *    (2 7 3)               0
 *    (2 2 7 3)             1
 *    (2 2 7 2 2 2 2)       2
 *    (2 2 3 3 3 4 4 4 4)   3
 *  
 */
int numRuns(ListType list);



/*
 * reverseCopy
 *
 * PRE: list is a well-formed list.
 *
 * returns a copy of the list, but with the elements in reverse order.
 * The original list is unchanged.
 *
 * Examples:
 *
 *  list              reverseCopy(list)
 *    ()                ()
 *    (7)               (7)
 *    (4 2 5 1)         (1 5 2 4)
 *    (1 2 2 3)         (3 2 2 1)
 *
 */
ListType reverseCopy(ListType list);



/* 
 * removeMiddleElmt
 *
 * PRE: list is a well-formed list
 * 
 * removes the middle element from the list.
 * If the list has an even number of elements, returns the one just left of the middle.
 * If the list is empty, does nothing.
 *
 * Examples:
 *
 *  list before         list
 *  before call:        after call to removeMiddleElmt:
 *    ()                ()
 *    (7)               ()
 *    (6 5 2 3)         (6 2 3)
 *    (5 2)             (2)
 *    (1 2 3 4 5)       (1 2 4 5)
 */
void removeMiddleElmt(ListType & list);



/*
 * splitOn
 *
 * PRE: list is a well-formed list
 *
 * Splits list into two sub-lists as follows: "a" will contain all the
 * elements up to, but not including, the first occurrence of splitVal
 * in the original list.  And "b" will contain all the elements after
 * splitVal in the original list.  Otherwise the values in the new
 * lists will be in the same order as in the original list.  If
 * splitVal does not appear in list, all the elements will be in "a",
 * and "b" will be NULL.
 *
 * This operation will destroy the list, because it reuses nodes from the
 * original list.  After the operation, list will be NULL.
 *
 * NOTE: this function does not create any nodes, but reuses
 * nodes from the original list.
 *
 * Examples:
 *
 *  list        splitVal  a       b
 *  (7 4 2 3 9)  2       (7 4)   (3 9)
 *  (7 4 2 3 9)  7       ()      (4 2 3 9)
 *  (1 2 3 3 2)  3       (1 2)   (3 2)
 *  ()           3       ()      ()
 *  (7 5)        3       (7 5)   ()
 *  (7 2 3)      3       (7 2)   ()
 *  (3)          3       ()      ()
 */
void splitOn(ListType &list, int splitVal, ListType &a, ListType &b);


void gut(ListType & list);
void rm(ListType & list);

//*************************************************************************

#endif
