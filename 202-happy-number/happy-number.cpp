class Solution {
public:
    bool isHappy(int n) {
        unordered_set <int> s;
        int sum=0;
    while(sum!=1){
        sum=0;

        while (n>0){
        int digit=n%10;
        sum+=digit*digit;
        n/=10;
        }
        if (s.count(sum)) return false; 
        else s.insert(sum);
        n=sum;
        
    }
    return true;

    
        
    }
};