#include <iostream>
using namespace std;

class Node{
	public:
		char id;
		Node *next;
	
		Node(){
			next = NULL;
		}
};

class LinkedList{
	public:
	Node *head;
	Node *tail;
	
	LinkedList(){
		head = tail = NULL;
	}
	
	void insertToHead(char data){
		Node *node = new Node();
		node -> id = data;
		
		Node *tmp = head;
		head = node;
		node -> next = tmp;
	}
	
	void insertToTail(char data){
		Node *node = new Node();
		node -> id = data;
		
		tail -> next = node;
		tail = node;
	}
	
	void printAll(){
		if (head!=NULL){
			Node *tmp = head;
			do {
				cout << tmp -> id << "->";
				tmp = tmp -> next;
			} while(tmp!=NULL);
		}
	}
};

int main(int argc, char** argv) {
	
	LinkedList *list1 = new LinkedList();
	
	Node *node1 = new Node();
	node1->	id = 'A';
	
	list1->	head = node1;
	list1->	tail = node1;
	
	cout << list1-> head-> id <<endl;
	cout << node1 << endl;
	
	Node *node2 = new Node();
	node2->	id = 'B';
	
	list1->	tail -> next = node2;
	list1->	tail = node2;
	
	cout << list1-> head-> id << endl;
	cout << list1-> tail-> id << endl;
	
	Node *nodeX = new Node();
	nodeX->	id = 'X';
	
	Node *tmp = list1->head;
	list1->	head = nodeX;
	nodeX->	next = tmp;
	
	cout << list1->head->id << endl;
	cout << list1->tail->id << endl;
	
	list1-> insertToHead('Y');
	list1-> insertToTail('C');
	
	cout << list1-> head-> id << endl;
	cout << list1-> tail-> id << endl;
	
	list1-> printAll();
	
	
	return 0;
}
