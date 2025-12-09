#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct P { double x,y; };

// even-odd point-in-polygon for axis-aligned polygon
bool inside(const vector<P>& poly, double x, double y) {
    bool c = false;
    int n = poly.size();
    for(int i=0, j=n-1; i<n; j=i++){
        double xi = poly[i].x, yi = poly[i].y;
        double xj = poly[j].x, yj = poly[j].y;

        bool intersect =
            ((yi > y) != (yj > y)) &&
            (x < (xj - xi) * (y - yi) / (yj - yi) + xi);

        if (intersect) c = !c;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream input("input.txt");

    vector<P> reds;
    string s;
    while (getline(input, s)) {
        if (s.empty()) continue;
        int c = s.find(',');
        ll x = stoll(s.substr(0, c));
        ll y = stoll(s.substr(c+1));
        reds.push_back({(double)x, (double)y});
    }

    int R = reds.size();
    ll best = 0;

    for(int i=0; i<R; ++i) {
        for(int j=i+1; j<R; ++j) {

            double x1 = reds[i].x, y1 = reds[i].y;
            double x2 = reds[j].x, y2 = reds[j].y;

            if (x1 == x2 || y1 == y2) continue; // not opposite corners

            double xmin = min(x1, x2);
            double xmax = max(x1, x2);
            double ymin = min(y1, y2);
            double ymax = max(y1, y2);

            // test point inside rectangle interior
            double tx = xmin + 0.5;
            double ty = ymin + 0.5;

            if (!inside(reds, tx, ty)) continue;

            ll area = (ll)(xmax - xmin + 1) * (ll)(ymax - ymin + 1);
            best = max(best, area);
        }
    }

    cout << best << "\n";
}
