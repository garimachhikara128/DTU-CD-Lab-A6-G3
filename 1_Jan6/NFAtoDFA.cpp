#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>

using namespace std ;

string unionStates(string str, int alphabet, unordered_map<string, vector<string> > map)
{
    string ans = "" ;

    for(int i = 0 ; i < str.length() ; i++)
    {
        string ch ;
        ch += str[i]  ;
        ans += map[ch][alphabet] ;
    }

    return ans ;
}

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
            cout <<  sa[s] << "\t" << a << " ?" << endl ;
            string transition ;
            cin >> transition ;

            if(transition == "X")
                transition = "" ;

            map[sa[s]].push_back(transition) ;
        }
    }

    int max = (int)(pow(2,states) + 0.5) ;
    unordered_map<string,vector<string> > nfa ;

    string is, fs ;
    cout << "Enter initial and final states ?" << endl ;
    cin >> is >> fs ;

    queue<string> q ;
    unordered_set<string> visited ;

    q.push(is) ;

    while(!q.empty())
    {
        string present = q.front() ;
        q.pop() ;

        if(visited.count(present))
            continue ;
        
        visited.insert(present) ;

        for (int a = 0; a < alphabets; a++)
        {
            string ans = unionStates(present, a, map) ;
            nfa[present].push_back(ans) ;
            q.push(ans) ;
        }     
    }

    cout << "FINAL ANSWER" << endl ;
    
    unordered_map<string,vector<string> >::iterator i = nfa.begin();

    for( ;i!=nfa.end() ;i++)
    {

        cout << i->first << "\t\t" ;

        for (int a = 0; a < alphabets; a++)
        {   
            cout << i->second[a] << "\t";
        }

        cout << endl ;

    }
    







    return 0 ;
}


