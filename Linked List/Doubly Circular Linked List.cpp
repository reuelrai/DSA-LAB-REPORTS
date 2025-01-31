#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->previous = NULL;
    }
};

class DoublyCircularLinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void insertAtFront(int x)
    {
        Node *newNode = new Node;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = newNode;
            newNode->previous = newNode;
            tail = newNode;

            newNode->data = x;
        }
        else
        {
            head->previous = newNode;
            newNode->next = head;

            head = newNode;

            tail->next = head;
            head->previous = tail;

            newNode->data = x;
        }
    }

    void insertAtBack(int x)
    {
        Node *newNode = new Node;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = newNode;
            newNode->previous = newNode;
            tail = newNode;

            newNode->data = x;
        }
        else
        {
            Node *newNode = new Node;

            newNode->previous = tail;
            tail->next = newNode;

            tail = newNode;

            tail->next = head;
            head->previous = tail;

            newNode->data = x;
        }
    }

    void insertBetween(int x, int ind)
    {
        Node *newNode = new Node;
        int i = 0;

        Node *temp = head;
        while (i < ind - 1)
        {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        newNode->previous = temp;
        newNode->next->previous = newNode;

        newNode->data = x;
    }

    void traverseNext()
    {
        Node *temp;
        for (temp = head; temp != tail; temp = temp->next)
        {
            cout << temp->data << "->";
        }
        cout << temp->data << "->NULL";
        cout << endl;
    }

    void traversePrevious()
    {
        Node *temp;
        cout << "NULL"
             << "<-";
        for (temp = tail; temp != head; temp = temp->previous)
        {
            cout << temp->data << "<-";
        }
        cout << temp->data;
        cout << endl;
    }

    void deleteFromFront()
    {
        if (head == NULL)
        {
            cout << "Can't delete the list is empty." << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            if (head->next != head)
            {
                head->previous = tail;
                tail->next = head;
            }
            else
            {
                tail = NULL;
                head = NULL;
            }
            delete temp;
        }
    }

    void deleteFromBack()
    {
        if (head == NULL)
        {
            cout << "Can't delete the list is empty." << endl;
        }
        else
        {
            Node *temp = tail;
            tail = tail->previous;
            if (tail->previous != tail)
            {
                tail->next = head;
                head->previous = tail;
            }
            else
            {
                tail = NULL;
                head = NULL;
            }
            delete temp;
        }
    }

    void deleteFromBetween()
    {
        if (head == NULL)
        {
            cout << "Can't delete the list is empty." << endl;
        }
        else
        {
            int ind;
            cout << "Enter an index to delete from: ";
            cin >> ind;

            Node *temp;
            int i = 0;
            for (i = 0, temp = head; (i < ind - 1) && (temp->next->next != head); i++, temp = temp->next)
                ;
            Node *toDel = temp->next;
            if (temp->next->next == head)
            {
                tail = temp;
                tail->next = head;
                head->previous = tail;
            }
            else
            {
                temp->next = temp->next->next;
                temp->next->previous = temp;
            }

            delete toDel;
        }
    }

    void mainProcess()
    {
        int uInput;
        do
        {
            cout << "Choose an operation from below: " << endl;
            cout << "1 ) Insert at front" << endl
                 << "2 ) Insert at back" << endl
                 << "3 ) Insert in between" << endl
                 << "4 ) Traverse from front" << endl
                 << "5 ) Traverse from back" << endl
                 << "6 ) Delete from front" << endl
                 << "7 ) Delete from back" << endl
                 << "8 ) Delete from between" << endl
                 << "9 ) Exit the program" << endl;
            cin >> uInput;
            switch (uInput)
            {
            case 1:
                int valuef;
                cout << "Enter a number to input: ";
                cin >> valuef;
                insertAtFront(valuef);
                break;

            case 2:
                int valuel;
                cout << "Enter a number to input: ";
                cin >> valuel;
                insertAtBack(valuel);
                break;

            case 3:
                int valueb, pos;
                cout << "Enter a number to input: ";
                cin >> valueb;
                cout << "Enter a position : ";
                cin >> pos;
                insertBetween(valueb, pos);
                break;

            case 4:
                traverseNext();
                break;

            case 5:
                traversePrevious();
                break;

            case 6:
                deleteFromFront();
                break;

            case 7:
                deleteFromBack();
                break;

            case 8:
                deleteFromBetween();
                break;

            case 9:
                cout << "Program is exiting..." << endl;
                break;

            default:
                cout << "Invalid input" << endl;
                break;
            }
        } while (uInput != 9);
    }
};

int main()
{
    DoublyCircularLinkedList d1;
    d1.mainProcess();
}
