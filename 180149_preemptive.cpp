#include <bits/stdc++.h>
using namespace std;
struct Process {
    string ID;
    int at;
    int bt;
};

void findWaitingTime(Process proc[], int n) {
    int rt[n];
    int wt[n];
    for (int i = 0; i < n; i++) rt[i] = proc[i].bt;

    int complete = 0, t = 0, minm = INT_MAX,shortest = 0, finish_time;
    bool running = false;

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((proc[j].at <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                running = true;
            }
        }

        if (running == false) {
            t++;
            continue;
        }

        rt[shortest]--;

        minm = rt[shortest];
        if (minm == 0) minm = INT_MAX;

        if (rt[shortest] == 0) {
            complete++;
            running = false;
            finish_time = t + 1;
            cout << "ft - " << finish_time << endl;
            wt[shortest] = finish_time - proc[shortest].at - proc[shortest].bt;

            cout << "waiting time - " << shortest << " - " << wt[shortest]
                 << endl;
            if (wt[shortest] < 0) wt[shortest] = 0;
        }
        t++;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cout << proc[i].ID << " - " << wt[i] << endl;
        sum += wt[i];
    }

    cout << "Average waiting time - " << sum / (n * 1.0) << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    Process proc[n],waiting_list[n];

    for (int i = 0; i < n; i++) {
        Process p;
        cin >> p.ID >> p.at >> p.bt;
        proc[i] = p;
    }
    findWaitingTime(proc, n);

    return 0;
}