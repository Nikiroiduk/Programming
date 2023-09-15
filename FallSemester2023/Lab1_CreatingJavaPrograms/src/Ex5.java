/*
 * Создайте программу, вычисляющую факториал целого числа.
 */

public class Ex5 {
    public static void main(String[] args) {
        System.out.println(fac(Integer.parseInt(args[0])));
    }

    public static int fac(int n) {
        if (n == 0)
            return 1;
        return n * fac(n - 1);
    }
}
