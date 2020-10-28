// Эта задача не решена до конца
#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <cstdio>

using namespace std;


void my_merge(FILE* f1, int n1, FILE* f2, int n2, FILE* out, int n) {
    while ((n1 != 0) || (n2 != 0))
    {
        int j = 0, i = 0;
        char s1[100000], s2[100000];
        bool b1 = false, b2 = false;
        for (int k = 0; k < 2 * n; k++) {
            if ((n1 == 0) && (n2 == 0))
                    break;
            if (n1 == 0) i = n;
            if (n2 == 0) j = n;
            if (i > n - 1) {
                if (!b2){
                    fgets (s2, 100000, f2);
                    b2 = true;

                }
                fputs(s2, out);
                b2 = false;
                j++;
                n2--;
            }
            else if (j > n - 1) {
                if (!b1){
                    fgets (s1, 100000, f1);
                    b1 = true;

                }
                fputs(s1, out);
                b1 = false;
                i++;
                n1--;

            }
            else {
                if (!b1) {
                    fgets (s1, 100000, f1);
                    b1 = true;

                }
                if (!b2){
                    fgets (s2, 100000, f2);
                    b2 = true;

                }
                if ((string)s1 < (string)s2) {
                    fputs(s1, out);
                    b1 = false;
                    i++;
                    n1--;
                } else {
                    fputs(s2, out);
                    b2 = false;
                    j++;
                    n2--;
                }
            }

        }
    }
}

int main() {
    FILE *fin = fopen("input.txt", "r");

    int k = 1;
    int n = 0;
    FILE *fout = fopen("output.txt", "w");
    char str[100000];
    while(fgets (str, 100000, fin) != NULL) {
        fputs(str, fout);
        n++;
    }
    fclose(fout);
    fclose(fin);
    while (k < n)
    {
        FILE* fout2 = fopen("output.txt", "r");
        FILE* f1 = fopen("1.txt", "w+");
        FILE* f2 = fopen("2.txt", "w+");
        int n1 = 0, n2 = 0;
        while(! feof (fin)) {
            char s[100000];
            for (int j = 0; j < k; j++) {
                if (fgets (s, 100000, fout2) == NULL) break;
                fputs(s, f1);
                n1++;
                if (feof (fin))
                    break;
            }
            for (int j = 0; j < k; j++) {
                if (fgets (s, 100000, fout2) == NULL) break;
                fputs(s, f2);
                n2++;
                if (feof (fin))
                    break;
            }

        }

        fclose(fout2);

        FILE* out = fopen("output.txt", "w");
        fseek(f1, 0, 0);
        fseek(f2, 0, 0);

        my_merge(f1, n1, f2, n2, out, k);

        fclose(f1);
        fclose(f2);
        fclose(out);
        k *= 2;
    }
    return 0;
}