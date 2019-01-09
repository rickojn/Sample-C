#include <stdio.h>
#include <stdlib.h>


typedef char bool;

struct ListItem
{
	struct ListItem *  prev;
	struct ListItem *  next;
};

typedef struct ListItem ListItem;

struct
{
	ListItem * beginning;
	ListItem * end;
} typedef List;

ListItem * nextItem(ListItem * item) {
	return item->next;
}

ListItem * prevItem(ListItem * item) {
	return item->prev;
}

void listInit(List * list) {
	list->beginning = 0;
	list->end = 0;
}

bool isEmpty(List * list) {
	return !(list->beginning);
}

void addItemToEnd(List * list, ListItem * listItem) {
	if (isEmpty(list)) {
		list->beginning = listItem;
		list->beginning->next = 0;
		list->beginning->prev = 0;
		list->end = listItem;
	}
	else {
		list->end->next = listItem;
		listItem->prev = list->end;
		list->end = listItem;
		list->end->next = 0;
	}
}

ListItem * removeItemFromBeginning(List * list) {
	ListItem * listItemToBeRemoved = list->beginning;
	list->beginning = list->beginning->next;
	if (list->beginning) {
		list->beginning->prev = 0;
	}
	return listItemToBeRemoved;
}

struct Point
{
	ListItem * linkPrev;
	ListItem * linkNext;
	float x;
	float y;
} typedef Point;

int main() {
	List aList;
	listInit(&aList);

	Point * p = (Point *)malloc(sizeof(Point));
	Point * q = (Point *)malloc(sizeof(Point));
	Point * r = (Point *)malloc(sizeof(Point));
	p->x = 10;
	p->y = 15;

	q->x = 20;
	q->y = 25;

	r->x = 30;
	r->y = 35;

	addItemToEnd(&aList, (ListItem *)p);
	addItemToEnd(&aList, (ListItem *)q);
	addItemToEnd(&aList, (ListItem *)r);

	printf("Go forward thru the list: \n");
	for (Point * ptrPoint = (Point *)aList.beginning; ptrPoint; ptrPoint = (Point *)nextItem((ListItem *)ptrPoint)) {
		printf("\tx: %f, y: %f \n", ptrPoint->x, ptrPoint->y);
	}

	printf("Go backwards thru the list: \n");
	for (Point * ptrPointer = (Point *)aList.end; ptrPointer; ptrPointer = (Point *)prevItem((ListItem *)ptrPointer)) {
		printf("\tx: %f, y: %f \n", ptrPointer->x, ptrPointer->y);
	}

	while (!isEmpty(&aList))
	{
		free(removeItemFromBeginning(&aList));
	}

	return 0;
}

