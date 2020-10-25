#include <iostream>

struct Node
{
	int data;
	Node *next;
	Node(int data1 = 0) : data(data1), next(nullptr){};
};

struct LinkedList
{
	Node *head;
	int size;
	LinkedList() : head(nullptr), size(0){};
};

void push(LinkedList &list, int data)
{
	list.size++;
	if (list.head == nullptr)
	{
		list.head = new Node(data);
		return;
	}
	Node *tmp_iterator = list.head;
	while (tmp_iterator->next != nullptr)
		tmp_iterator = tmp_iterator->next;
	tmp_iterator->next = new Node(data);
}
void print_list(LinkedList &list)
{
	Node *tmp_iterator = list.head;
	while (tmp_iterator != nullptr)
	{
		std::cout << tmp_iterator->data << " ";
		tmp_iterator = tmp_iterator->next;
	}
	std::cout << std::endl;
}

LinkedList reverse_linked_list(LinkedList &linked_list)
{
	int size = linked_list.size;
	int arr[size];
	Node *temp_iterator = linked_list.head;
	for (int i = 0; i < size; ++i)
	{
		arr[i] = temp_iterator->data;
		temp_iterator = temp_iterator->next;
	}
	LinkedList new_linked_list;
	Node *current_node = new_linked_list.head;
	for (int i = size - 1; i >= 0; --i)
		push(new_linked_list, arr[i]);	
	return new_linked_list;
}


int main()
{
	LinkedList my_linked_list;
	print_list(my_linked_list);
	for (int i = 0; i < 10; ++i)
		push(my_linked_list, i);
	print_list(my_linked_list);
	LinkedList reversed = reverse_linked_list(my_linked_list);
	print_list(reversed);
	return 0;
}