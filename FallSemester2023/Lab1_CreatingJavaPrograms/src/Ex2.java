/*
 * Программа, в которой перебираются числа от 1 до 500 и выводятся
 * на экран. Если число делится на 5, то вместо него выводится
 * слово fizz, если на 7, то buzz. Если число делится на 5 и
 * на 7, то выводить слово fizzbuzz. Примечание*: остаток от
 * деления в Java обозначается через символ %.
 */

public class Ex2 {
    public static void main(String[] args) {
        for (int i = 1; i <= 500; i++) {
            System.out.println(((i % 5 == 0) ? "fizz" : "") +
                    ((i % 7 == 0) ? "buzz" : "") +
                    (i % 5 != 0 && i % 7 != 0 ? i : ""));
        }
    }
}
