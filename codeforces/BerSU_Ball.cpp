//SOLN BY MOHIT MAROLIYA
#include <functional>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    priority_queue<int> boys, girls;
    int boysNum, girlsNum, matches;

    cin >> boysNum;

    while (boysNum--) {
        int skillLevel;
        cin >> skillLevel;
        boys.push(skillLevel);
    }

    cin >> girlsNum;

    while (girlsNum--) {
        int skillLevel;
        cin >> skillLevel;
        girls.push(skillLevel);
    }

    matches = 0;

    while (!boys.empty() && !girls.empty()) {
        int girlSkill = girls.top();
        int boySkill = boys.top();

        if (boySkill <= girlSkill+1 && boySkill >= girlSkill-1) {
            // if match:
            //~ cout << "Skill matched: " << boySkill << "  " << girlSkill << endl;
            girls.pop();
            boys.pop();
            matches++;
        } else {
            if (boySkill > girlSkill) {
                boys.pop();
            } else {
                girls.pop();
            }
        }
    }

    cout << matches <<endl;
}
