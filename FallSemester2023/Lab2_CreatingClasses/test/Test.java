package FallSemester2023.Lab2_CreatingClasses.test;

import models.Rectangle;

public class Test {
    public static void main(String[] args) {
        Rectangle rect1 = new Rectangle();
        Rectangle rect2 = new Rectangle(100, 50);
        Rectangle rect3 = new Rectangle(10, 10, 40, 70);

        System.out.println("Created rectangles:");
        System.out.println("rect1: " + rect1.rect_print());
        System.out.println("rect2: " + rect2.rect_print());
        System.out.println("rect3: " + rect3.rect_print());

        rect1.move(20, 5);
        rect2.move(-50, 10);
        rect3.move(1, 0);

        System.out.println("Moved rectangles:");
        System.out.println("rect1: " + rect1.rect_print());
        System.out.println("rect2: " + rect2.rect_print());
        System.out.println("rect3: " + rect3.rect_print());

        rect2.union(rect3);
        System.out.println("rect2 union rect3:");
        System.out.println(rect2.rect_print());

    }
}
