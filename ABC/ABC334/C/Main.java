import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
  static int solveOdd(int k, int[] a) {
    int[] sumDLeft = new int[k];
    sumDLeft[0] = 0;
    for (int i = 1; i < k; ++i) {
      sumDLeft[i] = sumDLeft[i - 1];
      if (i % 2 == 1) sumDLeft[i] += a[i] - a[i - 1];
    }
    int[] sumDRight = new int[k];
    sumDRight[k - 1] = 0;
    for (int i = k - 2; i >= 0; --i) {
      sumDRight[i] = sumDRight[i + 1];
      if ((k - 1 - i) % 2 == 1) sumDRight[i] += a[i + 1] - a[i];
    }
    int res = 1 << 30;
    for (int i = 0; i < k; ++i) {
      int cur = 0;
      if (i > 0) cur += sumDLeft[i - 1];
      if (i < k - 1) cur += sumDRight[i + 1];
      if (i % 2 == 1) cur += a[i + 1] - a[i - 1];
      res = Math.min(res, cur);
    }
    return res;
  }

  static int solveEven(int k, int[] a) {
    int res = 0;
    for (int i = 1; i < k; i += 2) {
      res += a[i] - a[i - 1];
    }
    return res;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    int[] a = new int[k];
    for (int i = 0; i < k; ++i) {
      a[i] = sc.nextInt();
    }
    sc.close();
    Arrays.sort(a);
    System.out.println((k & 1) == 1 ? solveOdd(k, a) : solveEven(k, a));
  }
}
