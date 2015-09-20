#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Solution : two pointers
//Time: O(m*n)
int findIndex(string s, string p) {
    int len1 = s.size(), len2 = p.size();
    int i = 0, j = 0;
    while(i < len1 && j < len2) {
        if(s[i] == p[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == len2) return i - j;
    return -1;
}


//Solution 2 : KMP
void get_next(string& p, vector<int>& next) {
    int n = next.size(), j = 0, k = -1;
    next[0] = -1;
    while(j < n - 1) {
        if(k == -1 || p[j] == p[k])
            next[j++] = k++;
        else
            k = next[k];
    }
}

int findIndex2(string s, string p) {
    int i = 0, j = 0;
    int len1 = s.size(), len2 = p.size();
    vector<int> next(len2);
    get_next(p, next);
    while(i < len1 && j < len2) {
        if(j == -1 || s[i] == p[j]) {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if(j == len2) return i - j;
    return -1;
}

int main()
{
    cout << findIndex2("whatis", "is") << endl;
    return 0;
}
