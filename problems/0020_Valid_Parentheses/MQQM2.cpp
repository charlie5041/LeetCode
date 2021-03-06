/*
  题目：
  给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
  
  说明：
  有效字符串需满足：左括号必须用相同类型的右括号闭合。左括号必须以正确的顺序闭合。
  注意空字符串可被认为是有效字符串。
*/
class Solution {
public:       
    bool isValid(string s) {
        if(s.empty()){
            return true;
        }
        
        stack<char> stk;
        unordered_map<char,char> um;
        um.insert( make_pair('(',')') );
        um.insert( make_pair('[',']') );
        um.insert( make_pair('{','}') );
        
        for(int i=0; i<s.size(); i++){            
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stk.push(s[i]);
                continue;
            }
            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if( stk.empty() || um[stk.top()] != s[i] ){
                    return false;
                }else{
                    stk.pop();                    
                }               
            }            
        }
        if( stk.empty() ){
            return true;
        }
                        
        return false;
    }
};
