#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    
    stack <int> stk1;
    stack <int> stk2;
    stack <int> stk3;
    
    int height1=0,height2=0,height3=0;
    
    for(int i=h1.size()-1; i>=0; i--)
    {
        height1= height1+h1[i];
        stk1.push(height1);
    }
      for(int i=h2.size()-1; i>=0; i--)
    {
        height2= height2+h2[i];
        stk2.push(height2);
    }
      for(int i=h3.size()-1; i>=0; i--)
    {
        height3= height3+h3[i];
        stk3.push(height3);
    }
       
        
    while(true)
    {
        if(stk1.empty() || stk2.empty() || stk3.empty())
            return 0;
        
        height1= stk1.top();
        height2= stk2.top();
        height3= stk3.top();
        
         if(height1==height2 && height2==height3)
            return height1;
           
        if(height1>=height2 && height1>=height3)
            stk1.pop();
         else if(height2>=height1 && height2>=height3)
            stk2.pop();
         else if(height3>=height1 && height3>=height2)
            stk3.pop();  
    }
  
}

int main()
{
    string n;
    getline(cin, n);

    vector<string> first_multiple_input = split(rtrim(n));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);
//h1
    string first;
    getline(cin, first);

    vector<string> h1_temp = split(rtrim(first));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }
//h2
    string second;
    getline(cin, second);

    vector<string> h2_temp = split(rtrim(second));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }
//h3
    string third;
    getline(cin, third);

    vector<string> h3_temp = split(rtrim(third));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    cout << result << "\n";

}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
