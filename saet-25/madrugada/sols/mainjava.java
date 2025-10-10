// codigo em java para testar no boca
import java.util.Scanner;

public class mainjava {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int b = sc.nextInt();
        int v = sc.nextInt();
        
        if ((b - v) % n == 0)
            System.out.println((b - v) / n);
        else
            System.out.println(-1);
        
        sc.close();
    }
}
