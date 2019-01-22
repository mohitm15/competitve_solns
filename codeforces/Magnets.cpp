// contest: Codeforces Round #200 (Div. 2), problem: (A) Magnets, Accepted, #
 
 #include<iostream>
  using namespace std;

  int main()
  {
      long int n,i,j,pn=0;
      cin>>n;
      long int a[n];

      for (  i=0; i <n; i++) cin>>a[i];

      for ( i=0; i<n; )
      {
          if ( a[i]==10)
          {
              for ( j=i+1; j<n; j++)
                if ( a[j]!=10) break;

              pn++;
              i=j;
          }
          else
          {
              for( j=i+1; j<n; j++)
                if (a[j]!=1) break;
              pn++;
              i=j;
           }
      }

      cout<<pn<<endl;

      return 0;


  }
