#include <iostream>
#include <queue>
using namespace std;

struct node {
	node* prev;
	int x;
	node* l;
	node* r;
	node(int a) {
		x = a;
		l = NULL;
		r = NULL;
	}
};

class bin_tree {
	node* top_node;
public:
	bin_tree(int a) {
		node *A = new node(a);
		top_node = A;
	}

	node* get_root() {
		return top_node;
	}

	void push(int a, node* cur = NULL) {
		if (cur == NULL)
			cur = top_node;

		if (cur->x <= a)
			if (cur->r != NULL)
				push(a, cur->r);
			else {
				node *A = new node(a);
				cur->r = A;
			}
		else
			if (cur->l != NULL)
				push(a, cur->l);
			else {
				node *A = new node(a);
				cur->l = A;
			}
	}

	void push(node* q, node* cur){
		if (q == NULL) return;
		if (cur == NULL) {
			cur = q;
			return;
		}
			if (cur->x <= q->x)
				if (cur->r != NULL)
					push(q, cur->r);
				else {
					cur->r = q;
				}
			else
				if (cur->l != NULL)
					push(q, cur->l);
				else {
					cur->l = q;
				}
	}

	void pop(int a, node* cur = NULL) {
		if (cur == NULL) {
			cur = top_node;
		}

		if (cur->x == a) {
			push(cur->l, cur->r);
			cur = cur->r;
			return;
		}

		if (cur->x < a) {
			if (cur->r != NULL)
				pop(a, cur->r);
		}

		else {
			if (cur->l != NULL)
				pop(a, cur->l);
		}
	}

	void dfs(node* cur) {
		if (cur == NULL);
		else {
			this->dfs(cur->l);
			this->dfs(cur->r);
		}
	}

	void bfs(node* cur, queue <node*> &q) {
		q.pop();
		if (cur == NULL);
		else {
			q.push(cur->l);
			q.push(cur->r);
			bfs(q.front(), q);
		}
	}

	void clear(node* cur) {
		if (cur->l != NULL)
			this->clear(cur->l);
		if (cur->r != NULL)
			this->clear(cur->r);
		cur = NULL;
	}

	~bin_tree() {
		clear(top_node);
	}
};

int main() {
}
