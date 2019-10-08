#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n, m;
lli inf = 100000000000;
struct ed {
    lli src;
    lli des;
    lli wt;
};

struct dj {
    lli cost;
    lli val;
};

lli flag = 0;

// bellman ford
lli bellman_Ford(vector<lli> &dis, vector<struct ed> &edge) {
    for (lli i = 1; i <= n; i++) {
        edge[m + i - 1].src = n + 1;
        edge[m + i - 1].des = i;
        edge[m + i - 1].wt = 0;
    }

    for (lli i = 0; i < n - 1; i++) {
        for (lli j = 0; j < m + n; j++) {
            if (dis[edge[j].des] > dis[edge[j].src] + edge[j].wt) {
                dis[edge[j].des] = dis[edge[j].src] + edge[j].wt;
            }
        }
    }

    for (lli j = 0; j < m + n; j++) {
        if (dis[edge[j].des] > dis[edge[j].src] + edge[j].wt) {
            flag = 1;
            return 0;
        }
    }
    return 0;
}

// djikstra
lli djikstra(lli s, vector<lli> &d, vector<vector<struct dj>> &arr,
             vector<lli> &dis) {
    for (lli i = 1; i <= n; i++) {
        d[i] = inf;
    }
    d[s] = 0;
    set<pair<lli, lli>> st;
    st.insert(make_pair(0, s));

    while (!st.empty()) {
        // set<pair<lli,lli>>::const_iterator p = st.begin();
        auto p = st.begin();
        lli beg = (*p).second;

        for (lli i = 0; i < arr[beg].size(); i++) {
            if (d[arr[beg][i].val] >
                d[beg] + dis[arr[beg][i].val] - dis[beg] + arr[beg][i].cost) {
                d[arr[beg][i].val] =
                    d[beg] + dis[arr[beg][i].val] - dis[beg] + arr[beg][i].cost;
                st.insert({d[arr[beg][i].val], arr[beg][i].val});
            }
        }
        st.erase(p);
    }
    return 0;
}

int main(void) {
    lli t;
    cin >> t;
    for (lli tt = 1; tt <= t; tt++) {
        flag = 0;
        vector<vector<dj>> arr;
        vector<struct ed> edge;
        vector<lli> d;
        vector<lli> dis;
        cin >> n >> m;
        // arr.clear();
        // edge.clear();
        // d.clear();
        // dis.clear();
        arr.resize(n + 1);
        d.resize(n + 1);
        edge.resize(m + 1 + n);

        for (lli i = 0; i < m; i++) {
            cin >> edge[i].src >> edge[i].des >> edge[i].wt;
            struct dj t;
            t.val = edge[i].des;
            t.cost = edge[i].wt;
            arr[edge[i].src].push_back(t);
        }
        for (lli i = 1; i <= n + 2; i++) {
            dis.push_back(0);
        }

        bellman_Ford(dis, edge);
        if (flag == 1) {
            cout << "graph " << tt << " no" << endl;
        }

        else {
            cout << "graph " << tt << " yes" << endl << endl;
            for (lli i = 1; i <= n; i++) {
                cout << dis[i] << " ";
            }
            cout << "0 ";
            cout << endl << endl;
            for (lli i = 1; i <= n; i++) {
                djikstra(i, d, arr, dis);
                for (lli j = 1; j <= n; j++) {
                    if (d[j] != inf) {
                        cout << d[j] - dis[j] + dis[i] << " ";
                    } else {
                        cout << "# ";
                    }
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}