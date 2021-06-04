#include <iostream>
#include <string>
using namespace std;

class student {
public:
	int id, rollNum;
	string name;
	student* next, * prev;
	void insert(int, string, int);
	void update(int);
	bool isEmpty();
	void display();
	void del(int);
};

student* head = NULL;
void student::insert(int id, string na, int rn) {
	student* newnode = new student();
	newnode->id = id;
	newnode->name = na;
	newnode->rollNum = rn;
	if (head == NULL) {
		newnode->next = newnode;
		newnode->prev = newnode;
		head = newnode;
		return;
	}
	else {
		student* ptr = head;
		while (ptr->next != head) {
			ptr = ptr->next;
		}
		ptr->next = newnode;
		newnode->prev = ptr;
		newnode->next = head;
	}
}
void student::display() {
	student* temp = head;
	int node = 1;
	while (temp->next != head) {
		cout << "\n\t\tStudent Number: " << node << endl;
		cout << "\t\tID: " << temp->id << endl;
		cout << "\t\tName: " << temp->name << endl;
		cout << "\t\tRoll Number: " << temp->rollNum << endl << endl;
		node++;
		temp = temp->next;
	}
	cout << "\n\t\tStudent Number: " << node << endl;
	cout << "\t\tID: " << temp->id << endl;
	cout << "\t\tName: " << temp->name << endl;
	cout << "\t\tRoll Number: " << temp->rollNum << endl << endl;
}

void student::del(int pos) {
	student* p, * q;
	p = head;
	q = head->next;
	student* tail = head;
	while (tail->next != head) {
		tail = tail->next;
	}
	if (p->id == pos) {
		head = q;
		delete(p);
		q->prev = tail;
		tail->next = q; // This will delete the first node
	}
	else {
		while (q->id == pos) {
			p = p->next;
			q = q->next;
		}
		if (q->next == head) {
			p->next = head;
			delete(q);
			head->prev = p; // This will delete the last node
		}
		else {
			student* store;
			store = q->next;
			p->next = store;
			store->prev = p;
			delete(q);  // if the value is between the list
		}
	}
}
bool student::isEmpty()
{
	return(head == NULL);
}
void student::update(int idNo) {
	student* temp = head;
	bool notFound = true;
	while (temp->next != head)
	{
		if (temp->id == idNo)
		{
			notFound = false;
			temp->display();
			char option;
			cout << "\n\n\n\t\t1.  Update Name Of Student";
			cout << "\n\n\n\t\t2.  Update Roll Of Student";
			cout << "\n\n\n\t\t3.  Update ID # Of Student\n\n\n\t\t";
			cin >> option;
			system("CLS");
			if (option == '1')
			{
				cout << "\n\t\Please enter the New name: ";
				cin >> temp->name;
			}
			else if (option == '2')
			{
				cout << "\n\t\t\tPlease enter the New Roll Number: ";
				cin >> temp->rollNum;
			}
			else if (option == '3')
			{
				cout << "\n\t\t\tPlease enter the New Id: ";
				cin >> temp->id;
			}
			break;
		}
		temp = temp->next;
	}
	if (notFound == true) {
		cout << "\n\t\tThe student not found!!!!\n";
		return;
	}
	
}

void main()
{
	student s;
	string newName;
	int newRoll, Newid;
	int Id, rollnum;
	string name;
	int toDel;
	int toUp;
	cout << "\n\n\t\t\tSTUDENT REPOSITORY\n\n";
	cout << "\t\t\tPress c to continue: ";
	char con;
	cin >> con;
	if (con == 'c') {
		goto Menu;
	}
	else {
		exit(1);
	}
Menu:
	system("cls");
	cout << "\n\n\t\tEnter 1 for enter data\n";
	cout << "\t\tEnter 2 for Delete Someone's Data\n";
	cout << "\t\tEnter 3 for Display Data\n";
	cout << "\t\tEnter 4 for Update Data\n";
	int choice;
	cout << "\t\tEnter Your Choice Please: ";
	cin >> choice;
	system("cls");
	switch (choice) {
	case 1:
		cout << "\n\n\t\tPlease enter The name: ";
		cin.ignore();
		getline(cin, name);
		cout << "\t\tPlease enter the Id: ";
		cin >> Id;
		cout << "\t\tPlease enter the Roll Number: ";
		cin >> rollnum;
		s.insert(Id, name, rollnum);
		break;
	case 2:
		cout << "\n\t\tEnter the ID of which data you want to Delete: ";
		cin >> toDel;
		s.del(toDel);
		break;
	case 3:
		cout << "\n\t\t****Displayed List**\n\n";
		s.display();
		break;
	case 4:
		cout << "\n\t\tEnter the ID of which data you want to Update: ";
		cin >> toUp;
		s.update(toUp);
		break;
	}
	cout << "\n\t\tYou want Goto Menu or Exit? (Menu = 1, Exit = 2): ";
	int temp;
	cin >> temp;
	if (temp == 1) {
		goto Menu;
	}
	else {
		exit(1);
	}

}