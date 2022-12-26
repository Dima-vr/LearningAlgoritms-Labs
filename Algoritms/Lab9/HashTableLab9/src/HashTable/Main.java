package HashTable;

import java.util.LinkedList;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Hash table = new Hash();

        Random random = new Random();
        int day, month, year;
        String generatedString;
        table.hashAdd(new HashItem());
        for (int i = 0; i < 10; i++) {
            year = random.nextInt(1970, 2021);
            month = random.nextInt(1, 12);
            day = random.nextInt(1, 28);
            generatedString = random.ints(97, 122 + 1) // 97 - letter 'a', 122 - 'z'
                    .limit(month%6 + 1)// (month%6 + 1) - length of string
                    .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
                    .toString();
            table.hashAdd(new HashItem(day, month, year, generatedString));
        }
        table.output();
    }
}
