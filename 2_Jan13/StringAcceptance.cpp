#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std ;

int main()
{

    int states , alphabets ;

    cout << "States ?" << endl ;
    cin >> states ;

    // take input for states
    string sa[states] ;
    for (int i = 0; i < states; i++)
    {
        cin >> sa[i] ;
    }
    
    cout << "Alphabets ?" << endl ;
    cin >> alphabets ;

    unordered_map<string, vector<string> > map ;

    for (int s = 0; s < states; s++)
    {
        for(int a = 0 ; a < alphabets ; a++)
        {
            cout <<  sa[s] << " " << a << " ? "  ;
            string transition ;
            cin >> transition ;
            map[sa[s]].push_back(transition) ;
        }
    }

    string is, fs, str ;
    cout << "Initial State ? " ;
    cin >> is ;
    cout << "Final State ? " ;
    cin >> fs ;
    cout << "Input the string ? " ;
    cin >> str ;

    string ps = is ;
    int idx = 0 ;

    while(idx < str.length())
    {
        char ch = str[idx] ;
        ps = map[ps][ch-'0'] ;
        idx ++ ;
    }

    if(ps == fs)
        cout << "String is accepted" << endl ;
    else
        cout << "String is not accepted" << endl;

    return 0 ;
}