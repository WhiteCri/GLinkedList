#include <iostream>
#include "GLinkedList.h"
struct foo {};
int main() {
	GLinkedList list;
	
	list.saveNewNode(3);
	list.saveNewNode(5.0);
	list.saveNewNode('g');
	list.saveNewNode("helloo");
	list.saveNewNode(foo());
	list.checkData();
}