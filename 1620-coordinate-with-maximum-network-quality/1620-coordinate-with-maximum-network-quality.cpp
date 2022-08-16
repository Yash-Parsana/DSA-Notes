class Solution {
public:
    int quality(int &q,int &d)
    {
        return  (q/(1+sqrt(d)));
    }
    int dist(int &x1,int &y1,int &x2,int &y2)
    {
        int d=(pow((x1-x2),2)+pow((y1-y2),2));
        // cout<<" d(fun)"<<" x1: "<<x1<<" x2: "<<x2<<" y1: "<<y1<<" y2: "<<y2<<" "<<d<<" ";
        return d;
    }
    vector<int> bestCoordinate(vector<vector<int>>& t, int r) {
        int n=t.size();
        
        int mxi=0,mxj=0;
        for(auto i:t)
        {
            mxi=max(mxi,i[0]);
            mxj=max(mxj,i[1]);
        }
        // vector<vector<int>> v(mxi+1,vector<int>(mxj+1,INT_MAX));
         int ii=INT_MAX,jj=INT_MAX;
        int q=0;       
        for(int i=0;i<=mxi+1;i++)
        {
            for(int j=0;j<=mxj;j++)
            {
                int temp=0;
                for(int k=0;k<n;k++)
                {
                    int d=dist(i,j,t[k][0],t[k][1]);
                    
                    if(d<=r*r)
                    {
                        temp+=quality(t[k][2],d);    
                    }
                    // cout<<"tower : "<<k<<" point: "<<i<<" "<<j<<" dist: "<<d<<" q: "<<quality(t[k][2],d)<<endl;
                }
                // cout<<temp<<" "<<i<<" "<<j<<endl;
                if(temp>q)
                {
                    q=temp;
                    ii=i;
                    jj=j;
                }
                
            }
        }
        

        
        // for(int i=0;i<=mxi;i++)
        // {
        //     int temp=0;
        //     for(int j=0;j<=mxj;j++)
        //     {
        //         if(v[i][j]<=r)
        //         {
        //             temp+=quality(t[j][2],v[i][j]);
        //         }
        //     }
        //     if(temp>q)
        //     {
        //         q=temp;
        //         ii=t[i][0];
        //         jj=t[i][1];
        //     }
        //     else if(temp==q)
        //     {
        //         if(t[i][0]<ii)
        //         {
        //             ii=t[i][0];
        //             jj=t[i][1];
        //         }
        //         else if(t[i][0]==ii&&t[i][1]<jj)
        //         {
        //             jj=t[i][1];
        //         }
        //     }
        // }
        // // cout<<q<<endl;
        if(q==0)return {0,0};
        return {ii,jj};
        
    }
};