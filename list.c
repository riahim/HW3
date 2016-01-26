#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	
	list_t* temp = head;
	list_t *left;
	list_t *right;
	
	if(new_element -> index <= head->index)
	{
		new_element->next = head;
		head = new_element;
	
	}
	
	/*printf("%u\n", *head);
	temp = temp->next;
	printf("%s", "NEXT VALUE\n");
	printf("%u\n", *temp);
	temp = temp->next;
	printf("%s", "SECOND VALUE\n");
	printf("%u\n", *temp);*/
	
	else
	{
	
		//printf("%u\n", *new_element);
		//printf("%u\n", temp->index);
		
		while((new_element -> index > temp->index) && (temp->next !=NULL))
		{
			left = temp;
			right = temp->next;
			new_element->next = temp; 
			
			temp = temp->next;
			
			/*printf("%s", "LEFT\n");
			printf("%u\n", *left);
			printf("%s", "Temp\n");
			printf("%u\n", *temp);
			printf("%s", "new element\n");
			printf("%u\n", *new_element);*/
					
		}
		if(temp->next == NULL && temp->index<new_element->index)
		{
			temp->next = new_element;
			new_element->next = NULL;
			
		}
		else
		{
		left->next = new_element;
		new_element->next = right;
		}
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	
	list_t* prev = NULL;
	list_t* next;
	while(head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	head = prev;
	
	return head;
}
