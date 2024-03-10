// This is my approach after reading kshatriyas's explaination on solving this problem.
// This solution uses a set structure instead of a vector.

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int max_streak = 0;
        unordered_set<char> s_chars;
        int beginning = 0;
        
        for ( int end = 0; end < s.length(); end++)
        {
            // check if the char appears in the set
            if (s_chars.count( s[end] ) == 0 )  //does not appear
            {
                s_chars.insert( s[end] );       //add it to the set
                if ( max_streak < (end - beginning + 1) )   //update max_streak
                    max_streak = (end - beginning + 1);
            }
            else    //did appear in the set
            {
                while ( s_chars.count( s[end] ) ) // delete from the beginning of the set until the char no longer appears in it
                {
                    s_chars.erase( s[beginning] );
                    beginning++;
                }
                s_chars.insert( s[end] ); //add the current char to the newly shortened set
            }
        }
        return max_streak;
    } // lengthOfLongestString()
};
