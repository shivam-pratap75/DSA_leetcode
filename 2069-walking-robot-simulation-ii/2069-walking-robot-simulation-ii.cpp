class Robot {
public:
    int w;
    int h;
    bool east=true, west=false, north=false, south=false;
    int x=0, y=0;

    Robot(int width, int height) {
        w = width - 1;
        h = height - 1;
    }
    
    void step(int num) {

        int perimeter = 2 * (w + h);
        num %= perimeter;  

        int count = num;
      
        while(count > 0){

            if(east){
                int move = min(count, w - x);
                x += move;
                count -= move;

                if(count > 0){
                    east = false;
                    north = true;
                }

            }else if(north){
                int move = min(count, h - y);
                y += move;
                count -= move;

                if(count > 0){
                    north = false;
                    west = true;
                }

            }else if(west){
                int move = min(count, x);
                x -= move;
                count -= move;

                if(count > 0){
                    west = false;
                    south = true;
                }

            }else{ 
                int move = min(count, y);
                y -= move;
                count -= move;

                if(count > 0){
                    south = false;
                    east = true;
                }
            }
        }

       if(num == 0 && x == 0 && y == 0){
    east = false;
    south = true;
    west = false;
    north = false;
}

       
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if(east) return "East";
        if(west) return "West";
        if(north) return "North";
        return "South";
    }
};