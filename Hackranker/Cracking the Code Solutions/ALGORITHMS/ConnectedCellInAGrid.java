import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static int getBiggestRegion(int[][] matrix) {
        int biggestRegion = 0;
        int currentbiggestRegion = 0;

        for(int y = 0; y < matrix.length; y++){
            for(int x = 0; x < matrix[y].length; x++){
                if(matrix[y][x] == 1){
                    currentbiggestRegion = DFS(matrix, y, x);

                    if( currentbiggestRegion > biggestRegion){
                        biggestRegion = currentbiggestRegion;
                    }
                }
            }
        }
        return biggestRegion;
    }

    public static int DFS(int[][] matrix, int y, int x ){
        int size = 1;

        matrix[y][x] = 0;

        for(int r = y-1; r < y+2; r++){
            for(int c = x-1; c < x+2; c++){
                if( r != y || c != x){
                    if(r > -1 && c > -1 && r < matrix.length && c < matrix[y].length){
                        if(matrix[r][c] == 1){
                             size += DFS(matrix, r, c);
                        }
                    }
                }
            }
        }

        return size;

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int grid[][] = new int[n][m];
        for(int grid_i=0; grid_i < n; grid_i++){
            for(int grid_j=0; grid_j < m; grid_j++){
                grid[grid_i][grid_j] = in.nextInt();
            }
        }
        System.out.println(getBiggestRegion(grid));
    }
}
