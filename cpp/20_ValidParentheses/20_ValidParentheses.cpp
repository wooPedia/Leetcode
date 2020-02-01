/*
<<<<<<< HEAD
=======
    [Easy] 20.Valid Parentheses
    -----------------------------------------------------------------------------------------------------------------------
>>>>>>> 64ec1a41a743be28bc2427fb6ad41dbf467b00f6
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.
    
    Note that an empty string is also considered valid.

    Example 1:
    Input: "()"
    Output: true
    
    Example 2:
    Input: "()[]{}"
    Output: true
    
    Example 3:
    Input: "(]"
    Output: false
    
    Example 4:
    Input: "([)]"
    Output: false
    
    Example 5:
    Input: "{[]}"
    Output: true
<<<<<<< HEAD
=======
    -----------------------------------------------------------------------------------------------------------------------
    
    - Detail
    https://woo-dev.tistory.com/73
>>>>>>> 64ec1a41a743be28bc2427fb6ad41dbf467b00f6
*/

#include <string>
#include <stack>

using namespace std;

class Solution 
{
public:
<<<<<<< HEAD
    bool isValid(string s) {
        /*
            스택을 이용하여 문자열의 크기만큼 루프를 돕니다.
            루프를 돌면서 각 문자를 스택에 push합니다.
        */
=======
    bool isValid(string s) 
    {
>>>>>>> 64ec1a41a743be28bc2427fb6ad41dbf467b00f6

        size_t sSize = s.size();
        if (sSize == 0)
            return true;
        if ((sSize & 1) == 1)
            return false;

        stack<char> stk;
        for (size_t i = 0; i != sSize; ++i)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stk.emplace(s[i]);
                continue;
            }
            else if (s[i] == ')')
            {
                if (stk.empty() || stk.top() != '(')
                    return false;

                stk.pop();
                continue;
            }
            else if (s[i] == '}')
            {
                if (stk.empty() || stk.top() != '{')
                    return false;

                stk.pop();
                continue;
            }
            else if (s[i] == ']')
            {
                if (stk.empty() || stk.top() != '[')
                    return false;

                stk.pop();
                continue;
            }
        }

        return stk.empty();
    }
};
