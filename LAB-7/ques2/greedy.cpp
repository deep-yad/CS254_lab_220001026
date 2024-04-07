#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void findMaxProfit(vector<Job>& jobs, int n) {
    sort(jobs.begin(), jobs.end(), comparison);
    int result[n];
    bool slot[n];
    int ans=0;
    for (int i = 0; i < n; i++)
        slot[i] = false;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                ans+=jobs[i].profit;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << jobs[result[i]].id << ' ';

    cout<<"The max profit is : "<<ans<<endl;
}

int main() {
    vector<Job> jobs = {{'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30}};
    int n = jobs.size();
    findMaxProfit(jobs, n);
    return 0;
}

