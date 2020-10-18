package include;

public class Chopstick {
    public boolean is_available;
    public String owner;
    public int priority;

    public Chopstick(boolean is_available, String owner, int priority) {
        this.is_available = is_available;
        this.owner = owner;
        this.priority = priority;
    }
}
