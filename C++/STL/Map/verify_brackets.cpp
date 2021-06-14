// STL to verify brackets or parentheses in a string 

/*Algo:
 * 1) Create empty stack of characters
 * 2) Traverse character in string one by one
 * 	If any open bracket is encountered, then push that in stack
 * 	If any close bracket is encountered, then push then match it's open bracket counterpart with top of stack
 * 		If match is successful then pop character from stack
 * 		If match is unsussful the return false
 * 3) If stack is empty return true
 * 4) If stack is not empty then return false
 * */


#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <iterator>

using namespace std;

bool isOpenBracket(char val, map<char, char> mapOfBrackets)
{
	map<char, char>::iterator it = mapOfBrackets.begin();

	while(it != mapOfBrackets.end())
	{
		if(it -> second == val)
		{
			return true;
		}
		it++;
	}
	return false;
}

bool testBracket(string s)
{
	stack<char> bracketStack;
	map<char, char> bracketMap;

	bracketMap['}'] = '{';
	bracketMap[')'] = '(';
	bracketMap[']'] = '[';

	for(int i = 0; i < s.size(); i++) 
	{
		if(isOpenBracket(s[i], bracketMap))
			bracketStack.push(s[i]);

		if(bracketMap.find(s[i]) != bracketMap.end()) // close bracket
		{
			if(bracketStack.empty())
				return false;
			if(bracketStack.top() != bracketMap[s[i]])
			{
				return false;
			}
			else
				bracketStack.pop();
		}
	}

	if(bracketStack.size() > 0)
	{
		return false;
	}
	else
	{
		return true;
	}

}

int main()
{
	cout<<testBracket("([(2+11)]+)")<<endl;
	return 0;
}

/*Output:
 * 1
 * */
