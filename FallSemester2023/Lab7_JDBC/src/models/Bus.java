package src.models;

import java.util.*;

public class Bus {
    private int BusID = 0;

    public void setBusID(int busID) {
        BusID = busID;
    }

    public int getBusID() {
        return BusID;
    }

    private String BusNumber = "-----";

    public String getBusNumber() {
        return BusNumber;
    }

    private int Capacity = 0;

    public int getCapacity() {
        return Capacity;
    }

    public Bus(int BusID, String BusNumber, int Capacity) {
        this.BusID = BusID;
        this.BusNumber = BusNumber;
        this.Capacity = Capacity;
    }

    public Bus(String BusNumber, int Capacity) {
        this.BusNumber = BusNumber;
        this.Capacity = Capacity;
    }

    public static List<Bus> gimeSomeBuses(int n) {
        List<Bus> result = new ArrayList<Bus>();
        Random random = new Random();
        for (int i = 0; i < n; ++i) {
            var num = randBusNumber();
            var cap = random.nextInt(50 - 20) + 20;
            result.add(new Bus(num, cap));
        }
        return result;
    }

    private static String randBusNumber() {
        Random random = new Random();
        String chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < 8; i++) {
            result.append(chars.charAt(random.nextInt(chars.length())));
        }
        return result.toString();
    }

    @Override
    public String toString() {
        return String.format("ID: %d, BusNumber: %s, Capacity: %d", BusID, BusNumber, Capacity);
    }
}
