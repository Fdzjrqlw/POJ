#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <queue>
#include <cmath>
#include <stack>

using namespace std ;
const int maxL = 11000 ;

int test_case ;

string transform(char s[]){
    stack <char> gs ;
    while(!gs.empty())
        gs.pop() ;
    char res[maxL] ;
    int l = 0 ;
    memset(res , 0 , sizeof(res)) ;
    int len = strlen(s) ;

    for(int i = 0 ; i < len ; ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            res[l++] = s[i] ;
            continue ;
        }
        if(s[i] >= 'a' && s[i] <= 'z'){
            res[l++] = s[i] ;
            continue ;
        }
        if(s[i] == '('){
            gs.push('(') ;
            continue ;
        }
        if(s[i] == ')'){
            while(!gs.empty()){
                char op = gs.top() ; 
                gs.pop() ;
                if(op == '('){
                    break ;
                }
                res[l++] = op ;
            }
            continue ;
        }
        if(s[i] == '+' || s[i] == '-'){
            while(!gs.empty()){
                char op = gs.top() ;
                if(op == '+' || op == '-' || op == '*'){
                    gs.pop() ;
                    res[l++] = op ;
                } else break ;
            }
            gs.push(s[i]) ;
            continue ;
        }
        if(s[i] == '*'){
            while(!gs.empty()){
                char op = gs.top() ;
                if(op == '*'){
                    gs.pop() ;
                    res[l++] = op ;
                } else break ;
            }
            gs.push(s[i]) ;
            continue ;
        }
    }
    while(!gs.empty()){
        char op = gs.top() ;
        gs.pop() ;
        res[l++] = op ;
    }
    res[l] ='\0' ;
    string t = string(res) ;
    return t ;
}

int calculate(string s){
    stack <int> gs ;
    while(!gs.empty())
        gs.pop() ;
    for(int i = 0 ; i < s.size() ; ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            gs.push(s[i] - '0') ;
            continue ;
        }
        if(s[i] >= 'a' && s[i] <= 'z'){
            gs.push((int) s[i]) ;
            continue ;
        }
        if(s[i] == '+'){
            int y = gs.top() ; gs.pop() ;
            int x = gs.top() ; gs.pop() ;
            int z = x + y ;
            gs.push(z) ;
            continue ;
        }
        if(s[i] == '-'){
            int y = gs.top() ; gs.pop() ;
            int x = gs.top() ; gs.pop() ;
            int z = x - y ;
            gs.push(z) ;
            continue ;
        }
        if(s[i] == '*'){
            int y = gs.top() ; gs.pop() ;
            int x = gs.top() ; gs.pop() ;
            int z = x * y ;
            gs.push(z) ;
            continue ;
        }
    }
    int res = gs.top() ; gs.pop() ;
    return res ;
}

int main(){

    scanf("%d",&test_case) ;
    char c = getchar() ;
    while(test_case--){
        char s1[maxL] , s2[maxL] ;
        int r1 , r2 ;
        scanf("%[^\n]s",s1) ;
        char c = getchar() ;
        string t1 = "" , t2 = "" ;
        t1 = transform(s1) ;
        scanf("%[^\n]s",s2) ;
        c = getchar() ;
        t2 = transform(s2) ;
        //cout << t1 << endl ;
       // cout << t2 << endl ;
        r1 = calculate(t1) ;
        r2 = calculate(t2) ;
        if(r1 == r2){
            cout << "YES" << endl ;
        } else 
            cout << "NO" << endl ;

    }

    return 0 ;
}