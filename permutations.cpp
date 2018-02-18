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


void print_permutation(int p[], int n){

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
		print_permutation(set, n);
	}
	else
	{
		//Set the first element to each element in the permutation adn then permutate a ccordingly
		for (int i = index; i < n; ++i)
		{
//			cout << "before swap 1 "; print_permutation(set, n);
			swap(set[index], set[i]);
//			cout << "after swap 1:  " << index << " with " << i; print_permutation(set, n);
			get_permutations(set, index+1, n); //Move to the next position (i.e. a 1 less subset now )
			swap(set[index], set[i]); //restore the order for proper storage
//			cout << "after swap 2:  " << index << " with " << i; print_permutation(set, n);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the number " << endl;
	cin >> n;

	cout << "factorial of the numebr is " << get_factorial_recursive(n) << endl;

	int *set = new int[n];
	get_factorial_nums(n, set);
	cout << "numbers in the factorial are ";
	print_permutation(set, n);

	cout << "permutations of the number are" << endl;
	get_permutations(set, 0, n);

//	delete [] set;
	delete set;
	return 0;
}