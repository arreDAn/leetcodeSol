#include <iostream>
using namespace std;
#include <string>


/*
 key points:
 -Charcaters have to be unique in substring
 -Generate all substring with not repeted characters and keep the highest size.


 ##Edge cases##
 -if all letters are the same we return 1
 */

int lengthOfLongestSubstring(string s){
    string str ="";//this string will be use to store each substring,
                    // it should be cleared after each substring is generated
    int lonSub =0;//This will hold the largest size
    int count =0;//Holds current size

    for(int i=0; i<s.size();i++)//we will generate all substrings starting from index 0.
    {
        str =str+s[i];//we add firts character
        int j =i+1;//we define next index
        size_t f = str.find(s[j]);// We look for character in str
        while(f== std::string::npos && j<s.size()){// std::string::npos is a constant that in this case
                                                    // means the character is not in str.
            str = str + s[j];//we add character to str
            j++;
            f = str.find(s[j]);//we look for the next character str, for next iretaration.
        }
        count = str.size();//once substring is generated we get the size
        if(count>lonSub)// and if the size turns to be bigger than what we used to have, we set lonSub = count
            lonSub = count;
        str = "";
    }
    return lonSub;
}

//The following are test cases
int main() {
    std::cout << "Hello, World!" << std::endl;
    cout<<"The fallowing has a substring of: "<<lengthOfLongestSubstring("abcabcbb")<<endl;
    cout<<"The fallowing has a substring of: "<<lengthOfLongestSubstring("bbbbb")<<endl;
    cout<<"The fallowing has a substring of: "<<lengthOfLongestSubstring("pwwkew")<<endl;
    cout<<"The fallowing has a substring of: "<<lengthOfLongestSubstring("au")<<endl;
    return 0;
}
