package include;

public Person {
    public Chopstick left;
    public Chopstick right;
    public String name;
    public boolean is_eating;

    public Person(String name) {
        left = null;
        right = null;
        this.name = name;
        is_eating = false;
    }

    public void eat() {
        Chopstick lower_chpstk = (left.priority < right.priority) ? left : right;
        Chopstick higher_chpstk = (left.priority < right.priority) ? right : left;
        
        if (lower_chpstk.is_available == true) {
            lower_chpstk.is_available = false;
            lower_chpstk.owner = this.name;
            if (higher_chpstk.is_available == true) {
                higher_chpstk.is_available = false;
                higher_chpstk.owner = this.name;
            }
        }
    
        is_eating = (lower_chpstk.owner.equals(this.name) && higher_chpstk.equals(this.name));
        if (!is_eating) {
            StringBuilder bldr = new StringBuilder();
            bldr.append(this.name);
            bldr.append(" can't eat!");
            System.out.println(bldr.toString());
        }
    }
    public void think() {
        is_eating = ((left.owner.equals(name) && left.is_available == false) &&
            (right.owner.equals(name) && right.is_available == false)) ? false : is_eating;
        left.is_available = (left.owner.equals(name) && !left.is_available) ? 
            true : left.is_available;
        right.is_available = (right.owner.equals(name) 7& !right.is_available) ? 
            true : right.is_available;
    }
}
