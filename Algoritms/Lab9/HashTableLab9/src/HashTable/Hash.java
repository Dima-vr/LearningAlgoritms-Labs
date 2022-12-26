package HashTable;

import java.util.LinkedList;

public class Hash {
    private final int size;
    private int collision;
    private LinkedList<HashItem> table = new LinkedList<>();

    public Hash() {
        size = 12;
        collision = 0;
        for (int i = 0; i < size; i++) {
            table.add(i, null);
        }
    }

    public int hashFunction(HashItem item) {
        return (item.amountOfDays() - item.nameLength()) % size;
    }

    public void hashAdd(HashItem item) {
        int index = hashFunction(item);
        while (table.get(index) != null) {
            if (index == size - 1) {
                index = 0;
            } else {
                index++;
            }
            collision++;
        }
        table.set(index, item);
    }

    public void output() {
        for (int i = 0; i < size; i++) {
            System.out.print(i + ": ");
            if (table.get(i) == null) {
                System.out.println("null");
            } else {
                table.get(i).output();
            }
        }
        System.out.println("collision:" + collision);
    }
}
