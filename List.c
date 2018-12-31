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
		list->beginning->next = 0;
		list->end = listItem;
	}
	else {
		list->end->next = listItem;
		list->end = listItem;
		list->end->next = 0;
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

	addItemToEnd(&aList, (ListItem *) p);
	addItemToEnd(&aList, (ListItem *) q);
	addItemToEnd(&aList, (ListItem *) r);

	for (Point * c = (Point *) aList.beginning; c != 0; c = (Point *)c->nextPoint ) {
		printf("\tx: %f, y: %f \n", c->x, c->y);
	}

	while (!isEmpty(&aList))
	{
		free(removeItemFromBeginning(&aList));
	}

	return 0;
}

