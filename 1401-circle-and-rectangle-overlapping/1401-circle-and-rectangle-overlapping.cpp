class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xDistance;
        int yDistance;

        // For X-Axis
        if(x1<=xCenter && xCenter<=x2){
            xDistance = 0;
        }
        else if(xCenter < x1){
            xDistance = x1 - xCenter;
        }
        else{
            xDistance = xCenter - x2;
        }

        // For Y-Axis
        if(y1<=yCenter && yCenter<=y2){
            yDistance = 0;
        }
        else if(yCenter < y1){
            yDistance = y1 - yCenter;
        }
        else{
            yDistance = yCenter - y2;
        }


        int actualDist = sqrt((xDistance * xDistance) + (yDistance * yDistance));

        return radius>=actualDist;
    }
};