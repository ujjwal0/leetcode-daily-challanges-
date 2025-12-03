class Solution{
public:
    //the calc function is the same problem as trapazoid 1 with a small twist
    long long calc(unordered_map<int,unordered_map<int,unordered_map<int,int>>>&mp){
        long long ans=0;

        for(auto&[x,m1]:mp){
            for(auto&[y,m2]:m1){
                long long sum=0;
                for(auto&[key,val]:m2){
                    sum+=val;
                }

                for(auto&[key,val]:m2){
                    sum-=val;
                    ans+=val*sum;
                }
            }
        }

        //since we are trying to calculate the following expression as :
        //a0(a1+a2+...an) + a1(a2+a3+..an) + .... + an*(0)
        return ans;
    }

    int countTrapezoids(vector<vector<int>>&points){
        unordered_map<int,unordered_map<int,unordered_map<int,int>>>a,b;
        //{sx,{sy,val}} format
        //a will store the count of valid trapazoids
        //b will store the count of pallelograms

        //so, esentially we are storing vectors here 
        //specifically the direction vectors
        //with the {sx,sy} part and the "val" just talks about 
        //which plane it lies in OR the intercept 

        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dx=points[i][0]-points[j][0];
                int dy=points[i][1]-points[j][1];

                //to bring the gradients in a fixed format : 
                //if slope is negative, then dy should be -ve only
                if(dx<0||(dx==0 && dy<0)){
                    dx=-dx;
                    dy=-dy;
                }

                int g=gcd(dx,dy);

                int sx=dx/g;
                int sy=dy/g;
                //bring the gradiants in simplest forms

                int val=sx*points[i][1]-sy*points[i][0];

                a[sx][sy][val]++;
                b[dx][dy][val]++;
                //The logic being the pair {dx,dy} will 
                //also hold the information of the distance 
                //between the points. Since, the pair {sx,sy} 
                //does not account for that because of the gcd.
            }
        }

        //final answer will be total possible answers 
        //- overcounted parallelograms
        //also notice that when we calculate the parallelograms
        //we will again overcount it twice so we divide by 2
        return calc(a)-calc(b)/2;
    }
};