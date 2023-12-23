import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static int binarySearch(long[] array, long val) {
    int l = -1;
    int r = array.length;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (array[mid] < val) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return r;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int q = sc.nextInt();
    long[] r = new long[n];
    for (int i = 0; i < n; ++i) {
      r[i] = sc.nextLong();
    }
    Arrays.sort(r);
    for (int i = 1; i < n; ++i) {
      r[i] += r[i - 1];
    }

    while (q-- > 0) {
      long x = sc.nextLong();
      System.out.println(binarySearch(r, x + 1));
    }

    sc.close();
  }
}
