#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

struct Point {
    int x, y;

    Point(int x1, int y1) : x(x1), y(y1) {}
    Point() : x(0), y(0) {}

    double distance(const Point &p) {
        return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
    }

    bool operator != (Point const & b)
    {
        return x != b.x || y != b.y;
    }
    bool operator <(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

double cross(const Point &O, const Point &A, const Point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P)
{
    long n = P.size(), k = 0;
    vector<Point> H(2 * n);

    sort(P.begin(), P.end());

    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    for (long i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    H.resize(k - 1);
    return H;
}

double perimeter(vector <Point> &p){
    double per = 0;
    double l, r;
    for (size_t i = 0;i < p.size(); i++){
        if (i + 1 == p.size()) {
            l = (p[i].x - p[0].x);
            r = (p[i].y - p[0].y);
            per = per + sqrt(l*l + r*r);
            break;
        }
        l = (p[i].x - p[i + 1].x);
        r = (p[i].y - p[i + 1].y);
        per = per + sqrt(l*l + r*r);

    }
    return per;
}



int main(){

    int N;
    scanf("%d", &N);
    vector<Point> points(N);
    vector<Point> hool;
    for (int i = 0; i < N; i++){
        int x, y;
        scanf("%d",&x);
        scanf("%d",&y);
        points[i] = Point(x, y);
    }
    hool = convex_hull(points);
    printf("%.2lf", perimeter(hool));
    return 0;
}
