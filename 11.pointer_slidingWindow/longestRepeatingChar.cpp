#include<iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int repeatingChar(string s, int k ){
    int maxlen = 0;

    for(int i = 0; i < s.size(); i++){
        vector<int> freq(26, 0);
        int maxfreq = 0;

        for(int j = i; j < s.size(); j++){
            freq[s[j] - 'A']++;
            maxfreq = max(maxfreq, freq[s[j] - 'A']);

            // cout << "max freq1" << maxfreq << " ";
            int windowLength = j-i+1;

            int replace = windowLength - maxfreq;
            if(replace <=k ){
                maxlen = max(maxlen, windowLength);
            }
            // cout << "max freq2" << maxfreq << " ";

        }
    }

    return maxlen;
}

int repeatingCharBetter(string s, int k){
    int left = 0, maxfreq = 0, maxlen = 0;

    unordered_map<char, int> freq;

    for(int right = 0; right < s.size(); right++){
        freq[s[right]]++;

        maxfreq = max(maxfreq, freq[s[right]]);

        while((right - left + 1) - maxfreq > k){
            freq[s[left]]--;
            left++;
        }

        maxlen = max(maxlen, right - left + 1);
    }
    return maxlen;
}

int repeatingCharOptimal(string s, int k ){
    int left = 0, right = 0, maxfreq = 0, maxlen = 0;

    unordered_map<char, int> freq;

    while(right < s.size()){
        freq[s[right]]++;
        maxfreq = max(freq[s[right]], maxfreq);

        while((right - left + 1) - maxfreq > k){
            freq[s[left]]--;
            left++;
        }
        maxlen = max(maxlen, right - left + 1);
        right++; 
    }

    return maxlen;
}

int main(){
    string s = "BAABAABBBAAA";
    int k = 2; 

    int result = repeatingCharOptimal(s, k);
    cout << "Result: " << result << endl;
}