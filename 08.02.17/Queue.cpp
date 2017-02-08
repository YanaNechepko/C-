#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node{
	int data;
	Node *next;
};

class Queue{
private:
	Node *head;
	int size;
public:
	Queue(int data){
		head = new Node;
		head->data = data;
		head->next = NULL;
	}

	~Queue(){
		while (head != NULL){
			Node *tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	void push(int data){
		if (head == NULL){
			head = new Node;
			head->next = NULL;
			head->data = data;
			return;
		}
		Node *index = head;
		Node *tmp = new Node;
		while (index->next != NULL){
			index = index->next;
		}
		tmp->data = data;
		tmp->next = NULL;
		index->next = tmp;
		size++;
	}

	int  pop(){
		if (head == NULL){
			cout << "Queue is empty";
			return NULL;
		}
		if (head->next == NULL){
			int a = head->data;
			head = NULL;
			size--;
			return a;
		}
		Node *tmp = head;
		head = head->next;
		int a = tmp->data;
		delete tmp;
		size--;
		return a;
	}
	void printAll(){
		Node *index = head;
		cout << "\n";
		while (index != NULL){
			cout << index->data << "\n";
			index = index->next;
		}
	}
};

int main()
{
	map <string, int> commands;
	commands["queue"] = 1;
	commands["end"] = 2;
	commands["push"] = 3;
	commands["pop"] = 4;

	string s;
	Queue A(0);

	do{
		cin >> s;
		int temp;
		switch (commands[s]){

		case 1:
			cin >> temp;
			A.pop();
			A.push(temp);
			break;
		case 2:
			break;
		case 3:
			cin >> temp;
			A.push(temp);
			break;
		case 4:
			cout << A.pop() << endl;
			break;
		}
	} while (s != "end");
	return 0;
}
