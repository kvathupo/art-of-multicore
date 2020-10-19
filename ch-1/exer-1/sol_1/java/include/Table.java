package include;

import java.util.LinkedHashMap;
import java.util.ArrayList;

public class Table {
    private LinkedHashMap<String, Person> people;
    private ArrayList<Chopstick> utensils;
    
    // Constructors
    public Table(String ...names) {
        for (int i = 0; i < names.length; i++) {
            people.put(name, new Person(names[i]));
            utensils.add(new Chopstick(false, "", i));
            if (i == 0) {
                people.get(name).right = utensils.get(0);
            } else if (i == names.length - 1) {
                people.get(name).left = utensils.get(i - 1);
                people.get(name).right = utensils.get(i);
                people.get(names[0]).left = utensils.get(i);
            } else {
                people.get(name).left = utensils.get(i - 1);
                people.get(name).right = utensils.get(i);
            }
        }
    }

    /*
     *  Methods
     */
    public Person get(String name) {
        return people.get(name);
    }
    // Eating
    public void eat(String name) {
        people.get(name).eat();
    }
    public void eat(int idx) {
        for (Map.Entry<String, Person> ele : people.entrySet()) {
            if (idx-- == 0) {
                ele.getValue().eat();
            }
        }
    }
    // Thinking
    public void think(String name) {
        people.get(name).think();
    }
    public void think(int idx) {
        for (Map.Entry<String, Person> ele : people.entrySet()) {
            if (idx-- == 0) {
                ele.getValue().think();
            }
        }
    }
    // Printing
    public void print() {
        for (Map.Entry<String, Person> ele : people.entrySet()) {
            StringBuilder bldr = new StringBuilder();
            bldr.append(ele.getKey());
            bldr.append(" is ");
            bldr.append((ele.getValue().is_eating) ? " eating!" : " not eating!");
            System.out.println(bldr.toString());
        }
    }
}
