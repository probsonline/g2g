#include <iostream>
using namespace std;

void print_array(int p[], int n);
bool compare_array(int sample[], int comparison[], int n);

bool found=false;
int *starting_permutation;

void get_permutations(int set[], int index, int n){

	if (found) return;

//    cout << "index= " << index << endl;
	if (index==n) //reached the last character. so print it
	{
		found = compare_array(starting_permutation, set, n);
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


//p: array to hold the permutations
//index: Current character/member to start the permutation with
// number of characters
bool check_if_greatest_permutation(int input[], int n)
{
//	cout << "check_if_greatest_permutation" << endl;
	int i=0;
	while(i < n && input[i] == n-i)
	{
//		cout << "Checking that " << input[i] << " is " << n-i << endl;
		i++;
	}

	return (i==n)?true:false;
}

void print_array(int p[], int n)
{

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


bool compare_array(int sample[], int comparison[], int n)
{
	int i=0;
	int counter=0;
	bool match=false;
	while(i<n && sample[i]==comparison[i]){
//		cout << "Checking that " << comparison[i] << " at " << i << " is " << sample[i] << endl;
		i++;
	}

	//only interested in matches, differing by 1
	if (i != n)
	{
		if (comparison[i]-sample[i] == 1)
		{
			match = true;
		}
	}

	return match;
}

void get_factorial_nums(int n, int set[]){
	int fact=1;    //0! is 1

	if (n==0)
	{
			set[0]=1;
	}
	else
	{
		for (int i = n; i >= 1; --i)
		{
			set[i-1]=i;
		}
	}
}

int main()
{

    // Note that size of arr[] is considered 200 according to
    // the constraints mentioned in problem statement.
    int t, n;
    int * p;

    // Input the number of test cases you want to run
    cin >> t;

    if (t < 1)
    {
    	cout << "Invalid number for test case input. Enter at leat one test case.\n";
    	return 0;
    }

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
	        cout << "Input permutation: ";
	        print_array(starting_permutation, n);

	        p = new int[n];
	        get_factorial_nums(n,p);
	        if (check_if_greatest_permutation(starting_permutation, n))
	        {
		        cout << "The input is already the greated permutation. The sorted order is ";
		        print_array(p, n);
	        }
	        else
	        {
		        cout << "Findng permutations"  << endl;        //Find until what number the permutation is in order 
		        get_permutations(p, 0, n);
	        }

        }
        else
        {
        	cout << "invalid input. the number must be positive" << endl;
        }
    }
    return 0;
}



#if 0
//Keeping some good but not used functions in the final solution
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

#endif
