//SOLN BY MOHIT MAROLIYA;


#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }

    d[a] = find(d, d[a]);
    return d[a];
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    d[a] = b;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> lang(m+1);
    vector<int> d(n, -1);
    bool langseen = false;

    for(int i = 0; i < n; i++) {
        int langs;
        cin >> langs;
        for(int j = 0; j < langs; j++) {
            langseen = true;

            int l;
            cin >> l;

            lang[l].push_back(i);
        }
    }

    for(auto i : lang) {
        for(int j = 1; j < i.size(); j++) {
            join(d, i[j-1], i[j]);
        }
    }

    int total = 0;
    for(int i = 0; i < d.size(); i++) {
        if(d[i] == -1) {
            total++;
        }
    }

    if(langseen) {
        total--;
    }

    cout << total << endl;
}
