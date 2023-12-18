import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    char[] s = sc.next().toCharArray();
    char[] t = sc.next().toCharArray();
    sc.close();
    System.out.println(dist(s) == dist(t) ? "Yes" : "No");
  }

  public static int dist(char[] s) {
    int d = Math.abs((s[0] - 'A') - (s[1] - 'A'));
    return Math.min(d, 5 - d);
  }
}