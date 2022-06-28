class Solution {
public:
    string predictPartyVictory(string senate) {
        int dc=0, rc=0, i=0;
        int bansc=0, bansS=senate[0];
        for(auto ch :senate)
        {
            if (ch=='D') dc++;
            else rc++;
        }
        while(dc != 0 && rc != 0)
        {
            if (bansc == 0 || senate[i] == bansS)
            {
			    bansS = senate[i];
                senate.push_back(bansS);
                bansc++;
            }
            else
            {
                if (bansS == 'D')
                    rc--;
                else
                    dc--;
                bansc--;
            }
            i++;
        }
        return dc>rc?"Dire":"Radiant";
    }
};