// SOLN BY MOHIT MAROLIYA
#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;
typedef pair <int,int> ii ;
typedef vector < ii > vii ;
typedef vector < vii > viii ;

char maze[510][510] ;

bool used[510][510] ;
int n , m ,K ;
bool valid( int x , int y){
	 if ( x >= 0 && x < n && y >= 0 && y < m)
	 	return true;
	 else
	 	return false ;
}

int dx[] = { 1, -1  , 0 , 0};
int dy[] = { 0  ,0 , 1 ,-1} ;

void dfs ( int u , int  v ){

	  used[u][v] = true ;
	  K-- ;

	  for( int i = 0 ; i < 4 ; i++){
	  	 if (K)
	  	 {
	  	 	 int x ,y ;
	  	 	 x = u + dx[i] ; y = v +dy[i] ;
	  	 	 if ( valid(x,y))
	  	 	 if( maze[x][y] == '.' )
	  	 	 if( !used[x][y] )
	  	 	 dfs(x,y) ;
	  	 }
	  }
}

int main(){
   memset ( used , false ,sizeof used) ;
   int i , j ;
   std::cin >> n>>m>>K;

   for( int i = 0 ; i < n ; i++)
   scanf("%s",maze[i]) ;

   vii safe ;

   for( int i = 0 ; i < n ; i++)
   for( int j = 0 ; j < m ; j++)
   if( maze[i][j] == '.' )
   safe.push_back(ii(i,j)) ;

   K = safe.size() - K ;

   dfs(safe[0].first , safe[0].second );

  for( int i = 0 ; i < safe.size() ; i++)
  if(!used[ safe[i].first] [safe[i].second])
  maze [ safe[i].first] [safe[i].second] = 'X' ;

  for( int i = 0 ; i < n ; i++)
   puts(maze[i]) ;

	return 0;
}
