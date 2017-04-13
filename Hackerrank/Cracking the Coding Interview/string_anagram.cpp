#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
    int a_store[26]={0},b_store[26]={0};
    int i,count=0;
    for(i=0;i<a.length();i++)
        a_store[a[i]-'a']+=1;
    for(i=0;i<b.length();i++)
        b_store[b[i]-'a']+=1;
    for(i=0;i<26;i++){
        count+=abs(a_store[i]-b_store[i]);
    }
    return count;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}

