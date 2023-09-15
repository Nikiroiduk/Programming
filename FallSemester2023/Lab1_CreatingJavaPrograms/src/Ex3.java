/*
 * Программа, в которой все переданные во входную строку аргументы
 * выводятся на экран в обратной порядке. Например, если было
 * передано 2 аргумента – make install, то на экран должно
 * вывестись llatsni ekam. Примечание*: для разбора слова по
 * буквам необходимо использовать функцию charAt(). Например,
 * str.charAt(i) вернет символ с позиции i в слове, записанном в
 * строковую переменную str. Команда str.length() возвращает
 * длину слова str.
 */

public class Ex3 {
    public static void main(String[] args) {
        for (int i = 0; i < args.length; i++) {
            String str = args[i];
            String reversedStr = "";

            for (int j = str.length() - 1; j >= 0; j--) {
                reversedStr += str.charAt(j);
            }

            args[i] = reversedStr;
        }

        for (int i = 0; i < args.length / 2; i++) {
            String temp = args[i];
            args[i] = args[args.length - 1 - i];
            args[args.length - 1 - i] = temp;
        }

        for (String str : args) {
            System.out.println(str);
        }
    }
}
