class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;
        int result;
        for (string c:tokens){
            if (c == "+" || c == "-" || c == "*" || c == "/"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                if (c == "+") result = a + b;
                else if (c == "-") result = b-a;
                else if (c == "*") result = a * b;
                else result = b/a;
                s.push (result);

            }
            else{
                int num= stoi(c);
                s.push(num);
            }
         

        }
        return s.top();
        
        
    }
};