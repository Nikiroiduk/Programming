package models;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class TicketDTO extends Ticket {
    private LocalDateTime DepartureTime = LocalDateTime.now();

    public LocalDateTime getDepartureTime() {
        return DepartureTime;
    }

    private LocalDateTime ArrivalTime = LocalDateTime.now();

    public LocalDateTime getArrivalTime() {
        return ArrivalTime;
    }

    private double Distance = 0.0;

    public double getDistance() {
        return Distance;
    }

    public TicketDTO(int TicketID, int ScheduleID, int SeatNumber, double Price, String Status, LocalDateTime DepartureTime, LocalDateTime ArrivalTime, double Distance) {
        super(TicketID, ScheduleID, SeatNumber, Price, Status);
        this.DepartureTime = DepartureTime;
        this.ArrivalTime = ArrivalTime;
        this.Distance = Distance;
    }

    @Override
    public String toString() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String dep = DepartureTime.format(formatter);
        String arr = ArrivalTime.format(formatter);
        return String.format("SeatNumber: %d, Price: %f, DepartureTime: %s, ArrivalTime: %s, Ditance: %f", getSeatNumber(), getPrice(), dep, arr, Distance);
    }
    
}
