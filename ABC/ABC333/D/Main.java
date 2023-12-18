import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
  public static int countSubtreeSize(ArrayList<ArrayList<Integer> > graph, int v, int parent) {
    int ret = 1;
    for (int i = 0; i < graph.get(v).size(); ++i) {
      int nv = graph.get(v).get(i);
      if (nv != parent) {
        ret += countSubtreeSize(graph, nv, v);
      }
    }
    return ret;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.next());
    ArrayList<ArrayList<Integer> > graph = new ArrayList<>();
    for (int i = 0; i < n; ++i) {
      ArrayList<Integer> g = new ArrayList<>();
      graph.add(g);
    }
    for (int i = 0; i < n - 1; ++i) {
      int u = Integer.parseInt(sc.next());
      int v = Integer.parseInt(sc.next());
      graph.get(--u).add(--v);
      graph.get(v).add(u);
    }
    sc.close();

    ArrayList<Integer> subtreeSizes = new ArrayList<>();
    for (int i = 0; i < graph.get(0).size(); ++i) {
      subtreeSizes.add(countSubtreeSize(graph, graph.get(0).get(i), 0));
    }
    Collections.sort(subtreeSizes);

    int res = 1;
    for (int i = 0; i < subtreeSizes.size() - 1; ++i) {
      res += subtreeSizes.get(i);
    }
    System.out.println(res);
  }
}