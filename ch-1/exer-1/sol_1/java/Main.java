import include.*;
import java.util.ArrayList;

public class Main {
    private static Object lock1 = new Object();
    private static Object lock2 = new Object();
    private static class ThreadPerson implements Runnable {
        private String name;
        private int time_offset;
        private Table table;
        
        public ThreadPerson(Table table, String name, int time_offset) {
            this.table = table;
            this.name = name;
            this.time_offset = time_offset;
        }
        public void run() {
            for (int iter = 0; iter < 3; iter++) {
                synchronized(lock1) {
                    table.eat(name);
                }
                try {
                    Thread.sleep(time_offset);
                } catch (Exception e) {
                    System.err.println("Fatal error: Interrupted Thread");
                    return;
                }
                if (table.get(name).is_eating) {
                    synchronized(lock2) {
                        table.think(name);
                    }
                    return;
                }
            }
        }
    }

    public static void main(String[] args) 
        throws InterruptedException {
        String[] names = {"Burke", "Darwin", "Descartes", "Plato"};
        Table table = new Table(names);
        ArrayList<Thread> lst = new ArrayList<>();

        for (int i = 0; i < 4; i++) {
            Thread thrd = new Thread(new ThreadPerson(table, names[i], 1 + i));
            lst.add(thrd);
        }
        for (Thread thrd : lst) {
            thrd.start();
        }
        for (Thread thrd : lst) {
            thrd.join();
        }
        System.out.println("Done!");
        table.print();
    }
}
