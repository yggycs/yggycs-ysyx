#include <lcthw/list_algos.h>

int List_bubble_sort(List *list, List_compare cmp)
{
	if(list->count == 1 || list->count == 0 || list == NULL) return 0;

	for(int i = 0; i < list->count - 1; i++) {
		ListNode *node1 = list->first;
		ListNode *node2 = list->first->next;
		for(int j = 0; j < list->count - i - 1; j++)
		{
			if(cmp((char*)node1->value, (char*)node2->value) > 0)
			{
				char *temp = (char*)node1->value;
				node1->value = (char*)node2->value;
				node2->value = (void*)temp;
			}
			node1 = node1->next;
			node2 = node2->next;
		}
	}

	return 0;
}

List *List_merge_sort(List *list, List_compare cmp)
{
	if(list->count == 1 || list->count == 0 || list == NULL) return list;
	
	List *left = List_create();
	List *right = List_create();
	
	ListNode *n = list->first;
	for(int i = 0; i < list->count; i++)
	{	
		if(i < list->count/2) List_push(left, n->value);
		else List_push(right, n->value);
		n = n->next;
	}

	List_merge_sort(left, cmp);
	List_merge_sort(right, cmp);

	// merge
	ListNode *leftNode = left->first;
	ListNode *rightNode = right->first;
	ListNode *listNode = list->first;
	while(leftNode != NULL || rightNode != NULL)
	{	
		if(leftNode == NULL)
		{
			while(rightNode != NULL)
			{
				listNode->value = rightNode->value;
				listNode = (listNode == list->last)? NULL : listNode->next;
				rightNode = (rightNode == right->last)? NULL : rightNode->next;
			}
		}
		else if(rightNode == NULL)
		{
			while(leftNode != NULL)
			{
				listNode->value = leftNode->value;
				listNode = (listNode == list->last)? NULL : listNode->next;
				leftNode = (leftNode == left->last)? NULL : leftNode->next;
			}
		}
		else if(cmp((char*)leftNode->value, (char*)rightNode->value) > 0)
		{
			listNode->value = rightNode->value;
			listNode = (listNode == list->last)? NULL : listNode->next;
			rightNode = (rightNode == right->last)? NULL : rightNode->next;
		}
		else
		{
			listNode->value = leftNode->value;
			listNode = (listNode == list->last)? NULL : listNode->next;
			leftNode = (leftNode == left->last)? NULL : leftNode->next;
		}
	}
	
	List_destroy(left);
	List_destroy(right);
	return list;

}
