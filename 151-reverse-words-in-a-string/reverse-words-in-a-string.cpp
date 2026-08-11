class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        vector<string> words;
        while (iss >> word) {  
        words.push_back(word);
    }
    int a=0, b=words.size()-1;
    while (a<b){
        swap(words[a++], words[b--]);
    }
    string result = "";
    for (int i = 0; i < words.size(); i++) {
    if (i > 0) result += " "; 
    result += words[i];
    }
    return result;       
    }
};