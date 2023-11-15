#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t){
    int sIndex = 0;
    int tIndex = 0;

    while (tIndex < t.length() && sIndex < s.length()){
        if (s[sIndex] == t[tIndex]){
            sIndex++;
        }
        tIndex++;
    }

    return sIndex == s.length();
}

int main(){
    // Test Case 1
    string s1 = "abc";
    string t1 = "ahngdc";

    bool result1 = isSubsequence(s1, t1);

    if (result1){
        cout << "Test Case 1: s1 is a subsequence of t1." << std::endl;
    }
    else{
        cout << "Test Case 1: s1 is not a subsequence of t1." << std::endl;
    }

    // Test Case 2
    string s2 = "xyz";
    string t2 = "xbyzl";

    bool result2 = isSubsequence(s2, t2);

    if (result2){
        cout << "Test Case 2: s2 is a subsequence of t2." << std::endl;
    }
    else{
        cout << "Test Case 2: s2 is not a subsequence of t2." << std::endl;
    }

    return 0;
}
