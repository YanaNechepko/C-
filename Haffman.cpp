#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <cstdio>

using namespace std;

class node
{
	public:

	 int a;
	 char c;
	 node* left;
	 node* right;
	 node()
	 {
	     left = NULL;
	     right = NULL;
     }

	 node(node *l, node *r)
	 {
        left =  l;
	    right = r;
	    a = l->a + r->a;
    }
};

struct compare
{
    bool operator()(const node* l, const node* r) const
    {
        return l->a < r->a;
    }
};

vector<bool> code;
map<char,vector<bool>> table;

void build_table(node *root)
{
    if (root->left != NULL)
    {
        code.push_back(0);
        build_table(root->left);
    }

    if (root->right!=NULL)
    {
        code.push_back(1);
        build_table(root->right);
    }

    if (root->left == NULL && root->right == NULL)
    {
        table[root->c] = code;
    }
    code.pop_back();
}

void Huffman()
{
    string file_name;
    string str;
    cout << "Enter File name: ";
    cin >> file_name;
	ifstream fin(file_name);
	getline(fin,str);
	map<char,int> my_map;

	for(int i = 0; i < str.length(); i++)
	{
        char symbol = str[i];
	    my_map[symbol]++;
    }

   list<node*> t;
   map<char,int>::iterator itq;

   for(itq = my_map.begin(); itq != my_map.end(); ++itq)
   {
      node *p = new node;
      p->c = itq->first;
      p->a = itq->second;
      t.push_back(p);
    }

  while (t.size() != 1)
  {
     t.sort(compare());
     node *lSon = t.front();
     t.pop_front();
     node *rSon = t.front();
     t.pop_front();
     node *parent = new node(lSon,rSon);
     t.push_front(parent);
  }

	node *root = t.front();
   	build_table(root);
    fin.clear();
    fin.seekg(0);
	ofstream fout("output1.bin");
    int counter = 0;
    char byte = 0;

    while (!fin.eof())
    {
        char c = fin.get();
        vector<bool> x = table[c];

        for(int n = 0; n < x.size(); n++)
	    {
	        byte = byte | x[n]<<(7-counter);
            counter++;

            if (counter == 8)
            {
                counter = 0;
                fout << byte;
                byte = 0;
            }

        }

    }

    fout << byte;
    fin.close();
	fout.close();
	fout.open("output2.bin");
	map<char,vector<bool>>::iterator it;

	for(it = table.begin(); it != table.end(); ++it)
    {
        fout << it->first;
        vector<bool> x = table[it->first];

        for(int n = 0; n < x.size(); n++)
        {
            fout << x[n];
        }

        fout << endl;
    }

    for(it = table.begin(); it != table.end(); ++it)
    {
        cout << it->first << " ";
        vector<bool> x = table[it->first];

        for(int n = 0; n < x.size(); n++)
        {
            cout << x[n];
        }

        cout << endl;
    }

    fout.close();
}

void console_Huffman()
{
    string str;
    cout << "Enter string: " << endl;
    cin >> str;
    map<char,int>my_map;

    for(int i = 0; i < str.length(); i++)
	{
        char c = str[i];
	    my_map[c]++;
    }

   list<node*> t;
   map<char,int>::iterator itq;

   for(itq = my_map.begin(); itq != my_map.end(); ++itq)
   {
      node *p = new node;
      p->c = itq->first;
      p->a = itq->second;
      t.push_back(p);
    }

  while (t.size() != 1)
  {
     t.sort(compare());
     node *lSon = t.front();
     t.pop_front();
     node *rSon = t.front();
     t.pop_front();
     node *parent = new node(lSon,rSon);
     t.push_front(parent);
  }
	node *root = t.front();
   	build_table(root);
   	map<char,vector<bool>>::iterator it;

   	for(it = table.begin(); it != table.end(); ++it)
    {
        cout << it->first << " ";
        vector<bool> x = table[it->first];

        for(int n = 0; n < x.size(); n++)
        {
            cout << x[n];
        }

        cout << endl;
    }

    cout << "Output: ";

    for(int i = 0; i < str.length(); i++)
    {
        vector<bool> x = table[str[i]];

        for(int n = 0; n < x.size(); n++)
        {
            cout << x[n];
        }

    }

}

void decoder()
{
    ifstream fin("output2.bin");
    string void_symbol;
    getline(fin,void_symbol);

    while(!fin.eof())
    {
        char c = fin.get();
        string str;
        getline(fin,str);

        for(int i = 0; i < str.length(); i++)
        {
            int p = int(str[i]);

            if(p == 48)
            {
                code.push_back(0);
            }

            else
            {
                code.push_back(1);
            }

        }

        table[c] = code;
        code.clear();
    }

    fin.close();
    map<char,vector<bool>>::iterator itq;
    fin.open("output1.bin");
    int counter = 0;
    char byte = 0;
    fin >> byte;
    vector<bool> vect;
    vector<bool>::iterator it;

    while(fin)
    {
        bool b = byte & (1<<(7-counter));

        if(b)
        {
            vect.push_back(1);
        }

        else
        {
            vect.push_back(0);
        }

        for(itq = table.begin(); itq != table.end(); ++itq)
        {
            vector<bool> x = table[itq->first];

            if(x == vect)
            {
                cout << itq->first;
                vect.clear();
                break;
            }

        }

        counter++;

        if(counter == 8)
        {
            counter = 0;
            fin >> byte;
        }

    }

}

int main () {
    int choice;
    cout << "Read from console - 1 " << endl << "Read from file - 2" << endl << "Decode - 3" << endl;
	cin >> choice;

	if(choice == 2)
    {
        Huffman();
    }

    if(choice == 1)
    {
        console_Huffman();
    }

    if(choice == 3)
    {
        decoder();
    }

	return 0;
}
