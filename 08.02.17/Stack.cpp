#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node{
	int data;
	Node *next;
};

class Stack{
private:
	Node *head;
	int size;
	int begin;

public:
	Stack(int data){
		head = new Node;
		head->data = data;
		head->next = NULL;
	}

	~Stack(){
		while (head != NULL){
			Node *tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	void push(int data){
		if (head != NULL){
			Node *tmp = new Node;
			tmp->data = data;
			tmp->next = head;
			head = tmp;
			size++;
		}
		else{
			head = new Node;
			head->next = NULL;
			head->data = data;
		}
	}

	int pop(){
		if (head == NULL){
			cout << "Stack is empty";
			return NULL;
		}

		if (head->next != NULL){
			Node *tmp = head;
			head = head->next;
			int a = tmp->data;
			delete tmp;
			size--;
			return a;
		}
		int a = head->data;
		head = NULL;
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
	commands["stack"] = 1;
	commands["end"] = 2;
	commands["push"] = 3;
	commands["pop"] = 4;

	string s;
	Stack A(0);

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
