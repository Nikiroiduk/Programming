package src.models;

import java.util.*;

public class Ticket {
    private int TicketID;

    public int getTicketID() {
        return TicketID;
    }

    public void setTicketID(int ticketID) {
        TicketID = ticketID;
    }

    private int ScheduleID;

    public int getScheduleID() {
        return ScheduleID;
    }

    public void setScheduleID(int scheduleID) {
        ScheduleID = scheduleID;
    }

    private int SeatNumber;

    public int getSeatNumber() {
        return SeatNumber;
    }

    private double Price;

    public double getPrice() {
        return Price;
    }

    private String Status;

    public String getStatus() {
        return Status;
    }

    public Ticket(int TicketID, int ScheduleID, int SeatNumber, double Price, String Status) {
        this.TicketID = TicketID;
        this.ScheduleID = ScheduleID;
        this.SeatNumber = SeatNumber;
        this.Price = Price;
        this.Status = Status;
    }

    public Ticket(int SeatNumber, double Price, String Status) {
        this.SeatNumber = SeatNumber;
        this.Price = Price;
        this.Status = Status;
    }

    public static List<Ticket> gimeSomeTickets(int n) {
        List<Ticket> result = new ArrayList<Ticket>();
        Random random = new Random();
        for (int i = 0; i < n; ++i) {
            result.add(new Ticket(random.nextInt(20, 50), random.nextDouble(50, 5000),
                    states.get(random.nextInt(states.size()))));
        }
        return result;
    }

    private static List<String> states = new ArrayList<String>(Arrays.asList("available", "booked"));

    @Override
    public String toString() {
        return String.format("ID: %d, ScheduleID: %d, SeatNumber: %d, Price: %f, Status: %s", TicketID, ScheduleID,
                SeatNumber, Price, Status);
    }
}
