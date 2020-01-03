static const double deg90InRad = -3.14159265358979324 / 2;
 
int main(int argc, char *argv[]) {
    double startX = 10.0, startY = 10.0;
    double endX = 15.0, endY = 15.0;
    double x, y;
 
    // This code rotates the line by 90 degrees clockwise about the point start
    // We want (x,y) to be the location of the end endpoint, and start to be moved to the origin
    // First, set (x,y) to the end
    x = endX;
    y = endY;
 
    // Now translate by (-startX, -startY)
    x -= startX;
    y -= startY;
 
    // Next perform the rotation (you seem to have not copied the formulae correctly, I got this from the Wikipedia page, more or less)
    endX = (x * cos(deg90InRad)) - (y * sin(deg90InRad));
    endY = (x * sin(deg90InRad)) + (y * cos(deg90InRad));
   
    // Now translate back, by (startX, startY)
    endX += startX;
    endY += startY;    
 
    printf("New line is from (%f,%f) to (%f,%f)\n", startX, startY, endX, endY);
 
    return 0;
}
