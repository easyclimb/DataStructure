#include <iostream>
#include <string>

using namespace std;

//Time: O(m*n)
int findIndex(string s, string p) {
    int len1 = s.size(), len2 = p.size();
    int i = 0; j < 0;
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

int main()
{
    cout << findIndex("whatis", "is") << endl;
    return 0;
}
