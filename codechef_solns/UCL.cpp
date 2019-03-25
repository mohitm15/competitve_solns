//March Cook-off 2019: Problem 02

#include <bits/stdc++.h>

using namespace std;

int main()
{


	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{	

		int points[4] = {0,0,0,0};
		int goals_diff[4] = {0,0,0,0};
		unordered_map<string, int> teams;
		unordered_map<int,string> rev_teams;
		int team_id =0;
		
		for(int i=0;i<12;i++)
		{
			string s;
			// cin>>s;
			getline(cin,s);
			vector <string> tokens; 
      		// cout<<"string: "<<s<<endl;
		    // stringstream class check1 
		    stringstream check1(s); 
		      
		    string intermediate; 
		      
		    // Tokenizing w.r.t. space ' ' 
		    while(getline(check1, intermediate, ' ')) 
		    { 
		        tokens.push_back(intermediate); 
		    } 
		    // cout<<"size: "<<tokens.size()<<endl; 
		    // Printing the token vector 
		    // for(int i = 0; i < tokens.size(); i++) 
		        // cout << tokens[i] << '\n';
		    string team1 = tokens[0];
		    int g1 = atoi(tokens[1].c_str());
		    string team2 = tokens[4];
		    int g2 = atoi(tokens[3].c_str());
		    // cout<<team1<<g1<<team2<<g2<<endl;
		    if(teams.find(team1)==teams.end())
		    {
		    	teams[team1] = team_id;
		    	rev_teams[team_id] = team1;
		    	team_id++;
		    }
		    if(teams.find(team2)==teams.end())
		    {
		    	teams[team2] = team_id;
		    	rev_teams[team_id] = team2;
		    	team_id++;
		    }

		    if(g1>g2)
		    {
		    	points[teams[team1]]+=3;
		    	goals_diff[teams[team1]]+= g1-g2;
		    	goals_diff[teams[team2]]+= g2-g1;
		    }
		    else if(g2>g1)
		    {
		    	points[teams[team2]]+=3;
		    	goals_diff[teams[team2]]+= g2-g1;
		    	goals_diff[teams[team1]]+= g1-g2;
		    }
		    else
		    {
		    	points[teams[team1]]+=1;
		    	points[teams[team2]]+=1;
		    }
		}
        
        
       //  std::unordered_map<std::string, int>::iterator it = teams.begin();
 
       //  // Iterate over the map using iterator
       //  while(it != teams.end())
       //  {
       //  	std::cout<<it->first << " :: "<<it->second<<std::endl;
       //  	it++;
       //  }
        
       // std::unordered_map<int, string>::iterator it2 = rev_teams.begin();
 
       //  // Iterate over the map using iterator
       //  while(it2 != rev_teams.end())
       //  {
       //  	std::cout<<it2->first << " :: "<<it2->second<<std::endl;
       //  	it2++;
       //  }


        // for(int i=0;i<4;i++)cout<<points[i]<<" ";
        // 	cout<<endl;
        // for(int i=0;i<4;i++)cout<<goals_diff[i]<<" ";
        // 	cout<<endl;
		int max=-1;
		// int max2=-1;
		int t1=-1;
		// string t2;
		for(int i=0;i<4;i++)
		{
			if(points[i]>max)max=points[i],t1=i;
			else if(t1!=-1 && points[i]==max && goals_diff[i]>goals_diff[t1])max = points[i],t1=i;
		}
		cout<<rev_teams[t1]<<" ";
		points[t1]=-1;
		t1=-1;
		max=-1;
		for(int i=0;i<4;i++)
		{
			if(points[i]>max)max=points[i],t1=i;
			else if(t1!=-1 && points[i]==max && goals_diff[i]>goals_diff[t1])max = points[i],t1=i;
		}
		cout<<rev_teams[t1]<<endl;
		// cin.ignore();
	} 
}		
		
			
