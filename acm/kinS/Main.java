import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(new InputStreamReader(System.in));
        int testCases = in.nextInt();
        for (int i = 0; i < testCases; i++) {
            HashSet<location> waterSquares = new HashSet<>();

            int row = in.nextInt();
            int column = in.nextInt();
            int M = in.nextInt();
            int N = in.nextInt();

            int numberWaterSquares = in.nextInt();
            while (numberWaterSquares > 0) {
                int x = in.nextInt();
                int y = in.nextInt();
                waterSquares.add(new location(x,y));
                numberWaterSquares--;
            }
            HashSet<location> even = new HashSet<>();
            HashSet<location> odd = new HashSet<>();
            LinkedList<location> queue = new LinkedList<>();
            queue.push(new location(0, 0));

            while (!queue.isEmpty()) {
                location current = queue.pop();
                HashSet<location> Access = accessableSquares(N, M, column, row, current, waterSquares);
                for (location n : Access) {
                    if (!even.contains(n) && !odd.contains(n) && !queue.contains(n)) {
                        queue.add(n);
                    }
                }
                System.out.printf("current: %s\n access: %s\n", current.toString(), Access.toString());
                //System.out.printf( "ODD:" + odd.toString() + "EVEN: " + even.toString());
                if (Access.size() % 2 == 0) even.add(current);
                else odd.add(current);


            }

            System.out.printf("Case %d: %d %d\n", i+1,even.size(), odd.size() );
        }
    }


    public static HashSet<location> accessableSquares(int N, int M, int sx, int sy, location point, HashSet<location> water){
        HashSet<location> locations = new HashSet<>();

        location
        tmp = new location(point.x + N,point.y + M);
        if (tmp.isValid(sx,sy,water)){
            locations.add(tmp);
        }
        tmp = new location(point.x + N,point.y - M);
        if (tmp.isValid(sx,sy,water)){
            locations.add(tmp);
        }
        tmp = new location(point.x - N,point.y + M);
        if (tmp.isValid(sx,sy,water)){
            locations.add(tmp);
        }
        tmp = new location(point.x - N,point.y - M);
        if (tmp.isValid(sx,sy,water)){
            locations.add(tmp);
        }
        tmp = new location(point.x + M,point.y + N);
        if (tmp.isValid(sx,sy,water)){
            locations.add(tmp);
        }
        tmp = new location(point.x + M,point.y - N);
        if (tmp.isValid(sx,sy,water)){
            locations.add(tmp);
        }
        tmp = new location(point.x - M,point.y + N);
        if (tmp.isValid(sx,sy,water)){
            locations.add(tmp);
        }
        tmp = new location(point.x - M,point.y - N);
        if (tmp.isValid(sx,sy,water)){
            locations.add(tmp);
        }
        return locations;
    }

}


class location extends Object {
    int x ,y;

    @Override
     public boolean equals (Object other){
         return this.x == ((location)other).x && this.y == ((location)other).y;
     }
    location(int x, int y){
        this.x = x;
        this.y = y;
    }
    boolean isValid(int sx, int sy, HashSet<location> water){

        if (this.x >= sx | this.y >= sy | this.x < 0 | this.y < 0 ){
            return false;
        }
        if (water.contains(this)){
            return false;
        }
        else return true;
    }

    @Override
    public String toString() {
        return ("( " + x + " ," + y + " )");
    }
}
