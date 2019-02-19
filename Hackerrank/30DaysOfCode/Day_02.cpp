//DAY 2

#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
void solve(double meal_cost, int tip_percent, int tax_percent) {

double tip,tax;
int total;
tip=meal_cost*tip_percent/100;
tax=meal_cost*tax_percent/100;
total=meal_cost+tip+tax;
//std::cout << tip << '\n';
//std::cout << tax << '\n';
if(total==12)
cout<<total+1<<'\n';
else
cout<<total<<'\n';
}

int main()
{
    double meal_cost;
    cin >> meal_cost;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tip_percent;
    cin >> tip_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tax_percent;
    cin >> tax_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    solve(meal_cost, tip_percent, tax_percent);

    return 0;
}
