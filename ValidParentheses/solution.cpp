#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
 key points
 -every open parentheses needs a close parentheses
 -A close parentheses should never come before an open parentheses
 - edge cases: last parentheses on string is a close parentheses, the string
 size should be bigger than 1, number of characters must be even.
 */
//Funtion;
//Input: given a string s || Output: return a bool
// -true is valid, false otherwise.
bool isValid(string s) {
    bool ans = false;
    stack<char>Op;//open stack


    if(s.size()<=1)//num of charaters must be greater than 1
        return ans;//return false otherwise

    if(s.size()%2!=0)//num of characters must be even
        return ans;//return false otherwise
    //the last character must be close parentheses
    if(s[s.size()-1]=='[' || s[s.size()-1]=='{' || s[s.size()-1]=='(')
        return ans;//return false otherwise

    if(s[0]=='(' || s[0]=='{' || s[0]=='[')//The first charater must be open parentheses
    {
        Op.push(s[0]);
    }
    else
        return ans;//return false otherwise

    for(int i=1; i<s.size();i++)//
    {

        if(s[i]=='(' || s[i]=='[' || s[i]=='{')//all open parentheses are added to the open stack
            Op.push(s[i]);
        //we check if condition are meet when close parentheses is given
        else{
            if(s[i]==')') {
                if (!Op.empty() && Op.top()=='(')//good condition
                    Op.pop();
                else//else there is not good maching. Return false
                    return ans;
            }
            else if(s[i]==']'){
                if (!Op.empty()  && Op.top()=='[')
                    Op.pop();
                else
                    return ans;
            }
            else if(s[i]=='}' ){
                if (!Op.empty() && Op.top()=='{')
                    Op.pop();
                else
                    return ans;
            }
            else
                return ans;
        }
    }
    if(Op.empty())//If we went over the whole string and stack is empty. Conditions were meet we return true.
        return true;
    return ans;//else we return false




    }
    //the fallowing is for testin puposes.
int main() {
    std::cout << "Hello, World!" << std::endl;
    cout<<"(){}}{ "<<"is "<< isValid("(){}}{")<<endl;
    cout<<"())) "<<"is "<< isValid("()))")<<endl;
    cout<<"()[]{} "<<"is "<< isValid("()[]{}");
    return 0;
}
