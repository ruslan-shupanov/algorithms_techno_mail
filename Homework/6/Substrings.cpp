#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include<stdio.h>
#include<string.h>

using namespace std;


#define d 256



int search(string &pat, string &txt, int q)
{
    int k=0;
    int M = pat.size();
    int N = txt.size();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;


    for (i = 0; i < M-1; i++)
        h = (h*d)%q;


    for (i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }

    for (i = 0; i <= N - M; i++)
    {

        if ( p == t )
        {

            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }


            if (j == M)
                k++;
        }


        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;


            if (t < 0)
                t = (t + q);
        }
    }
    return k;
}

int main() {
    int max = 0;
    string text;
    string pattern;
    int q = 101;
    cin >> text;
    for (int i = 0; i < text.size(); i++) {
        pattern = text.substr(i);
        if (search(pattern, text, q) * pattern.size() > max)
            max = search(pattern, text, q) * pattern.size();

    }
    //char txt[] = "aabaabaabaabaa";
    //char pat[] = "aabaabaa";
    cout << max << endl;
    return 0;
}