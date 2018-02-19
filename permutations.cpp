#include <iostream>
using namespace std;


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

//p: array to hold the permutations
//index: Current character/member to start the permutation with
// number of characters
void get_permutations(int set[], int index, int n){
//    cout << "index= " << index << endl;
	if (index==n) //reached the last character. so print it
	{
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


//Get from the input permutation, what subset can be ontained to get the next permutation
int get_sub_permutation_start(int p[], int n)
{
	int index=0;
#if 1

	while(p[index] != n)
	{
		index++;
	}

	return (index !=0)? p[index-1]: p[index]; //this is not necessarily correct.

#else
	while(p[i] != n && (p[i+1] > p[i]))
	{
		index = i;
		i++;
	}

	return (p[index] == n) ?

	//run to n-1 to avoid array out of bound issue
	for (int i = 0; i < n-1; ++i)
	{
		if (p[i] != n && (p[i+1] > p[i]))
		{
			index = i;
			/* code */
		}
	}
#endif	
}


int main()
{

    // Note that size of arr[] is considered 200 according to
    // the constraints mentioned in problem statement.
    int t, n;
    int *permutations_list;
    int *starting_permutation;
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

        cout << "this was the permutation input (as starting permutation";
        print_array(starting_permutation, n);

        //Find permutations of the the subset from where the next greater one will start
        int m = get_sub_permutation_start(starting_permutation, n);
        cout << "the sub permutation number is " << m << endl;
//        int *sub_p = new int[m];
//        cout << "This sub has these numbers for permutations " ;
//        get_factorial_nums(m, sub_p);
//        get_permutations(sub_p, 0, m); //Can we pass a non zero value for index and get the next permutation?
        get_permutations(p, m-1, n); //Can we pass a non zero value for index and get the next permutation?
    }

    return 0;
}
