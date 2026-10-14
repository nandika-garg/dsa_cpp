class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int score=0;
        if(sum>num*9) return "";
        string result="";
        
        while(sum>=9){
            sum-=9;
            result+='9';
        }
        if(result.size()!=num && sum!=0){
            result+= char('0' + sum);
            sum=0;
        }
        while(result.size()!=num){
            result+='0';
        }
        return result;
        
    }
};