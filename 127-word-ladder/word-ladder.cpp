class Solution {
public:
    vector<string> getValidWordsAtDistance1(unordered_set<string>&s, string word){
        unordered_set<string>wordSet;

        for(int i=0;i<word.length();i++){
            for(int j=0;j<26;j++){
                string firstHalf = word.substr(0,i);
                // cout<<"First Half "<<firstHalf<<endl;
                char replacedChar = char('a'+j);
                // cout<<"Replace Char "<<replacedChar<<endl;
                string secondHalf = word.substr(i+1, word.length()-i-1);
                // cout<<"Second Half "<<secondHalf<<endl;
                // cout<<"-----------\n";
                string newWord = firstHalf+replacedChar+secondHalf;
                if(s.find(newWord)!=s.end())    
                    wordSet.insert(newWord);
            }
        }
        vector<string>ans(wordSet.begin(), wordSet.end());
        return ans;
    }

    void print(vector<string>&nums){
        cout<<"Valid Words are : ";
        for(string s : nums)
            cout<<s<<" ";
        cout<<endl;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;
        unordered_set<string>visited;
        for(string word : wordList)
            s.insert(word);

        queue<string>q;
        q.push(beginWord);
        visited.insert(beginWord);
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            level++;
            for(int i=0;i<size;i++){
                string word = q.front();
                q.pop();
                vector<string> validWords = getValidWordsAtDistance1(s, word);
                print(validWords);
                for(string newWord : validWords){
                    if(newWord==endWord)
                        return level+1;
                    else if(visited.find(newWord)==visited.end()){
                        q.push(newWord);
                        visited.insert(newWord);
                    }
                }
            }

        }
        return 0;
    }
};