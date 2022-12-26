package HashTable;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;


public class HashItem {
    private final LocalDate birthday;
    private final String person;
    DateTimeFormatter dateFormat = DateTimeFormatter.ofPattern("dd MM yyyy");


    public HashItem() {
        birthday = LocalDate.parse(toStringDate(28, 12, 2004), dateFormat);
        person = "Dima";
    }

    public HashItem(int day, int month, int year, String person) {
        birthday = LocalDate.parse(toStringDate(day, month, year), dateFormat);
        this.person = person;
    }

    public void output() {
        System.out.println("Date:" + birthday + ";   Person: " + person + ";");
    }

    public int amountOfDays() {
        LocalDate today = LocalDate.now();
        float daysBetween = ChronoUnit.DAYS.between(birthday, today);
        return (int) daysBetween;
    }

    public int nameLength() {
        return person.length();
    }

    public String toStringDate(int day, int month, int year) {
        return (day < 10 ? "0" + day : day) + " " + (month < 10 ? "0" + month : month) + " " + year;
    }
}
