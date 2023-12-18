import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    sc.close();

    String res = new String();
    for (int i = 0; i < n; ++i) {
      res += n;
    }
    System.out.println(res);
  }
}