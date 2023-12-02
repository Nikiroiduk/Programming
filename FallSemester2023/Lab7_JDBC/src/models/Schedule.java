package models;

import java.util.*;
import java.time.*;
import java.time.format.DateTimeFormatter;

public class Schedule {
    private int ScheduleID = 0;

    public void setScheduleID(int scheduleID) {
        ScheduleID = scheduleID;
    }

    public int getScheduleID() {
        return ScheduleID;
    }

    private int BusID = 0;

    public void setBusID(int busID) {
        BusID = busID;
    }

    public int getBusID() {
        return BusID;
    }

    private int RouteID = 0;

    public void setRouteID(int routeID) {
        RouteID = routeID;
    }

    public int getRouteID() {
        return RouteID;
    }

    private LocalDateTime DepartureTime = LocalDateTime.now();

    public LocalDateTime getDepartureTime() {
        return DepartureTime;
    }

    private LocalDateTime ArrivalTime = LocalDateTime.now();

    public LocalDateTime getArrivalTime() {
        return ArrivalTime;
    }

    public Schedule(int ScheduleID, int BusID, int RouteID, LocalDateTime DepartureTime, LocalDateTime ArrivalTime) {
        this.ScheduleID = ScheduleID;
        this.BusID = BusID;
        this.RouteID = RouteID;
        this.DepartureTime = DepartureTime;
        this.ArrivalTime = ArrivalTime;
    }

    public Schedule(LocalDateTime DepartureTime, LocalDateTime ArrivalTime) {
        this.DepartureTime = DepartureTime;
        this.ArrivalTime = ArrivalTime;
    }

    public static List<Schedule> gimeSomeSchedules(int n) {
        List<Schedule> result = new ArrayList<Schedule>();
        for (int i = 0; i < n; ++i) {
            result.add(new Schedule(LocalDateTime.now(), LocalDateTime.now()));
        }
        return result;
    }

    @Override
    public String toString() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String dep = DepartureTime.format(formatter);
        String arr = ArrivalTime.format(formatter);

        return String.format("ID: %d, BusID: %d, RouteID: %d, DepartureTime: %s, ArrivalTime: %s", ScheduleID, BusID,
                RouteID, dep, arr);
    }
}
