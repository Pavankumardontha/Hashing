class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1>n2)
        return false;
        else
        {
            unordered_map<char,int> m1;
            unordered_map<char,int> m2;
            for(int i=0;i<n1;i++)
            {
                m1[s1[i]]++;
                m2[s2[i]]++;
            }
            if(m1==m2)
            return true;
            for(int i=n1;i<n2;i++)
            {
                //remove i-n1 character from the map m2
                m2[s2[i-n1]]--;
                //if its count becomes zero , erase the key
                if(m2[s2[i-n1]]==0)
                m2.erase(s2[i-n1]);

                // insert the current character
                m2[s2[i]]++;

                //compare the maps
                if(m1==m2)
                return true;
            }
            return false;
        }
    }
};
