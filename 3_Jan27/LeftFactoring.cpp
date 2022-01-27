#include<iostream>
#include<unordered_map>
#include<vector>
#include<sstream>

using namespace std ;

string trim(string str)
{
    string ans = "" ;

    for(int i = 0 ; i < str.length() ; i++)
    {
        if(str[i] != ' ')
            ans += str[i] ;
    }

    return ans ;
}

int main()
{
    int n ;

    // take input
    cout << "Enter N ?" << endl ;
    cin >> n ;

    fflush(stdin) ;

    string productions[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        getline(cin, productions[i]) ;
    }    

    // store content in map
    unordered_map<string, vector<string> > map ;
    vector<string> vec ;

    for(int i = 0 ; i < n ; i++)
    {
        int idx = productions[i].find("->") ;
        string lhs = productions[i].substr(0,idx) ;
        string rhs = productions[i].substr(idx+2) ;

        // split your rhs on the basis of |
        stringstream data(rhs) ;
        string line ;

        while(getline(data, line, '|'))
        {
            string ts = trim(line) ;
            map[lhs].push_back(ts) ;
        }

        vec.push_back(lhs) ;
    }

    
    



    return 0 ;
}
