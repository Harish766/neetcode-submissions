class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_map<string,int> map;
        for(int i=0;i<wordList.size();i++){
            map[wordList[i]]++;
        }
        if(beginWord == endWord){
            return 1;
        }
        q.push({beginWord,1});
        while(!q.empty()){
            auto [word,second]=q.front();
            q.pop();
            if(word==endWord){
                return second;
            }
            for(int i=0;i<beginWord.size();i++){
                char original = word[i];
    
                for(int j=0;j<26;j++){
                    word[i]='a'+j;
                    if(map[word]==1){
                        q.push({word,second+1});
                        map[word]=0;
                    }
                    word[i]=original;
                }
            }
        }
        return 0;
    }
};
