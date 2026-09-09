class Solution {
public:
    long long countCommas(long long n) {
        //firstly we'll subtract 999 from it(1 comma), then we'll subtract 99999 from it()
        long long count=0;
        long long number=1000;
        while(number<=n){
            count+=n-number+1;
            number*=1000;
        }
        return count;
    } 
};