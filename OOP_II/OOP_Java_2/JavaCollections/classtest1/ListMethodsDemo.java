import java.util.*;

public class ListMethodsDemo {

    public static void main(String[] args) {
        Integer[] array = {50, 80, 21, 19, 91, 35};
        Integer[] anotherArr = {10,56,35};
        List<Integer> myList = Arrays.asList(array);

        Collections.sort(myList);
        System.out.println("Sorted list: " + myList);

        Integer elementToSearch = myList.get(new Random().nextInt(myList.size()));
        int index = Collections.binarySearch(myList, elementToSearch);
        System.out.println("Binary search result for " + elementToSearch + ": Index " + index);

        Collections.reverse(myList);
        System.out.println("Reversed list: " + myList);

        Collections.shuffle(myList);
        System.out.println("Shuffled list: " + myList);

        List<Integer> copiedList = new ArrayList<>(myList);
        System.out.println("Copied list: " + copiedList);

        Integer fillValue = 0;
        Collections.fill(copiedList, fillValue);
        System.out.println("List filled with " + fillValue + ": " + copiedList);

        Integer minValue = Collections.min(myList);
        Integer maxValue = Collections.max(myList);
        System.out.println("Minimum value: " + minValue);
        System.out.println("Maximum value: " + maxValue);

        List<Integer> anotherList = Arrays.asList(anotherArr);
        myList.addAll(anotherList);
        System.out.println("List after adding all elements from another list: " + myList);

        Integer valueToCount = myList.get(35);
        int count = Collections.frequency(myList, valueToCount);
        System.out.println("Frequency of " + valueToCount + " in the list: " + count);

        List<Integer> otherList = Arrays.asList(anotherArr);
        boolean isDisjoint = Collections.disjoint(myList, otherList);
        System.out.println("Are the two lists disjoint? " + isDisjoint);
    }
}
