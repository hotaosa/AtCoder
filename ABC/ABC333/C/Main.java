import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    sc.close();

    final int SIZE = 13;
    long[] repunit = new long[SIZE];
    repunit[0] = 1;
    for (int i = 1; i < SIZE; ++i) {
      repunit[i] = repunit[i - 1] * 10 + 1;
    }

    List<Long> sumRepunit = new ArrayList<Long>();
    for (int i = 0; i < SIZE; ++i) {
      for (int j = i; j < SIZE; ++j) {
        for (int k = j; k < SIZE; ++k) {
          sumRepunit.add(repunit[i] + repunit[j] + repunit[k]);
        }
      }
    }
    Collections.sort(sumRepunit);
    System.out.println(sumRepunit.get(n - 1));
  }
}