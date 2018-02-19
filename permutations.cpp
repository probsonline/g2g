#include <iostream>
using namespace std;

typedef struct _node
{
	int *data;
	struct _node *next;	
} node;

node *permutations_list;

void initialize_list(node *head);
void add_to_list(node *head, int data[], int n);
void remove_from_list(node *head, int data[]);
void empty_list(node *head);
bool search_list(node *head, int *data_in, int* data_out, int n);
void print_list(node *head);

int get_factorial_nums(int n, int set[]){
	int fact=1;    //0! is 1

	if (n==0)
	{
			set[0]=1;
	}
	else{
		for (int i = n; i >= 1; --i)
		{
			set[i-1]=i;
			fact =  fact * i;
		}
	}

	return fact;

}


int get_factorial_recursive(int n){

	if ((n==1) || (n==0))
	{
		return 1;
	}
	else
	{
		return n*get_factorial_recursive(n-1);
	}
}


void print_array(int p[], int n){

	cout << "{ ";
	for (int i = 0; i < n; ++i)
	{
		if ((i!=n-1))
		{
			cout << p[i] << ", ";
		}
		else{
			cout << p[i] ;
		}
	}
		cout << " }" << endl ;
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



//p: array to hold the permutations
//index: Current character/member to start the permutation with
// number of characters
bool found=false;
int *starting_permutation;

void get_permutations(int set[], int index, int n){

	if (found) return;

//    cout << "index= " << index << endl;
	if (index==n) //reached the last character. so print it
	{
		found = compare_data(starting_permutation, set, n);
		if (found)
		{
			cout << "found the next permutation ";
		}
		print_array(set, n);
	}
	else
	{
		//Set the first element to each element in the permutation adn then permutate a ccordingly
		for (int i = index; i < n; ++i)
		{
//			cout << "before swap 1 "; print_array(set, n);
			swap(set[index], set[i]);
//			cout << "after swap 1:  " << index << " with " << i; print_array(set, n);
			get_permutations(set, index+1, n); //Move to the next position (i.e. a 1 less subset now )
			swap(set[index], set[i]); //restore the order for proper storage
//			cout << "after swap 2:  " << index << " with " << i; print_array(set, n);
		}
	}
}

int perm2calls=0;

void get_permutations2(int set[], int index, int n)
{
	cout << "get_permutations2 call No: " << perm2calls++ << endl;
	if (index==n) //reached the last character. so print it
	{
		print_array(set, n);
		add_to_list(permutations_list, set, n);
		print_list(permutations_list);
	}
	else
	{
		//Set the first element to each element in the permutation adn then permutate a ccordingly
		for (int i = index; i < n; ++i)
		{
			cout << "before swap 1 "; print_array(set, n);
			swap(set[index], set[i]);
			cout << "after swap 1:  " << index << " with " << i; print_array(set, n);
			get_permutations(set, index+1, n); //Move to the next position (i.e. a 1 less subset now )
			swap(set[index], set[i]); //restore the order for proper storage
			cout << "after swap 2:  " << index << " with " << i; print_array(set, n);
		}
	}
}

//Get from the input permutation, what subset can be ontained to get the next permutation
int get_sub_permutation_start(int p[], int n)
{
	int index=0;

	while(p[index] != n)
	{
		index++;
	}

	return (index !=0)? p[index-1]: p[index]; //this is not necessarily correct.

}

bool search_next_permutation(int input[], int n, int next_perm[])
{
	return search_list(permutations_list , input, next_perm, n);
}

int main()
{

    // Note that size of arr[] is considered 200 according to
    // the constraints mentioned in problem statement.
    int t, n;
    int * p;

//    int arr[100];

    // Input the number of test cases you want to run
    cin >> t;

    // One by one run for all input test cases
    while (t--)
    {
        // Input the number for which to calculate the pemutations
        cin >> n;

        if (n > 0)
        {
        	//Allocate memory for the permutation entry
        	starting_permutation = new int[n];
	        //Input the starting permutation
	        for (int i = 0; i < n; ++i)
	        {
	        	cin >> starting_permutation[i];
	        }

        }
        else
        {
        	cout << "invalid input" << endl;
        }


        //Calculate how many permutations are possible
//        cout << "This number has " << get_factorial_recursive(n) << " permutations " << endl;
        p = new int[n];
        cout << "This number has " << get_factorial_nums(n, p) << " permutations " << endl;        //Find until what number the permutation is in order 
        get_permutations(p, 0, n);
#if 0
        cout << "this was the permutation input (as starting permutation";
        print_array(starting_permutation, n);

        //Find permutations of the the subset from where the next greater one will start
        int m = get_sub_permutation_start(starting_permutation, n);
        cout << "the index from where the next big permutations will be found is  " << n-m << endl;
//        permutations_list = new int*[n-m];  //To save memory only saving permutations that will have changing members starting from the first member that will change
        initialize_list(permutations_list);
        print_list(permutations_list);
        cout << "we'll get " <<  get_factorial_recursive(n-m) << " permutations for finding the bigger one" << endl;
        get_permutations(p, n-m, n); //start getting permutations from one index less than from where the change starts
//        get_permutations2(p, n-m, n); //start getting permutations from one index less than from where the change starts
        perm2calls=0;

        int *next_perm = new int[n];
        if(search_next_permutation(starting_permutation, n, next_perm))
        {
        	cout << "This is the next permutation ";
        	print_array(next_perm, n);
        }
        else
        {
        	cout << "next perm not found. Simple print to be implemented yet\n";
        }
#endif
    }

    return 0;
}



//===============================================================
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

void insert_first_node(node *head, node *current)
{
	head = current;
	current->next = NULL;
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
	else
	{
		insert_first_node(head, temp);
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

void print_list(node *head)
{
	if (head == NULL)
	{
		cout << "No node in the list" << endl;
		return;
	}

	node* current = head;
	int i=0;
	node* temp;

	while(current != NULL)
	{
		cout << "node: " << i++ << "node data ";
		print_array(current->data, sizeof(current->data)/sizeof(int *));
		current = current->next;
	}	
}

bool compare_nodes(node *sample, node *comparison)
{
	int n = sizeof(sample->data)/sizeof(int *);
	return (compare_data(sample->data, comparison->data, n));
}

bool search_list(node *head, int *data_in, int* data_out, int n)
{
	node* current = head;
	node * temp;

	while(current != NULL)
	{
		cout << "Current node's data is ";
		print_array(current->data, n);
		if(compare_data(data_in, current->data, n))
		{
			copy_data(data_out, data_in, n);
			return true;
		}
		current = current->next;
	}

	return false;
}
