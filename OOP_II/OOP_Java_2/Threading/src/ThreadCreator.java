public class ThreadCreator {

    public static void main(String[] args) {
        System.out.println("Creating threads");

        Thread t1=new Thread(new PrintTask("task1"));
        Thread t2=new Thread(new PrintTask("task2"));
        Thread t3=new Thread(new PrintTask("task3"));

        System.out.println("Thread Created,starting tasks.");

        t1.start();
        t2.start();
        t3.start();

        System.out.println("Task started,main ends.\n");
    }

}