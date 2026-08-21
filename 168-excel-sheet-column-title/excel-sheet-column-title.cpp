class Solution {
public:
    string convertToTitle(int columnNumber) {
       string result;
      int n=columnNumber;
      while (n>0){
        int digit=(n-1)%26;
        char c = 'A' + digit;
        result= c + result;
        n=(n-1)/26;
      }
      return result;
    }
};