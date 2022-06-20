//in this ques, suppose we are given an array of 'n' elements, and an integer 'k'. Now we will take 'k' elements
//from the array, starting from 0th index, and find the max element among those elements, and put the max element
//in the output array.

//input[] = {1,2,3,3,4,5,2,3,6}
//k = 3
//take {1,2,3}, max = 3
//now take {2,3,3}, max = 3
//now {3,3,4}, max = 4
//now {3,4,5}, max = 5
//now {4,5,2}, max = 5
//now {5,2,3}, max = 5
//now {2,3,6}, max = 6

//output[] = {3,3,4,5,5,5,6}

#include<iostream>
#include<deque>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[90];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int k;
    cin>>k;

    deque <int> q(k);
    int i;
    //process 1st 'k' elements separately
    for(i=0; i<k; i++){
        while(!q.empty() && a[i]>a[q.back()]){
            q.pop_back();
        }
        q.push_front(i);
    }
    
    //processing elements after 1st 'k' elements
    for(;i<n;i++){

        cout<<a[q.front()]; //printing the greatest element in the 1st window.

        //removing the elements of the previous window.
        while(!q.empty() && (q.front()<(i-k))){
            q.pop_front();
        }

        //pushing the window elements by comparing with themselves, if the current index element is greater than the previously pushed element, then
        //previously pushed element is removed and when the queue becomes empty, current element is pushed in the front.
        while(!q.empty() && a[i]>a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    

    return 0;
}