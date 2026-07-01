#ifndef STUDENT_BST
#define STUDENT_BST

#include <iostream>
using namespace std;

class StudentNode
{
public:
    int rollNo;
    string name;
    double cgpa;
    StudentNode *left;
    StudentNode *right;

    StudentNode(int r, string n, double cg)
    {
        rollNo = r;
        name = n;
        cgpa = cg;
        left = right = nullptr;
    }
};
class StudentBST
{
private:
    StudentNode *root;

    void destroy(StudentNode *s)
    {
        if (s == nullptr)
            return;
        destroy(s->left);
        destroy(s->right);
        delete s;
    }

    void InOrder(StudentNode *s)
    {
        if (s != nullptr)
        {
            InOrder(s->left);
            cout << s->rollNo << ",";
            cout << s->name << ",";
            cout << s->cgpa << endl;
            InOrder(s->right);
        }
    }

    void displayInRange(StudentNode *s, double cgpaStart, double cgpaEnd)
    {
        if (s != nullptr)
        {
            displayInRange(s->left, cgpaStart, cgpaEnd);
            if (s->cgpa >= cgpaStart && s->cgpa <= cgpaEnd)
            {
                cout << s->rollNo << ",";
                cout << s->name << ",";
                cout << s->cgpa << endl;
            }
            displayInRange(s->right, cgpaStart, cgpaEnd);
        }
    }

    StudentNode *findMin(StudentNode *curr)
    {
        while (curr->left != nullptr)
        {
            curr = curr->left;
        }
        return curr;
    }

public:
    StudentBST()
    {
        root = nullptr;
    }
    bool insert(int r, string n, double cg)
    {
        if (search(r))
        {
            cout << "Roll no already exists." << endl;
            return false;
        }
        else
        {
            if (root == nullptr)
            {
                root = new StudentNode(r, n, cg);
                return true;
            }
            StudentNode *curr = root;
            StudentNode *par = nullptr;
            while (curr != nullptr)
            {
                par = curr;
                if (r < curr->rollNo)
                {
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
            if (r < par->rollNo)
            {
                par->left = new StudentNode(r, n, cg);
                return true;
            }
            else
            {
                par->right = new StudentNode(r, n, cg);
                return true;
            }
        }
    }

    bool search(int r)
    {
        StudentNode *curr = root;
        while (curr != nullptr)
        {
            if (curr->rollNo == r)
                return true;
            else if (r < curr->rollNo)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return false;
    }

    StudentNode *findMin()
    {
        StudentNode *min = findMin(root);
        return min;
    }

    bool remove(int r)
    {
        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
            return false;
        }

        StudentNode *curr = root;
        StudentNode *par = nullptr;
        while (curr != nullptr && curr->rollNo != r)
        {
            par = curr;
            if (r < curr->rollNo)
                curr = curr->left;
            else if (r > curr->rollNo)
                curr = curr->right;
        }

        if (curr == nullptr)
        {
            cout << "RollNo not found." << endl;
            return false;
        }

        // node with no child
        if (curr->left == nullptr && curr->right == nullptr)
        {
            if (par == nullptr)
            {
                delete root;
                root = nullptr;
            }
            else if (r < par->rollNo)
            {
                delete curr;
                par->left = nullptr;
            }
            else
            {
                delete curr;
                par->right = nullptr;
            }
            return true;
        }
        // only left child
        if (curr->left != nullptr && curr->right == nullptr)
        {
            if (par == nullptr)
            {
                root = curr->left;
            }
            else if (par->left == curr)
            {
                par->left = curr->left;
            }
            else
            {
                par->right = curr->left;
            }
            curr->left = nullptr;
            delete curr;
            return true;
        }
        // only right child
        if (curr->left == nullptr && curr->right != nullptr)
        {
            if (par == nullptr)
            {
                root = curr->right;
            }
            else if (par->left == curr)
            {
                par->left = curr->right;
            }
            else
            {
                par->right = curr->right;
            }
            curr->right = nullptr;
            delete curr;
            return true;
        }
        // node with both child
        if (curr->left != nullptr && curr->right != nullptr)
        {
            StudentNode *rightMin = findMin(curr->right);
            int minValue = rightMin->rollNo;
            remove(minValue);
            curr->rollNo = minValue;
            return true;
        }
    }

    void displayInRange(double cgpaStart, double cgpaEnd)
    {
        displayInRange(root, cgpaStart, cgpaEnd);
    }

    void InOrder()
    {
        InOrder(root);
    }

    ~StudentBST()
    {
        destroy(root);
        root = nullptr;
    }
};

#endif