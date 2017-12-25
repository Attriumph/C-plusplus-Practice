/*  Name:Lingqun Han
 *  USC NetID: lingquah
 *  CS 455 Fall 2017
 *
 *  See ecListFuncs.h for specification of each function.
 */

#include <iostream>

#include <cassert>

#include "ecListFuncs.h"

using namespace std;


int numRuns(ListType list) {
	
	int numOfRuns = 0;
	//if the list is null or just has one element return 0
	if (list == NULL || list->next == NULL) {
		return numOfRuns;
	}
	else {//if the list has two or more elements
		ListType curr = list;
		ListType nextList = curr->next;
		int time = 1;// the times of a element occurs

		while (nextList != NULL) {

			//if the element occurs more than twice,increase time by 1
			if (curr->data == nextList->data) {
				if ((nextList->next == NULL) || (nextList->next->data != curr->data)) {
					time++;
				}
			}
			curr = nextList;
			nextList = curr->next;
			//if the time of one element is equal to 2,then 
			//increase the number of run
			if (time == 2) {
				numOfRuns++;
				time = 1;
			}
		  }
	     }
	 return numOfRuns;
   }



	ListType reverseCopy(ListType list) {
		ListType  curr = list;
		ListType reversedList = NULL;
		
		//if the list is null or just has one element
		//return the original list
		if (curr == NULL||curr->next == NULL) {
			return list;
		}
		else {
			//if the list has more than two elements
			//reverse by structing new node to form list
			while (curr != NULL) {
				reversedList = new Node(curr->data, reversedList);
				curr = curr->next;
			}
		}

  return reversedList;  

}



	void removeMiddleElmt(ListType &list) {
		
		ListType temp = list;
		ListType prev = list;
		ListType curr = list;
		int length = 0;

		//compute the length of the list
		while (temp != NULL) {
			length++;
			temp = temp->next;
		}
		delete temp;

		//if the list just has one element
		//delete the element
		if (length == 1) {
			list = NULL;
		}
		if (length > 1) {
			int mid = length / 2;
            int location = 1; //the initial location of the list
			
			//if the list has odd elements
			if (length % 2 != 0) {
				//delete the element after mid
				while (location != mid + 1) {
					//find the element before the element that will be deleted
					if (location == mid) {
						prev = curr;
					}
					curr = curr->next;
					location++;
				}
				//connect the ones before and after the deleting element
				prev->next = curr->next;
				delete curr;
			}
			else {//if the list has even elements
				//if the list just has two elements
				if (length == 2) {
					list = curr->next;
					delete curr;
				}
				else {//if the list has more than 2 elements
					while (location != mid) {
						//find the element before the element that will be deleted
						if (location == mid - 1) {
							prev = curr;
						}
						curr = curr->next;
						location++;
					}
					//connect the ones before and after the deleting element
					prev->next = curr->next;
					delete curr;
				}
			}

		}
	}



void splitOn(ListType &list, int splitVal, ListType &a, ListType &b) {
	
	ListType temp1 = list;
	ListType temp2 = list;
	ListType prev = list;
	bool contain = false;
	
	//if the list is Null, then a and b are null 
	if (list == NULL) {
		a = NULL;
		b = NULL;
	}

	//judge if the list contains the split value
	while (temp1 != NULL) {
		if ( temp1->data == splitVal) {
			contain = true;
		}
		temp1 = temp1->next;
	}
	delete temp1;

	//if the list does not contain such split value
	//then all the elements will be in "a",and "b" will be NULL.
	if (contain == false) {
		a = list;
		//b = NULL;
	}
	//if the list contain the split value
	else {
		//if the split value in the first location of the list
		if (temp2->data == splitVal) {
			//a = NULL;
			b = temp2->next;
			delete temp2;
		}
		//if the split value is not in the first location
		else {
			a = list;
			while (temp2->data != splitVal) {
				if (temp2->next->data == splitVal) {
					prev = temp2;
				}
				temp2 = temp2->next;
			}
			//split the list from the current location
			prev->next = NULL;
			b = temp2->next;
			delete temp2;
		}
	}
	list = NULL;
}

void gut(ListType & list) {
	if (list != NULL || list->next != NULL || list->next->next != NULL) {
		ListType p = list;
		while (p->next ->next != NULL) {
			ListType temp = p->next->next;
			delete p->next;
			p->next = temp;
		}
		
	}
}


void rm(ListType & list) {

	int iter = 1;
	if (list == NULL) { return; }
	if (list->next == NULL) {
		delete list;
		list = NULL;
	}
	list = list->next;
	ListType curr = list;
	while (curr->next != NULL) {
		if (iter % 2 != 0) {
			if (curr->next->next != NULL) {
				ListType temp = curr->next->next;
				delete curr->next;
				curr->next = temp;
			}
			else {
				delete curr->next;
				curr->next = NULL;
			}
		}
		iter++;
		curr = curr->next;
	}
}
