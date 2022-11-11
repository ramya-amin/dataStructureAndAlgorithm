/*
A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

You are given an array of strings sentences, where each sentences[i] represents a single sentence.

Return the maximum number of words that appear in a single sentence.

 

Example 1:

Input: sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
Output: 6

*/

// O(n)
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords=0;
        
        for(int i=0;i<sentences.size();i++)
        {
            //string str=;
            int numberofWords=count(sentences[i].begin(),sentences[i].end(), ' ') + 1; //count number of spaces and then add one 
            maxWords = max(maxWords,numberofWords);

        }

       return maxWords;
    }
};
