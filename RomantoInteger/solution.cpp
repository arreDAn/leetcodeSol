#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
/*
  -Create an unordered map, assigning values to each roman numeral
  -edge case:
    bigger numbers are always to the left->therefore if a smaller number comes first is edge case
  - for each character in string add values, if edge case calculate valued and add
  -returnt sum
 */
int romanToInt(string s) {
        int ans = 0;// ans will contain the total value of the roman number
        // The following unordered map contains the integer values of each
        // of the roman characters
        std::unordered_map<char,int>romanNUmerals;
        romanNUmerals['I']=1;
        romanNUmerals['V']=5;
        romanNUmerals['X']=10;
        romanNUmerals['L']=50;
        romanNUmerals['C']=100;
        romanNUmerals['D']=500;
        romanNUmerals['M']=1000;
        int val =0;//val contains the value of each individual roman number

        //The loop will go through each number in the string containing the roman numbers
        for(int i=0; i<s.size();i++)
        {
            //The following check for out of bounds, and edge case
            if(i+1<=s.size() && romanNUmerals[s[i]]<romanNUmerals[s[i+1]])
            {
                //if edge case, the following assing the correct value to val
                if(romanNUmerals[s[i+1]] == 1000)
                    val = 900;
                else if(romanNUmerals[s[i+1]]== 500)
                    val = 400;
                else if(romanNUmerals[s[i+1]]== 100)
                    val = 90;
                else if(romanNUmerals[s[i+1]]== 50)
                    val = 40;
                else if(romanNUmerals[s[i+1]]== 10)
                    val = 9;
                else if(romanNUmerals[s[i+1]]== 5)
                    val = 4;
                ans += val;
                cout<<val<<endl;
                //we incremented here, because we took in consideration 2 numbers insted of 1
                // this is because of an edge case
                i++;


            }
            else
                //if not edge case we just add the value to ans
                ans += romanNUmerals[s[i]];

        }

        return ans;

    }
//The following can be use to test our code
int main() {
    cout << "Hello, World!" <<endl;
    cout<<"this is the answer: "<<romanToInt("MCMXCIV");
    return 0;
}
