/**
There are n people standing in a circle (numbered clockwise 1 to n) waiting to be executed. The counting out begins at point 1 in the circle and proceeds around the circle in a fixed direction (clockwise). In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.

For example, if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives.
If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, 1 are killed in order, and person at position 4 survives.

Note: The above is a variation and generalization of josepheus problem
*/

/**
There are n people standing in a circle (numbered clockwise 1 to n) waiting to be executed. The counting out begins at point 1 in the circle and proceeds around the circle in a fixed direction (clockwise). In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.

For example, if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives.
If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, 1 are killed in order, and person at position 4 survives.

Note: The above is a variation and generalization of josepheus problem
*/

#include<iostream>
using namespace std;

int findSafePosition(int n, int k){

    if(k > n){
        cout << "Invalid input" << endl;
        return -1;
    }

    //Create a list of all criminals alive
    int* cids = new int[n]; //Making one array bigger so that 0 indexing and id's dont' confuse
    int* safe_cids = new int[n]; //Making one array bigger so that 0 indexing and id's dont' confuse

    for(int i=0; i< n; i++){
        cids[i] = i+1;
        safe_cids[i] = 0;
    }

    int safe_position=0; //To start with no position is safe
    int person_left  = n;
    int person_to_kill = k; //kth person will be killed. k is guaranteed here to be less than n

    while(person_left > 1)
    {
//      cout << "Person left"  << person_left << endl;

        for(int i=0; i< n && person_left>1; i++){
//            cout << "iter: " << i << " person_id_to_kill: " << person_to_kill << " current person Id[" << i << "]: " << cids[i] << endl;
            if(cids[i] == 0){
                person_to_kill++;
                person_to_kill = (person_to_kill%n != 0)? person_to_kill%n : n;
                continue;
            }

            if(cids[i] == person_to_kill)
            {
//                cout << "killing " << cids[i] << endl;
                cids[i]=0;
                person_to_kill = (((person_to_kill + k)%n != 0) ? (person_to_kill + k)%n: n);
                person_left--;
            }
            else
            {
//                cout << "Sparing " << cids[i] << endl;
            }
        }

    }

    for(int i=0; i< n; i++){
        if(cids[i] != 0){
            safe_position = cids[i];            //not caring for a trailing comma
        }
    }

    return safe_position;
}

int main()
{

    // Note that size of arr[] is considered 200 according to
    // the constraints mentioned in problem statement.
    int t, n, k;
//    int arr[100];

    // Input the number of test cases you want to run
    cin >> t;

    // One by one run for all input test cases
    while (t--)
    {
        // Input the number of persons
        cin >> n;

        //Input the kth person to kill
        cin >> k;

        // Compute and print result
//        cout << findSafePosition(n, k) << " is final safe position *** " << endl;
        cout << findSafePosition(n, k) << endl;
    }

    return 0;
}
