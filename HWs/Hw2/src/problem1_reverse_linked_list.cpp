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

void reverse_linked_list(LinkedList &list)
{
	for (int i = 0; i < list.size / 2; ++i)
	{
		Node *temp_node = list.head;
		for (int j = 0; j < i; ++j)
			temp_node = temp_node->next;
		Node *temp_node_2 = list.head;
		for (int j = 0; j < (list.size - 1) - i; ++j)
			temp_node_2 = temp_node_2->next;
		int aux = temp_node->data;
		temp_node->data = temp_node_2->data;
		temp_node_2->data = aux;
	}
}

void reve(LinkedList &list)
{
	Node *aux = nullptr;
	while(list.head)
	{
		std::swap(list.head->next, aux);
		std::swap(list.head, aux);
	}
	list.head = aux;
}

int main()
{
	LinkedList my_linked_list;
	print_list(my_linked_list);
	for (int i = 0; i < 4; ++i)
		push(my_linked_list, i);
	print_list(my_linked_list);
	reve(my_linked_list);
	print_list(my_linked_list);
	return 0;
}