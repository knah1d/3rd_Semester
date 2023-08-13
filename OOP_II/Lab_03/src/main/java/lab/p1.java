package lab;

import java.util.*;

public class p1 {

    private static final String colors[] = {"black", "yellow",
        "green", "blue", "violet", "silver"};
    private static final String colors2[] = {"gold", "white",
        "brown", "blue", "gray", "silver", "magenta"};

    public p1() {
        List< String> list1 = new LinkedList< String>();
        List< String> list2 = new LinkedList< String>();

        for (String color : colors) {
            list1.add(color);
        }

        for (String color : colors2) {
            list2.add(color);
        }
        System.out.println("After Sorting List1:");
        Collections.sort(list1);
        printList(list1);
        System.out.println();
        
        System.out.print("index of \"yellow\" in list1: ");
        int index = Collections.binarySearch(list1, "yellow");
        System.out.println(index);
        System.out.println();


        System.out.println("After Reversing List1:");
        Collections.reverse(list1);
        printList(list1);
        System.out.println();

        System.out.println("Shuffled list1:");
        Collections.shuffle(list1);
        printList(list1);
        System.out.println();

        //Copies references from one List into another
        List<String> anotherList = new ArrayList<>(list1);

        System.out.print("min: ");
        String smallestElement = Collections.min(list1);
        System.out.println(smallestElement);
        System.out.println();
        System.out.print("max: ");
        String largestElement = Collections.max(list1);
        System.out.println(largestElement);
        System.out.println();

        System.out.println("After Appending all elements:");
        String[] array = {"red", "indigo"};
        Collections.addAll(list1, array);
        printList(list1);
        System.out.println();

        System.out.println("Sets every List element to refer to a specified object:");
        String specifiedObject = "magenta";
        Collections.fill(list1, specifiedObject);
        printList(list1);
        System.out.println();

        System.out.print("Frequency of megenta: ");
        int count = Collections.frequency(list1, "magenta");
        System.out.println(count);
        System.out.println();

        boolean noCommonElements = Collections.disjoint(list1, list2);
        if (noCommonElements) {
            System.out.println("no Common Elements");
        } else {
            System.out.println("Common Elements existed");
        }
    }

    public void printList(List< String> list) {

        for (String color : list) {
            System.out.printf("%s ", color);
        }

        System.out.println();
    }
}
