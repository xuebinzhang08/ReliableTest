class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector <int> location = {0, 0};
        vector <int>direction = {0, 1};
        for(int i =0; i < instructions.length(); i++){
            switch(instructions[i]){
                case 'L':
                    direction = {-direction[1], direction[0]};
                    break;
                case 'R':
                    direction = {direction[1], -direction[0]};
                    break;
                default:
                    location[0]+= direction[0];
                    location[1]+= direction[1];
            }
        }
        return (location[0]==0 && location[1]==0 || direction[0]!=0 && direction[1]!=1)? true:false;
    }
};
