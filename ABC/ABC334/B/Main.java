import java.util.Scanner;

public class Main {

  public static long floor(long x, long y) {
    long z = (x % y + y) % y;
    return (x - z) / y;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long a = sc.nextLong();
    long m = sc.nextLong();
    long l = sc.nextLong();
    long r = sc.nextLong();
    System.out.println(floor(r - a, m) - floor(l - a - 1, m));
    sc.close();
  }
}
