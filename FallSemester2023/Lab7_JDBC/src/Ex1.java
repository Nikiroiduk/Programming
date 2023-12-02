package src;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.*;

import src.models.Booking;
import src.models.Bus;
import src.models.Route;
import src.models.Schedule;
import src.models.Ticket;
import src.models.TicketDTO;

public class Ex1 {
    private static final String URL = "jdbc:mysql://localhost/bus_tickets";
    private static final String USER = "root";
    private static final String PASS = "password";

    private static final int amountOfGeneratedRows = 10;

    public static void main(String[] args) {
        Random random = new Random();
        var buses = Bus.gimeSomeBuses(amountOfGeneratedRows);
        var routes = Route.gimeSomeRoutes(amountOfGeneratedRows);
        var schedules = Schedule.gimeSomeSchedules(amountOfGeneratedRows);
        var tickets = Ticket.gimeSomeTickets(amountOfGeneratedRows);
        var bookings = Booking.gimeSomeBookings(amountOfGeneratedRows);
        try (Connection conn = DriverManager.getConnection(URL, USER, PASS)) {
            for (Bus bus : buses) {
                String insertBuses = "INSERT INTO Buses VALUES (?, ?, ?)";
                PreparedStatement stmt = conn.prepareStatement(insertBuses,
                        Statement.RETURN_GENERATED_KEYS);
                stmt.setInt(1, bus.getBusID());
                stmt.setString(2, bus.getBusNumber());
                stmt.setInt(3, bus.getCapacity());
                if (stmt.executeUpdate() == 1) {
                    try (ResultSet keys = stmt.getGeneratedKeys()) {
                        if (keys.next()) {
                            bus.setBusID(keys.getInt(1));
                        }
                    }
                    System.out.println("Inserted (Bus): " + bus);
                }
            }

            for (Route route : routes) {
                String insertRoutes = "INSERT INTO Routes VALUES (?, ?, ?, ?)";
                PreparedStatement stmt = conn.prepareStatement(insertRoutes,
                        Statement.RETURN_GENERATED_KEYS);
                stmt.setInt(1, route.getRouteID());
                stmt.setString(2, route.getStartLocation());
                stmt.setString(3, route.getEndLocation());
                stmt.setDouble(4, route.getDistance());
                if (stmt.executeUpdate() == 1) {
                    try (ResultSet keys = stmt.getGeneratedKeys()) {
                        if (keys.next()) {
                            route.setRouteID(keys.getInt(1));
                        }
                    }
                    System.out.println("Inserted (Route): " + route);
                }
            }

            for (Schedule schedule : schedules) {
                schedule.setBusID(buses.get(random.nextInt(buses.size())).getBusID());
                schedule.setRouteID(routes.get(random.nextInt(routes.size())).getRouteID());
            }
            for (Schedule schedule : schedules) {
                String insertSchedules = "INSERT INTO Schedules VALUES (?, ?, ?, ?, ?)";
                PreparedStatement stmt = conn.prepareStatement(insertSchedules,
                        Statement.RETURN_GENERATED_KEYS);
                stmt.setInt(1, schedule.getScheduleID());
                stmt.setTimestamp(2, Timestamp.valueOf(schedule.getDepartureTime()));
                stmt.setTimestamp(3, Timestamp.valueOf(schedule.getArrivalTime()));
                stmt.setInt(4, schedule.getBusID());
                stmt.setInt(5, schedule.getRouteID());
                if (stmt.executeUpdate() == 1) {
                    try (ResultSet keys = stmt.getGeneratedKeys()) {
                        if (keys.next()) {
                            schedule.setScheduleID(keys.getInt(1));
                        }
                    }
                    System.out.println("Inserted (Schedule): " + schedule);
                }
            }

            for (Ticket ticket : tickets) {
                ticket.setScheduleID(schedules.get(random.nextInt(schedules.size())).getScheduleID());
            }
            for (Ticket ticket : tickets) {
                String insertTickets = "INSERT INTO Tickets VALUES (?, ?, ?, ?, ?)";
                PreparedStatement stmt = conn.prepareStatement(insertTickets,
                        Statement.RETURN_GENERATED_KEYS);
                stmt.setInt(1, ticket.getTicketID());
                stmt.setInt(2, ticket.getScheduleID());
                stmt.setInt(3, ticket.getSeatNumber());
                stmt.setDouble(4, ticket.getPrice());
                stmt.setString(5, ticket.getStatus());
                if (stmt.executeUpdate() == 1) {
                    try (ResultSet keys = stmt.getGeneratedKeys()) {
                        if (keys.next()) {
                            ticket.setTicketID(keys.getInt(1));
                        }
                    }
                    System.out.println("Inserted (Ticket): " + ticket);
                }
            }

            for (Booking booking : bookings) {
                booking.setTicketID(tickets.get(random.nextInt(tickets.size())).getTicketID());
            }
            for (Booking booking : bookings) {
                String insertBookings = "INSERT INTO Bookings VALUES (?, ?, ?)";
                PreparedStatement stmt = conn.prepareStatement(insertBookings,
                        Statement.RETURN_GENERATED_KEYS);
                stmt.setInt(1, booking.getBookingID());
                stmt.setInt(2, booking.getTicketID());
                stmt.setTimestamp(3, Timestamp.valueOf(booking.getBookingDate()));

                if (stmt.executeUpdate() == 1) {
                    try (ResultSet keys = stmt.getGeneratedKeys()) {
                        if (keys.next()) {
                            booking.setBookingID(keys.getInt(1));
                        }
                    }
                    System.out.println("Inserted (Booking): " + booking);
                }
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }

        try (Connection conn = DriverManager.getConnection(URL, USER, PASS)) {
            Scanner scanner = new Scanner(System.in);
            while (true) {

                System.out.println( "\n\nPosiible locations:\n" + "Barranquilla\n" + "Cologne\n" + "Brasilia\n" + "Mashhad\n" +
                        "Bogota\n" + "Bandung\n" + "Delhi\n" + "Nagoya\n" + "Havana\n");

                System.out.println("Where are you coming from?: ");
                var startLocation = scanner.nextLine();
                // startLocation = "Delhi";
                System.out.println("Where you go?: ");
                var endLocation = scanner.nextLine();
                // endLocation = "Bogotá";

                String checkAvaliavleTickets = "SELECT Tickets.*, Schedules.DepartureTime, Schedules.ArrivalTime, Routes.Distance FROM Tickets JOIN Schedules ON Tickets.ScheduleID = Schedules.ScheduleID JOIN Routes ON Schedules.RouteID = Routes.RouteID WHERE Routes.StartLocation = ? AND Routes.EndLocation = ? AND Tickets.Status = 'available';";
                PreparedStatement checkStmt = conn.prepareStatement(checkAvaliavleTickets);
                checkStmt.setString(1, startLocation);
                checkStmt.setString(2, endLocation);
                ResultSet rs = checkStmt.executeQuery();

                List<TicketDTO> avaliableTickets = new ArrayList<TicketDTO>();
                while (rs.next()) {
                    int ticketID = rs.getInt("TicketID");
                    int scheduleID = rs.getInt("ScheduleID");
                    int seatNumber = rs.getInt("SeatNumber");
                    double price = rs.getDouble("Price");
                    String status = rs.getString("Status");
                    LocalDateTime departureTime = rs.getTimestamp("DepartureTime").toLocalDateTime();
                    LocalDateTime arrivalTime = rs.getTimestamp("ArrivalTime").toLocalDateTime();
                    double distance = rs.getDouble("Distance");
                    // System.out.println(rs.getTimestamp("DepartureTime"));
                    // System.out.println(rs.getTimestamp("ArrivalTime"));

                    avaliableTickets.add(new TicketDTO(ticketID, scheduleID, seatNumber, price, status, departureTime,
                            arrivalTime, distance));
                }

                for (int i = 0; i < avaliableTickets.size(); ++i) {
                    System.out.println(String.format("%d) %s", i + 1, avaliableTickets.get(i)));
                }

                if (avaliableTickets.size() > 0) {
                    System.out.println("Wich tickey you would like to buy?: ");
                    var index = convert(scanner.nextLine()) - 1;
                    System.out.println(String.format("It will cost you: %f", avaliableTickets.get(index).getPrice()));
                    System.out.println("Press any key to continue");
                    scanner.nextLine();

                    var selectedTicketID = avaliableTickets.get(index).getTicketID();
                    String createBooking = "INSERT INTO Bookings (TicketID, BookingDate) VALUES (?, ?)";
                    PreparedStatement bookingStmt = conn.prepareStatement(createBooking);
                    bookingStmt.setInt(1, selectedTicketID);
                    bookingStmt.setTimestamp(2, Timestamp.valueOf(LocalDateTime.now()));
                    bookingStmt.executeUpdate();

                    String updateTicketStatus = "UPDATE Tickets SET Status = 'Booked' WHERE TicketID = ?";
                    PreparedStatement updateStmt = conn.prepareStatement(updateTicketStatus);
                    updateStmt.setInt(1, selectedTicketID);
                    updateStmt.executeUpdate();

                    System.out.println("Ticket booked successfully!");
                }
                System.out.println("Enter 'exit' to get out of here");
                String input = scanner.nextLine();
                if ("exit".equalsIgnoreCase(input)) {
                    break;
                }

            }
            scanner.close();
            conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }

    public static int convert(String str) {
        int val = 0;
        try {
            val = Integer.parseInt(str);
        } catch (NumberFormatException e) {
            System.out.println("Invalid String");
        }
        return val;
    }
}
