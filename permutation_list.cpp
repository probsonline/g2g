#include <iostream>
using namespace std;

typedef struct _node
{
	int *data;
	struct _node *next;	
} node;

void initialize_list(node *head);
extern void add_to_list(node *head, int data[], int n);
extern void remove_from_list(node *head, int data[]);
extern void empty_list(node *head);

void copy_data(int* d, int* s, int n)
{
	for (int i = 0; i < n; ++i)
	{
		d[i] = s[i];
	}
}

void initialize_list(node *head)
{
	head = NULL;
}

void add_to_list(node *head, int data[], int n)
{
	node *temp, *current;

	temp = new node;
	temp->data = new int[n]; //allocate memory for the data specifically and don't rely on the passed array
	copy_data(temp->data, data, n);


	//traverse to find the last element and add the element at the end
	if (head != NULL)
	{
		current = head;
		while(current->next != NULL)
		{
			current = current->next;
		}

		current->next = temp;
		temp->next = NULL;
	}
}

void remove_from_list(node *head, node *to_remove)
{
	node* current = head;
	node* temp;

	while(current != NULL)
	{
		temp = current;
		if (temp == to_remove)
		{
			delete [] temp->data;
			delete temp;
		}
		current = current->next;
	}
}

void empty_list(node *head)
{
	node* current = head;
	node * temp;

	while(current != NULL)
	{
		temp = current;
		current = current->next;

		delete [] temp->data;
		delete temp;
	}
}

bool compare_data(int *sample, int *comparison, int n)
{
	int i=0;
	while(i<n && sample[i]==comparison[i]){
		i++;
	}

	//only interested in matches, differing by 1
	if (i != n)
	{
		if (comparison[i]-sample[i] == 1)
		{
			/* If comparison is only 1 greater in the first change place, then we found the next permutation */
			return true;
		}
	}

	return false;
}


bool compare_nodes(node *sample, node *comparison)
{
	int n = sizeof(sample->data)/sizeof(int *);
	return (compare_data(sample->data, comparison->data, n));
}

int main(int argc, char const *argv[])
{
	node *permutations;

	initialize_list(permutations);

	int data[] = {1,2,3};
	add_to_list(permutations, data, 3);

	empty_list(permutations);

	return 0;
}
