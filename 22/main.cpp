/** sort p022_names.txt in alphabetical order
 * then for each name:
 * 1. get alphabetical position
 * 2. get alphabetiacal value 
 * 3. calculate score
 * then calculate sum of all names' scores
 * */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

/** prints_vec
 * @ex print_vec(vec, cout, "\n");
 * */
#define print_vec(v,file,sep) \
    copy(v.begin(), v.end(), ostream_iterator<string>(file, sep)); \
    cout << endl

vector<string> split(const string &s);
int name_value(const string& );
int multiply_by_n(int);

bool test_split_fnc();
bool test_name_value_fnc();
bool test_multiply_by_n();

int main(int argc, char* argv[])
{
    cout << "22" << endl;

    ifstream infile("p022_names.txt");
    ofstream outfile("alphabetical_order.txt");

    // return !(test_split_fnc() == true);
    // return !(test_name_value_fnc() == true);
    // return !(test_multiply_by_n() == true);

    vector<string> names;

    string s;
    while (getline(infile, s))
    {
        vector<string> n = split(s);
        copy(n.begin(), n.end(), back_inserter(names));
    }

    sort(names.begin(), names.end());


    vector<int> values;
    transform(names.begin(), names.end(), back_inserter(values), name_value);


    vector<int> scores;
    transform(values.begin(), values.end(), back_inserter(scores), multiply_by_n);
        
    unsigned long int ans = accumulate(scores.begin(), scores.end(), 0);
    
    cout << ans << endl;
    return 0;
}

bool alpha(char c) { return isalpha(c); }

bool not_alpha(char c) { return !isalpha(c); }

vector<string> split(const string &s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter i = s.begin();

    while (i != s.end())
    {
        i = find_if(i, s.end(), alpha);
        iter j = find_if(i, s.end(), not_alpha);
        if (j != s.end())
            ret.push_back(string(i,j));
        i = j;
    }
    return ret;
}


// returns true if test passed
bool test_split_fnc()
{
    string s = "\"NameA\",\"NameB\",\"NameC\"";
    vector<string> ans = {"NameA","NameB","NameC"};
    vector<string> res = split(s);

    return ans == res;
}


int name_value(const string& s)
{
    return accumulate(s.begin(), s.end(), 0) - 64*s.length();
}

bool test_name_value_fnc()
{
    string s = "COLIN";
    int ans = 53;
    return name_value(s) == ans;
}

int multiply_by_n(int v)
{
    static int n = 0;
    return ++n*v;
}

bool test_multiply_by_n()
{
    int a = multiply_by_n(1);
    int b = multiply_by_n(2);

    return (a == 1) && (b == 4);
}