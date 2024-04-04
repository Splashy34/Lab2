#include <iostream>
using namespace std;

class Queue
{
public:

	Queue();
	~Queue();

	void clear();
	bool is_empty() const;
	void queue(int data);
	int unqueue();
	int count() const;
	void insertBeforeNegative();
	void removeNegative();
	int count(int data) const;

private:
	class Node
	{
	public:
		Node* next;
		int data;
		Node(int data) : data(data), next(nullptr) {}
	};
	Node* tail;
	Node* head;
	int size;

};
Queue::Queue()
{
	size = 0;
	tail = nullptr;
	head = nullptr;
}
Queue::~Queue()
{
	clear();
}

void Queue::clear()
{
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	tail = nullptr;

}

bool Queue::is_empty() const
{
	if (head == nullptr)
		return true;
	else
	{
		return false;
	}
}

void Queue::queue(int data)
{
	
	Node* newnode = new Node(data);
	if (is_empty())
	{
		head = tail = newnode;
	}
	else
	{
		tail->next = newnode;
		tail = newnode;
	}
	size++;

}

int Queue::unqueue()
{
	if (is_empty())
	{
		return -1;
	}
	else
	{
		Node* temp = head;
		int data = head->data;
		head = head->next;
		delete temp;
		if (head == nullptr)
		{
			tail = nullptr;
		}
		size--;
		return data;
	}
}

int Queue::count() const
{
	return size;
}

void Queue::insertBeforeNegative()
{
	Node* now = head, *prev = nullptr;
	while (now != nullptr)
	{
		if (now->data < 0) 
		{
			Node* newnode = new Node(1);
			if (prev == nullptr)
			{
				newnode->next = head;
				head = newnode;
			}
			else 
			{
				prev->next = newnode;
			}
			newnode->next = now;
			prev = newnode;
			size++;
		}
		prev = now;
		now = now->next;
	}
}

void Queue::removeNegative()
{
	Node* now = head, * prev = nullptr;
	while (now != nullptr)
	{
		if (now->data < 0)
		{
			if (prev == nullptr)
			{
				head = now->next;
				delete now;
				now = head;
			}
			else
			{
				prev->next = now->next;
				delete now;
				now = prev->next;
			}
			if (now == nullptr)
			{
				tail = prev;
			}
			size--;
		}
		else
		{
			prev = now;
			now = now->next;
		}
	}
}

int Queue::count(int data) const
{
	int count = 0;
	for (Node* temp = head; temp != nullptr; temp = temp->next)
	{
		if (temp->data == data)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	Queue q;
	int choise;
	int value = -1;

	cout << "Enter numbers in the queue (0 to stop): " << endl;
	while (true)
	{
		cin >> value;
		if (value == 0) break;
		q.queue(value);
	}
	do
	{
		cout << "1. Add an element\n";
		cout << "2. Delete element\n";
		cout << "3. Count number of elements\n";
		cout << "4. Insert 1 before negative elements\n";
		cout << "5. Delete negative elements\n";
		cout << "6. Count number of entries\n";
		cout << "7. Clear\n";
		cout << "8. Exit\n";
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "Enter the element you want to add: " << endl;
			cin >> value;
			q.queue(value);
			cout << "The element is added." << endl;
			break;
		case 2:
			cout << "Deleted element: " << q.unqueue() << endl;
			break;
		case 3:
			cout << "Number of elements: " << q.count() << endl;
			break;
		case 4:
			q.insertBeforeNegative();
			cout << "Inserted 1 before all negative elements." << endl;
			break;
		case 5:
			q.removeNegative();
			cout << "All negative elements are removed." << endl;
			break;
		case 6:
			cout << "Enter element to count" << endl;
			cin >> value;
			cout << "Amount of entered element: " << q.count(value) << endl;
			break;
		case 7: 
			q.clear();
			cout << "The queue is cleared." << endl;
			break;
		case 8:
			break;
		default:
			cout << "An unknown command. Try again." << endl;
			break;
		}
	} 
	while (choise != 8);
	return 0;
}