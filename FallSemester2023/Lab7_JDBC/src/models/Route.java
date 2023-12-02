package models;

import java.util.*;

public class Route {
    private int RouteID = 0;

    public void setRouteID(int routeID) {
        RouteID = routeID;
    }

    public int getRouteID() {
        return RouteID;
    }

    private String StartLocation = "-----";

    public String getStartLocation() {
        return StartLocation;
    }

    private String EndLocation = "-----";

    public String getEndLocation() {
        return EndLocation;
    }

    private double Distance = 0.0;

    public double getDistance() {
        return Distance;
    }

    public Route(int RouteID, String StartLocation, String EndLocation, double Distatce) {
        this.RouteID = RouteID;
        this.StartLocation = StartLocation;
        this.EndLocation = EndLocation;
        this.Distance = Distatce;
    }

    public Route(String StartLocation, String EndLocation, double Distatce) {
        this.StartLocation = StartLocation;
        this.EndLocation = EndLocation;
        this.Distance = Distatce;
    }

    public static List<Route> gimeSomeRoutes(int n) {
        List<Route> result = new ArrayList<Route>();
        Random random = new Random();
        for (int i = 0; i < n; ++i) {
            var start = cities.get(random.nextInt(cities.size()));
            var end = cities.get(random.nextInt(cities.size()));
            var dist = random.nextDouble(5, 500);
            result.add(new Route(start, end, dist));
        }
        return result;
    }

    private static List<String> cities = new ArrayList<String>(
            Arrays.asList("Barranquilla", "Cologne", "Brasilia", "Mashhad",
                    "Bogota", "Bandung", "Delhi", "Nagoya", "Havana"));

    @Override
    public String toString() {
        return String.format("ID: %d, StartLocation: %s, EndLocation: %s, Distance: %f", RouteID, StartLocation,
                EndLocation, Distance);
    }
}
