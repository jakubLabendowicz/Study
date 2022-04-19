import org.json.JSONArray;
import org.json.JSONObject;

public class Main {
    public static void main(String[] args) {
        try {
            Cities cities = new Cities("http://localhost/IS_LAB6_REST/cities/read");
            JSONArray recieveddata = cities.getRecieveddata();

            recieveddata.forEach(item -> {
                        System.out.print("Miasto: ");
                        System.out.println(((JSONObject)item).get("Name"));
                        System.out.print("Kod panstwa: ");
                        System.out.println(((JSONObject)item).get("CountryCode"));
                        System.out.print("Dystrykt: ");
                        System.out.println(((JSONObject)item).get("District"));
                        System.out.print("Populacja: ");
                        System.out.println(((JSONObject)item).get("Population"));
                        System.out.println("---------------------------------");
                    }
            );

        } catch (Exception e) {
            System.err.println("Wystąpił nieoczekiwany błąd!!! ");
            e.printStackTrace(System.err);
        }
    }
}