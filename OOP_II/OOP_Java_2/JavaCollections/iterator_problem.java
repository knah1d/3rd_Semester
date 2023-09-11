import java.util.Collection;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

public class iterator_problem {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<Integer>();

        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);

        Iterator<Integer> iter = list.iterator();
        while (iter.hasNext()) {
            Integer n1 = iter.next();
            System.out.println(n1);
            iter.remove();
        }
    }
}
