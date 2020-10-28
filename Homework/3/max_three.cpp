#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

long long int highest_product_of_3(vector<long long int> &vec, int n) {
    long long int highest = max(vec[0], vec[1]);
    long long int lowest =  min(vec[0], vec[1]);
    long long int highest_product_of_2 = vec[0] * vec[1];
    long long int lowest_product_of_2  = vec[0] * vec[1];
    long long int highest_product_of_three = vec[0] * vec[1] * vec[2];
            
    for (int i = 2; i < n; i++) {

        highest_product_of_three = max(highest_product_of_three, max(vec[i] * highest_product_of_2, vec[i] * lowest_product_of_2));

        highest_product_of_2 = max(highest_product_of_2, max(vec[i] * highest, vec[i] * lowest));

        lowest_product_of_2 = min(lowest_product_of_2, min(vec[i] * highest, vec[i] * lowest));

        highest = max(highest, vec[i]);

        lowest = min(lowest, vec[i]);
    }
    return highest_product_of_three;
    
}

int main() {
    int n;
    cin >> n;
    vector<long long int> vec(n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        vec[i] = x;
    }
//    if (n < 3)
//        cout << "Error";
//    else
    cout << highest_product_of_3(vec, n) << endl;
    return 0;
}