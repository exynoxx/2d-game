import java.util.*;
import java.util.concurrent.ThreadLocalRandom;
import java.awt.Desktop;
import java.net.URI;
import java.io.IOException;
import java.net.URISyntaxException;

public class spillet{
    public static void main(String[] args) {
        String url = "https://www.youtube.com/watch?v=dQw4w9WgXcQ";
        String url2 = "https://www.youtube.com/watch?v=oQgJlYD2pFw";
        Scanner input = new Scanner(System.in);   
        int number = ThreadLocalRandom.current().nextInt(1, 5+ 1);
        System.out.println("A random number has been generated");
        System.out.println("\nGuess the number between 1 and 5");
        System.out.println("\nPlay at your own risk");
        int response = input.nextInt();
        if(response != number){
            if(Desktop.isDesktopSupported()){
                try {
                    Desktop desktop = Desktop.getDesktop();
                    desktop.browse(new URI(url));
                } catch (IOException | URISyntaxException e) {

                }
            }
        }
        else{
            try {
                Desktop desktop = Desktop.getDesktop();
                desktop.browse(new URI(url2));
            } catch (IOException | URISyntaxException e) {

            }
        }
        System.out.println("Du gættede på tallet "+ response);
        System.out.println("Det korrekte tal var  "+ number);
    }
}