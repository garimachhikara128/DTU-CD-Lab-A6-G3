#include<iostream>
#include<vector>

using namespace std ;

bool isDelimiter(char ch)
{
    char arr[]= {' ', '(', ')', '[', ']', '{', '}', ',', ';', '<', '>', '=', '+', '-', '*', '/', '%'} ; 

    int length = sizeof(arr) / sizeof(char) ;

    for (int i = 0; i < length; i++)
    {
        if(ch == arr[i])
            return true ;
    }

    return false ;
}

bool isOperator(char ch)
{
    char arr[]= {'=', '+', '-', '*', '/', '%'} ; 

    int length = sizeof(arr) / sizeof(char) ;

    for (int i = 0; i < length; i++)
    {
        if(ch == arr[i])
            return true ;
    }

    return false ;
}

bool isConstant(string str)
{
    char arr[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'} ;

    int length = sizeof(arr) / sizeof(char) ;

    for (int i = 0; i < str.length(); i++)
    {
        char sc = str[i] ;
        bool flag = true ;

        if(!(sc == '1' || sc == '2' || sc == '3' || sc == '4' || sc == '5' || sc == '6' || sc == '7' || sc == '8' || sc == '9' || sc == '0'))
        {
            return false ;
        } 
    }

    return true ;
}

bool isKeyword(string str)
{
    string arr[] = {"if", "else", "while", "for", "do", "break", "continue", "int", "float", 
    "double", "long", "char", "sizeof", "switch", "unsigned", "signed", "void", 
    "static", "struct", "goto"} ;

    int length = 20 ;

    for (int i = 0; i < length; i++)
    {
        if(str == arr[i])
            return true ;
    }

    return false ;
}

bool isIdentifier(string str)
{
    char ch = str[0] ;

    char arr[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'} ;

    int length = sizeof(arr) / sizeof(char) ;

    for (int i = 0; i < length; i++)
    {
        if(ch == arr[i])
            return false ;
    }

    if(isDelimiter(ch))
        return false ;

    return true ;

}


int main()
{
    string str ;

    cout << "Enter string ? " ;
    getline(cin, str) ;

    // string str = "void main(){int a,b,c ; c = 101 + 50 * 20;}";

    string ps = "" ;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i] ;

        if(isDelimiter(ch))
        {
            if(ps.length() == 0)
            {}
            else if(isKeyword(ps))
                cout << ps << " is a keyword." << endl ;
            else if(isIdentifier(ps))
                cout << ps << " is an identifier." << endl ;
            else if(isConstant(ps))
                cout << ps << " is an constant." << endl ;
            else
                cout << ps << " is an invalid identifier." << endl ;

            if(isOperator(ch))
                cout << ch << " is an operator." << endl ;

            ps = "" ;
        }
        else
        {
            ps += ch ;
        }
       
    }

    return 0 ;
}


