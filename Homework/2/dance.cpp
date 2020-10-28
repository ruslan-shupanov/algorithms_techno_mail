/*
 * анец точек
На прямой располагается 1⩽N⩽10000 точек с целочисленными координатами −109⩽Vi⩽109.
Каждой из точек разрешается сделать ровно одно движение (танцевальное па) в любом направлении на расстояние не больше 0⩽L⩽108 и остановиться на другой позиции.
Какое минимальное количество точек может оказаться после окончания танца (все точки после танца, оказывающиеся на одной позиции сливаются в одну)?

Input format
L N

V1

V2

...

VN

Output format
MinimalNumberOfPoints

Examples
Input
10 5
30 3 14 19 21

Output
2
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t n;
    int l;
    cin >> l; cin >> n;

    vector<int> points(n);
    for (auto &point : points)
        cin >> point;

    sort(points.begin(), points.end());

    size_t amount = 0;
    int start = points[0];
    int end = start + 2 * l;
    for (size_t i = 0; i < points.size(); i++)
    {
        while(points[i] <= end && i < n) i++;
        amount++;
        start = points[i];
        end = start + 2 * l;
        if (i == n - 1) amount++;
    }

    cout << amount << endl;

    return 0;
}