import java.lang.reflect.Array;
import java.util.Arrays;

public class UsingArrays {
    private int intArray[] = {1,2,3,4,5,6};
    private double doubleArray[] = {8.4,9.3,0.2,7.9,3.4};
    private int filledIntArray[], intArrayCopy[];

    public UsingArrays(){
        filledIntArray = new int[10];
        intArrayCopy = new int[intArray.length];
        Arrays.fill(filledIntArray,7);
        Arrays.sort(doubleArray);
        System.arraycopy(intArray,0, intArrayCopy, 0, intArray.length);
    }

    public void printArrays(){
        System.out.print("doubleArray: ");
        for(double doublevalue: doubleArray){
            System.out.printf("%.1f ", doublevalue);
        }
        System.out.print("\nintArray: ");
        for(int intvalue: intArray){
            System.out.print(intvalue + " ");
        }
        System.out.print("\nfilledIntArray: ");
        for(int intvalue: filledIntArray){
            System.out.print(intvalue+" ");
        }
        System.out.print("\nintArraycopy: ");
        for(int intvalue: intArrayCopy){
            System.out.print(intvalue + " ");
        }
    }

    public int arraySearch(int value){
        return Arrays.binarySearch(intArray, value);
    }
}
