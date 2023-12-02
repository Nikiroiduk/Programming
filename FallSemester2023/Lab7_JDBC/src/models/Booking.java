package src.models;

import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.*;

public class Booking {
    int BookingID = 0;

    public int getBookingID() {
        return BookingID;
    }

    public void setBookingID(int bookingID) {
        BookingID = bookingID;
    }

    int TicketID = 0;

    public int getTicketID() {
        return TicketID;
    }

    public void setTicketID(int ticketID) {
        TicketID = ticketID;
    }

    LocalDateTime BookingDate = LocalDateTime.now();

    public LocalDateTime getBookingDate() {
        return BookingDate;
    }

    public Booking(int BookingID, int TicketID, LocalDateTime BookingDate) {
        this.BookingID = BookingID;
        this.TicketID = TicketID;
        this.BookingDate = BookingDate;
    }

    public Booking() {
    }

    public static List<Booking> gimeSomeBookings(int n) {
        List<Booking> result = new ArrayList<Booking>();
        for (int i = 0; i < n; ++i) {
            result.add(new Booking());
        }
        return result;
    }

    @Override
    public String toString() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String dep = BookingDate.format(formatter);

        return String.format("ID: %d, TicketID: %d, BookingDate: %s", BookingID, TicketID, dep);
    }
}
