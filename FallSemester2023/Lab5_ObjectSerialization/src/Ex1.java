
/*
* Осуществить запись в файл большого произвольного массива данных,
* используя бинарные потоки, двумя способами: запись без и запись
* с использованием классов-фильтров, позволяющих выполнить
* буферизацию. Произвести замеры времени выполнения записи в
* файл и сравнить полученное ускорение. Указание: для отсчета
* времени в миллисекундах необходимо использовать системную
* функцию следующим образом: long timeStart =System.currentTimeMillis().
* То же самое проделать для операции считывания данных из файла.
*/

package src;
import java.io.*;
import java.util.*;

public class Ex1 {

    private static final int AMOUNT_OF_LINES = 1000000;
    
    private static List<String> data = new ArrayList<String>();

    public static void main(String[] args) {

        var file = new File("data.bin");
        
        for (int i = 0; i < AMOUNT_OF_LINES; i++) {
            data.add(UUID.randomUUID().toString());
        }
        
        SaveFile(file);
        ReadFile(file);

        SaveFileBuffered(file);
        ReadFileBuffered(file);

    }
    
    private static void SaveFile(File file) {
        try (var str = new FileOutputStream(file)) {
            var time = System.currentTimeMillis();
            for (String string : data) {
                str.write((string + "\n").getBytes());
            }
            str.close();
            System.out.println("File saved in " + (System.currentTimeMillis() - time) + " ms.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void ReadFile(File file) {
        var data = new ArrayList<String>();
        try (var str = new FileInputStream(file)) {
            var time = System.currentTimeMillis();
            var line = "";
            for (byte b : str.readAllBytes()) {
                line += (char)b;
                if (b == 10){
                    data.add(line + "\n");
                    line = "";
                }
            }
            str.close();
            System.out.println("File read in " + (System.currentTimeMillis() - time) + " ms.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void SaveFileBuffered(File file) {
        try {
            OutputStream str = new FileOutputStream(file);
            var time = System.currentTimeMillis();
            str = new BufferedOutputStream(str);
            for (String string : data) {
                str.write((string + "\n").getBytes());
            }
            str.close();
            System.out.println("File saved in " + (System.currentTimeMillis() - time) + " ms. (buffered)");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void ReadFileBuffered(File file) {
        var data = new ArrayList<String>();
        try {
            InputStream str = new FileInputStream(file);
            var time = System.currentTimeMillis();
            str = new BufferedInputStream(str);
            var line = "";
            for (byte b : str.readAllBytes()) {
                line += (char)b;
                if (b == 10){
                    data.add(line + "\n");
                    line = "";
                }
            }
            str.close();
            System.out.println("File read in " + (System.currentTimeMillis() - time) + " ms. (buffered)");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
