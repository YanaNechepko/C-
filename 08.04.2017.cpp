#include <iostream>
#include <cstring>

using namespace std;

struct node
{
    string data;
    int colour;
    node* left;
    node* right;
    node* parent;
};

class RB_tree
{
private:
    node* root;
    node* NIL;
public:
    RB_tree()
    {
        NIL = new node;
        NIL->colour = 0;

        root = new node;
        root->parent = NULL;
        root->data = "\0";
        root->left = NIL;
        root->right = NIL;
        root->colour = 0;
    }

    void RB_insert(string a)
    {

        if(cross_tree3(root,a))
        {
            cout << "Node with this string exists" << endl;
            return;
        }
        if(root->data == "\0")
        {
            root->data = a;
            return;
        }

        node* temp = new node;
        temp->left = NIL;
        temp->right = NIL;
        node* n = root;

        my_begin:

        if(n->data > a)
        {
            if(n->left == NIL)
        {
            temp->data = a;
            n->left = temp;
            temp->parent = n;
            fix_colour(temp);
            return;
        }
            n = n->left;
            goto my_begin;
        }

        if(n->data < a)
        {
            if(n->right == NIL)
        {
            temp->data = a;
            n->right = temp;
            temp->parent = n;
            fix_colour(temp);
            return;
        }
            n = n->right;
            goto my_begin;
        }
    }

    void left_rotate(node* q)
    {
        node* p = q->right;
        q->right = p->left;

        if(p->left != NIL)
        {
            p->left->parent = q;
        }

        p->parent = q->parent;

        if(q->parent == NULL)
        {
            root = p;
        }
        else
        {
            if(q == q->parent->left)
            {
                q->parent->left = p;
            }
            else
            {
                q->parent->right = p;
            }
        }
        p->left = q;
        q->parent = p;
    }

    void right_rotate(node* p)
    {
        node* q = p->left;
        p->left = q->right;

        if(q->right != NIL)
        {
            q->right->parent = p;
        }

        q->parent = p->parent;

        if(p->parent == NULL)
        {
            root = q;
        }
        else
        {
            if(p == p->parent->right)
            {
                p->parent->right = q;
            }
            else
            {
                p->parent->left = q;
            }
        }
        q->right = p;
        p->parent = q;
    }


    void fix_colour(node* p)
    {
        p->colour = 1;
        while((p != root) && (p->parent->colour == 1))
        {
            if(p->parent == p->parent->parent->left)
            {
                node* q = p->parent->parent->right;

                if(q->colour == 1)
                {
                    p->parent->colour = 0;
                    q->colour = 0;
                    p->parent->parent->colour = 1;
                    p = p->parent->parent;
                }
                else
                {
                    if(p == p->parent->right)
                    {
                        p = p->parent;
                        left_rotate(p);
                    }

                    p->parent->colour = 0;
                    p->parent->parent->colour = 1;
                    right_rotate(p->parent->parent);
                }
            }
            else
            {
                node* q = p->parent->parent->left;

                if(q->colour == 1)
                {
                    p->parent->colour = 0;
                    q->colour = 0;
                    p->parent->parent->colour = 1;
                    p = p->parent->parent;
                }
                else
                {
                    if(p == p->parent->left)
                    {
                        p = p->parent;
                        right_rotate(p);
                    }

                    p->parent->colour = 0;
                    p->parent->parent->colour = 1;
                    left_rotate(p->parent->parent);
                }
            }
        }
        root->colour = 0;
    }

    node* tree_minimum(node* q)
    {
        while(q->left != NIL)
        {
            q = q->left;
        }

        return q;
    }

    node* tree_successor(node* p)
    {
        if(p->right != NIL)
        {
            return  tree_minimum(p->right);
        }

        node* q = p->parent;
        while((q != NIL) && (p == q->right))
        {
            p = q;
            q = q->parent;
        }
        return q;
    }

    int set_power()
    {
        int index = 0;
        if(root->data == "\0")
        {
            cout << index << endl;
            return index;
        }
        cross_tree(root,index);
        cout << index << endl;
        return index;

    }

    void cross_tree(node* n, int& index)
    {
        index++;
        if(n->left !=NIL )
        {
            cross_tree(n->left,index);
        }
        if(n->right != NIL)
        {
            cross_tree(n->right,index);
        }

    }

    bool Is_empty()
    {
        if(root->data == "\0")
        {
            cout << "set is empty" << endl;
            return true;
        }
        else
        {
            cout << "set is not empty" << endl;
            return false;
        }
    }

    bool my_find(string str)
    {
        if(cross_tree3(root,str))
        {
            cout << "Element is in set" << endl;
            return true;
        }
        else
        {
            cout << "Element is not in set" << endl;
            return false;
        }
    }
     bool cross_tree3(node* n,string str)
    {
        if(n == NIL)
        {
            return false;
        }
        if(n->data == str)
        {
            return true;
        }
        if(cross_tree3(n->left,str))
        {
            return true;
        }
        if(cross_tree3(n->right,str))
        {
            return true;
        }
        return false;
    }



    void print()
    {
        cross_tree2(root);
    }

    void cross_tree2(node* n)
    {
        cout << n->data << endl;
        if(n->left != NIL )
        {
            cross_tree2(n->left);
        }
        if(n->right != NIL)
        {
            cross_tree2(n->right);
        }

    }

    node operator= (node& p)
    {
        return p;
    }

    void destroy_tree(node* n)
    {
        if(n != NIL)
        {
            destroy_tree(n->left);
            destroy_tree(n->right);
            delete n;
        }
    }

    ~RB_tree()
    {
        destroy_tree(root);
    }
};

int main()
{
    RB_tree a;
    a.RB_insert("ploi");
    a.RB_insert("aifu");
    a.RB_insert("afsh");
    a.RB_insert("afshbkj");
    a.RB_insert("ahj");
    a.set_power();
    a.Is_empty();
    a.print();
    a.my_find("ploi");
    a.my_find("p");
    a.RB_insert("ploi");
    RB_tree b;
    b.RB_insert("lkj");
    b.RB_insert("sdhgjhsd");
    a = b;
    a.print();
    a.set_power();
    b.print();
    return 0;
}
