import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Write name: ");
        String firstName = in.nextLine();
        System.out.println("Write last name: ");
        String lastName = in.nextLine();
        Student1 student1 = new Student1();
        student1.setFirstName(firstName);
        student1.setLastName(lastName);
    }
}
