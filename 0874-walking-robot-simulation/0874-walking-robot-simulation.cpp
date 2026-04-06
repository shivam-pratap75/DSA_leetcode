class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int x=0,y=0;
        bool east=false,west=false,north=true,south=false;

        set<pair<int,int>> temp;
        int maxDist=0;

        for(int i=0;i<obstacles.size();i++){
            temp.insert({obstacles[i][0], obstacles[i][1]});
        }

        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                if(east){
                    east=false;
                    south=true;
                }else if(north){
                    north=false;
                    east=true;
                }else if(west){
                    west=false;
                    north=true;
                }else{
                   south=false;
                    west=true;
                }
            }
            else if(commands[i]==-2){
                if(east){
                    east=false;
                    north=true;
                }else if(north){
                    north=false;
                    west=true;
                }else if(west){
                    west=false;
                    south=true;
                }else{
                    south=false;
                    east=true;
                }
            }
            else{
                if(east){
                    int a=x,b=y;
                    for(int step=1;step<=commands[i];step++){
                        if(!temp.count({a+1,b})){
                            x++;
                            a++;
                        }else break;
                        maxDist = max(maxDist, x*x + y*y);
                    }
                }
                else if(west){
                    int a=x,b=y;
                    for(int step=1;step<=commands[i];step++){
                        if(!temp.count({a-1,b})){
                            x--;
                            a--;
                        }else break;
                        maxDist = max(maxDist, x*x + y*y);
                    }
                }
                else if(north){
                    int a=x,b=y;
                    for(int step=1;step<=commands[i];step++){
                        if(!temp.count({a,b+1})){
                            y++;
                            b++;
                        }else break;
                        maxDist = max(maxDist, x*x + y*y);
                    }
                }
                else{
                    int a=x,b=y;
                    for(int step=1;step<=commands[i];step++){
                        if(!temp.count({a,b-1})){
                            y--;
                            b--;
                        }else break;
                        maxDist = max(maxDist, x*x + y*y);
                    }
                }
            }

            
            maxDist = max(maxDist, x*x + y*y);
        }

        return maxDist;
    }
};