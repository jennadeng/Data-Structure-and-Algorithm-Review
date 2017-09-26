import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static long countInversions(int[] arr) {
        return mergeSort(arr, new int[arr.length], 0, arr.length - 1);
    }

    public static long mergeSort(int[] arr, int[] tempArr, int start, int end){
        if(start >= end){
            return 0;
        }

        int middle = (start + end) /2;

        long count = 0;
        count += mergeSort(arr, tempArr, start, middle);
        count += mergeSort(arr, tempArr, middle + 1, end);
        count += merge(arr, tempArr, start, end);

        return count;
    }

    public static long merge(int[] arr, int[] tempArr, int start, int end){

        int middle = (start + end)/2;
        int lowerIndex = start;
        int upperIndex = middle + 1;

        int index = start;

        long count = 0;

        while(lowerIndex <= middle && upperIndex <= end ){
            if(arr[lowerIndex] <= arr[upperIndex]){
                tempArr[index] = arr[lowerIndex];
                lowerIndex++;
            }else {
                tempArr[index] = arr[upperIndex];
                upperIndex++;

                // All upper elements have to be inverted
                count += middle + 1 - lowerIndex;
            }

            index++;
        }

        // Copy remaining elemenets
        System.arraycopy(arr, lowerIndex, tempArr, index,  middle - lowerIndex + 1);
        System.arraycopy(arr, upperIndex, tempArr, index,  end - upperIndex + 1);
        System.arraycopy(tempArr, start, arr, start, end - start + 1);

        return count;
    }


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int[] arr = new int[n];
            for(int arr_i = 0; arr_i < n; arr_i++){
                arr[arr_i] = in.nextInt();
            }
            long result = countInversions(arr);
            System.out.println(result);
        }
        in.close();
    }
}
