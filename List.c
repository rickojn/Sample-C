#include <stdio.h>
#include <stdlib.h>


typedef int bool;

struct ListItem
{
	struct ListItem *  next;
};

typedef struct ListItem ListItem;

struct List
{
	ListItem * beginning;
	ListItem * end;
} typedef List;

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
		list->beginning->next = listItem;
		list->end = listItem;
	}
	else {
		list->end->next = listItem;
		list->end = listItem;
	}
}

ListItem * removeItemFromBeginning(List * list) {
	ListItem * listItemToBeRemoved = list->beginning;
	list->beginning = list->beginning->next;
	return listItemToBeRemoved;
}

struct Point
{
	ListItem * nextPoint;
	float x;
	float y;
} typedef Coord;

int main() {
	List aList;
	listInit(&aList);

	Coord * p = (Coord *)malloc(sizeof(Coord));
	Coord * q = (Coord *)malloc(sizeof(Coord));
	Coord * r = (Coord *)malloc(sizeof(Coord));
	p->x = 10;
	p->y = 15;

	q->x = 20;
	q->y = 25;

	r->x = 30;
	r->y = 35;

	addItemToEnd(&aList, p);
	addItemToEnd(&aList, q);
	addItemToEnd(&aList, r);

	for (Coord * c = aList.beginning; c->nextPoint->next != 0; c = c->nextPoint ) {
		printf("x: %f, y: %f /n", c->x, c->y);
	}

	while (!isEmpty(&aList))
	{
		free(removeItemFromBeginning(&aList));
	}

	return 0;
}

