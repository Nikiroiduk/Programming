/*
 * Создайте программу, вычисляющую числа Фибоначчи. 
 * Числа Фибоначчи – последовательность чисел, в 
 * котором каждое следующее число равно сумме 
 * двух предыдущих. Начало этой последовательности – 
 * числа 1, 1, 2, 3, 5, 8, 13…
 */

public class Ex4 {
    public static void main(String[] args) {
        System.out.println(fib(Integer.parseInt(args[0])));
    }

    public static int fib(int n) {
        if (n <= 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
}
