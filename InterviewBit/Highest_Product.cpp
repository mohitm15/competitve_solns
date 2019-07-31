
//Soln By Mohit Maroliya



// Given an array of integers, return the highest product possible by multiplying 3 numbers from the array
// Input:

// array of integers e.g {1, 2, 3}
// NOTE: Solution will fit in a 32-bit signed integer 

// Example:

// [0, -1, 3, 100, 70, 50]

// => 70*50*100 = 350000




int Solution::maxp3(vector<int> &a) {
    int n=a.size(),ans,cnt=0;
    sort(a.begin(),a.end());
    if(a[n-1]==0)
    {
        ans=0;
    }
    else
    {
      for(int i=0;i<n;i++)
      {
          if(a[i]<0)
          cnt++;
      }
      //cout<<cnt<<"yo"<<'\n';
      if(cnt>=2 && cnt<n)
      {
          if((abs(a[0])>=abs(a[n-2])) && (abs(a[1])>=abs(a[n-3])))
                ans=a[0]*a[1]*a[n-1];
          else if((a[0]*a[1])>(a[n-2]*a[n-3]))
                ans=a[0]*a[1]*a[n-1];
          else
          ans=a[n-1]*a[n-2]*a[n-3];
      }
      else if(cnt==n)
      {
          ans=a[n-1]*a[n-2]*a[n-3];
      }
      else
      {
        ans=a[n-1]*a[n-2]*a[n-3];
      }
    }
    return ans;
}
