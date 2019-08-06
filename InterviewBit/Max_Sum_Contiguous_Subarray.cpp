//Max Sum Contiguous Subarray

int Solution::maxSubArray(const vector<int> &A) {
    int size= A.size();
    int a = INT_MIN, b = 0; 

    for (int i = 0; i < size; i++) 
    { 
        b+=A[i]; 
        if (a < b) 
            a = b; 

        if (b < 0) 
            b = 0; 
    } 
    return a;
}
